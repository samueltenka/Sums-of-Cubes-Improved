#include <stdio.h>
#include <math.h>

const int n = 15;

int cube(int x) {return x*x*x;}
float croot(int x) {return pow(x, 1.0/3);}
int is_int(float x) {return x==(int)x;}

int main(int argc, const char * argv[])
{
    for(int a=0; a<=n; ++a) {
        for(int b=0; b<=a; ++b) {
            int sum = cube(a)+cube(b);
            int clim = (int)(croot(sum-cube(b)));
            if(clim>b) {clim=b;}
            for(int c=0; c<clim; ++c) {
                int d3 = sum-cube(c);
                float d = croot(d3);
                if(is_int(d)) {printf("%d: %d^3+%d^3=%d^3+%d^3\n", sum, a, b, c, (int)d);}
            }
        }
    }
    return 0;
}

