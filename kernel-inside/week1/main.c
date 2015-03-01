/*
 * @file main.c
 * @author Akagi201
 * @date 2015/03/01
 *
 * A simple code to learn how assembly code works.
 * build on linux x64: gcc -S -o main.s main.c -m32
 */

int g(int x) {
  return x + 3;
}

int f(int x) {
  return g(x);
}

int main (void) {
  return f(8) + 1;
}
