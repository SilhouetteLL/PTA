#include <bits/stdc++.h>
using namespace std;
int main()
{
    string prev, cur;       // prev记录前一个字符串 cur记录当前字符串
    char ch;
    int n;
    scanf("%c%d", &ch, &n);
    // 直接输出第一项
    if(n == 1)
    {
        printf("%c", ch);
    }
    // 递推求第n项
    else
    {
        prev += ch;
        int len;
        for(int i = 2; i <= n; i++)
        {
            cur = "";
            ch = prev[0];                   // 初始化ch为d
            for(size_t j = 0; prev[j]; )    // 遍历字符串
            {
                len = 0;
                for(; prev[j] == ch && prev[j]; j++, len++);    // 寻找一个连续字符相同的子串
                cur += ch;                                      // 添加该子串的字符
                cur += len + '0';                               // 添加该子串的长度
                if(prev[j])                                     // 未遍历完字符串 更新ch为后续字符
                {
                    ch = prev[j];
                }
            }
            prev = cur;                                         // 更新prev
        }
        cout<<cur;
    }

    printf("\n");
    return 0;
}
