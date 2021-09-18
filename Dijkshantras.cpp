#include<iostream>
#include<list>
#include<vector>
#include<set>
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
        void addEdge(int i,int j,bool undir=true)
        {
            l[i].push_back(j);
            if(undir)
                l[j].push_back(i);
        }
        int dijkshatra(int src,int dest)
        {
            vector<int>dist(V,INT_MAX);
            set<pair<int,int> >s;
            dist[src]=0;
            s.insert({0,src});
            while(!s.empty())
            {
                auto it=s.begin();
                int node=it->second;
                int distanceTillNow=it->first;
                s.erase(it);
                for(auto nbrpair:l[node])
                {
                    int nbr=nbrpair.second;
                    int currentEdge=nbrpair.first;
                    if(distaceTillNow+currentEdge<dist[nbr])
                    {
                        auto f=s.find({dist[nbr],nbr});
                        if(f!=s.end())
                        {
                            s.erase(f);
                        }
                        distance[nbr]=distanceTillNow+currentEdge;
                        s.insert({dist[nbr],nbr});
                    }
                }

            }
            return dist[dest];
        }

};
int main()
{
    Graph g(5);
    g.addEdge(0,1,1);
    g.addEdge(1,2,2);
    g.addEdge(0,2,4);
    g.addEdge(0,3,7);
    g.addEdge(3,2,2);
    g.addEdge(3,4,3);
    cout<<g.dijkshatra(0,4);
    return 0;
}
