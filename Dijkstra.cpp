/*
单源最短路径板子 
*/
#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <vector> 
#include <set>
#include <algorithm>
#include <math.h>
#include <string> 
#include <string.h>
#define N 10000
using namespace std;

struct edge{	//这个边在堆中为抽象边,代表目前源点到des的最短距离为dist 
	int des;
	int dist;
};

bool operator>(const edge a,const edge b){
	return a.dist>b.dist;
}

int n,s,e;	//边数，起点，终点 
priority_queue <edge,vector<edge>,greater<edge> > pq;
vector <edge> G[N+2];
int ans[N+2],pre[N+2],vis[N+2];	//距离数组和路径数组 

int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b,d;
		cin>>a>>b>>d;
		G[a].push_back(edge{b,d});	
		G[b].push_back(edge{a,d});  //有向图去掉这一行 
	}
	cin>>s>>e;   //确定起点就可算出到所有点的最短路径 
	memset(ans,-1,sizeof(ans));
	memset(pre,-1,sizeof(pre));
	pq.push(edge{s,0});
	ans[s]=0;
	while(!pq.empty()){
		edge t=pq.top(); pq.pop();
		if(vis[t.des]) continue;//加个vis数组可以加快效率 
		vis[t.des]=1;
		for(int i=0;i<G[t.des].size();i++){
			edge eg=G[t.des][i];
			if(ans[eg.des]<0||ans[eg.des]>ans[t.des]+eg.dist){
				ans[eg.des]=ans[t.des]+eg.dist;
				pre[eg.des]=t.des;	//修改该节点的前驱 
				pq.push(edge{eg.des,ans[eg.des]});
			}
		}
	}
	if(ans[e]<0) cout<<"Inf"<<endl;
	else cout<<ans[e]<<endl;
	
	return 0;
}
