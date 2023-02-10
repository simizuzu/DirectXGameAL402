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

	/// <summary>
	/// �e���g�O�p�`�̍ŋߐړ_�����߂�
	/// </summary>
	/// <param name="point">�_</param>
	/// <param name="triangle">�O�p�`</param>
	/// <param name="closest">�ŋߐړ_</param>
	static void ClosestPtPoint2Triangle(const DirectX::XMVECTOR& point, const Triangle& triangle, DirectX::XMVECTOR* closest);

	/// <summary>
	/// ���Ɩ@���t���O�p�`�̓�����`�F�b�N
	/// </summary>
	/// <param name="sphere"��></param>
	/// <param name="triangle">�O�p�`</param>
	/// <param name="inter">��_�i�O�p�`�̍ŋߐړ_�j</param>
	/// <returns>�������Ă��邩�ۂ�</returns>
	static bool CheckSphere2Triangle(const Sphere& sphere, const Triangle& triangle, DirectX::XMVECTOR* inter = nullptr);
};

