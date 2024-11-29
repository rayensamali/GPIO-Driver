/**
  ******************************************************************************
  * @file    Lab-Libraries/gpio.c
  * @author  CSF Team
  * @mail    formation@csf.tn
  * @Tel     (+216)92.039.433
  * @version V1.0.0
  * @date    28-04-2024
  *****************************************************************************
/* Includes ------------------------------------------------------------------*/

#include "gpio.h"

// Ajouter define pour RCC clock 
#define RCC 0x40023800
// Ajouter define pour RCC  reste 
//#define RCC_AHB1ENR (*(volatile unsigned int *)(RCC + AHB1ENR_OFFSET))
volatile unsigned short int * RCC_AHB1ENR = (volatile unsigned short int *) 0x40023830;
volatile unsigned short int * RCC_AHB1RSTR = (volatile unsigned short int *)0x40023810;
/**
  * @brief  Enable the gpio_x peripheral clock.
  * @param  gpio_x: where x can be (A..G) to select the GPIO peripheral.
  * @retval None
  */
void GPIO_ClockEnable(unsigned int* gpio_x) {
  
    if (gpio_x == GPIO_A) {
        *RCC_AHB1ENR |= (1 << 0);
    } else if (gpio_x == GPIO_B) {
       * RCC_AHB1ENR |= (1 << 1);
    } else if (gpio_x == GPIO_C) {
       * RCC_AHB1ENR |= (1 << 2);
    } else if (gpio_x == GPIO_D) {
      *  RCC_AHB1ENR |= (1 << 3);
    } else if (gpio_x == GPIO_E) {
      *  RCC_AHB1ENR |= (1 << 4);
    } else if (gpio_x == GPIO_F) {
       * RCC_AHB1ENR |= (1 << 5);
    } else if (gpio_x == GPIO_G) {
        *RCC_AHB1ENR |= (1 << 6);
    } else if (gpio_x == GPIO_H) {
        *RCC_AHB1ENR |= (1 << 7);
    } else if (gpio_x == GPIO_I) {
       * RCC_AHB1ENR |= (1 << 8);
    } else if (gpio_x == GPIO_J) {
        *RCC_AHB1ENR |= (1 << 9);
    } else if (gpio_x == GPIO_K) {
        *RCC_AHB1ENR |= (1 << 10);
    } else {
        // handle error case
    }
}


/**
* @brief Deinitializes the gpio_x peripheral registers to their default reset values.
* @param gpio_x: where x can be (A..G) to select the GPIO peripheral.
* @retval None
*/
void GPIO_DeInit(unsigned int * gpio_x){
  
  
  
  
      if (gpio_x == GPIO_A) {
        * RCC_AHB1RSTR  |= (1 << 0);
        * RCC_AHB1RSTR  &= ~(1 << 0);
    } else if (gpio_x == GPIO_B) {
        *RCC_AHB1ENR |= (1 << 1);
        * RCC_AHB1RSTR  &= ~(1 << 1);
    } else if (gpio_x == GPIO_C) {
        * RCC_AHB1RSTR  |= (1 << 2);
        * RCC_AHB1RSTR  &= ~(1 << 2);
    } else if (gpio_x == GPIO_D) {
       * RCC_AHB1RSTR  |= (1 << 3);
       * RCC_AHB1RSTR  &= ~(1 << 3);
    } else if (gpio_x == GPIO_E) {
      * RCC_AHB1RSTR  |= (1 << 4);
      * RCC_AHB1RSTR  &= ~(1 << 4);
    } else if (gpio_x == GPIO_F) {
       * RCC_AHB1RSTR  |= (1 << 5);
       * RCC_AHB1RSTR  &= ~(1 << 5);
    } else if (gpio_x == GPIO_G) {
      * RCC_AHB1RSTR  |= (1 << 6);
      * RCC_AHB1RSTR  &= ~(1 << 6);
    } else if (gpio_x == GPIO_H) {
       * RCC_AHB1RSTR  |= (1 << 7);
       * RCC_AHB1RSTR  &= ~(1 << 7);
    } else if (gpio_x == GPIO_I) {
       * RCC_AHB1RSTR  |= (1 << 8);
       * RCC_AHB1RSTR  &= ~(1 << 8);
    } else if (gpio_x == GPIO_J) {
       * RCC_AHB1RSTR  |= (1 << 9);
       * RCC_AHB1RSTR  &= ~(1 << 9);
    } else if (gpio_x == GPIO_K) {
       * RCC_AHB1RSTR  |= (1 << 10);
       * RCC_AHB1RSTR  &= ~(1 << 10);
    } else {
        // handle error case
    }
 
 
  
}


/**
* @brief Configure the gpio_x
* @param gpio_x: where x can be (A..G) to select the GPIO peripheral.
* @param Mode: can be INPUT, OUTPUT, AF or AN
* @param typeOutput: can be PP or OD
* @param pin: can be 0...15
* @retval None
*/
#include "gpio.h"

