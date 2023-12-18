class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {

        string morse[] ={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        set<string> uniqueMorseCode;
        for(int i=0; i<words.size();i++){
            string s;
            for(int j: words[i]){
                s+=morse[j-'a'];
            }
            uniqueMorseCode.insert(s);
        }
        return uniqueMorseCode.size();
        

        
    }
};