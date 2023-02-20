#include <glad/glad.h>

#include "runtime/function/render/rhi/opengl/opengl_rhi.h"

#include "runtime/function/render/window_system.h"

#include <algorithm>
#include <cassert>

#include <cstring>
#include <iostream>
#include <set>
#include <stdexcept>
#include <string>

namespace Dream
{
    OpenglRHI::~OpenglRHI()
    {
        // TODO
    }

    void OpenglRHI::initialize(RHIInitInfo init_info)
    {
        // glad: load all OpenGL function pointers
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
        }

        m_window = init_info.window_system->getWindow();

        std::array<int, 2> window_size = init_info.window_system->getWindowSize();

//         m_viewport = { 0.0f, 0.0f, (float)window_size[0], (float)window_size[1], 0.0f, 1.0f };
//         m_scissor = { {0, 0}, {(uint32_t)window_size[0], (uint32_t)window_size[1]} };
    }

    void OpenglRHI::prepareContext()
    {

    }

} // namespace Piccolo