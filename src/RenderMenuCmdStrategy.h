#ifndef RENDERMENUCMDSTRATEGY_H
#define RENDERMENUCMDSTRATEGY_H

#include <memory>

#include "RenderStrategy.h"

class RenderMenuCmdStrategy: public RenderStrategy {
    public:
    void render(const Renderable& object) const override;
};

#endif // RENDERMENUCMDSTRATEGY_H