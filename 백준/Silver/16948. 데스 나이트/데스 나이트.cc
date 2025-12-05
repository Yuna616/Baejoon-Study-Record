#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int main() {
	int n;
	cin >> n;

	int visited[201][201] = { false };
	queue<tuple<int,int,int>>q;
	int dxy[6][2] = { {-2,-1} ,{-2,1},{0,-2},{0,2}, { 2,-1 },{2,1} };
	int a, b, r, c;
	cin >> a >> b >> r >> c;
	q.push({ a,b,0 });
	visited[a][b] = true;
	int ans = -1;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int curX = get<0>(cur);
		int curY = get<1>(cur);
		int cnt = get<2>(cur);
		if (curX == r && curY == c) {
			ans = cnt;
			break;
		}
		for (auto d : dxy) {
			int x = curX + d[0];
			int y = curY + d[1];
			if (x >= 0 && x < n && y >= 0 && y < n && !visited[x][y]) {
				visited[x][y] = true;
				q.push({ x,y,cnt + 1 });
			}
		}
	}
	cout << ans << "\n";
}