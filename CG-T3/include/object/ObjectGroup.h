#ifndef OBJECTGROUP_H_INCLUDED
#define OBJECTGROUP_H_INCLUDED

#include <string>
#include <vector>

#include "Object.h"
#include "Wall.h"

#include "../drawable/Drawable.h"
#include "../collision/Collider.h"
#include "../primitive/Point.h"

class ObjectGroup
{
    private:
        std::string groupName;
        MaterialType groupMaterialType;

        std::vector<Object*> objectList;
        std::vector<Drawable*> drawableList;
        std::vector<Collider*> colliderList;
        std::vector<Point*> pointList;
    public:
        ObjectGroup(std::string groupName);

        std::string getGroupName();
        MaterialType getGroupMaterialType();

        void addObject(Object *obj, bool isDrawable, bool isCollisible);
        Object* getObject(int index);
        std::vector<Object*>* getObjectList();
        int objectListSize();

        std::vector<Drawable*>* getDrawableList();
        int drawableListSize();

        std::vector<Collider*>* getColliderList();
        int colliderListSize();

        std::vector<BoundingBox*>* getWallBoundingBoxList();
        int wallColliderListSize();

        void addWallPoint(Point *point);
        void removeLastWallPoint();
        std::vector<Point*>* getWallPointList();
        int wallPointListSize();

        double getWallWidth();
        void increaseWallWidth();
        void decreaseWallWidth();
        void setWallWidth(double wallWidth);

        double getWallHeight();
        void increaseWallHeight();
        void decreaseWallHeight();
        void setWallHeight(double wallHeight);

        void setWallHasTexture(bool hasTexture);
        void setWallTextureId(int textureId);
        void setWallHasTexture(int faceId, bool hasTexture);
        void addWallTextureVertex(int faceId, Vertex3D* v0, Vertex3D* v1, Vertex3D* v2, Vertex3D* v3);

        void setMaterialGroup(MaterialType materialType);

        void clearGroup();
};

#endif // OBJECTGROUP_H_INCLUDED
