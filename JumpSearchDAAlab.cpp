#include <iostream>
#include<math.h>
using namespace std;
int jump_Search(int a[],int n,int x)
{
    int step = sqrt(n);
    int prev = 0;
    int c=1;
    while (a[min(step, n)-1] < x)
    {
        c++;
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }

    while (a[prev] < x)
    {
        prev++;
       
        if (prev == min(step, n))
        {
            //cout<<"Number of comaprisons"<<c;
            return -1;
        }
    }
   
    if (a[prev] == x)
    {
        cout<<"Number of comaprisons"<<c;
        return prev;
    }
    cout<<"Number of comaprisons"<<c;
    return -1;
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
      int x;
      cin>>x;
      int ans=jump_Search(a,n,x);
      if(ans!=-1)
      cout<<"Present"<<endl;
      else
      cout<<"Not Present"<<endl;
  }
  return 0;
}
