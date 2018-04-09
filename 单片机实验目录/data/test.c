#pragma sfr		//使用特殊功能寄存器
#pragma NOP		//使用空操作功能
#pragma DI		//使用关中断功能
#pragma EI		//使用开中断功能
#pragma rot		//使用循环移位功能
#pragma interrupt INTKR OnKeyPress		//使用按键中断功能

unsigned char gCurrentScheme = 0;		//当前小灯闪亮模式
unsigned char gFlag = 1；			//有按键按下时设置标志gFlag为0，否则为1

void Delay(int x){
	unsigned char i,j;
	for(i = 0;i < 200;i++){
		for(j = 0;j < x;j++){}
	}
}//软件延时函数

void InitKey_INTKR(void){
	PM4 = 0x3F;		//端口4的位5~位0为输入端口
	PU4 = 0x3F;		//设置端口4的位5~位0使用内部上拉电阻
	KRM = 0x3F;		//设置每个按键按下都会产生按键中断信号
	KRMK = 0;		//按键中断屏蔽标志设置为允许按键中断
}//按键中断初始化函数

__interrupt void OnKeyPress(void){
	DI();		//关中断
	gFlag = 0;		//设置有按键按下标志
	switch(P4 & 0x3F){		//检测P4端口的位5~位0的值
		case 0x3E:		//按下key1键
			gCurrentScheme = -1;break;	//选择0号LED灯闪亮模式
		case 0x3D:
			gCurrentScheme = 0;break;	//选择1号LED灯闪亮模式
		default:break;				//其他情况不选择
	}
	EI();		//开中断
	
}//按键中断函数

void InitLed(){
	PM13 = 0xF0;		//端口13的低4位为输出模式
	PM14 = 0xF0;		//端口14的低4位为输出模式
	PM15 = 0xF0;		//端口15的低4位为输出模式
}//LED灯端口模式初始化函数

void LightOneLed(unsigned char ucNum){
	switch(ucNum){		//检测变量ucNum
		case 0:
		case 1:
		case 2:
		case 3:
			P13 = (unsigned char) 1 << (ucNum);
			break;//如果ucNum为0~3中的一个值，就让LED1~LED4中的一个点亮
		case 4:
		case 5:
		case 6:
		case 7:
			P14 = (unsigned char) 1 << (ucNum - 4);
			break;//如果ucNum为4~7中的一个值，就让LED1~LED4中的一个点亮
		case 8:
		case 9:
		case 10:
		case 11:
			P15 = (unsigned char) 1 << (ucNum - 8);
			break;//如果ucNum为8~11中的一个值，就让LED1~LED4中的一个点亮
		default:
			break;
			
	}
}//点亮编号为unNum的1个小灯函数

void LightLeds(unsigned char *pNum,unsigned char unCnt){
	unsigned char i;
	for(i =0;i < unCnt;i++){	//循环unCnt次
		switch(*pNum){
			case 0:
			case 1:
			case 2:
			case 3:
				P13 |= (unsigned char) 1 << (*pNum);
				break;//左移pNum中值所指示的次数，然后和P13相或
 			
			case 4:
			case 5:
			case 6:
			case 7:
				P14 |= (unsigned char) 1 << (*pNum - 4);
				break;//左移pNum中值所指示的次数，然后和P14相或
			
			case 8:
			case 9:
			case 10:
			case 11:
				P15 |= (unsigned char) 1 << (*pNum - 8);
				break;//左移pNum中值所指示的次数，然后和P15相或
			break;
		}
		pNum++;
	}
}//点亮数组中指定位置的，变量中指定数量的小灯函数

void LightOff(){
	P13 = 0;		//端口P13的低4位输出为0
	P14 = 0;		//端口P14的低4位输出为0
	P15 = 0;		//端口P15的低4位输出为0
}//熄灭所有小灯

void Scheme_0(void){
	unsigned char i,j;
	for(j = 0;j < 2 && gFlag;i++){	//无按键中断时循环两次
		for(i = 0;i < 12 && gFlag;i++){
			LightOneLed(i);	
			Delay(10);	//调用软件延时函数
			LightOff();	//关闭所有LED灯
			Delay(10);	//调用软件延时函数
		}
	}
}//方案0

void Scheme_1(void){
	unsigned char Nums[6] = {0,1,2,3,4,5};
	unsigned char i,j;
	for(j = 0;j < 2 && gFlag;j++){
		for(i = 0;i < 12 && gFlag;i++){
			LightLeds(Nums,6);
			Delay(200);	//调用软件延时函数
			LightOff();	//关闭所有LED灯
			Delay(200);	//调用软件延时函数
			Nums[0] = (Nums[0] + 3) % 12;
			Nums[1] = (Nums[1] + 3) % 12;
			Nums[2] = (Nums[2] + 3) % 12;
			Nums[3] = (Nums[3] + 3) % 12;
			Nums[4] = (Nums[4] + 3) % 12;
			Nums[5] = (Nums[5] + 3) % 12;
		}
	}
}//方案1

void Scheme_2(void){
	unsigned char Nums[2] = {0,3};
	unsigned char i,j;
	for(j = 0;j < 2 && gFlag;j++){
		for(i = 0;i < 12 && gFlag;i++){
			LightLeds(Nums,2);
			Delay(200);
			LightOff();
			Delay(200);
			Nums[0] = (Nums[0] + 1) % 12;
			Nums[1] = (Nums[1] + 1) % 12;
		}
	}
}

void main(){
	InitLed();
	InitKey_INTKR();
	EI();
	while(1){
		switch(gCurrentScheme){
			case 0:
				gFlag = 1;
				Scheme_1();
				gCurrentScheme = ((++gCurrentScheme) % 6);
				break;
			case 1:
				gFlag = 1;
				Scheme_2();
				gCurrentScheme = ((++gCurrentScheme) % 6);
				break;
			default:
				break;
		}
	}
}