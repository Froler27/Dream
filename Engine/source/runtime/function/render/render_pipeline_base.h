#pragma once

#include "runtime/function/render/render_pass_base.h"

#include <memory>
#include <vector>

namespace Dream
{
    class RHI;
    class RenderResourceBase;

    struct RenderPipelineInitInfo
    {
        bool                                enable_fxaa {false};
        std::shared_ptr<RenderResourceBase> render_resource;
    };

    class RenderPipelineBase
    {
        friend class RenderSystem;

    public:
        virtual ~RenderPipelineBase() {}

        virtual void initialize(RenderPipelineInitInfo init_info) = 0;

        virtual void preparePassData(std::shared_ptr<RenderResourceBase> render_resource);
        virtual void forwardRender(std::shared_ptr<RHI> rhi, std::shared_ptr<RenderResourceBase> render_resource);
        virtual void deferredRender(std::shared_ptr<RHI> rhi, std::shared_ptr<RenderResourceBase> render_resource);

    protected:
        std::shared_ptr<RHI> m_rhi;
        std::vector<std::shared_ptr<RenderPassBase>> m_passes;

        // std::shared_ptr<RenderPassBase> m_directional_light_pass;
        // std::shared_ptr<RenderPassBase> m_point_light_shadow_pass;
        // std::shared_ptr<RenderPassBase> m_main_camera_pass;
        // std::shared_ptr<RenderPassBase> m_color_grading_pass;
        // std::shared_ptr<RenderPassBase> m_fxaa_pass;
        // std::shared_ptr<RenderPassBase> m_tone_mapping_pass;
        // std::shared_ptr<RenderPassBase> m_ui_pass;
        // std::shared_ptr<RenderPassBase> m_combine_ui_pass;
        // std::shared_ptr<RenderPassBase> m_pick_pass;
        // std::shared_ptr<RenderPassBase> m_particle_pass;

    };
} // namespace Dream
