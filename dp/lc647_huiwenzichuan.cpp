/*给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。

回文字符串 是正着读和倒过来读一样的字符串。

子字符串 是字符串中的由连续字符组成的一个序列。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

 

示例 1：

输入：s = "abc"
输出：3
解释：三个回文子串: "a", "b", "c"
示例 2：

输入：s = "aaa"
输出：6
解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
        int ans = 0;
        for(int i = 0;i < s.size();i++){
            dp[i][i] = true;
            ans++;
        }
        //遍历字符串的长度
        for(int len = 2;len <= s.size();len++){
            for(int i = 0;(i+len-1)<s.size();i++){
                //判断条件，长度为2和长度为3
                int j = i+len-1;
                if(s[i] == s[j]){
                    if(len == 2){
                        dp[i][j] = true;
                        ans++;
                    }else if((len >= 3) && (dp[i+1][j-1] == true)){
                        dp[i][j] = true;
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};