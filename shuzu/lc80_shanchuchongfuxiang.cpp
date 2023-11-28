//
// Created by 11751 on 2023/11/22.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    /*
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        sort(nums.begin(),nums.end());
        int num = 1;//重复数,默认重复数为一
        for(int i = 0;i < length;i++){
            if(i > 0 && nums[i] == nums[i-1]){
                num += 1;
            }
            else if(nums[i] != nums[i-1]){
                if(num >=3){
                    for(int j = i-num+1;j < length;j++){
                        nums.erase(nums.begin()+j);
                    }
                    length -= (num-2);
                }
                num = 1;
            }

            for(const auto& n:nums){
                cout<<n<<" ";
            }
            cout<<endl;
        }
        return length;
    }
     */

    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n;
        }
        int slow = 2, fast = 2;
        while (fast < n) {
            if (nums[slow - 2] != nums[fast]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }


};


int main(){
    vector<int> nums = {1,1,1,2,2,3};
    Solution s = Solution();
    int ans = s.removeDuplicates(nums);
    cout<<ans<<endl;

}