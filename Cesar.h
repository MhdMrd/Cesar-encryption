//Mourad<mohammadabdoulahi@gmail.com>
#ifndef __CESAR_H__
#define __CESAR_H__

int readFile(char const * file, char * res, int* n, char * mode);
int encrypt(char * string, int key, int size);
int decrypt(char const * filename, int key, int size);
void operations(char * action, int argc, char const *argv[]);

#endif
