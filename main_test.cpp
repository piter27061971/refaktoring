#pragma once
#include "./Catch2/src/catch2/catch_test_macros.hpp"
#include "./Catch2/src/catch2/catch_session.hpp"
#include "shape.h"
#include "Catch2/extras/catch_amalgamated.hpp"
#include <iostream>
#include <cmath>

ShapeLine shLine(1, 1, 3, 3);
ShapeSqr shSqr(1, 1, 3, 1, 3, 3, 1, 3);
ShapeCube shCube(1, 1, 1, 3, 1, 1, 3, 1, 3, 1, 1, 3, 1, 3, 3, 1, 3, 1, 3, 3, 1, 3, 3, 3);
ShapeCircle shCircle(0, 0, 1);
ShapeCylinder shCylinder(0, 0, 1., 10.);

TEST_CASE("class Shape - test Line", "[testLineShape]")
{
	SECTION("coordinates Line")
	{
		CHECK(shLine.cosFM.x1 == 1);
		CHECK(shLine.cosFM.y1 == 1);
		CHECK(shLine.cosFM.x2 == 3);
		CHECK(shLine.cosFM.y2 == 3);
	}

	SECTION("Square Line")
	{
		CHECK(shLine.getSquare() == 0.0);
	}

	SECTION("Volume Line")
	{
		CHECK(shLine.getVolume() == 0.0);
	}
}

TEST_CASE("class Shape - test Sqr", "[testSqrShape]")
{
	SECTION("coordinates Sqr")
	{
		CHECK(shSqr.cosFM.x1 == 1);
		CHECK(shSqr.cosFM.y1 == 1);
		CHECK(shSqr.cosFM.x2 == 3);
		CHECK(shSqr.cosFM.y2 == 1);
		CHECK(shSqr.cosFM.x3 == 3);
		CHECK(shSqr.cosFM.y3 == 3);
		CHECK(shSqr.cosFM.x4 == 1);
		CHECK(shSqr.cosFM.y4 == 3);
	}

	SECTION("Square shSqr")
	{
		CHECK(shSqr.getSquare() == 4.0);
	}

	SECTION("Volume shSqr")
	{
		CHECK(shSqr.getVolume() == 0.0);
	}
}

TEST_CASE("class Shape - test Cube", "[testCubeShape]")
{
	SECTION("coordinates Cube")
	{
		CHECK(shCube.cosFM.x1 == 1);
		CHECK(shCube.cosFM.y1 == 1);
		CHECK(shCube.cosFM.z1 == 1);
		CHECK(shCube.cosFM.x2 == 3);
		CHECK(shCube.cosFM.y2 == 1);
		CHECK(shCube.cosFM.z2 == 1);
		CHECK(shCube.cosFM.x3 == 3);
		CHECK(shCube.cosFM.y3 == 1);
		CHECK(shCube.cosFM.z3 == 3);
		CHECK(shCube.cosFM.x4 == 1);
		CHECK(shCube.cosFM.y4 == 1);
		CHECK(shCube.cosFM.z4 == 3);
		CHECK(shCube.cosFM.x5 == 1);
		CHECK(shCube.cosFM.y5 == 3);
		CHECK(shCube.cosFM.z5 == 3);
		CHECK(shCube.cosFM.x6 == 1);
		CHECK(shCube.cosFM.y6 == 3);
		CHECK(shCube.cosFM.z6 == 1);
		CHECK(shCube.cosFM.x7 == 3);
		CHECK(shCube.cosFM.y7 == 3);
		CHECK(shCube.cosFM.z7 == 1);
		CHECK(shCube.cosFM.x8 == 3);
		CHECK(shCube.cosFM.y8 == 3);
		CHECK(shCube.cosFM.z8 == 3);
	}

	SECTION("Square Cube")
	{
		CHECK(shCube.getSquare() == 24.);
	}

	SECTION("Volume Cube")
	{
		CHECK(shCube.getVolume() == 8.);
	}
}

