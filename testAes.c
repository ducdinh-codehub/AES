#include<stdio.h>
//All function for encryption
int mulp2(int in);
int mulp3(int in);
int mulpAll(int in1, int in2, int in3, int in4);
void displayArray(int in[16],char displayName[50]);
void subBytes(int in[16]);
void subBytesKeySchedule(int in[4]);
void shiftRow(int in[16]);
void mixColumns(int in[16]);
void keySchedule(int in[16], int numColRcon);
void addRoundKey(int input[16], int key[16]);
char checkChar(int a);
//Global variable for encryption
int sbox[256] =   {
	//0     1    2      3     4    5     6     7      8    9     A      B    C     D     E     F
	0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76, //0
	0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0, //1
	0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15, //2
	0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75, //3
	0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84, //4
	0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf, //5
	0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8, //6
	0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2, //7
	0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73, //8
	0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb, //9
	0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79, //A
	0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08, //B
	0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a, //C
	0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e, //D
	0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf, //E
	0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16 }; //F
int rcon[40] = {
	//0		1	 2	   3	 4	   5	 6	   7	 8	   9
	0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, //0
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //1
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //2
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //3
};

int main(){
	printf("Hello world !!!\n");
	/*
	char plainText[255];
	printf("Type your plain text:\n");
	fgets(plainText, sizeof(plainText), stdin); // read input
	printf("Your string: %s\n",plainText);
	*/
	// Create block
	/*
	int inputBlock[16] = {
		//0		1		2		3	
		0x19, 0xa0,   0x9a,    0xe9,
		0x3d, 0xf4,   0xc6,    0xf8,
		0xe3, 0xe2,	  0x8d,    0x48,
		0xbe, 0x2b,   0x2a,    0x08
	};*/
	FILE *ftpr;
	ftpr = fopen("aesResult.txt","w");
	int inputBlock[16] = {
		//0		1		2		3	
		0x32, 0x88,   0x31,    0xe0,
		0x43, 0x5a,   0x31,    0x37,
		0xf6, 0x30,	  0x98,    0x07,
		0xa8, 0x8d,   0xa2,    0x34
	};
	int keyBlock[16] = {
		//0		1		2		3
		0x2b, 	0x28, 	0xab, 	0x09,
		0x7e, 	0xae, 	0xf7, 	0xcf,
		0x15, 	0xd2,	0x15, 	0x4f,
		0x16,	0xa6,	0x88, 	0x3c
	};
	addRoundKey(inputBlock,keyBlock);
	for(int time = 0 ; time < 9; time++){
		//Checking section
		displayArray(inputBlock,"Original");

		//SubBytes
		subBytes(inputBlock);
		//Checking section
		displayArray(inputBlock,"After SubBytes");

		//ShiftRow
		shiftRow(inputBlock);
		//Checking section
		displayArray(inputBlock,"After ShiftRow");

		//MixColumns
		mixColumns(inputBlock);	
		//Checking section
		displayArray(inputBlock,"After MixColumns");

		//KeySchedule
		displayArray(keyBlock,"Original key block");
		keySchedule(keyBlock, time);
		//Checking section
		displayArray(keyBlock,"New keyBlock");

		//AddRoundKey
		addRoundKey(inputBlock,keyBlock);
		//Checking section
		displayArray(inputBlock,"After AddRoundKey");
	}
	//Ending round
	subBytes(inputBlock);
	shiftRow(inputBlock);
	keySchedule(keyBlock,9);
	addRoundKey(inputBlock,keyBlock);
	//Checking section
	displayArray(inputBlock, "Encryption result");
	
	//Writing result to file

	for(int k = 0; k < 16; k++){
		//printf("%d and %d\n", (inputBlock[k] >> 4), (inputBlock[k] & 0xf));
		fputc(checkChar(inputBlock[k] >> 4), ftpr);
		fputc(checkChar(inputBlock[k] & 0xf), ftpr);
	}
	fputc('\n',ftpr);

	return 0;
}

