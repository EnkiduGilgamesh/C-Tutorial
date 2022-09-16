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

We can divide most operators into six classes, which are arithmetic, relational, logical, bitwise, assignment and other operators.

### 1.2.1 Arithmetic Operators

There are seven kinds of aritmetic operators.

|||
| --- | --- |
| `+` | add two operand |
| `-` | the first operand substracts the second operand |
| `*` | multiply two operand |
| `/` | the second operand divides the first operand |
| `%` | return the remainder of the `/` operation |
| `++` | operand adds 1 |
| `--` | operand substacts 1 |

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


