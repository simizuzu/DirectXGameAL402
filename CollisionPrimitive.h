#pragma once
#include <DirectXMath.h>

class CollisionPrimitive
{
};

/// <summary>
/// �@���t���O�p�`�i���v��肪�\�ʁj
/// </summary>
class Triangle
{
public:
	// ���_���W3��
	DirectX::XMVECTOR p0;
	DirectX::XMVECTOR p1;
	DirectX::XMVECTOR p2;
	// �@���x�N�g��
	DirectX::XMVECTOR normal;
};

struct Sphere
{
	DirectX::XMVECTOR center = { 0,0,0,1 };
	float radius = 1.0f;
};

struct Plane
{
	DirectX::XMVECTOR normal = { 0,1,0,0 };
	float distance = 0.0f;
};