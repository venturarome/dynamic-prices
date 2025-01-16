#include <memory>
#include <vector>

#include "Renderer.h"

void Renderer::render(const std::vector<std::shared_ptr<const Renderable>>& objects) {
    for (const auto& obj : objects) {
        obj->render();
    }
}

void Renderer::render(const std::shared_ptr<const Renderable>& object) {
    object->render();
}