#ifndef RENDERSTRATEGY_H
#define RENDERSTRATEGY_H

class Renderable;

class RenderStrategy {
    public:
    virtual void render(const Renderable& object) const = 0;
    virtual ~RenderStrategy() = default;
};

#endif // RENDERSTRATEGY_H