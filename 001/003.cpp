#include <stdio.h>

void removeDuplicateCharcters (char str[], int len)
{
  int savebits = 0;
  for (int i=0 ; i<len ; i++) {
    if (str[i] < 'a' || str[i] > 'z') continue;

    int bit = str[i] - 'a';
    int mask_bit = 1<<bit;
    if (savebits & mask_bit) {
      for (int j=i ; j<(len-1) ; j++) str[j] = str[j+1];
      len--;
      i--;
    }
    savebits |= mask_bit;
  }

  str[len] = '\0';
}

void test_removeDuplicateCharcters (char str[], int len, char result[], int result_len)
{
  char * tempStr = new char[len];
  for (int i=0 ; i<len ; i++) tempStr[i] = str[i];

  removeDuplicateCharcters (tempStr, len);

  bool isOkay = true;
  for (int i=0 ; i<result_len ; i++){
    if (tempStr[i] != result[i]) {
      isOkay = false;
      break;
    }
  }

  if(isOkay) printf("TC(%s:%s) OK\n", str, tempStr);
  else printf("TC(%s:%s) Failed\n", str, tempStr);
}

int main(void)
{
  test_removeDuplicateCharcters ("abcdef", 6, "abcdef" , 6);
  test_removeDuplicateCharcters ("aacdef", 6, "acdef", 5);
  test_removeDuplicateCharcters ("aaaaaa", 6, "a", 1);

  return 0;
}
