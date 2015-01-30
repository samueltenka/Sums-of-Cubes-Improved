#include <stdio.h>

const float croot2 = 1.259921;

int cube(int x) {return x*x*x;}
float croot_(float x, float c) {
    if(x<2) {float eps=x-1; return (1+eps/3-eps*eps/9+4*eps*eps*eps/81)*c;} // Taylor
    if(x<8) {return croot_(x/2, croot2*c);}
    return croot_(x/8, 2*c);
} float croot(float x) {return croot_(x, 1);}


int main(int argc, const char * argv[])
{
    for(int i=0; i<400; i+=20) {
        printf("%d\t%f\n", i, croot(cube(i)));
    }
    return 0;
}

