#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

	char export_path[100] = "/sys/class/gpio/export";
	char direction_path_red[100] = "/sys/class/gpio/";
	char direction_path_green[100] = "/sys/class/gpio/";
	char direction_path_blue[100] = "/sys/class/gpio/";
	char value_path_red[100] = "/sys/class/gpio/";
	char value_path_green[100] = "/sys/class/gpio/";
	char value_path_blue[100] = "/sys/class/gpio/";
	void setupPin(int pin) {
	int fd_export = open(export_path, O_WRONLY);
		if (fd_export == -1) {
		perror("Error opening export");
		exit(EXIT_FAILURE);
		}
	char pin_str[4];
	sprintf(pin_str, "%d", pin);
	write(fd_export, pin_str, strlen(pin_str) + 1);
	close(fd_export);
	}
	void setupRGB(int red, int green, int blue) {
	setupPin(red);
	setupPin(green);
	setupPin(blue);
	sprintf(direction_path_red + 16, "%s%d%s", "PA", red, "/direction");
	sprintf(direction_path_green + 16, "%s%d%s", "PA", green, "/direction");
	sprintf(direction_path_blue + 16, "%s%d%s", "PA", blue, "/direction");
	sprintf(value_path_red + 16, "%s%d%s", "PA", red, "/value");
	sprintf(value_path_green + 16, "%s%d%s", "PA", green, "/value");
	sprintf(value_path_blue + 16, "%s%d%s", "PA", blue, "/value");
	int fd_direction_red = open(direction_path_red, O_WRONLY);
	int fd_direction_green = open(direction_path_green, O_WRONLY);
	int fd_direction_blue = open(direction_path_blue, O_WRONLY);
	if (fd_direction_red == -1 || fd_direction_green == -1 || fd_direction_blue == -1) 
	{
	perror("Error opening direction");
	exit(EXIT_FAILURE);
	}
	write(fd_direction_red, "out", 4);
	write(fd_direction_green, "out", 4);
	write(fd_direction_blue, "out", 4);
	close(fd_direction_red);
	close(fd_direction_green);
	close(fd_direction_blue);
	}
	
	int main() 
	{
	setupRGB(29,31,13); 
	int fd_red = open(value_path_red, O_WRONLY);
	int fd_green = open(value_path_green, O_WRONLY);
	int fd_blue = open(value_path_blue, O_WRONLY);
	
	if (fd_red == -1 || fd_green == -1 || fd_blue == -1) 
	{
	perror("Error opening value");
	exit(EXIT_FAILURE);
	}
	
	while (1) 
	{
	// Turn on the red LED
	write(fd_red, "1",2); 
	usleep(500000); // Sleep for 500 ms
	// Turn off the red LED
	write(fd_red, "0", 2);
	// Turn on the green LED
	write(fd_green, "1", 2);
	usleep(500000); // Sleep for 500 ms
	// Turn off the green LED
	write(fd_green, "0", 2);
	// Turn on the blue LED
	write(fd_blue, "1", 2);
	usleep(500000); // Sleep for 500 ms
	}
	close(fd_red);
	close(fd_green);
	close(fd_blue);
	return 0;
	}
