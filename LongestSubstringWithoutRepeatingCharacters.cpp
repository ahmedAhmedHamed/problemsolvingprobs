//
// Created by Stan on 11/7/2023.
//
#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
	// can do  dynamic approach, probably.
	// this approach is O(n^2).
	// checking if a character was there before and marking as existing is O(1).
	// best case can be improved to O(n) when the entire array is comprised of unique characters.
	int lengthOfLongestSubstring(string s) {
		int possibleCharacters[255];
		int sequenceNumber = 1;
		int currentSequenceSize = 0;
		int maxSequenceSize = 0;
		int currentCharacterValue;
		for (int i = -128; i < 128; i ++) {
			possibleCharacters[i] = -1;
		}
		for (int i = 0; i < s.length(); i++) {
			sequenceNumber = i;
			currentSequenceSize = 0;
			for (int j = i; j < s.length(); j++) {
				currentCharacterValue = int(s[j]);
				if (possibleCharacters[currentCharacterValue] == sequenceNumber) {
					maxSequenceSize = max(maxSequenceSize, currentSequenceSize);
					break;
				}
				possibleCharacters[currentCharacterValue] = sequenceNumber;
				currentSequenceSize++;
				maxSequenceSize = max(maxSequenceSize, currentSequenceSize);
			}
		}
		maxSequenceSize = max(maxSequenceSize, currentSequenceSize);
		maxSequenceSize = max(0, maxSequenceSize);
		return maxSequenceSize;
	}
};


int main() {
	int sol;
	Solution solver = Solution();
	sol = solver.lengthOfLongestSubstring("12312321123");
	cout << sol << '\n';
	sol = solver.lengthOfLongestSubstring("1231232112345");
	cout << sol << '\n';
	sol = solver.lengthOfLongestSubstring("");
	cout << sol << '\n';
	sol = solver.lengthOfLongestSubstring("123");
	cout << sol << '\n';
	sol = solver.lengthOfLongestSubstring("12312365");
	cout << sol << '\n';
	cout << INT_MAX;
}