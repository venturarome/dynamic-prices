#ifndef RENDERABLE_H
#define RENDERABLE_H

#include <memory>

#include "RenderStrategy.h"

class Renderable {
    public:
    Renderable(std::shared_ptr<RenderStrategy> renderService);
    virtual ~Renderable() = default;
    void render() const;

    protected:
    std::shared_ptr<RenderStrategy> renderService_;
};

#endif // RENDERABLE_H