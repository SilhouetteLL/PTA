// 模拟字符串的编码与解码 注意编码与解码时处理的数字可能不只一位

#include <bits/stdc++.h>
using namespace std;

// 字符串的编码过程
string encode(string &str)
{
    string res;
    size_t j = -1;
    char alpha;
    for(size_t i = 0; i < str.size(); i = j)
    {
        alpha = str[i];
        while(str[++j] == alpha);
        // j-i为连续相同的字符个数
        if(j - i > 1)
        {
            res += to_string(j - i);
        }
        res += alpha;
    }
    return res;
}

// 字符串的解码过程
string decode(string &str)
{
    string res;
    for(size_t i = 0; i < str.size(); i++)
    {
        int sum = 0;
        // 处理数字
        while(isdigit(str[i]))
        {
            sum = sum * 10 + (str[i] - '0');
            i++;
        }
        if(sum)
        {
            res.append(sum, str[i]);
        }
        else
        {
            res += str[i];
        }
    }
    return res;
}

int main()
{
    char ch;
    string str, res;
    scanf("%c", &ch);
    getchar();
    getline(cin, str);
    res = (ch == 'C' ? encode(str) : decode(str));
    cout<<res;
    return 0;
}
