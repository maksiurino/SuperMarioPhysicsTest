#pragma once

#include <string>
#include <SDL3/SDL.h>
#include <vector>

class Sprite
{
    public:
    Sprite(const std::string& path, SDL_Renderer *renderer);
    void draw(SDL_Renderer *renderer) const;
    [[nodiscard]] float getScale() const;
    void setScale(float new_scale);
    [[nodiscard]] SDL_FRect getDrawRect() const;
    void setDrawRect(SDL_FRect new_draw_rect);
    [[nodiscard]] SDL_Texture* getTexture() const;
    void setPosition(const std::vector<float>* new_position);
    [[nodiscard]] std::vector<float> getPosition() const;
    private:
    std::vector<float> position{0, 0};
    SDL_Texture* texture;
    int texture_width;
    int texture_height;
    float scale = 1;
    SDL_FRect draw_rect;
    bool draw_rect_set = false;
};