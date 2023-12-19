#include<bits/stdc++.h>
using namespace std;

/*
class Solution{
private:
    vector<vector<int>> result;
    vector<int> path;
public:
    void backtracking(int index,vector<int>& nums,vector<bool>& used){
        result.push_back(path);
        for(int i = index;i < nums.size();i++){
            // used[i - 1] == true，说明同一树枝candidates[i - 1]使用过
            // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
            if(i > index && nums[i] == nums[i-1] && used[i-1] == false){
                //从第2个元素开始判断，如果发现和前面的元素相等，而且前面的元素 树层用过了就跳过
                continue;
            }
            //经过上面的判断之后就ok
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(i+1,nums,used);
            used[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums){
        vector<bool> used(nums.size(),false);
        
        //排序是一定不能少的,要把一样的元素靠在一起
        sort(nums.begin(),nums.end());

        backtracking(0,nums,used);

        return result;

    }
};
*/

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int index,vector<int>& nums){
        result.push_back(path);
        for(int i = index;i < nums.size();i++){
            if(i > index && nums[i] == nums[i-1]) continue;//当前树层后面重复的元素都不取 
            path.push_back(nums[i]);
            backtracking(i+1,nums);
            path.pop_back();
        }
        
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

    }