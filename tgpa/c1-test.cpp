// RBI wants to introduce currency of new denominations,so for this, the Governor conducts a poll about the among N banks. Governor imposed a restriction on the denomination of the currency that is the denomination can be in the range of ==[1,N]==.Votes of all the banks have been stored in the votes array and the RBI will release currency of only those denominations which have got more than 1 vote. So you have been provided with the votes array and you need to return the array which will contain the denominations of the currency which is going to be released by the RBI sorted in increasing order. If no denominations got more than 1 vote then simply return an empty array.

// Note: Can you wirte an algorithm that runs in O(N) Time complexity and O(1) space complexity if we exclude the space used by answer array.

// Example 1
// Input
// votes = [4,3,2,1,2,1]
// Output
// [1,2]
// Explanation:
// currency of denominations 1 and 2 got more than 1 votes so they are going to be released by the RBI

// Example 2
// Input
//  arr = [3,4,3,1]
// Output
// [3]
// Explanation:
// only currency of denomination 3 got more than 1 votes.

// Constraints:
// 1 <= n= 10000
// 1 <= arr[i] <= N


class Solution
{
public:
	vector<int> findCurrency(vector<int> &votes) {

      vector<int>denominations;

      if(votes.empty()){
        return {};
      }

      unordered_map<int,int> freq;
      int maxFreq = 0;
      int n = votes.size();

      for(int i=0;i<n;++i){
        freq[votes[i]]++;
        maxFreq = max(maxFreq,freq[votes[i]]);
      }

      for(auto& i:freq){
        if(i.second == maxFreq){
          denominations.push_back(i.first);
        }
      }

      if(maxFreq==0){
        return {};
      }else{
        return denominations;
      }

      // return denominations;

	}
};


