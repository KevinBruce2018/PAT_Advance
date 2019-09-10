#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    //好久不写算法了，今天第一次刷甲级
    int a,b;
    cin>>a>>b;
    b = a+b;
    if(b<0)
        cout<<"-";
    else if(!b){
        cout<<"0"<<endl;
        return 0;
    }
    b = abs(b);

    stack<int>s;
    int count = 0;
    while (b!=0)
    {
        s.push(b%10);
        b/=10;
        count++;
        if(count%3==0)
            s.push((int)',');
    }
    if(s.top()==',')
        s.pop();
    while (!s.empty())
    {
        if(s.top()==',')
            cout<<",";
        else
            cout<<s.top();
        s.pop();
    }
    cout<<endl;
    return 0;
}