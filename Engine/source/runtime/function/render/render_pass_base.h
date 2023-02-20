#pragma once

#include "runtime/function/render/rhi/rhi.h"

namespace Dream
{
    class RHI;
    class RenderResourceBase;
    class WindowUI;

    struct RenderPassInitInfo
    {};

    struct RenderPassCommonInfo
    {
        std::shared_ptr<RHI>                rhi;
        std::shared_ptr<RenderResourceBase> render_resource;
    };

    class RenderPassBase
    {
    public:
        virtual void initialize(const RenderPassInitInfo* init_info) = 0;
        virtual void postInitialize();
        virtual void setCommonInfo(RenderPassCommonInfo common_info);
        virtual void preparePassData(std::shared_ptr<RenderResourceBase> render_resource);

        virtual void draw() = 0;

    protected:
        std::shared_ptr<RHI>                m_rhi;
        std::shared_ptr<RenderResourceBase> m_render_resource;
    };
} // namespace Dream
