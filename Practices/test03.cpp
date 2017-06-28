#include <stdio.h>

int max(int x, int y){
  if(x>y)return x;
  return y;
}
int subseq(int arr[], int len, int p)
{
  if(len == (p+1)) return arr[len-1];
  int max = 0;
  for(int i=p; i<len ; i++ ){
    if(arr[p]>=arr[i]) continue;
    int sum = arr[p] + subseq(arr, len, i);
    if(sum > max) max = sum;
  }

  return max;
}


int main(void)
{
  int arr[] = {10,20,1,9,11,19,2,8,12,18,5,15,4,6,14,16,3,7,13,17};
  printf("max : %d\n", subseq(arr,20,0));
  return 0;
}
