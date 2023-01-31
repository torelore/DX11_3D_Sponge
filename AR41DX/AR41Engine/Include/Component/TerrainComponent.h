#pragma once

#include "PrimitiveComponent.h"

class CTerrainComponent :
    public CPrimitiveComponent
{
    friend class CGameObject;
    friend class CScene;

protected:
    CTerrainComponent();
    CTerrainComponent(const CTerrainComponent& component);
    virtual ~CTerrainComponent();

private:
    int m_CountX;
    int m_CountY;
    Vector2 m_CellSize;
    Vector2 m_Size;
    std::vector<Vertex3DStatic> m_vecVtx;
    std::vector<unsigned int> m_vecIndex;
    std::vector<Vector3> m_vecFaceNormal;
    class CTerrainConstantBuffer* m_CBuffer;
    bool m_Grid;

public:
    bool GetGrid() const
    {
        return m_Grid;
    }

public:
    void SetDetailLevel(float Level);
    void SetSplatCount(int Count);

public:
    virtual bool SetMesh(const std::string& Name);
    virtual bool SetMesh(class CMesh* Mesh);
    virtual bool SetMesh(const std::string& Name, const TCHAR* FileName, const std::string& PathName = TEXTURE_PATH);
    virtual bool SetMeshFullPath(const std::string& Name, const TCHAR* FullPath);

public:
    virtual void Start();
    virtual bool Init();
    virtual void Update(float DeltaTime);
    virtual void PostUpdate(float DeltaTime);
    virtual void Render();
    virtual CTerrainComponent* Clone()    const;
    virtual void Save(FILE* File);
    virtual void Load(FILE* File);


public:
    void CreateTerrain(int CountX, int CountY, float SizeX, float SizeY, const TCHAR* HeightMapName = nullptr, const std::string& HeightMapPath = TEXTURE_PATH);

private:
    void ComputeNormal();
    void ComputeTangent();
};

