//Mourad<mohammadabdoulahi@gmail.com>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "chars.h"

#define MAX 10000
#define ACTION_ENCRYPT "-e"
#define ACTION_DECRYPT "-d"

//Function to read file
int readFile(char const * file, char * res, int* n, char * mode){
	int i=0;
	char c = ' ';
	int size = MAX;
	char * string = (char*)malloc(sizeof(char)*MAX);
	FILE* stream = NULL;
	stream = fopen(file, mode);
	if (stream==NULL)
	{
		printf("Opening failed.\n");
		return 0;
	}else{
		printf("Opening...\n");
		i=0;
		while (c!=EOF)
		{
			if(c==EOF) break;
			c = fgetc(stream);
			i++;
			if(i<=MAX){
				res[i-1]=(char)c;
			}
		};
		*n=i-1;
		fread(res, sizeof(char), *n, stream);
	}
	fclose(stream);
	return 1;	
}

//Function to encrypt the text
int encrypt(char * string, int n, int size){
	int i=0;
	char c = ' ';
	char s = ' ';
	int end = 0;
	while(c!='\0')
	{
		
		c =string[i];
		*(string + i ) = toLowerCase(*(string + i));
		i++;
	}
	FILE * stream = NULL;
	stream = fopen("encrypted.enc", "w+");
	if (stream == NULL)
	{
		printf("Opening failed.\n");
		return 0;
	}else{
		c= ' ';
		i=0;
		
		while(c!='\0' && i<size){
			*(string + i) = shiftRight(*(string + i), n);
			i++;
		}

		fwrite(string, sizeof(*string), size, stream);
		
			printf("Text encrypted into file 'encrypted.enc'.\n");
		
		return 1;
	}
	fclose(stream);
}

//Function to decrypt the file
int decrypt(char const * filename, int key, int size){
	int i=0;
	char c = ' ';
	int end = 0;
	char * str = (char*)malloc(sizeof(char)*MAX);
	int r = readFile("encrypted.enc", str, &size, "r+");
	*(str + size) = '\0';
	FILE * stream = NULL;
	stream = fopen("decrypted.txt", "w+");
	if (stream == NULL)
	{
		printf("Opening failed.\n");
		return 0;
	}else{
		printf("Opening...\n");
		c= ' ';
		i=0;
		while(c!='\0' && i<size){
			c = *(str + i);
			*(str + i) = shiftLeft(c, key);
			c=*(str + i);
			i++;
		}
		fwrite(str, sizeof(*str), size, stream);
		
		printf("Text decrypted into file 'decrypted.txt'.\n");		
		return 1;
	}
	fclose(stream);
}

//The operations carried out in the main according to the type of action desired: encryption or decryption
void operations(char * action, int argc, char const *argv[]){
	int e = 0, d=0;
	if(argc<3)
			{
				(strcmp(action, "encrypt")==0)?printf("Incomplete arguments. The command must be something like: ./a.out -e file_to_encrypt.txt key_file.txt.\n"):printf("Incomplete arguments. The command must be something like: ./a.out -d file_to_decrypt.txt key_file.txt.\n");
			}else{
				if (argc==4)
				{
					int i=0, nberCharacters = 0, n=0;
					char* res = (char*)malloc(sizeof(char)*MAX);
					char* key = (char*)malloc(sizeof(int));	
					int file = readFile(argv[2], res, &nberCharacters, "r+");
					int key_res = readFile(argv[3], key, &n, "r+");
					int key_i = atoi(key);
					if(strcmp(action, "encrypt")==0){
						e = encrypt(res, key_i, nberCharacters);
					}else{
						d = decrypt((char*)argv[2], key_i, n);
					}
				}
				
			}
}
