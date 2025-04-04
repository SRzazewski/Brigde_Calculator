/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "HD44780U.h"
#include "bridge_timers.h"
#include "bc_state_machine.h"
#include "bridge_common.h"
#include <stdio.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
void init_HD44780();
void delay_62_5ns(uint32_t ns);
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
lcd_hd44780u lcd_0;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if(htim->Instance == TIM2)
  { 
    (void)timers_update();
	}
}
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */
  uint16_t adc_value = 0;
  char adc_char_value[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
  lcd_0.interface = mode_4_bits;
  lcd_0.pinout.enable_port = (uint32_t*)LCD_Enable_GPIO_Port;
  lcd_0.pinout.enable_pin = LCD_Enable_Pin;
  lcd_0.pinout.rs_port = (uint32_t*)LCD_RS_GPIO_Port;
  lcd_0.pinout.rs_pin = LCD_RS_Pin;
  lcd_0.pinout.db7_port = (uint32_t*)LCD_DB7_GPIO_Port;
  lcd_0.pinout.db7_pin = LCD_DB7_Pin;
  lcd_0.pinout.db6_port = (uint32_t*)LCD_DB6_GPIO_Port;
  lcd_0.pinout.db6_pin = LCD_DB6_Pin;
  lcd_0.pinout.db5_port = (uint32_t*)LCD_DB5_GPIO_Port;
  lcd_0.pinout.db5_pin = LCD_DB5_Pin;
  lcd_0.pinout.db4_port = (uint32_t*)LCD_DB4_GPIO_Port;
  lcd_0.pinout.db4_pin = LCD_DB4_Pin;
  lcd_0.curr_display_state = MODULE_IDLE_STATE;
  lcd_0.delay = &delay_62_5ns;

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART2_UART_Init();
  MX_ADC1_Init();
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  set_modules(&lcd_0);
  start_bc_state_machine();
  HAL_TIM_Base_Start_IT(&htim2);
	// while(0 == init_lcd(&lcd_0)){}

  HAL_GPIO_WritePin(LCD_Backlight_Control_GPIO_Port, LCD_Backlight_Control_Pin, GPIO_PIN_SET);
  
  (void)timer_start(ADC_MESUR_TIMER);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

    bc_state_machine_routine();

    if (is_timer_reached(ADC_MESUR_TIMER))
    {
      (void)timer_reset(ADC_MESUR_TIMER);
      HAL_ADC_Start(&hadc1);
      (void)timer_start(ADC_MESUR_TIMER);
    }

    if (HAL_ADC_PollForConversion(&hadc1, 10) == HAL_OK)
    {
      adc_value = HAL_ADC_GetValue(&hadc1);
      (void)sprintf(adc_char_value, "Value: %d", adc_value);
      clean_display(&lcd_0);
      display_control(&lcd_0, 0x0C);
      display_string(&lcd_0, adc_char_value, sizeof(adc_char_value));
    }
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSIDiv = RCC_HSI_DIV1;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void delay_62_5ns(uint32_t ns)
{
  if (ns > 63)
  {
    for (uint32_t i = 0; i < (uint32_t)(ns/62.5) ; i++)
    {
      asm("nop");
    }
  }
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
