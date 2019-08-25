/*
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
using namespace std;
const int maxn= 5000+2;
struct edge{
	int fr;
	int to;
	int dis;
};

bool operator>(const edge a,const edge b){
	return a.dis>b.dis;
}
priority_queue <edge,vector<edge>,greater<edge> > Q;

int pa[maxn];
int N,M;
int find(int x){
	if(pa[x]==x) return x;
	int r=find(pa[x]);
	pa[x]=r;
	return r;
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin>>N>>M;
	for(int i=1;i<=N;i++) pa[i]=i;
	for(int i=0;i<M;i++){
		edge e;
		cin>>e.fr>>e.to>>e.dis;
		Q.push(e);
	}
	int cnt=0,ans=0; //加入生成树边的数量 
	while(!Q.empty()){
		edge t=Q.top();	Q.pop();
		int r1=find(t.fr),r2=find(t.to);
		if(r1!=r2){
			ans+=t.dis;
			pa[r1]=r2;
			cnt++;
		}
		if(cnt==N-1) break;
	}
	if(cnt==N-1) cout<<ans<<endl;
	else cout<<"orz"<<endl;
	return 0;
}
