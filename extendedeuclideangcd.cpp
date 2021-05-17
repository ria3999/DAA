
#include <iostream>
using namespace std;
struct Triplet
{
    int gcd;
    int x,y;
};
Triplet gcdExtendedEuclidean(int a,int b)
{
    if(b==0)
    {
        Triplet myAns;
        myAns.gcd=a;
        myAns.x=1;
        myAns.y=0;
        return myAns;
    }
    Triplet smallAns=gcdExtendedEuclidean(b,a%b);
    Triplet myAns;
    myAns.gcd=smallAns.gcd;
    cout<<myAns.gcd<<" ";
    myAns.x=smallAns.y;
    cout<<myAns.x<<" ";
    myAns.y=(smallAns.x-((a/b)*(smallAns.y)));
    cout<<myAns.y<<endl;
    return myAns;
}
int main() 
{
    Triplet k=gcdExtendedEuclidean(57,81);
    cout<<k.gcd<<" ";
    cout<<k.x<<" ";
    cout<<k.y<<" ";
    return 0;
}
