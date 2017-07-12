//Mourad<mohammadabdoulahi@gmail.com>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "chars.h"

#define MAX 10000
#define ACTION_ENCRYPT "-e"
#define ACTION_DECRYPT "-d"

int main(int argc, char const *argv[])
{
	
	if (argc<2)
	{
		printf("You must provided at least 2 arguments to run this code.\n");
		return 0;
	}else{
		if ((strcmp(argv[1],ACTION_ENCRYPT)!=0)&&(strcmp(argv[1],ACTION_DECRYPT)!=0))
		{
			printf("The first argument must be [-e|-d] to respectively encrypt and decrypt!\n");
		}
		if (strcmp(argv[1],ACTION_ENCRYPT)==0)
		{
			
			operations("encrypt", argc, argv);
		}
		if(strcmp(argv[1],ACTION_DECRYPT)==0){
			operations("decrypt", argc, argv);
		}
	}
}


