/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \main.c                                                                                    *
* Project: 22_MySort                                                                               *
* Created Date: Thursday Dec 8th 2022, 9:02:39 am                                                  *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 8/12/2022 10:01:21                                                                *
* Modified By: Wenren Muyan                                                                        *
* --------------------------------------------------------------------------------                 *
* Copyright (c) 2022 - future Wenren Muyan                                                         *
* --------------------------------------------------------------------------------                 *
* HISTORY:                                                                                         *
* Date				By				Comments                                                       *
* --------------------------------------------------------------------------------                 *
***************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mysort.h"
#define MAX_SIZE 100000

int main(){
    sortType * s = (sortType *)malloc(sizeof(sortType) * MAX_SIZE);
    clock_t begin, end;
    double duration;
    for(int i = 0; i < MAX_SIZE; i++){
        s[i] = (int)(rand());
    }
    
    begin = clock();
    directInsertSort(s, MAX_SIZE);
    if(testSortRes(s, MAX_SIZE)) printf("Sort successfully!\n");
    else printf("Failed to sort!\n");
    end = clock();
    duration = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Direct insert Sort consumes time: %lfs\n", duration);
    
    for(int i = 0; i < MAX_SIZE; i++){
        s[i] = (int)(rand());
    }
    
    begin = clock();
    binaryInsertSort(s, MAX_SIZE);
    // for(int j = 0; j < MAX_SIZE; j++){
    //     printf("%d ", s[j]);
    // }
    if(testSortRes(s, MAX_SIZE)) printf("Sort successfully!\n");
    else printf("Failed to sort!\n");
    end = clock();
    duration = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Binary insert Sort consumes time: %lfs\n", duration);

    for(int i = 0; i < MAX_SIZE; i++){
        s[i] = (int)(rand());
    }
    
    begin = clock();
    shellInsertSort(s, MAX_SIZE, 10000);
    // for(int j = 0; j < MAX_SIZE; j++){
    //     printf("%d ", s[j]);
    // }
    if(testSortRes(s, MAX_SIZE)) printf("Sort successfully!\n");
    else printf("Failed to sort!\n");
    end = clock();
    duration = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Shell Sort consumes time: %lfs\n", duration);

    return 0;
}
