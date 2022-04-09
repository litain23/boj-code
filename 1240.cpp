#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int main() {
	int n, m; scanf("%d %d", &n, &m);
	vector<pair<int,int>> v[1001];
	bool ck[1001];
	for(int i=0;i<n-1;i++) {
		int s, e, d;
		scanf("%d %d %d", &s, &e, &d);

		v[s].push_back({e, d});
		v[e].push_back({s, d});
	}

	for(int tc=0;tc<m;tc++) {
		int s, e;
		scanf("%d %d", &s, &e);

		memset(ck, 0, 1001);
		queue<pair<int,int>> q;
		q.push({s, 0});
		while(!q.empty()) {
			auto now = q.front(); q.pop();
			ck[now.first] = true;
			for(auto i: v[now.first]) {
				if(ck[i.first]) continue;
				if(i.first == e) {
					printf("%d\n", now.second + i.second);
					break;
				}

				q.push({i.first, i.second + now.second});
			}
		}
	}
}