// 首先给出各对不相容的物品
// 不妨使用hash表建立不相容物品之间的映射关系 但是每一个物品可能与多个物品不相容 因此需要使用unordered_map<int, vector<int> >
// 然后给出每一组待运输的物品 使用listedItem记录每一组出现在不相容物品清单中的待运输物品
// 如果该物品是之前出现在不相容物品清单中 则其可能会与后续的带传输物品不相容因此将其添加到listedItem中
// 如果添加该物品到listedItem后,listedItem中的元素不少于2个 则就需要检测是否存在不相容的物品
// 若检测到有一对物品不相容 则将isSafe置为false 表明无法安全运输
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    if (scanf("%d%d", &n, &m) == 2)
    {
        unordered_map<int, vector<int>> table; //记录某一个物品的所有的不相容物品
        int i, j, incompatibleItem1, incompatibleItem2;
        for (i = 0; i < n; i++)
        {
            if (scanf("%d%d", &incompatibleItem1, &incompatibleItem2) == 2)
            {
                // 逐步建立每一个物品与其不相容的物品之间的映射关系
                table[incompatibleItem1].emplace_back(incompatibleItem2);
                table[incompatibleItem2].emplace_back(incompatibleItem1);
            }
        }

        for (i = 0; i < m; i++)
        {
            int len;
            if (scanf("%d", &len) == 1)
            {
                vector<int> goods(len);              // goods记录当前的传输物品
                vector<int> listedItem;              // listedItem记录存在于不相容物品清单中的待运输物品
                size_t quantity = listedItem.size(); // record the quantity of goods emerging in the list of the compatible items
                bool isSafe = true;                  // 表明能否安全运输

                for (j = 0; j < len; j++)
                {
                    if (scanf("%d", &goods[j]) == 1)
                    {
                        if (isSafe)
                        {
                            if (table[goods[j]].size())
                            {
                                listedItem.emplace_back(goods[j]);
                                quantity = listedItem.size();
                                if (quantity > 1)
                                {
                                    //遍历存在于不相容清单中的待运输物品
                                    for (auto item : listedItem)
                                    {
                                        //如果listeItem中存在与当前物品中不相容的物品 则无法安全运输 将isSafe置为false
                                        if (find(table[goods[j]].begin(), table[goods[j]].end(), item) != table[goods[j]].end())
                                        {
                                            isSafe ^= 1;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }

                if (isSafe)
                {
                    printf("Yes\n");
                }
                else
                {
                    printf("No\n");
                }
            }
        }
    }
    return 0;
}
