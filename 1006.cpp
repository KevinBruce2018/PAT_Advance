#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n;
    cin>>n;
    //字符串比较规整，直接比较字符串大小
    string start_first = "23:59:59",left_last = "00:00:00";
    string first_id,last_id;
    for(int i = 0;i < n;i++)
    {
        string id,start_time,left_time;
        cin>>id>>start_time>>left_time;
        if(start_time<start_first){
            start_first = start_time;
            first_id = id;
        }
        if(left_time>left_last)
        {
            left_last = left_time;
            last_id = id;
        }
    }
    cout<<first_id<<" "<<last_id<<endl;
    return 0;
}