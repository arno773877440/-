#pragma sfr

void delay_long(){
	int i,j;
	for(i = 0;i <= 200;i++)
		for(j = 0;j <= 200;j++);
}
void delay_short(){
	int i,j;
	for(i = 0;i <= 200;i++)
		for(j = 0;j <= 10;j++);
}
void main(){
	int Buzi;
	P3.3 = 0;
	PM3.3 = 0;
	BZOE = 0;
	while(1){
		for(Buzi = 3;Buzi > 0;Buzi--){
			CKS = 0X80;
			delay_short();
			BZOE = 0;
			CKS = 0XA0;
			delay_short();
			BZOE = 0;
			
			CKS = 0XC0;
			delay_short();
			BZOE = 0;
			
			CKS = 0XE0;
			delay_short();
			BZOE = 0;
		}
		
		for(Buzi = 3;Buzi > 0;Buzi--){
			CKS = 0X80;
			delay_long();
			BZOE = 0;
			
			CKS = 0XA0;
			delay_long();
			BZOE = 0;
			
			CKS = 0XC0;
			delay_long();
			BZOE = 0;
			
			CKS = 0XE0;
			delay_long();
			BZOE = 0;
			
		}
	}
}