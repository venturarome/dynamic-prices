#ifndef CMDRENDERER_H
#define CMDRENDERER_H

#include <memory>

#include "Menu.h"

class CmdRenderer: public Renderer {
    public:
    void render(const std::unique_ptr<Menu>& menu) override;
};

#endif // CMDRENDERER_H