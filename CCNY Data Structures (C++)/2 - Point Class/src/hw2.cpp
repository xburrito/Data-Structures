#include "hw2.h"
#include <iostream>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>

// Put your functions/prototype here
	//Constructor
	Point::Point(){
		x = 0;
		y = 0;
		z = 0;
	}
	//Constructor used if z is not given a value
	Point::Point(double inX, double inY, double inZ){
		x = inX;
		y = inY;
		z = inZ;
	}
	//Copy Constructor
	Point::Point(const Point& inPt){
		x = inPt.x;
		y = inPt.y;
		z = inPt.z;
	}

	//Set Functions
	void Point::setX(double inX){
		x = inX;
	}
	void Point::setY(double inY){
		y = inY;
	}
	void Point::setZ(double inZ){
		z = inZ;
	}
	void Point::setXY(double inX, double inY){
		x = inX;
		y = inY;
	}
	void Point::setXYZ(double inX, double inY, double inZ){
		x = inX;
		y = inY;
		z = inZ;
	}

	//Get Functions
	double Point::getX() const{
		return x;
	}
	double Point::getY() const{
		return y;
	}
	double Point::getZ() const{
		return z;
	}

	//Prints out the point as (x,y,z)
	void Point::print(){
		cout << "(" << x << ", " << y << ", " << z << ")" << endl;
	}

	//Calculates and returns the distance between the origin and the point
	double Point::distance(){
		double dist;
		dist = pow(x, 2) + pow(y, 2) + pow(z, 2);
		dist = sqrt(dist);
		return dist;
	}

	//Calculates and returns the distance between two points
	double Point::distance(const Point& pt2) const{
		double dist;
		dist = pow(pt2.x - x, 2) + pow(pt2.y - y, 2) + pow(pt2.z - z, 2);
		dist = sqrt(dist);
		return dist;
	}

	// Checks to see if the point is at the origin (0,0,0)
	bool Point::origin(){
		if(x == 0 && y == 0 && z == 0){
			return true;
		}
		else
			return false;
	}

	//Checks to see if the two points lie on the same line as point and origin
	bool Point::line(Point pt2){
		double point1, point2;

		point1 = y / x;
		point2 = (pt2.y) / (pt2.x);
		if(point1 == point2){
			return true;
		}
		else
			return false;
	}
	//Calculates the cross product of point 1 and point 2 and returns as point 3. 
	Point Point::cross(Point pt2){
		Point pt3;
			pt3.x = (y * pt2.z) - (z * pt2.y);
			pt3.y = (z * pt2.x) - (x * pt2.z);
			pt3.z = (x * pt2.y) - (y * pt2.x);
		return pt3;
	}

Point operator+(const Point& pt1, const Point& pt2) {
		double xSum = pt1.getX() + pt2.getX();
		double ySum = pt1.getY() + pt2.getY();
		double zSum = pt1.getZ() + pt2.getZ();
		Point pointSum(xSum,ySum,zSum);
	return pointSum;
}

Point operator-(const Point& pt1, const Point& pt2) {
		double xdiff = pt1.getX() - pt2.getX();
		double ydiff = pt1.getY() - pt2.getY();
		double zdiff = pt1.getZ() - pt2.getZ();
		Point pointdiff(xdiff,ydiff,zdiff);
	return pointdiff;
}

istream& operator>>(istream& ins, Point& target){
		ins >> target.x >> target.y >> target.z;
	return ins;
}

ostream& operator<<(ostream& outs, const Point& source){
	outs << "(" << source.x << ", " << source.y << ", " << source.z << ")" << endl;
}

bool plane(const Point pts[], const Point& target){
	bool Plane = false;
	Point uVec = pts[1] - pts[0];
	Point vVec = pts[2] - pts[0];
	Point crossUV = uVec.cross(vVec);
		for(size_t i = 0; i < 3; i++){
			double checkXpt = target.getX() - pts[i].getX();
			double checkYpt = target.getY() - pts[i].getY();
			double checkZpt = target.getZ() - pts[i].getZ();
			if(!((crossUV.getX() * checkXpt) + (crossUV.getY() * checkYpt) + (crossUV.getZ() * checkZpt))){
				Plane = true;
			}
		}
	return Plane;
}

bool square(const Point pts[], const size_t size){
	if(size >= 4){
		size_t i = 0;
		size_t j = 0;
		size_t breakOff = size - 3;
		
		for(i = 0; i < breakOff; i++){
			double lineOne = pts[i].distance(pts[i+1]);
			double lineTwo = pts[i+1].distance(pts[i+2]);
			double lineThree = pts[i+2].distance(pts[i+3]);
			double lineFour = pts[i+3].distance(pts[i]);
			double diagOne = pts[i].distance(pts[i+2]) * sqrt(2);
			double diagTwo = pts[i+1].distance(pts[i+3]) * sqrt(2);

			if((lineOne == lineThree) && (lineTwo == lineFour)){
				if(diagOne == diagTwo)
					return true;
			}
		}
		for(j = i; j < size; j++){
			size_t pt2 = 0, pt3 = 0, pt4 = 0;
			if(j == i){
				pt2 = j+1;
				pt3 = j+2;
				pt4 = 0;
			}
			else if(j == i+1){
				pt2 = j+1;
				pt3 = 0;
				pt4 = 1;
			}
			else if(j == i+2){
				pt2 = 0;
				pt3 = 1;
				pt4 = 2;
			}

			double lineOne = pts[j].distance(pts[pt2]);
			double lineTwo = pts[pt2].distance(pts[pt3]);
			double lineThree = pts[pt3].distance(pts[pt4]);
			double lineFour = pts[pt4].distance(pts[j]);
			double diagOne = pts[j].distance(pts[pt3]) * sqrt(2);
			double diagTwo = pts[pt2].distance(pts[pt4]) * sqrt(2);

			if((lineOne == lineThree) && (lineTwo == lineFour)){
				if(diagOne == diagTwo)
					return true;
			}
		}
		return false;
	}
	else
		return false;
}

Point centroid(const Point pts[], const size_t size){
	Point origin(0,0,0);
	if(size == 0)
		return origin;
	double midX, midY, midZ;
	for(size_t i = 0; i < size; i++){
		midX += pts[i].getX();
		midY += pts[i].getY();
		midZ += pts[i].getZ();
	}
	Point cent(midX/size, midY/size, midZ/size);
	return cent;
}
