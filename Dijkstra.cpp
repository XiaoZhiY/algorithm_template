/*
��Դ���·������ 
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

struct edge{	//������ڶ���Ϊ�����,����ĿǰԴ�㵽des����̾���Ϊdist 
	int des;
	int dist;
};

bool operator>(const edge a,const edge b){
	return a.dist>b.dist;
}

int n,s,e;	//��������㣬�յ� 
priority_queue <edge,vector<edge>,greater<edge> > pq;
vector <edge> G[N+2];
int ans[N+2],pre[N+2],vis[N+2];	//���������·������ 

int main()
{
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b,d;
		cin>>a>>b>>d;
		G[a].push_back(edge{b,d});	
		G[b].push_back(edge{a,d});  //����ͼȥ����һ�� 
	}
	cin>>s>>e;   //ȷ�����Ϳ���������е�����·�� 
	memset(ans,-1,sizeof(ans));
	memset(pre,-1,sizeof(pre));
	pq.push(edge{s,0});
	ans[s]=0;
	while(!pq.empty()){
		edge t=pq.top(); pq.pop();
		if(vis[t.des]) continue;//�Ӹ�vis������Լӿ�Ч�� 
		vis[t.des]=1;
		for(int i=0;i<G[t.des].size();i++){
			edge eg=G[t.des][i];
			if(ans[eg.des]<0||ans[eg.des]>ans[t.des]+eg.dist){
				ans[eg.des]=ans[t.des]+eg.dist;
				pre[eg.des]=t.des;	//�޸ĸýڵ��ǰ�� 
				pq.push(edge{eg.des,ans[eg.des]});
			}
		}
	}
	if(ans[e]<0) cout<<"Inf"<<endl;
	else cout<<ans[e]<<endl;
	
	return 0;
}
