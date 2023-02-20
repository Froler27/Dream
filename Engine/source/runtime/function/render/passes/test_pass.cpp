#include <glad/glad.h>

#include "runtime/function/render/passes/test_pass.h"

#include "runtime/function/global/global_context.h"
#include "runtime/resource/config_manager/config_manager.h"
#include "runtime/function/time/time_system.h"

#include "runtime/function/render/rhi/rhi.h"
#include "runtime/function/render/rhi/opengl/opengl_rhi.h"
#include "runtime/function/render/rhi/opengl/opengl_util.h"

#include "runtime/core/base/macro.h"

#include <stdexcept>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace Dream
{
    float vertices[] = {
        // positions          // colors           // texture coords
         0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // top right
         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // top left 
    };

    unsigned int indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    GLuint program;
    GLuint vertex_array_object;
    unsigned int VBO, VAO, EBO;
    unsigned int texture1, texture2;
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
        auto shaderFolder = g_runtime_global_context.m_config_manager->getShaderFolder() / "learn_opengl";
        auto vertShaderPath = shaderFolder / "4.1.texture.vert";
        auto fragShaderPath = shaderFolder / "4.1.texture.frag";
        //         auto tcsShaderPath = shaderFolder / "test.tcs";
        //         auto tesShaderPath = shaderFolder / "test.tes";
                //program = OpenglUtil::CreateProgram();
        program = OpenglUtil::CreateProgram(vertShaderPath.generic_string(), fragShaderPath.generic_string());
        //         program = OpenglUtil::CreateProgram(vertShaderPath.generic_string(), fragShaderPath.generic_string(),
        //             tcsShaderPath.generic_string(), tesShaderPath.generic_string());

        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        // position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        // color attribute
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
        // texture coord attribute
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
        glEnableVertexAttribArray(2);

        
        // texture 1
        // ---------
        glGenTextures(1, &texture1);
        glBindTexture(GL_TEXTURE_2D, texture1);
        // set the texture wrapping parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        // set texture filtering parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        // load image, create texture and generate mipmaps
        int width, height, nrChannels;
        stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
        auto textureFolder = g_runtime_global_context.m_config_manager->getAssetFolder() / "textures";
        const auto imagePath = (textureFolder / "wall.jpg").generic_string();
        unsigned char* data = stbi_load(imagePath.c_str(), &width, &height, &nrChannels, 0);
        if (data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else
        {
            LOG_ERROR("Failed to load texture: " + imagePath);
        }
        stbi_image_free(data);

        

        //glCreateVertexArrays(1, &vertex_array_object);
        //glGenVertexArrays(1, &vertex_array_object);

        //glBindVertexArray(vertex_array_object);
        //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
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

        // bind Texture
        glBindTexture(GL_TEXTURE_2D, texture1);

        glUseProgram(program);
        //glDrawArrays(GL_TRIANGLES, 0, 3);// GL_TRIANGLES  GL_POINTS GL_PATCHES
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }
} // namespace Dream
