#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int main() {
	char ch1[50], *ch2, *ch3;
	char ch;
	FILE *in;
	printf("请输入需要打开的文件名:");
	//scanf("%s", ch1);
	if ((in = fopen("test.txt", "rt")) == NULL) {
		printf("打开文件失败！\n");
		system("pause");
		return 0;
	}
	else {
		ch = fgetc(in);
		while (ch != EOF) {
			fputc(ch, in);
			ch = fgetc(in);
		}
	}
	fclose(in);
	//fclose(out);


	system("pause");
	return 0;
}