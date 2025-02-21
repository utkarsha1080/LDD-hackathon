#include "MAX7219.h"

extern SPI_HandleTypeDef hspi1;

#define MAX7219_CS_LOW  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET)
#define MAX7219_CS_HIGH HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET)

void MAX7219_Send(uint8_t addr, uint8_t data) {
    uint8_t buf[2] = {addr, data};
    MAX7219_CS_LOW;
    HAL_SPI_Transmit(&hspi1, buf, 2, HAL_MAX_DELAY);
    MAX7219_CS_HIGH;
}

void MAX7219_Init(void) {
    MAX7219_Send(0x0C, 0x01);  // Normal mode
    MAX7219_Send(0x09, 0xFF);  // BCD decode mode
    MAX7219_Send(0x0A, 0x08);  // Brightness
    MAX7219_Send(0x0B, 0x07);  // Scan limit (all digits)
    MAX7219_Send(0x0F, 0x00);  // Disable test mode
}
void Display_Hardcoded_Number(void) {
    MAX7219_Send(1, 4);  // Rightmost digit
    MAX7219_Send(2, 3);
    MAX7219_Send(3, 2);
    MAX7219_Send(4, 1);  // Leftmost digit
}


void Display_Number(uint16_t num) {
    for (uint8_t i = 1; i <= 4; i++) {
        MAX7219_Send(i, num % 10);
        num /= 10;
    }
}
