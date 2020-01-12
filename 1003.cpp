#include<iostream>
#include<vector>
#define INF 0x3f3f3f3f
using namespace std;

vector<int> cost(500,INF);//到某个点的最短距离
bool visit[500] = {0}; //一个点是否在集合中
vector<vector<int> >graph(500,vector<int>(500,INF)); //邻接矩阵
vector<int>team_num(500,0);//每个点拥有的队伍数
vector<int>res_num(500,0);//到达i点的救援队数量
vector<int>raod_num(500,0);//到达i点多少条不同的道路

void dijkstra(int first,int n)
{
    //初始化第一个点的信息
    raod_num[first] = 1;
    res_num[first] = team_num[first];
    cost[first] = 0;
    visit[first] = 1;
    //初始化每个点的救援队数量
    for(int i = 0;i < n;i++)
    {
        cost[i] = graph[first][i];
        if(cost[i]!=INF)
        {
            raod_num[i] = 1;
            //与原点直接连接
            if(i!=first)
                res_num[i] = team_num[i]+team_num[first];
        }
        else
        {
            //与原点不直接连接
            res_num[i] = team_num[i];
        }
        
    }
    //在集合中加入其它的点
    for(int i = 1;i < n;i++)
    {
        int min = INF+1;
        int min_pos = 0;
        //找到未加入集合，且离原点最近的点
        for(int j = 0; j < n;j++)
        {
            if(!visit[j]&&cost[j]<min)
            {
                min = cost[j];
                min_pos = j;
            }
        }
        visit[min_pos] = 1;
        //修改相关的路径
        for(int j = 0;j < n;j++)
        {
            if(j==min_pos)  continue;//不加这句话会导致错误的执行else if语句
            if(graph[min_pos][j]+cost[min_pos]<cost[j])
            {
                cost[j] = graph[min_pos][j]+cost[min_pos];
                raod_num[j] = raod_num[min_pos];
                res_num[j] = res_num[min_pos]+team_num[j];
            }
            else if(graph[min_pos][j]+cost[min_pos]==cost[j])
            {
                raod_num[j] += raod_num[min_pos];
                res_num[j] = max(res_num[j],res_num[min_pos]+team_num[j]);
            }
        }
    }
}
int main()
{
    int n,m,a,b;
    //输入输出重定向语句，在测试时使用，提交时注释掉
    //freopen("1.txt","w",stdout);
    //freopen("2.txt","r",stdin);
    cin>>n>>m>>a>>b;
    for(int i = 0;i < n;i++){
        cin>>team_num[i];
        graph[i][i] = 0;
    }
    for(int i = 0;i < m;i++)
    {
        int t1,t2,dis;
        cin>>t1>>t2>>dis;
        graph[t1][t2] = graph[t2][t1] = dis;
    }
    dijkstra(a,n);
    cout<<raod_num[b]<<" "<<res_num[b]<<endl;
    return 0;
}