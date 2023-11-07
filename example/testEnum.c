#include <stdio.h>

const enum PERCENT {
  ZER = 0,
  ONE = 14,
  TWO = 28,
  THR = 42,
  FOU = 56,
  FIV = 70,
  SIX = 84,
  SEV = 100
} per;

unsigned char map(unsigned char value);

unsigned char map(unsigned char value)
{
  enum PERCENT per = ZER;
  
  return per * value;
}

int main()
{
  printf("percent =  %u%% \n",map(3));
  return 0;
}