#include <world_map.h>

const Uint8 *keyboard_state = SDL_GetKeyboardState(NULL);
WorldMap::WorldMap()
{
    grass[0] = TextureManager::LoadTexture("res/grass_00.png");
    grass[1] = TextureManager::LoadTexture("res/grass_01.png");
    grass[2] = TextureManager::LoadTexture("res/grass_10.png");
    grass[3] = TextureManager::LoadTexture("res/grass_11.png");
    grass[4] = TextureManager::LoadTexture("res/grass_20.png");
    grass[5] = TextureManager::LoadTexture("res/grass_21.png");
    xdif = ydif = 0;
}

WorldMap::~WorldMap()
{}

int WorldMap::GetTileType(int x, int y)
{
    uint32_t tile_seed = x * 31 + y * 71 + x * y;
    rng.seed(tile_seed);
    return rng() % 6;
}

void WorldMap::UpdateMap()
{
    if (keyboard_state[SDL_SCANCODE_A] && keyboard_state[SDL_SCANCODE_W])
    {
        std::cout << "Left, Up\n";
        xdif -= 2;
        ydif -= 2;
        return;
    }
    if (keyboard_state[SDL_SCANCODE_D] && keyboard_state[SDL_SCANCODE_W])
    {
        std::cout << "Right, Up\n";
        xdif += 2;
        ydif -= 2;
        return;
    }
    if (keyboard_state[SDL_SCANCODE_A] && keyboard_state[SDL_SCANCODE_S])
    {
        std::cout << "Left, Down\n";
        xdif -= 2;
        ydif += 2;
        return;
    }
    if (keyboard_state[SDL_SCANCODE_D] && keyboard_state[SDL_SCANCODE_S])
    {
        std::cout << "Right, Down\n";
        xdif += 2;
        ydif += 2;
        return;
    }
    if (keyboard_state[SDL_SCANCODE_W])
    {
        std::cout << "Up\n";
        ydif -= 2;
    }
    if (keyboard_state[SDL_SCANCODE_S])
    {
        std::cout << "Down\n";
        ydif += 2;
    }
    if (keyboard_state[SDL_SCANCODE_A])
    {
        std::cout << "Left\n";
        xdif -= 2;
    }
    if (keyboard_state[SDL_SCANCODE_D])
    {
        std::cout << "Right\n";
        xdif += 2;
    }
}

void WorldMap::RenderMap()
{
    int x_left = -((xdif % 32 + 32) % 32);

    int y_left = -((ydif % 32 + 32) % 32);
    int X_tile = (xdif / 32) + (x_left == 0 ? 0 : (xdif < 0 ? -1 : 0));
    int Y_tile = (ydif / 32) + (y_left == 0 ? 0 : (ydif < 0 ? -1 : 0));
    for (int x = x_left, x_tile = X_tile; x < 800; x += 32, x_tile++)
        for (int y = y_left, y_tile = Y_tile; y < 640; y += 32, y_tile++)
    {
        int tile_type = WorldMap::GetTileType(x_tile, y_tile);
        tmp_dest.h = tmp_dest.w = 32;
        tmp_dest.x = x;
        tmp_dest.y = y;
            
        TextureManager::Draw(grass[tile_type], tmp_dest);
    }
}

// phát triển ứng dụng di động - thầy Tân
// thiết kế giao diện người dùng - cô Duyên
// kho dữ liệu, các hệ thống thương mại điện tử - thầy Quang Hưng
// quản trị mạng - Dương Lê Minh
// các vấn đề hiện đại cntt, kiểm thử - cô Trang
// AI - Vinh
// nguyên lí hệ điều hành - Trần Mai Vũ