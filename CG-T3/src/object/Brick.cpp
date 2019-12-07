#include "object/Brick.h"

Brick::Brick()
{
    Vertex3D *v0 = new Vertex3D(0, -1.0, -1.0, -1.0);
    Vertex3D *v1 = new Vertex3D(1, -1.0, -1.0, 1.0);
    Vertex3D *v2 = new Vertex3D(2, 1.0, -1.0, 1.0);
    Vertex3D *v3 = new Vertex3D(3, 1.0, -1.0, -1.0);

    Vertex3D *v4 = new Vertex3D(4, -1.0, 1.0, -1.0);
    Vertex3D *v5 = new Vertex3D(5, -1.0, 1.0, 1.0);
    Vertex3D *v6 = new Vertex3D(6, 1.0, 1.0, 1.0);
    Vertex3D *v7 = new Vertex3D(7, 1.0, 1.0, -1.0);

    addVertex(v0);
    addVertex(v1);
    addVertex(v2);
    addVertex(v3);
    addVertex(v4);
    addVertex(v5);
    addVertex(v6);
    addVertex(v7);

    Quad* f0 = new Quad(v4, v5, v6, v7);
    f0->setEnableTexture(true);
    f0->addTextureVertex(new Vertex3D(-1, 0.0, 0.0, 0.0));
    f0->addTextureVertex(new Vertex3D(-1, 1.0, 0.0, 0.0));
    f0->addTextureVertex(new Vertex3D(-1, 1.0, 0.0, 1.0));
    f0->addTextureVertex(new Vertex3D(-1, 0.0, 0.0, 1.0));

    Quad* f1 = new Quad(v0, v3, v2, v1);
    f1->setEnableTexture(true);
    f1->addTextureVertex(new Vertex3D(-1, 0.0, 0.0, 0.0));
    f1->addTextureVertex(new Vertex3D(-1, 1.0, 0.0, 0.0));
    f1->addTextureVertex(new Vertex3D(-1, 1.0, 0.0, 1.0));
    f1->addTextureVertex(new Vertex3D(-1, 0.0, 0.0, 1.0));

    Quad* f2 = new Quad(v0, v1, v5, v4);
    f2->setEnableTexture(true);
    f2->addTextureVertex(new Vertex3D(-1, 0.0, 0.0, 0.0));
    f2->addTextureVertex(new Vertex3D(-1, 1.0, 0.0, 0.0));
    f2->addTextureVertex(new Vertex3D(-1, 1.0, 0.0, 1.0));
    f2->addTextureVertex(new Vertex3D(-1, 0.0, 0.0, 1.0));

    Quad* f3 = new Quad(v2, v3, v7, v6);
    f3->setEnableTexture(true);
    f3->addTextureVertex(new Vertex3D(-1, 0.0, 0.0, 0.0));
    f3->addTextureVertex(new Vertex3D(-1, 1.0, 0.0, 0.0));
    f3->addTextureVertex(new Vertex3D(-1, 1.0, 0.0, 1.0));
    f3->addTextureVertex(new Vertex3D(-1, 0.0, 0.0, 1.0));

    Quad* f4 = new Quad(v0, v4, v7, v3);
    f4->setEnableTexture(true);
    f4->addTextureVertex(new Vertex3D(-1, 0.0, 0.0, 0.0));
    f4->addTextureVertex(new Vertex3D(-1, 1.0, 0.0, 0.0));
    f4->addTextureVertex(new Vertex3D(-1, 1.0, 0.0, 1.0));
    f4->addTextureVertex(new Vertex3D(-1, 0.0, 0.0, 1.0));

    Quad* f5 = new Quad(v2, v6, v5, v1);
    f5->setEnableTexture(true);
    f5->addTextureVertex(new Vertex3D(-1, 0.0, 0.0, 0.0));
    f5->addTextureVertex(new Vertex3D(-1, 1.0, 0.0, 0.0));
    f5->addTextureVertex(new Vertex3D(-1, 1.0, 0.0, 1.0));
    f5->addTextureVertex(new Vertex3D(-1, 0.0, 0.0, 1.0));

    addFace(f0);
    addFace(f1);
    addFace(f2);
    addFace(f3);
    addFace(f4);
    addFace(f5);
}

