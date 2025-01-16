#include <memory>

#include "Renderable.h"
#include "RenderStrategy.h"

Renderable::Renderable(std::shared_ptr<RenderStrategy> renderService) : renderService_(renderService) {}
void Renderable::render() const {
    renderService_->render(*this);
}
