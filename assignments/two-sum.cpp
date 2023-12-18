class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> funHm; //using HashMap
        int n = nums.size();
        for(int i=0;i<n;i++){
            int num = nums[i];
            int moreNeeded = target - num;
            if(funHm.find(moreNeeded)!=funHm.end()){
                return{funHm[moreNeeded],i};
            }
            funHm[num]=i;
        }
        return{-1,-1};
    }
};

//time Complexity:- o(n*logn)
//space Complexity:-o(n)