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



const int maxn = 100000 + 10;
int c[maxn];
int a[maxn];
int n;

int lowbit(int x)
{
	return x&(-x);
}

void add(int x, int inc)
{
	while (x <= n)
	{
		c[x] += inc;
		x += lowbit(x);
	}
}

int sum(int x)
{
	int ans = 0;
	while(x > 0)
	{
		ans += c[x];
		x -= lowbit(x);
	}
	return ans;
}

int main() 
{
	memset(c, 0, sizeof(c));
	memset(a, 0, sizeof(a));

	/*
	4
	3 1 2 4
	3
	1 4
	3 3
	2 4

	*/
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		add(i, a[i]);
	}
	int k;
	scanf("%d", &k);
	while (k--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		cout << sum(r) - sum(l - 1) << endl;
	}
	return 0;
}