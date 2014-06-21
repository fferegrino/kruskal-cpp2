#include "pch.h"
#include "Kruskal.h"
#include <algorithm>
#include <string>

using namespace KruskalRT;
using namespace Platform;

Kruskal::Kruskal(int size)
{
	_size = size;
	points = (Point *)malloc(sizeof(Point) * size);
	p = (int *)malloc(sizeof(int) * size);
	for (int ix = 0; ix < size; ix++) p[ix] = ix;
	i = 0;
	distance = 0;
}

void Kruskal::AddPoint(int x, int y){
	points[i].Set(i, x, y);
	i++;
}

void Kruskal::CalcRoutes(){
	for (int a = 0; a < i; a++){
		for (int b = 0; b < i; b++){
			if (a == b) continue;
			Route r;
			r.a = a;
			r.b = b;
			r.d = points[a].Distance(points[b]);
			routes.push_back(r);
		}
	}
}

void Kruskal::Exec(){
	std::sort(routes.begin(), routes.end());
	for (int k = 0; k < (int)routes.size(); k++){
		Join(routes[k]);
	}
}

int Kruskal::Distance(){
	return distance;
}
int Kruskal::RealRoutes(){
	return realroutes.size();
}

Platform::String^ Kruskal::NextCoordinate(){
	String^ s = L"INVALID";
	if (iii < (int)realroutes.size()){
		char16 val[20];

		// Convert to a wchar_t*
		char *orig = "%d %d to %d %d";
		size_t origsize = strlen(orig) + 1;
		const size_t newsize = 100;
		size_t convertedChars = 0;
		wchar_t wcstring[newsize];
		mbstowcs_s(&convertedChars, wcstring, origsize, orig, _TRUNCATE);

		swprintf_s<20>(val, wcstring
			, points[realroutes[iii].a].X(), points[realroutes[iii].a].Y()
			, points[realroutes[iii].b].X(), points[realroutes[iii].b].Y());
		s = ref new String(val);
		iii++;
		return s;
	}
	return s;
}

void Kruskal::Clear(){
	routes.clear();
	realroutes.clear();
	for (int ix = 0; ix < _size; ix++) p[ix] = ix;
	i = 0;
	iii = 0;
	distance = 0;
}

void Kruskal::Join(Route r){
	int aa = Root(r.a);
	int bb = Root(r.b);
	if (aa != bb){
		p[aa] = p[bb];
		distance += r.d;
		realroutes.push_back(r);
	}
}

int Kruskal::Root(int son){
	int padre = 0;
	if (p[son] != son){
		p[son] = Root(p[son]);
	}
	return p[son];
}
