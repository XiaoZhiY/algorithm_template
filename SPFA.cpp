/*
SPFA适用于存在负边的有向图，并且可以检测是否有负环。 
如果是无向图必须没有负边，否则就相当于负环，不存在最短路。 
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

const int Inf=1e7+5;

struct edge{
	int des;
	int dist;
};


int n,s,e;	//边数，起点，终点 
vector <edge> G[N+2];
int d[N+2],  //起点到各个点的距离 
inq[N+2],	 //某个点是否在队列中 
cnt[N+2];	 //某个点距离被更新的次数，如果到达n就说明有负环 
int pre[N+2];


bool spfa(int s){ //算出从s到所有顶点的最短路，有负环返回false 
	for(int i=1;i<=1000;i++) d[i]=Inf;
	d[s]=0;
	inq[s]=1;
	cnt[s]=1;
	queue <int> Q;
	Q.push(s);
	while(!Q.empty()){
		int u=Q.front(); Q.pop();
		inq[u]=0;
		for(int i=0;i<G[u].size();i++){
			edge ed=G[u][i];
			if(d[ed.des]==Inf || d[ed.des]>d[u]+ed.dist){
				d[ed.des]=d[u]+ed.dist;
				if(!inq[ed.des]){
					Q.push(ed.des);
					inq[ed.des]=1;
					if(++cnt[ed.des]>=n) return false;
				}
			}
		}
	} 
	return true;
}


int main()
{
	cin>>n; //n是边数不是点数 
	for(int i=0;i<n;i++){
		int a,b,d;
		cin>>a>>b>>d;
		G[a].push_back(edge{b,d});	
		G[b].push_back(edge{a,d});   
	}
	cin>>s>>e;  
	bool ok=spfa(s);
	if(ok==false){
		cout<<" 有负环！";
		return 0;
	}
	if(d[e]==Inf) cout<<"Inf"<<endl;
	else cout<<d[e]<<endl; 
	
	return 0;
}
