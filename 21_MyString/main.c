/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \main.c                                                                                    *
* Project: 21_MyString                                                                             *
* Created Date: Thursday Nov 24th 2022, 11:58:25 am                                                *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 2/12/2022 04:48:0                                                                 *
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
#include <string.h>
#include <time.h>
#include "mystring.h"

#define MAX_SIZE 100000000

int main(){
    char sb[] = "ASDHKSAFHGHKVJDBXVASDYUSGCXBVGEWRUYGFBV\
        JHDVJXGAKSFHCKXZBVJCBXJVBJHSGDFHDJSKDFNKJBVJCXB\
        ASBCKXZNKNVFKDVNVKDFVJDSVNASJFACNXZCNGJRLLADEVC\
        ASDEIFITUOVNCNASDEFRHYJUJUKOIKGFVASDVCVXVKNNABA\
        ASFHRHGJNVXNCVKNFJHGHASDCZXCBBJDJFSVNXVKJXJCCSD\
        ASDSJKNCNVCNXVNCXNVNLFKELALDJSNCVJNEOWFJLSDFSNV\
        DDDDDDDDDDDDDDDDDDDDDDASDSACZFEGBASVFXBDSGTGFDG\
        ASCNLZNLRNVNNADSCNJVNVLSDKSALCMMCFVFJVNJLALAMVV\
        ASIHCOXOVNFLENROFDSLKVNLKFLGLNBNHOASDDJCNZLCNRN\
        ASODIORJFNVNCLASKDEJFIROGJJJASLKMKLXNCJNFJDVNNO\
        SAIHCUHJCFORJRGKVDCCXLVJFJASDKCMXZCMFJEIJQPIPWK\
        ACOIJCOVNFVJNFIFPASDKASMCFKVTNPFLKDJFVJNVNMVKJA\
        UAFOIJDISVKNVLCMVLKALFJJFRIOJZVKNKFLDKIPAAKDSSV\
        SADSACNDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD\
        ASDADWQSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS\
        ZXCDFSDUVJCXVDSSSSFEFASDDDDDDDDDDDDDDDDDDDDDDDD\
        ASDEFSDJCZVZVNJFJASABABSADWDACZCBBBAAAASDSAAABS\
        ASDSACZCFAAABABBABABASADCDSFEDSADSCABABASDSACZC\
        ABABAASCJZCFJBBBASDASDABBBSDADSAAAAAASADEFSDCBX\
        ZXCHFRASDAANANNABABASDADCACXZCDABABASCDFAAAAABA\
        ACZCZCABABDEFFFASDACXZCABABADSDFEFSASCAFEFABABS\
        ADCCFSDSAFDFJOLJJNNNADJAOABABACJJJDJJFESKKCNLLA\
        UADAABSDEDSABABCJJCRFKCKJZSHHHHHHDEFFJJJJJJJJHA\
        ASDHEFHABABBASJAJCJOCJOJEFEFJVOOJCAJDFHROFJJFJF\
        AFHRHFNCHAIDJJCJACNCNANCNASDHNCZXCVEFEFFASDSACC\
        JHGAABBABABAABABAAB";
    char sub[] = "ABABAABAB";
    char good[] = "abcdefeghde";
    char subgood[] = "cde";
    char * s = (char *)malloc(sizeof(char) * MAX_SIZE);
    for(int i = 0; i < MAX_SIZE - 9; i++){
        s[i] = 'A' + (int)(rand() / 1261);
    }
    strcat(s, sub);
    // int len = strlen(good);
    // int * goodSufFix = (int *)malloc(sizeof(int) * len);

    // time_t t;
    // time(&t);
    // printf("Time: %s\n", ctime(&t));
    clock_t begin, end;
    begin = clock();
    int pos = findBF(s, sub);
    end = clock();
    printf("%d\n", pos);
    double duration = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time: %lfs\n", duration);
    // time(&t);
    // printf("Time: %s\n", ctime(&t));
    begin = clock();
    pos = findKMP(s, sub);
    end = clock();
    printf("%d\n", pos);
    duration = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time: %lfs\n", duration);
    begin = clock();
    pos = findBM(s, sub);
    end = clock();
    printf("%d\n", pos);
    duration = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time: %lfs\n", duration);

    // genBMGoodFix(good, len, goodSufFix);

    return 0;
}