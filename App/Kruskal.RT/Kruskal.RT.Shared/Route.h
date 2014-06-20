#pragma once
namespace KruskalRT
{
	class Route
	{
	public:
		Route();
		int a;
		int b;
		int d; 
		bool operator<(KruskalRT::Route &a);
	};

}
