#include <stdio.h>

#define SWAP(x, y)\
        int z = x;\
        x = y;\
        y = z;

#define LSB(x) x & 1

int main (){
        int x = 1;
        int y = 4;
        printf("x is %d and y is %d\n", x, y);
        printf("LSB %d is %d\n", x, LSB(x));
        printf("LSB %d is %d\n", y, LSB(y));
        SWAP(x,y);
        printf("x is now %d and y is now %d\n", x, y);
        printf("LSB %d is %d\n", x, LSB(x));
        printf("LSB %d is %d\n", y, LSB(y));
        return 0;
}
