#include <iostream>

using namespace std;

int checkPalindrome(const string& s, int l, int r) {
	while (l < r) {
		if (s[l] != s[r])return 0;
		l++;
		r--;
	}
	return 1;
}

int main() {
	int test_case;
	cin >> test_case;
	while (test_case--) {
		string str;
		cin >> str;
		int left = 0;
		int right = str.length() - 1;
		bool isUsa = false;
		bool isEnd = false;
		int result = 0;
		while (left < right) {
			if (str[left] == str[right]) {
				left += 1;
				right -= 1;
			}
			
			else {
				bool case1 = checkPalindrome(str, left + 1, right);
				bool case2 = checkPalindrome(str, left, right - 1);
				if (case1 || case2)result = 1;
				else result = 2;
				break;
			}

		}
		cout << result << "\n";

	}
}