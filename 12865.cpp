#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
int v[101], w[101];
int d[101][100001];

int f(int i, int j) {
	if(i < 1) return 0;
	if(j < w[i]) return f(i-1, j);
	if(d[i][j]) return d[i][j];

	return d[i][j] = max(f(i-1,j), f(i-1,j-w[i]) + v[i]);
}

int main() {
	scanf("%d %d", &n, &k);
	for(int i=1;i<=n;i++) {
		scanf("%d %d", &w[i], &v[i]);
	}

	printf("%d", f(n, k));
}