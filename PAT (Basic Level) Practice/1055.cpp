// 模拟拍照时的每一排的排列

#include <bits/stdc++.h>
using namespace std;
struct Person
{
    // 重载< 按照身高进行排序(升序) 如果身高相同 则字典序小的姓名的人在后
    bool operator<(const Person &p)const
    {
        return p.height == this->height ? this->name > p.name : this->height < p.height;
    }
    string name;
    int height;
    Person() {};
    Person(string s, int h):name(s), height(h) {};
};

int main()
{
    int n, k;
    while(scanf("%d%d", &n, &k) != EOF)
    {
        int i, j;
        string str;
        int h;
        vector<Person>res;
        for(i = 0; i < n; i++)
        {
            cin>>str;
            scanf("%d", &h);
            res.emplace_back(Person(str, h));
        }
        sort(res.begin(), res.end());                       
        int cnt = n - 1;
        for(i = k; i >= 1; i--)
        {
            int line = (i == k ? n / k + n % k : n / k);    // 每一排的人数 
            Person order[line];                             // 存储该排的人数的排列
            order[line / 2] = res[cnt--];                   // 将身高最高的人放入该排中间作为轴 
            for(j = 1; j <= line / 2; j++)                  // j为与轴的距离 总共循环的次数为该排的人数/2
            {
                // 依次按照身高降序将每个人入队 注意防止越界
                if(line / 2 - j >= 0)                       // 先站到轴的左边
                {
                    order[line / 2 - j] = res[cnt--];
                }
                if(line / 2 + j < line)                     // 再站到轴的右边
                {
                    order[line / 2 + j] = res[cnt--];
                }
            }
            
            for(int tmpi = 0; tmpi < line; tmpi++)          // 输出该行的排列
            {
                if(tmpi)
                {
                    printf(" ");
                }
                cout<<order[tmpi].name;
            }
            printf("\n");
        }
    }

    return 0;
}
