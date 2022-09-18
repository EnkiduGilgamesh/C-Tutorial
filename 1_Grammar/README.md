# 1 Grammar

- [ ] data type enum, list, pointer...
- [ ] storage type
- [ ] constant
- [ ] data type example

- [1 Grammar](#1-grammar)
  - [1.1 Variable](#11-variable)
  - [1.2 Operator](#12-operator)
    - [1.2.1 Arithmetic Operators](#121-arithmetic-operators)
    - [1.2.2 Relational Operators](#122-relational-operators)
    - [1.2.3 Logical Operators](#123-logical-operators)
    - [1.2.4 Bitwise Operators](#124-bitwise-operators)
    - [1.2.5 Assignment Operators](#125-assignment-operators)
    - [1.2.6 Other Operators](#126-other-operators)
    - [1.2.6 Priority](#126-priority)
  - [1.3 Data Type](#13-data-type)
    - [1.3.1 Integer](#131-integer)
    - [1.3.2 Float](#132-float)
    - [1.3.3 Void](#133-void)
  - [1.4 Conditional Statement](#14-conditional-statement)
    - [1.4.1 if...else](#141-ifelse)
    - [1.4.2 ?: Operator](#142--operator)
    - [1.4.3 switch...case](#143-switchcase)
  - [1.5 Loop](#15-loop)
    - [1.5.1 while...loop](#151-whileloop)
    - [1.5.2 for..loop](#152-forloop)
    - [1.5.3 do..while...loop](#153-dowhileloop)
    - [1.5.4 control statement](#154-control-statement)

## 1.1 Variable

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

## 1.2 Operator

We can divide most operators into six classes by their usage, which are arithmetic, relational, logical, bitwise, assignment and other operators.

In addition, different operators need different number of operands. The unary operators means only 1 operand is needed when we use those operators, the binary operators means two, while the ternary operators means three.

### 1.2.1 Arithmetic Operators

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

### 1.2.2 Relational Operators

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

### 1.2.3 Logical Operators

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

### 1.2.4 Bitwise Operators

TODO: [https://www.runoob.com/cprogramming/c-operators.html](https://www.runoob.com/cprogramming/c-operators.html)

### 1.2.5 Assignment Operators

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

### 1.2.6 Other Operators

| Operator | Operand | Function |
| --- | --- | --- |
| `sizeof()` | one | return the bitwise of the variable |
| `&` | one | givr a variable as its operand and it will return the address in internal storage of the variable |
| `*` | one | give a address as its operand and it will return the variable storage in it |
| `?:` | three |  |

### 1.2.6 Priority

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

## 1.3 Data Type

Every variable has its type, and the type decide the space the variable will use in internal storage and its valua range. In the beiginning we only introduce the integer, float, and the void type.

It should be known to us that 1 byte is equivalant to 8 bits.

$$
1\ byte = 8\ bits
$$

### 1.3.1 Integer

| type | space | range |
| --- | --- | --- |
| `char` | 1 byte | -128~127 or 0~255 |
| `unsigned char` | 1 byte | 0~255 |
| `signed char` | 1 byte | -128~127 |
| `int` | 2 or 4 bytes | -32,768~32,767 or -2,147,483,648~2,147,483,647 |
| `unsigned int` | 2 or 4 bytes | 0~65,535 or 0~4,294,967,295 |
| `short` | 2 bytes | -32,768~32,767 |
| `unsigned short` | 2 bytes | 0~65,535 |
| `long` | 4 bytes | -2,147,483,648~2,147,483,647 |
| `unsigned long` | 4 bytes | 0~4,294,967,295 |

### 1.3.2 Float

| type | space | range | Precision(significant bit) |
| --- | --- | --- | --- |
| `float` | 4 bytes | 1.2E-38~3.4E+38 | 6 |
| `double` | 8 bytes | 2.3E-308~1.7E+308 | 15 |
| `long double` | 16 bytes | 3.4E-4932~1.1E+4932 | 19 |

### 1.3.3 Void

If a object has no value, it is the void type. In function, if no value will be returned, we should set it void type.

## 1.4 Conditional Statement

Conditional statement will be only executed when the conditions are true.

### 1.4.1 if...else

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

### 1.4.2 ?: Operator

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

### 1.4.3 switch...case

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

If the value of `expression` is equal to one of the `case`'s `constant-expression`, the statement under that `case` will be executed. If none of the `constant-expression` match the value, the statement under `default` will be executed. Like the `else`, `default` is also not essential. For instance

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
   case 'B' :
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

## 1.5 Loop

Sometimes, we need execute some statements several times. For these statement, loop statement can make us easier.

### 1.5.1 while...loop

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

### 1.5.2 for..loop

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

### 1.5.3 do..while...loop

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

### 1.5.4 control statement

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