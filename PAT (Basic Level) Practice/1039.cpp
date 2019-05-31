#include <bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<char, int>table;  // 存储所需要的每种珠子的数量
    string seller, purchaser;       // seller代表卖家的珠串  purchaser代表想做的珠串
    cin>>seller>>purchaser;     
    bool flag = true;               // 是否购买的标志 如果购买为true 不购买为false
    int lack = 0;                   // 表明不购买时卖家珠串中所缺少的需要的珠子数量
    for(auto ch : purchaser)
    {
        table[ch]++;
    }
    // 遍历卖家的珠串 遇到需要的珠子 则将其相应的需求值减一
    for(auto ch : seller)
    {
        if(table[ch])
        {
            table[ch]--;
        }
    }
    // 遍历table 
    for(auto iter = table.begin(); iter != table.end(); iter++)
    {
        // 如果还有需求的珠子 则不购买 并且记录缺少的需要珠子的数量
        if(iter->second)
        {
            flag = false;
            lack += iter->second;
        }
        // 如果还有需求的珠子 则不购买 并且记录缺少的需要珠子的数量
    }
    if(flag)
    {
        // 卖家珠串的长度减去需要珠串的长度为卖家珠串中多余的珠子数量
        printf("Yes %zd\n", seller.size() - purchaser.size());
    }
    else
    {
        // 卖家珠串中缺少的需求珠子的数量
        printf("No %d\n", lack);
    }
    return 0;
}
