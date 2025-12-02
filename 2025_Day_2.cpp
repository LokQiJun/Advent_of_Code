#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef vector<pair<long, long>> vll;

vll parseRanges(const string& input);
bool checkNum(long num);
bool checkRepeatNum(long num);

int main() {
    long count1 = 0, count2 = 0;
    string s1;

    // Read the input string
    cin >> s1;

    // Parse the ranges from the input
    vll input = parseRanges(s1);

    // Process each pair in the parsed input ranges
    for (auto& range : input) {
        for (long i = range.first; i <= range.second; i++) {
            if (checkNum(i)) {
                count1 += i;  // Add to count1 if the number satisfies the condition
            }
            if (checkRepeatNum(i)) {
                count2 += i;  // Add to count1 if the number satisfies the condition
            }
        }
    }

    cout << count1 << ' ' << count2 << endl;
    return 0;
}

// Optimized range parsing
vll parseRanges(const string& input) {
    vll result;
    size_t start = 0;

    while (true) {
        size_t commaPos = input.find(',', start);
        size_t endPos = (commaPos == string::npos) ? input.length() : commaPos;

        size_t hyphenPos = input.find('-', start);
        long a = stol(input.substr(start, hyphenPos - start));
        long b = stol(input.substr(hyphenPos + 1, endPos - hyphenPos - 1));

        result.emplace_back(a, b);

        if (commaPos == string::npos) break;
        start = commaPos + 1;
    }

    return result;
}

// Optimized checkNum function without converting number to string
bool checkNum(long num) {
    // Find the number of digits
    int len = log10(num) + 1;

    // If the number of digits is odd, it cannot be split evenly
    if (len % 2 != 0) {
        return false;
    }

    // Get the first half and second half of the number without converting to string
    long divisor = pow(10, len / 2);
    long firstHalf = num / divisor;
    long secondHalf = num % divisor;

    return firstHalf == secondHalf;
}


bool checkRepeatNum(long num) {
    int n = log10(num) + 1;
    
    string id = to_string(num);

    // Check all possible lengths for the repeating substring
    for (int m = 1; m <= n / 2; ++m) {
        if (n % m == 0) {  // m must divide the length of the ID
            std::string repeat_substr = id.substr(0, m);
            std::string repeated = "";

            // Repeat the substring (n / m) times to reconstruct the original string
            for (int i = 0; i < n / m; ++i) {
                repeated += repeat_substr;
            }

            // If the reconstructed string matches the ID, it's invalid
            if (repeated == id) {
                return true;
            }
        }
    }

    return false;  // If no valid repeating substring is found, it's a valid ID
}
