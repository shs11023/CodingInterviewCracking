#include <stdio.h>

int pal(const char *str, int len)
{
  int l = len-1;
  int r = 0;
  int count = len;

  while(r<l){
    if(str[r] == str[l]){
      l--;
      r++;
    }else {
      count++;
      r++;
    }

  }

  return count;
}

int main (void)
{
  const char *str = "abcccc";
  int len = 6;

  printf("answer: %d\n", pal(str,len));

  return 0;
}
