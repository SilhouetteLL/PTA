//练习使用条件运算符 ? : 
#include <bits/stdc++.h>
using namespace std;
struct Person
{
    //重载< 根据出生日期进行排序(降序)
    bool operator< (const Person& p)
    {
        return this->year ^ p.year ? this->year < p.year : (this->month != p.month ? this->month < p.month : this->day < p.day);
    }
    string name;
    int year;
    int month;
    int day;
    Person() {};
    Person(const string& s, int &y, int &m, int &d):name(s), year(y), month(m), day(d) {};
};

// 判断给出的日期是否有效
bool isValid(Person p)
{
    if(!(p.year ^ 1814))
    {
        if(p.month == 9)
        {
            return p.day >= 6;
        }
        else
        {
            return p.month > 9;
        }
    }

    else if(!(p.year ^ 2014))
    {
        if(p.month == 9)
        {
            return p.day <= 6;
        }
        else
        {
            return p.month < 9;
        }
    }

    else
    {
        return p.year > 1814 && p.year < 2014;
    }
}

int main()
{
    int n;
    if(scanf("%d", &n)  == 1)
    {

        int y, m, d;
        vector<Person>res;
        for(int i = 0; i < n; i++)
        {
            string str;
            cin>>str;
            scanf("%d/%d/%d", &y, &m, &d);
            Person p = Person(str, y, m, d);
            if(isValid(p))
            {
                res.emplace_back(p);
            }
        }
        int len = res.size();
        printf("%d", len);
        if(len)
        {
            sort(res.begin(), res.end());
            cout<<" "<<res[0].name<<" ";
            cout<<res[len - 1].name;
        }
        printf("\n");
    }
    return 0;
}
