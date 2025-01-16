#ifndef RENDERER_H
#define RENDERER_H

#include <memory>

#include "Renderable.h"

class Renderer {
public:
    void render(const std::vector<std::shared_ptr<const Renderable>>& objects);
    void render(const std::shared_ptr<const Renderable>& object);
};

#endif // RENDERER_H