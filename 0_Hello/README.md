# 0 Basic Structure

```c
#include <stdio.h>

int main(){
    /* My First C Program*/
    char hello[] = "Hello world! ";
    printf(hello);
    return 0;
}
```

Firstly, the line `#include` means our program will contain the pre-process header whose name is `stdio.h`. In this file, several important functions have been defined, so that we can reuse them directly, for instanse the print function in C language `printf` has been defined in `stdio.h`. We can define our own header file in the future.

Secondly, the line `int` and its body wrapped by `{}` means a function. The `int` is the type of the function, the `main` is the name of the function. The C program is always starting at the `main` function.

Thirdly, in the end of the function, we must return something matching the function type we define in the beginning. In addition, if a function executes to a line with something returned, the function will be ended, that is to say, what you write after the 'return' line will never be useless.

Forthly, we divide orders in a function  with `;`.

Finally, the line wrapped by `/*` in the beginning and `*/` in the end is called comment, which will not be contained in our program, and we can use it to help our code more readable. In addition we can use `//` in the beginning to comment a single line.  
