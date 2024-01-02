/*给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

进阶：

如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？

致谢：

特别感谢 @pbrother 添加此问题并且创建所有测试用例。

 

示例 1：

输入：s = "abc", t = "ahbgdc"
输出：true
示例 2：

输入：s = "axc", t = "ahbgdc"
输出：false*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        //相对顺序要保持一致
        //先遍历长的字符串，找到一样的再移动短的字符串
        vector<bool> dp(t.size()+1,false);
        dp[0] = true;
        //设置t.size()+1个比较好操作
        for(const auto& c:t){
            if(c == s[i-1]&&i<s.size()+1){
                dp[i] = dp[i-1];
                i++;
                //这样就保持了一种相对顺序，后面的依赖前面
            }else if(i>=s.size()+1) break;
    }
    return dp.back();
};