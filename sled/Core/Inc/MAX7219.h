/*
 * MAX7219.h
 *
 *  Created on: Feb 20, 2025
 *      Author: utkarsha
 */

#ifndef MAX7219_H
#define MAX7219_H

#include "stm32f4xx_hal.h"

void MAX7219_Init(void);
void Display_Number(uint16_t num);

#endif
