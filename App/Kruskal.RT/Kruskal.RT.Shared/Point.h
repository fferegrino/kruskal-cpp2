#pragma once

namespace KruskalRT
{
	class Point sealed
	{
	public:
		Point();
		void Set(int i, int x, int y);
		int Distance(Point p);
	private:
		int _i;
		int _x;
		int _y;
	};
}
