#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int board[101] = { 0 };
	int WHat[101] = { 0 }; //1이면 사다리, 2이면 뱀
	for (int i = 0;i < n;i++) {
		int x, y;
		cin >> x >> y;
		WHat[x] = 1;
		board[x] = y;
	}
	for (int i = 0;i < m;i++) {
		int u, v;
		cin >> u >> v;
		WHat[u] = 2;
		board[u] = v;
	}
	queue<pair<int,int>>q;
	q.push({1,0});
	int dice[6] = { 6,5,4,3,2,1 };
	bool visited[101] = { false };
	while (!q.empty()) {
		auto cu = q.front();
		int cur = cu.first;
		int cnt = cu.second;
		q.pop();
		for (int num : dice) {
			int x = cur + num;
			if (x < 100) {
				while(WHat[x] != 0) {
					x = board[x];
				}
				if (!visited[x]) {
					q.push({ x,cnt + 1 });
					visited[x] = true;
				}
			}
			else if (x == 100) {
				cout << cnt+1 << "\n";
				return 0;
			}
		}

	}

}