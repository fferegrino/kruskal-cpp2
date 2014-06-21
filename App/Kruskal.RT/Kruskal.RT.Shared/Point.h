#pragma once

namespace KruskalRT
{
	class Point sealed
	{
	public:
		Point();
		void Set(int i, int x, int y);
		int Distance(Point p);
		int X();
		int Y();
	private:
		int _i;
		int _x;
		int _y;
	};
}