Brick::Brick(Vertex3D *v0, Vertex3D *v1, Vertex3D *v2, Vertex3D *v3, Vertex3D *v4, Vertex3D *v5, Vertex3D *v6 , Vertex3D *v7)
{
    addVertex(v0);
    addVertex(v1);
    addVertex(v2);
    addVertex(v3);
    addVertex(v4);
    addVertex(v5);
    addVertex(v6);
    addVertex(v7);

    Quad* f0 = new Quad(v0, v2, v3, v1);
    f0->setEnableTexture(true);
    f0->addTextureVertex(new Vertex3D(-1, 0.0, 0.0, 0.0));
    f0->addTextureVertex(new Vertex3D(-1, 1.0, 0.0, 0.0));
    f0->addTextureVertex(new Vertex3D(-1, 1.0, 0.0, 1.0));
    f0->addTextureVertex(new Vertex3D(-1, 0.0, 0.0, 1.0));

    Quad* f1 = new Quad(v5, v7, v6, v4);
    f1->setEnableTexture(true);
    f1->addTextureVertex(new Vertex3D(-1, 0.0, 0.0, 0.0));
    f1->addTextureVertex(new Vertex3D(-1, 1.0, 0.0, 0.0));
    f1->addTextureVertex(new Vertex3D(-1, 1.0, 0.0, 1.0));
    f1->addTextureVertex(new Vertex3D(-1, 0.0, 0.0, 1.0));

    Quad* f2 = new Quad(v0, v4, v6, v2);
    f2->setEnableTexture(true);
    f2->addTextureVertex(new Vertex3D(-1, 0.0, 0.0, 0.0));
    f2->addTextureVertex(new Vertex3D(-1, 1.0, 0.0, 0.0));
    f2->addTextureVertex(new Vertex3D(-1, 1.0, 0.0, 1.0));
    f2->addTextureVertex(new Vertex3D(-1, 0.0, 0.0, 1.0));

    Quad* f3 = new Quad(v1, v3, v7, v5);
    f3->setEnableTexture(true);
    f3->addTextureVertex(new Vertex3D(-1, 0.0, 0.0, 0.0));
    f3->addTextureVertex(new Vertex3D(-1, 1.0, 0.0, 0.0));
    f3->addTextureVertex(new Vertex3D(-1, 1.0, 0.0, 1.0));
    f3->addTextureVertex(new Vertex3D(-1, 0.0, 0.0, 1.0));

    Quad* f4 = new Quad(v2, v6, v7, v3);
    f4->setEnableTexture(true);
    f4->addTextureVertex(new Vertex3D(-1, 0.0, 0.0, 0.0));
    f4->addTextureVertex(new Vertex3D(-1, 1.0, 0.0, 0.0));
    f4->addTextureVertex(new Vertex3D(-1, 1.0, 0.0, 1.0));
    f4->addTextureVertex(new Vertex3D(-1, 0.0, 0.0, 1.0));

    Quad* f5 = new Quad(v0, v1, v5, v4);
    f5->setEnableTexture(true);
    f5->addTextureVertex(new Vertex3D(-1, 0.0, 0.0, 0.0));
    f5->addTextureVertex(new Vertex3D(-1, 1.0, 0.0, 0.0));
    f5->addTextureVertex(new Vertex3D(-1, 1.0, 0.0, 1.0));
    f5->addTextureVertex(new Vertex3D(-1, 0.0, 0.0, 1.0));

    addFace(f0);
    addFace(f1);
    addFace(f2);
    addFace(f3);
    addFace(f4);
    addFace(f5);
}
