#include <stdio.h>
#include <stack>

void print_allSubsets (int arr[], int len)
{
  // 0
  // 0 1
  // 0 1 2 12

  for (int i=0 ; i<len ; i++) {
    for (int j=0 ; j<=i ; j++) {
      printf("{");
      for (int k=0 ; k<=j ; k++)
        printf("%d,",k+i);
      printf("}");
    }
    printf("\n");
  }

}

int main (void)
{
  int arr[] = {3, 1, 2, 4};
  print_allSubsets (arr, 4);
  return 0;
}
