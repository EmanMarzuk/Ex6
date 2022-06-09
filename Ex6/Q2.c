#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* decToBinary(int n)
{
	char* r = (char*)malloc(sizeof(char));
	char* t = (char*)malloc(sizeof(char));
	t = r;
	int c, k, i;
	for (c = 15,i=0; c >= 0; c--,i--)
	{
		k = n >> c;

		if (k & 1)
			*t = '1';
		else
			*t = '0';
		t++;
	}
	return r;
}
void revstr(char* str1)
{
	// declare variable  
	int i, len, temp;
	len = findlen(str1); // use strlen() to get the length of str string  

	// use for loop to iterate the string   
	for (i = 0; i < len / 2; i++)
	{
		// temp variable use to temporary hold the string  
		temp = str1[i];
		str1[i] = str1[len - i - 1];
		str1[len - i - 1] = temp;
	}
}
int findlen(char* s) {
	int l = 0;
	while (*s == '0' || *s == '1')
	{
		l++;
		s++;
	}
	return l;
}

int binTodec(char* num) {
	int total = 0;
	while (*num)
	{
		total *= 2;
		if (*num++ == '1') total += 1;
	}
	return total;
}

char* twosc(char* num) {
	char r[17], t[16];
	int len = findlen(num), i, dnum;
	for (i = 0; i < len; i++) {
		r[i] = (int)(*num) ^ 1;
		num++;
	}
	r[i] = '\0';
	dnum = binTodec(r);
	dnum++;
	_itoa(dnum, r, 2);
	return r;
}


int checkEvenParity(short input) {
	char* posBinNum = (char*)malloc(sizeof(char) * 16);
	char* binNum = (char*)malloc(sizeof(char) * 16);
	int count = 0, negcount = 0;
	int j;
	if (input >= 0) {
		binNum = decToBinary(input);
	}
	else {
		posBinNum = decToBinary(input*-1);
		binNum = twosc(posBinNum);
		while (*posBinNum != '\0') {
			if (*posBinNum == '0')   negcount++;
			else  break;
			posBinNum++;
		}
		
	}
	for (int i = 1; i < 17; i++) {
		if (*binNum == '1') {
			count++;
		}
		binNum++;
	}
	if (input >= 0) {
		if (count % 2 == 0)	return 1;
		else    return 0;
	}
	else {
		if ((count - negcount) % 2 == 0)	return 1;
		else    return 0;
	}
}

void main() {
	int num;
	printf("Enter a number:");
	scanf(" %d", &num);
	if (checkEvenParity(num))	printf("The sum of the bits is even\n");
	else   printf("The sum of the bits is odd\n");
}