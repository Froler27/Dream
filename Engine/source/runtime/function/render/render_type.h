#pragma once

//#include "runtime/core/base/hash.h"

#include <cstdint>
#include <memory>
#include <string>

namespace Dream
{
    enum RHIFormat : int
    {
        RHI_FORMAT_UNDEFINED = 0,
        RHI_FORMAT_R4G4_UNORM_PACK8 = 1,
        RHI_FORMAT_R4G4B4A4_UNORM_PACK16 = 2,
        RHI_FORMAT_B4G4R4A4_UNORM_PACK16 = 3,
        RHI_FORMAT_R5G6B5_UNORM_PACK16 = 4,
        RHI_FORMAT_B5G6R5_UNORM_PACK16 = 5,
        RHI_FORMAT_R5G5B5A1_UNORM_PACK16 = 6,
        RHI_FORMAT_B5G5R5A1_UNORM_PACK16 = 7,
        RHI_FORMAT_A1R5G5B5_UNORM_PACK16 = 8,
        RHI_FORMAT_R8_UNORM = 9,
        RHI_FORMAT_R8_SNORM = 10,
        RHI_FORMAT_R8_USCALED = 11,
        RHI_FORMAT_R8_SSCALED = 12,
        RHI_FORMAT_R8_UINT = 13,
        RHI_FORMAT_R8_SINT = 14,
        RHI_FORMAT_R8_SRGB = 15,
        RHI_FORMAT_R8G8_UNORM = 16,
        RHI_FORMAT_R8G8_SNORM = 17,
        RHI_FORMAT_R8G8_USCALED = 18,
        RHI_FORMAT_R8G8_SSCALED = 19,
        RHI_FORMAT_R8G8_UINT = 20,
        RHI_FORMAT_R8G8_SINT = 21,
        RHI_FORMAT_R8G8_SRGB = 22,
        RHI_FORMAT_R8G8B8_UNORM = 23,
        RHI_FORMAT_R8G8B8_SNORM = 24,
        RHI_FORMAT_R8G8B8_USCALED = 25,
        RHI_FORMAT_R8G8B8_SSCALED = 26,
        RHI_FORMAT_R8G8B8_UINT = 27,
        RHI_FORMAT_R8G8B8_SINT = 28,
        RHI_FORMAT_R8G8B8_SRGB = 29,
        RHI_FORMAT_B8G8R8_UNORM = 30,
        RHI_FORMAT_B8G8R8_SNORM = 31,
        RHI_FORMAT_B8G8R8_USCALED = 32,
        RHI_FORMAT_B8G8R8_SSCALED = 33,
        RHI_FORMAT_B8G8R8_UINT = 34,
        RHI_FORMAT_B8G8R8_SINT = 35,
        RHI_FORMAT_B8G8R8_SRGB = 36,
        RHI_FORMAT_R8G8B8A8_UNORM = 37,
        RHI_FORMAT_R8G8B8A8_SNORM = 38,
        RHI_FORMAT_R8G8B8A8_USCALED = 39,
        RHI_FORMAT_R8G8B8A8_SSCALED = 40,
        RHI_FORMAT_R8G8B8A8_UINT = 41,
        RHI_FORMAT_R8G8B8A8_SINT = 42,
        RHI_FORMAT_R8G8B8A8_SRGB = 43,
        RHI_FORMAT_B8G8R8A8_UNORM = 44,
        RHI_FORMAT_B8G8R8A8_SNORM = 45,
        RHI_FORMAT_B8G8R8A8_USCALED = 46,
        RHI_FORMAT_B8G8R8A8_SSCALED = 47,
        RHI_FORMAT_B8G8R8A8_UINT = 48,
        RHI_FORMAT_B8G8R8A8_SINT = 49,
        RHI_FORMAT_B8G8R8A8_SRGB = 50,
        RHI_FORMAT_A8B8G8R8_UNORM_PACK32 = 51,
        RHI_FORMAT_A8B8G8R8_SNORM_PACK32 = 52,
        RHI_FORMAT_A8B8G8R8_USCALED_PACK32 = 53,
        RHI_FORMAT_A8B8G8R8_SSCALED_PACK32 = 54,
        RHI_FORMAT_A8B8G8R8_UINT_PACK32 = 55,
        RHI_FORMAT_A8B8G8R8_SINT_PACK32 = 56,
        RHI_FORMAT_A8B8G8R8_SRGB_PACK32 = 57,
        RHI_FORMAT_A2R10G10B10_UNORM_PACK32 = 58,
        RHI_FORMAT_A2R10G10B10_SNORM_PACK32 = 59,
        RHI_FORMAT_A2R10G10B10_USCALED_PACK32 = 60,
        RHI_FORMAT_A2R10G10B10_SSCALED_PACK32 = 61,
        RHI_FORMAT_A2R10G10B10_UINT_PACK32 = 62,
        RHI_FORMAT_A2R10G10B10_SINT_PACK32 = 63,
        RHI_FORMAT_A2B10G10R10_UNORM_PACK32 = 64,
        RHI_FORMAT_A2B10G10R10_SNORM_PACK32 = 65,
        RHI_FORMAT_A2B10G10R10_USCALED_PACK32 = 66,
        RHI_FORMAT_A2B10G10R10_SSCALED_PACK32 = 67,
        RHI_FORMAT_A2B10G10R10_UINT_PACK32 = 68,
        RHI_FORMAT_A2B10G10R10_SINT_PACK32 = 69,
        RHI_FORMAT_R16_UNORM = 70,
        RHI_FORMAT_R16_SNORM = 71,
        RHI_FORMAT_R16_USCALED = 72,
        RHI_FORMAT_R16_SSCALED = 73,
        RHI_FORMAT_R16_UINT = 74,
        RHI_FORMAT_R16_SINT = 75,
        RHI_FORMAT_R16_SFLOAT = 76,
        RHI_FORMAT_R16G16_UNORM = 77,
        RHI_FORMAT_R16G16_SNORM = 78,
        RHI_FORMAT_R16G16_USCALED = 79,
        RHI_FORMAT_R16G16_SSCALED = 80,
        RHI_FORMAT_R16G16_UINT = 81,
        RHI_FORMAT_R16G16_SINT = 82,
        RHI_FORMAT_R16G16_SFLOAT = 83,
        RHI_FORMAT_R16G16B16_UNORM = 84,
        RHI_FORMAT_R16G16B16_SNORM = 85,
        RHI_FORMAT_R16G16B16_USCALED = 86,
        RHI_FORMAT_R16G16B16_SSCALED = 87,
        RHI_FORMAT_R16G16B16_UINT = 88,
        RHI_FORMAT_R16G16B16_SINT = 89,
        RHI_FORMAT_R16G16B16_SFLOAT = 90,
        RHI_FORMAT_R16G16B16A16_UNORM = 91,
        RHI_FORMAT_R16G16B16A16_SNORM = 92,
        RHI_FORMAT_R16G16B16A16_USCALED = 93,
        RHI_FORMAT_R16G16B16A16_SSCALED = 94,
        RHI_FORMAT_R16G16B16A16_UINT = 95,
        RHI_FORMAT_R16G16B16A16_SINT = 96,
        RHI_FORMAT_R16G16B16A16_SFLOAT = 97,
        RHI_FORMAT_R32_UINT = 98,
        RHI_FORMAT_R32_SINT = 99,
        RHI_FORMAT_R32_SFLOAT = 100,
        RHI_FORMAT_R32G32_UINT = 101,
        RHI_FORMAT_R32G32_SINT = 102,
        RHI_FORMAT_R32G32_SFLOAT = 103,
        RHI_FORMAT_R32G32B32_UINT = 104,
        RHI_FORMAT_R32G32B32_SINT = 105,
        RHI_FORMAT_R32G32B32_SFLOAT = 106,
        RHI_FORMAT_R32G32B32A32_UINT = 107,
        RHI_FORMAT_R32G32B32A32_SINT = 108,
        RHI_FORMAT_R32G32B32A32_SFLOAT = 109,
        RHI_FORMAT_R64_UINT = 110,
        RHI_FORMAT_R64_SINT = 111,
        RHI_FORMAT_R64_SFLOAT = 112,
        RHI_FORMAT_R64G64_UINT = 113,
        RHI_FORMAT_R64G64_SINT = 114,
        RHI_FORMAT_R64G64_SFLOAT = 115,
        RHI_FORMAT_R64G64B64_UINT = 116,
        RHI_FORMAT_R64G64B64_SINT = 117,
        RHI_FORMAT_R64G64B64_SFLOAT = 118,
        RHI_FORMAT_R64G64B64A64_UINT = 119,
        RHI_FORMAT_R64G64B64A64_SINT = 120,
        RHI_FORMAT_R64G64B64A64_SFLOAT = 121,
        RHI_FORMAT_B10G11R11_UFLOAT_PACK32 = 122,
        RHI_FORMAT_E5B9G9R9_UFLOAT_PACK32 = 123,
        RHI_FORMAT_D16_UNORM = 124,
        RHI_FORMAT_X8_D24_UNORM_PACK32 = 125,
        RHI_FORMAT_D32_SFLOAT = 126,
        RHI_FORMAT_S8_UINT = 127,
        RHI_FORMAT_D16_UNORM_S8_UINT = 128,
        RHI_FORMAT_D24_UNORM_S8_UINT = 129,
        RHI_FORMAT_D32_SFLOAT_S8_UINT = 130,
        RHI_FORMAT_BC1_RGB_UNORM_BLOCK = 131,
        RHI_FORMAT_BC1_RGB_SRGB_BLOCK = 132,
        RHI_FORMAT_BC1_RGBA_UNORM_BLOCK = 133,
        RHI_FORMAT_BC1_RGBA_SRGB_BLOCK = 134,
        RHI_FORMAT_BC2_UNORM_BLOCK = 135,
        RHI_FORMAT_BC2_SRGB_BLOCK = 136,
        RHI_FORMAT_BC3_UNORM_BLOCK = 137,
        RHI_FORMAT_BC3_SRGB_BLOCK = 138,
        RHI_FORMAT_BC4_UNORM_BLOCK = 139,
        RHI_FORMAT_BC4_SNORM_BLOCK = 140,
        RHI_FORMAT_BC5_UNORM_BLOCK = 141,
        RHI_FORMAT_BC5_SNORM_BLOCK = 142,
        RHI_FORMAT_BC6H_UFLOAT_BLOCK = 143,
        RHI_FORMAT_BC6H_SFLOAT_BLOCK = 144,
        RHI_FORMAT_BC7_UNORM_BLOCK = 145,
        RHI_FORMAT_BC7_SRGB_BLOCK = 146,
        RHI_FORMAT_ETC2_R8G8B8_UNORM_BLOCK = 147,
        RHI_FORMAT_ETC2_R8G8B8_SRGB_BLOCK = 148,
        RHI_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK = 149,
        RHI_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK = 150,
        RHI_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK = 151,
        RHI_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK = 152,
        RHI_FORMAT_EAC_R11_UNORM_BLOCK = 153,
        RHI_FORMAT_EAC_R11_SNORM_BLOCK = 154,
        RHI_FORMAT_EAC_R11G11_UNORM_BLOCK = 155,
        RHI_FORMAT_EAC_R11G11_SNORM_BLOCK = 156,
        RHI_FORMAT_ASTC_4x4_UNORM_BLOCK = 157,
        RHI_FORMAT_ASTC_4x4_SRGB_BLOCK = 158,
        RHI_FORMAT_ASTC_5x4_UNORM_BLOCK = 159,
        RHI_FORMAT_ASTC_5x4_SRGB_BLOCK = 160,
        RHI_FORMAT_ASTC_5x5_UNORM_BLOCK = 161,
        RHI_FORMAT_ASTC_5x5_SRGB_BLOCK = 162,
        RHI_FORMAT_ASTC_6x5_UNORM_BLOCK = 163,
        RHI_FORMAT_ASTC_6x5_SRGB_BLOCK = 164,
        RHI_FORMAT_ASTC_6x6_UNORM_BLOCK = 165,
        RHI_FORMAT_ASTC_6x6_SRGB_BLOCK = 166,
        RHI_FORMAT_ASTC_8x5_UNORM_BLOCK = 167,
        RHI_FORMAT_ASTC_8x5_SRGB_BLOCK = 168,
        RHI_FORMAT_ASTC_8x6_UNORM_BLOCK = 169,
        RHI_FORMAT_ASTC_8x6_SRGB_BLOCK = 170,
        RHI_FORMAT_ASTC_8x8_UNORM_BLOCK = 171,
        RHI_FORMAT_ASTC_8x8_SRGB_BLOCK = 172,
        RHI_FORMAT_ASTC_10x5_UNORM_BLOCK = 173,
        RHI_FORMAT_ASTC_10x5_SRGB_BLOCK = 174,
        RHI_FORMAT_ASTC_10x6_UNORM_BLOCK = 175,
        RHI_FORMAT_ASTC_10x6_SRGB_BLOCK = 176,
        RHI_FORMAT_ASTC_10x8_UNORM_BLOCK = 177,
        RHI_FORMAT_ASTC_10x8_SRGB_BLOCK = 178,
        RHI_FORMAT_ASTC_10x10_UNORM_BLOCK = 179,
        RHI_FORMAT_ASTC_10x10_SRGB_BLOCK = 180,
        RHI_FORMAT_ASTC_12x10_UNORM_BLOCK = 181,
        RHI_FORMAT_ASTC_12x10_SRGB_BLOCK = 182,
        RHI_FORMAT_ASTC_12x12_UNORM_BLOCK = 183,
        RHI_FORMAT_ASTC_12x12_SRGB_BLOCK = 184,
        RHI_FORMAT_G8B8G8R8_422_UNORM = 1000156000,
        RHI_FORMAT_B8G8R8G8_422_UNORM = 1000156001,
        RHI_FORMAT_G8_B8_R8_3PLANE_420_UNORM = 1000156002,
        RHI_FORMAT_G8_B8R8_2PLANE_420_UNORM = 1000156003,
        RHI_FORMAT_G8_B8_R8_3PLANE_422_UNORM = 1000156004,
        RHI_FORMAT_G8_B8R8_2PLANE_422_UNORM = 1000156005,
        RHI_FORMAT_G8_B8_R8_3PLANE_444_UNORM = 1000156006,
        RHI_FORMAT_R10X6_UNORM_PACK16 = 1000156007,
        RHI_FORMAT_R10X6G10X6_UNORM_2PACK16 = 1000156008,
        RHI_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16 = 1000156009,
        RHI_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16 = 1000156010,
        RHI_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16 = 1000156011,
        RHI_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16 = 1000156012,
        RHI_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16 = 1000156013,
        RHI_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16 = 1000156014,
        RHI_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16 = 1000156015,
        RHI_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16 = 1000156016,
        RHI_FORMAT_R12X4_UNORM_PACK16 = 1000156017,
        RHI_FORMAT_R12X4G12X4_UNORM_2PACK16 = 1000156018,
        RHI_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16 = 1000156019,
        RHI_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16 = 1000156020,
        RHI_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16 = 1000156021,
        RHI_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16 = 1000156022,
        RHI_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16 = 1000156023,
        RHI_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16 = 1000156024,
        RHI_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16 = 1000156025,
        RHI_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16 = 1000156026,
        RHI_FORMAT_G16B16G16R16_422_UNORM = 1000156027,
        RHI_FORMAT_B16G16R16G16_422_UNORM = 1000156028,
        RHI_FORMAT_G16_B16_R16_3PLANE_420_UNORM = 1000156029,
        RHI_FORMAT_G16_B16R16_2PLANE_420_UNORM = 1000156030,
        RHI_FORMAT_G16_B16_R16_3PLANE_422_UNORM = 1000156031,
        RHI_FORMAT_G16_B16R16_2PLANE_422_UNORM = 1000156032,
        RHI_FORMAT_G16_B16_R16_3PLANE_444_UNORM = 1000156033,
        RHI_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG = 1000054000,
        RHI_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG = 1000054001,
        RHI_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG = 1000054002,
        RHI_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG = 1000054003,
        RHI_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG = 1000054004,
        RHI_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG = 1000054005,
        RHI_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG = 1000054006,
        RHI_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG = 1000054007,
        RHI_FORMAT_ASTC_4x4_SFLOAT_BLOCK_EXT = 1000066000,
        RHI_FORMAT_ASTC_5x4_SFLOAT_BLOCK_EXT = 1000066001,
        RHI_FORMAT_ASTC_5x5_SFLOAT_BLOCK_EXT = 1000066002,
        RHI_FORMAT_ASTC_6x5_SFLOAT_BLOCK_EXT = 1000066003,
        RHI_FORMAT_ASTC_6x6_SFLOAT_BLOCK_EXT = 1000066004,
        RHI_FORMAT_ASTC_8x5_SFLOAT_BLOCK_EXT = 1000066005,
        RHI_FORMAT_ASTC_8x6_SFLOAT_BLOCK_EXT = 1000066006,
        RHI_FORMAT_ASTC_8x8_SFLOAT_BLOCK_EXT = 1000066007,
        RHI_FORMAT_ASTC_10x5_SFLOAT_BLOCK_EXT = 1000066008,
        RHI_FORMAT_ASTC_10x6_SFLOAT_BLOCK_EXT = 1000066009,
        RHI_FORMAT_ASTC_10x8_SFLOAT_BLOCK_EXT = 1000066010,
        RHI_FORMAT_ASTC_10x10_SFLOAT_BLOCK_EXT = 1000066011,
        RHI_FORMAT_ASTC_12x10_SFLOAT_BLOCK_EXT = 1000066012,
        RHI_FORMAT_ASTC_12x12_SFLOAT_BLOCK_EXT = 1000066013,
        RHI_FORMAT_G8_B8R8_2PLANE_444_UNORM_EXT = 1000330000,
        RHI_FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16_EXT = 1000330001,
        RHI_FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16_EXT = 1000330002,
        RHI_FORMAT_G16_B16R16_2PLANE_444_UNORM_EXT = 1000330003,
        RHI_FORMAT_A4R4G4B4_UNORM_PACK16_EXT = 1000340000,
        RHI_FORMAT_A4B4G4R4_UNORM_PACK16_EXT = 1000340001,
        RHI_FORMAT_G8B8G8R8_422_UNORM_KHR = RHI_FORMAT_G8B8G8R8_422_UNORM,
        RHI_FORMAT_B8G8R8G8_422_UNORM_KHR = RHI_FORMAT_B8G8R8G8_422_UNORM,
        RHI_FORMAT_G8_B8_R8_3PLANE_420_UNORM_KHR = RHI_FORMAT_G8_B8_R8_3PLANE_420_UNORM,
        RHI_FORMAT_G8_B8R8_2PLANE_420_UNORM_KHR = RHI_FORMAT_G8_B8R8_2PLANE_420_UNORM,
        RHI_FORMAT_G8_B8_R8_3PLANE_422_UNORM_KHR = RHI_FORMAT_G8_B8_R8_3PLANE_422_UNORM,
        RHI_FORMAT_G8_B8R8_2PLANE_422_UNORM_KHR = RHI_FORMAT_G8_B8R8_2PLANE_422_UNORM,
        RHI_FORMAT_G8_B8_R8_3PLANE_444_UNORM_KHR = RHI_FORMAT_G8_B8_R8_3PLANE_444_UNORM,
        RHI_FORMAT_R10X6_UNORM_PACK16_KHR = RHI_FORMAT_R10X6_UNORM_PACK16,
        RHI_FORMAT_R10X6G10X6_UNORM_2PACK16_KHR = RHI_FORMAT_R10X6G10X6_UNORM_2PACK16,
        RHI_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16_KHR = RHI_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16,
        RHI_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16_KHR = RHI_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16,
        RHI_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16_KHR = RHI_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16,
        RHI_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16_KHR = RHI_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16,
        RHI_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16_KHR = RHI_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16,
        RHI_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16_KHR = RHI_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16,
        RHI_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16_KHR = RHI_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16,
        RHI_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16_KHR = RHI_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16,
        RHI_FORMAT_R12X4_UNORM_PACK16_KHR = RHI_FORMAT_R12X4_UNORM_PACK16,
        RHI_FORMAT_R12X4G12X4_UNORM_2PACK16_KHR = RHI_FORMAT_R12X4G12X4_UNORM_2PACK16,
        RHI_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16_KHR = RHI_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16,
        RHI_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16_KHR = RHI_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16,
        RHI_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16_KHR = RHI_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16,
        RHI_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16_KHR = RHI_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16,
        RHI_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16_KHR = RHI_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16,
        RHI_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16_KHR = RHI_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16,
        RHI_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16_KHR = RHI_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16,
        RHI_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16_KHR = RHI_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16,
        RHI_FORMAT_G16B16G16R16_422_UNORM_KHR = RHI_FORMAT_G16B16G16R16_422_UNORM,
        RHI_FORMAT_B16G16R16G16_422_UNORM_KHR = RHI_FORMAT_B16G16R16G16_422_UNORM,
        RHI_FORMAT_G16_B16_R16_3PLANE_420_UNORM_KHR = RHI_FORMAT_G16_B16_R16_3PLANE_420_UNORM,
        RHI_FORMAT_G16_B16R16_2PLANE_420_UNORM_KHR = RHI_FORMAT_G16_B16R16_2PLANE_420_UNORM,
        RHI_FORMAT_G16_B16_R16_3PLANE_422_UNORM_KHR = RHI_FORMAT_G16_B16_R16_3PLANE_422_UNORM,
        RHI_FORMAT_G16_B16R16_2PLANE_422_UNORM_KHR = RHI_FORMAT_G16_B16R16_2PLANE_422_UNORM,
        RHI_FORMAT_G16_B16_R16_3PLANE_444_UNORM_KHR = RHI_FORMAT_G16_B16_R16_3PLANE_444_UNORM,
        RHI_FORMAT_MAX_ENUM = 0x7FFFFFFF
    };

