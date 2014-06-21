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
		Platform::String^ NextCoordinate();
		int Distance();
		int RealRoutes();
		void Clear();
	private:
		void Join(Route r);
		int Root(int son);
		int distance;
		int i;
		int iii;
		int _size;
		int * p;
		std::vector < Route > routes;
		std::vector < Route > realroutes;
		Point * points;
	};
}
