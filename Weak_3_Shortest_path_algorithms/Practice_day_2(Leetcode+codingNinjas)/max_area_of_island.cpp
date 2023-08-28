//program to find out max area of island
//problem link: https://leetcode.com/problems/max-area-of-island/description/


#include<bits/stdc++.h> // this line is uncecessary
using namespace std;  // this line also

int ans ;
vector<vector<int>>grid2;
const int N = 1e3 + 5;
bool visited[N][N];
typedef pair<int, int> pii;
vector<pii>direction = {{1,0},{-1,0},{0,1},{0,-1}};

class Solution {
public:
    bool isValid(int i, int j)
    {
        return(i >=0 && i< grid2.size() && j >= 0 && j < grid2[0].size() && grid2[i][j] == 1);
    }

    void BFS(int si, int sj)
    {
        queue<pii>q;
        q.push({si, sj}); ans ++;
        visited[si][sj] = true;

        cout<<"This is source "<<si <<" "<<sj<<endl;
        
        while(!q.empty())
        {
            pii u_pair = q.front(); q.pop();

            int i, j; i = u_pair.first, j = u_pair.second;

            for(auto dir: direction)
            {
                int ni, nj; ni = i + dir.first; nj = j + dir.second;
                if(isValid(ni,nj) && !visited[ni][nj])
                {
                    cout<<ni<<" "<<nj<<endl;
                    q.push({ni,nj});
                    ans ++;
                    visited[ni][nj] = true;
                }
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        grid2 = grid;
        if(grid2.size() == 0) return 0;

        int ans2 = 0;
        for(int i = 0; i<grid.size(); i++)
        {
            for(int j = 0; j< grid[0].size(); j++)
            {
                if(!visited[i][j] && grid2[i][j] != 0)
                {
                    ans = 0;
                    BFS(i,j);
                    ans2 = max(ans,ans2);
                }
            }
        }
         for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                visited[i][j]= false;
            }
        }
        return ans2;
    }
};
