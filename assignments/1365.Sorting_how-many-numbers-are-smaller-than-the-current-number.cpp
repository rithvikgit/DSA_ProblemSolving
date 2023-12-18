class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>ans(nums.size());
        //init frequency array
        int temp[101]={0};

        //storing the frequency of each element
        for(auto i:nums){
            temp[i]++;
        }

        //storing the runnig sum
        for(int i=1;i<101;i++){
            temp[i] += temp[i-1];
        }

        //store the ans
        for(int i=0; i<nums.size();i++){
            if(nums[i]==0) ans[i]=0;
            else ans[i] = temp[nums[i]-1];
        }
        return ans;
        
    }
};