#define _CRT_SECURE_NO_WARNINGS 1
int main()//字符串相乘。
{
    char num1[] = "456789216598";
    char num2[] = "498465468798";
    int length1 = strlen(num1) - 1;//获取两个字符串的长度
    int length2 = strlen(num2) - 1;
    int sum = 0;
    int n = 0;
    int tmp = 0;
    int* number = malloc(sizeof(int) * (length1 + length2 + 2));//申请空间，这里用经验得出两个数相乘得出那个数的位数只能是两数位数之和或在此基础上加一
    memset(number, 0, (sizeof(int)) * (length1 + length2 + 2));//初始化全为零
    int i = 0;
    for (i = length1; i >= 0; i--)//两层循环让每个数都能乘到
    {
        int j = 0;
        for (j = length2; j >= 0; j--)
        {
            sum = (num2[j] - 48) * (num1[i] - 48);
            int k = 0;
            while (sum)
            {
                number[length1 + j - n - k + 1] += sum % 10;//将得到的书按位填入number空间，从末位开始
                sum /= 10;
                k++;
            }
            int y = 0;
            tmp = length1 + length2 - y + 1;
            while (tmp)//这里是为了在上一个循环过后number里的元素有大于9的情况需要向前一位进一本位取余数
            {
                int x = 0;
                if (number[tmp] > 9)
                {
                    x = number[tmp];
                    number[tmp] = x % 10;
                    x /= 10;
                    number[tmp - 1] += x;

                }
                tmp--;//这里让遍历数组（太挫，想不到咋写就不用遍历了）
            }
            y++;//这里就是从当次循环对象number中的元素开始的那位开始判断是否有大于9的元素
        }
        n += 1;//每次内层循环结束时，都要让下两个元素向左进一位。
    }
    char* str;
    if (number[0] == 0)//这里申请空间将上面得到的数变成字符填入字符串中，返回字符串
    {
        str = malloc(sizeof(char) * length1 + length2 + 2);
        memset(str, '\0', length1 + length2 + 2);
        for (i = length1 + length2; i >= 0; i--)
        {
            str[i] = number[i + 1] + 48;
        }
    }
    else
    {
        str = malloc(sizeof(char) * length1 + length2 + 3);
        memset(str, '\0', length1 + length2 + 3);
        for (i = length1 + length2 + 1; i >= 0; i--)
        {
            str[i] = number[i] + 48;
        }
    }
    printf("%s\n", str);
    puts(str);
    return 0;
}
