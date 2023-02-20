#include "runtime/function/render/render_system.h"

#include "runtime/core/base/macro.h"

// #include "runtime/resource/asset_manager/asset_manager.h"
// #include "runtime/resource/config_manager/config_manager.h"
// 
// #include "runtime/function/render/render_camera.h"
// #include "runtime/function/render/render_pass.h"
#include "runtime/function/render/render_pipeline.h"
// #include "runtime/function/render/render_resource.h"
// #include "runtime/function/render/render_resource_base.h"
// #include "runtime/function/render/render_scene.h"
// #include "runtime/function/render/window_system.h"
// 
// #include "runtime/function/render/passes/main_camera_pass.h"
// #include "runtime/function/render/passes/particle_pass.h"

#include "runtime/function/render/rhi/opengl/opengl_rhi.h"

namespace Dream
{
    RenderSystem::~RenderSystem() {}

    void RenderSystem::initialize(RenderSystemInitInfo init_info)
    {
//         std::shared_ptr<ConfigManager> config_manager = g_runtime_global_context.m_config_manager;
//         ASSERT(config_manager);
//         std::shared_ptr<AssetManager> asset_manager = g_runtime_global_context.m_asset_manager;
//         ASSERT(asset_manager);

        // render context initialize
        RHIInitInfo rhi_init_info;
        rhi_init_info.window_system = init_info.window_system;

        m_rhi = std::make_shared<OpenglRHI>();
        m_rhi->initialize(rhi_init_info);

        // initialize render pipeline
        RenderPipelineInitInfo pipeline_init_info;
        //pipeline_init_info.enable_fxaa = global_rendering_res.m_enable_fxaa;
        pipeline_init_info.render_resource = m_render_resource;

        m_render_pipeline = std::make_shared<RenderPipeline>();
        m_render_pipeline->m_rhi = m_rhi;
        m_render_pipeline->initialize(pipeline_init_info);
    }

    void RenderSystem::tick()
    {
        // process swap data between logic and render contexts
        processSwapData();

        // prepare render command context
        m_rhi->prepareContext();

        // prepare pipeline's render passes data
        m_render_pipeline->preparePassData(m_render_resource);

        // render one frame
        if (m_render_pipeline_type == RENDER_PIPELINE_TYPE::FORWARD_PIPELINE)
        {
            m_render_pipeline->forwardRender(m_rhi, m_render_resource);
        }
        else if (m_render_pipeline_type == RENDER_PIPELINE_TYPE::DEFERRED_PIPELINE)
        {
            m_render_pipeline->deferredRender(m_rhi, m_render_resource);
        }
        else
        {
            LOG_ERROR(__FUNCTION__, "unsupported render pipeline type");
        }

    }

    void RenderSystem::updateEngineContentViewport(float offset_x, float offset_y, float width, float height)
    {
//         std::static_pointer_cast<OpenglRHI>(m_rhi)->m_viewport.x        = offset_x;
//         std::static_pointer_cast<OpenglRHI>(m_rhi)->m_viewport.y        = offset_y;
//         std::static_pointer_cast<OpenglRHI>(m_rhi)->m_viewport.width    = width;
//         std::static_pointer_cast<OpenglRHI>(m_rhi)->m_viewport.height   = height;
//         std::static_pointer_cast<OpenglRHI>(m_rhi)->m_viewport.minDepth = 0.0f;
//         std::static_pointer_cast<OpenglRHI>(m_rhi)->m_viewport.maxDepth = 1.0f;

        //m_render_camera->setAspect(width / height);
    }

    EngineContentViewport RenderSystem::getEngineContentViewport() const
    {
//         float x      = std::static_pointer_cast<OpenglRHI>(m_rhi)->m_viewport.x;
//         float y      = std::static_pointer_cast<OpenglRHI>(m_rhi)->m_viewport.y;
//         float width  = std::static_pointer_cast<OpenglRHI>(m_rhi)->m_viewport.width;
//         float height = std::static_pointer_cast<OpenglRHI>(m_rhi)->m_viewport.height;
/*        return {x, y, width, height};*/
        return {};
    }


    void RenderSystem::processSwapData()
    {

    }

} // namespace Dream
