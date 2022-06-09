#include<stdio.h>
#define S 8

void revstr(char* str1);
int findlen(char* s);
char* CharToAsciiBin(char num);

char* CharToAsciiBin(char num) {

	 char bits[S];
	 // finding the 8 bits ascii value
	 for (int i = 0; i < 8; i++)
	 {
		 bits[i] = (num >> i) & 1;
	 }
	 revstr(bits);
	 return bits;
}

int findlen(char* s) {
	int l = 0;
	while (*s==0||*s==1)
	{
		l++;
		s++;
	}
	return l;
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

void decToBinary(int n)
{
	int c, k;
	for (c = 31; c >= 0; c--)
	{
		k = n >> c;

		if (k & 1)
			printf("1");
		else
			printf("0");
	}
}

int pack4Chars2Int(char c1, char c2, char c3, char c4) {
	
	int res = ((int)(((unsigned char)c1) << 24) | (int)(((unsigned char)c2) << 16) | (int)(((unsigned char)c3) << 8 | (int)((unsigned char)c4)));
	printf("0b");
	decToBinary(res);
	printf("\n");
	return res;
}



void main() {
	int res = pack4Chars2Int('a', 'b', 'c', 'd');
	printf("The decimal value is: %d\n",res);
}
