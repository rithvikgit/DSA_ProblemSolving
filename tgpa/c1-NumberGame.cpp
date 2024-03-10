// Number Game
// Bholu and Dholu play a game. Initially each player receives one fixed positive integer that doesn't change throughout the game. Bholu receives number a and Dholu receives number b. They also have a heap of n stones. The players take turns to make a move and Bholu starts. During a move a player should take from the heap the number of stones equal to the greatest common divisor of the fixed number he has received and the number of stones left in the heap. A player loses when he cannot take the required number of stones (i. e. the heap has strictly less stones left than one needs to take).

// Your task is to determine who wins the game.

// Input The only string contains space-separated integers a, b and n (1 ≤ a, b, n ≤ 100) — the fixed numbers Bholu and Dholu have received correspondingly and the initial number of stones in the pile.

// Output If Bholu wins, print "0" (without the quotes), otherwise print "1" (without the quotes).



class Solution {
public:

    int gcd(int a, int b){
      if(b==0){
        return a;
      }
      return gcd(b,a%b);
    }

    int solve(long long a, long long b, long long n) {

      bool Bholu = true;

      while(n>0){
        if(Bholu){
          int gcd_value = gcd(a,n);
          n = n - gcd_value;
        }else{
          int gcd_value = gcd(b,n);
          n = n - gcd_value;
        }
        Bholu = !Bholu;
      }

      if(Bholu){
        return 1;
      }else{
        return 0;
      }
    }
};
