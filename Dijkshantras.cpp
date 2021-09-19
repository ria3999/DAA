#include <iostream>
#include <list>
#include<vector>
#include<set>
#include <climits>
using namespace std;
class Graph
{
    int V;
     list<pair<int,int> >*l;
    public:
    Graph(int V)
    {
        this->V=V;
        l=new list<pair<int,int> >[V];
        
    }
    void addEdge(int s,int d,int w)
    {
        l[s].push_back(make_pair(d,w));
        l[d].push_back(make_pair(s,w));
    }
    int dijakstras(int src,int des)
    {
        vector<int>dist(V,INT_MAX);
        set<pair<int,int> >s;
        dist[src]=0;
        s.insert({src,0});
        while(!s.empty())
        {
            auto it=s.begin();
            int node=it->first;
            int distanceTillNow=it->second;
            s.erase(it);
            for(auto nbrPair: l[node])
            {
                int nbr=nbrPair.first;
                int currentEdge=nbrPair.second;
                if(distanceTillNow+currentEdge<dist[nbr])
                {
                    auto f=s.find({nbr,dist[nbr]});
                if(f!=s.end())
                s.erase(f);
                    dist[nbr]=distanceTillNow+currentEdge;
                    s.insert({nbr,dist[nbr]});
                }

            }
        }
        return dist[des];
    }
};


int main() 
{
    Graph g(5);
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(0,2,4);
    g.addEdge(0,3,7);
    g.addEdge(3,2,2);
    g.addEdge(3,4,3);
    cout<<g.dijakstras(0,4)<<endl;
    return 0;
}
