#pragma once
#include<wrl.h>
#include<DirectXMath.h>
#include <d3d12.h>

/// <summary>
/// ���C�g
/// </summary>
class DirectionalLight
{
private://�G�C���A�X
	//Microsoft::WRL::���ȗ�
	template<class T>using ComPtr = Microsoft::WRL::ComPtr<T>;
	//DirectX::���ȗ�
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMVECTOR = DirectX::XMVECTOR;
	using XMMATRIX = DirectX::XMMATRIX;

public://�T�u�N���X
	//�萔�o�b�t�@�p�f�[�^�\����
	struct ConstBufferData
	{
		XMVECTOR lightv;//���C�g�ւ̕�����\���x�N�g��
		XMFLOAT3 lightcolor;//���C�g�̐F
		unsigned int active;
	};

private://�ÓI�����o�ϐ�
	//�f�o�C�X
	static ID3D12Device* device;

public://�ÓI�����o�֐�

	/// <summary>
	/// �ÓI������
	/// </summary>
	/// <param name="device">�f�o�C�X</param>
	static void StaticInitialize(ID3D12Device* device);

	/// <summary>
	/// �C���X�^���X����
	/// </summary>
	/// <returns>�C���X�^���X</returns>
	static DirectionalLight* Create();

private:
	//�萔�o�b�t�@
	ComPtr<ID3D12Resource>constBuff;
	//���C�g��������(�P�ʃx�N�g��)
	XMVECTOR lightdir = { 1,0,0,0 };
	//���C�g�F
	XMFLOAT3 lightcolor = { 1,1,1 };
	//�_�[�e�B�t���O
	bool dirty = false;
	// �L���t���O
	bool active = false;

public:

	/// <summary>
	/// ������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �萔�o�b�t�@�փf�[�^�]��
	/// </summary>
	void TransferConstBuffer();

	/// <summary>
	/// ���C�g�������Z�b�g
	/// </summary>
	/// <param name="light">���C�g����</param>
	void SetLightDir(const XMVECTOR& light);

	/// <summary>
	/// ���C�g�F���Z�b�g
	/// </summary>
	/// <param name="lightcolor">���C�g�F</param>
	void SetLightColor(const XMFLOAT3& lightcolor);

	XMVECTOR GetLightDir() { return lightdir; }
	XMFLOAT3 GetLightColor() { return lightcolor; }

	/// <summary>
	/// �L���t���O���Z�b�g
	/// </summary>
	/// <param name="active">�L���t���O</param>
	inline void SetActive(bool active) { this->active = active; }

	/// <summary>
	/// �L���`�F�b�N
	/// </summary>
	/// <returns>�L���t���O</returns>
	inline bool IsActive() { return active; }

	/// <summary>
	/// �X�V
	/// </summary>
	void Update();

	/// <summary>
	/// �`��
	/// </summary>
	/// <param name="cmdList"></param>
	/// <param name="rootParameterIndex"></param>
	void Draw(ID3D12GraphicsCommandList* cmdList, UINT rootParameterIndex);
};
