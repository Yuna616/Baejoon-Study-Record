#include <iostream>
#include <vector>

using namespace std; // 연속합

static int N, answer;
static vector<int>A;
static vector<int>front;
static vector<int>back;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	A.resize(N);
	front.resize(N);
	back.resize(N);

	for (int i = 0; i < N; i++)
		cin >> A[i];

	front[0] = A[0];
	answer = front[0];
	for (int i = 1; i < N; i++)
	{
		front[i] = max(A[i], front[i - 1] + A[i]);
		answer = max(answer, front[i]);
	}

	back[N - 1] = A[N - 1];
	for (int i = N - 2; i >= 0; i--)
		back[i] = max(A[i], back[i + 1] + A[i]);

	for (int i = 1; i < N - 1; i++)
		answer = max(answer, front[i - 1] + back[i + 1]);

	cout << answer;
}