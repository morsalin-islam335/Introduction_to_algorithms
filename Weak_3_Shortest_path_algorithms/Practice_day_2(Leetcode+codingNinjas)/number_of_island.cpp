//program to count total number of island 

//problem link: https://leetcode.com/problems/number-of-islands/submissions/

const int N = 1e3 + 5;
class Solution {
public:
   
    int ans ;
    
    bool visited[N][N];   // initial with false
    int numberOfRow, numberOfColumn;

    typedef pair < int, int> pii;

    vector < pii > direction = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};

    vector<vector<char>>grid2;
    
    bool isValid(int i, int j)
    {
        return (i >= 0 && i < numberOfRow && j >=  0 && j < numberOfColumn);
    }
    void dfs(int i, int j)
    {
        visited[i][j] = true;

        for(auto dir: direction)
        {
            int ni = i + dir.first;
            int nj = j+ dir.second;

            //if(visited[ni][nj]) continue;

            if(isValid(ni, nj) && !visited[ni][nj] && grid2[ni][nj] != '0')
            {
                dfs(ni, nj);
            }
        }
    }
    vector<string>graph;
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;

        grid2 = grid;
        numberOfRow = grid.size();
        numberOfColumn = grid[0].size();

        ans = 0;

        for(int i = 0; i< numberOfRow; i++)
        {
            for(int j = 0; j < numberOfColumn; j++)
            {
                if(grid2[i][j] != '0'  && !visited[i][j])
                {
                    dfs(i,j);
                    ans ++;
                }
            }
        }
        return ans;
       
    }
};