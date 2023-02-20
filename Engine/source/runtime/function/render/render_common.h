#pragma once

#include "runtime/core/math/matrix4.h"
#include "runtime/core/math/vector3.h"
#include "runtime/core/math/vector4.h"

#include "runtime/function/render/render_type.h"
#include "rhi/rhi.h"

namespace Dream
{
    static const uint32_t s_point_light_shadow_map_dimension       = 2048;
    static const uint32_t s_directional_light_shadow_map_dimension = 4096;

    // TODO: 64 may not be the best
    static uint32_t const s_mesh_per_drawcall_max_instance_count = 64;
    static uint32_t const s_mesh_vertex_blending_max_joint_count = 1024;
    static uint32_t const s_max_point_light_count                = 15;
    // should sync the macros in "shader_include/constants.h"

    // nodes
    struct RenderMeshNode
    {
        const Matrix4x4* model_matrix{ nullptr };
        const Matrix4x4* joint_matrices{ nullptr };
        uint32_t           joint_count{ 0 };
//         VulkanMesh* ref_mesh{ nullptr };
//         VulkanPBRMaterial* ref_material{ nullptr };
        uint32_t           node_id;
        bool               enable_vertex_blending{ false };
    };
} // namespace Dream
