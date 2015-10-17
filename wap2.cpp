/*
** some feature:
** 1. support error handling.
** 2. support low level cache.
*/

#include <queue>
#include <vector>
#include <iostream>

using namespace std;

struct GraphNode {
	int val;
	bool festive;
	bool visited;
	vector<int> neighbor;
	GraphNode(int x) : val(x), festive(false), visited(false) {}
};

int breadFirstSearch(vector<GraphNode>& g, int v) {
	queue<int> que;
	int depth = 0;

	if (g[v].festive)
		return 0;
	que.push(v);
	while (que.empty() == false) {
		int index = que.front();
		que.pop();
		g[index].visited = true;
		if (g[index].festive)
			return depth;
		depth++;
		for (int i = 0; i < g[index].neighbor.size(); i++) {
			int subIndex = g[index].neighbor[i];
			if (g[subIndex].visited == false)
				que.push(subIndex);
		}
	}
	return -1;
}

void cleanFlag(vector<GraphNode>& g) {
	for (int i = 1; i < g.size(); i++)
		g[i].visited = false;
}

int main() {
	int n, m, gNodeNum;
	vector<GraphNode> g;
	vector<int> cache;//store thre results that we already calculated.
	bool cacheUseable = false;
	//dummy
	GraphNode node(0);
	g.push_back(node);
	cache.push_back(-1);

	cin >> n >> m;

	//error handling
	if (n <= 0 || m <= 0)
		return -1;

	gNodeNum = n;
	for (int i = 1; i <= n; i++) {
		GraphNode node(i);
		g.push_back(node);
		cache.push_back(-1);
	}
	//read and build graph
	for (int i = 0; i < n - 1; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		if (v1 <= 0 || v1 > gNodeNum || v2 <= 0 || v2 > gNodeNum)
			return -1;
		g[v1].neighbor.push_back(v2);
		g[v2].neighbor.push_back(v1);
	}
	//slove the query
	g[1].festive = true;
	for (int i = 0; i < m; i++) {
		int type, v;
		cin >> type >> v;
		if (v <= 0 || v > gNodeNum)
			return -1;//input error data.
		if (type == 1) {
			g[v].festive = true;
			cacheUseable = false;
		} else if (type == 2) {
			int res;
			if (cacheUseable && cache[v] != -1)
				res = cache[v];
			else
				res = breadFirstSearch(g, v);

			if (res >= 0)
				cout << res << endl;
			else
				return -1;//error
			cleanFlag(g);
			cacheUseable = true;
		} else {
			return -1;//do not support that type.
		}
	}

	return 0;
}