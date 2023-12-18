class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>ans;
        for(int i=left;i<=right;i++){
            bool selfDivide = true;
            int a = i;
            while(a){
                if(a%10==0|| i%(a%10)!=0){
                    selfDivide=false;
                    break;
                }
                a=a/10;
            }
            if(selfDivide){
                ans.push_back(i);
            }
        }
        return ans;
    }
};