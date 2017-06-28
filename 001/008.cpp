#include <stdio.h>

bool isSubstring (char str[], char str2[], int len1, int len2)
{
  for(int i=0 ; i<(len1*2) ; i++) {
    int idx = i%len1;
    if (str[idx] == str2[0]) {
      int j;
      for (j=0 ; j<len2 ; j++){
        int iidx = (idx+j)%len1;
        if (str[iidx] != str2[j]) break;
      }
      if (j==len2) return true;
    }
  }
  return false;
}

void test_isSubstring (char str[], char str2[], int len1, int len2, bool result) {
  if (isSubstring (str, str2, len1, len2) == result) printf("TC(%s) OK\n", str);
  else printf("TC(%s) Failed\n", str);
}

int main(void)
{
  test_isSubstring("abcdefg", "fga", 7, 3, true);
  test_isSubstring("abcdefg", "fgad", 7, 4, false);

  return 0;
}
