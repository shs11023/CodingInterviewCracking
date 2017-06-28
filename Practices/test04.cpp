#include <stdio.h>


void subset(int arr[], int len, int n, int idx) {
  if(idx == n) {
    for(int i=0 ; i<len ; i++)
      printf("%d ", arr[i]);
    printf("\n");
    return ;
  }

  //arr[len] = idx;
  subset(arr, len+1, n, idx+1);
  subset(arr, len  , n, idx+1);
}


int main(void)
{
  int arr[] = {1,2,3,4};
  subset(arr, 0, 3, 0);
  return 0;
}
