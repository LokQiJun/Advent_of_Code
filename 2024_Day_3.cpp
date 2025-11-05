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
#include <regex>
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
vl splitToInts(const string& str);
int check_vec(vl inputs);

struct Mul {
    int x;
    int y;
    size_t pos;
    bool active;
};
vector<Mul> findMulCalls(const string& input);

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); /*
  FILE* stream;
	freopen_s(&stream, "input.txt", "r", stdin);
	freopen_s(&stream, "output.txt", "w", stdout); //*/
	long a, b, c, d, n, count, max;
    char c1, c2, c3;
    bool flag1, flag2, flag3;
    string s1, s2, s3;
    vl vl_1, temp;

  a=0, b=0;s2 = "";
  
  while(getline(cin, s1)){
    s2 += s1;
  }
  
  auto calls = findMulCalls(s2);
  for (const auto& m : calls) {
      a += m.x * m.y;
      if(m.active == true) b += m.x*m.y;
      cout << "Found: " << m.x << ' ' << m.y << ' ' << m.active << ' ' << m.pos << endl; 
  }
  cout << a << ' ' << b;
  

	return 0;
}

vector<Mul> findMulCalls(const string& input) {
    vector<Mul> result;

    // Regex for mul(x,y) with integers up to 3 digits
    // regex mulPattern(R"(mul\(\s*([+-]?\d{1,3})\s*,\s*([+-]?\d{1,3})\s*\))");
    regex mulPattern(R"([^\w]?mul\(\s*([+-]?\d{1,3})\s*,\s*([+-]?\d{1,3})\s*\))");

    // Regex for control keywords "do" or "dont"
    regex controlPattern(R"(don't|do)");

    // Store positions of all control keywords
    vector<pair<size_t, string>> controls; 
    for (auto it = sregex_iterator(input.begin(), input.end(), controlPattern);
         it != sregex_iterator(); ++it) {
        controls.push_back({static_cast<size_t>(it->position()), it->str()});
        size_t pos = it->position();
        string keyword = it->str();
        cout << keyword << " at index " << pos << "\n";
    }

    // Iterate over all mul(x,y)
    for (auto it = sregex_iterator(input.begin(), input.end(), mulPattern);
         it != sregex_iterator(); ++it) {

        size_t mulPos = static_cast<size_t>(it->position(0)); cout << mulPos << endl;
        int x = stoi((*it)[1]);
        int y = stoi((*it)[2]);

        // Find nearest preceding control keyword
        string lastControl = "do";
        for (auto &c : controls) {
            if (c.first < mulPos)
                lastControl = c.second;
            else
                break;
        }

        bool active = (lastControl == "do");
        result.push_back({x, y, mulPos, active});
    }

    return result;
}