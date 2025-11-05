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
vl splitToInts(const string& str);
int check_vec(vl inputs);

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); //*
	FILE* stream;
	freopen_s(&stream, "input.txt", "r", stdin);
	freopen_s(&stream, "output.txt", "w", stdout); //*/
	long a, b, c, d, n, count, max;
    char c1, c2, c3;
    bool flag1, flag2, flag3;
    string s1, s2, s3;
    vl vl_1, temp;

    // Part 1
    a = 0, b = 0;
    while(getline(cin, s1)) {
        vl_1 = splitToInts(s1);
        n = check_vec(vl_1);
        
        //Part 1
        if (n == -1) a++, b++;
        //else cout << "Line " << vl_1[0] << vl_1[1] << " is not safe\n";
        
        //Part 2
        else {
          if(n != 0) {
            temp = vl_1;
            temp.erase(temp.begin() + (n-1));
            c = check_vec(temp);
            temp.clear();
            if(c == -1) {b++; continue;};
          }
          temp = vl_1;
          temp.erase(temp.begin() + (n));
          c = check_vec(temp);
          temp.clear();
          if(c == -1) {b++; continue;};
          temp = vl_1;
          temp.erase(temp.begin() + (n+1));
          c = check_vec(temp);
          temp.clear();
          if(c == -1) {b++; continue;};
        }
        
        vl_1.clear();
    }
    cout << a << ' ' << b;

	return 0;
}

vl splitToInts(const string& str) {
    vl result; char delimiter = ' ';
    stringstream ss(str);
    string temp;

    while (getline(ss, temp, delimiter)) {
        if (!temp.empty()) { // avoid empty segments
            result.push_back(stoi(temp));
        }
    }
    return result;
}

int check_vec(vl vl_1){
  bool flag1, flag2, flag3;
  flag1 = false, flag2 = false;
  if(vl_1[0] == vl_1[1]) return 0;
  else if(vl_1[0] < vl_1[1]) flag2 = false;
  else if(vl_1[0] > vl_1[1]) flag2 = true;
  for(int i = 0; i < vl_1.size()-1; i++){
      if(vl_1[i] == vl_1[i+1]) return i;
      else if(vl_1[i] < vl_1[i+1] && flag2 == true) return i;
      else if(vl_1[i] > vl_1[i+1] && flag2 == false) return i;
      else if (abs(vl_1[i] - vl_1[i+1]) >= 4) return i;
  }
  return -1;
}