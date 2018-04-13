/********************************************************************
* Substitution Cypher - Project 1
*
* February 19, 2018
* Aron Ockerse
*********************************************************************/

#include "functions.h"
#define MAXNUM 26

int main(int argc, char* argv[]){
	
	/** initialize arrays */
	char encrypt[MAXNUM];
	char decrypt[MAXNUM];

	/** pointer for key*/
	char* pKey;	

	/** for main function parameter*/
	char ch;

	/** boolean for encrypting or decrypting*/
	int isEncrypting = 1;	

	/** initialize fileIn and fileOut */
	FILE* fileIn;
	FILE* fileOut; 
	
	// set char on parameter 2 equal to ch
	ch = *argv[1];
	
	// sets isEncrypting to false if ch equals d
	if ((strcmp(&ch, "d"))){
		isEncrypting = 0;
	}

	// sets fileIn to read and fileOut to write
	fileIn = fopen(argv[3], "r");
	fileOut = fopen(argv[4], "w");

	// if files are null print message
	if (fileIn == NULL || fileOut == NULL){
		printf("Unable to open file");
		exit(1);
	}
	
	// remove duplicates from key
	pKey = removeDuplicates(argv[2]);

	// initialize encrypt array		
	initializeEncryptArray(pKey, encrypt);

	// initialize decrypt array
	initializeDecryptArray(encrypt, decrypt);

	// if isEcrypting is 0 encrypt file else decrypt
	if (isEncrypting == 0){
		processInput(fileIn, fileOut, encrypt);
		fprintf(stdout, "The encrypted file is: %s\n", argv[4]);
	} else{
	 	processInput(fileIn, fileOut, decrypt);
		fprintf(stdout, "The decrypted file is: %s\n", argv[4]);
	}

	fclose(fileIn);
	fclose(fileOut);
	free(pKey);

	return 0;
}
