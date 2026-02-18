#include "sprite.hpp"

Sprite::Sprite(const std::string& path, SDL_Renderer *renderer)
{
    char* png_path = nullptr;
    SDL_asprintf(&png_path, (static_cast<std::string>(SDL_GetBasePath()) + "Resources\\" + path + ".png").c_str());
    SDL_Surface* surface = SDL_LoadPNG(png_path);
    if (!surface)
    {
        SDL_ShowSimpleMessageBox(
            SDL_MESSAGEBOX_ERROR,
            "Error",
            SDL_GetError(),
            nullptr
        );
        return;
    }

    SDL_free(png_path);

    texture_width = surface->w;
    texture_height = surface->h;

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        SDL_ShowSimpleMessageBox(
            SDL_MESSAGEBOX_ERROR,
            "Error",
            ("Couldn't create static texture: " + std::string(SDL_GetError()) + "\n").c_str(),
            nullptr
        );
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

SDL_FRect Sprite::getDrawRect() const
{
    return draw_rect;
}

SDL_Texture* Sprite::getTexture() const
{
    return texture;
}

void Sprite::setDrawRect(const SDL_FRect new_draw_rect)
{
    draw_rect = new_draw_rect;
    draw_rect_set = true;
}

void Sprite::setPosition(const std::vector<float>* new_position)
{
    position = *new_position;
}

std::vector<float> Sprite::getPosition() const
{
    return position;
}

void Sprite::draw(SDL_Renderer* renderer) const
{
    SDL_FRect dst_rect;

    dst_rect.x = position[0];
    dst_rect.y = position[1];
    dst_rect.w = static_cast<float>(texture_width) * scale;
    dst_rect.h = static_cast<float>(texture_height) * scale;

    if (!draw_rect_set)
    {
        SDL_RenderTexture(renderer, texture, nullptr, &dst_rect);
    } else
    {
        SDL_FRect dest_rect = draw_rect;
        dest_rect.w = draw_rect.w * scale;
        dest_rect.h = draw_rect.h * scale;
        SDL_RenderTexture(renderer, texture, &draw_rect, &dest_rect);
    }
}
