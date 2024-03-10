class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> mp(nums.begin(), nums.end());
        int n = nums.size()+1;
        for(int i=0;i<n;i++){
            if(mp.find(i)==mp.end()){
             return i;
            }
        }
        return -1;
    }
};