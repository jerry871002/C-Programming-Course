//gcd(greatest common divisor), lcm(least common multiple)

#include <stdio.h>

int gcd(int, int);
int lcm(int, int);

int main() {
    int a, b, c, d, e;
    printf("Input five integer number:\n");
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    printf("g.c.d : %d\n", gcd(a, gcd(b, gcd(c, gcd(d, e)))));
    printf("l.c.m : %d\n", lcm(a, lcm(b, lcm(c, lcm(d, e)))));
    return 0;
}

int gcd(int n1, int n2) {
    if(n2 == 0)
        return n1;
    else
        gcd (n2, n1 % n2);
}

int lcm(int n1, int n2) {
    return n1 * n2 / gcd(n1, n2);
}