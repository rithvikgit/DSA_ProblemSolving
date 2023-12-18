class Solution {
public:
    bool judgeCircle(string moves) {
        int a=0,b=0;

        for(int i=0;i<moves.length();i++){
            if(moves.at(i)=='U') a++;
            else if(moves.at(i)=='D') a--;
            else if(moves.at(i)=='R') b++;
            else b--;
        }

        if(a==0 && b==0)return true;
        return false;
        
    }
};