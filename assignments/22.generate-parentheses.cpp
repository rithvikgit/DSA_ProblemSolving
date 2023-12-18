class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        fun(ans,n,0,0,"");
        return ans;       
    }
    void fun(vector<string>&ans,int n, int open, int close, string cur){
        if(cur.size()==n*2){
            ans.push_back(cur);
            return;
        }

        if(open<n){
            fun(ans,n,open+1,close,cur+"(");
        }
        if(close<open){
            fun(ans,n,open,close+1,cur+")");
        }
    }
};