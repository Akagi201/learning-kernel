/*
 * @file test1.c
 * @author Akagi201
 * @date 2015/03/09
 *
 * gcc -g test1.c -o test1
 */

#include <stdio.h>

void p1(char c) {
    printf("%c\n", c);
}

int p2(int x, int y) {
    return x + y;
}

int main(void) {
    char c = 'a';
    int x, y, z;
    x = 1;
    y = 2;
    p1(c);
    z = p2(x, y);
    printf("%d = %d + %d\n", z, x, y);

    return 0;
}