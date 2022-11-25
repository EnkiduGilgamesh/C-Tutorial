/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \mystring.c                                                                                *
* Project: 21_MyString                                                                             *
* Created Date: Thursday Nov 24th 2022, 9:40:35 am                                                 *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 25/11/2022 10:50:55                                                               *
* Modified By: Wenren Muyan                                                                        *
* --------------------------------------------------------------------------------                 *
* Copyright (c) 2022 - future Wenren Muyan                                                         *
* --------------------------------------------------------------------------------                 *
* HISTORY:                                                                                         *
* Date				By				Comments                                                       *
* --------------------------------------------------------------------------------                 *
***************************************************************************************************/


#include <string.h>
#include <stdlib.h>
#include "mystring.h"

// BF
int findBF(char * s, int sLen, char * sub, int subLen){
    int i, j;
    for(i = 0; i < sLen; i++){
        if(sLen - i < subLen) return -1;
        int pos = i;
        for(j = 0; j < subLen;){
            if(s[pos++] != sub[j++]) break;
            if(j == subLen) return i;
        }
    }
    return -1;
}

// KMP
void genKMPNext(int * next, char * s, int sLen){
    int i = 0, j = -1;

    next[0] = -1;
    while(i < sLen - 1){
        /**/
        while(j >= 0 && s[i] != s[j])
            /*  */
            j = next[j];
        i++; j++;
        if(s[i] == s[j]) 
            next[i] = next[j];
        else next[i] = j;
    }
}

int findKMP(char * s, int sLen, char * sub, int subLen){        /* find 'sub' in 's' */
    int i, j;
    int * next = (int *)malloc(sizeof(int) * subLen);

    genKMPNext(next, sub, subLen);

    // for(int k = 0; k < subLen; k++) printf("%d, ", next[k]);
    // printf("\n");
   
    for(i = 0, j = 0; i < subLen && j < sLen;){
        if(sub[i] == s[j]){
            i++; j++;
        }
        else if(next[i] >= 0) i = next[i];
        else{
            i = 0; j++;
        }
    }

    if(i >= subLen) return j-subLen;
    else            return -1;                                  /* search failed */
}

// BM
void genBMBadChar(char * s, int sLen, int * badchar){
    int i, ascii;
    for(i = 0; i < CHAR_SET_SIZE; i++){
        badchar[i] = -1;                                        // initialize value with -1
    }
    for(i = 0; i < sLen; i++){
        ascii = (int)s[i];                                      // get the ASCII value
        badchar[ascii] = i;                                     // cover the initialized value with the position
    }
}


void genBMGoodFix(char * s, int sLen, int * goodSufFix){
    int i = sLen - 1, j = 0, b_i, b_j;
    for(b_i = 0; b_i < sLen - 1; b_i++) goodSufFix[b_i] = -1;
    while(j < i){
        b_i = i; b_j = j;
        while(b_j >= 0 && s[b_i] == s[b_j]){
            goodSufFix[b_i--] = b_j--;
        }
        j++;
    }

    for(int k = 0; k < sLen; k++) printf("%d, ", goodSufFix[k]);
    printf("\n");
}
