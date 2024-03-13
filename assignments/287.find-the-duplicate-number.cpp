class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int temp=-1;
        for(int i = 0; i<nums.size() ; i++){
            if(nums[i]==nums[i+1]){
                temp = nums[i];
                break;
            }
        }
        return temp;
    }
};