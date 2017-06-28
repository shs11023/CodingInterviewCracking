#include <stdio.h>

int max(int x, int y){
  if(x>y)return x;
  return y;
}

int mem[100][100] = {0,};

int subset(int arr[], int v[], int w[], int num, int weg, int size, int idx){


  if(num == idx) {
    int sumw = 0, sumv = 0;
    for(int i=0 ; i<size ; i++){
      sumw += w[arr[i]]; sumv += v[arr[i]];
    }

    if(sumw == weg)
      return sumv;
    return 0;
  }

  if(mem[size][idx] != 0) return mem[size][idx];

  arr[size] = idx;

  return mem[size][idx] = max(subset(arr,v,w,num,weg,size+1,idx+1), subset(arr,v,w,num,weg,size  ,idx+1));
}

int main()
{
  int num = 10;
  int weg = 20;
  int v[] = {2,3,3,4,4,5,7,8,8,9};
  int w[] = {3,5,7,4,3,9,2,9,5,10};
  int arr[10] = {0,};

  printf("max value : %d\n", subset(arr,v,w,num,weg,0,0));

  return 0;
}