    enum class PICCOLO_PIXEL_FORMAT : uint8_t
    {
        PICCOLO_PIXEL_FORMAT_UNKNOWN = 0,
        PICCOLO_PIXEL_FORMAT_R8G8B8_UNORM,
        PICCOLO_PIXEL_FORMAT_R8G8B8_SRGB,
        PICCOLO_PIXEL_FORMAT_R8G8B8A8_UNORM,
        PICCOLO_PIXEL_FORMAT_R8G8B8A8_SRGB,
        PICCOLO_PIXEL_FORMAT_R32G32_FLOAT,
        PICCOLO_PIXEL_FORMAT_R32G32B32_FLOAT,
        PICCOLO_PIXEL_FORMAT_R32G32B32A32_FLOAT
    };

    enum class PICCOLO_IMAGE_TYPE : uint8_t
    {
        PICCOLO_IMAGE_TYPE_UNKNOWM = 0,
        PICCOLO_IMAGE_TYPE_2D
    };

    enum class RENDER_PIPELINE_TYPE : uint8_t
    {
        FORWARD_PIPELINE = 0,
        DEFERRED_PIPELINE,
        PIPELINE_TYPE_COUNT
    };

    class BufferData
    {
    public:
        size_t m_size {0};
        void*  m_data {nullptr};

