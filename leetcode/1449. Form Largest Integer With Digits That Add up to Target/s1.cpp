// OJ: https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/
// Author: github.com/lzl124631x
// Time: O(T)
// Space: O(T)
class Solution {
    bool isGreaterThan(string &a, string &b) {
        if (a.size() != b.size()) return a.size() > b.size();
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == b[i]) continue;
            return a[i] > b[i];
        }
        return false;
    }
public:
    string largestNumber(vector<int>& A, int T) {
        int N = A.size();
        vector<vector<string>> dp(N + 1, vector<string>(T + 1, "0"));
        for (int i = 0; i <= N; ++i) dp[i][0] = "";
        for (int i = 0; i < N; ++i) {
            for (int c = 1; c <= T; ++c) {
                dp[i + 1][c] = dp[i][c];
                if (c < A[i] || dp[i + 1][c - A[i]] == "0") continue;
                auto s = string(1, '1' + i) + dp[i + 1][c - A[i]];
                if (isGreaterThan(s, dp[i + 1][c])) dp[i + 1][c] = s;
            }
        }
        return dp[N][T];
    }
};