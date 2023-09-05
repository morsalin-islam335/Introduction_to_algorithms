//program to implement bellman ford algorithm

#include<bits/stdc++.h>
using namespace std;

class edge{
    public:
        int u,v,w;
        edge(int u, int v, int w)
        {
            this -> u = u; this -> v = v; this -> w = w;
        }
};
int main()
{
    int numberOfNode; cin >> numberOfNode; int numberOfEdge; cin >> numberOfEdge;
    vector<int>dist(numberOfNode+1, INT_MAX);

    vector<edge>v;
    for(int i = 0; i< numberOfNode; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge ed(a,b,c);
        v.push_back(ed);

    }

    dist[1] = 0;

        for (int i = 1; i <= numberOfNode - 1; i++)
        {
        for (int j = 0; j < v.size(); j++)
            {
                edge ed = v[j];
                int a = ed.u;
                int b = ed.v;
                int w = ed.w;
                if (dist[a] + w < dist[b])
                {
                    dist[b] = dist[a] + w;
                }
            }
        }

    for(int i = 1; i<= numberOfNode; i++)
    {
        cout<<"distance of "<<i<<" " <<dist[i] <<endl;
    }
    return 0;
}