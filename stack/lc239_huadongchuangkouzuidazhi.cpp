//
// Created by 11751 on 2023/12/3.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> que;//可以用firsr和second来索引元素
        vector<int> ans;
        for(int i = 0;i < k;i++){
            que.emplace(nums[i],i);
        }//加入前k个元素
        ans.push_back(que.top().first);
        for(int i = k;i < nums.size();i++){
            que.emplace(nums[i],i);
            //i维护的是滑动窗口尾部
            //开始弹出元素,下面的while保证top元素在[i,i+k-1]范围内
            while(que.top().second < (i-k+1)){//不会误弹
                que.pop();
            }
            ans.push_back(que.top().first);
        }

        return ans;
    }
};