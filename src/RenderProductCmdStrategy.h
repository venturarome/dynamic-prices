#ifndef RENDERPRODUCTCMDSTRATEGY_H
#define RENDERPRODUCTCMDSTRATEGY_H

#include <memory>

#include "RenderStrategy.h"

class RenderProductCmdStrategy: public RenderStrategy {
    public:
    void render(const Renderable& object) const override;
};

#endif // RENDERPRODUCTCMDSTRATEGY_H