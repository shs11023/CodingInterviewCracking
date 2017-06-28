#include <stdio.h>

bool isAllUniqueCharacters (char str[], int len)
{
	unsigned int savebits = 0;

	int i;
	for (i=0 ; i<len ; i++) {
		if(str[i] == ' ') continue;
		if(str[i] < 'a' || str[i] > 'z') continue;

		int bit = str[i] - 'a';
		int bit_mask = 1<<bit;
		if (savebits & bit_mask) return false;
		savebits |= bit_mask;
	}

	return true;
}

void test_isAllUniqueCharacters (char str[], int len, bool result)
{
        if (isAllUniqueCharacters(str, len) == result) printf(" TC:(%s) OK \n", str);
        else printf(" TC(%s) Failed \n", str);
}

int main(void)
{
	test_isAllUniqueCharacters ("asdfzxcv", 8, true);
	test_isAllUniqueCharacters ("asdfazxc", 9, false);

	return 0;
}
