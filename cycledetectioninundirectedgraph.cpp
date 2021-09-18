#include<iostream>
#include<list>
#include<queue>
using namespace std;
class Graph
{
    int V;
    list<int>*l;
    public:
    Graph(int v)
    {
        V=v;
        l=new list<int>[V];
    }
    void addedge(int i,int j,bool undir=true)
    {
        l[i].push_back(j);
        //if(undir)
        //l[j].push_back(i);
    }
    void print()
    {
        for(int i=0;i<V;i++)
        {
            cout<<i<<"->";
            for(auto j:l[i])
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
    void bfs(int s)
    {
        cout<<"Printing bfs:"<<endl;
        queue<int>q;
        bool *visited=new bool[V]{0};
        q.push(s);
        visited[s]=true;
        while(!q.empty())
        {
            int f=q.front();
            cout<<f<<" ";
            q.pop();
            for(auto nbr:l[f])
            {
                if(!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr]=true;
                }
            }
            cout<<endl;
        }

    }
    bool detectcyclein_ug(int s)
    {
        queue<int>q;
        bool *visited=new bool[V]{0};
        int *parent=new int[V]{-1};
        q.push(s);
        visited[s]=1;
        while(!q.empty())
        {
            int f=q.front();
            q.pop();
            for(auto nbr:l[f])
            {
                if(!visited[nbr])
                {
                    visited[nbr]=true;
                    q.push(nbr);
                    parent[nbr]=f;
                }
                else if(parent[f]!=nbr)
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
    g.addedge(0,1);
    g.addedge(0,4);
    g.addedge(2,1);
    g.addedge(3,4);
   // g.addedge(1,3);
    g.print();
    g.bfs(0);
    cout<<"cycle->"<<g.detectcyclein_ug(0)<<endl;
    return 0;
}