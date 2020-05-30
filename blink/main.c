//PC6
//AHB
//RCC->AHBENR
//GPIOx_MODER
//GPIOx_ODR

#include "stm32f0xx.h" // Device header
void delayMs(int delay); 
int main(void)
{
	RCC->AHBENR  |= 1<<19;  //0x20000;
	GPIOC->MODER |= (1<<12 | 0<<13) ;//0x1000;   //1000 for red led 4000 for blue 5000 for both red and blue
	//GPIOC->MODER = 0<<13;
	
	while(1)
	{

		GPIOC->BSRR = 1<<6;  //red led
		for(int i=0; i<5000;i++);
		GPIOC->BSRR = 1<<(6+16); 
	  for(int i=0; i<5000;i++);
		
	}

}

void delayMs(int delay)
{
	int i;
	for(;delay>0; delay--){
	  for(i=0;i<3195;i++);
	}
}

