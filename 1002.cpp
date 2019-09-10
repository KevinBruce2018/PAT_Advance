#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int count=0;
    double polynomial[1001]={0};
    int n;
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        int a;
        double b;
        cin>>a>>b;
        polynomial[a] = b;
    }
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        int a;
        double b;
        cin>>a>>b;
        polynomial[a] += b;
    }
    //0项不输出，但是题目没说，自己WA以后猜的
    for(int i = 0;i <= 1000;i++)
        if(polynomial[i])
            count++;
    cout<<count;
    
    for(int i = 1000;i>=0;i--){
        if(polynomial[i])
            printf(" %d %.1lf",i,polynomial[i]);
    }
    cout<<endl;
    return 0;
}
