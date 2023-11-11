#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define vi vector<int>
#define v vector

class Solution {
public:
	int reverse(int x) {
		int negcheck = 0;
		int bigNoCheck = 0;
		int digit = 1;
		int sol = 0;
		if (x == 0)
			return 0;
		if (x == -2147483648)
			return 0;
		if (x < 0) {
			x = x * -1;
			negcheck = 1;
		}
		for (int i = x; i >= 10; i /= 10) {
			digit *= 10;
		}
		if (digit == 1000000000)
			bigNoCheck = checkBigNo(x % 10, digit, negcheck);

		while (digit > 0) {
			if (bigNoCheck)
				bigNoCheck = checkBigNo(x % 10, digit, negcheck);
			if (bigNoCheck && checkOverFlowPos(x % 10, digit, negcheck))
				return 0;
			sol += digit * (x % 10);
			digit /= 10;
			x /= 10;
		}
		if (negcheck == 1) {
			sol = sol * -1;
		}
		return sol;
	}
	//2147483648
	int checkBigNo(int x, int digit, int isNeg) {
		if (digit == 1000000000 && x >= 2)
			return 1;
		if (digit == 100000000 && x >= 1)
			return 1;
		if (digit == 10000000 && x >= 4)
			return 1;
		if (digit == 1000000 && x >= 7)
			return 1;
		if (digit == 100000 && x >= 4)
			return 1;
		if (digit == 10000 && x >= 8)
			return 1;
		if (digit == 1000 && x >= 3)
			return 1;
		if (digit == 100 && x >= 6)
			return 1;
		if (digit == 10 && x >= 4)
			return 1;
		if (digit == 1 && x >= 7 && isNeg)
			return 1;
		if (digit == 1 && x >= 8)
			return 1;
		return 0;
	}
	int checkOverFlowPos(int x, int digit, int isNeg) {
		if (digit == 1000000000 && x > 2)
			return 1;
		if (digit == 100000000 && x > 1)
			return 1;
		if (digit == 10000000 && x > 4)
			return 1;
		if (digit == 1000000 && x > 7)
			return 1;
		if (digit == 100000 && x > 4)
			return 1;
		if (digit == 10000 && x > 8)
			return 1;
		if (digit == 1000 && x > 3)
			return 1;
		if (digit == 100 && x > 6)
			return 1;
		if (digit == 10 && x > 4)
			return 1;
		if (digit == 1 && x > 7 && isNeg)
			return 1;
		if (digit == 1 && x > 8)
			return 1;
		return 0;
	}
};

int main(void)
{
	Solution s;
	const int max_pos = 2147483647;
	const int max_neg = -2147483648;
	vi checks = {5599, 636363, 1000, 22, 1, -5599, -636363, -1000, -22,
					-1, -2147483412, -2143847412,//11
					-2147483412, -2143847412,
					max_pos, max_neg};
	vi sols = {9955, 363636, 1, 22, 1, -9955, -363636, -1, -22,
				  -1, -2143847412, -2147483412,
				  -2143847412, -2147483412,
				  0, 0};
//	cout << s.reverse(-5599) << ' ' << s.reverse(-636363) << ' ';
//	cout << s.reverse(-1000) << ' ';
//	cout << s.reverse(-22) << ' ' << s.reverse(-1);
//
//
//	cout << ' ' << s.reverse(-2147483412);
//	cout << ' ' << s.reverse(-2143847412);
//	cout << ' ' << s.reverse(-2147483412);
//	cout << ' ' << s.reverse(-2143847412);
//	cout << '\n';
//	cout << s.reverse(max_pos);
//	cout << ' ' << s.reverse(max_neg);
	for (int i = 0; i < checks.size(); i++) {
		int check = checks[i];
		int checkSol = s.reverse(checks[i]);
		int validationNo = sols[i];
		if (checkSol == sols[i])
			cout << i << " YES" << '\n';
		else
			cout << i << " NO" << '\n';
	}

}
