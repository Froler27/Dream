#include <glad/glad.h>

#include "runtime/function/render/passes/test_pass.h"

#include "runtime/function/global/global_context.h"
#include "runtime/resource/config_manager/config_manager.h"
#include "runtime/function/time/time_system.h"

#include "runtime/function/render/rhi/rhi.h"
#include "runtime/function/render/rhi/opengl/opengl_rhi.h"
#include "runtime/function/render/rhi/opengl/opengl_util.h"

#include <stdexcept>

namespace Dream
{
    GLuint program;
    GLuint vertex_array_object;
    unsigned int VBO, VAO;
    void TestPass::initialize(const RenderPassInitInfo* init_info)
    {
        RenderPass::initialize(nullptr);

        setupDescriptorSetLayout();
        setupPipelines();
        setupDescriptorSet();
    }

    void TestPass::setupDescriptorSetLayout()
    {
        
    }

    void TestPass::setupPipelines()
    {
        auto shaderFolder = g_runtime_global_context.m_config_manager->getShaderFolder() / "glsl";
        auto vertShaderPath = shaderFolder / "test.vert";
        auto fragShaderPath = shaderFolder / "test.frag";
        auto tcsShaderPath = shaderFolder / "test.tcs";
        auto tesShaderPath = shaderFolder / "test.tes";
        //program = OpenglUtil::CreateProgram();
        //program = OpenglUtil::CreateProgram(vertShaderPath.generic_string(), fragShaderPath.generic_string());
        program = OpenglUtil::CreateProgram(vertShaderPath.generic_string(), fragShaderPath.generic_string(),
            tcsShaderPath.generic_string(), tesShaderPath.generic_string());

        glCreateVertexArrays(1, &vertex_array_object);
        //glGenVertexArrays(1, &vertex_array_object);

        glBindVertexArray(vertex_array_object);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }

    void TestPass::setupDescriptorSet()
    {
    }


    void TestPass::draw()
    {
        float currentTime = g_runtime_global_context.m_time_system->getRunningTime();
        float r = std::sin(currentTime) * 0.5f + 0.5f;
        float g = std::cos(currentTime) * 0.5f + 0.5f;
        glClearColor(r, g, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glPointSize(20);
        glUseProgram(program);
        glDrawArrays(GL_PATCHES, 0, 3);// GL_TRIANGLES  GL_POINTS GL_PATCHES
    }
} // namespace Dream
