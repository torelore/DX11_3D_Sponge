#include "TestSceneInfo.h"
#include "Scene/Scene.h"
#include "../GameObject/Player.h"
#include "../GameObject/Monster.h"
#include "../GameObject/Weapon.h"
#include "../GameObject/KingJellyfish.h"
#include "../GameObject/Jellyfish.h"
#include "../GameObject/ElectricRing.h"
#include "../GameObject/Fodder.h"
#include "../GameObject/Hammer.h"
#include "../GameObject/Duplicatotron.h"
#include "../GameObject/BikiniBottomBuildings.h"
#include "../GameObject/JellyfishField.h"
#include "../GameObject/Object/JumpTree.h"
#include "../GameObject/Object/TeleportBox.h"
#include "../GameObject/Object/CheckPoint.h"
#include "../GameObject/Object/Gate.h"
#include "../GameObject/TeeterRock.h"
#include "../GameObject/Cannon.h"
#include "../GameObject/Pufferfish.h"
#include "Component/TerrainComponent.h"
#include "Component/BillboardComponent.h"
#include "Component/ParticleComponent.h"
#include "Component/StaticMeshComponent.h"
#include "../UI/PlayerUI.h"
#include "Component/LightComponent.h"
#include "../GameObject/Object/Pool.h"

CTestSceneInfo::CTestSceneInfo() : m_Time(0.f)
{
}

CTestSceneInfo::~CTestSceneInfo()
{
}

bool CTestSceneInfo::Init()
{
	CSceneInfo::Init();

	CGameObject* GlobalLightObj = m_Owner->CreateObject<CGameObject>("GlobalLight");
	CLightComponent* GlobalLightComponent = GlobalLightObj->CreateComponent<CLightComponent>("GlobalLight");
	GlobalLightComponent->SetLightType(ELightType::Direction);
	GlobalLightComponent->SetRelativeRotation(0, 90.f, 0.f);
	m_Owner->GetLightManager()->SetGlobalLightObject(GlobalLightObj);

	CPlayer* Player = m_Owner->CreateObject<CPlayer>("Player");
	Player->SetWorldPosition(16500.f, 0.f, 12200.f);
	SetPlayerObject(Player);

	//CTeeterRock* TeeterRock = m_Owner->CreateObject<CTeeterRock>("TeeterRock");
	//TeeterRock->SetWorldPosition(16500.f, 0.f, 12200.f);

	//*CPufferfish* Cannon = m_Owner->CreateObject<CPufferfish>("Cannon");
	//Cannon->SetWorldPosition(16500.f, 0.f, 12200.f);*/

	//// 보원테스트 구간
	//CJumpTree* JumpTree = m_Owner->CreateObject<CJumpTree>("JumpTree");
	//JumpTree->SetWorldPosition(17000.f, 0.f, 12500.f);
	//
	/*CTeeterRock* TeeterRock = m_Owner->CreateObject<CTeeterRock>("TeeterRock");
	TeeterRock->SetWorldPosition(16500.f, 0.f, 12200.f);*/

	// 보원테스트 구간
	CJumpTree* JumpTree = m_Owner->CreateObject<CJumpTree>("JumpTree");
	JumpTree->SetWorldPosition(17000.f, 0.f, 12500.f);
	
	//CTeleportBox* TeleportBox1 = m_Owner->CreateObject<CTeleportBox>("TeleportBox");
	//TeleportBox1->SetBoxIndex(1);

	//CTeleportBox* TeleportBox2 = m_Owner->CreateObject<CTeleportBox>("TeleportBox");
	//TeleportBox2->SetBoxIndex(2);
	//Vector3 TeleportBox2Pos = TeleportBox2->GetWorldPos();

	//CCheckPoint* CheckPoint = m_Owner->CreateObject<CCheckPoint>("CheckPoint");
	//CheckPoint->SetWorldPosition(17500.f, 0.f, 13700.f);

	//CGate* Gate = m_Owner->CreateObject<CGate>("Gate");
	//Gate->SetWorldPosition(16800.f, 0.f, 13000.f);

	CFodder* Fodder = m_Owner->CreateObject<CFodder>("Fodder");
	Fodder->SetWorldPosition(17000.f, 0.f, 14000.f);


	/*CTeeterRock* TeeterRock = m_Owner->CreateObject<CTeeterRock>("TeeterRock");
	TeeterRock->SetWorldPosition(16500.f, 0.f, 12200.f);*/

	//CCannon* Cannon = m_Owner->CreateObject<CCannon>("Cannon");
	//Cannon->SetWorldPosition(16500.f, 0.f, 12200.f);

	//Cannon->AddWorldRotationY(45.f);

	CGameObject* TerrainObj = m_Owner->CreateObject<CGameObject>("TerrainObj");
	CTerrainComponent* TerrainComponent = TerrainObj->CreateComponent<CTerrainComponent>("TerrainComponent");
	TerrainComponent->CreateTerrain(680, 631, 40.f, 40.f, TEXT("LandScape/BikiniCity_Height.png"));

	//애니메이션 문제
	//CPatric* Patric = m_Owner->CreateObject<CPatric>("Patric");
	//Patric->SetWorldPosition(16500.f, 0.f, 12200.f);

	CPool* Pool = m_Owner->CreateObject<CPool>("Pool");
	Pool->SetWorldPosition(16000, 0.f, 12200.f);

	CKingJellyfish* KingJellyfish = m_Owner->CreateObject<CKingJellyfish>("KingJellyfish");
	KingJellyfish->SetWorldPosition(16500.f, 0.f, 13000.f);


	//CGameObject* GateArm = m_Owner->CreateObject<CGameObject>("GateArm");


	//CStaticMeshComponent* Arm = GateArm->CreateComponent<CStaticMeshComponent>("Mesh");
	//Arm->SetMesh("GateArm");
	//Arm->SetWorldPosition(16500.f, 0.f, 12200.f);
	
	

	//CElectricRing* ElectricRing = m_Owner->CreateObject<CElectricRing>("ElectricRing");
	//ElectricRing->SetWorldPosition(16500.f, 500.f, 12200.f);

	return true;
}

void CTestSceneInfo::Update(float DeltaTime)
{
	CSceneInfo::Update(DeltaTime);

	/*m_Time += DeltaTime;

	if (m_Time >= 10.0f)
	{
		m_Time = 0.f;

		CPufferfish* Pufferfish = m_Owner->CreateObject<CPufferfish>("Cannon");
		Pufferfish->SetWorldPosition(16500.f, 500.f, 12200.f);
	}*/
}
