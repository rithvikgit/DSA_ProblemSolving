class Solution {
private:
    vector<string>ans;
    string key[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())return ans;
        recursion(digits,"",0);
        return ans;
    }
    void recursion(string s, string cur, int index){
        if(index== s.length()){ 
        ans.push_back(cur);
        }else{
            string letters = key[s[index]-'0'];
            for(const char c: letters){
                recursion(s, cur+c, index+1);
            }
        }
    }
    
};