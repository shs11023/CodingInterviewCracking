#include <stdio.h>

int subset (int arr[], int size, int idx, int n, int m)
{
  if(idx == n) {
    if(size == m){
      for(int i=0 ; i<size ; i++)
        printf("%d,", arr[i]+1);

      printf("\n");
      return 1;
    }

    return 0;
  }

  arr[size] = idx;
  int a = subset(arr, size+1, idx+1, n, m);
  int b = subset(arr, size, idx+1, n, m);

  return a+b;
}

int main (void)
{
  int n = 10;
  int m = 10;
  int arr[8]={0,};

  printf("max: %d\n", subset(arr,0,0,n,m));


  return 0;
}
