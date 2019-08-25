/*
SPFA�����ڴ��ڸ��ߵ�����ͼ�����ҿ��Լ���Ƿ��и����� 
���������ͼ����û�и��ߣ�������൱�ڸ��������������·�� 
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


int n,s,e;	//��������㣬�յ� 
vector <edge> G[N+2];
int d[N+2],  //��㵽������ľ��� 
inq[N+2],	 //ĳ�����Ƿ��ڶ����� 
cnt[N+2];	 //ĳ������뱻���µĴ������������n��˵���и��� 
int pre[N+2];


bool spfa(int s){ //�����s�����ж�������·���и�������false 
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
	cin>>n; //n�Ǳ������ǵ��� 
	for(int i=0;i<n;i++){
		int a,b,d;
		cin>>a>>b>>d;
		G[a].push_back(edge{b,d});	
		G[b].push_back(edge{a,d});   
	}
	cin>>s>>e;  
	bool ok=spfa(s);
	if(ok==false){
		cout<<" �и�����";
		return 0;
	}
	if(d[e]==Inf) cout<<"Inf"<<endl;
	else cout<<d[e]<<endl; 
	
	return 0;
}
