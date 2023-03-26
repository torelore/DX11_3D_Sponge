#include "RoboSpongeSceneInfo.h"

#include "Scene/Scene.h"

#include "Component/LightComponent.h"
#include "Component/TerrainComponent.h"
#include "Component/StaticMeshComponent.h"
#include "Component/ParticleComponent.h"
#include "Component/ColliderCube.h"
#include "Component/LightComponent.h"
#include "Component/TerrainComponent.h"
#include "../GameObject/Player.h"
#include "../GameObject/Object/Common/Trampoline.h"
#include "../GameObject/Object/CBL/CBL_Platform.h"
#include "../GameObject/Object/CBL/CBL_Floor.h"
#include "../GameObject/BossMonster/RoboSponge/RoboSponge.h"
#include "../UI/TitleSceneUI.h"
#include "../UI/InteractUI.h"
#include "../UI/DialogUI.h"
#include "../UI/PauseUI.h"

CRoboSpongeSceneInfo::CRoboSpongeSceneInfo()
{
	m_ClassTypeName = "RoboSpongeSceneInfo";
}

CRoboSpongeSceneInfo::~CRoboSpongeSceneInfo()
{
}

bool CRoboSpongeSceneInfo::Init()
{
	CSceneInfo::Init();

	CGameObject* GlobalLightObj = m_Owner->CreateObject<CGameObject>("GlobalLight");
	CLightComponent* GlobalLightComponent = GlobalLightObj->CreateComponent<CLightComponent>("GlobalLight");
	GlobalLightComponent->SetLightType(ELightType::Direction);
	GlobalLightComponent->SetRelativeRotation(0.f, 90.f, 0.f);
	m_Owner->GetLightManager()->SetGlobalLightObject(GlobalLightObj);

	CInteractUI* InteractUI = m_Owner->GetViewport()->CreateUIWindow<CInteractUI>("InteractUI");
	CDialogUI* Dialog = m_Owner->GetViewport()->CreateUIWindow<CDialogUI>("DialogUI");
	CPauseUI* PauseUI = m_Owner->GetViewport()->CreateUIWindow<CPauseUI>("PauseUI");

	int TerrainCount = 300;
	float TerrainSize = 40.f;
	Vector2 CenterPos(TerrainCount / 2 * TerrainSize, TerrainCount / 2 * TerrainSize);

	CGameObject* TerrainObj = m_Owner->CreateObject<CGameObject>("TerrainObj");
	CTerrainComponent* TerrainComponent = TerrainObj->CreateComponent<CTerrainComponent>("TerrainComponent");
	TerrainComponent->CreateTerrain(TerrainCount, TerrainCount, TerrainSize, TerrainSize, TEXT("LandScape/RoboSponge_Height.png"));
	TerrainObj->SetWorldPosition(0.f, 0.f, 0.f);

	CRoboSponge* RoboSponge = m_Owner->CreateObject<CRoboSponge>("RoboSponge");
	RoboSponge->SetWorldPosition(CenterPos.x, 1000.f, CenterPos.y);

	float StandardPos = 50 * TerrainSize;

	for (int i = 0; i < 12; i++) {
		float Radian = i * 30.f * PI / 180.f;

		std::string PlatformName = "Platform" + std::to_string(i);
		
		CCBL_Platform* Platform = m_Owner->CreateObject<CCBL_Platform>(PlatformName);
		Platform->SetWorldPosition(CenterPos.x + StandardPos * sinf(Radian), 1800.f, CenterPos.y + StandardPos * cosf(Radian));
		Platform->SetLookBoss(RoboSponge->GetWorldPos());

		break;

		std::string TrampolineName = "Platform" + std::to_string(i);
		CTrampoline* Trampoline = m_Owner->CreateObject<CTrampoline>(TrampolineName);
		Trampoline->SetWorldPosition(CenterPos.x + StandardPos * 1.2 * sinf(Radian), 610.f, CenterPos.y + StandardPos * 1.2 * cosf(Radian));

	}

	CCBL_Floor* Floor = m_Owner->CreateObject<CCBL_Floor>("Floor");
	Floor->SetWorldPosition(CenterPos.x, 600.f, CenterPos.y);


	CPlayer* Player = m_Owner->CreateObject<CPlayer>("Player");
	SetPlayerObject(Player);
	Player->SetWorldPosition(TerrainSize * TerrainCount, 0.f, TerrainSize * TerrainCount);



	return true;
}
