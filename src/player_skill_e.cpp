#include <player_skill_e.h>
#include <player_manager.h>
#include <enemy_generator.h>
#include <point_2d.h>
#include <sound_manager.h>
PlayerSkillE::PlayerSkillE()
{
    cooldown = 0;
    cooldown_base = 450;
    duration = 0;
    duration_base = 70;

    circle_on = TextureManager::LoadTexture("img/player/e_circle_on.png");
    circle_off = TextureManager::LoadTexture("img/player/e_circle_off.png");
    circle.x = 680, circle.y = 450;
    circle.w = circle.h = 80;

    transform = new TransformComponent(348, 275, 0, 100, 100);
    sprite = new SpriteComponent("img/player/e_animation.png", transform, false);

}

PlayerSkillE::~PlayerSkillE() 
{
    delete transform;
    delete sprite;
    SDL_DestroyTexture(circle_on);
    SDL_DestroyTexture(circle_off);
}

void PlayerSkillE::Update()
{
    if (duration > 0)
    {
        sprite->Update();
    }
}
void PlayerSkillE::Render()
{
    if (cooldown == 0)
        TextureManager::Draw(circle_on, circle);
    else
    {
        cooldown--;
        TextureManager::Draw(circle_off, circle);
    }
    if (duration > 0)
    {
        duration--;
        sprite->Draw();
    }
}
void PlayerSkillE::ExecuteSkill()
{
    
    if (cooldown == 0 || cooldown >= 40)
    {
        if (player->direction)
            player->sprite->ApplyAnimation("sword_right");
        else 
            player->sprite->ApplyAnimation("sword_left");
    }
    if (cooldown > 0)
        return;
    sound_manager->PlayE();
    duration = duration_base;
    cooldown = cooldown_base;
    
}
