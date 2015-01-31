#include <stdio.h>
#include <math.h>

const int n = 2000;

long cube(int x) {return x*x*x;}
float croot(long x) {return pow(x, 1.0/3);}
bool is_int(float x) {return x==(int)x;}

int main(int argc, const char * argv[])
{
    for(int a=1; a<=n; ++a) {
        for(int b=1; b<a; ++b) {
            int sum = cube(a)+cube(b);
            for(int c=a-1; c>b; --c) {
                long c3 = cube(c);
                long d3 = sum-cube(c); if(d3>c3) {break;}
                float d = croot(d3);
                if(is_int(d)) {printf("%d: %d^3+%d^3=%d^3+%d^3\n", sum, a, b, c, (int)d);}
            }
        }
    }
    return 0;
}

