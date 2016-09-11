//============================================================================
// Name        : HackerRank.cpp
// Author      : Rakesh Kumar Satvik
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
using namespace std;

class Point2D {
public:

	//Constructor
	Point2D();
	Point2D(int a, int b) {
		x = a;
		y = b;
	}

	//Accessor Function
	double dist2D(Point2D p){
		return ceil(sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y)));
	}

	void printDistance(double d) {
		cout << "2D distance = " << d << endl;
	}

protected:
	int x;
	int y;
};

class Point3D: public Point2D {
public:
	//constructor
	Point3D();
	Point3D(int a, int b, int c)
	: Point2D(a, b) {
		z = c;
	}
	//Accessor Function
	double dist3D(Point3D p) {
		return ceil(sqrt((p.x - x) * (p.x - x) + (p.y - y) * (p.y - y) + (p.z - z) * (p.z - z)));
	}

	void printDistance(double d) {
		cout << "3D distance = " << d << endl;
	}
protected:
	int z;
};

int main() {
	int a,b,c;
	cin >> a;
	cin >> b;
	cin >> c;
	Point3D p1 = Point3D(a,b,c);

	cin >> a;
	cin >> b;
	cin >> c;
	Point3D p2 = Point3D(a,b,c);


	double d1 = p1.dist2D(p2);
	double d2 = p1.dist3D(p2);

	Point2D p = Point2D(0,0);

	p = p1;
	p.printDistance(d1);
	p1.printDistance(d2);
	return 0;
}
