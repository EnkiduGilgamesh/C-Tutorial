# Grammar

TODO:

- [ ] data type example

- [Grammar](#grammar)
- [1 Variable](#1-variable)
- [2 Operator](#2-operator)
  - [2.1 Arithmetic Operators](#21-arithmetic-operators)
  - [2.2 Relational Operators](#22-relational-operators)
  - [2.3 Logical Operators](#23-logical-operators)
  - [2.4 Bitwise Operators](#24-bitwise-operators)
  - [2.5 Assignment Operators](#25-assignment-operators)
  - [2.6 Other Operators](#26-other-operators)
  - [2.7 Priority](#27-priority)
- [3 Data Type](#3-data-type)
  - [3.1 Integer](#31-integer)
  - [3.2 Float](#32-float)
  - [3.3 Void](#33-void)
  - [3.4 sizeof](#34-sizeof)
  - [3.5 Number System](#35-number-system)
- [4 Conditional Statement](#4-conditional-statement)
  - [4.1 if...else](#41-ifelse)
  - [4.2 ?: Operator](#42--operator)
  - [4.3 switch...case](#43-switchcase)
- [5 Loop](#5-loop)
  - [5.1 while...loop](#51-whileloop)
  - [5.2 for..loop](#52-forloop)
  - [5.3 do..while...loop](#53-dowhileloop)
  - [5.4 control statement](#54-control-statement)
- [6 Function](#6-function)
  - [6.1 Definition](#61-definition)
  - [6.2 Declaration](#62-declaration)
  - [6.3 Calling](#63-calling)
  - [6.4 Recursion](#64-recursion)
- [7 Scope](#7-scope)
  - [7.1 Local Variable](#71-local-variable)
  - [7.2 Global Variable](#72-global-variable)
  - [7.3 Formal Parameter](#73-formal-parameter)
- [8 Storage Class](#8-storage-class)
  - [8.1 auto](#81-auto)
  - [8.2 register](#82-register)
  - [8.3 static](#83-static)
  - [8.4 external](#84-external)
- [9 Array](#9-array)
  - [9.1 Declarati](#91-declarati)
  - [9.2 Initialization](#92-initialization)
  - [9.3 Visit](#93-visit)
- [10 String](#10-string)
- [11 Standard IO](#11-standard-io)
  - [11.1 printf](#111-printf)
  - [12.2 scanf](#122-scanf)
  - [12.3 Placeholder](#123-placeholder)
  - [12.4 Character Constant](#124-character-constant)
- [13 Preprocessor](#13-preprocessor)
- [14 Enumeration](#14-enumeration)
  - [14.1 Definition](#141-definition)
  - [14.2 Visit](#142-visit)
- [15 typedef](#15-typedef)
- [16 Structure](#16-structure)
  - [16.1 Definition](#161-definition)
  - [16.2 Initialization](#162-initialization)
- [17 Union](#17-union)
  - [17.1 Definition](#171-definition)
  - [17.2 Visit](#172-visit)
- [18 Data Converting](#18-data-converting)

# 1 Variable

We can define variable to store different data structure. In Clanguage, we can use letter `a-z`, `A-Z`, symbol `_` in the beginning and none or several letters, `_` or numbers following to define a variable. The legal variables and illegal variables are listing underneath.

```c
//legal
a, abs, _a, A, A_bs, a1, A22, A__bs, A_2b;
//illegel
2a;
```

In C language, some names are reserved for other purpose, so we cannot use them as our variable name. They are:

||||
| --- | --- | --- |
| `auto` | `break` | `case` |
| `char` | `const` | `continue` |
| `default` | `do` | `double` |
| `else` | `enum` | `extern` |
| `float` | `for` | `goto` |
| `if` | `int` | `long` |
| `register` | `return` | `short` |
| `signed` | `sizeof` | `static` |
| `struct` | `switch` | `typedef` |
| `unsigned` | `union` | `void` |
| `volatile` | `while` |  |

In C99 standard, these names are added in,

||||
| --- | --- | --- |
| `_Bool` | `_Complex` | `_Imaginary` |
| `inline` | `restrict` |  |

In C11 standard, these names are added in,

||||
| --- | --- | --- |
| `_Alignas` | `_Alignof` | `_Atomic` |
| `_Generic` | `_Noreturn` | `_Static_assert` |
| `_Thread_local` | `` | `` |

A variable should **not longer than 32 characters**.

# 2 Operator

We can divide most operators into six classes by their usage, which are arithmetic, relational, logical, bitwise, assignment and other operators.

In addition, different operators need different number of operands. The unary operators means only 1 operand is needed when we use those operators, the binary operators means two, while the ternary operators means three.

## 2.1 Arithmetic Operators

There are seven kinds of aritmetic operators.

| Operator | Operand | Function |
| --- | --- | --- |
| `+` | two | add two operand |
| `-` | two | the first operand substracts the second operand |
| `*` | two | multiply two operand |
| `/` | two | the second operand divides the first operand |
| `%` | two | return the remainder of the `/` operation |
| `++` | one |operand adds 1 |
| `--` | one |operand substacts 1 |

Foe instance

```c
#include <stdio.h>

int main()
{
   int a = 21;
   int b = 10;
   int c ;
 
   c = a + b;
   printf("The value of line 1 - c is %d\n", c );
   c = a - b;
   printf("The value of line 2 - c is %d\n", c );
   c = a * b;
   printf("The value of line 3 - c is %d\n", c );
   c = a / b;
   printf("The value of line 4 - c is %d\n", c );
   c = a % b;
   printf("The value of line 5 - c is %d\n", c );
   c = a++;
   printf("The value of line 6 - c is %d\n", c );
   c = a--;
   printf("The value of line 7 - c is %d\n", c );

}
```

We will get the result underneath after running the code.

```c
The value of line 1 - c is 31
The value of line 2 - c is 11
The value of line 3 - c is 210
The value of line 4 - c is 2
The value of line 5 - c is 1
The value of line 6 - c is 21
The value of line 7 - c is 22
```

Notice that there is a difference between the `a++` and `++a`, the same with `--`. Look at the code underneath,

```c
#include <stdio.h>
 
int main()
{
   int c;
   int a = 10;
   c = a++; 
   printf("Firstly assign c with a, and then a adds 1.\n");
   printf("The value of line 1 - c is %d\n", c );
   printf("The value of line 2 - c is %d\n", a );
   a = 10;
   c = a--; 
   printf("The value of line 3 - c is %d\n", c );
   printf("The value of line 4 - c is %d\n", a );
 
   printf("Firstly a adds 1, and then assign c with a.\n");
   a = 10;
   c = ++a; 
   printf("The value of line 5 - c is %d\n", c );
   printf("The value of line 6 - c is %d\n", a );
   a = 10;
   c = --a; 
   printf("The value of line 7 - c is %d\n", c );
   printf("The value of line 8 - c is %d\n", a );
 
}   
```

We will get the result underneath after running the code.

```c
Firstly assign c with a, and then a adds 1.
The value of line 1 - c is 10
The value of line 2 - c is 11
The value of line 3 - c is 10
The value of line 4 - c is 9
Firstly a adds 1, and then assign c with a.
The value of line 5 - c is 11
The value of line 6 - c is 11
The value of line 7 - c is 9
The value of line 8 - c is 9
```

## 2.2 Relational Operators

Relation operators are used to compare two operands. These operators are all binary operators.

|||
| --- | --- |
| `==` | if the two operands are equal, return `true`; otherwise return `false` |
| `!=` | if the two operands are not equal, return `true`; otherwise return `false` |
| `>` | if the first operand is bigger than the second, return `true`, otherwise return `false` |
| `<` | if the first operand is smaller than the second, return `true`, otherwise return `false` |
| `>=` | be equivalant to `==` and `>` |
| `<=` | be equivalant to `==` and `<` |

```c
#include <stdio.h>
 
int main()
{
   int a = 21;
   int b = 10;
   int c ;
 
   if( a == b ){
      printf("Line 1 - a is equal to b\n" );
   }
   else
   {
      printf("Line 1 - a is not equal to b\n" );
   }
   if ( a < b )
   {
      printf("Line 2 - a is smaller b\n" );
   }
   else
   {
      printf("Line 2 - a is not smaller b\n" );
   }
   if ( a > b )
   {
      printf("Line 3 - a is bigger b\n" );
   }
   else
   {
      printf("Line 3 - a is not bigger b\n" );
   }
   /* change the value of a and b */
   a = 5;
   b = 20;
   if ( a <= b )
   {
      printf("Line 4 - a is not bigger b\n" );
   }
   if ( b >= a )
   {
      printf("Line 5 - b is not smaller a\n" );
   }
}
```

We will get the result underneath after running the code.

```c
Line 1 - a is not equal to b
Line 2 - a is not smaller b
Line 3 - a is bigger b
Line 4 - a is not bigger b
Line 5 - b is not smaller a
```

## 2.3 Logical Operators

There are three logical operators, 'or', 'and', and 'not'.

| Operator | Operand | Function |
| --- | --- | --- |
| `&&` | two | only two operands' value are both `true`, it will return `true`, otherwise return `false` |
| `\|\|` | two |as long as at least one of the operands is `true`, it will return `true` |
| `!` | one | if the operand is `true`, return `false`; if the operand is `false` teturn `true` |

```c
#include <stdio.h>
 
int main()
{
   int a = 5;
   int b = 20;
   int c ;
 
   if ( a && b )
   {
      printf("Line 1 - condition is true\n" );
   }
   if ( a || b )
   {
      printf("Line 2 - condition is true\n" );
   }
   /* change the value of a and b */
   a = 0;
   b = 10;
   if ( a && b )
   {
      printf("Line 3 - condition is true\n" );
   }
   else
   {
      printf("Line 3 - condition is false\n" );
   }
   if ( !(a && b) )
   {
      printf("Line 4 - condition is true\n" );
   }
}
```

Notice that in C language, any variable whose value is not **0** or `null` will be regarded as `true` in logical operation.

## 2.4 Bitwise Operators

TODO: [https://www.runoob.com/cprogramming/c-operators.html](https://www.runoob.com/cprogramming/c-operators.html)

## 2.5 Assignment Operators

| Operator | Example | Function |
| --- | --- | --- |
| `=` | `c = a` | assign the first operand to the second operand |
| `+=` | `c += a` | assign the result of the sum of the fitst and the second operands to the first operand, in ther words, it is equivalant to `c = c + a` |
| `-=` | `c -= a` | be equivalant to `c = c - a` |
| `*=` | `c *= a` | be equivalant to `c = c * a` |
| `/=` | `c /= a` | be equivalant to `c = c / a` |
| `%=` | `c %= a` | be equivalant to `c = c % a` |
| `<<=` | `c <<= 2` | be equivalant to `c = c << 2` |
| `>>=` | `c >>= 2` | be equivalant to `c = c >> 2` |
| `*&=` | `c &= 2` | be equivalant to `c = c & 2` |
| `*^=` | `c ^= 2` | be equivalant to `c = c ^ 2` |
| `\|=` | `c \|= 2` | be equivalant to `c = c \| 2` |

## 2.6 Other Operators

| Operator | Operand | Function |
| --- | --- | --- |
| `sizeof()` | one | return the bitwise of the variable |
| `&` | one | givr a variable as its operand and it will return the address in internal storage of the variable |
| `*` | one | give a address as its operand and it will return the variable storage in it |
| `?:` | three |  |

## 2.7 Priority

Different operators are set with different priority when the program is compiled, in order to make the code more simple and readable.

In the table underneath, the smaller the row is, the higher the priority is. And operators in the same priority obey the order given in combination.

| Class | Operators | Combination |
| --- | --- | --- |
| suffix | `()`, `[]`, `->`, `.`, `++`, `--` | from left to right |
| unary | `+`, `-`, `!`, `~`, `++`, `--`, `(type)*`, `&`, `sizeof` | from right to left |
| multiplication and division(binary) | `*`, `/`, `%` | from left to right |
| add and subtract(binary) | `+`, `-`  | from left to right |
| shift | `>>`, `<<` | from left to right |
| relation | `<`, `>`, `>=`, `<=` | from left to right |
| equivalence | `==`, `!=` | from left to right |
| and(bitwise) | `&` | from left to right |
| xor(bitwise) | `^` | from left to right |
| or(bitwise) | `\|` | from left to right |
| and(logical) | `&&` | from left to right |
| or(logical) | `\|\|` | from left to right |
| condition | `?:` | from right to left |
| assignment | `=`, `+=`, `-=` ... | from right to left |
| comma | `,` | from left to right |

```c
#include <stdio.h>

int main()
{
   int a = 20;
   int b = 10;
   int c = 15;
   int d = 5;
   int e;

   e = (a + b) * c / d;      // ( 30 * 15 ) / 5
   printf("The value of \"(a + b) * c / d\" is %d\n",  e );

   e = ((a + b) * c) / d;    // (30 * 15 ) / 5
   printf("The value of \"((a + b) * c) / d\" is %d\n" ,  e );

   e = (a + b) * (c / d);   // (30) * (15/5)
   printf("The value of \"(a + b) * (c / d)\" is %d\n",  e );

   e = a + (b * c) / d;     //  20 + (150/5)
   printf("The value of \"a + (b * c) / d\" is %d\n" ,  e );

   return 0;
}
```

We will get the result underneath after compiling the code.

```c
The value of "(a + b) * c / d" is 90
The value of "((a + b) * c) / d" is 90
The value of "(a + b) * (c / d)" is 90
The value of "a + (b * c) / d" is 50
```

# 3 Data Type

Every variable has its type, and the type decide the space the variable will use in internal storage and its valua range. In the beiginning we only introduce the integer, float, and the void type.

It should be known to us that 1 byte is equivalant to 8 bits.

$$
1\ byte = 8\ bits
$$

## 3.1 Integer

| type | space | range |
| --- | --- | --- |
| `char` | 1 byte | -128\~127 or 0\~255 |
| `unsigned char` | 1 byte | 0\~255 |
| `signed char` | 1 byte | -128~127 |
| `int` | 2 or 4 bytes | -32,768\~32,767 or -2,147,483,648\~2,147,483,647 |
| `unsigned int` | 2 or 4 bytes | 0\~65,535 or 0~4,294,967,295 |
| `short` | 2 bytes | -32,768\~32,767 |
| `unsigned short` | 2 bytes | 0\~65,535 |
| `long` | 4 bytes | -2,147,483,648\~2,147,483,647 |
| `unsigned long` | 4 bytes | 0\~4,294,967,295 |

## 3.2 Float

| type | space | range | Precision(significant bit) |
| --- | --- | --- | --- |
| `float` | 4 bytes | 1.2E-38~3.4E+38 | 6 |
| `double` | 8 bytes | 2.3E-308~1.7E+308 | 15 |
| `long double` | 16 bytes | 3.4E-4932~1.1E+4932 | 19 |

In different systems and different compilers, the size of a data type may be different. The table shows some details.

| Data Type | Windows MVSC |  | Windows Mingw64 | | Linux gcc | |
| --- | --- | --- | --- | --- | --- | --- |
| | Win32 | x64 | Win32 | x64 | i686 | x86_64 |
| char | 1 | | 1 | 1  | 1 | 1 |
| unsigned char | 1 | | -- | | 1 | 1 |
| short | 2 | | 2 | 2 | 2 | 2 |
| unsigned short | 2 | | -- | | 2 | 2 |
| int | 4 | | 4 | 4 | 4 | 4 |
| unsigned int | 4 | | -- | | 4 | 4 |
| long | 4 | | 4 | 4 | 4 | 8 |
| unsigned long | 4 | | -- | | 4 | 8 |
| float | 4 | | 4 | 4 | 4 | 4 |
| double | 8 | | 8 | 8 | 8 | 8 |
| long int | 4 | | -- | | 8 | 8 |
| long long | 8 | | 8 | 8 | 8 | 8 |
| long double | 8 | | -- | | 12 | 16 |
| pointer | 4 | 8 | 4 | 8 | 4 | 8 |

## 3.3 Void

If a object has no value, it is the void type. In function, if no value will be returned, we should set it void type.

## 3.4 sizeof

The function `sizeof(data_type)` can return the size of the data type you give. For instance

```c
#include <stdio.h>

int main(){
   print("The size of int is %d", sizeof(int));

   return 0;
}
```

## 3.5 Number System

For integer, if an integer starts with:

- **none**, it means it uses decimalism, for example: 10, 20;
- **0**, it means it uses octonary, for example: 045, 021;
- **0b**, it means it uses binary, for example: 0b11101101;
- **0x**, it means it uses hexadecimal for example: 0x21458adf.

# 4 Conditional Statement

Conditional statement will be only executed when the conditions are true.

## 4.1 if...else

The structure of `if...else...` is like underneath:

```c
if(boolean_expression)
{
   /* statement */
}
else
{
   /* statement */
}
```

For instance

```c
#include <stdio.h>
 
int main ()
{
   /* definition */
   int a = 10;
 
   /* check the bool value */
   if( a < 20 )
   {
       /* if the value is true, this statement will be executed */
       printf("a is smaller than 20\n" );
   }
   else
   {
      /* if the value is false, this statement will be executed */
      printf("a is not smaller than 20\n" );
   }
   printf("The value of a is %d\n", a);
 
   return 0;
}
```

The `else` statement is not essential, in other words, if there is no `else` statement nothing will be done if the condition is `false`.

If the condition is very complex, we can use `else if` statement.

```c
#include <stdio.h>
 
int main ()
{
   /* definition */
   int a = 100;
 
   /* check */
   if( a == 10 )
   {
       printf("The valua of a is 10\n" );
   }
   else if( a == 20 )
   {
       printf("The valua of a is 20\n" );
   }
   else if( a == 30 )
   {
       printf("The valua of a is 30\n" );
   }
   else
   {
       printf("No match value for a \n" );
   }
   printf("The valua of a is %d\n", a );
 
   return 0;
}
```

Notice that, as long as one of the conditions is `true`, the whole conditional statements will be over after executing the conditional statement, although there are conditions are also true after the first condition.

Also, the `if` statement can nested by other `if` statement. For instance

```c
#include <stdio.h>
 
int main ()
{
   /* definition */
   int a = 100;
   int b = 200;
 
   /* check */
   if( a == 100 )
   {
       if( b == 200 )
       {
          printf("The value of a is 100, and the value of b is 200\n" );
       }
   }
   printf("The value of a is %d\n", a );
   printf("The value of a is %d\n", b );
 
   return 0;
}
```

## 4.2 ?: Operator

We have known the ternary operators `?:`. It is actually is a conditional statement. It is used like this

```c
Exp1 ? Exp2 : Exp3;
```

The `Exp1` is a bool expression, if it is `true`, then return the value of `Exp2`, otherwise `Exp3`. For instance

```c
#include<stdio.h>
 
int main()
{
    int num;
 
    printf("Please enter a number: ");
    scanf("%d",&num);
 
    (num%2==0)?printf("The nnumber is even"):printf("The number is odd");
}
```

## 4.3 switch...case

The `switch` statement is like this

```c
switch(expression){
    case constant-expression1  :
       statement(s);
       break; /* optional */
    case constant-expression2  :
       statement(s);
       break; /* optional */
      /* any number of cases */
    default : /* optional */
       statement(s);
}
```

If the value of `expression` is equal to one of the `case`'s `constant-expression`, the statement after that `case` will be executed until the `swith` statement's end or meeting a `break`. If none of the `constant-expression` match the value, the statement under `default` will be executed. Like the `else`, `default` is also not essential. For instance

```c
int main ()
{
   /* difinition */
   char grade = 'B';
 
   switch(grade)
   {
   case 'A' :
      printf("Great!\n" );
      break;
   case 'B' :break;
   case 'C' :
      printf("Well done!\n" );
      break;
   case 'D' :
      printf("You have passed.\n" );
      break;
   case 'F' :
      printf("Try again.\n" );
      break;
   default :
      printf("invalid grade.\n" );
   }
   printf("Your grade is %c\n", grade );
 
   return 0;
}
```

# 5 Loop

Sometimes, we need execute some statements several times. For these statement, loop statement can make us easier.

## 5.1 while...loop

One kind of loop is `while` loop. It is used like this

```c
while(condition)
{
   statement(s);
}
```

If the value of `condition` is `true`, the statement under `while` will be executed until the `condition` change to `false`. For instanse

```c
#include <stdio.h>
 
int main ()
{
   /* definition */
   int a = 10;

   /* while loop */
   while( a < 20 )
   {
      printf("The value of a is %d\n", a);
      a++;
   }
 
   return 0;
}
```

## 5.2 for..loop

Another kind of loop is `for` loop. This kind of loop is ofen used to those loop we need set loop times for. It is used like this

```c
for ( init; condition; increment )
{
   statement(s);
}
```

The `init` is to initialize an internal variable and will only be executed at the first time, and then if the variable meet the `condition`, the statement will be executed. After the statement's execution, the variable will change as the `increment` tells. For instance

```c
#include <stdio.h>
 
int main ()
{
   /* for loop */
   for( int a = 10; a < 20; a = a + 1 )
   {
      printf("The value of a is %d\n", a);
   }
 
   return 0;
}
```

## 5.3 do..while...loop

Similar to `while` loop, the `do...while` loop is used like this

```c
do
{
   statement(s);

}while( condition );
```

But there is difference between `while` and `do...while` which is that `while` check the condition in the beginning, whereas the `do..while` check the condition at the end which makes the `do...while` loop always executes at least once. For instance

```c
#include <stdio.h>
 
int main ()
{
   /* definition */
   int a = 10;

   /* do...while loop */
   do
   {
       printf("a 的值： %d\n", a);
       a = a + 1;
   }while( a < 20 );
 
   return 0;
}
```

## 5.4 control statement

There is two common control statement in loop, `break` and `continue`.

Control `break` will end the whole loop, and the program will goto statement after this loop. For instance

```c
#include <stdio.h>
 
int main ()
{
   /* definition */
   int a = 10;

   while( a < 20 )
   {
      printf("a 的值： %d\n", a);
      a++;
      if( a > 15)
      {
         /* end the loop */
          break;
      }
   }
 
   return 0;
}
```

The `break` is also used in the `switch` statement to end the whole conditional statement. Without `break`, the statement will continue checking from the first case to the last case which makes the program may execute several cases in one time. For instance

```c
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
```

We will get the result after we compiling the program

```c
In the first loop without "break", finally, i=40
In the second loop with "break", finally, i=20
```

Control `continue` will end this time of loop, and goto the next time immediately. For instance

```c
#include <stdio.h>
 
int main ()
{
   int a = 10;

   do
   {
      if( a == 15)
      {
         /* pass this time of loop */
         a = a + 1;
         continue;
      }
      printf("The value of a is %d\n", a);
      a++;
     
   }while( a < 20 );
 
   return 0;
}
```

# 6 Function

Function is a group of statement doing a particular task. Every C program contains at least one function, whose name is `main`. Generaly, to use function, there are three steps, 'declaration', 'definition' and 'calling'.

## 6.1 Definition

We firstly introduce how to define a function.

```c
return_type function_name( parameter list )
{
   body of the function;
   return value;
}
```

A function is consist of head and body.

In head, we firstly declare the return type of the function which is the same as he return value's type. Then we define the name of the function to call it in other place. Finally, we need give a parameter list to the function to help the function complete its task.

In body we write statement to achieve what we want to do, and then return the result so that we can joint different functions to finish a complex work. For instance

```c
/* give the function two numbers, and we will get the bigger number of them */
int max(int num1, int num2) 
{
   int result;
 
   if (num1 > num2) {
      result = num1;
   } else {
      result = num2;
   }
   return result; 
}
```

## 6.2 Declaration

We declare function like this

```c
return_type function_name(parameter list);
```

It's a good habit to declare functions what we will define in the beginning of C file. But if the function and the `main` function are defined in the same file, the declaration is not essential.

In declaration, only the parameters'types are needed, whereas the parameters' names are not essential, for instance

```c
int max(int num1, int num2);
int min(int,int);
/* both OK */
```

## 6.3 Calling

We can call function which we have defined before to complete a task in particular situation. For instance, we can call the `max` function defined in *1.6.1*

```c
#include <stdio.h>
 
int max(int num1, int num2);
 
int main ()
{
   int a = 100;
   int b = 200;
   int ret;
 
   /* Calling */
   ret = max(a, b);
 
   printf( "Max value is : %d\n", ret );
 
   return 0;
}
```

## 6.4 Recursion

We can even call a function in itself body. This operation is called recursion. A classic example is *Fibonacci Series*.

$$
F_n= \begin{cases}
   1, & n=1 \\
   1, & n=2 \\
   F_{n-1}+F_{n-2}, & n\ge3
\end{cases}
$$

```c
#include <stdio.h>
 
int fibonaci(int i)
{
   if(i == 0)
   {
      return 0;
   }
   if(i == 1)
   {
      return 1;
   }
   return fibonaci(i-1) + fibonaci(i-2);
}
 
int  main()
{
    int i;
    for (i = 0; i < 10; i++)
    {
       printf("%d\t\n", fibonaci(i));
    }
    return 0;
}
```

# 7 Scope

In C language, every variable has its scope which is related to the variable's declaration place. We cannot visit the variable beyond its scope. Totally, we have three place to declare variable.

- Local variable: in a function or in a block statement;
- Global variable: out of all functions;
- Formal parameter: the formal parameter when defining a function.

## 7.1 Local Variable

Local variables only exist in the block where it is declared. For instance

```c
if(sizeof(int)==sizeof(long))
{
    long sum;
}
else
{
    int sum;
}
```

The `long sum` only exists in `if` block, whereas the `int sum` only exists in the `else` block. Out of the block, we cannot visit the variable named `sum`. There is another situation where we declare `sum` out of `if...else` and redeclare `sum` in `if...else` block, the compiler will use the declaration in the nearest, in other word, the declaration in `if...else` block as priority.

## 7.2 Global Variable

The global variable is declared out of any functions so it can be visited by any functions. For instance

```c
#include <stdio.h>
 
/* global variable */
int g;
 
int main ()
{
  int a, b;

  a = 10;
  b = 20;
  g = a + b;
 
  printf ("value of a = %d, b = %d and g = %d\n", a, b, g);
 
  return 0;
}
```

## 7.3 Formal Parameter

When we define a function, the parameters we give to the function is acually variables. They are declared automatically when we define the function and can be visited in any place in the function. Also the parameters are given the highest priority in the function if there is several variables with a same name. For instance

```c
/* global variable */
int a = 20;
 
int main ()
{
  /* local variable */
  int a = 10;
  int b = 20;
  int c = 0;
  int sum(int, int);
 
  printf ("value of a in main() = %d\n",  a);
  c = sum( a, b);
  printf ("value of c in main() = %d\n",  c);
 
  return 0;
}
 
/* formal parameter */
int sum(int a, int b)
{
    printf ("value of a in sum() = %d\n",  a);
    printf ("value of b in sum() = %d\n",  b);
 
    return a + b;
}
```

# 8 Storage Class

In C language, there are four kinds of storage classes, `auto`, `register`, `static`, `extern`. We can define a variable's storage class before its data type

```c
storage_lass data_type a;
```

## 8.1 auto

The class `auto` is defaultly used by local variable.

## 8.2 register

As its name, variable with `register` class will be storaged in register(Actually, different machine may deal with this class in different ways, even not storage it in register).

Because storaged in register, this kind of variable cannot bigger than a register(generally 1 byte), but we can visit `register` class more rapidly.

## 8.3 static

There are two ways to use `static` class.

One of the ways is to decorate local variable. If a local variable decorated by `static`, it will exist through the program's lifecycle. That is to say, whenever we enter or exit the block where the variable is declared, the variable will not be destoryed or initialized after the first time it is initialized.

Another way is to decorate global variable, so that the global variable only can be visited in the file where it is declared.

For instance

```c
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
```

We will get the result after compiling this program

```bash
The value of thingy is 6 ， count is 9
The value of thingy is 7 ， count is 8
The value of thingy is 8 ， count is 7
The value of thingy is 9 ， count is 6
The value of thingy is 10 ， count is 5
The value of thingy is 11 ， count is 4
The value of thingy is 12 ， count is 3
The value of thingy is 13 ， count is 2
The value of thingy is 14 ， count is 1
The value of thingy is 15 ， count is 0
```

## 8.4 external

The class `external` is used to decorate a global variable. It will make the variable visitable to all files. If the variable is already defined, then the declaration will point to the pre-declaration. For instance, there are two `.c` files

```c
/* main.c */
#include <stdio.h>
 
int count ;
extern void write_extern();

int main()
{
   count = 5;
   write_extern();
}
```

```c
/* support.c */
#include <stdio.h>
 
extern int count;
 
void write_extern(void)
{
   printf("count is %d\n", count);
}
```

We can compile the two files like this

```bash
gcc main.c support.c
```

Finally, we will get esult

```bash
count is 5
```

# 9 Array

Array is one of the data types which can be used to storage a series data with same type.

## 9.1 Declarati

To declarate a array, the array size is essential, which is equal to the number of data we plan to storage in the array. We can also call it 'length'.

```c
type arrayName [ arraySize ];
```

For instance

```c
double balance[10];
```

The `balance` is the array's name, and it can storage 10 double-type numbers.

## 9.2 Initialization

We can initialization array when we declare it.

```c
double balance[5] = {1000.0, 2.0, 3.4, 7.0, 50.0};
double balance2[] = {1000.0, 2.0, 3.4, 7.0, 50.0};
```

In this way, the array size is not essential. If the size is ignored, the compiler will default set its size as you give size. And if the numbers you give to the array is less than the array's size, the remaining elements will be defaultly set by `0`. And all the elements are kept continuously in computer's memory.

## 9.3 Visit

The operator `[]` is used to visit array's element. The first element in array's index is `0`, the second is `1`...

```c
balance[4] = 50.0;
```

We often use `for` loop to initialize a array with some rules. For instance

```c
double p[9]

for(int i = 0; i < 9; i++){
   p[i] = 1 / i;
}
```

## 9.4 Two-dimensional array

The array I have introduced has only one dimension. Actually, we can initialize an array with two dimensions.

```c
type arrayName[ rowSize ][ columnSize ];
```

The array can storage $rowSize * columnSize$ numbers with the appointed type. We can initialize a two-dimensional array and visit the element in it like this

```c
int p[2][3] = {{1, 2, 3}, {4, 5, 6}};
int num = p[1][2];
printf("The result is %d", num);
```

By that analogy, we can create an array with more dimensions. Notice that no matter how many the demension is, all the elements in an array are kept continuously in computer's memory.

# 10 String

String actually is a array made up by a series of characters and ended with `NULL` character `\0`.

We can initialize a string like this

```c
char site[7] = {'R', 'U', 'N', 'O', 'O', 'B', '\0'};
/* or */
char site2[] = "RUNOOB";
```

The second way is more simple and is more widely used.

In header `string.h`, there are many functions to operate strings being defined.

| Function | Effect |
| --- | --- |
| `strcpy(s1, s2)` | copy the content of string `s2` to `s1` |
| `strcat(s1, s2)` | joint `s2` at the end of `s1` |
| `strlen(s1)` | return the length of `s1` |
| `strcmp(s1, s2)` | compare `s1` with `s2`, if `s1`>`s2`, it will return a positive number; if `s1`<`s2`, it will return a negative number; else it will return `0` |
| `strchr(s1, ch)` | return a pointer where the character `ch` first appear in `s1` |
| `strstr(s1, s2)` | return a pointer where the string `s2` first appear in `s1` |

For instance

```c
#include <stdio.h>
#include <string.h>  /* call string.h */
 
int main ()
{
   char str1[14] = "runoob";
   char str2[14] = "google";
   char str3[14];
   int  len ;
 
   /* copy str1 to str3 */
   strcpy(str3, str1);
   printf("strcpy( str3, str1) :  %s\n", str3 );
 
   /* joint str1 with str2 */
   strcat( str1, str2);
   printf("strcat( str1, str2):   %s\n", str1 );
 
   /* get the length of str1 */
   len = strlen(str1);
   printf("strlen(str1) :  %d\n", len );
 
   return 0;
}
```

# 11 Standard IO

We have used `printf` function many times. In C language, we can use `printf` function to put out in console, `scanf` function to put in, both the two functions are defined in the `stdio.h`.

## 11.1 printf

The standard function `printf` is defined like this

```c
int printf(const char *format, ...)
```

The `format` can be a simple string, whereas it also can be a string with several placeholders. If a string has placeholder, then the placehoder will be placed by the parameter following `format` and the parameters and placeholders have a corresponding relationship. So the **numbers, types and orders** of placeholders and parameters following `format` are must the same. For instance

```c
#include <stdio.h>

int main(){
   char boy[] = "Bob";
   char girl[] = "Rose";

   printf("%s loves %s.", boy, girl);

   return 0;turn 0;
}
```

This program will get

```bash
Bob loves Rose.
```

## 12.2 scanf

The `scanf`'s style is much similar to `printf`.

```c
int scanf(const char *format, ...)
```

For instance

```c
char str[100];
int i;

scanf("%s %d", str, &i);
```

After we compile the program, the console will be held to wait us put in and what we put in will be transmitted to `str` and `i` respectively.

A whole program can be like this

```c
#include <stdio.h>
int main( ) {
 
   char str[100];
   int i;
 
   printf( "Enter a value :");
   scanf("%s %d", str, &i);
 
   printf( "\nYou entered: %s %d ", str, i);
   printf("\n");
   return 0;
}
```

Notice that `scanf` will terminate when it meets `space`, `tab`, and wrapping around.

## 12.3 Placeholder

In `printf` and `scanf`, placeholders are often used. There are many types of placeholders.

| Placeholder | Type |
| --- | --- |
| `%a` and `%A` | floating number |
| `%c` | character |
| `%s` | string |
| `%d` | decimalism integer |
| `%e` and `%E` | float with scientific notation |
| `%i` | integer, very similar to `%d` |
| `%f` | decimals including `float` and `double` |
| `%g` and `%G` | floating number with 6 significat figures, if the figures are more than 6, it will use scientific notation |
| `%o` | octonary integer |
| `%x` | hexadecimal integer |
| `%u` | unsigner integer |
| `%n` | put out the times of strings which are put out |
| `%%` | put out a per cent `%` |
| `%hd` | short decimalism integer |
| `%ho` | short octonary integer |
| `%hx` | short hexadecimal integer |
| `%hu` | unsigned short integer |
| `%ld` | long decimalism integer |
| `%lo` | long octonaty integer |
| `%lx` | long hexadecimal integer |
| `%lu` | long unsigned integer |
| `%lld` | long long decimalism integer |
| `%llo` | long long octonaty integer |
| `%llx` | long long hexadecimal integer |
| `%lu` | long long unsigned integer |
| `%Le` | long double type floating with scientific notation |
| `%Lf` | long double type floating number |
| `%p` | put out a hexadecimal number with **8 digits if the system is 32 bit, whereas 16 digits if the system is 64 bit** |

We can expand the placeholder as `%num1.num2..`. The `num1` means that the out will hold how many digits place whereas the `num2` means how many digits are visitable. Notice that only when the `num1` is bigger than the number's actual width, it will work and the number will add space on the left. For example

```c
printf("%5.4d\n", 22);
printf("%5.3d\n", 22);
printf("%5d\n", 22);
printf("%.3d\n", 22);
```

If we add a `-` in front of the `num1`, the printed number will align at the right instead of the default right. For example

```c
printf("%-5.4d\n", 22);
printf("%-5.3d\n", 22);
```

The code will get this result

```terminal
0022 
022  
```

For `float` type, the `num2` means the precision. For example

```c
printf("%7.2f", 1234.5678);
```

## 12.4 Character Constant

In C language, there are some strings being reserved for special usage. Most of these strings are often started with `\`.

| String | Function |
| --- | --- |
| `\\` | character `\` |
| `\'` | character `'` |
| `\"` | character `"` |
| `\?` | character `?` |
| `\a` | alarm bell |
| `\b` | backspace |
| `\f` | form-feed |
| `\n` | line break |
| `\r` | carriage return |
| `\t` | horizontal tab |
| `\v` | vertical tab |

## 12.5 Other input

### 12.5.1 getchar

```c
char c = getchar();
```

This function can get the next character of the characters having been read in the buffer. For instance

```c
#include "stdio.h"

int main()
{
	char ch;
	printf("Input two characters: "); 
	scanf("%c", &ch); 
	printf("%c", getchar()); 

   return 0;
}
```

If you input `12`, you will get `2` as the result.

### 12.5.2 gets

Function `gets` will only terminate when it meets wrapping around. For instance

```c
# include <stdio.h>

int main(void)
{
    char str[20];
    printf("Input a string: ");
    gets(str);
    printf("%s\n", str);

    return 0;
}
```

If you input `I love you`, you will get `I love you` as the result. The `space` can be recognized in `gets` function.

Notice that `gets` function will keep reading until it meets wrapping around, so if the input is longer than the string's space, the function could be unsafe. C has provided `gets_s(char*, int*)` as a replacing method, but unfortunately, gcc and clang havn't supported it yet.

# 13 Preprocessor

We can use preprocesser to define a const. The preprocesser is used at the beginning of the program, and it can be visited by any functions and cannot be modified after defined.

```c
#define identifier value
```

For instance

```c
#include <stdio.h>
 
#define LENGTH 10   
#define WIDTH  5
#define NEWLINE '\n'
 
int main()
{  
   int area;  
  
   area = LENGTH * WIDTH;
   printf("value of area : %d", area);
   printf("%c", NEWLINE);
 
   return 0;
}
```

# 14 Enumeration

Enumeration is one of the data types in C language. It can rapidly name a series of numbers.

## 14.1 Definition

We can define a enumeration like this

```c
enum DAY
{
      MON=1, TUE, WED, THU, FRI, SAT, SUN
};
```

The first element in an enumeration is defaultly 0, but we can set it as what we want. And the latter element is 1 bigger than the former. We also can set the value of any element among an enumeration,

```c
enum season {spring, summer=3, autumn, winter};
```

Notice that the `DAY` and `season` are just a **tag** of enumeration, not varialble names. To visit an enumeration, we need to name it firstly.

```c
enum DAY day;
```

Or we can create a enumeration when we define the type.

```c
enum DAY
{
      MON=1, TUE, WED, THU, FRI, SAT, SUN
} day;
```

The type name is not even essential.

```c
enum
{
      MON=1, TUE, WED, THU, FRI, SAT, SUN
} day;
```

## 14.2 Visit

We can visit the element in enumeration by its name.

```c
#include <stdio.h>
 
enum DAY
{
      MON=1, TUE, WED, THU, FRI, SAT, SUN
};
 
int main()
{
    enum DAY day;
    day = WED;
    printf("%d",day);
    return 0;
}
```

But only the enumeration with continuous value can be traversed. For instance

```c
#include <stdio.h>
 
enum DAY
{
      MON=1, TUE, WED, THU, FRI, SAT, SUN
} day;
int main()
{
    for (day = MON; day <= SUN; day++) {
        printf("枚举元素：%d \n", day);
    }
}
```

# 15 typedef

The keyword `typedef` in C language is used to rename a existing data type, or define a new type of data.

```c
typedef unsigned char BYTE;

BYTE  b1, b2;

BYTE OperBYTE(BYTE b);
```

```c
typedef struct
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} Books;
```

# 16 Structure

Structure is a data type that contains a group of data which are difined by users, even these data are different types.

## 16.1 Definition

We can define a structure to store a book's property

```c
struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} book;
```

In *1.15* we have introduced the way through `typedef` to define a structure.

Then we can use the tag to declare a data type named `Books`

```c
Books book1, books2[20], *books3;
```

## 16.2 Initialization

We can initialize a structure when we define it.

```c
struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} book = {"C Language", "Wenren Muyan", "Programming language", 123456};
```

Or we can initialize the element in a structure one by one. Notice that we visit the element of a structure through `.` operator.

```c
int main(){
   struct Books Book1; 
   strcpy( Book1.title, "C Programming");
   strcpy( Book1.author, "Nuha Ali"); 
   strcpy( Book1.subject, "C Programming Tutorial");
   Book1.book_id = 6495407;

   /* statement */
}
```

# 17 Union

Union is a very special data type. A union has several different types of data to option. All of the data will be storaged in the same address in internal storage, but only one data can be storaged in one time.

## 17.1 Definition

Defining a union is very similar to defining a structure.

```c
union Data
{
   int i;
   float f;
   char  str[20];
} data;
```

The size of a union is equivalent the largest size among data types in the union's options. For instance, we can check the size of union `Data` we have defined above

```c
int main( )
{
   union Data data;        
 
   printf( "Memory size occupied by data : %d\n", sizeof(data));
 
   return 0;
}
```

We will get this result

```bash
Memory size occupied by data : 20
```

## 17.2 Visit

We can visit a union's element like structure, but we need to remember that only one data can be storaged in one time.

```c
#include <stdio.h>
#include <string.h>
 
union Data
{
   int i;
   float f;
   char  str[20];
};
 
int main( )
{
   union Data data;        
 
   data.i = 10;
   data.f = 220.5;
   strcpy( data.str, "C Programming");
 
   printf( "data.i : %d\n", data.i);
   printf( "data.f : %f\n", data.f);
   printf( "data.str : %s\n", data.str);
 
   return 0;
}
```

Compiling the program above, we will get the result

```bash
data.i : 1917853763
data.f : 4122360580327794860452759994368.000000
data.str : C Programming
```

We can see only the last assignment is correct, because the formers are both recovered.

# 18 Data Converting

We can convert one data type to another through the way underneath

```c
(type_name) expression
```

For instance

```c
#include <stdio.h>
 
int main()
{
   int sum = 17, count = 5;
   double mean;
 
   mean = (double) sum / count;
   printf("Value of mean : %f\n", mean );
 
}
```

In the instance, we convert integer sum to double float.

The convertiong can be implicit. For instance

```c
#include <stdio.h>
 
int main()
{
   int  i = 17;
   char c = 'c'; /* The value of ascii is 99 */
   int sum;
 
   sum = i + c;
   printf("Value of sum : %d\n", sum );
 
}
```

In this instance, the character `c` is converted to integer. This kind of converting is called **Integer Promotion**.

In computing, if the operands are different types, the compiler will convert one of them to the higher priority as the under image showing.

![Converting](https://www.runoob.com/wp-content/uploads/2014/08/usual_arithmetic_conversion.png)

For instance

```c
#include <stdio.h>
 
int main()
{
   int  i = 17;
   int c = 99; /* ascii 值是 99 */
   float sum;
 
   sum = i + c;
   printf("Value of sum : %f\n", sum );
 
}
```

We will get the result

```bash
Value of sum : 116.000000
```

# 20 Head file

Sometimes, writing function declaration and other definitions in header files is a good habit, so that we can clearly know what functions and variable we can use meanwhile make the main file more legible. Also, we can reuse them in other program just by including the same header files. In the former instance, we have used the standard header file `stdio.h` many times. Just create a new file with `.h` as its suffix, and write your declarations and definitions in it, then you can simply include it in your main program

```c
#include "myheader.h"
```

Notice that your own header files are quoted by `"`, and only standard header files are quoted by `<` and `>`.

Customarily, we will write a `.c` file with the same name with the `.h` file to define all the functions declared in it.

Actually, what the including does is like to copy the content in head file and paste it in the destination. To void the repeatedly quotations from one head file, we can do in head files like this

```c
#ifndef HEADER_FILE
#define HEADER_FILE

/* statements */

#endif
```

Another situation is that we need different head file in different conditions. We can do in main program like this

```c
#if SYSTEM_1
   # include "system_1.h"
#elif SYSTEM_2
   # include "system_2.h"
#elif SYSTEM_3
   ...
#endif
```

If there are too many head files to include, we can include all of them in another head file, and then include the special head file in main file.

```c
/* global.h */
#include "head1.h"
#include "head2.h"
#include "head3.h"
#include <stdio.h>
```

```c
/* main.c */
#include "global.h"
```
