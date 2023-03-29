#define _CRT_SECURE_NO_WARNINGS 1
int addDigits(int num) {
    int ans = 0;
    while (1)
    {
        if (num > 9)
        {
            while (num)
            {
                ans += num % 10;
                num /= 10;
            }
            num = ans;
            ans = 0;
        }
        else
        {
            break;
        }
    }
    return num;
}