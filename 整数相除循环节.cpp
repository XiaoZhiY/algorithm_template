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
vector <int> V;	//ÿ���ϵ��� 
map <int,int> M; //��¼ÿ�γ��ֵı������Լ�λ�� 

int main()
{
	int a,b,n,cnt=0,cur;
	cin>>a>>b>>n;
	a%=b;
	while(1){
		if(cnt==n-1){  //����Ѿ�����nλ�� 
			for(int i=0;i<3;i++){
				a*=10;
				cout<<a/b;
				a%=b;
			}
			cout<<endl;
			return 0;
		}
		a*=10;  //�õ�������
		map <int,int>::iterator it=M.find(a);	
		//���������������ֹ���˵����ʼѭ���ˣ��ҵ�ѭ������� 
		if(it!=M.end()){
			cur=it->second;
			break;
		} 
		M[a]=cnt;
		V.push_back(a/b);
		a%=b;
		cnt++;
		
	}
	int len=cnt-cur;        //ѭ���ڵĳ���
	int st=(n-1-cur)%len;   //�ҵ���nλ����ѭ�����ж�Ӧ�������ʼλ�� 
	cout<<V[st+cur];		//�����0��ʼ�ľ����±� 
	for(int i=0;i<2;i++){
		st=(st+1)%len;		//�ҵ�����λ�� 
		cout<<V[st+cur];
	} 
	cout<<endl;
	
	return 0;
}
