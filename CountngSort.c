# include<stdio.h>
int main()
{
    int arr[]={11,3,7,3,9,2};
    int max=-1,n=6;
    for(int i=0;i<n;i++)
    {
        if(max<arr[i])
            max=arr[i];
    }
    int countarray[max];
    for(int i=0;i<=max;i++)
    {
        countarray[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        countarray[arr[i]]++;
    }
    for(int i=0;i<=max;i++)
    {
        printf("%d",countarray[i]);
    }
    printf("\n");
    int sum=0;
    for(int i=0;i<=max;i++)
    {
    sum=sum+countarray[i];
     countarray[i]= sum;
    }

       for(int i=0;i<=max;i++)
    {
        printf("%d",countarray[i]);
    }
    printf("\n");
    int out[n];
    for(int i=0;i<n;i++)
    {
        int index=countarray[arr[i]]-1;
        printf("index=%d for arr[i]=%d\n",index,arr[i]);
        countarray[arr[i]]=countarray[arr[i]]-1;
        out[index]=arr[i];
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",out[i]);
    }
    return 0;
}
