#pragma sfr		//ʹ�����⹦�ܼĴ���
#pragma NOP		//ʹ�ÿղ�������
#pragma DI		//ʹ�ù��жϹ���
#pragma EI		//ʹ�ÿ��жϹ���
#pragma rot		//ʹ��ѭ����λ����
#pragma interrupt INTKR OnKeyPress		//ʹ�ð����жϹ���

unsigned char gCurrentScheme = 0;		//��ǰС������ģʽ
unsigned char gFlag = 1��			//�а�������ʱ���ñ�־gFlagΪ0������Ϊ1

void Delay(int x){
	unsigned char i,j;
	for(i = 0;i < 200;i++){
		for(j = 0;j < x;j++){}
	}
}//�����ʱ����

void InitKey_INTKR(void){
	PM4 = 0x3F;		//�˿�4��λ5~λ0Ϊ����˿�
	PU4 = 0x3F;		//���ö˿�4��λ5~λ0ʹ���ڲ���������
	KRM = 0x3F;		//����ÿ���������¶�����������ж��ź�
	KRMK = 0;		//�����ж����α�־����Ϊ�������ж�
}//�����жϳ�ʼ������

__interrupt void OnKeyPress(void){
	DI();		//���ж�
	gFlag = 0;		//�����а������±�־
	switch(P4 & 0x3F){		//���P4�˿ڵ�λ5~λ0��ֵ
		case 0x3E:		//����key1��
			gCurrentScheme = -1;break;	//ѡ��0��LED������ģʽ
		case 0x3D:
			gCurrentScheme = 0;break;	//ѡ��1��LED������ģʽ
		default:break;				//���������ѡ��
	}
	EI();		//���ж�
	
}//�����жϺ���

void InitLed(){
	PM13 = 0xF0;		//�˿�13�ĵ�4λΪ���ģʽ
	PM14 = 0xF0;		//�˿�14�ĵ�4λΪ���ģʽ
	PM15 = 0xF0;		//�˿�15�ĵ�4λΪ���ģʽ
}//LED�ƶ˿�ģʽ��ʼ������

void LightOneLed(unsigned char ucNum){
	switch(ucNum){		//������ucNum
		case 0:
		case 1:
		case 2:
		case 3:
			P13 = (unsigned char) 1 << (ucNum);
			break;//���ucNumΪ0~3�е�һ��ֵ������LED1~LED4�е�һ������
		case 4:
		case 5:
		case 6:
		case 7:
			P14 = (unsigned char) 1 << (ucNum - 4);
			break;//���ucNumΪ4~7�е�һ��ֵ������LED1~LED4�е�һ������
		case 8:
		case 9:
		case 10:
		case 11:
			P15 = (unsigned char) 1 << (ucNum - 8);
			break;//���ucNumΪ8~11�е�һ��ֵ������LED1~LED4�е�һ������
		default:
			break;
			
	}
}//�������ΪunNum��1��С�ƺ���

void LightLeds(unsigned char *pNum,unsigned char unCnt){
	unsigned char i;
	for(i =0;i < unCnt;i++){	//ѭ��unCnt��
		switch(*pNum){
			case 0:
			case 1:
			case 2:
			case 3:
				P13 |= (unsigned char) 1 << (*pNum);
				break;//����pNum��ֵ��ָʾ�Ĵ�����Ȼ���P13���
 			
			case 4:
			case 5:
			case 6:
			case 7:
				P14 |= (unsigned char) 1 << (*pNum - 4);
				break;//����pNum��ֵ��ָʾ�Ĵ�����Ȼ���P14���
			
			case 8:
			case 9:
			case 10:
			case 11:
				P15 |= (unsigned char) 1 << (*pNum - 8);
				break;//����pNum��ֵ��ָʾ�Ĵ�����Ȼ���P15���
			break;
		}
		pNum++;
	}
}//����������ָ��λ�õģ�������ָ��������С�ƺ���

void LightOff(){
	P13 = 0;		//�˿�P13�ĵ�4λ���Ϊ0
	P14 = 0;		//�˿�P14�ĵ�4λ���Ϊ0
	P15 = 0;		//�˿�P15�ĵ�4λ���Ϊ0
}//Ϩ������С��

void Scheme_0(void){
	unsigned char i,j;
	for(j = 0;j < 2 && gFlag;i++){	//�ް����ж�ʱѭ������
		for(i = 0;i < 12 && gFlag;i++){
			LightOneLed(i);	
			Delay(10);	//���������ʱ����
			LightOff();	//�ر�����LED��
			Delay(10);	//���������ʱ����
		}
	}
}//����0

void Scheme_1(void){
	unsigned char Nums[6] = {0,1,2,3,4,5};
	unsigned char i,j;
	for(j = 0;j < 2 && gFlag;j++){
		for(i = 0;i < 12 && gFlag;i++){
			LightLeds(Nums,6);
			Delay(200);	//���������ʱ����
			LightOff();	//�ر�����LED��
			Delay(200);	//���������ʱ����
			Nums[0] = (Nums[0] + 3) % 12;
			Nums[1] = (Nums[1] + 3) % 12;
			Nums[2] = (Nums[2] + 3) % 12;
			Nums[3] = (Nums[3] + 3) % 12;
			Nums[4] = (Nums[4] + 3) % 12;
			Nums[5] = (Nums[5] + 3) % 12;
		}
	}
}//����1

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