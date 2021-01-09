#include<stdio.h>
#include "fun.h"
int main() 
{
  int a, b, c, d,e;
  a = 50;
  b = 10;
  c=15;
  d = sub(a,b);
  e = cube(c);
  printf("Subtraction of %d and %d is %d\n",a,b,d);
  printf("Cube of %d is %d\n",c,e);
  return 0;
}
