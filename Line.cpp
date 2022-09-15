/*file:		SlopeInterceptFinal.cpp
* by:		Sebastian Campos
* org:		COP 2001,202101, 10409
* desc:		Calculating line variables
*/
#include <math.h>			//  calculate the math functions
#include <iostream>			//  console input output
#include "Line.h"


const float PI = 3.14159265;		// used for PI

// constructors
// ********************************************************
/**
* default constructor
*/

Line line = Line();

Line::Line()
{
	pointOne = Point();
	pointTwo = Point();
}

/**
* properties constructor - initalize to parameter values
*/

Line::Line(Point* firstPoint, Point* secondPoint)
{
	this->pointOne = firstPoint;
	this->pointTwo = secondPoint;
}

Line::Line(Point* point, float slope)
{
	this->pointOne = point;
	this->slope = slope;
}

// accessors
// ********************************************************
// getters
Point* Line::getPointOne() { return &pointOne; }
Point* Line::getPointTwo() { return &pointTwo; }
float Line::getAngle() { return angle; }
float Line::getSlope() { return slope; }
float Line::getLineLength() { return length; }
float Line::getYIntercept() { return yInt; }

//setters
void Line::setAngle(float value) { angle = value; }
void Line::setSlope(float value) { slope = value; }
void Line::setLineLength(float value) { length = value; }
void Line::setYIntercept(float value) { yInt = value; }

//calculate slope between two coordinates of x and y
void Line::slopeFromTwoPoint()
{
	slope = (pointTwo.getYCoor() - pointOne.getYCoor()) / (pointTwo.getXCoor() - pointOne.getXCoor());
}

//calculate angle of two coordinates of x and y
void Line::lineAngle()
{
	float LineAngle = std::atan2((pointTwo.getYCoor() - pointOne.getYCoor()),
		(pointTwo.getXCoor() - pointOne.getXCoor()));

	angle = fmod((90.0 - double(LineAngle * 180.0 / PI)), 360);
}

// calculate length of two points
void Line::lineLength()
{
	length = std::sqrt((std::pow(pointTwo.getXCoor() - pointOne.getXCoor(), 2))
		+ (std::pow((pointTwo.getYCoor() - pointOne.getYCoor()), 2)));
}

// calculate the slope of the line
void Line::slopeIntercept()
{
	yInt = (pointOne.getYCoor() - (slope * pointOne.getXCoor()));
}

// determines whether a value has point two of x and y and if not goes to else
void Line::calcLine()
{
	if (pointTwo.getXCoor() && pointTwo.getYCoor())
	{
		slopeFromTwoPoint();
		slopeIntercept();
	}
	else
	{
		yInt = (pointOne, slope);
		slopeIntercept();
		pointTwo.setYCoor(yInt);
	}
	lineAngle();
	lineLength();
}