/****************************************************************************************[Solver.h]
 The MIT License (MIT)

 Copyright (c) 2014, Sam Bayless

 Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
 associated documentation files (the "Software"), to deal in the Software without restriction,
 including without limitation the rights to use, copy, modify, merge, publish, distribute,
 sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all copies or
 substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
 NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT
 OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 **************************************************************************************************/

#ifndef QUICK_CONVEXHULL_H_
#define QUICK_CONVEXHULL_H_
#include "ConvexHull.h"
#include "PointSet.h"
#include "monosat/mtl/Sort.h"
#include "cevans/quickhull3D.h"
#include <gmpxx.h>
#include "ConvexPolygon.h"
using namespace Monosat;

template<unsigned int D, class T>
class QuickConvexHull: public ConvexHull<D, T> {
	
	PointSet<D, T> & pointSet;
	NConvexPolygon<D, T> hull;
public:
	QuickConvexHull(PointSet<D, T> & p) :
			pointSet(p) {
		
	}
	
	void update();

	ConvexPolygon<D, T> & getHull() {
		update();
		return hull;
	}
	
};
template<>
void QuickConvexHull<1, double>::update();
template<>
void QuickConvexHull<2, double>::update();
template<>
void QuickConvexHull<3, double>::update();

template<>
void QuickConvexHull<2, mpq_class>::update();

#endif
