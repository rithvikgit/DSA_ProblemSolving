// Fractional knapsack
// Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack. Note: Unlike 0/1 knapsack, you are allowed to break the item.

// Example 1
// Input
// N = 3, W = 50
// values = [60,100,120]
// weight = [10,20,30]
// Output
// 240.00
// Explanation:
// Initial W = 50. take item 1 with weight 10 and value 60 so W is now 50 - 10 = 40. take item 2 with weight 20 and value 100 so W is now 40 - 20 = 20. Now, we cannot take item 3 completely so we will just take W = 20 amount of it and the value we will get out of it is 80 and W becomes 20 - 20 = 0. so total value is 60 + 100 + 80 = 240. So,Total maximum value of item we can have is 240.00 from the given capacity of sack.

// Example 2
// Input
// N = 2, W = 50
// values = [60,100]
// weight = [10,20]
// Output
// 160.00
// Explanation:
// Total maximum value of item we can have is 160.00 from the given capacity of sack.

// Constraints:
// 1 <= Items.length <= 10000
// 1 <= Items.value , Items.weight <= 100000


class Solution {
public:
    double fractionalKnapsack(int N, int W, vector<int>& values, vector<int>& weight) {

      vector<pair<double,int>> valuePerWeigth(N);

      for(int i=0;i<N;i++){
        valuePerWeigth[i]=make_pair((double)values[i]/weight[i],i);
      }

      //Desc sort
      sort(valuePerWeigth.rbegin(),valuePerWeigth.rend());

      double max = 0.0;

      for(auto& a :valuePerWeigth){
        int i = a.second;
        if(W==0){
          break;
        }else if(weight[i]<=W){
          max += values[i];
          W-=weight[i];
        }else{
          max+=(values[i]/(double)weight[i])*W;
          W=0;
        }
      }

      return max;

        

 }
};