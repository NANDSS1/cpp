//
// Created by 11751 on 2023/12/3.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    class mycomparison {
        //小顶堆
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //hashmap和小顶堆
        unordered_map<int,int> hashmap;
        priority_queue<pair<int,int>,vector<pair<int,int>>, mycomparison> que;
        for(int i = 0;i < nums.size();i++){
            hashmap[nums[i]]++;
        }
        for(const auto& m:hashmap){
            if(que.size() < k) que.push(m);
            else{
                if(m.second > que.top().second){
                    que.pop();
                    que.push(m);
                }
            }
        }

        vector<int> ans;
        while(!que.empty()){
            ans.push_back(que.top().first);
            que.pop();
        }

        return ans;

    }
};
