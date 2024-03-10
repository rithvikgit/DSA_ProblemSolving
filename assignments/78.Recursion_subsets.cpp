class Solution {
public:
    vector<vector<int>>ans;
    void func(vector<int> nums, vector<int> temp, int i){
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        func(nums,temp,i+1);
        temp.pop_back();
        func(nums,temp,i+1);
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        func(nums,temp,0);
        return ans;
    }
};