TEST_CASE("class Shape - test Circle", "[testCircleShape]")
{
	SECTION("coordinates Circle")
	{
		CHECK(shCircle.cosFM.x1 == 0);
		CHECK(shCircle.cosFM.y1 == 0);
		CHECK(shCircle.getRadius() == 1.);
	}

	SECTION("Square Circle")
	{
		CHECK(shCircle.getSquare() == 3.14159265358979312);
	}

	SECTION("Volume Circle")
	{
		CHECK(shCircle.getVolume() == 0.);
	}
}

TEST_CASE("class Shape - test Cylinder", "[testCylinderShape]")
{
	SECTION("coordinates Cylinder")
	{
		CHECK(shCylinder.cosFM.x1 == 0);
		CHECK(shCylinder.cosFM.y1 == 0);
		CHECK(shCylinder.getRadius() == 1.);
		CHECK(shCylinder.getHeight() == 10.);
	}

	SECTION("Square Cylinder")
	{
		CHECK(shCylinder.getSquare() == 69.11503837897544145);
	}

	SECTION("Volume Cylinder")
	{
		CHECK(shCylinder.getVolume() == 31.41592653589793116);
	}
}

//transform Line
//***************************************************************************************

std::once_flag flag1;
void trLineShift(const int _m, const int _n)
{
	shLine.shift(_m, _n);
}
std::once_flag flag2;
void trLineScaleX(const int _a)
{
	shLine.scaleX(_a);
}
std::once_flag flag3;
void trLineScaleY(const int _d)
{
	shLine.scaleY(_d);
}
std::once_flag flag4;
void trLineScaleZ(const int _e)
{
	shLine.scaleZ(_e);
}
std::once_flag flag5;
void trLineScale(const int _s)
{
	shLine.scale(_s);
}

TEST_CASE("class Transform - test Line", "[testLineTransform]")
{
	SECTION("class Transform - test Line")
	{
		const int _m = 1;
		const int _n = 2;
		std::call_once(flag1, trLineShift, _m, _n);

		SECTION("coordinates Line after Shift")
		{

			CHECK(shLine.cosFM.x1 == 1 + _m);
			CHECK(shLine.cosFM.y1 == 1 + _n);
			CHECK(shLine.cosFM.x2 == 3 + _m);
			CHECK(shLine.cosFM.y2 == 3 + _n);
		}

		SECTION("Square Line after Shift")
		{
			CHECK(shLine.getSquare() == 0.0);
		}

		SECTION("Volume Line after Shift")
		{
			CHECK(shLine.getVolume() == 0.0);
		}
	}

	SECTION("class Transform - test Line ScaleX")
	{
		const int _a = 3;
		std::call_once(flag2, trLineScaleX, _a);

		SECTION("coordinates Line after ScaleX")
		{
			CHECK(shLine.cosFM.x1 == 6);
			CHECK(shLine.cosFM.y1 == 3);
			CHECK(shLine.cosFM.x2 == 12);
			CHECK(shLine.cosFM.y2 == 5);
		}

		SECTION("Square Line after ScaleX")
		{
			CHECK(shLine.getSquare() == 0.0);
		}

		SECTION("Volume Line after ScaleX")
		{
			CHECK(shLine.getVolume() == 0.0);
		}
	}

	SECTION("class Transform - test Line ScaleY")
	{
		const int _d = 4;
		std::call_once(flag3, trLineScaleY, _d);

		SECTION("coordinates Line after ScaleY")
		{
			CHECK(shLine.cosFM.x1 == 6);
			CHECK(shLine.cosFM.y1 == 12);
			CHECK(shLine.cosFM.x2 == 12);
			CHECK(shLine.cosFM.y2 == 20);
		}

		SECTION("Square Line after ScaleY")
		{
			CHECK(shLine.getSquare() == 0.0);
		}

		SECTION("Volume Line after ScaleY")
		{
			CHECK(shLine.getVolume() == 0.0);
		}
	}

	SECTION("class Transform - test Line ScaleZ")
	{
		const int _e = 5;
		std::call_once(flag4, trLineScaleZ, _e);

		SECTION("coordinates Line after ScaleZ")
		{
			CHECK(shLine.cosFM.z1 == 0);
			CHECK(shLine.cosFM.z2 == 0);
		}

		SECTION("Square Line after ScaleZ")
		{
			CHECK(shLine.getSquare() == 0.0);
		}

		SECTION("Volume Line after ScaleZ")
		{
			CHECK(shLine.getVolume() == 0.0);
		}
	}

	SECTION("class Transform - test Line Scale")
	{
		const int _s = 2;
		std::call_once(flag5, trLineScale, _s);

		SECTION("coordinates Line after Scale")
		{
			CHECK(shLine.cosFM.x1 == 3);
			CHECK(shLine.cosFM.y1 == 6);
			CHECK(shLine.cosFM.x2 == 6);
			CHECK(shLine.cosFM.y2 == 10);
		}

		SECTION("Square Line after Scale")
		{
			CHECK(shLine.getSquare() == 0.0);
		}

		SECTION("Volume Line after Scale")
		{
			CHECK(shLine.getVolume() == 0.0);
		}
	}

}


