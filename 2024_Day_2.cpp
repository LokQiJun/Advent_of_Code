#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <sstream>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <iterator>
#include <ranges>
using namespace std;
typedef vector<long> vl;
typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<vl> vvl;
typedef pair <long, string> pls;
typedef pair <string, long> psl;
typedef pair<string, string> pss;
typedef pair <long, long> pll;
typedef vector<pls> vls;
typedef vector<psl> vsl;
typedef vector<pll> vll;
typedef tuple<int, int, int, int, int> ti_v;
typedef tuple<int, int, int> ti_t;
typedef vector<ti_v> vti_v; // get<0>(tuple name)
typedef vector<ti_t> vti_t;
typedef vector<vll> vvll;
long z;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); //*
	FILE* stream;
	freopen_s(&stream, "input.txt", "r", stdin);
	freopen_s(&stream, "output.txt", "w", stdout); //*/
	long a, b, c, d, n, count, max; string temp;
    char c1, c2, c3;
    bool flag;
    string s1, s2, s3;
    vl vl_1;

    // Part 1
    a = 0;
    while(cin >> s1) {
        for (auto part : s1 | views::split(' ')) {
            string token(part.begin(), part.end());
            vl_1.push_back(stoi(token));
        }
        flag = false;
        for(int i = 0; i < vl_1.size(); i++){
            
        }
        if(flag == false) a++;

        vl_1.clear()
    }
    cout << a;

	return 0;
}