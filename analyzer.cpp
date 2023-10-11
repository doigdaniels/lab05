// Cameron Daniels
// 10/15/23
// Partner: Richard Sun

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <string>
#include "StringData.h"

using namespace std;

int linear_search(vector<string> container, string element) {
  for (int i = 0; i < container.size(); i++) {
    if (container.at(i) == element) {
      return i;
    }
  }

  return -1;
}

int binary_search(vector<string> container, string element) {
  int l = 0;
  int m = container.size() / 2;
  int r = container.size();

  while (l < r) {
    if (element > container.at(m)) {
      l = m + 1;
    }
    else {
      r = m;
    }
    m = (l + r) / 2;
  }

  if (container.at(l) == element) {
    return l;
  }
  
  return -1;
}

int main() {
  vector<string> data = getStringData();

  int start_time = systemTimeNanoseconds();
  int i = linear_search(data, "not_here");
  int time_diff = systemTimeNanoseconds() - start_time;
  cout << "Linear search found not_here at " << i << " in " << time_diff << " nanoseconds" << endl;

  start_time = systemTimeNanoseconds();
  i = binary_search(data, "not_here");
  time_diff = systemTimeNanoseconds() - start_time;
  cout << "Binary search found not_here at " << i << " in " << time_diff << " nanoseconds" << endl;

  start_time = systemTimeNanoseconds();
  i = linear_search(data, "aaaaa");
  time_diff = systemTimeNanoseconds() - start_time;
  cout << "Linear search found aaaaa at " << i << " in " << time_diff << " nanoseconds" << endl;

  start_time = systemTimeNanoseconds();
  i = binary_search(data, "aaaaa");
  time_diff = systemTimeNanoseconds() - start_time;
  cout << "Binary search found aaaaa at " << i << " in " << time_diff << " nanoseconds" << endl;

  start_time = systemTimeNanoseconds();
  i = linear_search(data, "mzzzz");
  time_diff = systemTimeNanoseconds() - start_time;
  cout << "Linear search found mzzzz at " << i << " in " << time_diff << " nanoseconds" << endl;

  start_time = systemTimeNanoseconds();
  i = binary_search(data, "mzzzz");
  time_diff = systemTimeNanoseconds() - start_time;
  cout << "Binary search found mzzzz at " << i << " in " << time_diff << " nanoseconds" << endl;


  return 0;
}