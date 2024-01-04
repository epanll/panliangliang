#include "1_1602_lcd.h"
//1602显示屏

//LCD引脚初始化配置
static void LCD_GPIO_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOF, ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|
								  GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|
								  GPIO_Pin_6|GPIO_Pin_7;//配置LCD数据接口
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //配置为推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //配置IO口速度为50MHz
	GPIO_Init(GPIOF, &GPIO_InitStructure);	          //初始化GPIOD7~0
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7;//配置LCD命令接口
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //配置为推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //配置IO口速度为50MHz
	GPIO_Init(GPIOA, &GPIO_InitStructure);	          //初始化GPIOC12~10
}

//向GPIOD的低8位写入8位数据  接线从第几位开始就向左移几位
static void Write_Byte(u8 data)
{
	GPIO_Write(GPIOF,data);//写操作最小的建立时间为40ns
	delay_ms(10);
}


//LCD写命令
static void LCD_Write_Command(u8 cmd)
{
	//配置写入命令
	Clr_RS;
	//delay_ms(3);
	Clr_RW;
	//delay_ms(3);
	Clr_EN;
	//delay_ms(3);

	//写入命令操作
	Write_Byte(cmd);//写完操作最小延迟10ns
	
	Set_EN;
	delay_ms(5);
	Clr_EN;		//写入完毕  拉低功能引脚
}

//LCD写数据
static void LCD_Write_Data(u8 dat)
{
	//配置写入数据
	Set_RS;
	//delay_ms(3);
	Clr_RW;
	//delay_ms(3);
	Clr_EN;
	//delay_ms(3);
	
	//写入命令操作
	Write_Byte(dat);//写完操作最小延迟10ns
	
	Set_EN;
	delay_ms(5);
	Clr_EN;	//写入完毕  拉低功能引脚
}
	
//LCD初始化
void LCD_Init(void)
{
	LCD_GPIO_Init();//初始化GPIO
	
	LCD_Write_Command(0x38);	//工作方式设置（8位数据接口，两行显示，5*8点阵）
	delay_ms(5);
	
	LCD_Write_Command(0x0C);	//显示开关控制指令设置（显示开+光标不显示+光标不闪烁）
	delay_ms(5);
	/*
	0x0E显示开+光标显示+光标不闪烁
	0x0F显示开+光标显示+光标闪烁
	*/
	
	LCD_Write_Command(0x06);	//光标模式设置指令（写入数据后光标右移 显示不移动）
	delay_ms(5);
	/*
	0x07写入数据后右移+显示移动
	0x05左移+显示移动
	0x04左移+显示不移动
	*/
	
	LCD_Write_Command(0x01);	//清屏设置
	delay_ms(5);
	
	//LCD_Write_Command(0x02);//光标归为  返回屏幕左上角  不改变屏幕显示内容

}

//清屏函数
void LCD_Clear(void)
{
	LCD_Write_Command(0x01);
	delay_ms(5);
}

//设置光标坐标
static void Set_Cursor(u8 x,u8 y)
{
	u8 addr;
	if(y == 0)
		addr = 0x00+x;
	else
		addr = 0x40+x;
	LCD_Write_Command(addr | 0x80);
}

//显示字符串
void LCD_Display_Str(u8 x,u8 y,u8 *str)
{
	Set_Cursor(x,y);
	
	while(*str != '\0')
	{
		LCD_Write_Data(*str++);
	}
}

//显示字符函数
void LCD_Display_Char(u8 x,u8 y,char dat)
{
	Set_Cursor(x,y);
	LCD_Write_Data(dat);
}

//长数据滚动显示
/*
@str：要显示的数据
@RL： 0：向左滚动   非零：向右移动
*/
void LCD_RunDisplay(u8 x,u8 y,u8 *str,u8 RL)
{
	if(RL==0)
	{
		LCD_Write_Command(0x18);
	}
	else
		
		LCD_Write_Command(0x1C);
	
	Set_Cursor(x,y);
	
	while(*str != '\0')
	{
		LCD_Write_Data(*str++);
	}
}

//倒计时显示函数
//time:单位s
void LCD1602_countdown(u8 time)
{
	u8 i;
	char display[16];
	
	LCD_Clear();       //LCD1602清屏
	LCD_Display_Str(0,0,"CONTROL SYSTEM");
	
	for(i = time; i > 0; i--)
	{
		delay_ms(1000);	//延时60ms
		sprintf(display,"Running Time:%2dS",i);//显示器计时
		LCD_Display_Str(0,1,(u8 *)display);
	}
	
}















































