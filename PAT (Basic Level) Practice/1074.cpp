// 将两个加数以字符串的形式存储 并且使用formatStr函数将其的长度填充为21(多1位防止相加后有进位)，便于各位数进行对齐相加

#include <bits/stdc++.h>
using namespace std;

string formatStr(const string &str)
{
    string res;
    res.append(21 - str.size(), '0');
    res += str;
    return res;
}

int main()
{
    int digit[21] = {0};
    string str, a, b, res(21, '0');
    cin>>str>>a>>b;
    int n = str.size(), i, aLen = a.size(), bLen = b.size(), cnt = max(aLen, bLen), carry = 0;
    a = formatStr(a);
    b = formatStr(b);
    //digit存储每一位的数位进制
    for(i = 0; i < n; i++)
    {
        digit[20 - i] = (str[n - 1 -i] == '0' ? 10 : str[n - 1 - i] - '0');
    }
    //start记录最高位的位置
    int start = 21;
    // cnt记录相加后结果的位数
    for(i = 1; i <= cnt; i++)
    {
        int sum = carry;
        sum += (a[21 - i] - '0') + (b[21 - i] - '0');
        if(sum)
        {
            // 模拟每一位相加的过程 同时还要使用carry记录进位
            start--;
            res[start] = (sum % digit[start]) + '0';
            carry = sum / digit[start];
        }
    }
    // 还有进位 添加进位并且最高位左移一位
    if(carry)
    {
        res[21 - i] = carry + '0';
        start--;
    }
    // 如果最高位一直未发生变化 表明相加后结果为0 将最高位左移一位变为个位
    if(start == 21)
    {
        start--;
    }
    // 从最高位到最低位输出每一位数字
    for(i = start; i < 21; i++)
    {
        printf("%c",res[i]);
    }
    return 0;
}
