class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans =0;
        for(int j=grid[0].size()-1,i=0;i<grid.size();i++){
            while(j>=0 && grid[i][j]<0)--j;
            ans += grid[0].size()-j-1;
        }
        return ans;
    }
};