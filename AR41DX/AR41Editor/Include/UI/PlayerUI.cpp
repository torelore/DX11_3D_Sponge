#include "PlayerUI.h"
#include "UI/UIText.h"
#include "UI/UIImage.h"
#include "Scene/SceneManager.h"
#include "Scene/Scene.h"

CPlayerUI::CPlayerUI()
	: m_AllOpacity(3.f)
{
	m_WindowTypeName = "PlayerUI";
}

CPlayerUI::CPlayerUI(const CPlayerUI& Window)
{
	size_t size = std::size(m_MaxHP);
	for (size_t i = 0; i < size; ++i)
	{
		m_MaxHP[i] = FindWidget<CUIImage>("MaxHP" + std::to_string(i));
		m_CurHP[i] = FindWidget<CUIImage>("CurHP" + std::to_string(i));
	}
	m_Socks = FindWidget<CUIImage>("Socks");
	m_Fritter = FindWidget<CUIImage>("Fritter");
	m_Glittering = FindWidget<CUIImage>("Glittering");
}

CPlayerUI::~CPlayerUI()
{
}

void CPlayerUI::Start()
{
	CUIWindow::Start();
}

bool CPlayerUI::Init()
{
	CUIWindow::Init();
	size_t size = std::size(m_MaxHP);
	for (size_t i = 0; i < size; ++i)
	{
		m_MaxHP[i] = CreateWidget<CUIImage>("MaxHP" + std::to_string(i));
		m_MaxHP[i]->SetSize(70.f, 70.f);
		m_MaxHP[i]->SetPos(20.f+75.f*i, 630.f);
		m_MaxHP[i]->SetTexture("MaxHP", TEXT("UI/Bubble.png"));

		m_CurHP[i] = CreateWidget<CUIImage>("CurHP" + std::to_string(i));
		m_CurHP[i]->SetSize(50.f, 50.f);
		m_CurHP[i]->SetPos(30.f + 75.f * i, 635.f);
		m_CurHP[i]->SetTexture("CurHP", TEXT("UI/Underpants.png"));
	}

	m_Fritter = CreateWidget<CUIImage>("Fritter");
	m_Fritter->SetSize(120.f, 120.f);
	m_Fritter->SetPos(600.f, 600.f);
	m_Fritter->SetTexture("Fritter", TEXT("UI/Spatula.png"));

	m_Glittering = CreateWidget<CUIImage>("Glittering");
	m_Glittering->SetSize(70.f, 70.f);
	m_Glittering->SetPos(1180.f, 630.f);
	m_Glittering->SetTexture("Glittering", TEXT("UI/Flower.png"));

	m_Socks = CreateWidget<CUIImage>("Socks");
	m_Socks->SetSize(100.f, 85.f);
	m_Socks->SetPos(1140.f, 30.f);
	m_Socks->SetTexture("Socks", TEXT("UI/Sock.png"));

	return true;
}

void CPlayerUI::Update(float DeltaTime)
{
	CUIWindow::Update(DeltaTime);
	if(m_AllOpacity>0.f)
	{
		m_AllOpacity -= DeltaTime;
		SetPlayerUIOpacity(m_AllOpacity);
	}
}

void CPlayerUI::PostUpdate(float DeltaTime)
{
	CUIWindow::PostUpdate(DeltaTime);
}

void CPlayerUI::Render()
{
	CUIWindow::Render();
}

CPlayerUI* CPlayerUI::Clone()
{
	return new CPlayerUI(*this);
}

void CPlayerUI::Save(FILE* File)
{
	CUIWindow::Save(File);
}

void CPlayerUI::Load(FILE* File)
{
	CUIWindow::Load(File);
	size_t size = std::size(m_MaxHP);
	for (size_t i = 0; i < size; ++i)
	{
		m_MaxHP[i] = FindWidget<CUIImage>("MaxHP" + std::to_string(i));
		m_CurHP[i] = FindWidget<CUIImage>("CurHP" + std::to_string(i));
	}
	m_Socks = FindWidget<CUIImage>("Socks");
	m_Fritter = FindWidget<CUIImage>("Fritter");
	m_Glittering = FindWidget<CUIImage>("Glittering");
}

void CPlayerUI::SetPlayerUIOpacity(float opacity)
{
	size_t size = std::size(m_MaxHP);
	for (size_t i = 0; i < size; ++i)
	{
		m_MaxHP[i]->SetOpacity(opacity);
		m_CurHP[i]->SetOpacity(opacity);
	}
	m_Socks->SetOpacity(opacity);
	m_Fritter->SetOpacity(opacity);
	m_Glittering->SetOpacity(opacity);
}