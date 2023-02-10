#pragma once

#include "CollisionPrimitive.h"

/// <summary>
/// �����蔻��v���~�e�B�u
/// </summary>
class Collision
{
public:
	/// <summary>
	/// ���ƕ��ʂ̓����蔻��
	/// </summary>
	/// <param name="sphere">��</param>
	/// <param name="plane">����</param>
	/// <param name="inter">��_�i���ʏ�̍ŋߐړ_�j</param>
	/// <returns�������Ă��邩�ۂ�></returns>
	static bool CheckSpere2Plane(const Sphere& sphere, const Plane& plane, DirectX::XMVECTOR* inter = nullptr);
};

