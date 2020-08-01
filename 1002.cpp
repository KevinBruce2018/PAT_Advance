#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    double a[1001]={0},b[1001]={0},sum[1001]={0};
    int k1,k2;
    cin>>k1;
    for(int i = 0;i < k1;i++)
    {
        int x;
        double y;
        cin>>x>>y;
        a[x] = y;
    }
    cin>>k2;
    for(int i = 0;i < k2;i++)
    {
        int x;
        double y;
        cin>>x>>y;
        b[x] = y;
    }
    int count = 0;
    for(int i = 0;i < 1001;i++)
    {
        sum[i] = a[i]+b[i];
        if(sum[i]!=0)
            count++;
    }
    cout<<count;
    for(int i = 1000;i >= 0;i--)
    {
        if(sum[i]!=0)
            printf(" %d %.1lf",i,sum[i]);
    }
    cout<<endl;
    return 0;
}
