#include <stdio.h>

typedef struct _num {
  char number[999999]; //MAX
  int len;
}Number;

void addNum (Number &a, Number &b, Number *v)
{
  int max_len = (a.len>b.len)?a.len:b.len;
  int c = 0;
  for(int i=0 ; i<max_len ; i++) {
    int a1 = (i<a.len)?(a.number[i]-'0') : 0;
    int b1 = (i<b.len)?(b.number[i]-'0') : 0;

    v->number[i] = ((a1 + b1 + c) % 10) + '0';
    c = (a1 + b1 + c)/10;
  }
  v->len = max_len;

  if (c > 0) {
    v->number[v->len] = c + '0';
    v->len ++;
  }
}

int main(void)
{
  const int n = 8181;
  Number dp[3] = {0,};

  dp[0].len = dp[1].len = 1;
  dp[0].number[0] = dp[1].number[0] ='1';

  for(int i=2 ; i<n ; i++) {
    addNum (dp[(i-1)%3], dp[(i-2)%3], &dp[i%3]);
  }

  printf("The answer is ");
  for (int i=dp[(n-1)%3].len-1 ; i>=0 ; i--)
    printf("%c", dp[(n-1)%3].number[i]);
  printf("\n");
  return 0;
}
