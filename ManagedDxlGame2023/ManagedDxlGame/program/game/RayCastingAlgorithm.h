#pragma once
#include "RayCastingAlgorithm.h"


//rayIntersectsRectangleは、rayOriginからrayDirectionに向かう光線がrectangleと交差するかどうかを判定します。

//Pointは、xとyの座標を持つ構造体です。
struct Point {
	float x;
	float y;
};
//Rayは、originとdirectionの座標を持つ構造体です。
//originは、光線の始点の座標です。
//directionは、光線の方向の座標です。
struct Ray {
	Point origin;
	Point direction;
};
//BoundingBoxは、topLeftとbottomRightの座標を持つ構造体です。
//topLeftは、矩形の左上の座標です。
//bottomRightは、矩形の右下の座標です。
struct BoundingBox {
	Point topLeft;
	Point bottomRight;
};

