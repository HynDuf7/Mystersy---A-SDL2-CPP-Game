#pragma once
#include <SDL_mixer.h>
class SoundManager
{
public:
    SoundManager();
    ~SoundManager();
    void PlayLevelUp();
    void PlayMonsterAppear();
    void PlayQ();
    void PlayE();
    void PlayShoot();
    void PlaySlash();
    void PlayPlayerDamaged();
    void PlayBossBGM();
    void PlayBGM();
    bool IsPlayingBossBGM();
    void Update();
private:
    bool is_playing_boss_bgm;
    
    int duration_bgm = 60 * 200;

    int duration_boss_bgm = 60 * 315;

    Mix_Music *bgm = NULL;
    Mix_Music *boss_bgm = NULL;

    //The sound effects that will be used
    Mix_Chunk *level_up = NULL;
    Mix_Chunk *monster_appear = NULL;
    Mix_Chunk *Q = NULL;
    Mix_Chunk *E = NULL;
    Mix_Chunk *shoot = NULL;
    Mix_Chunk *slash = NULL;
    Mix_Chunk *player_damaged = NULL;


};

extern SoundManager *sound_manager;