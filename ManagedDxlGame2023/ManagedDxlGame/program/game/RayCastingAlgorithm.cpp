#include <time.h>
#include <string.h>
#include "../dxlib_ext/dxlib_ext.h"
#include "RayCastingAlgorithm.h"

//rayIntersectsRectangle�́ArayOrigin����rayDirection�Ɍ�����������rectangle�ƌ������邩�ǂ����𔻒肵�܂��B
bool rayIntersectsRectangle(const Point& rayOrigin, const Point& rayDirection, const BoundingBox& rectangle) {
	//rayDirection�𐳋K�����܂��B
	//rectangle.topLeft.x ���� rayOrigin.x �ւ̋����� rayDirection.x �Ŋ���܂��B����ƁA�ː��̌����͈͂̉��������܂�܂��B
	float tmin = (rectangle.topLeft.x - rayOrigin.x) / rayDirection.x;
	float tmax = (rectangle.bottomRight.x - rayOrigin.x) / rayDirection.x;
	//rayDirection�����̏ꍇ�Atmin��tmax���������܂��B��`�̏㉺���E�𐳂����������邽�߂ł��B
	if (tmin > tmax) {
		std::swap(tmin, tmax);
	}

	//rayDirection�𐳋K�����܂��B
	//rectangle.topLeft.y ���� rayOrigin.y �ւ̋����� rayDirection.y �Ŋ���܂��B����ƁA�ː��̌����͈͂̉��������܂�܂��B
	float tymin = (rectangle.topLeft.y - rayOrigin.y) / rayDirection.y;
	float tymax = (rectangle.bottomRight.y - rayOrigin.y) / rayDirection.y;
	//rayDirection�����̏ꍇ�Atymin��tymax���������܂��B��`�̏㉺���E�𐳂����������邽�߂ł��B
	if (tymin > tymax) {
		std::swap(tymin, tymax);
	}
	/*
	tmin��tmax�̒l�A�����tymin��tymax�̒l���r���A
	�������Ȃ��ꍇ�͑����ɏ������I�����Afalse��Ԃ��܂��B
	�܂�A�ː��Ƌ�`���������Ă��Ȃ��ꍇ�ɂ́A
	�㑱�̏������s�킸�Ɍ������茋�ʂ�Ԃ��܂��B
	*/
	if ((tmin > tymax) || (tymin > tmax))return false;
	//�ː��̌����͈͂̉������X�V���܂��B
	if (tymin > tmin) tmin = tymin;
	//�ː��̌����͈͂̏�����X�V���܂��B
	if (tymax < tmax) tmax = tymax;
	//�ː��̌����͈͂�0���傫���ꍇ�A�ː��Ƌ�`�͌������Ă��邱�Ƃ�Trure�ŕԂ��܂��B
	return (tmin < 1.0f && tmax > 0.0f);
}