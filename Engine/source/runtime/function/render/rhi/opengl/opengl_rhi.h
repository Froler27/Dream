#pragma once

#include "runtime/function/render/rhi/rhi.h"

#include <functional>
#include <optional>
#include <vector>

namespace Dream
{
    class OpenglRHI final : public RHI
    {
    public:
        // override functions
        virtual ~OpenglRHI() override final;
        virtual void initialize(RHIInitInfo init_info) override final;
        virtual void prepareContext() override final;

    public:
        GLFWwindow* m_window{ nullptr };
    };
} // namespace Dream
