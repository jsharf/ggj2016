#ifndef _DRAW_GL_DRAWDEVICE_HPP
#define _DRAW_GL_DRAWDEVICE_HPP

#include "framebuffer.hpp"
#include "texture.hpp"
#include "mesh.hpp"
#include "program.hpp"
#include "geom/mat.hpp"

#include <GL/glew.h>
#include <GL/gl.h>

namespace GL {

class DrawDevice {
    Framebuffer *mainBuffer;
    Texture *colorTexture;
    Texture *normalTexture;
    Texture *depthTexture;

    Program *simpleProgram;
    Program *meshProgram;

    Mesh *quad;
    Mesh *cube;
    int w, h;

    static DrawDevice *instance;

    void bindStandardAttributes(Program *program);

    public:
    static DrawDevice *getInstance();
    DrawDevice(int w, int h);
    void clear();
    void clearFramebuffer();
    void runMeshProgram(Mesh *m, Texture *t, const Mat4 &mv);
    void runSimpleProgram(Mesh *m, Texture *t, const Mat4 &mv);
    void test();
};

}

#endif
