//
// Created by 11751 on 2023/12/2.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //快慢指针
        int slow = 0;
        int fast = 0;
        while(fast <= nums.size()-1){
            if(nums[fast] != val){
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }

        return slow;

    }
};
/*
int main(){
    vector<int> nums;
    int num;
    while(true){
        cin>>num;
        nums.push_back(num);
        if(cin.get() == '\n') break;
    }
    //cout<<nums.size();
    int val;
    cin>>val;
    Solution s;
    int size = s.removeElement(nums,val);
    //cout<<size;
    for(int i = 0;i < size;i++){
        cout<<nums[i]<<" ";
    }
}

 */