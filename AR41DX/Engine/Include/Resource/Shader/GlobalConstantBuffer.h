#pragma once
#include "ConstantBufferData.h"
class CGlobalConstantBuffer :
    public CConstantBufferData
{
public:
	CGlobalConstantBuffer();
	CGlobalConstantBuffer(const CGlobalConstantBuffer& Buffer);
	virtual ~CGlobalConstantBuffer();

private:
	GlobalCBuffer	m_BufferData;

public:
	virtual bool Init();
	virtual void UpdateBuffer();
	virtual CGlobalConstantBuffer* Clone();

public:
	void SetDeltaTime(float DeltaTime)
	{
		m_BufferData.DeltaTime = DeltaTime;
	}

	void SetAccTime(float AccTime)
	{
		m_BufferData.AccTime = AccTime;
	}

	void SetResolution(float Width, float Height)
	{
		m_BufferData.Resolution = Vector2(Width, Height);
	}
};

