#include "pch.h"
#include "Route.h"
using namespace KruskalRT;
using namespace Platform;

Route::Route()
{
}


bool Route::operator<(KruskalRT::Route &a){
	return d < a.d;
}