        BufferData() = delete;
        BufferData(size_t size)
        {
            m_size = size;
            m_data = malloc(size);
        }
        ~BufferData()
        {
            if (m_data)
            {
                free(m_data);
            }
        }
        bool isValid() const { return m_data != nullptr; }
    };

    class TextureData
    {
    public:
        uint32_t m_width {0};
        uint32_t m_height {0};
        uint32_t m_depth {0};
        uint32_t m_mip_levels {0};
        uint32_t m_array_layers {0};
        void*    m_pixels {nullptr};

        PICCOLO_PIXEL_FORMAT m_format {PICCOLO_PIXEL_FORMAT::PICCOLO_PIXEL_FORMAT_UNKNOWN};
        PICCOLO_IMAGE_TYPE   m_type {PICCOLO_IMAGE_TYPE::PICCOLO_IMAGE_TYPE_UNKNOWM};

        TextureData() = default;
        ~TextureData()
        {
            if (m_pixels)
            {
                free(m_pixels);
            }
        }
        bool isValid() const { return m_pixels != nullptr; }
    };

    struct MeshVertexDataDefinition
    {
        float x, y, z;    // position
        float nx, ny, nz; // normal
        float tx, ty, tz; // tangent
        float u, v;       // UV coordinates
    };

    struct MeshVertexBindingDataDefinition
    {
        int m_index0 {0};
        int m_index1 {0};
        int m_index2 {0};
        int m_index3 {0};

