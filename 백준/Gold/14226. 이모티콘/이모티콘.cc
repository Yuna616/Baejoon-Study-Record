#include <iostream>
#include <queue>


using namespace std;
bool visited[2001][2001] = { false };
int main() {
	int s;
	cin >> s;

	queue < pair<pair<int,int>, int>>q;
	q.push({{ 1,0 },0});
	visited[1][0] = true;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		int screen = cur.first.first;
		int clip = cur.first.second;
		int cnt = cur.second;
		if (screen == s) {
			cout << cnt << "\n";
			return 0;
		}
		if (screen > 0 && screen<2000) {
			if (!visited[screen][screen]) {
				visited[screen][screen] = true;
				q.push({ {screen,screen},cnt + 1 });
			}
			if (!visited[screen - 1][clip]) {
				visited[screen - 1][clip] = true;
				q.push({ {screen-1,clip},cnt + 1 });
			}
		}
		if (clip > 0 && screen+clip<2000) {
			if (!visited[screen + clip][clip]) {
				visited[screen + clip][clip] = true;
				q.push({ {screen + clip,clip},cnt + 1 });
			}
		}
	}
}