# 2 Pointer

- [2 Pointer](#2-pointer)
  - [2.1 Basic](#21-basic)
  - [2.2 NULL](#22-null)
  - [2.3 Array and Pointer](#23-array-and-pointer)
  - [2.4 Operator](#24-operator)
  - [2.5 Pointer Parameter](#25-pointer-parameter)
  - [2.6 Return Pointer](#26-return-pointer)
  - [2.7 malloc](#27-malloc)
  - [2.8 Function Pointer](#28-function-pointer)
  - [2.9 Callback Function](#29-callback-function)

## 2.1 Basic

Every variable has an address on the internal storage. We can use operator `&` to get the address. For instance

```c
#include <stdio.h>
 
int main (){
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

## 2.3 Array and Pointer

The array name actually is a pointer points to the first element's address. For example

```c
#include <stdio.h>
 
int main ()
{
   double balance[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
   double *p;
   int i;
 
   p = balance;
 
   /* print the array's elements */
   printf( " Use p\n ");
   for ( i = 0; i < 5; i++ ){
       printf("*(p + %d) : %f\n",  i, *(p + i) );
   }
 
   printf( "Use balance\n");
   for ( i = 0; i < 5; i++ ){
       printf("*(balance + %d) : %f\n",  i, *(balance + i) );
   }
 
   return 0;
}
```

The strings are the same.

## 2.4 Operator

The pointer supports four kinds of arithmetic operator, `++`, `--`, `+`, `-`.

- `++`, the pointer will points the latter element's address;
- `--`, the pointer will points the former element's address;
- `+`, the pointer will move backward;
- `-`, the pointer will move forward.

For instance

```c
#include <stdio.h>
 
const int MAX = 3;
 
int main ()
{
   int  var[] = {10, 100, 200};
   int  i, *ptr;
 
   /* pointer points the beginning of the array */
   ptr = var;
   for ( i = 0; i < MAX; i++){
      printf("The address: var[%d] = %p\n", i, ptr );
      printf("The value: var[%d] = %d\n", i, *ptr );
 
      /* point to the latter element */
      ptr++;
   }
   return 0;
}
```

The pointer also supports relational operators `==`, `>` and `<`. Notice that it's better to use them in array. It will compare the two addresses' numerical value. For instance

```c
#include <stdio.h>
 
const int MAX = 3;
 
int main ()
{
   int  var[] = {10, 100, 200};
   int  i, *ptr;

   ptr = var;
   i = 0;
   while ( ptr <= &var[MAX - 1] ){
      printf("The address: var[%d] = %p\n", i, ptr );
      printf("The value: var[%d] = %d\n", i, *ptr );
 
      /* point to the latter element */
      ptr++;
      i++;
   }
   return 0;
}
```

## 2.5 Pointer Parameter

A formal parameter doesn't exist if a function ends. If we want to modify an array or a string, we can pass the pointer to functions, so we can get and change the value among it through the address directly. So our modification can be kept out of the function. For instance

```c
#include <stdio.h>

double getAverage(int *arr, int size);
 
int main (){
   int balance[5] = {1000, 2, 3, 17, 50};
   double avg;
   avg = getAverage( balance, 5 ) ;
 
   printf("Average value is: %f\n", avg );
   
   return 0;
}

double getAverage(int *arr, int size){
  int    i, sum = 0;      
  double avg;          
 
  for (i = 0; i < size; ++i){
    sum += arr[i];
  }
 
  avg = (double)sum / size;
 
  return avg;
}
```

## 2.6 Return Pointer

A pointer also can be a return value of a function. But notice that the address of local variable in function should not be the return value, unless the variable is `static`. For instance

```c
#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
 
/* generate 10 random number */
int * getRandom( )
{
   /* use static variable */
   static int  r[10];
   int i;
 
   /* set a seed */
   srand( (unsigned)time( NULL ) );
   for ( i = 0; i < 10; ++i)
   {
      r[i] = rand();
      printf("%d\n", r[i] );
   }
 
   /* return a pointer points array r */
   return r;
}
 
int main ()
{
   int *p;
   int i;
 
   p = getRandom();
   for ( i = 0; i < 10; i++ )
   {
       printf("*(p + [%d]) : %d\n", i, *(p + i) );
   }
 
   return 0;
}
```

## 2.7 malloc

The function `malloc` is from standard library `stdlib.h`. We don't always know a array's size when we initialize it. The `malloc` and `realloc` function can help us dynamically provide space for arrays. And `free` function can help us free up an array's space.

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
int main(){
   char *str;
 
   /* allot space */
   str = (char *) malloc(15);
   strcpy(str, "runoob");
   printf("String = %s,  Address = %u\n", str, str);
 
   /* reallot space */
   str = (char *) realloc(str, 25);
   strcat(str, ".com");
   printf("String = %s,  Address = %u\n", str, str);
 
   free(str);
 
   return(0);
}
```

## 2.8 Function Pointer

A pointer also can points a function, for instance

```c
#include <stdio.h>
 
int max(int x, int y){
    return x > y ? x : y;
}
 
int main(void){
    /* p is function pointer */
    int (* p)(int, int) = & max; // & is not essential
    int a, b, c, d;
 
    printf("Please enter three numbers: ");
    scanf("%d %d %d", & a, & b, & c);
 
    /* equal to d = max(max(a, b), c) */
    d = p(p(a, b), c); 
 
    printf("The maximum number is: %d\n", d);
 
    return 0;
}
```

## 2.9 Callback Function

If a function has at least one function pointer as its parameter, the function can be called callback function. For instance

```c
#include <stdlib.h>  
#include <stdio.h>
 
void populate_array(int *array, size_t arraySize, int (*getNextValue)(void)){
    for (size_t i=0; i<arraySize; i++)
        array[i] = getNextValue();
}

// get random number
int getNextRandomValue(void){
    return rand();
}
 
int main(void){
    int myarray[10];
    /* use function getNextRandomValue's name as a pointer */
    populate_array(myarray, 10, getNextRandomValue);
    for(int i = 0; i < 10; i++) {
        printf("%d ", myarray[i]);
    }
    printf("\n");
    return 0;
}
```
