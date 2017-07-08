#include <stdio.h>
//Mourad<mohammadabdoulahi@gmail.com>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


int isLower(char c){
	return (c>='a'&&c<='z')?1:0;
}

int isUpper(char c){
	return (c>='A'&&c<='Z')?1:0;
}

char toLowerCase(char c){
	return (isLower(c))?(c):(c - 'A' + 'a');
}

char toUpperCase(char c){
	return (isUpper(c))?(c):(c - 'a' + 'A');
}

int getPositionOf(char c){
	return (isLower(c))?(c - 'a' + 1):(toLowerCase(c) - 'a' + 1);
}

char getNextOf(char c){
	return ((char)('a'+(getPositionOf(c))));
}

char shiftRight(char c, int n){
	char tab[] = {'a', 'b', 'c','d','e', 'f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	return tab[(getPositionOf(c)+n-1)%26];
}

char shiftLeft(char c, int n){
	char tab[] = {'a', 'b', 'c','d','e', 'f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	int res = (getPositionOf(c)-n)%26;
	int i=0;
	while(res<0){
		res = (getPositionOf(c)-n +(i*26))%26;
		i++;
	}
	return tab[res-1];
}

int rotateLeft(int x, int n){
	return (x << n) | (x >> (0x1F & (32 + ~n + 1))) & ~(0xFFFFFFFF << n);
}