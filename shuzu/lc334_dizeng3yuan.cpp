//
//
// Created by 11751 on 2023/11/23.
//
/*https://leetcode.cn/problems/increasing-triplet-subsequence/description/
 * 334. 递增的三元子序列
中等
784
相关企业
给你一个整数数组 nums ，判断这个数组中是否存在长度为 3 的递增子序列。

如果存在这样的三元组下标 (i, j, k) 且满足 i < j < k ，使得 nums[i] < nums[j] < nums[k] ，返回 true ；否则，返回 false 。*/
#include<bits/stdc++.h>
using namespace std;
/*
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        //以目标元素为中心在左边找一个小的，右边找一个大的
        int n = nums.size();
        bool minFlag = false;
        bool maxFlag = false;
        for(int i = 1;i < n-1;i++){
            for(int j = 0;j < i;j++){
                if(nums[j] < nums[i]){
                    minFlag = true;
                    break;
                }
            }

            for(int j = i+1;j < n;j++){
                if(nums[j] > nums[i]){
                    maxFlag = true;
                    break;
                }
            }

            if((minFlag&&maxFlag) == true) return true;
            minFlag = false;
            maxFlag = false;//重置初始条件
        }

        return false;
    }
};//这种方法超时
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> minLeft(n,0);//记录i索引结尾（包括i索引）之前的最小元素
        minLeft[0] = nums[0];
        for(int i = 1;i < n;i++){
            minLeft[i] = min(minLeft[i-1],nums[i]);
        }
        vector<int> maxRight(n,0);
        maxRight[n-1] = nums[n-1];
        for(int i = n-2;i >= 0;i--){
            maxRight[i] = max(maxRight[i+1],nums[i]);
        }

        //有贪心策略在，一个元素左边最小的元素都比他大，右边最大的元素都比他小，那么以这个元素为中心就无法构成递增子序列

        for(int i = 1;i < n-1;i++){
            if((minLeft[i-1] < nums[i]) && (maxRight[i+1] > nums[i])) return true;//贪心策略，比左边最小的大就行了，比右边最大的小就行了。
        }

        return false;
    }
};
/*
int main(){
    vector<int> nums ={2,1,5,0,4,6};
    Solution s = Solution();
    bool f = s.increasingTriplet(nums);

    cout<<f<<endl;

}
 */
