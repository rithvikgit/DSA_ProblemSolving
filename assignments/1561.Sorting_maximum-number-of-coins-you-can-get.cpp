class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        int a=piles.size()-1,m=piles.size()-2,b=0;
        int result=0;

        while(m>b){
            result+=piles[m];
            b++;
            m-=2;
        }

        return result;

    }
};