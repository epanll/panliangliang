#include "1_1602_lcd.h"
#include "2_light_sensor.h"
#include "3_pyroelectric_sensor.h"
#include "4_relay_led.h"

int main(void)
{	
	u8 i, time = 20;
	static char display[16];
	
	delay_init();
	uart_init(115200);

	LCD_Init();        //LCD1602配置初始化 
	Light_Sensor_Init();	//光敏传感器初始化
	Pyro_Sensor_Init();		//红外传感器初始化
	Relay_Led_Init();		//继电器&灯光控制		
	
	while(1)
	{
		if(Light_Sensor == 0)	//白天,关闭系统
		{
			
			DAY_LED = 0;	//打开白天指示灯
			NIGHT_LED = 1;	//关闭夜间指示灯
			
			LCD_Display_Str(0, 0, "DAY             ");
			LCD_Display_Str(0, 1, "SYSTEM CLOSED!  ");
			
			RELAY_CONTROL = 0;	//关闭继电器
			NIGHT_LIGHTING = 0;	//关闭LED灯
			
			delay_ms(1000);
		}
		else if(Light_Sensor == 1)	//夜间,开启系统
		{
			
			DAY_LED = 1;	//关闭白天指示灯
			NIGHT_LED = 0;	//打开夜间指示灯
			
			LCD_Display_Str(0, 0, "NIGHT           ");
			LCD_Display_Str(0, 1, "SYSTEM RUNNING! ");
			
			if(PYRO_SENSOR == 1)
			{
				//printf("exit person! \r\n");
				for(i = time; i > 0; i--)
				{
					delay_ms(1000);	//延时1s
					sprintf(display,"Running Time:%2dS",i);//显示器计时
					LCD_Display_Str(0,1,(u8 *)display);
					
					RELAY_CONTROL = 1;	//打开继电器
					NIGHT_LIGHTING = 1;	//打开LED灯
				}
				
			}
			else if(PYRO_SENSOR == 0)
			{
				//printf("exit no person! \r\n");
				RELAY_CONTROL = 0;	//关闭继电器
				NIGHT_LIGHTING = 0;	//关闭LED灯
				delay_ms(1000);
			}
			
			
		}
	}
	
	
}




















