void GPIO_Init(unsigned int* gpio_x, char Mode, char typeOutput, short int pin){// char 
  
  unsigned int mask = ~(0x3 << (pin*2)); // declaration de mask pour ecrire des 00 pour le mode choisit pour chaque pin .
  
  *(gpio_x + MODER_OFFSET/4) &= mask ; // reset de moder forcer les bits concerné a 0
  *(gpio_x + MODER_OFFSET/4) |=  (Mode << (pin*2));// appliquer le mode chaoisit par l'utilisateur
   mask = ~(1 << (pin));
  if(typeOutput == OUTPUT_PUSH_PULL){
     *(gpio_x + OTYPER_OFFSET/4)&= mask ;
  }else{
     *(gpio_x + OTYPER_OFFSET/4)&= ~mask ;
  }
  
  
   /* volatile unsigned int* MODER = (unsigned int*)((char*)gpio_x + MODER_OFFSET);
    volatile unsigned int* OTYPER = (unsigned int*)((char*) gpio_x + OTYPER_OFFSET);

    // Enable clock for the GPIO port
    GPIO_ClockEnable(gpio_x);

    // Reset MODER for the pin
    *MODER &= ~(0x3 << (pin * 2));
    *MODER |= (Mode << pin);
    *MODER &= ~(Mode << pin++);
    // Reset OTYPER for the pin
    *OTYPER &= ~(1 << pin);
    *OTYPER |= (typeOutput << pin);*/
}


/**
* @brief Reads the specified input port pin.
* @param gpio_x: where x can be (A..G) to select the GPIO peripheral.
* @param GPIO_Pin: specifies the port bit to read.
* This parameter can be GPIO_Pin_x where x can be (0..15).
* @retval The input port pin value.
*/
unsigned char GPIO_ReadInputDataBit(unsigned int * gpio_x, unsigned short int GPIO_Pin){
      
  
  
  //return (*(gpio_x +IDR_OFFSET) & GPIO_Pin);
  
  unsigned char  bit_status= 0x00;
  if((*(gpio_x +IDR_OFFSET/4) & GPIO_Pin) != 0x00){// por tester entre deux valeure 0 et autre on applique cette methode !=0  
    bit_status=0x01;
  }else {
    bit_status = 0x00;
  }
  return bit_status;
  
 /* // pointer sur l'adresse de l'odr de gpio correspondant 
   volatile unsigned int *ODR = (unsigned int*) ((char*)gpio_x + ODR_OFFSET);
   // extraire la valuere de ODR
   unsigned int idr_value = *ODR;
   
   // extraire la valeure de pin correspondant ;
   
   if(idr_value & GPIO_Pin){ 
    return (unsigned char) 1 ;
   }else{
    return (unsigned char) 0 ;
   }*/
   
}

/**
* @brief Reads the specified GPIO input data port.
* @param gpio_x: where x can be (A..G) to select the GPIO peripheral.
* @retval GPIO input data port value.
*/
unsigned short int GPIO_ReadInputData(unsigned int * gpio_x){
   return *(gpio_x +IDR_OFFSET/4);
}
/**
* @brief Sets or clears the selected data port bit.
* @param gpio_x: where x can be (A..G) to select the GPIO peripheral.
* @param GPIO_Pin: specifies the port bit to be written.
* This parameter can be one of GPIO_Pin_x where x can be (0..15).
* @param BitVal: specifies the value to be written to the selected bit.
* This parameter can be one of the BitAction enum values:
* @arg Bit_RESET: to clear the port pin
* @arg Bit_SET: to set the port pin
* @retval None
*/

// inline // atomic = volatile proteger contre l'ecriture d'interruption 
void GPIO_WriteBit(unsigned int * gpio_x, unsigned short int GPIO_Pin, char BitVal){
   // pointer sur l'adresse de l'odr  de gpio correspondant 
    
  if(BitVal != 0){
     *(gpio_x +ODR_OFFSET/4) |= GPIO_Pin;
  }else{
    *(gpio_x +ODR_OFFSET/4) &= ~GPIO_Pin;
  }
  
  
}

/**
* @brief Writes data to the specified GPIO data port.
* @param gpio_x: where x can be (A..G) to select the GPIO peripheral.
* @param PortVal: specifies the value to be written to the port output data register.
* @retval None
*/

void GPIO_Write(unsigned int * gpio_x, unsigned short int PortVal){
  
  volatile unsigned int * ODR =  (unsigned int*) ((char*)gpio_x + ODR_OFFSET/4);
  
  *ODR = PortVal;
 
}
/******************* (C) COPYRIGHT 2024 CSF *****END OF FILE*******************/


//flash latency (tres faible ) config de RCC 