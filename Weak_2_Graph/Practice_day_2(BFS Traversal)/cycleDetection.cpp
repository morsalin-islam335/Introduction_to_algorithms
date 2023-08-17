// //program to detected cycle

// #include<bits/stdc++.h>
// using namespace std;
// const int N = 1e3 + 5;
// vector<vector<int>>adj(N);
// bool visited[N];

// bool isCycle(int u)//bfs operation
// {
//     queue<int>q;
//     q.push(u);
//     visited[u] = true;
//     int front;
//     while(!q.empty())
//     {
//         front = q.front();
//         q.pop();

//         for(int v : adj[front])
//         {
//             if(v == front) continue;
//             else if(visited[v]) return true; // cycle detected
//             q.push(v);
//             visited[v] = true;
//         }
//     }
//     return false;
// }
// int main()
// {
//     int numberOfNode; cin >> numberOfNode;
//     int numberOfEdge; cin >> numberOfEdge;
//     int node1, node2;
    
//     for(int i = 1; i<= numberOfEdge; i++)
//     {
//         cin >> node1 >> node2;
//         adj[node1].push_back(node2);
//         adj[node2].push_back(node1);
//     }

//     bool doesCycle = false;
//     for(int i = 1; i<= numberOfNode; i++)
//     {
//         if(visited[i] ) continue;
//         //cout<<"visiting "<<i<<endl;
//         doesCycle |= isCycle(i);
//     }

//     (doesCycle == true)? cout<<"YES": cout<<"NO";
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<vector<int>> adj(N);
bool visited[N];

bool isCycle(int u)
{
    queue<int> q;
    q.push(u);
    vector<int>parent(N,-1); //initialize all value with -1
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (int v : adj[front])
        {
            if (v == parent[front]) // Skip the edge to parent
                continue;
            if (parent[v] != -1)
                return true;
            q.push(v);
            parent[v] = front; // Set parent of v to front
        }
    }
    return false;
}

int main()
{
    int numberOfNode; cin >> numberOfNode;
    int numberOfEdge; cin >> numberOfEdge;
    int node1, node2;

    for (int i = 1; i <= numberOfEdge; i++)
    {
        cin >> node1 >> node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }

    bool doesCycle = false;
    for (int i = 1; i <= numberOfNode; i++)
    {
        if (!visited[i]) {
            doesCycle |= isCycle(i);
        }
    }
  
    (doesCycle) ? cout << "YES" : cout << "NO";
    return 0;
}
