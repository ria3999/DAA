#include <iostream>
#include <algorithm>
using namespace std;
/* Given an unsorted array of integers, design an algorithm and implement it using a program to find whether two elements exist such that their sum is equal to the given key element. */
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
            int sum;
        cin>>sum;
        sort(a,a+n);
        int i=0,j=n-1,f=0;
        while(i<j)
        {
            if(a[i]+a[j]==sum)
            {
                f=1;
                cout<<a[i]<<" "<<a[j]<<endl;
                break;
            }
            else if(a[i]+a[j]<sum)
            {
                i++;
            }
            else
            j--;
        }
        if(f==0)
        cout<<"No Such Element Exist"<<endl;
    }
    return 0;
}
