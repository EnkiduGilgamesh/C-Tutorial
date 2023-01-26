/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \myfind.h                                                                                  *
* Project: 23_MyFind                                                                               *
* Created Date: Thursday Jan 26th 2023, 8:58:39 pm                                                 *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 26/01/2023 09:22:13                                                               *
* Modified By: Wenren Muyan                                                                        *
* --------------------------------------------------------------------------------                 *
* Copyright (c) 2023 - future Wenren Muyan                                                         *
* --------------------------------------------------------------------------------                 *
* HISTORY:                                                                                         *
* Date				By				Comments                                                       *
* --------------------------------------------------------------------------------                 *
***************************************************************************************************/


#ifndef __MYFIND_H
#define __MYFIND_H

typedef int findType;
typedef enum{FALSE, TRUE} bool;

int seqFind(findType * A, findType key, int findLen);

int binaryFind(findType * A, findType key, int findLen);

#endif