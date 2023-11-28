//
// Created by 11751 on 2023/11/28.
//
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int i = 0;//左指针
        int len = INT_MAX;
        //时间复杂度o(n)，一个元素进一次出一个，共n个元素
        for(int j = 0;j < nums.size();j++){//右指针
            sum += nums[j];
            while(sum >= target){//循环
                //如果越界了
                //右边不能再加了
                //只能去掉左边的
                len = min(len,j-i+1);
                sum -= nums[i];
                i++;
            }
        }

        return len==INT_MAX ? 0:len;
    }
};

/*
int main(){
    vector<int> nums = {1,2,3,4,5};
    int target = 11;
    Solution s = Solution();
    int ans = s.minSubArrayLen(target,nums);
    cout<<ans<<endl;
}
 */