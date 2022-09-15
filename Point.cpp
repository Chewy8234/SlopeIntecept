/*file:		SlopeInterceptFinal.cpp
* by:		Sebastian Campos
* org:		COP 2001,202101, 10409
* desc:		implemnentaton of the point class
*/

#include "Point.h"


Point::Point()
{
	xCoordinate = (float)0.0;
	yCoordinate = (float)0.0;
}


/**
* properties constructor - initalize to parameter values
*/

Point::Point(float xCoordinate, float yCoordinate)
{
	this->xCoordinate = xCoordinate;
	this->yCoordinate = yCoordinate;
}

Point::Point(Point* point)
{
	xCoordinate = point->xCoordinate;
	yCoordinate = point->yCoordinate;
}

// getters
float Point::getXCoor() { return xCoordinate; }
float Point::getYCoor() { return yCoordinate; }

//setters
void Point::setXCoor(float value) { xCoordinate = value; }
void Point::setYCoor(float value) { yCoordinate = value; }
