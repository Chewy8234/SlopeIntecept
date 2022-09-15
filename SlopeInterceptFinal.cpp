/*file:		SlopeInterceptFinal.cpp
* by:		Sebastian Campos
* org:		COP 2001,202101, 10409
* desc:		main application for graphing line
*/


#include <iostream>			//  console input output
#include <iomanip>			//  fixed or set prec
#include "fgcugl.h"
#include <cmath>			// enable sqrt, pow , fmod


#include "fgcugl.h"					// fgcu OpenGL library
#include "Line.h"
#include "Point.h"


// enums
enum MenuChoice {
	two_point = 1,
	point_slope, // assign to 2 
	menu_exit	// assign to 3
};

// main properties
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;
const std::string WINDOW_TITLE = "SlopeIntercept";
const int LINE_COLOR = fgcugl::White;


//Function prototypes
MenuChoice getProblem();
Point getPoint();
Line get2Point();
Line getPointSlope();
void displayLine(Line* line);
void display2Pt(Line* line);
void displayPointSlope(Line* line);
void displaySlopeIntercept(Line* line);
void drawLine(Line* line);

//main program
int main()
{
	MenuChoice choice;

	do
	{

		Line mainLine = Line();

		choice = getProblem();

		// displays the functions and draws the line for either two_point or point_slope
		switch (choice)
		{
		case two_point:
			mainLine = get2Point();
			mainLine.calcLine();
			displayLine(&mainLine);
			display2Pt(&mainLine);
			displaySlopeIntercept(&mainLine);
			drawLine(&mainLine);
			break;
		case point_slope:
			mainLine = getPointSlope();
			mainLine.calcLine();
			displayLine(&mainLine);
			displayPointSlope(&mainLine);
			displaySlopeIntercept(&mainLine);
			drawLine(&mainLine);
			break;
		case menu_exit:
			std::cout << "Exit Menu\n";
			break;
		default:
			std::cout << "Invalid Menu\n";
		}

	} while (choice != menu_exit);


	return 0;
}// end main

// displays the menu option of the for either two point or point slope form
MenuChoice getProblem()
{
	int option;

	std::cout << "\n\tSelect the form that you would like to convert to slope-intercept form:\n\t"
		<< "\t1) Two - point form(you know the two points of the line)\n\t"
		<< "\t2) Point - slope form(you know the line's slope and one point\n\t"
		<< "\t3) exit\n\t"
		<< "=> ";
	std::cin >> option;

	MenuChoice choice = static_cast<MenuChoice>(option);

	return choice;
}

// input of the x and y coordinate
Point getPoint() {

	float xCoordinate, yCoordinate;

	std::cout << "\n\tEnter X and Y coordinates separated by spaces: ";
	std::cin >> xCoordinate >> yCoordinate;

	Point point = Point(xCoordinate, yCoordinate);

	return point;
}

//  input of the first and second point of the line
Line get2Point()
{

	std::cout << "\n\tEnter the first point:\n\t";
	Point firstPoint = getPoint();


	std::cout << "\n\tEnter the second point:\n\t";
	Point secondPoint = getPoint();

	Line mainLine = Line(&firstPoint, &secondPoint);

	return mainLine;
}

//  gets the point slope of the first point and slope
Line getPointSlope()
{

	float slope;

	std::cout << "\n\tEnter a point for the line\n\t";
	Point firstPoint = getPoint();
	std::cout << "\n\tEnter the slope of the line:";
	std::cin >> slope;

	Line mainLine = Line(&firstPoint, slope);

	return mainLine;
}

// displays the results of the and the points given
void displayLine(Line* line) {
	Point* firstPoint = line->getPointOne();
	Point* secondPoint = line->getPointTwo();

	std::cout << "\n\tLine:"
		<< "\n\t\tPoint-1" << "\t(" << (firstPoint->getXCoor()) << (",") << (firstPoint->getYCoor()) << ")"
		<< "\n\t\tPoint-2" << "\t(" << (secondPoint->getXCoor()) << (",") << (secondPoint->getYCoor()) << ")"
		<< "\n\t\tSlope = " << std::setprecision(3) << line->getSlope()
		<< "\n\t\tY-Intcpt = " << line->getYIntercept()
		<< "\n\t\tLength = " << line->getLineLength()
		<< "\n\t\tAngle = " << line->getAngle();
}

// displays the points of two different x and y points
void display2Pt(Line* line) {
	Point* firstPoint = line->getPointOne();
	Point* secondPoint = line->getPointTwo();

	std::cout << "\n\n\tTwo-point form:\n\t" << "\n\t\t\t(" << secondPoint->getYCoor() << "-" << firstPoint->getYCoor() << ")"
		<< "\n\t\tm = -----------------------\n " << "\t\t\t(" << secondPoint->getXCoor() << "-" << firstPoint->getXCoor()
		<< ")\n";
}

//  displays the point slope of the first point and slope
void displayPointSlope(Line* line)
{
	Point* firstPoint = line->getPointOne();
	Point* secondPoint = line->getPointTwo();

	std::cout << "\n\tPoint-slope form:\n" << "\t\ty - " << firstPoint->getYCoor() << " = " << line->getSlope() << "(x"
		<< "- " << firstPoint->getXCoor() << ")\n";
}


// gets the slope and y-int 
void displaySlopeIntercept(Line* line) {

	std::cout << "\n\tSlope-Intercept form:\n" << "\t\ty = " << line->getSlope() << "x + " << line->getYIntercept() << "\n";
}


// draws the line for either point slope and two point
void drawLine(Line* line)
{
	fgcugl::openWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

	Point* firstPoint = line->getPointOne();
	Point* secondPoint = line->getPointTwo();

	while (!fgcugl::windowClosing())
	{

		fgcugl::drawLine(0, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT / 2); // x-axis
		fgcugl::drawLine(WINDOW_WIDTH / 2, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT); // y - axis

		//line
		fgcugl::drawLine(firstPoint->getXCoor() + WINDOW_WIDTH / 2, firstPoint->getYCoor() + WINDOW_HEIGHT / 2, secondPoint->getXCoor() + WINDOW_WIDTH / 2, secondPoint->getYCoor() + WINDOW_HEIGHT / 2);


		//paint new scene to window
		fgcugl::windowPaint();

		// window move /close events, and also gets events of the line
		fgcugl::getEvents();


	}
	// release resources
	fgcugl::cleanup();
}