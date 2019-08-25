
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
const int sigma_size = 26;
const int maxn = 300010;

struct Trie {
	int ch[maxnode][sigma_size];
	int val[maxnode];
	int sz;
	Trie()
	{
		sz = 1;
		memset(ch[0], 0, sizeof(ch[0]));
	}

	void reset()
	{
		sz = 1;
		memset(ch, 0, sizeof(ch));
		memset(val, 0, sizeof(val));
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

	int find(char *s)
	{
		int u = 0;
		int n = strlen(s);
		for (int i = 0; i < n; i++)
		{
			int c = idx(s[i]);
			if (!ch[u][c])
				return 0;
			u = ch[u][c];
		}
		return val[u];
	}

};


int main()
{
	Trie *tree = new Trie();
	tree->insert((char *)"abc", 6);
	tree->insert((char *)"abcd", 7);
	cout << tree->find((char *)"abcd") <<endl;
	delete tree;
	return 0;
}