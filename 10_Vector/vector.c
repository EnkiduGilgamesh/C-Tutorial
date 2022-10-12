/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \vector.c                                                                                  *
* Project: 10_Vector                                                                               *
* Created Date: Tuesday Oct 11th 2022, 9:55:32 am                                                  *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 12/10/2022 02:26:50                                                               *
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
#include "vector.h"

// initialize and free
void getVector(vector * v){
    v->elems = (elem *)malloc(sizeof(elem) * v->size);
    if(v->elems == NULL) printf("Memory Allocation Error!\n");
}

void initVector(vector * v, int size){
    if(size <= 0) printf("Invalid Vector Size!\n");
    else{
        v->size = size;
        v->len = 0;
        getVector(v);
    }
}

void freeVector(vector * v){
    free(v->elems);
}

// assignment
// TODO: add lSize parameter
vector * initFromArrary(elem * l, int listLen, int maxSize){

    if(listLen <= 0){
        printf("Init Failed, the Array is empty\n");
        return NULL;
    }

    if(maxSize <= 0){
        printf("Invalid Size Value!\n");
        return NULL;
    }

    vector * res = (vector *)malloc(sizeof(vector));

    res->size = maxSize;
    res->len = maxSize > listLen ? listLen : maxSize;
    getVector(res);

    for(int i = 0; i < res->len; i++)
        res->elems[i] = l[i];

    return res;
}

// if the maxSize is bigger than the v->size, the new vector's size will be set as the v->size, otherwise the maxSize
vector * initFromVector(vector * v, int maxSize){
    if(v->len <= 0){
        printf("Init Failed, the Vector is empty\n");
        return NULL;
    }

    if(maxSize <= 0){
        printf("Invalid Size Value!\n");
        return NULL;
    }

    vector * res = (vector *)malloc(sizeof(vector));

    res->size = maxSize > v->size ? v->size : maxSize;
    res->len = res->size > v->len ? v->len : res->size;
    getVector(res);

    for(int i = 0; i < res->len; i++)
        res->elems[i] = v->elems[i];
    
    return res;
}

// print
bool printVector(vector * v){
    if(v->len <= 0){
        printf("Empty Vector\n");
        return FALSE;
    }
    else{
        printf("[");
        for(int i = 0; i < v->len; i++){
            if(sizeof(elem) <= sizeof(int)) printf("%d", v->elems[i]);
            else printf("%f", v->elems[i]);

            if(i != v->len - 1) printf(", ");
        }
        printf("]");
        return TRUE;
    }
}

// function
// TODO: minus i
elem getVectorNode(vector * v, int i){
    if(i < -v->len || i >= v->len){
        printf("Invalid Visit Position!\n");
        return -1;
    }
    return v->elems[(i + v->len) % v->len];
}

int findVectorNode(vector * v, elem x){
    int num = 0;
    for(int i = 0; i < v->len; i ++){
        if(x == v->elems[i]) num++;
    }

    if(num) return num;
    else return 0;
}

bool insertVectorNode(vector * v, elem x, int i){
    if(v->len == v->size){
        printf("Overflow!\n");
        return FALSE;
    }
    else if(i + v->len < -1 || i > v->len){
        printf("Invalid Insert Position!\n");
        return FALSE;
    }
    // if i < 0, the order is from the rear to front
    else{
        int pos = i >= 0 ? i : i + v->len + 1;
        for(int j = v->len - 1; j >= pos; j--)
            v->elems[j + 1] = v->elems[j];
        v->elems[pos] = x;
        v->len++;
        return TRUE;
    }
}

bool removeVectorNode(vector * v, int i){
    if(v->len == 0){
        printf("The Vector is Empty!\n");
        return FALSE;
    }
    else if(i + v->len < 0 || i >= v->len){
        printf("Invalid Remove Position!\n");
        return FALSE;
    }
    // if i < 0, the order is from the rear to front
    else{
        int pos = i >= 0 ? i : i + v->len;
        v->len--;
        for(int j = pos; j < v->len; j++) v->elems[j] = v->elems[j + 1];
        return TRUE;
    }
}

void reserveVector(vector * v){
    int left = 0, right = v->len - 1;
    while(left < right){
        int temp = v->elems[left];
        v->elems[left++] = v->elems[right];
        v->elems[right--] = temp;
    }
}
