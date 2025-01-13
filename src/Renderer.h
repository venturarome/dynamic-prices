#ifndef RENDERER_H
#define RENDERER_H

#include <memory>

class Menu;

class Renderer {
    virtual void render(const std::unique_ptr<Menu>& menu) = 0;
};

#endif // RENDERER_H