#include <stdio.h>

int min = 10;
int subsetMax (int dp[], int size, int idx, int arr[], int n, int m)
{
  if(n == idx) {
    int sum = 0;
    for(int i=0 ; i<size ; i++)
      sum += arr[dp[i]];


    if(m == sum){
      if(min > size)
        min = size;

      for(int i=0 ; i<size ; i++)
        printf("%d ", arr[dp[i]]);
      printf("\n");
      return 1;
    }
    return 0;
  }

  dp[size] = idx;
  int a = subsetMax (dp, size+1, idx+1, arr, n, m);
  int b = subsetMax (dp, size, idx+1, arr, n, m);

  if(a>b)
    return a;
  return b;
}

int main (void)
{
  int dp[10]={0,};
  int arr[] ={6,9,13,14,20,21,22,30,49,55};
  int len = 10;
  int value = 110;
  int max = subsetMax(dp, 0, 0, arr, len, value);

  printf("min : %d\n", min);

  return 0;
}
