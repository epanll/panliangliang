#include "4_relay_led.h"

//继电器灯光控制
//白天指示灯	PB5
//晚上指示灯	PE5
//继电器控制	PB9
//晚上照明	PB8
void Relay_Led_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOE, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //配置为推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);	
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //配置为推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE, &GPIO_InitStructure);
	
	GPIO_SetBits(GPIOB, GPIO_Pin_5);	//白天指示灯	默认 关闭
	GPIO_SetBits(GPIOE, GPIO_Pin_5);	//晚上指示灯	默认 关闭
	GPIO_ResetBits(GPIOB, GPIO_Pin_9);	//继电器状态	默认 关闭
	GPIO_ResetBits(GPIOB, GPIO_Pin_8);	//晚上照明	默认 关闭
}
