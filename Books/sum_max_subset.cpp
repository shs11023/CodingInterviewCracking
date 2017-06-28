#include <stdio.h>

bool calc_subset_sum (int arr[], const int n, const int m)
{
  int c[n+1][m+1];
  int i, j;
  for (i=0 ; i<=n ; i++)
    c[i][0] = 1;
  for (i=1 ; i<=m ; i++)
    c[0][i] = 0;

  for (i=1 ; i<=n ; i++) {
    for (j=1 ; j<=m ; j++) {
      c[i][j] = 0;
      if (j >= arr[i-1]) {
        if (j >= arr[i-1]) {
          if (c[i-1][j-arr[i-1]] == 1)
            c[i][j] = 1;
        }
        if (c[i-1][j] == 1)
          c[i][j] = 1;
      }
    }
  }

  for (i=0 ; i<=m ; i++) {
    printf("m:%3d",i);
    for (j=0 ; j<=n ; j++) {
      printf("[%2d]", c[j][i]);
    }
    printf("\n");
  }
printf("\n\n\n");
  int nn = n;
  int mm = m;
  while(nn>0 && m>=0) {
    if(c[nn][mm] == 1) {
      mm -= arr[nn-1];
      printf("[%d]",arr[nn-1]);
    }
    nn--;
  }

  return (c[n][m] == 1);
}

int main(void)
{
  int arr[] = {5,9,13,14,20,21,22,30,49,55};
  if(calc_subset_sum (arr, 10, 81))
    printf("OK\n");

  return 0;
}
