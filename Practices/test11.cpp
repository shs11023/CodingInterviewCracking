#include <iostream>

void swap (int arr[], int x, int y)
{
  int temp = arr[x];
  arr[x] = arr[y];
  arr[y] = temp;
}

int subset(int dp[], int size, int idx, int arr[], int n)
{
  if(idx == n) {
    for(int i=0 ; i<n ; i++)
      printf("%d, ", arr[dp[i]]);

    printf("\n");

    return (arr[dp[0]] != 0);
  }

  int sum = 0;

  for(int i=idx ; i<n ; i++) {
    if(i != idx && arr[dp[i]] == arr[dp[idx]]) continue;

    swap(dp, i, idx);
    sum += subset(dp, size+1, idx+1, arr, n);
    swap(dp, i, idx);
  }

  return sum;
}

int main (void)
{
  int arr[] = {1,1,2};
  int dp[4] = {0,1,2,3};
  int n = 3;

  printf("sum : %d\n",subset(dp, 0, 0, arr, n));

  return 0;
}
