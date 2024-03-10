// Dholu and Bholu are great fans of odd numbers, that's why they want to divide the chocolate in such a way that each of the two parts weighs odd number of grams, at the same time it is not obligatory that the parts are equal. The boys are extremely excited to start eating their chocolates as soon as possible, that's why you should help them and find out, if they can divide the chocolate in the way they want. For sure, each of them should get a part of positive weight.

// Input
// The first (and the only) input line contains integer number c (1 ≤ c ≤ 100) — the weight of the chocolate bought by the boys.

// Output
// Print "YES", if the boys can divide the chocolate into two parts, each of them weighing odd number of grams; and "NO" in the opposite case ***CASE SENSITIVE ***


class Solution {
public:
    void canDivideChocolate(int n) {
      if(n%2!=0){
        cout<<"NO";
      }else{
        cout<<"YES";
      }
      
    }
};