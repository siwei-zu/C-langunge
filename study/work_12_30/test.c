#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int* printNumbers(int n, int* returnSize) {
    int x = n;
    int num = 1;
    while (x)
    {
        num *= 10;
        x--;
    }
    int* arr = (int*)malloc(sizeof(int) * (num - 1));
    for (x = 0; x < num; x++)
    {
        arr[x] = x + 1;
    }
    *returnSize = (num - 1);
    return arr;
}

//4.	�������������ʽ��ֵ�����Լ��������������ó�����⣬�Ƚϵõ��Ľ���Ƿ�һ�£���
//����x = 2��a = 7��y = 4������ʽ: x + a % 3 * x + y % 2 / 4 ��ֵ
//����a = 2��b = 3��x = 3.5��y = 2.5������ʽ : (float)(a + b) / 2 + (int)x % (int)y��ֵ
//5.	д��������ʽ�����a��ֵ����ԭ��a = 10��n = 5����a��n�Ѷ�������ͱ��������Լ��������������ó�����⣬�Ƚϵõ��Ľ���Ƿ�һ�£���
//�� a += a   �� a -= 2   �� a *= 2 + 3   �� a /= a + a   �� a %= (n %= 2)   �� a += a -= a *= a
//6.	���벢���е�3����3 - 3����3 - 6�еĳ���ͨ������������Ӧ�ĸ�ʽ˵����
//7.	���벢���е�3����3 - 8����3 - 10�еĳ���ע���������ݵĸ�ʽ��
//8.	��Ƴ�������һ��Բ����İ뾶r�͸�h����Բ����ĵ��ܳ�c�������s�������s1�������s2�����v��

//#define PI 3.141593
//int main()
//{
//	float r, h;
//	printf("������Բ����İ뾶�͸�(����������������ʽΪxx.0):>");
//	scanf("%f%f", &r, &h);
//	printf("Բ����ĵ��ܳ� c=%.2f\n", 2 * PI * r);
//	printf("Բ����ĵ���� s=%.2f\n", r * PI * r);
//	printf("Բ����Ĳ���� s1=%.2f\n", 2 * PI * r*h);
//	printf("Բ����ı���� s2=%.2f\n", r * PI * r * 2+ 2 * PI * r * h);
//	printf("Բ�������� v=%.2f\n", r * PI * r * h);
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	int n = 5;
//	printf("%d\n", a += a);
//	printf("%d\n", a -= 2);
//	printf("%d\n", a *= 2 + 3);
//	printf("%d\n", a /= a + a);
//	printf("%d\n", a %= (n %= 2));
//	printf("%d\n", a += a -= a *= a);
//	return 0;
//}
//int main()
//{
//	int a = 2;
//	int b = 3;
//	float x = 3.5f;
//	float y = 2.5f;
//	printf("%.1f\n", (float)(a + b) / 2 + (int)x % (int)y);
//	return 0;
//}

//int main()
//{
//	int x = 2;
//	int a = 7;
//	int y = 4;
//	printf("%d\n", x + a % 3 * x + y % 2 / 4);
//	return 0;
//}