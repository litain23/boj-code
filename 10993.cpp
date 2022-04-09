#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

bool m[3000][3000];
int cnt[11];

void f(int n, int y, int x) {
	if(n == 2) {
		for(int i=0;i<3;i++) {
			for(int j=i;j<3;j++) {
				m[y+i][x+4-j] = true;
				m[y+i][x+j] = true;
			}
		}
		return;
	}

	if(n % 2) {
		for(int i=0;i<cnt[n];i++) {
			m[y+i][x + cnt[n] - 1 - i] = true;
			m[y+i][x + cnt[n] - 1 + i] = true;
		}
		for(int i=0;i<cnt[n] * 2 - 1;i++) {
			m[y+cnt[n]-1][x+i] = true;
		}

		f(n-1, y + cnt[n] / 2, x + cnt[n] / 2 + 1);
	} else {
		for(int i=x;i<=x+cnt[n]*2-2;i++) {
			m[y][i] = true;
		}

		for(int i=0;i<cnt[n];i++) {
			m[y+i][x + i] = true;
			m[y+i][x + cnt[n] * 2 - 2 - i] = true;
		}

		f(n-1, y+1, x + cnt[n] / 2 + 1);
	}
}

int main() {
	int n; 
	cin >> n;

	if(n == 1) {
		printf("*");
		return 0; 
	}

	cnt[2] = 3;
	for(int i=3;i<=10;i++) {
		cnt[i] = cnt[i-1] * 2 + 1;
	}

	f(n, 1, 1);

	for(int i=1;i<=cnt[n];i++) {
		vector<char> v;
		for(int j=1;j<=cnt[n]*2-1;j++) {
			if(m[i][j]) v.push_back('*');
			else v.push_back(' ');
		}
		for(int i=v.size()-1;i>=0;i--) {
			if(v[i] == '*') break;
			else v.pop_back();
		}
		for(char c: v) {
			printf("%c", c);
		}
		if(i != cnt[n]) printf("\n");
	}
}