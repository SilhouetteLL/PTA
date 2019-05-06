//模拟除法运算的过程
//如果得到的结果以0开头 向后找到第一个非0的数为商的最高位
//res为存储商的结果字符串 remain为每次运算的余数 quotient为每次运算的商
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string dividend, res;
    int divisor, val, remain = 0, quotient;
    cin>>dividend>>divisor;
    int len = dividend.length(), i;
    for(int i = 0; i < len; i++, remain *= 10)
    {
        //进行一次运算
        val = (dividend[i] - '0') + remain; //得到该次运算的被除数
        quotient = val / divisor;           //得到该次运算的商
        remain =  val % divisor;            //得到该次运算的余数
        res += to_string(quotient);         //该次运算的商添加到结果字符串中
    }
    len = res.length();

    //注意全0的情况 因此遍历到结果字符串的最后一个数位的前一个数位 使得最终结果为0
    for(i = 0; i < len - 1 && !(res[i] - '0'); i++);
    for(; i < len; i++)
    {
        printf("%c", res[i]);
    }
    printf(" %d\n", remain / 10);
    return 0;
}
