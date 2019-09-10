#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    //WA  哭了  下次接着调整
    int max=0;
    double polynomial1[1001]={0},polynomial2[1001]={0};
    int n;
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        int a;
        double b;
        cin>>a>>b;
        if(a>max)
            max = a;
        polynomial1[a] = b;
    }
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        int a;
        double b;
        cin>>a>>b;
        if(a>max)
            max = a;
        polynomial2[a] = b;
    }
    cout<<max+1;
    for(int i = max;i>=0;i--)
    {
        printf(" %d %.1lf",i,polynomial1[i]+polynomial2[i]);
    }
    cout<<endl;
    return 0;
}
