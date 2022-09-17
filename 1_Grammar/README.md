# 1 Grammar

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

Notice that in C language, any variable whose value is not **0** will be regarded as `true` in logical operation.

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
| Suffix | `()`, `[]`, `->`, `.`, `++`, `--` | from left to right |
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
