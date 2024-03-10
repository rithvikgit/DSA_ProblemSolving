// Remove K digits
// Tuntun is given a task on strings. She is given a string str of digits and a integer k she has to remove k digits from the string. string str represents a non- negative integer. Print the smallest possible integer after removing k digits from str. Help her to do so.

// Input Format:
// first line contains a string.
// second line contains a integer k
// Output:
// return nothing, print the smallest possible integer after removing k digits from string.
// Constraints:
// 1<=k<= str.length<= 100000
// str contains of only digits
// Sample Input1
// 1432219
// 3
// Sample Output1
// 1219

// Explanation
// Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

class Solution {
public:
    string removeKdigits(string num, int k) {
      //Write your code here;
      if(num.length()==k){
        return "0";
      }

      string ans;
      vector<char> s;

      for(int i=0;i<num.length();i++){
        while(k>0 && !s.empty() && s.back()>num[i]){
          s.pop_back();
          --k;
        }
        s.push_back(num[i]);
      }

      while(k-- > 0){
        s.pop_back();
      }

      for(const char c:s){
        if(c=='0'&& ans.empty()){continue;}
        ans+=c;        
      }

      if(ans.empty()){
        return "0";
      }else{
        return ans;
      }
       