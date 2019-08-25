
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

const int maxnode = 400000 + 10;
const int SIGMA_SIZE = 26;
const int maxn = 300010;

struct Aho_Corasick {
	int ch[maxnode][SIGMA_SIZE];
	int val[maxnode];
	int f[maxnode];

	// suffix link 后缀链接 表示结点j沿着失配指针往回走时遇到的下一个单词节点编号
	int last[maxnode];
	int sz;
	Aho_Corasick()
	{
		sz = 1;
		memset(ch[0], 0, sizeof(ch[0]));
		memset(val, 0, sizeof(val));
		memset(last, 0, sizeof(last));
		memset(f, 0, sizeof(f));
	}

	void reset()
	{
		sz = 1;
		memset(ch, 0, sizeof(ch));
		memset(val, 0, sizeof(val));
		memset(last, 0, sizeof(last));
		memset(f, 0, sizeof(f));
	}

	int idx(char c)
	{
		return c - 'a';
	}

	void insert(char *s, int v)
	{
		int u = 0;
		int n = strlen(s);
		for (int i = 0; i < n; i++)
		{
			int c = idx(s[i]);
			if (!ch[u][c])
			{
				memset(ch[sz], 0, sizeof(ch[sz]));
				val[sz] = 0;
				ch[u][c] = sz;
				sz++;
			}
			u = ch[u][c];
		}
		val[u] = v;
	}

	void find(char *s)
	{
		int n = strlen(s);
		int j = 0;
		for (int i = 0; i < n; i++)
		{
			int c = idx(s[i]);
			while (j && !ch[j][c]) j = f[j];
			j = ch[j][c];
			if (val[j]) print(i, j);
			else if (last[j]) print(i, last[j]);
		}
	}

	void print(int i, int j)
	{
		if (j)
		{
			printf("%d %d\n", i, val[j]);
			print(i, last[j]);
		}
		
	}

	void getFail()
	{
		queue<int> q;
		f[0] = 0;
		// init queue
		for (int c = 0; c < SIGMA_SIZE; c++)
		{
			int u = ch[0][c];
			if (u)
			{
				f[u] = 0;
				q.push(u);
				last[u] = 0;
			}
		}
		while (!q.empty())
		{
			int r = q.front(); q.pop();
			for (int c = 0; c < SIGMA_SIZE; c++)
			{
				int u = ch[r][c];
				if (!u) continue;
				q.push(u);

				int v = f[r];
				while (v && !ch[v][c]) v = f[v];
				f[u] = ch[v][c];
				last[u] = val[f[u]] ? f[u] : last[f[u]];
			}
		}
	}
};


int main()
{
	Aho_Corasick *acM = new Aho_Corasick();
	acM->insert("abc", 1);
	acM->insert("abcd", 2);
	acM->insert("bcde", 3);
	acM->getFail();
	acM->find("abcdef");
	delete acM;
	return 0;
}

