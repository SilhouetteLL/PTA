// 找规律:
// 数列一共有n个元素,寻找每一个元素出现的次数,该次数和该元素的下标i有关.
// 对于下标为i的数列元素(称为目标元素):其后面有n - 1 - i个元素,再加上目标本身,此时会出现n - i次.
// 而该元素前面的元素下标为0~i-1个,共有i个元素,每个目标元素的前趋元素中还会在计算中带有n - i个目标元素,此时目标元素出现了i * (n - i)次.
// 因此,每一个数列元素会出现(i + 1) * (n - i)次 数列的片段和就是每个元素的值乘自身出现的次数再累和的结果.

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    double seq[n], res = 0;
    for(int i = 0; i < n; i++)
    {
        int factor = (i + 1) * (n - i);
        scanf("%lf", seq + i);
        res += seq[i] * factor;
    }
    printf("%.2f\n", res);
    return 0;
}
