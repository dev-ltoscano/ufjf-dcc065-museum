#include "drawable/Drawable.h"

RGBColor Drawable::getColor()
{
    return this->rgbColor;
}

void Drawable::setColor(RGBColor rgbColor)
{
    this->rgbColor = rgbColor;
}

MaterialType Drawable::getMaterialType()
{
    return this->materialType;
}

void Drawable::setMaterialType(MaterialType materialType)
{
    this->materialType = materialType;
}

bool Drawable::hasTexture()
{
    return this->enableTexture;
}

void Drawable::setEnableTexture(bool enableTexture)
{
    this->enableTexture = enableTexture;
}

int Drawable::getTextureId()
{
    return this->textureId;
}

void Drawable::setTextureId(int textureId)
{
    this->textureId = textureId;
}
