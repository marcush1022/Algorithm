/*
Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve 
this problem.
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        int n=k%nums.size();
        if(n==0)
            return ;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+n);
        reverse(nums.begin()+n, nums.end());
    }
};
