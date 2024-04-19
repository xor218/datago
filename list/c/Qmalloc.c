#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#if defined(__APPLE__)
    #error "Apple does not support the brk function"
#endif 


int main(){
    printf("hello");
    return 0;
}
