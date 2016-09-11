//============================================================================
// Name        : ValidBst.cpp
// Author      : Rakesh Kumar Satvik
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
	vector<int> min, max;
	int count, temp, flag = 0, loop;
	int min_flag = 0, min_so_far;
	cin >> loop;
	for(int j = 0; j < loop; j++) {
		cin >> count;
		flag = 0;
		min_flag = 0;
		min.clear();
		max.clear();
		min_so_far = INT_MIN;

		for(int i = 0; i < count; i++) {
			cin >> temp;
			if(flag)
				continue;

			if(min.size() == 0 || min.back() > temp) {
				if(min_flag == 1 || temp < min_so_far){
					flag = 1;
					continue;
				}
				min.push_back(temp);
			} else if(max.size() == 0 || max.back() <= temp) {
				if(max.size() != 0)
					min.push_back(max.back());
				max.push_back(temp);
				min_flag = 1;
			} else if(temp < max.back() and temp > min.back()) {
					min_so_far = min.back();
					min.push_back(temp);
					min_flag = 0;
			} else {
				flag = 1;
				break;
			}
		}
		if (flag)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}
