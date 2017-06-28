#include <stdio.h>

void subset(int arr[], int size, int idx, int n)
{
  if(n == idx) {
    printf("{");
    for(int i=0 ; i<size ; i++) {
      printf("%d", arr[i]+1);
      if(i+1<size) printf(" ");
    }
    printf("}\n");
    return;
  }

  arr[size] = idx;
  subset(arr, size+1, idx+1, n);
  subset(arr, size+0, idx+1, n);
}

int main(void)
{
  int arr [] = {0,};
  int n = 3;

  subset(arr, 0, 0, n);

  return 0;
}
