//面试题50-4：判断变位词

#include<stdio.h>
#include<string.h>
bool IsChangePos(char *str1,char *str2)
{
	if (str1 == NULL || str2 == NULL || strlen(str1) != strlen(str2))
	{
		return false;
	}

	const int size = 256;
	unsigned int hashTable[size];
	for (unsigned int i = 0; i < size; i++)
	{
		hashTable[i] = 0;
	}

	char *pStr_1 = str1;
	char *pStr_2 = str2;
	char *pStr_3 = str2;

	while (*pStr_1 != '\0')
	{
		hashTable[*(pStr_1++)]++;
	}

	while (*pStr_2 != '\0')
	{
		hashTable[*(pStr_2++)]--;
	}
	
	while (*pStr_3 != '\0')
	{
		if(hashTable[*(pStr_3)] == 0)
		{
			pStr_3++;
		}
		else
		{
			return false;
		}
	}
	return true;
}

// ====================测试代码====================

int main(int argc, char* argv[])
{
	char str1[] = "silent";
	char str2[] = "listen";
	if(IsChangePos(str1,str2)) {printf("Is ChangePosWords\n");}
	else {printf("Isn't ChangePosWords\n");}

	char str3[] = "evil";
	char str4[] = "live";
	if(IsChangePos(str3,str4)) {printf("Is ChangePosWords\n");}
	else {printf("Isn't ChangePosWords\n");}

	char str5[] = "abcdefg";
	char str6[] = "gfedcoa";
	if(IsChangePos(str5,str6)) {printf("Is ChangePosWords\n");}
	else {printf("Isn't ChangePosWords\n");}

	char str7[] = "abcdefg";
	char str8[] = "tt";
	if(IsChangePos(str7,str8)) {printf("Is ChangePosWords\n");}
	else {printf("Isn't ChangePosWords\n");}

    return 0;
}