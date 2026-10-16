class Solution {
public:
    void recursive(vector<vector<int>>& grid, int i , int j , int &count,vector<vector<bool>>&vis){
        if(i>=grid.size()||j>=grid[0].size()||i<0||j<0){
            return;
        }
        if(grid[i][j]==0||vis[i][j])return ;
        count++;
        //ans=max(ans,count);
        vis[i][j]=true ;
        recursive(grid,i,j+1,count,vis);
        recursive(grid,i+1,j,count,vis);
        recursive(grid,i,j-1,count,vis);
        recursive(grid,i-1,j,count,vis);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int result =0;
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i =0;i<grid.size();i++){
            for(int j =0;j<grid[0].size();j++){
                if(grid[i][j]!=0&&!vis[i][j]){
                    int count=0;
                      recursive(grid , i , j ,count, vis);
                      result =max(count,result);
                }
            }
        }
        return result ;
    }
};