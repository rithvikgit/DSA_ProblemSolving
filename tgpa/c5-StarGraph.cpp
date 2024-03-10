// Star graph
// There is an undirected star graph consisting of n nodes labeled from 1 to n. A star graph is a graph where there is one center node and exactly n - 1 edges that connect the center node with every other node.

// You are given a 2D integer array edges where each edges[i] = [ui, vi] indicates that there is an edge between the nodes ui and vi. Return the center of the given star graph.

// Example 1
// image

// Input
// edges = [[1,2],[2,3],[4,2]]
// Output
// 2
// Explanation:
// As shown in the figure above, node 2 is connected to every other node, so 2 is the center.

// Example 2
// Input
// edges = [[1,2],[5,1],[1,3],[1,4]]
// Output
// 1
// Constraints:
// 3 <= n <= 10^5
// edges.length == n - 1
// edges[i].length == 2
// 1 <= u, v <= n
// u != v
// The given edges represent a valid star graph.

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) { 

      int n = 0;
        for(int i=0;i<edges.size();i++){
            n = max(n,max(edges[i][0],edges[i][1]));
        }
        vector<int>indegree(n+1);

        for(int i=0;i<edges.size();i++){
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
        }

        int ans=0;
        for(int i=0;i<indegree.size();i++){
           if(indegree[i]==n-1){
               ans=i;
               break;
           }
        }
        return ans;

 }
};