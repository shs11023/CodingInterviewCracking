#include <stdio.h>

void reverseString (char str[], int len)
{
  int left = 0, right = len-1;
  while(left<right) {
    str[left]  = str[left] - str[right];
    str[right] = str[left] + str[right];
    str[left]  = str[right] - str[left];
    left ++;
    right --;
  }
}

void test_reverseString (char str[], int len, char result[])
{
  char *testStr = new char[len];
  for(int i=0 ; i<len ; i++) testStr[i] = str[i];

  reverseString (testStr, len);

  bool isOkay = true;
  for(int i=0 ; i<len ; i++) if(testStr[i] != result[i]) {isOkay = false; break;}

  if (isOkay) printf("TC(%s:%s) OK\n", str, testStr);
  else printf("TC(%s) Failed\n", str);

  delete [] testStr;
}

int main(void)
{
  test_reverseString ("apple", 5, "elppa");
  test_reverseString ("apple", 5, "apple");
  return 0;
}
