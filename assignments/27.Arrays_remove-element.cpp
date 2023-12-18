class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res= 1; 
        for(int i=1; i<nums.size(); i++){
            if (nums[i]!= nums[res-1]){
                nums[res]=nums[i];
                res++;
            }
        }
        if(nums.empty()){
                return NULL;
        }else
        return res;        
    }
};