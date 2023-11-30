//
// Created by 11751 on 2023/11/30.
//
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        int sum = 0;
        unordered_set<int> hashset;
        while(true){
            //cout<<n<<endl;
            int sum = 0;
            while(n != 0){
                sum += (n%10)*(n%10);
                n = n/10;
            }
            if(sum == 1) return true;
            n = sum;
            if(!hashset.count(sum)) hashset.insert(sum);
            else break;
        }

        return false;

    }
};
/*
int main(){
    Solution s = Solution();
    bool ans = s.isHappy(19);
    cout<<ans<<endl;
}
 */