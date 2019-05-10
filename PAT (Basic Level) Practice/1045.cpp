//对于每一个主元而言,如果其前面的主元存在 则其前面主元的值必定小于该主元的值 因此每一个主元的值在数组中是单调递增的
// isPivot记录nums数组中的每一个元素是否是主元 0代表该元素是主元 1代表不是主元
// 使用一个变量val 使其始终记录一个元素左侧的元素的最大值或者右侧元素的最小值
// 输入元素的过程中 先将val初始化化为数组的第一个元素
// 在后续的输入过程中 维持val为当前遍历元素的左侧所有元素的最大值 
// 只要每一个元素的值大于val 该元素就符合成为主元的第一个条件
// 如果输入的元素不大于val 则该元素必定不为主元 将相应的isPivot中的元素置1
// 如果输入的元素大于val 则将val更新为该元素的值
// 然后再将数组的最后一个元素的值赋给val 
// 然后从倒数第二个元素直到第一个元素进行遍历 维持val为当前遍历元素的右侧所有元素的最小值
// 只要每一个元素的值小于val 该元素就符合成为主元的第二个条件
// 如果该元素的值不小于val 如果该元素未被标记为不是主元 则对其进行标记 将相应的isPivot中的元素置1
// 最终遍历数组中的每一个元素 根据isPivot中每个元素的值确定该数组元素是否可以作为主元

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    if(scanf("%d", &n) == 1)
    {
        int i, nums[n], isPivot[n] = {0}, val = INT_MIN;
        int cnt = 0, pivotNums = 0;         //pivotNums记录主元的个数

        for(i = 0; i < n; i++)
        {
            if(scanf("%d", nums + i) == 1)
            {
                if(!i)                      //初始化val值为第一个元素的值
                {
                    val = nums[0];
                }
                else
                {
                    if(nums[i] <= val)      //如果该元素的值不大于val 则其必定不为主元 
                    {
                        isPivot[i] ^= 1;    //将相应的数组isPivot中的元素置1 将该元素进行标记
                    }

                    else
                    {
                        val = nums[i];      //否则, 更新val 维持其为当前遍历元素左侧所有元素的最大值
                    }
                }

            }
        }

        for(i = n - 1, val = nums[n - 1]; i >= 0; i--)
        {
            if(i != n - 1)
            {
                if(nums[i] >= val)          //如果当前遍历元素的值不小于val 其必定不为主元
                {
                    if(!isPivot[i])         //该元素之前未被标记不是主元 则将其标记
                    {
                        isPivot[i] ^= 1;
                    }
                }
                else                        //否则更新val的值 维持val为当前遍历元素的右侧所有元素的最小值
                {
                    val = nums[i];
                }

            }
            if(!isPivot[i])                 //如果该元素是主元
            {               
                pivotNums++;                // 记录主元个数的变量pivotNums的值加1
            }
        }

        printf("%d\n", pivotNums);
        for(i = 0; i < n && cnt != pivotNums; i++)
        {
            if(!isPivot[i])                 // 该元素为主元 则将该元素输出
            {
                if(cnt)
                {
                    printf(" ");
                }
                printf("%d", nums[i]);
                cnt++;
            }
        }
        printf("\n");
    }
}
