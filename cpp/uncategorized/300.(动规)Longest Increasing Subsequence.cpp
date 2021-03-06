/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. 
Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?

在i下标前面的所有nums值当中，找到所有比nums[i]小的，且dp值最大的那个值，然后加1
然后最长递增子序列的长度为所有dp[i]当中最大的值
*/

class AscentSequence {
public:
    int findLongest(vector<int> nums, int n) {
        // write code here
        int len=nums.size();
        int dp[len];
        int maxLen=0;
        dp[0]=1;
        for(int i=1; i<len; i++)
        {
            int tmp=0;
            for(int j=i-1; j>=0; j--)
            {
                if(nums[j]<nums[i])
                    tmp=max(tmp, dp[j]);
            }
            dp[i]=tmp+1;
            maxLen=max(maxLen, dp[i]);
        }
        return maxLen;
    }
};
