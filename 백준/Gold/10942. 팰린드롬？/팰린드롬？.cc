#include <iostream>
#include <vector>
using namespace std;
int dp[2001][2001] = { 0 };
int arr[2001] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;


	for (int i = 1;i <= n;i++) {
		cin >> arr[i];
		dp[i][i] = 1;
	}
	for (int i = 1;i < n;i++) {
		if (arr[i] == arr[i + 1]) {
			dp[i][i + 1] = 1;
		}
	}
	for (int len = 3;len <= n;len++) {
		for (int i = 1;i <= n - len+1;i++) {
			int j = i + len-1;
			if (arr[i] == arr[j] && dp[i + 1][j - 1]) {
				dp[i][j] = 1;
			}
		}
	}
	int m;
	cin >> m;
	while (m--) {
		int s, e;
		cin >> s >> e;
		cout << dp[s][e] << "\n";
	}
}