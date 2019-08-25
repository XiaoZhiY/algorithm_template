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
vector <int> V;	//每次上的商 
map <int,int> M; //记录每次出现的被除数以及位置 

int main()
{
	int a,b,n,cnt=0,cur;
	cin>>a>>b>>n;
	a%=b;
	while(1){
		if(cnt==n-1){  //如果已经到第n位了 
			for(int i=0;i<3;i++){
				a*=10;
				cout<<a/b;
				a%=b;
			}
			cout<<endl;
			return 0;
		}
		a*=10;  //得到被除数
		map <int,int>::iterator it=M.find(a);	
		//如果这个被除数出现过就说明开始循环了，找到循环节起点 
		if(it!=M.end()){
			cur=it->second;
			break;
		} 
		M[a]=cnt;
		V.push_back(a/b);
		a%=b;
		cnt++;
		
	}
	int len=cnt-cur;        //循环节的长度
	int st=(n-1-cur)%len;   //找到第n位数在循环节中对应的相对起始位置 
	cout<<V[st+cur];		//计算从0开始的绝对下标 
	for(int i=0;i<2;i++){
		st=(st+1)%len;		//找到后两位数 
		cout<<V[st+cur];
	} 
	cout<<endl;
	
	return 0;
}
