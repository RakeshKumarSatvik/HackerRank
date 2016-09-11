//============================================================================
// Name        : Add1_Multiply2.cpp
// Author      : Rakesh Kumar Satvik
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int count, number, add1, multiply2;

	cin >> count;

	for(int i = 0; i < count; i++) {
		cin >> number;
		add1 = 0;
		multiply2 = 0;
		while(number) {
			if(number % 2 == 0) {
				multiply2++;
				number /= 2;
			} else {
				number -= 1;
				add1++;
			}
		}
		cout << add1+multiply2 << endl;
	}
	return 0;
}
