/*file:		Point.h
* by:		Sebastian Campos
* org:		COP 2001,202101, 10409
* desc:		desc: declaration of a point class object
*/
#ifndef POINT_H
#define POINT_H

class Point
{
private:
	float xCoordinate;
	float yCoordinate;

public:
	// constructors
	Point();	// default constructor
	Point(float xCoordinate, float yCoordinate);	// property constructor
	Point(Point* point);		// copy constructor

	//getters
	//accessors
	float getXCoor();
	float getYCoor();

	//setters
	void setXCoor(float value);
	void setYCoor(float value);



};
#endif POINT_H
