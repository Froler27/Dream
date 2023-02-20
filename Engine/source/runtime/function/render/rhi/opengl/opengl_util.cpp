#include "runtime/function/render/rhi/opengl/opengl_util.h"

#include <fstream>
#include <vector>
#include <iostream>

#include "runtime/core/base/macro.h"


namespace Dream
{

    GLuint OpenglUtil::CreateProgram(const std::string& vertPath, const std::string& fragPath)
    {
        GLuint vertShader = CreateShader(vertPath, GL_VERTEX_SHADER);
        GLuint fragShader = CreateShader(fragPath, GL_FRAGMENT_SHADER);
        
        GLuint program = glCreateProgram();
        glAttachShader(program, vertShader);
        glAttachShader(program, fragShader);
        glLinkProgram(program);

        // check for linking errors
        int success;
        std::string infoLog(512, '\0');
        glGetProgramiv(program, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(program, 512, NULL, infoLog.data());
            LOG_ERROR("ERROR::SHADER::PROGRAM::LINKING_FAILED\n" + infoLog);
        }

        glDeleteShader(vertShader);
        glDeleteShader(fragShader);
        return program;
    }

    GLuint OpenglUtil::CreateProgram(const std::string& vertPath, const std::string& fragPath,
        const std::string& tcsPath, const std::string& tesPath)
    {
        auto vertShader = CreateShader(vertPath, GL_VERTEX_SHADER);
        auto fragShader = CreateShader(fragPath, GL_FRAGMENT_SHADER);
        auto tcsShader = CreateShader(tcsPath, GL_TESS_CONTROL_SHADER);
        auto tesShader = CreateShader(tesPath, GL_TESS_EVALUATION_SHADER);

        auto program = glCreateProgram();
        glAttachShader(program, vertShader);
        glAttachShader(program, tcsShader);
        glAttachShader(program, tesShader);
        glAttachShader(program, fragShader);
        glLinkProgram(program);

        // check for linking errors
        int success;
        std::string infoLog(512, '\0');
        glGetProgramiv(program, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(program, 512, NULL, infoLog.data());
            LOG_ERROR("ERROR::SHADER::PROGRAM::LINKING_FAILED\n" + infoLog);
        }

        glDeleteShader(vertShader);
        glDeleteShader(fragShader);
        glDeleteShader(tcsShader);
        glDeleteShader(tesShader);
        return program;
    }

    GLuint OpenglUtil::CreateProgram()
    {
        const char* vertexShaderSource = "#version 330 core\n"
            "layout (location = 0) in vec3 aPos;\n"
            "void main()\n"
            "{\n"
            "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
            "}\0";
        const char* fragmentShaderSource = "#version 330 core\n"
            "out vec4 FragColor;\n"
            "void main()\n"
            "{\n"
            "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
            "}\n\0";

        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        glCompileShader(vertexShader);
        // check for shader compile errors
        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        }
        // fragment shader
        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);
        // check for shader compile errors
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
        }
        // link shaders
        unsigned int shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);
        // check for linking errors
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        }
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        return shaderProgram;
    }

    GLuint OpenglUtil::CreateShader(const std::string& path, uint32_t shaderType)
    {
        std::ifstream ifs(path, std::ios_base::ate | std::ios_base::in);
        if (!ifs.is_open()) {
            LOG_ERROR(__FUNCTION__, "fail to open file ");
            return 0;
        }
        uint64_t fileSize = ifs.tellg();
        ifs.seekg(0, std::ios::beg);

        std::vector<GLchar> buffer(fileSize + 1);
        buffer[fileSize] = '/0';
        char* bufferPtr = buffer.data();
        ifs.read(bufferPtr, fileSize);
        ifs.close();

        GLuint shader = glCreateShader(shaderType);
        glShaderSource(shader, 1, &bufferPtr, nullptr);
        glCompileShader(shader);

        int success;
        std::string infoLog(512, '\0');
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 512, NULL, infoLog.data());
            LOG_ERROR("ERROR::SHADER::COMPILATION_FAILED\npath: " + path + "\n" + infoLog);
        }

        return shader;
    }
} // namespace Dream

