#include <algorithm>
#include <iostream>
#include <string>
#include <string.h>
#include <queue>
using namespace std;

string m[1501];
int r, c;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool isGo[1501][1501];
int cm[1501][1501];
bool removeTartgetMap[1501][1501];
int ck[1501][1501];

struct Group {
	int groupId;
	int x, y, count;

	bool operator < (const Group &other) const {
		if(count == other.count) {
			return groupId > other.groupId;
		} else {
			return count > other.count;
		}
	}

	Group(int groupId, int x, int y, int count): groupId(groupId), x(x), y(y), count(count) {}
};


int canGo(pair<int,int> start, pair<int,int> end) {
	priority_queue<Group> q;
	// int ck[1501][1501];
	// for(int i=0;i<=1500;i++) {
	// 	for(int j=0;j<=1500;j++) {
	// 		ck[i][j] = 0;
	// 	}
	// }

	// printf("%d %d", start.first, start.second);
	q.push(Group(1, start.first, start.second, 0));
	q.push(Group(2, end.first, end.second, 0));

	ck[start.first][start.second] = 1;
	ck[end.first][end.second] = 2;

	while(!q.empty()) {
		Group top = q.top(); q.pop();
		int x = top.x;
		int y = top.y;
		int count = top.count;
		// printf("x: %d y: %d grupId: %d count: %d\n", x, y, top.groupId, count);

		// if(q.size() >= 100) {
		// 	return 0;
		// }
		for(int i=0;i<4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || nx >= r) continue;
			if(ny < 0 || ny >= c) continue;
			// printf("nx : %d ny: %d\n", nx, ny);
			// printf("ck[nx][ny] : %d\n", ck[nx][ny]); //nx, ny)
			if(ck[nx][ny])
			if(ck[nx][ny] == top.groupId) {
				continue;
			} else if(ck[nx][ny] != 0 && ck[nx][ny] != top.groupId) {
				return max(cm[nx][ny], cm[x][y]);
			}

			q.push(Group(top.groupId, nx, ny, cm[nx][ny]));
			ck[nx][ny] = top.groupId;
		}
	}
	return 0;
}

void countIceRemoveDay() {
	queue<pair<int,pair<int,int>>> q;
	bool ck[1501][1501];
	memset(ck, 0, sizeof(ck));

	for(int i=0;i<r;i++) {
		for(int j=0;j<c;j++) {
			if(m[i][j] != 'X') {
				q.push(make_pair(0, make_pair(i, j)));
				ck[i][j] = true;
			}
		}
	}

	while(!q.empty()) {
		auto here = q.front().second;
		int count = q.front().first;
		q.pop();
		cm[here.first][here.second] = count;

		int x = here.first;
		int y = here.second;
		for(int i=0;i<4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || nx >= r) continue;
			if(ny < 0 || ny >= c) continue;
			if(ck[nx][ny]) continue;
			q.push(make_pair(count + 1, make_pair(nx, ny)));
			ck[nx][ny] = true;	
		}
	}
}

int main() {
	cin >> r >> c;
	pair<int, int> start = {-1, -1}, end = {-1, -1};

	for(int i=0;i<r;i++) {
		cin >> m[i];
		for(int j=0;j<c;j++) {
			if(m[i][j] == 'L') {
				if(start.first == -1) {
					start = make_pair(i, j);
				} else {
					end = make_pair(i, j);
				}
			}
		}
	}

	// priority_queue<pair<int, pair<int,int>>> q; 
	// q.push(make_pair(-1, make_pair(1, 0)));
	// q.push(make_pair(-1, make_pair(2, 0)));
	// q.push(make_pair(1, make_pair(1, 0)));
	// q.push(make_pair(1, make_pair(2, 0)));
	// q.push(make_pair(0, make_pair(1, 0)));
	// q.push(make_pair(0, make_pair(2, 0)));
	// while(!q.empty()) {
	// 	auto x = q.top();
	// 	q.pop();
	// 	printf("%d %d %d\n", x.first, x.second.first, x.second.second);
	// }
	// printf("%d %d\n", start.first, start.second);
	countIceRemoveDay();
	// for(int i=0;i<r;i++) {
	// 	for(int j=0;j<c;j++) {
	// 		printf("%d ", cm[i][j]);
	// 	}

	// 	printf("\n");
	// }
	printf("%d", max(canGo(start, end), 0));
}