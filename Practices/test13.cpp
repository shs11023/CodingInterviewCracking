#include <stdio.h>

int max_sz = 0;
int max_arr[5];

int pack(int dp[], int sz, int idx, int w[], int v[], int n, int m)
{
  if(n == idx) {
    int sum = 0;
    for(int i=0 ; i<sz ; i++)
      sum += w[dp[i]];
    if(sum == m) {
      sum = 0;
      for(int i=0 ; i<sz ; i++)
        sum += v[dp[i]];

      if(sum>max_sz){
        max_sz = sz;
        for(int i=0 ; i<sz ; i++)
          max_arr[i] = w[dp[i]];
      }
      return sum;
    }

    return 0;
  }

  dp[sz] = idx;
  int a = pack(dp, sz+1, idx+1, w, v, n, m);
  int b = pack(dp, sz, idx+1, w, v, n, m);

  if(a>b) return a;
  return b;
}

int main (void)
{
  int w[] = {3,4,1,2,3};
  int v[] = {2,3,2,3,6};
  int dp[5]={0,};
  int n = 5;
  int m = 7;


  pack(dp, 0, 0, w, v, n, m);

  for(int i=0 ; i<max_sz ; i++)
    printf("%d ", max_arr[i]);

  printf("\nmax : %d\n", max_sz);
  return 0;
}
