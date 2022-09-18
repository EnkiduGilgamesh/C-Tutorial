/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \SwitchBreak.c                                                                             *
* Project: 1_Grammar                                                                               *
* Created Date: Sunday Sep 18th 2022, 8:58:34 pm                                                   *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 18/09/2022 09:07:48                                                               *
* Modified By: Wenren Muyan                                                                        *
* --------------------------------------------------------------------------------                 *
* Copyright (c) 2022 - future Wenren Muyan                                                         *
* --------------------------------------------------------------------------------                 *
* HISTORY:                                                                                         *
* Date				By				Comments                                                       *
* --------------------------------------------------------------------------------                 *
***************************************************************************************************/

#include <stdio.h>

int main(){
   int i = 10;
   switch(i){
      case 10: i += 10;
      case 20: i += 10;
      default: i += 10;
   }
   printf("In the first loop without \"break\", finally, i=%d\n",i);

   i = 10;
   switch(i){
      case 10: 
        i += 10;
        break;
      case 20: i += 10;
      default: i += 10;
   }
   printf("In the second loop with \"break\", finally, i=%d\n",i);

   return 0;
}
