#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<set>
using namespace std;
vector<int>level(150,0);
vector<int>parent(150,0);
int getLevel(int id)
{
    if(level[id]!=0)
        return level[id];
    
    if(parent[id]==0)
    {
        level[id] = 1;
        return 1;
    }
    else{
        level[id] = 1+getLevel(parent[id]);
        return level[id];
    }
}
int main()
{
    level[1] = 1;
    int n,m,max_level = 0;
    cin>>n>>m;
    map<int,queue<int> >childs;//每一级的节点
    set<int>parents_set;
    for(int i = 0;i < m;i++)
    {
        int id,k;
        cin>>id>>k;
        parents_set.insert(id);
        for(int j = 0;j < k;j++)
        {
            int t;
            cin>>t;
            parent[t] = id;
        }
    }
    for(int i = 1;i <= n;i++)
    {
        int tmp = getLevel(i);
        if(tmp>max_level)
            max_level = tmp;
        childs[tmp].push(i);
    }
    for(int i = 1;i <= max_level;i++)
    {
        int count = 0;
        while (!childs[i].empty())
        {
            if(!parents_set.count(childs[i].front()))
                count++;
            childs[i].pop();
        }
        if(i-1) cout<<" ";
        cout<<count;
    }
    cout<<endl;
    return 0;
}