#ifndef H_FUNCTIONS
#define H_FUNCTIONS
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * removeDuplicates(char word []);

int targetFound(char charArray[], int num, char target);

void initializeEncryptArray(char key[], char encrypt[]);

void initializeDecryptArray(char encrypt[], char decrypt[]);

void processInput(FILE* inf, FILE* outf, char substitute[]);

#endif
