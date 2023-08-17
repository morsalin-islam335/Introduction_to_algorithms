//program to reverse BFS

#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
vector<vector<int>>adj(N);
bool visited[N];
stack<int>st;

void bfs(int s)
{
    queue<int>q;
    q.push(s);
    visited[s] = true;
    st.push(s);

    while(!q.empty())
    {
        int front = q.front();
        q.pop();

        for(int v: adj[front])
        {
            if(visited[v]) continue;
            st.push(v);
            q.push(v);
            visited[v] = true;

        }
    }
};
int main()
{
    int numberOfNode; cin >> numberOfNode; 
    int numberOfEdge; cin >> numberOfEdge;
    int node1, node2;
    while(numberOfEdge --)  
    {
        cin >> node1 >> node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }

    bfs(1);

    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}