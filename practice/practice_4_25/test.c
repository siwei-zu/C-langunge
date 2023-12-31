#define _CRT_SECURE_NO_WARNINGS 1
int main()//关于浮点型的数据在内存中如何存储。
{
	int n = 9;
	//00000000000000000000000000001001-整形9的二进制表达形式
	float* pn = (float*)&n;
	//0 00000000 00000000000000001001//整形9以这种形式储存到float类型中，因为指数位全为零所以是无穷小的一个数，
	printf("%d\n", n);//9
	printf("%f\n", *pn);//0.000000
	*pn = 5.5;//101.1--5.5的二进制形式
	//小数储存后1.011*2^2
	//0100 0000 1011 0000 0000 0000 0000 0000
	//0x40b00000
	//0          10000001                            01100000000000000000000
	//符号位     指数部分真实值加127，2+127          有效部分
	//01000000101100000000000000000000
	printf("%d\n", n);//1085276160
	printf("%f\n", *pn);//5.500000
	return 0;
}
