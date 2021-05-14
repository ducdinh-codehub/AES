#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int hexNum[16] = {
	0x0,0x1,0x2,0x3,
	0x4,0x5,0x6,0x7,
	0x8,0x9,0xa,0xb,
	0xc,0xd,0xe,0xf
};
int checkNumber(char a);
char checkChar(int a);
int main(){
	srand(time(NULL));
	//int a = (hexNum[0] << 8) | hexNum[15];
	//int a = (hexNum[1] << 4) | hexNum[3];
	//printf("%x",a);
	
	//Write hex number
	char str[32];
	for(int i =0; i < 32; i++){
		int r = rand() % 16;
		str[i] = checkChar(hexNum[r]);
	}
	for(int i =0; i < 32; i++){
		printf("%c",str[i]);
	}	
	//Read hex number from string convert it to int and store it inside inputBlock array
	printf("\n");
	int inputBlock[16];
	int countValueInputBlock = 0;
	char str2[32];
	strcmp(str2,str);
	//str2 = str;
	for(int i = 0; i < 32; i++){
		if(i%2!=0){
			inputBlock[countValueInputBlock] = (inputBlock[countValueInputBlock] << 4) 
									| hexNum[checkNumber(str2[i])];
			countValueInputBlock++;
		}
		inputBlock[countValueInputBlock] = hexNum[checkNumber(str2[i])];
		printf("%c ",str2[i]);
		printf(" ->Num: %d\n",checkNumber(str2[i]));
	}
	printf("\n");
	for(int i = 0; i < 16; i++){
		printf("%x \n",inputBlock[i]);
	}

	/*
	int i2;
	sscanf (str2,"%d",&i2);
	printf("%x",i2);*/
	/*
	int lamdaSet[32];
	int numberOfByteInSet = 1;// 32 byte = 256 bit
	int numberOfValueInOneset = 16;
	char oneSet[100];
	for(int i = 0; i < numberOfByteInSet; i++){
		for(int j = 0; j < numberOfValueInOneset; j++){
			if(j == 0){
				oneSet = "" + hexNum[]
			}
			int value;
			oneSet = oneSet + value; 
		}
	}*/
	return 0;
}
int checkNumber(char a){
	int rst = 0;
	switch (a){
		case '0':
			rst = 0;
			break;
		case '1':
			rst = 1;
			break;
		case '2':
			rst = 2;
			break;
		case '3':
			rst = 3;
			break;
		case '4':
			rst = 4;
			break;
		case '5':
			rst = 5;
			break;
		case '6':
			rst = 6;
			break;
		case '7':
			rst = 7;
			break;
		case '8':
			rst = 8;
			break;
		case '9':
			rst = 9;
			break;
		case 'a':
			rst = 10;
			break;
		case 'A':
			rst = 10;
			break;
		case 'b':
			rst = 11;
			break;
		case 'B':
			rst = 11;
			break;
		case 'c':
			rst = 12;
			break;
		case 'C':
			rst = 12;
			break;
		case 'd':
			rst = 13;
			break;
		case 'D':
			rst = 13;
			break;
		case 'e':
			rst = 14;
			break;
		case 'E':
			rst = 14;
			break;
		case 'f':
			rst = 15;
			break;
		case 'F':
			rst = 15;
			break;
	}
	return rst;
}

char checkChar(int a){
	char rst;
	switch(a){
		case 0:
			rst = '0';
			break;
		case 1:
			rst = '1';
			break;
		case 2:
			rst = '2';
			break;
		case 3:
			rst = '3';
			break;
		case 4:
			rst = '4';
			break;
		case 5:
			rst = '5';
			break;
		case 6:
			rst = '6';
			break;
		case 7:
			rst = '7';
			break;
		case 8:
			rst = '8';
			break;
		case 9:
			rst = '9';
			break;
		case 10:
			rst = 'a';
			break;
		case 11:
			rst = 'b';
			break;
		case 12:
			rst = 'c';
			break;
		case 13:
			rst = 'd';
			break;
		case 14:
			rst = 'e';
			break;
		case 15:
			rst = 'f';
			break;
	}
	return rst;
}