int mulp2(int in){
	int kq = in << 1;
	if(kq>256) kq = kq ^ 0x11B;
	kq = kq & 0xFF;
	return kq;
}
int mulp3(int in){
	int kq = in ^ mulp2(in);
	kq = kq & 0xFF;
	return kq;
}
int mulpAll(int in1, int in2, int in3, int in4){
	int kq1 = mulp2(in1) ^ mulp3(in2) ^ in3 ^ in4;
	int kq2 = in1 ^ mulp2(in2) ^ mulp3(in3) ^ in4;
	int kq3 = in1 ^ in2 ^ mulp2(in3) ^ mulp3(in4);
	int kq4 = mulp3(in1) ^ in2 ^ in3 ^ mulp2(in4);
	int kq = (kq1 << 24) | (kq2 << 16) | (kq3 << 8) | kq4;
	return kq;
}
void displayArray(int in[16],char displayName[50]){
	printf("%s\n", displayName);
	for(int i = 0; i < 16; i++){
		if(i!=0 && i%4==0){
			printf("\n");
		}
		if(in[i] < 16){
			printf("0%x  ",in[i]);
		}else{
			printf("%x  ",in[i]);
		}
	}
	printf("\n");
}
void subBytes(int in[16]){
	for(int i = 0; i < 16; i++){
		int rowNum = in[i] >> 4;
		int leftNum = in[i] & 0xf;
		in[i] = sbox[16 * rowNum + leftNum];
	}
}
void subBytesKeySchedule(int in[4]){
	for(int i = 0; i < 4; i++){
		int rowNum = in[i] >> 4;
		int leftNum = in[i] & 0xf;
		in[i] = sbox[16 * rowNum + leftNum];
	}
}
void shiftRow(int in[16]){
	int tmp;
	int numOfRotate = 4;
	int countChange = 0;
	int countRotateRound = 0;
	for(int row = 0; row < 4; row++){
		countRotateRound = 0;
		while(countRotateRound < 4 - numOfRotate){
			int startValue;
			for(int col = 0; col < 4; col++){
				// Value at start position = Value at end position
				if(col == 0){
					int startPosition = 4 * row + 0;
					startValue = in[startPosition];
				}
				if(col == 3){
					int endPosition = 4 * row + 3;
					in[endPosition] = startValue;
					break;
				}
				// Change order different number
					int currentPosition = 4 * row + col;
					int nxtPosition = 4 * row + (col + 1);
					in[currentPosition] = in[nxtPosition];
			}
			countRotateRound += 1;
		}
		numOfRotate -= 1;
	}
}
void mixColumns(int in[16]){
	for(int col = 0; col < 4; col++){
		//Get input.
		int in1 = in[4 * 0 + col];
		int in2 = in[4 * 1 + col];
		int in3 = in[4 * 2 + col];
		int in4 = in[4 * 3 + col];

		//Calculating multiplication and get result.
		int rst = mulpAll(in1, in2, in3, in4);
		int rst1 = (rst >> 24) & 0xFF;
		int rst2 = (rst >> 16) & 0xFF;
		int rst3 = (rst >> 8)  & 0xFF;
		int rst4 = rst & 0xFF;

		//Re initial new values for input array.
		in[4 * 0 + col] = rst1;
		in[4 * 1 + col] = rst2;
		in[4 * 2 + col] = rst3;
		in[4 * 3 + col] = rst4;
	}
}
void keySchedule(int in[16], int numColRcon){
		int newKeyBlock[16];
		int col = 0;
		int startColumnValue;

		//Get value
		int colBlock[4];
		colBlock[0] = in[4 * 0 + 3];
		colBlock[1] = in[4 * 1 + 3];
		colBlock[2] = in[4 * 2 + 3];
		colBlock[3] = in[4 * 3 + 3];

		//Rot word
		for(int i = 0; i < 4; i++){
			if(i == 0){
			 	startColumnValue = colBlock[0];
			}
			colBlock[i] = colBlock[i + 1];
		}
		colBlock[3] = startColumnValue;

		//Sub byte
		subBytesKeySchedule(colBlock);
		//Xor
		colBlock[0] = colBlock[0] ^ in[4 * 0 + 0] 
						^ rcon[10 * 0 + numColRcon];
		colBlock[1] = colBlock[1] ^ in[4 * 1 + 0] 
						^ rcon[10 * 1 + numColRcon];
		colBlock[2] = colBlock[2] ^ in[4 * 2 + 0] 
						^ rcon[10 * 2 + numColRcon];
		colBlock[3] = colBlock[3] ^ in[4 * 3 + 0] 
						^ rcon[10 * 3 + numColRcon];

		for(int j = 0; j < 4; j++){
			if(j == 0){
				newKeyBlock[4 * 0 + j] = colBlock[0];
				newKeyBlock[4 * 1 + j] = colBlock[1];
				newKeyBlock[4 * 2 + j] = colBlock[2];
				newKeyBlock[4 * 3 + j] = colBlock[3];
			}
			else{
				newKeyBlock[4 * 0 + j] = 
					(in[4 * 0 + j] ^ newKeyBlock[4 * 0 + (j - 1)]) & 0xff;
				newKeyBlock[4 * 1 + j] = 
					(in[4 * 1 + j] ^ newKeyBlock[4 * 1 + (j - 1)]) & 0xff;
				newKeyBlock[4 * 2 + j] = 
				    (in[4 * 2 + j] ^ newKeyBlock[4 * 2 + (j - 1)]) & 0xff;
				newKeyBlock[4 * 3 + j] = 
					(in[4 * 3 + j] ^ newKeyBlock[4 * 3 + (j - 1)]) & 0xff;
			}
		}	

		//Save new key
		for(int h = 0; h < 16; h++){
			in[h] = newKeyBlock[h];
		}
}
void addRoundKey(int input[16], int key[16]){
	for(int row = 0; row < 4; row++){
		for(int col = 0; col < 4; col++){
			input[4 * row + col] = (input[4 * row + col] 
				^ key[4 * row + col]) & 0xff;
		}
	}
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