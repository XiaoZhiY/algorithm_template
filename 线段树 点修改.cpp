#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <map>
#include <sstream>
#include <iterator>
#include <deque>
#include <list>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

using namespace std;

//线段树普通递归写法
//找寻 l - r 之间的最小值


const int maxn = 100000 + 10;



int minv[maxn * 2];


// find min(ql, qr);
int ql, qr;

int query(int o, int L, int R)
{
	int M = (R - L) / 2 + L;
	int ans = INT_MAX;
	if (ql <= L && R <= qr) return minv[o];
	if (ql <= M) ans = min(ans, query(o * 2, L, M)); // left
	if (M < qr) ans = min(ans, query(o * 2 + 1, M + 1, R)); //right
	return ans;
}

// change A[p] = v;
// p 是 [1, n]
int p, v;
void update(int o, int L, int R)
{
	int M = (R - L) / 2 + L;
	if (L == R) minv[o] = v;
	else
	{
		// L < R
		if (p <= M) update(o * 2, L, M);
		else update(o * 2 + 1, M + 1, R);
		minv[o] = min(minv[o * 2], minv[o * 2 + 1]);
	}
}

// 通过 a 初始化树
void init(int a[], int n,int h)
{
	int i = 0;
	for(; i < n; i++)
		minv[i + h] = a[i];
	for (; i < h; i++)
	{
		minv[i + h] = INT_MAX;
	}
	int o = h - 1;
	while (o >= 1)
	{
		minv[o] = min(minv[o * 2], minv[o * 2 + 1]);
		o--;
	}
}

int main() 
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = 10;

	//h 为需要多少个除了最底层的节点
	int h = 1;
	while (h < n)
		h *= 2;
	init(a, n ,h);
	
	
	
	p = 5; v = 1;
	update(1, 1, 16);

	for (int i = 1; i < h + n; i++)
		cout << minv[i] << endl;

	cout << query(1, 1, 16) << endl;
	return 0;
}