        float m_weight0 {0.f};
        float m_weight1 {0.f};
        float m_weight2 {0.f};
        float m_weight3 {0.f};
    };

    struct MeshSourceDesc
    {
        std::string m_mesh_file;

        bool   operator==(const MeshSourceDesc& rhs) const { return m_mesh_file == rhs.m_mesh_file; }
        size_t getHashValue() const { return std::hash<std::string> {}(m_mesh_file); }
    };

    struct MaterialSourceDesc
    {
        std::string m_base_color_file;
        std::string m_metallic_roughness_file;
        std::string m_normal_file;
        std::string m_occlusion_file;
        std::string m_emissive_file;

        bool operator==(const MaterialSourceDesc& rhs) const
        {
            return m_base_color_file == rhs.m_base_color_file &&
                   m_metallic_roughness_file == rhs.m_metallic_roughness_file &&
                   m_normal_file == rhs.m_normal_file &&
                   m_occlusion_file == rhs.m_occlusion_file &&
                   m_emissive_file == rhs.m_emissive_file;
        }

//         size_t getHashValue() const
//         {
//             size_t hash = 0;
//             hash_combine(hash,
//                          m_base_color_file,
//                          m_metallic_roughness_file,
//                          m_normal_file,
//                          m_occlusion_file,
//                          m_emissive_file);
//             return hash;
//         }
    };

    struct StaticMeshData
    {
        std::shared_ptr<BufferData> m_vertex_buffer;
        std::shared_ptr<BufferData> m_index_buffer;
    };

    struct RenderMeshData
    {
        StaticMeshData              m_static_mesh_data;
        std::shared_ptr<BufferData> m_skeleton_binding_buffer;
    };

    struct RenderMaterialData
    {
        std::shared_ptr<TextureData> m_base_color_texture;
        std::shared_ptr<TextureData> m_metallic_roughness_texture;
        std::shared_ptr<TextureData> m_normal_texture;
        std::shared_ptr<TextureData> m_occlusion_texture;
        std::shared_ptr<TextureData> m_emissive_texture;
    };
} // namespace Dream

template<>
struct std::hash<Dream::MeshSourceDesc>
{
    size_t operator()(const Dream::MeshSourceDesc& rhs) const noexcept { return rhs.getHashValue(); }
};
// template<>
// struct std::hash<Dream::MaterialSourceDesc>
// {
//     size_t operator()(const Dream::MaterialSourceDesc& rhs) const noexcept { return rhs.getHashValue(); }
// };
