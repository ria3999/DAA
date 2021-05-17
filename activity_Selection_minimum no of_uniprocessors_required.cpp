#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int fun(vector<int> &newemp,int k)
{
    for(int i=0;i<newemp.size();i++)
    {
        if(newemp[i]<=k)
        return i;
    }
    return -1;
}
int main() {
    vector<pair<int,int> > activity;
    int n,s,e;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s>>e;
        activity.push_back(make_pair(e,s));
    }
    sort(activity.begin(),activity.end());
    int count=0;
    int currentend=-1;
    vector<int>newemp;
    for(int i=0;i<n;i++)
    {
        if(activity[i].second >= currentend)
        {
            int z=fun(newemp,activity[i].second);
            if(z==-1)
            newemp.push_back(activity[i].first);
            else
            newemp[z]=activity[i].first;
        }
    }
    cout<<newemp.size()<<endl;
    return 0;
}

