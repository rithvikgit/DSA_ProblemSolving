class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int>counts;
        unordered_map<char, int>countTargets;

        for(char c:s){
            counts[c]++;
        }

        for(char c:target){
            countTargets[c]++;
        }
        int minCount = INT_MAX;

        for(auto& pair : countTargets){
            char c = pair.first;
            int requiredCount =  pair.second;

            if(counts.find(c)==counts.end()){
                return 0;
            }
            minCount = min(minCount, counts[c]/requiredCount);
        }
        return minCount;

    }
};