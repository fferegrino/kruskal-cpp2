#include "pch.h"
#include "Point.h"

using namespace KruskalRT;
using namespace Platform;

Point::Point(){

}

void Point::Set(int i, int x, int y)
{
	_i = i;
	_x = x;
	_y = y;
}

int Point::Distance(Point p){
	return sqrt(((_x - p._x) * (_x - p._x)) + ((_y - p._y)*(_y - p._y)));
}