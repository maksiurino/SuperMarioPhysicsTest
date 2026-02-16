#include "sprite.hpp"

Sprite::Sprite(const std::string& path, SDL_Renderer *renderer)
{
    char* png_path = nullptr;
    SDL_asprintf(&png_path, (static_cast<std::string>(SDL_GetBasePath()) + "Resources\\" + path).c_str());
    SDL_Surface* surface = SDL_LoadPNG(png_path);
    if (!surface)
    {
        SDL_Log("Couldn't load png: %s", SDL_GetError());
        return;
    }

    SDL_free(png_path);

    texture_width = surface->w;
    texture_height = surface->h;

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        SDL_Log("Couldn't create static texture: %s", SDL_GetError());
        return;
    }

    SDL_DestroySurface(surface);
}

float Sprite::getScale() const
{
    return scale;
}

void Sprite::setScale(const float new_scale)
{
    scale = new_scale;
}

void Sprite::draw(SDL_Renderer* renderer) const
{
    SDL_FRect dst_rect;

    dst_rect.x = position.x;
    dst_rect.y = position.y;
    dst_rect.w = static_cast<float>(texture_width) * scale;
    dst_rect.h = static_cast<float>(texture_height) * scale;
    SDL_RenderTexture(renderer, texture, nullptr, &dst_rect);
}
