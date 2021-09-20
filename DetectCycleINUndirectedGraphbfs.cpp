#include <iostream>
#include <queue>
#include <list>
using namespace std;
class Graph
{
    int v;
    list<int>*l;
    public:
    Graph(int V)
    {
        v=V;
        l=new list<int>[v];
    }
    void addEdge(int s,int d)
    {
        l[s].push_back(d);
        l[d].push_back(s);
    }
    bool bfs(int src)
    {
        int visited[v+1];
        int parent[v+1];
        for(int i=0;i<v;i++)
        {
            visited[i]=0;
            parent[i]=0;
        }
        queue<int>q;
        q.push(src);
        visited[src]=1;
        while(!q.empty())
        {
            int f=q.front();
            q.pop();
            for(auto nbr:l[f])
            {
                if(!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr]=1;
                    parent[nbr]=f;
                }
                else if(parent[nbr]!=f)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
int main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(0,3);
    g.addEdge(3,4);
    cout<<g.bfs(0);
    return 0;
}
