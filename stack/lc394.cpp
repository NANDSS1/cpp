#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isDigit(char c){
        if(c-'0' >= 0 && c-'0' <= 9){
            return true;
        }
        return false;
    }

    string decodeString(string s) {
        stack<char> stChar;
        stack<int> stNum;
        string res = "";
        int num1 = 0;

        for (const auto& c : s) {
            if (isDigit(c)) {
                num1 = num1 * 10 + (c - '0');
            } else if (c != ']' ) {
                stChar.push(c);
                if(c == '['){
                    stNum.push(num1);
                    num1 = 0;
                }

            } else if(c == ']'){

                string temp = "";
                while (!stChar.empty() && stChar.top() != '[') {
                    temp = stChar.top() + temp;
                    stChar.pop();
                }

                if (!stChar.empty()) {
                    stChar.pop();  // 弹出左括号
                }

                int num = stNum.top();
                stNum.pop();
                string repeatedStr = "";
                for (int i = 0; i < num; ++i) {
                    repeatedStr += temp;
                }

                for (const auto& ch : repeatedStr) {
                    stChar.push(ch);
                }
            }
        }

        while (!stChar.empty()) {
            res = stChar.top() + res;
            stChar.pop();
        }

        return res;
    }
};

/*
int main() {
    string s = "100[stack]";
    Solution solution;
    string ans = solution.decodeString(s);
    cout << ans;

    return 0;
}
*/