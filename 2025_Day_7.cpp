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
#include <set>
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
typedef priority_queue< pll, vll, greater<pll>> pq;
long z;

void addBeam(pq &beam_list, map<pll, long> &seen_beam, pll new_beam, long a, long n, long ways);

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); 
	long a, b, c, d, n, count1=0, count2=0, max;
  char c1, c2, c3;
  bool flag1, flag2;
  string s1, s2, s3, temp;
  vl vl_1;
  vvl vvl_1;
  pq pos_pq, beam_list; // pos: distance, position beam_list: distance, position
  map<pll, long> seen_beam; pll new_beam;
  set<long> straight_beam;

  cin >> s1;
  n = s1.find('S'); //Look for starting S, guaranteed
  beam_list.push(make_pair(a+2, n));
  seen_beam[{a+2, n}] = 1;
  n = s1.length();
  
  //Find ^ and store location in a priority queue
  a=1;
  while(cin >> s1){
    size_t pos = s1.find('^');
    while (pos != string::npos) {
        pos_pq.push(make_pair(a, pos));
        pos = s1.find('^', pos + 1);
    }
    a++;
  }
  // cout << "Length: " << n << " Distance: " << a << endl;
  
  // while (!pos_pq.empty()) {
  //     auto p = pos_pq.top();
  //     cout << p.first << " " << p.second << endl;
  //     pos_pq.pop();
  // }
  
  /*
  2 set: one for beam, one for spliiter
  if distance(first) of beam > spliiter, no chance of hitting spliiter, pop from splitter
  if distance(first) of beam <= spliiter, check for position:
    case 1: pos of beam == pos of splitter: (beam hit splitter)
      count1+=1, 
      add new beam = spliiter.first + 2 & spliiter.second +/- 1
      pop beam, pop splitter
    case 2: pos of beam < pos of splitter: (beam to left of splitter, no chance of hitting any splitter this row)
      add new beam = beam.first + 2 & beam.second
      pop beam
    case 3: pos of beam > pos of splitter: (beam to the right of splitter, no chance of splitter being hit)
      pop splitter
  when adding beam, check the following:
    new_beam.first is <= a(max_distance from inputs)
    new_beam.second is >= 0 && < n(max length of string)
  */
  while(!beam_list.empty() && !pos_pq.empty()) {
    auto beam = beam_list.top();
    auto splitter = pos_pq.top();
    if(beam.first > splitter.first) pos_pq.pop();
    else if(beam.first <= splitter.first) {
      if(beam.second == splitter.second) {
        count1++; 
        
        long ways = seen_beam[beam];
        new_beam.first = beam.first+2;
        new_beam.second = beam.second-1;
        addBeam(beam_list, seen_beam, new_beam, a, n, ways);
        new_beam.first = beam.first+2;
        new_beam.second = beam.second+1;
        addBeam(beam_list, seen_beam, new_beam, a, n, ways);
        
        beam_list.pop();
        pos_pq.pop();
      } else if(beam.second > splitter.second) {
        pos_pq.pop();
      } else if(beam.second < splitter.second) {
        long ways = seen_beam[beam];
        new_beam.first = beam.first+2;
        new_beam.second = beam.second;
        addBeam(beam_list, seen_beam, new_beam, a, n, ways);
        
        beam_list.pop();
      }
    }
  }
  
  for (auto &p : seen_beam) {
    long row = p.first.first;  
    long ways = p.second;      
    if (row >= a) count2 += ways;
  }

  cout << endl << count1 << ' ' << count2;

	return 0;
}

void addBeam(pq &beam_list, map<pll, long> &seen_beam, pll new_beam, long a, long n, long ways) {
  if(new_beam.first > a) return;
  if(new_beam.second < 0 || new_beam.second >= n) return;
  
  seen_beam[new_beam] += ways;
  if(seen_beam[new_beam] == ways) beam_list.push(new_beam);
}
