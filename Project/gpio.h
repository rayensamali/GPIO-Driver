/**
  ******************************************************************************
  * @file    Lab-Libraries/gpio.h 
  * @author  CSF Team
  * @mail    formation@csf.tn
  * @Tel     (+216)92.039.433
  * @version V1.0.0
  * @date    23-04-2024
  *****************************************************************************

/* Includes ------------------------------------------------------------------*/




/* GPIO_X adress*/
#define GPIO_A (unsigned int*) (0x40020000)
#define GPIO_B (unsigned int*) (0x40020400)
#define GPIO_C (unsigned int*) (0x40020800)
#define GPIO_D (unsigned int*) (0x40020C00)
#define GPIO_E (unsigned int*) (0x40021000)
#define GPIO_F (unsigned int*) (0x40021400)
#define GPIO_G (unsigned int*) (0x40021800)
#define GPIO_H (unsigned int*) (0x40021C00)
#define GPIO_I (unsigned int*) (0x40022000)
#define GPIO_J (unsigned int*) (0x40022400)
#define GPIO_K (unsigned int*) (0x40022800)
/*OFFSET REGISTER */ 

#define MODER_OFFSET  (0x00)
#define IDR_OFFSET   (0x10)
#define ODR_OFFSET   (0x14)// offset 0xc /4 = 0x3 : depend de pas de pointeur 
#define AHB1ENR_OFFSET   (0x30)
#define OTYPER_OFFSET  (0x04)

//....

/* mode  (MODER)*/

#define MODE_INPUT  0X00
#define MODE_OUTPUT  0X01
#define MODE_ALTERNATE_FUNC  0X10
#define MODE_ANALOG  0X11

/* TYPES DE SORTIE(otyper) */
#define OUTPUT_PUSH_PULL (char)  0
#define OUTPUT_OPEN_DRAIN (char)  1


/* position de pin dans les registres de lecture (IDR) et ecriture (ODR) */
#define GPIO_PIN_0  ((unsigned short) 0x0001)  // Pin 0 mask (0000 0000 0000 0001)
#define GPIO_PIN_1  ((unsigned short) 0x0002)  // Pin 1 mask (0000 0000 0000 0010)
#define GPIO_PIN_2  ((unsigned short) 0x0004)  // Pin 2 mask (0000 0000 0000 0100)
#define GPIO_PIN_3  ((unsigned short) 0x0008)  // Pin 3 mask (0000 0000 0000 1000)
#define GPIO_PIN_4  ((unsigned short) 0x0010)  // Pin 4 mask
#define GPIO_PIN_5  ((unsigned short) 0x0020)  // Pin 5 mask (1 << 5)
#define GPIO_PIN_6  ((unsigned short) 0x0040)  // Pin 6 mask
#define GPIO_PIN_7  ((unsigned short) 0x0080)  // Pin 7 mask
#define GPIO_PIN_8  ((unsigned short) 0x0100)  // Pin 8 mask
#define GPIO_PIN_9  ((unsigned short) 0x0200)  // Pin 9 mask
#define GPIO_PIN_10 ((unsigned short) 0x0400)  // Pin 10 mask
#define GPIO_PIN_11 ((unsigned short) 0x0800)  // Pin 11 mask
#define GPIO_PIN_12 ((unsigned short) 0x1000)  // Pin 12 mask
#define GPIO_PIN_13 ((unsigned short) 0x2000)  // Pin 13 mask
#define GPIO_PIN_14 ((unsigned short) 0x4000)  // Pin 14 mask
#define GPIO_PIN_15 ((unsigned short) 0x8000)  // Pin 15 mask
//(unsigned short)



/* -----------------ajouter les protopyes des fonctions----------------------*/
/* GPIO enable function */
//...
void GPIO_ClockEnable (unsigned int * gpio_x);
/* GPIO Resete function */
void GPIO_DeInit(unsigned int * gpio_x);

/* Config function */
void GPIO_Init(unsigned int * gpio_x, char Mode, char typeOutput, short int pin); // chat 1/4 registre // short 1/2 de registre // int registre complet

/* Read functions */
unsigned char GPIO_ReadInputDataBit(unsigned int * gpio_x, unsigned short int GPIO_Pin);
unsigned short int GPIO_ReadInputData(unsigned int * gpio_x);

/* Write functions */

void GPIO_WriteBit(unsigned int * gpio_x, unsigned short int GPIO_Pin, char BitVal);
void GPIO_Write(unsigned int * gpio_x, unsigned short int PortVal);


/******************* (C) COPYRIGHT 2019 CSF *****END OF FILE*******************/