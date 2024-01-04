#include "3_pyroelectric_sensor.h"
//红外热释电传感器

//光敏传感器初始化
void Pyro_Sensor_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;  //配置为浮空输入
	GPIO_Init(GPIOE, &GPIO_InitStructure);	
}
























































