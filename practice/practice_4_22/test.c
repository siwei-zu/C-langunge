#define _CRT_SECURE_NO_WARNINGS 1
int main()//�ַ�����ˡ�
{
    char num1[] = "456789216598";
    char num2[] = "498465468798";
    int length1 = strlen(num1) - 1;//��ȡ�����ַ����ĳ���
    int length2 = strlen(num2) - 1;
    int sum = 0;
    int n = 0;
    int tmp = 0;
    int* number = malloc(sizeof(int) * (length1 + length2 + 2));//����ռ䣬�����þ���ó���������˵ó��Ǹ�����λ��ֻ��������λ��֮�ͻ��ڴ˻����ϼ�һ
    memset(number, 0, (sizeof(int)) * (length1 + length2 + 2));//��ʼ��ȫΪ��
    int i = 0;
    for (i = length1; i >= 0; i--)//����ѭ����ÿ�������ܳ˵�
    {
        int j = 0;
        for (j = length2; j >= 0; j--)
        {
            sum = (num2[j] - 48) * (num1[i] - 48);
            int k = 0;
            while (sum)
            {
                number[length1 + j - n - k + 1] += sum % 10;//���õ����鰴λ����number�ռ䣬��ĩλ��ʼ
                sum /= 10;
                k++;
            }
            int y = 0;
            tmp = length1 + length2 - y + 1;
            while (tmp)//������Ϊ������һ��ѭ������number���Ԫ���д���9�������Ҫ��ǰһλ��һ��λȡ����
            {
                int x = 0;
                if (number[tmp] > 9)
                {
                    x = number[tmp];
                    number[tmp] = x % 10;
                    x /= 10;
                    number[tmp - 1] += x;

                }
                tmp--;//�����ñ������飨̫�죬�벻��զд�Ͳ��ñ����ˣ�
            }
            y++;//������Ǵӵ���ѭ������number�е�Ԫ�ؿ�ʼ����λ��ʼ�ж��Ƿ��д���9��Ԫ��
        }
        n += 1;//ÿ���ڲ�ѭ������ʱ����Ҫ��������Ԫ�������һλ��
    }
    char* str;
    if (number[0] == 0)//��������ռ佫����õ���������ַ������ַ����У������ַ���
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
