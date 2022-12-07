
#include "includes.h"

uint8_t MCU_KEY;
uint8_t LAST_KEY;
uint16_t bat_volt;
uint16_t press_time=0;
uint8_t shift_1st=0;
uint8_t down_1st=0;
uint8_t shift_2nd=0;
uint8_t LONG_PRESS=0;
uint8_t SINGLE_PRESS=0;
uint8_t TWICE_PRESS=0;

char automsg[]={"nvidia\n"};
char revmsg[100];
char hello[]={"nvidia-desktop login:"};
char key[]={"key"};
uint8_t time=0;
uint8_t uart1_flag=0;


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (htim->Instance == htim3.Instance) {
			
			MCU_KEY=HAL_GPIO_ReadPin(MCU_KEY_GPIO_Port,MCU_KEY_Pin);
			if(MCU_KEY!=LAST_KEY&&MCU_KEY&&!shift_2nd)shift_1st=1;
			if(shift_1st)press_time++;
			if(shift_1st&&!MCU_KEY)down_1st=1;
			if(MCU_KEY!=LAST_KEY&&MCU_KEY&&down_1st){shift_2nd=1;}
			
			
			if(press_time>=1000){
			
				if(shift_1st&&shift_2nd){TWICE_PRESS=1;}
				if(shift_1st&&!shift_2nd&&down_1st){SINGLE_PRESS=1;}
        if(shift_1st&&!shift_2nd&&!down_1st){LONG_PRESS=1;}		
         
        press_time=0;				
//				TWICE_PRESS=0;
//				SINGLE_PRESS=0;
//				LONG_PRESS=0;
				shift_1st=0;
				shift_2nd=0;
				down_1st=0;
 			}
			LAST_KEY=MCU_KEY;
			
			
			if(SINGLE_PRESS){
			  htim1.Instance->CCR1=900;
				htim2.Instance->CCR2=900;
				HAL_TIM_PWM_Stop(&htim1,TIM_CHANNEL_1);
				HAL_TIMEx_PWMN_Start(&htim1,TIM_CHANNEL_1);
				HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
			  SINGLE_PRESS=0;
			}
			if(TWICE_PRESS){
//			  htim2.Instance->CCR2=900;
//				HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
//				HAL_TIMEx_PWMN_Stop(&htim1,TIM_CHANNEL_1);
				HAL_TIM_PWM_Stop(&htim2,TIM_CHANNEL_2);
			  TWICE_PRESS=0;
			}
			if(LONG_PRESS){
			  htim1.Instance->CCR1=900;
				HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
				HAL_TIMEx_PWMN_Stop(&htim1,TIM_CHANNEL_1);
				HAL_TIM_PWM_Stop(&htim2,TIM_CHANNEL_2);
			  LONG_PRESS=0;
			}
			
			HAL_ADC_Start(&hadc1);
			HAL_ADC_PollForConversion(&hadc1, 0xff);
			bat_volt=HAL_ADC_GetValue(&hadc1);  		
			if(UART_RX_STA & 0X8000){
			   HAL_UART_Transmit_DMA(&huart2, UART_RX_BUF, UART_RX_STA & 0X7FFF);          
			   UART_RX_STA = 0;
				 time++;
				 if(time%2==0)HAL_UART_Transmit_DMA(&huart1, (uint8_t*)automsg,sizeof(automsg)); 		
	    }			
    }    
}

//void HAL_UART_AbortReceiveCpltCallback (UART_HandleTypeDef *huart) {
//    if (huart == &huart1) {
//			
//     
//			//HAL_UART_Receive_DMA(&huart1, UART_RX_BUF, UART_RX_LEN);
//    } 
//}


void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{//        if (WS2812::ws2812.isWorking1) {

//    if(htim->Instance == htim8.Instance) {
//            WS2812::ws2812.isWorking1 = 0;
//            HAL_TIM_PWM_Stop_DMA(&htim8, TIM_CHANNEL_1);
//        }
//    }
//    if(htim->Instance == htim5.Instance) {
//        if (WS2812::ws2812.isWorking2) {
//            WS2812::ws2812.isWorking2 = 0;
//            HAL_TIM_PWM_Stop_DMA(&htim5, TIM_CHANNEL_4);
//        }
//    }
//    if(htim->Instance == htim2.Instance){
//        if(WS2812::ws2812.isWorking3) {
//            WS2812::ws2812.isWorking3=0;
//            HAL_TIM_PWM_Stop_DMA(&htim2, TIM_CHANNEL_4);
//        }
//    }

//    if (htim->Instance == htim8.Instance) {
//        if (WS2812::ws2812.isWorking1) {
//            WS2812::ws2812.isWorking1 = 0;
//            HAL_TIM_PWM_Stop_DMA(&htim8, TIM_CHANNEL_1);
//        }
//        if (WS2812::ws2812.isWorking2) {
//            WS2812::ws2812.isWorking2 = 0;
//            HAL_TIM_PWM_Stop_DMA(&htim8, TIM_CHANNEL_2);
//        }
//        if (WS2812::ws2812.isWorking3) {
//            WS2812::ws2812.isWorking3 = 0;
//            HAL_TIM_PWM_Stop_DMA(&htim8, TIM_CHANNEL_3);
//        }
//    }




}
