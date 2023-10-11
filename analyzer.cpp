/*
 * Richard Sun
 * Partner: Cameron Daniels
 * 10/11/23
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <string>
#include <vector>
#include <chrono>
inline long long systemTimeNanoseconds()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::time_point_cast<std::chrono::milliseconds>(
                    std::chrono::system_clock::now()
            ).time_since_epoch()
    ).count();
}
inline std::vector<std::string>& getStringData()
{
    static std::vector<std::string> stringDataSet;
    if (stringDataSet.size() == 0)
    {
        char tempSet[6] = " ";
        for (tempSet[0] = 'a'; tempSet[0] <= 'z'; tempSet[0]++)
            for (tempSet[1] = 'a'; tempSet[1] <= 'z'; tempSet[1]++)
                for (tempSet[2] = 'a'; tempSet[2] <= 'z'; tempSet[2]++)
                    for (tempSet[3] = 'a'; tempSet[3] <= 'z'; tempSet[3]++)
                        for (tempSet[4] = 'a'; tempSet[4] <= 'z'; tempSet[4]++)
                            stringDataSet.push_back(std::string(tempSet));
    }
    return stringDataSet;
}
int linear_search(vector<string> container,string element) {
    for(int i=0;i<container.size();i++){
        if (container[i]==element){
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
    vector<string> stringData=getStringData();
    cout<<"finished generating"<<endl;
    cout<<"Linear Search"<<endl;
    cout<<"not_here"<<endl;
    long long start=systemTimeNanoseconds();
    cout<<"Index "<<linear_search(stringData,"not_here")<<endl;
    cout<<"Took "<<systemTimeNanoseconds()-start<<" nanoseconds"<<endl;
    cout<<"aaaaa"<<endl;
    start=systemTimeNanoseconds();
    cout<<"Index "<<linear_search(stringData,"aaaaa")<<endl;
    cout<<"Took "<<systemTimeNanoseconds()-start<<" nanoseconds"<<endl;
    cout<<"mzzzz"<<endl;
    start=systemTimeNanoseconds();
    cout<<"Index "<<linear_search(stringData,"mzzzz")<<endl;
    cout<<"Took "<<systemTimeNanoseconds()-start<<" nanoseconds"<<endl;
    cout<<"Binary Search"<<endl;
    start=systemTimeNanoseconds();
    cout<<"Index "<<binary_search(stringData,"not_here")<<endl;
    cout<<"Took "<<systemTimeNanoseconds()-start<<" nanoseconds"<<endl;
    cout<<"aaaaa"<<endl;
    start=systemTimeNanoseconds();
    cout<<"Index "<<binary_search(stringData,"aaaaa")<<endl;
    cout<<"Took "<<systemTimeNanoseconds()-start<<" nanoseconds"<<endl;
    cout<<"mzzzz"<<endl;
    start=systemTimeNanoseconds();
    cout<<"Index "<<binary_search(stringData,"mzzzz")<<endl;
    cout<<"Took "<<systemTimeNanoseconds()-start<<" nanoseconds"<<endl;

    return 0;
}
