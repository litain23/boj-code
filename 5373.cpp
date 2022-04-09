#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

char cube[7][4][4];
int cubeAround[7][5] = {
	{0, },
	{5, 2, 3, 4, 5},
	{1, 5, 6, 3, 1},
	{1, 2, 6, 4, 1},
	{1, 3, 6, 5, 1},
	{1, 4, 6, 2, 1},
	{3, 4, 5, 2, 3}
};

void init() {
	for(int face=1;face<=6;face++) {
		for(int i=1;i<=3;i++) {
			for(int j=1;j<=3;j++) {
				if(face == 1) {
					cube[face][i][j] = 'w';
				} else if(face == 2) {
					cube[face][i][j] = 'g';
				} else if(face == 3) {
					cube[face][i][j] = 'r';
				} else if(face == 4) {
					cube[face][i][j] = 'b';
				} else if(face == 5) {
					cube[face][i][j] = 'o';
				} else if(face == 6) {
					cube[face][i][j] = 'y';
				}
			}
		}
	}
}

int charToInt(char face) {
	if(face == 'U') return 1;
	if(face == 'L') return 2;
	if(face == 'F') return 3;
	if(face == 'R') return 4;
	if(face == 'B') return 5;
	if(face == 'D') return 6;
	return 0;
}


void turn(int cubeFace, bool clockWise) {
	char tempCube[4][4]; 
	for(int i=1;i<=3;i++) {
		for(int j=1;j<=3;j++) {
			tempCube[i][j] = cube[cubeFace][i][j];
		}
	}
	if(clockWise) {
		for(int i=1;i<=3;i++) {
			for(int j=1;j<=3;j++) {
				tempCube[i][j] = cube[cubeFace][3-j+1][i];	
			}
		}
	} else {
		for(int i=1;i<=3;i++) {
			for(int j=1;j<=3;j++) {
				tempCube[i][j] = cube[cubeFace][j][3+1-i];	
			}
		}
	}

	for(int i=1;i<=3;i++) {
		for(int j=1;j<=3;j++) {
			cube[cubeFace][i][j] = tempCube[i][j];
		}
	}
}

void turnAround(int cubeFace) {
	if(cubeFace == 1) {
		
	} else if(cubeFace == 2) {

	} else if(cubeFace == 3) {

	} else if(cubeFace == 4) {

	} else if(cubeFace == 5) {

	} else if(cubeFace == 6) {

	}
}

void f(char face, char direction) {
	int cubeFace = charToInt(face);
	turn(cubeFace, direction == '+' ? true : false);
	turnAround(cubeFace, direction == '+' ? true : false);
}

void main1() {
	init();
	int n; cin >> n;

	string input;
	cin >> input;

	for(int i=0;i<n;i++) {
		char face = input[i*3];
		char direction = input[i*3+1];
		f(face, direction);
	}
}

int main() {
	int tc; cin >> tc;
	for(int i=0;i<tc;i++) {
		main1();
		for(int i=1;i<=3;i++) {
			for(int j=1;j<=3;j++) {
				printf("%c", cube[1][i][j]);
			}
			printf("\n");
		}
	}
}