class Solution {
public:
    int findNumbers(vector<int>& nums) {

        int ans=0,digit=0;
        for(int a : nums){
            digit=0;
            while(a>0){
                a=a/10;
                digit++;
            }
            if(digit%2==0){
                ans++;
            }
        }
        return ans;
    }
};