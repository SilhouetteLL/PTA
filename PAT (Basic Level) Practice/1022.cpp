//该题考察如何将一个十进制的非负数数转化为任意的D进制数(2<=D<= 9)
//对于0 其任意D进制数仍为0
//对于正整数 用该正整数不断地除以D直到该正整数为1 然后由每次除法运算得到的余数组成该正整数的D进制数
//第一次除法运算得到的余数是D进制数的最低位 而最后一次除法运算得到的余数是D进制数的最高位
//根据这个特点 可以用栈存储每一次除法运算得到的余数 从栈顶到栈底依次为D进制数的最高位到最低位
//然后依次弹出栈顶元素 组成D进制数
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long A, B, D;
    while(scanf("%lld%lld%lld", &A, &B, &D) == 3)
    {
        long long sum = A + B;
        stack<int>digit;
        if(sum)
        {
            while(sum)
            {
                digit.push(sum % D);
                sum /= D;
            }
        }
        else
        {
            digit.push(0);
        }

        while(!digit.empty())
        {
            printf("%d",digit.top());
            digit.pop();
        }
        printf("\n");
    }
    return 0;
}
