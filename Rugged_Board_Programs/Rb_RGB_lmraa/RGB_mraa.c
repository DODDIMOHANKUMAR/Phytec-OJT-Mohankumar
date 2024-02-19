#include <stdio.h>
#include <unistd.h>
#include <mraa.h>

	mraa_gpio_context gpio_red, gpio_green, gpio_blue;

	void setupPin(int pin) 
	{
	mraa_gpio_context context = mraa_gpio_init(pin);
	if (context == NULL) 
	{
	fprintf(stderr, "Error initializing GPIO %d\n", pin);
	exit(EXIT_FAILURE);
	}
	mraa_result_t result = mraa_gpio_dir(context, MRAA_GPIO_OUT);
	if (result != MRAA_SUCCESS) {
	fprintf(stderr, "Error setting direction for GPIO %d\n", pin);
	mraa_result_print(result);
	exit(EXIT_FAILURE);
	}
}
	void setupRGB(int red, int green, int blue) 
	{
	setupPin(red);
	setupPin(green);
	setupPin(blue);
	gpio_red = mraa_gpio_init(red);
	gpio_green = mraa_gpio_init(green);
	gpio_blue = mraa_gpio_init(blue);
	if (gpio_red == NULL || gpio_green == NULL || gpio_blue == NULL) 
	{
	fprintf(stderr, "Error initializing GPIOs\n");
	exit(EXIT_FAILURE);
	}
}
	mraa_gpio_dir(gpio_red, MRAA_GPIO_OUT);
	mraa_gpio_dir(gpio_green, MRAA_GPIO_OUT);
	mraa_gpio_dir(gpio_blue, MRAA_GPIO_OUT);
	}
	int main() 
	{
	setupRGB(40, 42, 44);
	while (1) 
	{
	// Turn on the red LED
	mraa_gpio_write(gpio_red, 1);
	usleep(500000); // Sleep for 500 ms
	// Turn off the red LED
	mraa_gpio_write(gpio_red, 0);
	// Turn on the green LED
	mraa_gpio_write(gpio_green, 1);
	usleep(500000); // Sleep for 500 ms
	// Turn off the green LED
	mraa_gpio_write(gpio_green, 0);
	// Turn on the blue LED
	mraa_gpio_write(gpio_blue, 1);
	usleep(500000); // Sleep for 500 ms
	// Turn off the blue LED
	mraa_gpio_write(gpio_blue, 0);
	usleep(500000); // Sleep for 500 ms
	}

	mraa_gpio_close(gpio_red);
	mraa_gpio_close(gpio_green);
	mraa_gpio_close(gpio_blue);
	return 0;
}
