//program to identify flood fill by using graph

//problem link: https://leetcode.com/problems/flood-fill/submissions/

#include<bits/stdc++.h> //this line is unnecessary for leetcode
using namespace std; // this line also



const int N = 5e1 + 7;    
typedef pair<int , int> pii;
vector<pii> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int color2;
vector<vector<int>>image2;
int target;


class Solution {
public:

   

    bool isValid(int i, int j)
    {
        return (i >= 0 && i < image2.size() && j >=0 && j< image2[0].size() && image2[i][j] == target);
    }
    void BFS(int si, int sj)
    {
        queue<pii>q;
        q.push({si, sj});
        image2[si][sj] = color2;
       

        while(!q.empty())
        {
            pii u_pair = q.front();
            q.pop();

            int i = u_pair.first; // row
            int j = u_pair.second; // column

            for(auto dir: direction)
            {
                int ni = i + dir.first;
                int nj = j + dir.second;

                if(isValid(ni, nj) && image2[ni][nj] != color2 )
                {
                    image2[ni][nj] = color2;
                    q.push({ni, nj});

                  
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image.empty()) return image; // jodi size  0 thaka tahola return korba
      
       target = image[sr][sc];
       color2 = color;
       image2 = image;
      
       BFS(sr, sc);
       return image2; 
    }
};

