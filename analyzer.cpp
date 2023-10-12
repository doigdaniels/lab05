
/*
 * Richard Sun
 * Partner: Cameron Daniels
 * 10/11/23
*/

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

int binary_search(vector<string> container,string element) {
    int left = 0;
    int right = container.size() - 1;
    //breaks when left and right point to the same element
    while (left < right) {
        //calculate the midpoint
        int mid = (left + right) / 2;
        //check if element is in the lower half
        if (element < container[mid]) {
            //restrict the search area to the lower half
            right = mid;
            //check if element is in the upper half
        } else if (element > container[mid]) {
            //restrict the search area to the upper half
            left = mid + 1;
            //check if it is the element
        } else if (container[mid] == element) {
            //return the index
            return mid;
        }
    }
    //return -1 if not found
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
