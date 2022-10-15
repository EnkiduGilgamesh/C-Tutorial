# 2 Pointer

## 2.1 Basic

Every variable has an address on the internal storage. We can use operator `&` to get the address. For instance

```c
#include <stdio.h>
 
int main ()
{
    int i = 10;
    int * p;              // define a pointer variable
    p = &i;
 
   printf("the address of i is:  %p\n", p);
   return 0;
}
```

We can regard a pointer as a special data type. It uses 4 bytes in 32 bits system whereas 8 bytes in 64 bits system.

A pointer always points the address it storages. That means the pointer's type should match the data type it points. And we can use operator `*` to get the variable a pointer points. For instance

```c
#include <stdio.h>
 
int main ()
{
    char c = 'K';             // define a pointer variable
    char * p = &c;

   printf("%c", *p);
   return 0;
}
```

## 2.2 NULL

The `NULL` pointer means the pointer points nowhere. Notice that if we define a pointer but not initialize it in time, the poniter will point a random place. So **it's a good habit to make it point `NULL` when it is not the time to initialize it**. And **if we delete a variable, all the pointers point it should be assigned to `NULL`**. For example

```c
#include <stdio.h>
 
int main ()
{
   int  *ptr = NULL;
 
   printf("The address of ptr is: %p\n", ptr);
 
   return 0;
}
```

Another common situation to use pointer as a condition in judgement statement. If a pointer points `NULL`, it will return 0 to the judgement. For instance

```c
if(ptr)                 // if a pointer is NULL, it will return 0;
if(!ptr)
```
