#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <ctype.h>
#include <unistd.h>
#include "functions.h"
#define MAXNUM 26

/**********************************************************
* removeDuplicates takes in an array of a word and deletes
* any duplicate letters
*
* @param word array holding word
* @return pKey returns a pointer with updated word
***********************************************************/
char* removeDuplicates(char word[]){
	
	/** creates memory on the heap */
	char* pKey = (char*) malloc(sizeof(char) * MAXNUM);

	/** used in for loops */
	int i;
	int j = 0;

	/** length of word*/
	int len = (int)strlen(word);
	
	// runs through for loop checking for if letter at i repeats
	for (int i = 0; i < len; i++){
		if(!targetFound(word, i, word[i])){
			pKey[j++] = word[i];
		}
	
	}

	pKey[j] = '\0';

	return pKey;
}

/**********************************************************
* searched through an array for a selected target 
*
* @param charArray array holding word
* @param num keeps track of array size
* @param target desired letter to find
* @return 1 or 0 based on if target was found
***********************************************************/
int targetFound(char charArray[], int num, char target){

	/** used in for loop */
	int i;

	/** gets length of the word in charArray */
	int len = strlen(charArray);
	for (int i = 0; i < len; i++){

		// if the letter is equal to target and is in range
		// return 1
		if (i < num && charArray[i] == target){
			return 1;
		}

	}
	return 0;
}

/*******************************************************************
* reads in input file and outputs it to an outputfile
*
* @param *inf name of input file
* @param *outf name of output file
* @param substitue used if decrypting
********************************************************************/
void processInput(FILE* inf, FILE* outf, char substitute[]){

	/** used to check current character*/
	char ch;
	
	// while there are still characters in inf keep scanning
 	while (fscanf(inf, "%c", &ch) != EOF){
    		fprintf(outf, "%c", substitute[ch-'A']);
    	
  	}	
}

/*******************************************************************
* creates an encryption alphabet based on key
*
* @param key used to create encryption array
* @param encrypt encryption array
********************************************************************/
void initializeEncryptArray(char key[], char encrypt[]){
	int i;
	int j = 0;
	int len = strlen(key);
  	for(i=0; i < MAXNUM; i++){
    		if(i < len){
      			encrypt[i] = key[i];
    		} 
		else {
      			if(!targetFound(key, MAXNUM + 1, 'Z' - j)){
				encrypt[i] = 'Z' - j;
			}
      			else{
				i--;
      			}	j++;
    		}
  	}
	encrypt[i] = '\0';
	fprintf(stdout,"\nencrypt substitution: %s\n", encrypt);
}

/*******************************************************************
* initialize decrypt array with appropriate substitute letters based
* on the encrypt array
*
* @param encrypt contains encryption array
* @param decrypt contains decryption array
********************************************************************/
void initializeDecryptArray(char encrypt[], char decrypt[]){
  	int i;
  	char temp[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for(i=0; i < strlen(encrypt); i++){
		decrypt[encrypt[i]-'A'] = temp[i];
 	}
  
	decrypt[i] = '\0';

	fprintf(stdout, "decrypt substitution: %s\n\n", decrypt);	
}
