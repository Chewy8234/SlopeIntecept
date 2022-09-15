/*file:		Line.h
* by:		Sebastian Campos
* org:		COP 2001,202101, 10409
* desc:		desc: declaration of a line class object
*/
#ifndef LINE_H
#define LINE_H

#include "Point.h"

// variables for the line structure
class Line
{
private:
	Point pointOne;
	Point pointTwo;

	float slope;
	float yInt;
	float length;
	float angle;

public:

	// constructors
	Line();				//default constructor
	Line(Point* firstPoint, Point* secondPoint);	    //the two required points
	Line(Point* firstPoint, float slope);						// slope(float) point


	//accesors
	//getters
	Point* getPointOne();
	Point* getPointTwo();
	float getSlope();
	float getLineLength();
	float getAngle();
	float getYIntercept();

	//setters
	void setSlope(float value);
	void setLineLength(float value);
	void setAngle(float value);
	void setYIntercept(float value);


	//member methods
	void lineLength();
	void lineAngle();
	void slopeIntercept();
	void slopeFromTwoPoint();
	void calcLine();

};
#endif // LINE_H