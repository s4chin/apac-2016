#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

#define R 105
#define C 105

char a[R][C];
bool visited[R][C];
int dc[] = {0, 1, 0, -1};
int dr[] = {-1, 0, 1, 0};
int row, col;

void dfs(int i, int j) {
	visited[i][j] = true;
	for(int dir = 0; dir < 4; dir++) {
		int x = i + dr[dir], y = j + dc[dir];
		if(x >= 0 && x < row && y >= 0 && y < col) {
		    if(a[x][y] == '1' && !visited[x][y])
			    dfs(x, y);
        }
	}
}

int cc() {
	memset(visited, 0, sizeof(visited));
	int k = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (a[i][j] == '1' && !visited[i][j]) {
				dfs(i, j);
				k++;
			}
		}
	}
	return k;
}

int main() {
	freopen("A-large-practice.in", "r", stdin);
    freopen("A-large-practice.out", "w", stdout);
	int t, n;
	char p, r;
	int x, y;
	scanf("%d", &t);
	for(int z = 1; z <= t; z++) {
	    printf("Case #%d: \n", z);
		scanf("%d%d", &row, &col);
		for(int i = 0; i < row; i++) {
			scanf("%s", a[i]);
		}
		scanf("%d", &n);
		while(n--) {
			scanf(" %c", &p);
			if (p == 'Q') {
				int ans = cc();
				cout << ans << "\n";
			}
			else {
				scanf("%d%d %c", &x, &y, &r);
				a[x][y] = r;
			}
		}
	}
	return 0;
}

