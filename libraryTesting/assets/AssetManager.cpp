#include "AssetManager.hpp"


AssetManager *AssetManager::sInstance = nullptr;

AssetManager::AssetManager(){
    assert(sInstance == nullptr);
    sInstance = this;
}

sf::Texture& AssetManager::GetTexture(std::string const& filename){
    auto &texMap = sInstance->m_Textures;

    //See if the texture is already loaded
    auto pairFound = texMap.find(filename);

    // If yes, return the texture
    if (pairFound != texMap.end())
        return pairFound->second;
    else{ //Load the texture and return it
        //Create an element in the texture map
        auto &texture = texMap[filename];
        texture.loadFromFile(filename);
        return texture;
        }
}

/*sf::Sprite& AssetManager::GetSprite(std::string const& filename) {
    auto& spriteMap = sInstance->m_Sprites;

    //See if the texture is already loaded
    auto pairFound = spriteMap.find(filename);

    // If yes, return the texture
    if (pairFound != spriteMap.end())
        return pairFound->second;
    else { //Load the texture and return it
        //Create an element in the texture map
        auto& sprite = spriteMap[filename];
        sprite.loadFromFile(filename);
        return sprite;
    }
}*/

sf::Font& AssetManager::GetFont(std::string const& filename){
    auto &fontMap = sInstance->m_Fonts;

    //See if the font is already loaded
    auto pairFound = fontMap.find(filename);

    //If yes, return the font
    if (pairFound != fontMap.end())
        return pairFound->second;
    else{
        //Load the font and return it
        //Create an element in the font map
        auto &font = fontMap[filename];
        font.loadFromFile(filename);
        return font;
    }
}