//***************************************************************************************

std::once_flag flag6;
void trSqrShift(const int _m, const int _n)
{
	shSqr.shift(_m, _n);
}
std::once_flag flag7;
void trSqrScaleX(const int _a)
{
	shSqr.scaleX(_a);
}
std::once_flag flag8;
void trSqrScaleY(const int _d)
{
	shSqr.scaleY(_d);
}
std::once_flag flag9;
void trSqrScaleZ(const int _e)
{
	shSqr.scaleZ(_e);
}
std::once_flag flag10;
void trSqrScale(const int _s)
{
	shSqr.scale(_s);
}

TEST_CASE("class Transform - test Sqr", "[testSqrTransform]")
{
	SECTION("class Transform - test Sqr")
	{
		const int _m = 1;
		const int _n = 2;
		std::call_once(flag6, trSqrShift, _m, _n);

		SECTION("coordinates Sqr after Shift")
		{
			CHECK(shSqr.cosFM.x1 == 2);
			CHECK(shSqr.cosFM.y1 == 3);
			CHECK(shSqr.cosFM.x2 == 4);
			CHECK(shSqr.cosFM.y2 == 3);
			CHECK(shSqr.cosFM.x3 == 4);
			CHECK(shSqr.cosFM.y3 == 5);
			CHECK(shSqr.cosFM.x4 == 2);
			CHECK(shSqr.cosFM.y4 == 5);
		}

		SECTION("Square Sqr after Shift")
		{
			CHECK(shSqr.getSquare() == 4.0);
		}

		SECTION("Volume Sqr after Shift")
		{
			CHECK(shSqr.getVolume() == 0.0);
		}
	}

	SECTION("class Transform - test Sqr ScaleX")
	{
		const int _a = 3;
		std::call_once(flag7, trSqrScaleX, _a);

		SECTION("coordinates Sqr after ScaleX")
		{
			CHECK(shSqr.cosFM.x1 == 6);
			CHECK(shSqr.cosFM.y1 == 3);
			CHECK(shSqr.cosFM.x2 == 12);
			CHECK(shSqr.cosFM.y2 == 3);
			CHECK(shSqr.cosFM.x3 == 12);
			CHECK(shSqr.cosFM.y3 == 5);
			CHECK(shSqr.cosFM.x4 == 6);
			CHECK(shSqr.cosFM.y4 == 5);
		}

		SECTION("Square Sqr after ScaleX")
		{
			CHECK(shSqr.getSquare() == 4.0);
		}

		SECTION("Volume Sqr after ScaleX")
		{
			CHECK(shSqr.getVolume() == 0.0);
		}
	}

	SECTION("class Transform - test Sqr ScaleY")
	{
		const int _d = 4;
		std::call_once(flag8, trSqrScaleY, _d);

		SECTION("coordinates Sqr after ScaleY")
		{
			CHECK(shSqr.cosFM.x1 == 6);
			CHECK(shSqr.cosFM.y1 == 12);
			CHECK(shSqr.cosFM.x2 == 12);
			CHECK(shSqr.cosFM.y2 == 12);
			CHECK(shSqr.cosFM.x3 == 12);
			CHECK(shSqr.cosFM.y3 == 20);
			CHECK(shSqr.cosFM.x4 == 6);
			CHECK(shSqr.cosFM.y4 == 20);
		}

		SECTION("Square Sqr after ScaleY")
		{
			CHECK(shSqr.getSquare() == 4.0);
		}

		SECTION("Volume Sqr after ScaleY")
		{
			CHECK(shSqr.getVolume() == 0.0);
		}
	}

	SECTION("class Transform - test Sqr ScaleZ")
	{
		const int _e = 5;
		std::call_once(flag9, trSqrScaleZ, _e);

		SECTION("coordinates Sqr after ScaleZ")
		{
			CHECK(shSqr.cosFM.z1 == 0);
			CHECK(shSqr.cosFM.z2 == 0);
			CHECK(shSqr.cosFM.z3 == 0);
			CHECK(shSqr.cosFM.z4 == 0);
		}

		SECTION("Square Sqr after ScaleZ")
		{
			CHECK(shSqr.getSquare() == 4.0);
		}

		SECTION("Volume Sqr after ScaleZ")
		{
			CHECK(shSqr.getVolume() == 0.0);
		}
	}

	SECTION("class Transform - test Sqr Scale")
	{
		const int _s = 2;
		std::call_once(flag10, trSqrScale, _s);

		SECTION("coordinates Sqr after Scale")
		{
			CHECK(shSqr.cosFM.x1 == 3);
			CHECK(shSqr.cosFM.y1 == 6);
			CHECK(shSqr.cosFM.x2 == 6);
			CHECK(shSqr.cosFM.y2 == 6);
			CHECK(shSqr.cosFM.x3 == 6);
			CHECK(shSqr.cosFM.y3 == 10);
			CHECK(shSqr.cosFM.x4 == 3);
			CHECK(shSqr.cosFM.y4 == 10);
		}

		SECTION("Square Sqr after Scale")
		{
			CHECK(shSqr.getSquare() == 4.0);
		}

		SECTION("Volume Sqr after Scale")
		{
			CHECK(shSqr.getVolume() == 0.0);
		}
	}

}


