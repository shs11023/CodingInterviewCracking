#include <stdio.h>
#include <string.h>

typedef struct _num {
  char number[300]; //MAX
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

void toNum (int t, Number *v)
{
  int temp = t;
  v->len = 0;
  while(temp>0){
      v->number[v->len] = (temp%10) + '0';
      v->len++;
      temp/=10;
  }
}

void copyNum (Number *d, Number *s)
{
  memcpy(d, s, sizeof(Number));
}

Number calculate(Number mem[], int const n, int const face)
{
  if (n<0) {
    Number zero ={"0", 0};
    return zero;
  }
  else if (n==0) {
    Number zero ={"1", 1};
    return zero;
  }

  if (0 != mem[n].len)
    return mem[n];

  Number count = {"0", 0};
  for (int i=1 ; i<=face ; i++){
    Number temp = calculate (mem, n-i, face);
    addNum(count, temp, &count);
  }

  copyNum (&mem[n], &count);
  return count;
}

int main(void)
{
  const int n = 510;
  int face = 6;
  Number mem[n+1] = {0,};

  Number answer = calculate(mem, n, face);

  printf("The answer is ");
  for (int i=answer.len-1 ; i>=0 ; i--)
    printf("%c", answer.number[i]);
  printf("\n");

  return 0;
}
