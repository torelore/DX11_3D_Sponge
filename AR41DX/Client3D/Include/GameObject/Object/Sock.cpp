#include "Sock.h"

#include "Component/ColliderOBB3D.h"
#include "Component/StaticMeshComponent.h"

CSock::CSock()
{
}

CSock::CSock(const CSock& Obj) :
	CCollectibleItems(Obj)
{
	m_Mesh = (CStaticMeshComponent*)FindComponent("Mesh");
	m_Collider = (CColliderOBB3D*)FindComponent("OBB3D");
}

CSock::~CSock()
{
}

void CSock::Start()
{
	CCollectibleItems::Start();
}

bool CSock::Init()
{
	CCollectibleItems::Init();

	m_Mesh = CreateComponent<CStaticMeshComponent>("Mesh");
	m_Collider = CreateComponent<CColliderOBB3D>("OBB3D");

	SetRootComponent(m_Mesh);

	m_Mesh->AddChild(m_Collider);
	m_Mesh->SetMesh("Sock");

	m_Collider->SetBoxHalfSize(m_Mesh->GetMeshSize() / 2.f);
	m_Collider->SetCollisionProfile("Collectible");
	m_Collider->SetCollisionCallback<CSock>(ECollision_Result::Collision, this, &CSock::PlayerCollisionItem);

	m_Collider->SetInheritRotX(true);
	m_Collider->SetInheritRotY(true);
	m_Collider->SetInheritRotZ(true);

	return true;
}

void CSock::Update(float DeltaTime)
{
	CCollectibleItems::Update(DeltaTime);
}

void CSock::PostUpdate(float DeltaTime)
{
	CCollectibleItems::PostUpdate(DeltaTime);
}

CSock* CSock::Clone() const
{
	return new CSock(*this);
}

void CSock::Save(FILE* File)
{
	CCollectibleItems::Save(File);
}

void CSock::Load(FILE* File)
{
	CCollectibleItems::Load(File);
}

void CSock::PlayerCollisionItem(const CollisionResult& result)
{
	CCollectibleItems::PlayerCollisionItem(result);
}

