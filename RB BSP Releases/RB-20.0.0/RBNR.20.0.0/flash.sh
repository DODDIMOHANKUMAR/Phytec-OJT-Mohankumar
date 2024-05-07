./sam-ba -p usb -b sama5d27-som1-ek1 -a qspiflash -c erase
./sam-ba -p usb -b sama5d27-som1-ek1 -a qspiflash -c writeboot:nor/boot.bin -c verifyboot:nor/boot.bin
./sam-ba -p usb -b sama5d27-som1-ek1 -a qspiflash -c write:nor/u-boot.bin:0x16000
./sam-ba -p usb -b sama5d27-som1-ek1 -a qspiflash -c write:nor/at91-sama5d27_som1_ek.dtb:0x96000
./sam-ba -p usb -b sama5d27-som1-ek1 -a qspiflash -c write:nor/zImage:0xA6000
./sam-ba -p usb -b sama5d27-som1-ek1 -a qspiflash -c write:nor/core-image-minimal-sama5d27-som1-ek-sd.squashfs:0x5A6000
./sam-ba -p usb -b sama5d27-som1-ek1 -a bootconfig -c writecfg:bscr:valid,bureg0
./sam-ba -p usb -b sama5d27-som1-ek1 -a bootconfig -c writecfg:bureg0:ext_mem_boot,sdmmc1,sdmmc0_disabled,nfc_disabled,spi1_disabled,spi0_disabled,qspi1_ioset2,qspi0_disabled
./sam-ba -p usb -b sama5d27-som1-ek1 -a bootconfig -c writecfg:fuse:ext_mem_boot,sdmmc1,sdmmc0_disabled,nfc_disabled,spi1_disabled,spi0_disabled,qspi1_ioset2,qspi0_disabled

