class Solution {
public:
    string convert(string s, int numRows) {
        vector<string>ans(numRows);
        if(numRows == 1){
            return s;
        }

        bool flag = false;
        int i=0;
        for(auto ch : s){
            ans[i]+=ch;
            if( i == 0 || i == numRows-i){
                flag = !flag;
            }if(flag==true){
                i++;
            }else{
                i--;
            }
            
        }

        string zigzag = "";
        for(auto str:ans){
            zigzag+=str;
        }
        return zigzag;
    }
};