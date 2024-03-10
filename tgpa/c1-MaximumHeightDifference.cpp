// Minimum height difference
// n friends stand in a circle. For each friend his height ai is known. A reconnaissance unit can be made of such two neighbouring friends, whose heights difference is minimal, i.e. |ai - aj| is minimal. So each of them will be less noticeable with the other. Output the minimal difference.

// Input The first line contains integer n (2 ≤ n ≤ 100) — amount of friends. Then follow the heights of the friends in their order in the circle — n space-separated integers a1, a2, ..., an (1 ≤ ai ≤ 1000). The friends heights are given in clockwise or counterclockwise direction.

// Output Output one integers — The minimal difference.



class Solution {
public:
    int minDifference(vector<int>& nums) {
      int n =  nums.size();

      int minDiff = INT_MAX;
      
      for(int i =0; i<n ; i++){
        int diff = abs(nums[i]-nums[i+1]);
        minDiff = min(minDiff , diff);
      }
      int diff = abs(nums[n-1]-nums[0]);
      minDiff = min(minDiff,diff);

      return minDiff;
    }
};





