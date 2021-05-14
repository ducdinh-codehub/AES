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
	FILE *fptr;
	fptr = fopen("lambdaSet.txt","w");
	//Concatenate 2 hexa numbers
	//int a = (hexNum[1] << 4) | hexNum[3];
	
	//Random generate and Write hex number to file
	char str[33];
	int firstCharacterEachLine = 0;
	int nextCharacterEachLine = 0;
	
	//int activePos = 0;
	int numberOfActiveColumn = 2;
	int activePos[numberOfActiveColumn];
	activePos[0] = 0;
	activePos[1] = 30;
	int tmp1[numberOfActiveColumn];
	int tmp2[numberOfActiveColumn];

	for(int i = 0; i < numberOfActiveColumn; i++){
		if(activePos[i] % 2 == 0){ // active position first value have to start with even number.
			activePos[i] = activePos[i] % 31; // start value of activePosition can't reach out of 30.
		}
		tmp1[i] = 0;
		tmp2[i] = 0;
	}
	char startValue[30];
	int countRand = 0;
	int j = 0;
	for(int line = 0; line < 256; line++){
		
			// Random character each line
			
			for(int i = 0; i < 33; i++){
				if(j == numberOfActiveColumn){
					j = 0;
					//tmp1 = 0;
					//tmp2 = 0;
				}
				if(i == activePos[j]){
					if(tmp2[j] == 16){
						tmp1[j] += 1;
						tmp2[j] = 0;
					}
					str[activePos[j]] = checkChar(tmp1[j]);
				}
				else if(i == activePos[j] + 1){
					str[activePos[j] + 1] = checkChar(tmp2[j]);
					tmp2[j] += 1;
					j += 1;
				}

				else{
					if(i != 32){
						if(line < 1){
							int r = rand() % 16;
							startValue[i] = checkChar(hexNum[r]);
							countRand += 1;
						}
						str[i] = startValue[i];

					}else{
						str[i] = '\n';
					}
				}
				fputc(str[i], fptr);
			}
		
	}
	fclose(fptr);
	/*
	for(int i =0; i < 32; i++){
		printf("%c",str[i]);
	}*/	
	//Read hex number from string convert it to int and store it inside inputBlock array
	printf("\n");
	int inputBlock[16];
	int countValueInputBlock = 0;
	char str2[32];
	strcpy(str2,str);
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