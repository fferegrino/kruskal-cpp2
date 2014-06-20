#include "pch.h"
#include "Kruskal.h"
#include <algorithm>

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
	for (int k = 0; k < routes.size(); k++){
		Join(routes[k]);
	}
}

int Kruskal::Distance(){
	return distance;
}

void Kruskal::Join(Route r){
	int aa = Root(r.a);
	int bb = Root(r.b);
	if (aa != bb){
		p[aa] = p[bb];
		distance += r.d;
	}
}

int Kruskal::Root(int son){
	int padre = 0;
	if (p[son] != son){
		p[son] = Root(p[son]);
	}
	return p[son];
}
