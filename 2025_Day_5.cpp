#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <sstream>
using namespace std;

typedef vector<pair<long, long>> vpll;
long checkRange(vpll inputs, vector<long> ids);
long countRange(vpll inputs);

int main(){
  long a, b, c, d, count1=0, count2=0;
  string s1, s2, s3;
  char c1, c2, c3;
  
  vpll inputs;
  vector<string> tokens;
  vector<long> ids;
  
  while(cin >> s1){
    
    if (s1.find('-') == s1.npos) break;
    
    stringstream ss(s1);
    while (getline(ss, s2, '-')) {
        tokens.push_back(s2);  // Add the token to the result vector
    }
    
    inputs.push_back(make_pair(stol(tokens[0]), stol(tokens[1])));
    
    tokens.clear();
  }
  
  ids.push_back(stol(s1));
  while(cin >> a){
    ids.push_back(a);
  }
  
  sort(ids.begin(), ids.end());
  sort(inputs.begin(), inputs.end());
  // for(auto pair: inputs) cout << pair.first << ' ' << pair.second << endl;
  // for(auto id: ids) cout << id << endl;
  
  count1 = checkRange(inputs, ids);
  count2 = countRange(inputs);
  
  cout << endl << count1 << ' ' << count2;
  
  return 0;
}

long checkRange(vpll inputs, vector<long> ids) {
  long count = 0;
  long index = 0;
  for(int i = 0; i < ids.size(); i++) {
    if(index == inputs.size()) break;
    
    // cout << inputs[index].first << ' ' << inputs[index].second << ' ' << ids[i] << endl;
    
    if(inputs[index].first <= ids[i] && inputs[index].second >= ids[i]) count++;
    
    if(inputs[index].first > ids[i]) continue;
    if(inputs[index].first < ids[i] && inputs[index].second < ids[i]) {index++;i--;}
  }
  return count;
}

/*
long countRange(vpll inputs) {
  long count = 0;
  long index = 0;
  
  map<long, bool> rangeEle;
  
  for(auto input: inputs) {
    for(long i = input.first; i <= input.second; i++){
      rangeEle[i] = true;
    }
    
  return (long) rangeEle.size();
  }
}
/*/

long countRange(vpll inputs) {
    long total = 0;
    long curL = inputs[0].first;
    long curR = inputs[0].second;

    for (int i = 1; i < inputs.size(); i++) {
        long L = inputs[i].first;
        long R = inputs[i].second;

        if (L > curR + 1) {
            // gap → finalize previous segment
            total += (curR - curL + 1);
            curL = L;
            curR = R;
        } else {
            // overlap / touching → merge
            curR = max(curR, R);
        }
    }

    // final merged range
    total += (curR - curL + 1);
    return total;
}
