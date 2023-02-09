#define _CRT_SECURE_NO_WARNINGS 1
#include <Stdio.h>
#include <assert.h>


int my_strlen(char* str)
{
	assert(str);
	int count = 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return count;
}

void reverse_string(char* str)
{
	assert(str);
	int len = my_strlen(str);
	char tmp = *str;
	*str = *(str + len - 1);
	*(str + len - 1) = '\0';
	if(my_strlen(str+1)>1)
	{
		reverse_string(str + 1);
	}
	*(str + len - 1) = tmp;
}

int main()//ÄæĞò×Ö·û´®ÄÚÈİ£¬µİ¹é
{
	char arr[] = "abcdefg";
	reverse_string(arr);
	printf("%s\n", arr);
	return 0;
}