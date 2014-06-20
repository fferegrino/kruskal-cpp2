#pragma once
#include <vector>
#include "Point.h"
#include "Route.h"

namespace KruskalRT
{
	public ref class Kruskal sealed
	{
	public:
		Kruskal(int size);
		void AddPoint(int x, int y);
		void CalcRoutes();
		void Exec();
		int Distance();
	private:
		void Join(Route r);
		int Root(int son);
		int distance;
		int i;
		int _size;
		int * p;
		std::vector < Route > routes;
		Point * points;
	};
}
