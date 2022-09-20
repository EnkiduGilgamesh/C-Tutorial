/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \static.c                                                                                  *
* Project: 1_Grammar                                                                               *
* Created Date: Tuesday Sep 20th 2022, 4:41:48 pm                                                  *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 20/09/2022 04:41:52                                                               *
* Modified By: Wenren Muyan                                                                        *
* --------------------------------------------------------------------------------                 *
* Copyright (c) 2022 - future Wenren Muyan                                                         *
* --------------------------------------------------------------------------------                 *
* HISTORY:                                                                                         *
* Date				By				Comments                                                       *
* --------------------------------------------------------------------------------                 *
***************************************************************************************************/

#include <stdio.h>

void func1(void);

/* global static */
static int count=10;
 
int main()
{
  while (count--) {
      func1();
  }
  return 0;
}

void func1(void)
{
/* 'thingy' only be initialized once
 * Every time we call func1, the `thingy` will not be destoryed or initailized
 */                
  static int thingy=5;
  thingy++;
  printf("The value of thingy is %d ， count is %d\n", thingy, count);
}
