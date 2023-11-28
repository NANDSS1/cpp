//
// Created by 11751 on 2023/11/20.
//

/*hashmap*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> hashmap;
        int n = numbers.size();
        for(int i = 0;i < n;i++){
            //数组的值作为key，数组的索引作为value
            //在数组里面，数组的值是唯一的，对应的索引也就是唯一的
            if(!hashmap.count(target-numbers[i])) hashmap[numbers[i]] = i;
            else return {hashmap[target-numbers[i]]+1,i+1};

        }

        return {};
    }
};
/*
int main(){
    vector<int> demo = {2,7,11,15};
    int target = 9;
    Solution s = Solution();
    vector<int> ans = s.twoSum(demo,target);
    cout<<ans[0]<<ans[1]<<endl;
}
*/
