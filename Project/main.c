/**
  ******************************************************************************
  * @file    Lab-Libraries/main.c 
  * @author  CSF Team
  * @mail    formation@csf.tn
  * @Tel     (+216)92.039.433
  * @version V1.0.0
  * @date    23-04-2024
  *****************************************************************************/

#include "gpio.h"

/* Private define ------------------------------------------------------------*/
#define NOMBRE_BOUCLES 100
                                                       
/* Private function prototypes -----------------------------------------------*/
void Delay(volatile unsigned  int  nCount);


/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
  unsigned  int counter = 0x00;  

  /* Activer l'orloge pour le Port D */
  GPIO_ClockEnable (GPIO_D);

  /* re-intialiser les registers de port D */
 GPIO_DeInit(GPIO_D);
  
/* --- Configure PD12 et PD13 en mode Output Push pull */  
GPIO_Init(GPIO_D,MODE_OUTPUT,OUTPUT_PUSH_PULL,12);
GPIO_Init(GPIO_D,MODE_OUTPUT,OUTPUT_PUSH_PULL,13);

  for(counter=0; counter<NOMBRE_BOUCLES ; counter++)
  {
    
    /* User LD3: orange LED is a user LED connected to the I/O PD13 of the 
STM32F407VGT6.
  User LD4: green LED is a user LED connected to the I/O PD12 of the 
STM32F407VGT6.*/
    
    
   /* Turn On LD3 and LD4 */
   GPIO_WriteBit(GPIO_D,GPIO_PIN_12, 1);
   GPIO_WriteBit(GPIO_D,GPIO_PIN_13, 1);
    
    Delay(0x3FFFFF) ;
    
    /* Turn off LD3 and LD4 */
   GPIO_WriteBit(GPIO_D,GPIO_PIN_12, 0);
   GPIO_WriteBit(GPIO_D,GPIO_PIN_13, 0);
   
    Delay(0x3FFFFF) ;
           
  }
  while(1);
}
/**
  * @brief  Inserts a delay time.
  * @param  nCount: specifies the delay time length.
  * @retval None
  */
void Delay(volatile unsigned  int  nCount)
{
  for(; nCount != 0; nCount--);
}

/******************* (C) COPYRIGHT 22024 CSF *****END OF FILE*******************/