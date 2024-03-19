// Count unique subsequences
// Given a string s, your task is to calculate the number of distinct non-empty subsequences of s. Due to the potential size of the answer, return it modulo 1000000007 (1e9 + 7).

// A subsequence of a string is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. For example, "ace" is a subsequence of "abcde" while "aec" is not.

// Input Format:

// A single line containing the string s.
// Output Format:

// An integer representing the number of distinct non-empty subsequences of smodulo1000000007.`
// Sample Input 1:

// abc
// Sample Output 1:

// 7
// Explanation:
// The seven distinct subsequences are "a", "b", "c", "ab", "ac", "bc", and "abc".

// Sample Input 2:

// aba
// Sample Output 2:

// 6
// Explanation:
// The six distinct subsequences are "a", "b", "ab", "aa", "ba", and "aba".

// Constraints:

// 1 <= s.length <= 2000
// s consists of lowercase English letters.

//leetcode 940

class Solution {
public:
int MOD = 1e9 + 7;
const int MAX_CHAR = 256;
    int distinctSubseqII(string s) {
    
    int n = s.size();
        vector<int> dp(n + 1, 1), last(26, -1);

        dp[0] = 1;
        for(int i = 0; i < n; i ++){
            dp[i + 1] = 2 * dp[i] % MOD;
            if(last[s[i] - 'a'] != -1){
                dp[i + 1] -= dp[last[s[i] - 'a']];
                if(dp[i + 1] < 0)
                    dp[i + 1] += MOD;
            }
            last[s[i] - 'a'] = i;
        }
        return dp[n] - 1 < 0 ? MOD - 1 : dp[n] - 1;

        
    }
};