class Solution {
    public:
    int findMaximumXOR(vector<int>& nums) {
        const int maxNum = ranges::max(nums);
        if (maxNum == 0)
        return 0;
        const int maxBit = static_cast<int>(log2(maxNum));
        int ans = 0;
        int prefixMask = 0; 
        for (int i = maxBit; i >= 0; --i) {
        prefixMask |= 1 << i;
        unordered_set<int> prefixes;
        
        for (const int num : nums)
            prefixes.insert(num & prefixMask);
        
        const int candidate = ans | 1 << i;
        for (const int prefix : prefixes)
            if (prefixes.count(prefix ^ candidate)) {
            ans = candidate;
            break;
            }
        }

        return ans;
    }
};  