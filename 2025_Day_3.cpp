#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

typedef vector<pair<char,long>> vpcl;

void recurr(string& s1, vpcl inputs, int remain, int prevPos, int str_length);

int main() {
  string s1, s2, s3;
  char c1, c2;
  long a, b, c, d, count1 = 0, count2 = 0;
  vpcl inputs;

  while(cin >> s1) {
    
    for(int i = 0; i < s1.length(); i++) 
      inputs.push_back(make_pair(s1[i], i+1));
    
    // for(auto inn: inputs) cout << inn.first << ' ' << inn.second << endl;
    
    sort(inputs.begin(), inputs.end(),
     [](const auto &a, const auto &b) {
         if (a.first != b.first)
             return a.first > b.first;   // DESCENDING on first
         return a.second < b.second;     // ASCENDING on second
     });
     
    s2 = "";
    recurr(s2, inputs, 2, 0, inputs.size());
    count1 += stol(s2);
    s2 = "";
    recurr(s2, inputs, 12, 0, inputs.size());
    count2 += stol(s2);
    // cout << s2 << endl;
    // for(auto inn: inputs) cout << inn.first << ' ' << inn.second << endl;
    
    inputs.clear();
  }
  
  cout << count1 << ' ' << count2;
  
  return 0;
}

void recurr(string& s1, vpcl inputs, int remain, int prevPos, int str_length){
  // cout << s1 << "  " << remain << endl;
  if(remain == 0) return;
  for(auto pairs: inputs){
    if(str_length - pairs.second >= remain-1 && pairs.second > prevPos) {
      s1 += pairs.first;
      recurr(s1, inputs, remain-1, pairs.second, str_length);
      break;
    }
  }
}
