#include <glad/glad.h>

#include "runtime/function/global/global_context.h"
#include "runtime/function/time/time_system.h"

#include "runtime/function/render/render_pipeline.h"
#include "runtime/function/render/rhi/opengl/opengl_rhi.h"
#include "runtime/function/render/rhi/opengl/opengl_util.h"

#include "runtime/resource/config_manager/config_manager.h"

#include "runtime/function/render/passes/test_pass.h"
// #include "runtime/function/render/passes/color_grading_pass.h"
// #include "runtime/function/render/passes/combine_ui_pass.h"
// #include "runtime/function/render/passes/directional_light_pass.h"
// #include "runtime/function/render/passes/main_camera_pass.h"
// #include "runtime/function/render/passes/pick_pass.h"
// #include "runtime/function/render/passes/point_light_pass.h"
// #include "runtime/function/render/passes/tone_mapping_pass.h"
// #include "runtime/function/render/passes/ui_pass.h"
// #include "runtime/function/render/passes/particle_pass.h"

#include "runtime/core/base/macro.h"

#include <cmath>
#include <chrono>

namespace Dream
{
    void RenderPipeline::initialize(RenderPipelineInitInfo init_info)
    {
        auto test_pass = std::make_shared<TestPass>();
        test_pass->initialize(nullptr);
        m_passes.push_back(test_pass);
    }

    void RenderPipeline::forwardRender(std::shared_ptr<RHI> rhi, std::shared_ptr<RenderResourceBase> render_resource)
    {
        for (auto pass : m_passes) {
            pass->draw();
        }
    }

    void RenderPipeline::deferredRender(std::shared_ptr<RHI> rhi, std::shared_ptr<RenderResourceBase> render_resource)
    {
    }
} // namespace Dream
