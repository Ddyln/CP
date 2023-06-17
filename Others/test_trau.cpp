#include <iostream>
#include <vector>
using namespace std;

int countPalindromicSubstrings(const string& s) {
    string modified_s = "#";
    for (char c : s) {
        modified_s += c;
        modified_s += '#';
    }

    int n = modified_s.length();
    vector<int> p(n, 0); // Array to store palindrome lengths
    int center = 0, right = 0, result = 0;

    for (int i = 1; i < n - 1; i++) {
        if (i < right) {
            // Take advantage of previously computed palindrome lengths
            int mirror = 2 * center - i;
            p[i] = min(right - i, p[mirror]);
        }

        // Expand palindrome around the current center
        while (modified_s[i + 1 + p[i]] == modified_s[i - 1 - p[i]]) {
            p[i]++;
        }

        // Update the right boundary and center if necessary
        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }

        // Accumulate the count of palindromes
        result += (p[i] + 1) / 2;
    }

    return result;
}

int main() {
    string s = "ababa";
    int count = countPalindromicSubstrings(s);
    cout << count << endl; // Output: 9

    return 0;
}
