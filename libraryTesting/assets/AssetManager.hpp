#pragma once

#include <assert.h>

#include <SFML/Graphics.hpp>
#include <map>

#ifndef _ASSET_MANAGER_HPP
#define _ASSET_MANAGER_HPP

class AssetManager{
    public:
        AssetManager();
        static sf::Texture &GetTexture(std::string const &filename);
        static sf::Font &GetFont(std::string const &filename);
        //static sf::Sprite &GetSprite(std::string const& filename);
    
    private:
        std::map<std::string, sf::Texture> m_Textures;
        std::map<std::string, sf::Font> m_Fonts;
        //std::map<std::string, sf::Sprite> m_Sprites;

        static AssetManager *sInstance;
};

#endif