#include <stdio.h>
#include <math.h>

const int n = 2000;
typedef long long int nat;

nat cube(nat x) {return x*x*x;}
double croot(nat x) {return pow(x, 1.0/3);}
int is_int(float x) {return x==(nat)x;}

void proclaim_match(nat sum, nat a, nat b, nat c, nat d) {
    static nat count=0; count+=1;
    printf("#%d\t %lld = %d^3+%d^3=%d^3+%d^3\n", count, sum, a, b, c, (int)d);
}

int main(int argc, const char * argv[])
{
    for(nat a=1; a<=n; ++a) {
        for(nat b=1; b<a; ++b) {
            nat sum = cube(a)+cube(b);
            for(nat c=a-1; c>b; --c) {
                nat c3 = cube(c);
                nat d3 = sum-cube(c); if(d3>c3) {break;}
                double d = croot(d3);
                if(is_int(d)) {proclaim_match(sum, a, b, c, d);
                    
                }
            }
        }
    }
    return 0;
}

