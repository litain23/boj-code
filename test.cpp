#include <cstdio>
#include <algorithm>
using namespace std;

int ans = 9;
int d[320001];

void f(int n, int num, int count, int cur) {
	if(cur <= 0 || cur >= 320000) return;
	if(count > 8) return;
	if(cur == num) {
		ans = min(ans, count);
		return;
	}

	int temp = 0;
	f(n, num, count + 1, cur * 10 + n);
	f(n, num, count + 1, cur + n);
	f(n, num, count + 1, cur - n);
	f(n, num, count + 1, cur / n);
	f(n, num, count + 1, cur * n);
}

int main() {
	int n, target;
	scanf("%d %d", &n, &target);

	for(int i=0;i<=32000;i++) {
		d[i] = 0x3f3f3f3f;
	}

	f(n, target, 1, n);
	printf("%d", ans);

}