//============================================================================
// Name        : Sub_Array.cpp
// Author      : Rakesh Kumar Satvik
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

void printPowerSet(int *set, int set_size, int gk)
{
    vector<int> out;
    vector<pair<int, int> > apair;
    pair<int, int> result, tt;
    int sum = 0;
    int temp;
    for(int i = 0; i < set_size; i++) {
    	for(int j = 0; j < set_size; j++) {
    		sum = 0;
    		for(int k = i; k <= j; k++) {
    			sum += set[k];
				if(sum <= gk) {
					if(apair.size() != 0) {
						temp = k - i;
						tt = apair.back();
						if(temp > (tt.second - tt.first)) {
							apair.push_back(make_pair(i,k));
						}
					} else {
						apair.push_back(make_pair(i,k));
					}
				}
			}
		}
    }
    int i,j;
    result = apair.back();
    i = result.first;
    j = result.second;
    cout << "i " << i << " j " << j << endl;
    for(int k = i; k <= j; k++) {
    	cout << set[k] << " ";
    }
}
int main() {
	int set[] = {1,2,3};
	printPowerSet(set, 3, 4);

	return 0;
}
