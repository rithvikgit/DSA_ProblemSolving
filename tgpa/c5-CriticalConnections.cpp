// Critical Connection
// There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

// A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

// Return all critical connections in the network in any order.

// Example 1
// Input
// n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
// Output
// [[1,3]]
// Explanation:
// [[3,1]] is also accepted.

// Example 2
// Input
//  n = 2, connections = [[0,1]]
// Output
// [[0,1]]
// Constraints:
// 2 <= n <= 105
// n - 1 <= connections.length <= 10^5
// 0 <= ai, bi <= n - 1
// ai != bi
// There are no repeated connections.


class Solution {
public:
void dfs(int u, int parent, vector<int>& ids, vector<bool>& visited, vector<int>& low, vector<vector<int>>& graph, vector<vector<int>>& result) {
        visited[u] = true;
        int id = ids[parent] + 1;
        low[u] = id;
        ids[u] = id;
        for (int n : graph[u]) {
            if (n == parent) continue;
            if (!visited[n]) {
                dfs(n, u, ids, visited, low, graph, result);
                low[u] = min(low[u], low[n]);
                if (ids[u] < low[n]) {
                    result.push_back({u, n});
                }
            } else {
                low[u] = min(low[u], ids[n]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n, vector<int>());
         for (const vector<int>& conn : connections) {
            int to = conn[0];
            int from = conn[1];
            graph[to].push_back(from);
            graph[from].push_back(to);
        }
        
        vector<vector<int>> result;
        vector<bool> visited(n, false);
        vector<int> low(n, -1);
        vector<int> ids(n, 0);
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, i, ids, visited, low, graph, result);
            }
        }
        return result;
    }
};