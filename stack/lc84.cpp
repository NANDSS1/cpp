//
// Created by 11751 on 2023/11/17.
//
#include <bits/stdc++.h>
using namespace std;
/*暴力*/
/*
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = INT_MIN;
        for(int i = 0;i < n;i++){
            int minHeight = INT_MAX;
            for(int j = i;j < n;j++){
                minHeight = min(minHeight,heights[j]);
                ans = max(ans,(j-i+1)*minHeight);
            }
        }

        return ans;


    }
};
*/


/*空间换时间*/
/*单调栈*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = INT_MIN;
        stack<int> st;
        for(int i = 0;i < n;i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                //单调栈可以维护一段区间的最小值？
                int cur = st.top();
                st.pop();

            }
        }

        return ans;


    }
};

/*
int main(){
    vector<int> heights ={2,1,5,6,2,3};
    Solution s = Solution();
    int ans = s.largestRectangleArea(heights);

    cout<<ans;

}
 */