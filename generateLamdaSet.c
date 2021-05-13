#include<stdio.h>
int hexNum[16] = {
	0x00,0x01,0x02,0x03,
	0x04,0x05,0x06,0x07,
	0x08,0x09,0x0a,0x0b,
	0x0c,0x0d,0x0e,0x0f
};
int main(){
	printf("%x",(hexNum[1] & 0x0f + hexNum[12]));
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