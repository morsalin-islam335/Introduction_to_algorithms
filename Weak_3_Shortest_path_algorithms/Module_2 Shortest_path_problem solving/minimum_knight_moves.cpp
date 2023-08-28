//program to find out minimum knight moves in a chess board

//problem link: https://www.spoj.com/problems/NAKANJ/fbclid=IwAR21eNRD-BCoAZeOAqvoqNoUHxyYWVuPdcac99oDaRNPhXm3Pj57-tSXOrI


#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int>pii;
const int N = 8;
int si,sj, ei,ej;
vector<vector<bool>>visited(N,vector<bool>(N,false)); vector<vector<bool>>visited2 = visited;// visited2 is for replace with visited
vector<vector<int>>level(N,vector<int>(N,0)); vector<vector<int>>level2 = level; // level2 is for replace level with level2 in loop

bool isValid(int i, int j)
{
    return (i >=0 &&  i< 8 && j >=0 && j < 8);
}
vector<pii>direction = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}}; // 2.5 movement of knight in chess board

void BFS(int si , int sj)
{
    queue<pii>q;
    q.push({si,sj});
    visited[si][sj] = true;
    // ekhon q theke operation chalata hoiba

    while(!q.empty())
    {
        pii u_pair = q.front(); q.pop();

        int i = u_pair.first; // row
        int j = u_pair.second; // column

        for(auto dir : direction)
        {
            int ni, nj; // new row and new column
            ni = i + dir.first; nj = j + dir.second;

            if (isValid(ni,nj) && !visited[ni][nj])
            {
                level[ni][nj] = level[i][j] + 1;
                visited[ni][nj] = true;
                q.push({ni,nj});
            }
        }
    }
}
int main()
{
    string start, end;
    int test; cin >> test;
    while(test --) 
    {
        cin >> start >> end;
        si = start[0]-'a';
        sj = start[1]-'1' ;

        ei = end[0]-'a' ;
        ej = end[1] - '1';

        visited = visited2;
        level = level2;
        BFS(si,sj);
        cout<<level[ei][ej]<<endl;
        
    }
    return 0;
}