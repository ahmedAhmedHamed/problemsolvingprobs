//
// Created by Stan on 11/7/2023.
//
#include <iostream>
using namespace std;
class Solution {
public:
	// x ^ n
	// O(log n)
	double myPow(double x, int n) {
		if (x == 0)
			return 0;
		if (x == 1)
			return 1;
		if (n == 0)
			return 1;
		if (n == 1)
			return x;
		if (n == -1)
			return 1 / x;
		if (n % 2 == 0) {
			double temp = myPow(x, n/2);
			return (temp * temp);
		}
		else
			return (x * myPow(x, n - 1));
	}
};

int main() {
	Solution s;
	cout << s.myPow(2.1, -3);
}
