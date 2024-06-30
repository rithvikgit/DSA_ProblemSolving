// Encoder
// Given an array of words, devise a method to encode these words into a single reference string and an array of indices in such a way that:

// The length of the array of words equals the length of the array of indices.
// The reference string ends with the '#' character.
// For each index indices[i], the substring of the reference string starting at indices[i] and ending before the next '#' character equals words[i].
// Your task is to return the length of the shortest possible reference string that can be generated to validly encode the given array of words.

// Input Format:

// The input consists of an array of words words, where each word consists only of lowercase letters.
// Output Format:

// Return the length of the shortest reference string s possible of any valid encoding of words.
// Example 1
// Input
// words = ["time", "me", "bell"]
// Output
// `10`
// Explanation:
// A valid encoding would be s = "time#bell#" and indices = [0, 2, 5].
// words[0] = "time", the substring of s starting from indices[0] = 0 to the next '#' is underlined in "time#bell#"
// words[1] = "me", the substring of s starting from indices[1] = 2 to the next '#' is underlined in "time#bell#"
// words[2] = "bell", the substring of s starting from indices[2] = 5 to the next '#' is underlined in "time#bell#"
// Example 2
// Input
// ` words = ["t"]`
// Output
// `2`
// Explanation:
// A valid encoding would be s = "t#" and indices = [0].

// Constraints:
// 1 <= words.length <= 2000
// 1 <= words[i].length <= 7
// words[i] consists of only lowercase letters.


#include<bits/stdc++.h>
class Solution {
public:
    int minimumLengthEncoding(std::vector<std::string>& W) {
      // write your code here
      std::unordered_set<std::string> s(W.begin(),W.end());
        for(auto x:s){
            for(int i=1;i<x.size();i++){
                s.erase(x.substr(i));
            }
        }
        int ans = 0;
        for(auto x:s){
            ans+=1+x.size();
        }
        return ans;
    }
};
