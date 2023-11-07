//
// Created by Stan on 11/7/2023.
//

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		int tempidx;
		if (needle.length() > haystack.length())
			return -1;
		for (int i = 0; i < haystack.length(); i++) {
			tempidx = i;
			for (int j = 0; j < needle.length(); j++) {
				if (tempidx >= haystack.length())
					return -1;
				if (haystack[tempidx] != needle[j])
					break;
				tempidx++;
				if (j == needle.length() - 1)
					return i;
			}
		}
		return -1;
	}
};

int main() {
	int strstr = Solution().strStr("12312321123", "321");
	cout << strstr;
}
