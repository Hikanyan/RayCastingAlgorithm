#include <time.h>
#include <string.h>
#include "../dxlib_ext/dxlib_ext.h"
#include "RayCastingAlgorithm.h"

//rayIntersectsRectangleは、rayOriginからrayDirectionに向かう光線がrectangleと交差するかどうかを判定します。
bool rayIntersectsRectangle(const Point& rayOrigin, const Point& rayDirection, const BoundingBox& rectangle) {
	//rayDirectionを正規化します。
	//rectangle.topLeft.x から rayOrigin.x への距離を rayDirection.x で割ります。すると、射線の交差範囲の下限が求まります。
	float tmin = (rectangle.topLeft.x - rayOrigin.x) / rayDirection.x;
	float tmax = (rectangle.bottomRight.x - rayOrigin.x) / rayDirection.x;
	//rayDirectionが負の場合、tminとtmaxを交換します。矩形の上下境界を正しく処理するためです。
	if (tmin > tmax) {
		std::swap(tmin, tmax);
	}

	//rayDirectionを正規化します。
	//rectangle.topLeft.y から rayOrigin.y への距離を rayDirection.y で割ります。すると、射線の交差範囲の下限が求まります。
	float tymin = (rectangle.topLeft.y - rayOrigin.y) / rayDirection.y;
	float tymax = (rectangle.bottomRight.y - rayOrigin.y) / rayDirection.y;
	//rayDirectionが負の場合、tyminとtymaxを交換します。矩形の上下境界を正しく処理するためです。
	if (tymin > tymax) {
		std::swap(tymin, tymax);
	}
	/*
	tminとtmaxの値、およびtyminとtymaxの値を比較し、
	交差がない場合は早期に処理を終了し、falseを返します。
	つまり、射線と矩形が交差していない場合には、
	後続の処理を行わずに交差判定結果を返します。
	*/
	if ((tmin > tymax) || (tymin > tmax))return false;
	//射線の交差範囲の下限を更新します。
	if (tymin > tmin) tmin = tymin;
	//射線の交差範囲の上限を更新します。
	if (tymax < tmax) tmax = tymax;
	//射線の交差範囲が0より大きい場合、射線と矩形は交差していることをTrureで返します。
	return (tmin < 1.0f && tmax > 0.0f);
}