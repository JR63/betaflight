/*
 * This file is part of Cleanflight.
 *
 * Cleanflight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cleanflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Cleanflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define I2C1_OVERCLOCK true
#define I2C2_OVERCLOCK true

#ifdef STM32F7
#define STM_FAST_TARGET
#endif

/****************************
  STM32 F4 specific settings. 
****************************/
#ifdef STM32F4
#define STM_FAST_TARGET
#define USE_DSHOT
#define I2C3_OVERCLOCK true
#endif

#ifdef STM32F3
#define USE_DSHOT
#endif

#ifdef STM32F1
// Using RX DMA disables the use of receive callbacks
#define USE_UART1_RX_DMA
#define USE_UART1_TX_DMA
#endif

#define SERIAL_RX
#define USE_SERIALRX_CRSF       // Team Black Sheep Crossfire protocol
#define USE_SERIALRX_SPEKTRUM   // DSM2 and DSMX protocol
#define USE_SERIALRX_SBUS       // Frsky and Futaba receivers
#define USE_SERIALRX_IBUS       // FlySky and Turnigy receivers
#define USE_SERIALRX_SUMD       // Graupner Hott protocol
#define USE_SERIALRX_SUMH       // Graupner legacy protocol
#define USE_SERIALRX_XBUS       // JR
#define USE_CLI
#define USE_PWM
#define USE_PPM

#if defined(STM_FAST_TARGET)
#define MAX_AUX_CHANNELS                99
#define TASK_GYROPID_DESIRED_PERIOD     125
#define SCHEDULER_DELAY_LIMIT           10
#else
#define MAX_AUX_CHANNELS                6
#define TASK_GYROPID_DESIRED_PERIOD     1000
#define SCHEDULER_DELAY_LIMIT           100
#endif

#if (FLASH_SIZE > 64)
#define BLACKBOX
#define GPS
#define TELEMETRY
#define TELEMETRY_FRSKY
#define TELEMETRY_HOTT
#define TELEMETRY_IBUS
#define TELEMETRY_LTM
#define TELEMETRY_SMARTPORT
#define USE_SERVOS
#endif

#if (FLASH_SIZE > 128)
#define CMS
#define USE_DASHBOARD
#define USE_MSP_DISPLAYPORT
#define TELEMETRY_CRSF
#define TELEMETRY_JETIEXBUS
#define TELEMETRY_MAVLINK
#define USE_RX_MSP
#define USE_SERIALRX_JETIEXBUS
#else
#define SKIP_CLI_COMMAND_HELP
#endif
