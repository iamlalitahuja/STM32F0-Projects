
#include "stm32f0xx.h"                  // Device header
void usart1_init(void);
void usart_write(int ch);
int main(void){

	usart1_init();
	while(1){
	
		usart_write('H');
		usart_write('i');
	
	}

}

void usart1_init(void){
	RCC->APB2ENR |= 1<<14;  //APB2 bit 14 is USART1
	RCC->AHBENR  |= 1<<17;  //USART1 connected to PA10 rx PA9 tx

	GPIOA->AFR[1] = 0x70;			//enabling alternating function 7(0111) on bit 9
	GPIOA->MODER |= 0x80000;  //Set PA9 to alternate function
	
	USART1->BRR = 0x341;      //@9600 baud rate
	USART1->CR1 |= 0x0008;    // enabling the 3rd TE (transmission enable) bit high
	USART1->CR1 |= 0x0001;	  // enabling the 1st UE (usart enable) bit high
}

void usart_write(int ch){
	while(!(USART1->ISR & 0x0080)){}
	USART1->TDR = (ch & 0xFF);
}

