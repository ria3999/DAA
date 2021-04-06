#include <iostream>
using namespace std;
void merge(int arr[],int lb,int mid,int ub)
{
    int i,j,k;
    int n1=mid-lb+1;
    int n2=ub-mid;
    int l[n1],r[n2];
    for(int i=0;i<n1;i++)
        l[i]=arr[lb+i];
    for(int j=0;j<n2;j++)
        r[j]=arr[mid+1+j];
    i=0;
    j=0;
    k=lb;
    
    while(i<n1 && j<n2)
    {
        if(l[i]<=r[j])
        {
            arr[k]=l[i];
            i++;
        }
        else
        {
            arr[k]=r[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=l[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=r[j];
        j++;
        k++;
    }
}
void mergesort(int arr[],int start,int end)
{
    if(start>=end){
        return;
    }
        int mid=(start + end)/2;
        mergesort(arr,start,mid);
        mergesort(arr,mid+1,end);
        merge(arr,start,mid,end);

}
int main() 
{
    int arr[]={3,2,6,5,9,6};
    mergesort(arr,0,5);
    for(int i=0;i<6;i++)
    cout<<arr[i]<<" ";
    return 0;
}
