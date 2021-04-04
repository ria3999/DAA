#include <iostream>
using namespace std;
void insertion_sort(int a[],int n)
{
    int c=0,s=0;
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int temp=a[i];
        
        while(j>=0 && a[j]>temp)
        {
            c++;
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=temp;
        s++;
    }
    cout<<"comparisons="<<c<<endl;
    cout<<"shifts="<<s+c<<endl;
}
int main() 
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        insertion_sort(a,n);
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}
