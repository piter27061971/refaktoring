#define _USE_MATH_DEFINES
#include "shape.h"
#include <cmath>
#include <iostream>



ShapeLine::ShapeLine(int _x1, int _y1, int _x2, int _y2)
{
	cosFM.x1 = cos.x1 = _x1; cosFM.y1 = cos.y1 = _y1;
	cosFM.x2 = cos.x2 = _x2; cosFM.y2 = cos.y2 = _y2;
	square = 0.;
	volume = 0.;
	//cosFM = cos;
}

ShapeSqr::ShapeSqr(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int _x4, int _y4)
{
	cos.x1 = _x1; cos.y1 = _y1;
	cos.x2 = _x2; cos.y2 = _y2;
	cos.x3 = _x3; cos.y3 = _y3;
	cos.x4 = _x4; cos.y4 = _y4;
	square = pow((cos.x1 - cos.x2), 2) + pow((cos.y1 - cos.y2), 2);
	volume = 0.;
	cosFM = cos;
}



ShapeCube::ShapeCube(int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int _x3, int _y3, int _z3, int _x4, int _y4, int _z4, int _x5, int _y5, int _z5, int _x6, int _y6, int _z6, int _x7, int _y7, int _z7, int _x8, int _y8, int _z8)
{
	cos.x1 = _x1; cos.y1 = _y1; cos.z1 = _z1;
	cos.x2 = _x2; cos.y2 = _y2; cos.z2 = _z2;
	cos.x3 = _x3; cos.y3 = _y3; cos.z3 = _z3;
	cos.x4 = _x4; cos.y4 = _y4; cos.z4 = _z4;
	cos.x5 = _x5; cos.y5 = _y5; cos.z5 = _z5;
	cos.x6 = _x6; cos.y6 = _y6; cos.z6 = _z6;
	cos.x7 = _x7; cos.y7 = _y7; cos.z7 = _z7;
	cos.x8 = _x8; cos.y8 = _y8; cos.z8 = _z8;
	square = 6 * (pow((cos.x1 - cos.x2), 2) + pow((cos.y1 - cos.y2), 2));
	volume = 2 * (pow((cos.x1 - cos.x2), 2) + pow((cos.y1 - cos.y2), 2));
	cosFM = cos;
}

ShapeCircle::ShapeCircle(int _x1, int _y1, double _R)
{
	cos.x1 = _x1; cos.y1 = _y1;
	radius = _R;
	square = M_PI * _R * _R;
	volume = 0.;
	cosFM = cos;
}

ShapeCylinder::ShapeCylinder(int _x1, int _y1, double _R, double _H)
{
	cos.x1 = _x1; cos.y1 = _y1;
	radius = _R;
	height = _H;
	square = 2 * M_PI * _R * (_R + _H);
	volume = M_PI * _R * _R * _H;
	cosFM = cos;
}

double Shape::getVolume() const
{
	return volume;
}

double Shape::getSquare() const
{
	return square;
}

double Shape::getHeight() const
{
	return height;
}

double Shape::getRadius() const
{
	return radius;
}


void ShapeLine::shift(int _m, int _n)
{
	cos.x1 += _m; cos.y1 += _n;
	cos.x2 += _m; cos.y2 += _n;
	cosFM = cos;
}

void ShapeLine::scaleX(int _a)
{
	cos.x1 *= _a;
	cos.x2 *= _a;
	cosFM = cos;
}

void ShapeLine::scaleY(int _d)
{
	cos.y1 *= _d;
	cos.y2 *= _d;
	cosFM = cos;
}

void ShapeLine::scaleZ(int _e)
{
	cos.z1 *= _e;
	cos.z2 *= _e;
	cosFM = cos;
}

void ShapeLine::scale(int _s)
{
	cos.x1 /= _s; cos.y1 /= _s;
	cos.x2 /= _s; cos.y2 /= _s;
	cosFM = cos;
}

void ShapeSqr::shift(int _m, int _n) 
{
	cos.x1 += _m; cos.y1 += _n;
	cos.x2 += _m; cos.y2 += _n;
	cos.x3 += _m; cos.y3 += _n;
	cos.x4 += _m; cos.y4 += _n;
	cosFM = cos;
}

void ShapeSqr::scaleX(int _a)
{
	cos.x1 *= _a;
	cos.x2 *= _a;
	cos.x3 *= _a;
	cos.x4 *= _a;
	cosFM = cos;
}

void ShapeSqr::scaleY(int _d)
{
	cos.y1 *= _d;
	cos.y2 *= _d;
	cos.y3 *= _d;
	cos.y4 *= _d;
	cosFM = cos;
}

void ShapeSqr::scaleZ(int _e)
{
	cos.z1 *= _e;
	cos.z2 *= _e;
	cos.z3 *= _e;
	cos.z4 *= _e;
	cosFM = cos;
}

void ShapeSqr::scale(int _s)
{
	cos.x1 /= _s; cos.y1 /= _s;
	cos.x2 /= _s; cos.y2 /= _s;
	cos.x3 /= _s; cos.y3 /= _s;
	cos.x4 /= _s; cos.y4 /= _s;
	cosFM = cos;
}

void ShapeCube::shift(int _m, int _n, int _k)
{
	cos.x1 += _m; cos.y1 += _n; cos.z1 += _k;
	cos.x2 += _m; cos.y2 += _n; cos.z2 += _k;
	cos.x3 += _m; cos.y3 += _n; cos.z3 += _k;
	cos.x4 += _m; cos.y4 += _n; cos.z4 += _k;
	cos.x5 += _m; cos.y5 += _n; cos.z5 += _k;
	cos.x6 += _m; cos.y6 += _n; cos.z6 += _k;
	cos.x7 += _m; cos.y7 += _n; cos.z7 += _k;
	cos.x8 += _m; cos.y8 += _n; cos.z8 += _k;
	cosFM = cos;
}

void ShapeCube::scaleX(int _a)
{
	cos.x1 *= _a;
	cos.x2 *= _a;
	cos.x3 *= _a;
	cos.x4 *= _a;
	cos.x5 *= _a;
	cos.x6 *= _a;
	cos.x7 *= _a;
	cos.x8 *= _a;
	cosFM = cos;
}

void ShapeCube::scaleY(int _d)
{
	cos.y1 *= _d;
	cos.y2 *= _d;
	cos.y3 *= _d;
	cos.y4 *= _d;
	cos.y5 *= _d;
	cos.y6 *= _d;
	cos.y7 *= _d;
	cos.y8 *= _d;
	cosFM = cos;
}

void ShapeCube::scaleZ(int _e)
{
	cos.z1 *= _e;
	cos.z2 *= _e;
	cos.z3 *= _e;
	cos.z4 *= _e;
	cos.z5 *= _e;
	cos.z6 *= _e;
	cos.z7 *= _e;
	cos.z8 *= _e;
	cosFM = cos;
}

void ShapeCube::scale(int _s)
{
	cos.x1 /= _s; cos.y1 /= _s; cos.z1 /= _s;
	cos.x2 /= _s; cos.y2 /= _s; cos.z2 /= _s;
	cos.x3 /= _s; cos.y3 /= _s; cos.z3 /= _s;
	cos.x4 /= _s; cos.y4 /= _s; cos.z4 /= _s;
	cos.x5 /= _s; cos.y5 /= _s; cos.z5 /= _s;
	cos.x6 /= _s; cos.y6 /= _s; cos.z6 /= _s;
	cos.x7 /= _s; cos.y7 /= _s; cos.z7 /= _s;
	cos.x8 /= _s; cos.y8 /= _s; cos.z8 /= _s;
	cosFM = cos;
}