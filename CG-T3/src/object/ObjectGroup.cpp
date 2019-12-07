#include "object/ObjectGroup.h"

using namespace std;

ObjectGroup::ObjectGroup(string groupName)
{
    this->groupName = groupName;
    this->groupMaterialType = White;
    this->addObject(new Wall(), true, false);
}

string ObjectGroup::getGroupName()
{
    return groupName;
}

MaterialType ObjectGroup::getGroupMaterialType()
{
    return groupMaterialType;
}

void ObjectGroup::addObject(Object *obj, bool isDrawable, bool isCollisible)
{
    objectList.push_back(obj);

    if(isDrawable)
    {
        obj->setDrawable(true);
        drawableList.push_back(obj);
    }
    else
    {
        obj->setDrawable(false);
    }

    if(isCollisible)
    {
        obj->setCollisible(true);
        colliderList.push_back(obj);
    }
    else
    {
        obj->setCollisible(false);
    }
}

Object* ObjectGroup::getObject(int index)
{
    return objectList.at(index);
}

vector<Object*>* ObjectGroup::getObjectList()
{
    return &objectList;
}

int ObjectGroup::objectListSize()
{
    return objectList.size();
}

vector<Drawable*>* ObjectGroup::getDrawableList()
{
    return &drawableList;
}

vector<Collider*>* ObjectGroup::getColliderList()
{
    return &colliderList;
}

vector<BoundingBox*>* ObjectGroup::getWallBoundingBoxList()
{
    return ((Wall*)objectList.at(0))->getBoundingBoxList();
}

void ObjectGroup::addWallPoint(Point *point)
{
    ((Wall*)objectList.at(0))->addPoint(point);
    pointList.push_back(point);
}

void ObjectGroup::removeLastWallPoint()
{
    ((Wall*)objectList.at(0))->removeLastPoint();

    if(pointList.size() > 0)
    {
        pointList.pop_back();
    }
}

std::vector<Point*>* ObjectGroup::getWallPointList()
{
    return &pointList;
}

int ObjectGroup::wallPointListSize()
{
    return pointList.size();
}

double ObjectGroup::getWallWidth()
{
    return ((Wall*)objectList.at(0))->getWallWidth();
}

void ObjectGroup::increaseWallWidth()
{
    ((Wall*)objectList.at(0))->increaseWallWidth();
}

void ObjectGroup::decreaseWallWidth()
{
    ((Wall*)objectList.at(0))->decreaseWallWidth();
}

void ObjectGroup::setWallWidth(double wallWidth)
{
    ((Wall*)objectList.at(0))->setWallWidth(wallWidth);
}

double ObjectGroup::getWallHeight()
{
    return ((Wall*)objectList.at(0))->getWallHeight();
}

void ObjectGroup::increaseWallHeight()
{
    ((Wall*)objectList.at(0))->increaseWallHeight();
}

void ObjectGroup::decreaseWallHeight()
{
    ((Wall*)objectList.at(0))->decreaseWallHeight();
}

void ObjectGroup::setWallHeight(double wallHeight)
{
    ((Wall*)objectList.at(0))->setWallHeight(wallHeight);
}

void ObjectGroup::setWallHasTexture(bool hasTexture)
{
    ((Wall*)objectList.at(0))->setEnableTexture(hasTexture);
}

void ObjectGroup::setWallTextureId(int textureId)
{
    ((Wall*)objectList.at(0))->setTextureId(textureId);
}

void ObjectGroup::setWallHasTexture(int faceId, bool hasTexture)
{
    ((Wall*)objectList.at(0))->getFace(faceId)->setEnableTexture(hasTexture);
}

void ObjectGroup::addWallTextureVertex(int faceId, Vertex3D* v0, Vertex3D* v1, Vertex3D* v2, Vertex3D* v3)
{
    Primitive* face = ((Wall*)objectList.at(0))->getFace(faceId);

    face->getTextureVertexList()->clear();
    face->addTextureVertex(v0);
    face->addTextureVertex(v1);
    face->addTextureVertex(v2);
    face->addTextureVertex(v3);
}

void ObjectGroup::setMaterialGroup(MaterialType materialType)
{
    drawableList[0]->setMaterialType(materialType);

    for(unsigned int i = 1; i < drawableList.size(); i++)
    {
        drawableList[i]->setMaterialType(materialType);
    }

    groupMaterialType = materialType;
}

void ObjectGroup::clearGroup()
{
    objectList.clear();
    drawableList.clear();
    colliderList.clear();
    pointList.clear();

    addObject(new Wall(), true, false);
}
