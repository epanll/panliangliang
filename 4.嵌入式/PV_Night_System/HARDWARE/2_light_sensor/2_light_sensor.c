#include "2_light_sensor.h"
//光敏传感器

//光敏传感器初始化
void Light_Sensor_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;//配置LCD数据接口
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;  //配置为推挽输出
	GPIO_Init(GPIOE, &GPIO_InitStructure);	
}













































