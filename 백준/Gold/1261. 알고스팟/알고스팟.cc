#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int dxy[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int dist[101][101];

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> arr(m);
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            dist[i][j] = 1e9;

    deque<pair<int,int>> dq;
    dq.push_front({0,0});
    dist[0][0] = 0;

    while (!dq.empty()) {
        auto [x,y] = dq.front();
        dq.pop_front();

        for (auto &d : dxy) {
            int nx = x + d[0];
            int ny = y + d[1];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

            int cost = dist[x][y] + (arr[nx][ny] == '1');

            if (cost < dist[nx][ny]) {
                dist[nx][ny] = cost;
                if (arr[nx][ny] == '1')
                    dq.push_back({nx, ny});
                else
                    dq.push_front({nx, ny});
            }
        }
    }

    cout << dist[m-1][n-1];
}
