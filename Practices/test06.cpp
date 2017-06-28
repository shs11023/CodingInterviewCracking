#include <stdio.h>

void rperm(int arr[], int size, int n, int k, int idx)
{
  if(k == size){
    for(int i=0 ; i<size ; i++)
      printf("%d ", arr[i]);
    printf("\n");
    return;
  }

  for(int i=0 ; i<n ; i++) {
    arr[size] = i;
    rperm(arr, size+1, n, k, idx+1);
  }
}

int main()
{
  int arr[100];
  int n=3;
  int k=3;
  rperm(arr, 0, n, k, 0);

  return 0;
}
