#include "stm32f4xx_hal.h"
#include <stdio.h>
#include <string.h>

// Define the GPIO pins for the LED
#define RED_PIN GPIO_PIN_0
#define GREEN_PIN GPIO_PIN_1
#define BLUE_PIN GPIO_PIN_4
#define LED_PORT GPIOA

// Define the GPIO pin for the button
#define BUTTON_PIN GPIO_PIN_13
#define BUTTON_PORT GPIOC

// Define UART handle
UART_HandleTypeDef huart2;
UART_HandleTypeDef huart1;

// Function to initialize the GPIO pins for the LED
void LED_Init(void) {
    // Enable the GPIO clock for LED
    __HAL_RCC_GPIOA_CLK_ENABLE();

    // Configure GPIO pins as output for LED
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.Pin = RED_PIN | GREEN_PIN | BLUE_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; // Output push-pull mode
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(LED_PORT, &GPIO_InitStruct);
}

// Function to initialize the GPIO pin for the button
void Button_Init(void) {
    // Enable the GPIO clock for the button
    __HAL_RCC_GPIOC_CLK_ENABLE();

    // Configure GPIO pin as input for the button
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.Pin = BUTTON_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP; // Use internal pull-up resistor
    HAL_GPIO_Init(BUTTON_PORT, &GPIO_InitStruct);
}

// Function to initialize UART2
void UART2_Init(void) {
    huart2.Instance = USART2;
    huart2.Init.BaudRate = 115200; // Adjust the baud rate as needed
    huart2.Init.WordLength = UART_WORDLENGTH_8B;
    huart2.Init.StopBits = UART_STOPBITS_1;
    huart2.Init.Parity = UART_PARITY_NONE;
    huart2.Init.Mode = UART_MODE_TX;
    huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart2.Init.OverSampling = UART_OVERSAMPLING_16;
    if (HAL_UART_Init(&huart2) != HAL_OK) {
        Error_Handler();
    }
}
void UART1_Init(void)
{
	    huart2.Instance = USART1;
	    huart2.Init.BaudRate = 9600; // Adjust the baud rate as needed
	    huart2.Init.WordLength = UART_WORDLENGTH_8B;
	    huart2.Init.StopBits = UART_STOPBITS_1;
	    huart2.Init.Parity = UART_PARITY_NONE;
	    huart2.Init.Mode = UART_MODE_TX;
	    huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	    huart2.Init.OverSampling = UART_OVERSAMPLING_16;
	    if (HAL_UART_Init(&huart2) != HAL_OK) {
	        Error_Handler();
	    }
	}



void Error_Handler(void) {
    // Implement error handling or debugging logic here
    while (1) {
        // Infinite loop to halt the program when an error occurs
    }
}
void uart1_init(void)
{
	RCC->AHB1ENR |= 1;
	RCC->APB2ENR |= 0x00000010;
	GPIOA->MODER &= ~0x003C0000;
	GPIOA->MODER |= 0x00280000;
	GPIOA->AFR[1] &= ~0x0FF0;
	GPIOA->AFR[1] |= 0x0770 ; /* alt8 for UART4 */
	USART1->BRR = 0x0683; /* 9600 baud @ 16 MHz */
	USART1->CR1 = 0x000C;/* enable Tx, Rx, 8-bit data */
	USART1->CR2 = 0x0000; /* 1 stop bit*/
	USART1->CR3 = 0x0000; /* no flow control */
	USART1->CR1 |= 0x2000; /*enable UART4 */

}



void uart1_write(int ch) {
while (!(USART1->SR & 0x0080)) {} // wait until Tx buffer empty
USART1->DR = (ch & 0xFF);
}

int main(void) {
    HAL_Init();

    LED_Init();
    Button_Init();
    UART2_Init();
    uart1_init();// Initialize UART2 communication
  //  UART1_Init();

    uint8_t ledState = 0; // 0 - All LEDs OFF, 1 - Red ON, 2 - Green ON, 3 - Blue ON
    uint8_t i;
    while (1) {
            // Check the state of the button
            if (HAL_GPIO_ReadPin(BUTTON_PORT, BUTTON_PIN) == GPIO_PIN_RESET) {
                // Button is pressed, cycle through LED colors

                // Turn on Red LED
                HAL_GPIO_WritePin(LED_PORT, RED_PIN, GPIO_PIN_SET);
                HAL_GPIO_WritePin(LED_PORT, GREEN_PIN, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(LED_PORT, BLUE_PIN, GPIO_PIN_RESET);

                // Display the message on Minicom
                char message[50];
                sprintf(message, "Red light is ON\r\n");
                HAL_UART_Transmit(&huart2, (uint8_t*)message, strlen(message), HAL_MAX_DELAY);
                for(i=0;message[i]!='\0';i++)
                                {
                                	uart1_write(message[i]);
                                }
                // Add a small delay to debounce the button (adjust as needed)
                HAL_Delay(2000);

                // Turn on Green LED
                HAL_GPIO_WritePin(LED_PORT, RED_PIN, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(LED_PORT, GREEN_PIN, GPIO_PIN_SET);
                HAL_GPIO_WritePin(LED_PORT, BLUE_PIN, GPIO_PIN_RESET);
//                uart1_write('k');

                sprintf(message, "Green light is ON\r\n");
                HAL_UART_Transmit(&huart2, (uint8_t*)message, strlen(message), HAL_MAX_DELAY);
               // HAL_UART_Transmit(&huart1, (uint8_t*)message, strlen(message), HAL_MAX_DELAY);
//                uart1_write('a');
                for(i=0;message[i]!='\0';i++)
                {
                	uart1_write(message[i]);
                }
                HAL_Delay(2000);

                // Turn on Blue LED
                HAL_GPIO_WritePin(LED_PORT, RED_PIN, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(LED_PORT, GREEN_PIN, GPIO_PIN_RESET);
                HAL_GPIO_WritePin(LED_PORT, BLUE_PIN, GPIO_PIN_SET);

                sprintf(message, "Blue light is ON\r\n");
                HAL_UART_Transmit(&huart2, (uint8_t*)message, strlen(message), HAL_MAX_DELAY);
              //  HAL_UART_Transmit(&huart1, (uint8_t*)message, strlen(message), HAL_MAX_DELAY);
                for(i=0;message[i]!='\0';i++)
                                {
                                	uart1_write(message[i]);
                                }

                HAL_Delay(2000);
            }
        }
}

