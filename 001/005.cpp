#include <stdio.h>
#include <string.h>

void replaceSpaces (char str[], int len, char result[]) {
  int space_num = 0;
  for(int i=0 ; i<len ; i++)
    if(str[i] == ' ')
      space_num++;

  int new_len = len + (space_num*3) - space_num;
  for(int i=len-1,j=new_len-1 ; i>=0 ; i--, j-- ) {
    if(str[i] == ' ') {
      result[j--] = '%';
      result[j--] = '0';
      result[j] = '2';
    }
    else result[j] = str[i];
  }

  result[new_len] = '\0';
}

void test_replaceSpaces (char str[], int len, char result[])
{
  char buff[1024];
  replaceSpaces (str, len, buff);
  if (strcmp (buff, result) == 0) printf("TC(%s) OK\n", str);
  else printf("TC(%s) Failed\n", str);
}

int main(void)
{
  test_replaceSpaces ("AB CD", 5, "AB20%CD");
  test_replaceSpaces ("AB C D", 6, "AB20%C20%D");
  return 0;
}
