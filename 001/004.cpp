#include <stdio.h>

bool isAnagrams(char str1[], int len1, char str2[], int len2)
{
  if (len1 != len2)
    return false;

  int saveCount[256] = {0,};
  for(int i=0 ; i<len1 ; i++) {
    int idx = str1[i] - 'a';
    saveCount[idx]++;
  }

  for(int i=0 ; i<len2 ; i++) {
    int idx = str2[i] - 'a';
    if(--saveCount[idx] < 0)
      return false;
  }

  return true;
}

void test_isAnagrams(char str1[], int len1, char str2[], int len2, bool result)
{
  if(isAnagrams(str1, len1, str2, len2) == result) printf("TC(%s) OK\n", str1);
  else printf("TC(%s) Failed\n", str1);
}

int main(void)
{
  test_isAnagrams ("dog", 3, "god", 3, true);
  return 0;
}
