#include <iostream>
#include <cmath>;
using namespace std;

int main() {
	int dp[100001] = { 0 };
	int n;
	cin >> n;
	dp[0] = 0;

	for (int i = 1;i <= n;i++) {
		dp[i] = i;
		for (int j = 1;j <=sqrt(i);j++) {
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
		
	}
	cout << dp[n];
}