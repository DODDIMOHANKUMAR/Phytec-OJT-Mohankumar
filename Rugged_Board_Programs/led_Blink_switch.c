#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define GPIO_EN "/sys/class/gpio/export"
#define GPIO_DIR_LED "/sys/class/gpio/PC13/direction"
#define GPIO_VAL_LED "/sys/class/gpio/PC13/value"
#define GPIO_DIR_SWITCH "/sys/class/gpio/PC12/direction"
#define GPIO_VAL_SWITCH "/sys/class/gpio/PC12/value"

int main() {
    int gpio_fd, switch_fd;
    char value;
    int prev_value = 1;  // Previous switch state
    int led_state = 0;   // 0 for off, 1 for on

    // Export GPIO pins
    gpio_fd = open(GPIO_EN, O_WRONLY);
    if (gpio_fd < 0) {
        perror("Unable to open the file");
        exit(1);
    }
    write(gpio_fd, "76", 2);  // Export PC12
    write(gpio_fd, "77", 2);  // Export PC13
    close(gpio_fd);

    // Configure GPIO directions
    gpio_fd = open(GPIO_DIR_LED, O_WRONLY);
    if (gpio_fd < 0) {
        perror("Unable to open the file");
        exit(1);
    }
    write(gpio_fd, "out", 3);  // Set PC13 as output
    close(gpio_fd);

    gpio_fd = open(GPIO_DIR_SWITCH, O_WRONLY);
    if (gpio_fd < 0) {
        perror("Unable to open the file");
        exit(1);
    }
    write(gpio_fd, "in", 2);  // Set PC12 as input
    close(gpio_fd);

    // Main loop
    while (1) {
        // Read switch state
        switch_fd = open(GPIO_VAL_SWITCH, O_RDONLY);
        if (switch_fd < 0) {
            perror("Unable to open the file");
            exit(1);
        }
        read(switch_fd, &value, 1);
        close(switch_fd);

        // Check if switch state has changed
        if (value == '0' && prev_value == '1') {
            // Toggle LED state
            led_state = !led_state;
            
            // Set LED state
            gpio_fd = open(GPIO_VAL_LED, O_WRONLY);
            if (gpio_fd < 0) {
                perror("Unable to open the file");
                exit(1);
            }
            if (led_state == 1) {
                write(gpio_fd, "1", 1);  // Turn on LED (PC13)
            } else {
                write(gpio_fd, "0", 1);  // Turn off LED (PC13)
            }
            close(gpio_fd);
        }

        // Update previous switch state
        prev_value = value;

        // Sleep for a short duration to debounce the switch
        usleep(100000);  // 100ms
    }

    return 0;
}
