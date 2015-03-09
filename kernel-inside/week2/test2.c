/*
 * @file test2.c
 * @author Akagi201
 * @date 2015/03/09
 *
 * gcc -g test2.c -o test2
 * objdump -S test2
 */

#include <stdio.h>

void p1(char c) {
    printf("%c\n", c);
}

int p2(int x, int y) {
    char c;
    c = 'a';
    p1(c);
    return x + y;
}

int main(void) {
    int x, y, z;
    x = 1;
    y = 2;
    z = p2(x, y);
    printf("%d + %d = %d\n", x, y, z);

    return 0;
}
