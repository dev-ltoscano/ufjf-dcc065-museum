#include "object/Ground.h"

Ground::Ground()
{
    Vertex3D *v0 = new Vertex3D(0, -1.0, 0.0, -1.0);
    Vertex3D *v1 = new Vertex3D(1, -1.0, 0.0, 1.0);
    Vertex3D *v2 = new Vertex3D(2, 1.0, 0.0, 1.0);
    Vertex3D *v3 = new Vertex3D(3, 1.0, 0.0, -1.0);

    addVertex(v0);
    addVertex(v1);
    addVertex(v2);
    addVertex(v3);

    Quad *q0 = new Quad(v0, v1, v2, v3);

    q0->setEnableTexture(true);
    q0->addTextureVertex(new Vertex3D(-1, 0.0, 0.0, 0.0));
    q0->addTextureVertex(new Vertex3D(-1, 10.0, 0.0, 0.0));
    q0->addTextureVertex(new Vertex3D(-1, 10.0, 0.0, 10.0));
    q0->addTextureVertex(new Vertex3D(-1, 0.0, 0.0, 10.0));

    addFace(q0);
}
