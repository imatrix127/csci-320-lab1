/*
 * Implement your solution in thi file
 *
 */
#include "lab1.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* readString(char* fileName){
    FILE* textfile;
    char* readAlloc;

    readAlloc = malloc(MAX_LINE_LEN*sizeof(char()));

    textfile = fopen(fileName,"r");

    strcpy(readAlloc, fgets(readAlloc, MAX_LINE_LEN,textfile));

    fclose(textfile);

    return readAlloc;

}

char* mysteryExplode(const char* word){

    int sizeOfWord = strlen(word)-1;

    int explodeSize = ((sizeOfWord*(sizeOfWord +1))/2);

    char* memAlloc = calloc(explodeSize + 1,1);



    for(int k = 0; k < sizeOfWord; k++){
        for(int i = 0; i <= k; i++){
            strcpy(memAlloc, strncat(memAlloc,&word[i],1));
        }

    }

    return memAlloc;


}