//***************************************************************************************
std::once_flag flag11;
void trCubeShift(const int _m, const int _n, const int _k)
{
	shCube.shift(_m, _n, _k);
}
std::once_flag flag12;
void trCubeScaleX(const int _a)
{
	shCube.scaleX(_a);
}
std::once_flag flag13;
void trCubeScaleY(const int _d)
{
	shCube.scaleY(_d);
}
std::once_flag flag14;
void trCubeScaleZ(const int _e)
{
	shCube.scaleZ(_e);
}
std::once_flag flag15;
void trCubeScale(const int _s)
{
	shCube.scale(_s);
}

TEST_CASE("class Transform - test Cube", "[testCubeTransform]")
{
	SECTION("class Transform - test Cube")
	{
		const int _m = 1;
		const int _n = 2;
		const int _k = 3;

		std::call_once(flag11, trCubeShift, _m, _n, _k);

		SECTION("coordinates Cube after Shift")
		{
			CHECK(shCube.cosFM.x1 == 2);
			CHECK(shCube.cosFM.y1 == 3);
			CHECK(shCube.cosFM.z1 == 4);
			CHECK(shCube.cosFM.x2 == 4);
			CHECK(shCube.cosFM.y2 == 3);
			CHECK(shCube.cosFM.z2 == 4);
			CHECK(shCube.cosFM.x3 == 4);
			CHECK(shCube.cosFM.y3 == 3);
			CHECK(shCube.cosFM.z3 == 6);
			CHECK(shCube.cosFM.x4 == 2);
			CHECK(shCube.cosFM.y4 == 3);
			CHECK(shCube.cosFM.z4 == 6);
			CHECK(shCube.cosFM.x5 == 2);
			CHECK(shCube.cosFM.y5 == 5);
			CHECK(shCube.cosFM.z5 == 6);
			CHECK(shCube.cosFM.x6 == 2);
			CHECK(shCube.cosFM.y6 == 5);
			CHECK(shCube.cosFM.z6 == 4);
			CHECK(shCube.cosFM.x7 == 4);
			CHECK(shCube.cosFM.y7 == 5);
			CHECK(shCube.cosFM.z7 == 4);
			CHECK(shCube.cosFM.x8 == 4);
			CHECK(shCube.cosFM.y8 == 5);
			CHECK(shCube.cosFM.z8 == 6);
		}

		SECTION("Square Cube after Shift")
		{
			CHECK(shCube.getSquare() == 24.0);
		}

		SECTION("Volume Cube after Shift")
		{
			CHECK(shCube.getVolume() == 8.0);
		}
	}

	SECTION("class Transform - test Cube ScaleX")
	{
		const int _a = 3;
		std::call_once(flag12, trCubeScaleX, _a);

		SECTION("coordinates Cube after ScaleX")
		{
			CHECK(shCube.cosFM.x1 == 6);
			CHECK(shCube.cosFM.y1 == 3);
			CHECK(shCube.cosFM.z1 == 4);
			CHECK(shCube.cosFM.x2 == 12);
			CHECK(shCube.cosFM.y2 == 3);
			CHECK(shCube.cosFM.z2 == 4);
			CHECK(shCube.cosFM.x3 == 12);
			CHECK(shCube.cosFM.y3 == 3);
			CHECK(shCube.cosFM.z3 == 6);
			CHECK(shCube.cosFM.x4 == 6);
			CHECK(shCube.cosFM.y4 == 3);
			CHECK(shCube.cosFM.z4 == 6);
			CHECK(shCube.cosFM.x5 == 6);
			CHECK(shCube.cosFM.y5 == 5);
			CHECK(shCube.cosFM.z5 == 6);
			CHECK(shCube.cosFM.x6 == 6);
			CHECK(shCube.cosFM.y6 == 5);
			CHECK(shCube.cosFM.z6 == 4);
			CHECK(shCube.cosFM.x7 == 12);
			CHECK(shCube.cosFM.y7 == 5);
			CHECK(shCube.cosFM.z7 == 4);
			CHECK(shCube.cosFM.x8 == 12);
			CHECK(shCube.cosFM.y8 == 5);
			CHECK(shCube.cosFM.z8 == 6);
		}

		SECTION("Square Cube after ScaleX")
		{
			CHECK(shCube.getSquare() == 24.0);
		}

		SECTION("Volume Cube after ScaleX")
		{
			CHECK(shCube.getVolume() == 8.0);
		}
	}

	SECTION("class Transform - test Cube ScaleY")
	{
		const int _d = 4;
		std::call_once(flag13, trCubeScaleY, _d);

		SECTION("coordinates Cube after ScaleY")
		{
			CHECK(shCube.cosFM.x1 == 6);
			CHECK(shCube.cosFM.y1 == 12);
			CHECK(shCube.cosFM.z1 == 4);
			CHECK(shCube.cosFM.x2 == 12);
			CHECK(shCube.cosFM.y2 == 12);
			CHECK(shCube.cosFM.z2 == 4);
			CHECK(shCube.cosFM.x3 == 12);
			CHECK(shCube.cosFM.y3 == 12);
			CHECK(shCube.cosFM.z3 == 6);
			CHECK(shCube.cosFM.x4 == 6);
			CHECK(shCube.cosFM.y4 == 12);
			CHECK(shCube.cosFM.z4 == 6);
			CHECK(shCube.cosFM.x5 == 6);
			CHECK(shCube.cosFM.y5 == 20);
			CHECK(shCube.cosFM.z5 == 6);
			CHECK(shCube.cosFM.x6 == 6);
			CHECK(shCube.cosFM.y6 == 20);
			CHECK(shCube.cosFM.z6 == 4);
			CHECK(shCube.cosFM.x7 == 12);
			CHECK(shCube.cosFM.y7 == 20);
			CHECK(shCube.cosFM.z7 == 4);
			CHECK(shCube.cosFM.x8 == 12);
			CHECK(shCube.cosFM.y8 == 20);
			CHECK(shCube.cosFM.z8 == 6);
		}

		SECTION("Square Cube after ScaleY")
		{
			CHECK(shCube.getSquare() == 24.0);
		}

		SECTION("Volume Cube after ScaleY")
		{
			CHECK(shCube.getVolume() == 8.0);
		}
	}

	SECTION("class Transform - test Cube ScaleZ")
	{
		const int _e = 5;
		std::call_once(flag14, trCubeScaleZ, _e);

		SECTION("coordinates Cube after ScaleZ")
		{
			CHECK(shCube.cosFM.x1 == 6);
			CHECK(shCube.cosFM.y1 == 12);
			CHECK(shCube.cosFM.z1 == 20);
			CHECK(shCube.cosFM.x2 == 12);
			CHECK(shCube.cosFM.y2 == 12);
			CHECK(shCube.cosFM.z2 == 20);
			CHECK(shCube.cosFM.x3 == 12);
			CHECK(shCube.cosFM.y3 == 12);
			CHECK(shCube.cosFM.z3 == 30);
			CHECK(shCube.cosFM.x4 == 6);
			CHECK(shCube.cosFM.y4 == 12);
			CHECK(shCube.cosFM.z4 == 30);
			CHECK(shCube.cosFM.x5 == 6);
			CHECK(shCube.cosFM.y5 == 20);
			CHECK(shCube.cosFM.z5 == 30);
			CHECK(shCube.cosFM.x6 == 6);
			CHECK(shCube.cosFM.y6 == 20);
			CHECK(shCube.cosFM.z6 == 20);
			CHECK(shCube.cosFM.x7 == 12);
			CHECK(shCube.cosFM.y7 == 20);
			CHECK(shCube.cosFM.z7 == 20);
			CHECK(shCube.cosFM.x8 == 12);
			CHECK(shCube.cosFM.y8 == 20);
			CHECK(shCube.cosFM.z8 == 30);
		}

		SECTION("Square Cube after ScaleZ")
		{
			CHECK(shCube.getSquare() == 24.0);
		}

		SECTION("Volume Cube after ScaleZ")
		{
			CHECK(shCube.getVolume() == 8.0);
		}
	}

	SECTION("class Transform - test Cube Scale")
	{
		const int _s = 2;
		std::call_once(flag15, trCubeScale, _s);

		SECTION("coordinates Cube after Scale")
		{
			CHECK(shCube.cosFM.x1 == 3);
			CHECK(shCube.cosFM.y1 == 6);
			CHECK(shCube.cosFM.z1 == 10);
			CHECK(shCube.cosFM.x2 == 6);
			CHECK(shCube.cosFM.y2 == 6);
			CHECK(shCube.cosFM.z2 == 10);
			CHECK(shCube.cosFM.x3 == 6);
			CHECK(shCube.cosFM.y3 == 6);
			CHECK(shCube.cosFM.z3 == 15);
			CHECK(shCube.cosFM.x4 == 3);
			CHECK(shCube.cosFM.y4 == 6);
			CHECK(shCube.cosFM.z4 == 15);
			CHECK(shCube.cosFM.x5 == 3);
			CHECK(shCube.cosFM.y5 == 10);
			CHECK(shCube.cosFM.z5 == 15);
			CHECK(shCube.cosFM.x6 == 3);
			CHECK(shCube.cosFM.y6 == 10);
			CHECK(shCube.cosFM.z6 == 10);
			CHECK(shCube.cosFM.x7 == 6);
			CHECK(shCube.cosFM.y7 == 10);
			CHECK(shCube.cosFM.z7 == 10);
			CHECK(shCube.cosFM.x8 == 6);
			CHECK(shCube.cosFM.y8 == 10);
			CHECK(shCube.cosFM.z8 == 15);
		}

		SECTION("Square Cube after Scale")
		{
			CHECK(shCube.getSquare() == 24.0);
		}

		SECTION("Volume Cube after Scale")
		{
			CHECK(shCube.getVolume() == 8.0);
		}
	}

}

int main(int argc, char* argv[])
{
	return Catch::Session().run(argc, argv);
}