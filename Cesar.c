//Mourad<mohammadabdoulahi@gmail.com>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define MAX 10000
#define ACTION_ENCRYPT "-e"
#define ACTION_DECRYPT "-d"

int readFile(char const * file, char * res, int* n, char * mode);
int encrypt(char * string, int key, int size);
int decrypt(char * filename, int key, int size);
void operations(char * action, int argc, char const *argv[]);


int main(int argc, char const *argv[])
{
	printf("Ok\n");
	if (argc<2)
	{
		printf("You must provided at least 2 arguments to run this code.\n");
		return 0;
	}else{
		printf("Ik\n");
		if (strcmp(argv[1],ACTION_ENCRYPT)==0)
		{
			printf("Aok\n");
			operations("encrypt", argc, argv);
		}
		if(strcmp(argv[1],ACTION_DECRYPT)==0){
			operations("decrypt", argc, argv);
		}
	}
}


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
		i=0;
		while (c!=EOF)
		{
			if(c==EOF) break;
			c = fgetc(stream);
			i++;
			printf("c bn\n");
			//fread(&c, sizeof(char), 1, stream);
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
	stream = fopen("encrypted.txt", "w+");
	if (stream == NULL)
	{
		printf("Opening failed.\n");
		return 0;
	}else{
		c= ' ';
		i=0;
		
		while(c!='\0' && i<size){
			*(string + i) = shiftRight(*(string + i), n);
			//fwrite(&s,sizeof(char), 1, stream);
			i++;
			
		}
		fwrite(string, sizeof(*string), size, stream);
		
			printf("Text encrypted into file 'encrypted.txt'.\n");
			printf("n:%d\n",size);	
		
		return 1;
	}
	fclose(stream);
}

int decrypt(char * filename, int key, int size){
	int i=0, n=0, end =0;
	char c = ' ';
	char s = ' ';
	char * res = (char *)malloc(sizeof(char)*size);
	int res_int = readFile(filename, res, &n, "r+");
	FILE * stream = NULL;
	stream = fopen("decyrypted.txt", "w+");
	if (stream == NULL)
	{
		printf("Opening failed.\n");
		return 0;
	}else{
		c= ' ';
		i=0;
		printf("Ok\n");
		while(c!='\0' && i<n){
			c = *(res + i);
			*(res + i) = shiftLeft(c, key);
			//fwrite(&s, sizeof(char),1, stream);
			i++;
			
		}
			fwrite(res, sizeof(*res), n, stream);
			printf("Text decrypted into file 'decrypted.txt'.\n");	
			printf("n:%d\n",n );
		return 1;
	}
	fclose(stream);	
}

void operations(char * action, int argc, char const *argv[]){
	int e = 0, d=0;
	if(argc<3)
			{
				(strcmp(action, "encrypt")==0)?printf("Incomplete arguments. The command must be something like: ./a.out -e file_to_encrypt.txt key_file.txt.\n"):printf("Incomplete arguments. The command must be something like: ./a.out -d file_to_decrypt.txt key_file.txt.\n");
			}else{
				if (argc==4)
				{
					int i=0, nberCharacters = 0, n=0;
					printf("OKKK\n");
					char* res = (char*)malloc(sizeof(char)*MAX);
					char* key = (char*)malloc(sizeof(int));	
					printf("Avant\n");
					int file = readFile(argv[2], res, &nberCharacters, "r+");
					printf("Nombre de caracteres lus:%d\n",nberCharacters );
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
