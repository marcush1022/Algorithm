/*
Implement next permutation, which rearranges numbers into the lexicographically 
next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible 
order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding 
outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

打印字典序的下一个排列

如果从第n个数字到最后都是递减的并且第n-1个数字小于第n个，说明从第n个数字开始的这段序列
是字典序组合的最后一个，在下一个组合中他们要倒序变为字典序第一个，然后从这段序列中找出
第一个大于第n-1个数字的数和第n-1个数字交换就可以了。比如，当前组合为12431，可以看
出431是递减的，同时4>2，这样我们把431倒序，组合就变为12134，然后从134中找出第一个大于
2的数字和2交换，这样就得到了下一个组合13124。对于完全递减的组合例如4321在倒序之后就可
以了.

3种情况:
12431-->12134-->13124
4321-->1234
1234-->1243
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len=nums.size();
        if(len==0)
            return ;
        int i=len-1;
        while(i>0 && nums[i-1]>=nums[i])
            --i;
        reverse(nums.begin()+i, nums.end());
        if(i==0)
            return ;
        for(int j=i; j<len; j++)
        {
            cout<<j;
            if(nums[j]>nums[i-1])
            { 
                swap(nums[j], nums[i-1]);
                break;
            }
        }
    }
};
