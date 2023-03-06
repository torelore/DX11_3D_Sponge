#pragma once

#include "EngineSetting.h"

class CDefaultSetting :
    public CEngineSetting
{
public:
    CDefaultSetting();
    virtual ~CDefaultSetting();

public:
    virtual void Init();

private:
    void CreateCDO();
    void LoadResource();
    void SetInput();
    void SetCollision();

    // Player
    void LoadSpongebob();
    void LoadPatrick();
    void LoadSandy();

    // Sound
    void LoadPlayerSound();
    void LoadSound();

    // Monster
    void LoadRoboSponge();
    void LoadKingJellyfish();
    void LoadJellyfish();
    void LoadTikis();

    // NPC
    void LoadMrKrabs();
    void LoadSquidward();
    void LoadPatric_Npc();
    void LoadTaxi();

    void LoadBuildings();
    void LoadEnemies();
    void LoadParticle();
};

