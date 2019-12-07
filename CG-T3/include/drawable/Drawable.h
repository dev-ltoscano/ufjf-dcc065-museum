#ifndef DRAWABLE_H_INCLUDED
#define DRAWABLE_H_INCLUDED

#include "../primitive/RGBColor.h"
#include "../material/Material.h"

class Drawable : public Material
{
    private:
        // Cor do objeto
        RGBColor rgbColor;
        // Tipo de material do objeto
        MaterialType materialType;

        bool enableTexture = false;
        int textureId = -1;
    public:
        // Obt�m a cor do objeto
        virtual RGBColor getColor();
        // Define a cor do objeto
        virtual void setColor(RGBColor rgbColor);

        // Obt�m o material do objeto
        virtual MaterialType getMaterialType();
        // Define o material do objeto
        virtual void setMaterialType(MaterialType materialType);

        // M�todos para desenho do objeto
        virtual void draw() = 0;
        virtual void drawWireFrame() = 0;

        virtual bool hasTexture();
        virtual void setEnableTexture(bool enableTexture);

        virtual int getTextureId();
        virtual void setTextureId(int textureId);
};

#endif // DRAWABLE_H_INCLUDED