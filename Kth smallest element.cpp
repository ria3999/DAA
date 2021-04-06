#include <iostream>
using namespace std;
int partition(int a[],int l,int r)
{
    int pivot=a[l];
    int i=l+1;
    int j=r;
    do
    {
        while(a[i]<=pivot)
        i++;
        while(a[j]>pivot)
        j--;
        if(i<j)
        swap(a[i],a[j]);
    }while(i<j);
    swap(a[l],a[j]);
    return j;

}
int quicksort(int A[],int low,int high,int k)
{
    if(low<=high)
    {
       int pindex=partition(A,low,high);
       if(pindex==k-1)
       {
           return A[pindex];
       }
       else if(pindex>k-1)
          return quicksort(A,low,pindex-1,k);
          else
         return quicksort(A,pindex+1,high,k);
    }
    return -1;
    
}
int main() 
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int k;
    cin>>k;
    cout<<quicksort(a,0,n-1,k)<<endl;
}
