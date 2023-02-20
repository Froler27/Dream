#pragma once

#include <glad/glad.h>

#include "runtime/function/render/rhi/rhi.h"

#include <string>

namespace Dream
{
    class OpenglUtil
    {
    public:
        //static GLuint createShaderModule(VkDevice device, const std::vector<unsigned char>& shader_code);
        static GLuint CreateProgram();
        static GLuint CreateProgram(const std::string& vertPath, const std::string& fragPath);
        static GLuint CreateProgram(const std::string& vertPath, const std::string& fragPath,
            const std::string& tcsPath, const std::string& tesPath);
        static GLuint CreateShader(const std::string& path, uint32_t shaderType);
    };
} // namespace Dream
