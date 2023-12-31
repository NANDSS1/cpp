/*给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。返回 需要移除区间的最小数量，使剩余区间互不重叠 。

 

示例 1:

输入: intervals = [[1,2],[2,3],[3,4],[1,3]]
输出: 1
解释: 移除 [1,3] 后，剩下的区间没有重叠。
示例 2:

输入: intervals = [ [1,2], [1,2], [1,2] ]
输出: 2
解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
示例 3:

输入: intervals = [ [1,2], [2,3] ]
输出: 0
解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool cmp(const vector<int>& a,const vector<int>& b){//这里传入的是元素，指定的元素的规则
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>> ans;
        for( int i = 1;i < intervals.size();i++){
            if(intervals[i][0] > intervals[i-1][1]) ans.emplace_back(intervals[i-1]);//添加答案
            else {
                intervals[i][0] = min(intervals[i-1][0],intervals[i][0]);
                intervals[i][1] = max(intervals[i-1][1],intervals[i][1]);//取并集 右侧区间要取max
            }
        }
        ans.emplace_back(intervals.back());

        return ans;
    }
};

