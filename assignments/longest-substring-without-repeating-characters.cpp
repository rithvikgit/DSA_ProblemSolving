class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> fun(256,-1);
        int maxLen = 0, start = -1;
        for(int i=0;i<s.size();i++){
            if(fun[s[i]]>start){
                start = fun[s[i]];
            }
            fun[s[i]]=i;
            maxLen=max(maxLen,i-start);
        }
        return maxLen;
    }
};