#pragma once
#include<wrl.h>
#include<DirectXMath.h>
#include <d3d12.h>
#include "DirectionalLight.h"

class LightGroup
{
private: // �G�C���A�X
	//Microsoft::WRL::���ȗ�
	template<class T>using ComPtr = Microsoft::WRL::ComPtr<T>;
	//DirectX::���ȗ�
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMVECTOR = DirectX::XMVECTOR;
	using XMMATRIX = DirectX::XMMATRIX;

public: // �萔
	// ���C�g�̐�
	static const int DirLightNum = 3;

public: // �T�u�N���X
	// �萔�o�b�t�@�փf�[�^�\����
	struct ConstBufferData
	{
		// �����̐F
		XMFLOAT3 ambientColor;
		float pad1;
		// ���s�����p
		DirectionalLight::ConstBufferData dirLights[DirLightNum];
	};

private: // �ÓI�����o�ϐ�
	// �f�o�C�X
	static ID3D12Device* device;

private: // �ÓI�����o�֐�
	/// <summary>
	/// �ÓI������
	/// </summary>
	/// <param name="device">�f�o�C�X</param>
	static void StaticInitialize(ID3D12Device* device);

public: // �����o�֐�
	/// <summary>
	/// ������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �萔�o�b�t�@�փf�[�^�]��
	/// </summary>
	void TransferConstBuffer();

	/// <summary>
	/// �����̃��C�g�F���Z�b�g
	/// </summary>
	/// <param name="color"></param>
	void SetAmbientColor(const XMFLOAT3& color);

	/// <summary>
	/// ���s�����̗L���t���O���Z�b�g
	/// </summary>
	/// <param name="index">���C�g�ԍ�</param>
	/// <param name="active">�L���t���O</param>
	void SetDirLightActive(int index, bool active);

	/// <summary>
	/// ���s�����̃��C�g�������Z�b�g
	/// </summary>
	/// <param name="index">���C�g�ԍ�</param>
	/// <param name="lightdir">���C�g����</param>
	void SetDirLightDir(int index, const XMVECTOR& lightdir);

	/// <summary>
	/// ���s�����̃��C�g�F���Z�b�g
	/// </summary>
	/// <param name="index">���C�g�ԍ�</param>
	/// <param name="lightcolor">���C�g�F</param>
	void SetDirLightColor(int index, const XMFLOAT3& lightcolor);

private: // �����o�ϐ�
	//�萔�o�b�t�@
	ComPtr<ID3D12Resource> constBuff;
	// �����̐F
	XMFLOAT3 ambientColor = { 1,1,1 };
	// ���s�����̔z��
	DirectionalLight dirLights[DirLightNum];
	// �_�[�e�B�t���O
	bool dirty = false;
};

