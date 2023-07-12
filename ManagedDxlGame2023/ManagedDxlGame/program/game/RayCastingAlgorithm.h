#pragma once
#include "RayCastingAlgorithm.h"


//rayIntersectsRectangle�́ArayOrigin����rayDirection�Ɍ�����������rectangle�ƌ������邩�ǂ����𔻒肵�܂��B

//Point�́Ax��y�̍��W�����\���̂ł��B
struct Point {
	float x;
	float y;
};
//Ray�́Aorigin��direction�̍��W�����\���̂ł��B
//origin�́A�����̎n�_�̍��W�ł��B
//direction�́A�����̕����̍��W�ł��B
struct Ray {
	Point origin;
	Point direction;
};
//BoundingBox�́AtopLeft��bottomRight�̍��W�����\���̂ł��B
//topLeft�́A��`�̍���̍��W�ł��B
//bottomRight�́A��`�̉E���̍��W�ł��B
struct BoundingBox {
	Point topLeft;
	Point bottomRight;
};

