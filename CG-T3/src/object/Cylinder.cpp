#include "object/Cylinder.h"

using namespace std;

Cylinder::Cylinder(double radius)
{
    double degreeIncrement = (360.0 / CIRCLE_VERTEX_COUNT);
    double degree = 0.0;
    double x, y, z;

    for(int i = 0; i < CIRCLE_VERTEX_COUNT; i++)
    {
        x = radius * cos((degree * M_PI) / 180.0);
        y = 0.0;
        z = radius * sin((degree * M_PI) / 180.0);

        addVertex(new Vertex3D(i, x, y, z));

        degree += degreeIncrement;
    }

    for(int i = 0; i < CIRCLE_VERTEX_COUNT; i++)
    {
        x = radius * cos((degree * M_PI) / 180.0);
        y = 1.2;
        z = radius * sin((degree * M_PI) / 180.0);

        addVertex(new Vertex3D(i, x, y, z));

        degree += degreeIncrement;
    }

    vector<Vertex3D*>* vertexList = getVertexList();
    Vertex3D *tmpV0, *tmpV1, *tmpV2;

    for(int i = 0; i < CIRCLE_VERTEX_COUNT - 1; i++)
    {
        tmpV0 = vertexList->at(i);
        tmpV1 = vertexList->at(i + 1);
        tmpV2 = vertexList->at((i + 1) + CIRCLE_VERTEX_COUNT);

        Triangle *t0 = new Triangle(tmpV0, tmpV1, tmpV2);

        t0->setEnableTexture(true);
        t0->addTextureVertex(new Vertex3D(-1, 0.0, 0.0, 0.0));
        t0->addTextureVertex(new Vertex3D(-1, 1.0, 0.0, 0.0));
        t0->addTextureVertex(new Vertex3D(-1, 1.0, 0.0, 1.0));

        addFace(t0);

        tmpV0 = vertexList->at((i + 1) + CIRCLE_VERTEX_COUNT);
        tmpV1 = vertexList->at(i + CIRCLE_VERTEX_COUNT);
        tmpV2 = vertexList->at(i);

        Triangle *t1 = new Triangle(tmpV0, tmpV1, tmpV2);

        t1->setEnableTexture(true);
        t1->addTextureVertex(new Vertex3D(-1, 1.0, 0.0, 1.0));
        t1->addTextureVertex(new Vertex3D(-1, 0.0, 0.0, 1.0));
        t1->addTextureVertex(new Vertex3D(-1, 0, 0.0, 0.0));

        addFace(t1);
    }

    tmpV0 = vertexList->at(CIRCLE_VERTEX_COUNT - 1);
    tmpV1 = vertexList->at(0);
    tmpV2 = vertexList->at(CIRCLE_VERTEX_COUNT);

    addFace(new Triangle(tmpV0, tmpV1, tmpV2));

    tmpV0 = vertexList->at(CIRCLE_VERTEX_COUNT);
    tmpV1 = vertexList->at((2 * CIRCLE_VERTEX_COUNT) - 1);
    tmpV2 = vertexList->at(CIRCLE_VERTEX_COUNT - 1);

    addFace(new Triangle(tmpV0, tmpV1, tmpV2));
}
