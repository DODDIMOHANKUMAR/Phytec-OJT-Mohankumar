/* standard headers */
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

/* mraa header */
#include "mraa/spi.h"

/* SPI declaration */
#define SPI_BUS 0

/* SPI frequency in Hz */
#define SPI_FREQ 400000

/*uint16_t pat[] = { 0x01aa, 0x0255, 0x03aa, 0x0455, 0x05aa, 0x0655, 0x07aa, 0x0855 };
uint16_t pat_inv[] = { 0x0155, 0x02aa, 0x0355, 0x04aa, 0x0555, 0x06aa, 0x0755, 0x08aa };

uint16_t pat_clear[] = { 0x0100, 0x0200, 0x0300, 0x0400, 0x0500, 0x0600, 0x0700, 0x0800 };*/

char txbuf[] = "Hello How are you?";
char rxbuf[sizeof(txbuf)]={'\0'};

volatile sig_atomic_t flag = 1;

void
sig_handler(int signum)
{
    if (signum == SIGINT) {
        fprintf(stdout, "Exiting...\n");
        flag = 0;
    }
}

int
main(int argc, char** argv)
{
    mraa_result_t status = MRAA_SUCCESS;
    mraa_spi_context spi;
    int i, j;

    /* initialize mraa for the platform (not needed most of the times) */
    mraa_init();

    //! [Interesting]
    /* initialize SPI bus */
    spi = mraa_spi_init(SPI_BUS);
    if (spi == NULL) {
        fprintf(stderr, "Failed to initialize SPI\n");
        mraa_deinit();
        return EXIT_FAILURE;
    }

    /* set SPI frequency */
    status = mraa_spi_frequency(spi, SPI_FREQ);
    if (status != MRAA_SUCCESS)
        goto err_exit;

    /* set big endian mode */
    status = mraa_spi_lsbmode(spi, 0);
    if (status != MRAA_SUCCESS) {
        goto err_exit;
    }

    /* MAX7219/21 chip needs the data in word size */
   /* status = mraa_spi_bit_per_word(spi, 16);
    if (status != MRAA_SUCCESS) {
        fprintf(stdout, "Failed to set SPI Device to 16Bit mode\n");
        goto err_exit;
    }*/

    mraa_spi_transfer_buf(spi,txbuf,rxbuf,sizeof(txbuf));

    printf("%s \n",rxbuf);    

    /* stop spi */
    mraa_spi_stop(spi);

    //! [Interesting]
    /* deinitialize mraa for the platform (not needed most of the times) */
    mraa_deinit();

    return EXIT_SUCCESS;

err_exit:
    mraa_result_print(status);

    /* stop spi */
    mraa_spi_stop(spi);

    /* deinitialize mraa for the platform (not needed most of the times) */
    mraa_deinit();

    return EXIT_FAILURE;
}
