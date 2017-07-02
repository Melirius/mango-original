/*
    MANGO Multimedia Development Platform
    Copyright (C) 2012-2017 Twilight Finland 3D Oy Ltd. All rights reserved.
*/
#pragma once

#include "simd.hpp"

namespace mango {
namespace simd {

    // ------------------------------------------------------------------
    // gather
    // ------------------------------------------------------------------

#if defined(MANGO_ENABLE_AVX2)

    // 128 bit gather

    static inline float32x4 gather4(const float* address, int32x4 offset)
    {
        return _mm_i32gather_ps(reinterpret_cast<const float*>(address), offset, 4);
    }

    static inline float64x2 gather2(const double* address, int32x4 offset)
    {
        return _mm_i32gather_pd(reinterpret_cast<const double*>(address), offset, 8);
    }

    static inline uint32x4 gather4(const uint32* address, int32x4 offset)
    {
        return _mm_i32gather_epi32(reinterpret_cast<const int*>(address), offset, 4);
    }

    static inline int32x4 gather4(const int32* address, int32x4 offset)
    {
        return _mm_i32gather_epi32(reinterpret_cast<const int*>(address), offset, 4);
    }

    static inline uint64x2 gather2(const uint64* address, int32x4 offset)
    {
        return _mm_i32gather_epi64(reinterpret_cast<const long long*>(address), offset, 8);
    }

    static inline int64x2 gather2(const int64* address, int32x4 offset)
    {
        return _mm_i32gather_epi64(reinterpret_cast<const long long*>(address), offset, 8);
    }

    // 256 bit gather

    static inline float32x8 gather8(const float* address, int32x8 offset)
    {
        return _mm256_i32gather_ps(reinterpret_cast<const float*>(address), offset, 4);
    }

    static inline float64x4 gather4(const double* address, int32x4 offset)
    {
        return _mm256_i32gather_pd(reinterpret_cast<const double*>(address), offset, 8);
    }

    static inline uint32x8 gather8(const uint32* address, int32x8 offset)
    {
        return _mm256_i32gather_epi32(reinterpret_cast<const int*>(address), offset, 4);
    }

    static inline int32x8 gather8(const int32* address, int32x8 offset)
    {
        return _mm256_i32gather_epi32(reinterpret_cast<const int*>(address), offset, 4);
    }

    static inline uint64x4 gather4(const uint64* address, int32x4 offset)
    {
        return _mm256_i32gather_epi64(reinterpret_cast<const long long*>(address), offset, 8);
    }

    static inline int64x4 gather4(const int64* address, int32x4 offset)
    {
        return _mm256_i32gather_epi64(reinterpret_cast<const long long*>(address), offset, 8);
    }

    // 128 bit masked gather

    static inline float32x4 gather4(const float* address, int32x4 offset, float32x4 value, float32x4 mask)
    {
        return _mm_mask_i32gather_ps(value, reinterpret_cast<const float*>(address), offset, mask, 4);
    }

    static inline float64x2 gather2(const double* address, int32x4 offset, float64x2 value, float64x2 mask)
    {
        return _mm_mask_i32gather_pd(value, reinterpret_cast<const double*>(address), offset, mask, 8);
    }

    static inline uint32x4 gather4(const uint32* address, int32x4 offset, uint32x4 value, uint32x4 mask)
    {
        return _mm_mask_i32gather_epi32(value, reinterpret_cast<const int*>(address), offset, mask, 4);
    }

    static inline int32x4 gather4(const int32* address, int32x4 offset, int32x4 value, int32x4 mask)
    {
        return _mm_mask_i32gather_epi32(value, reinterpret_cast<const int*>(address), offset, mask, 4);
    }

    static inline uint64x2 gather2(const uint64* address, int32x4 offset, uint64x2 value, uint64x2 mask)
    {
        return _mm_mask_i32gather_epi64(value, reinterpret_cast<const long long*>(address), offset, mask, 8);
    }

    static inline int64x2 gather2(const int64* address, int32x4 offset, int64x2 value, int64x2 mask)
    {
        return _mm_mask_i32gather_epi64(value, reinterpret_cast<const long long*>(address), offset, mask, 8);
    }

    // 256 bit masked gather

    static inline float32x8 gather8(const float* address, int32x8 offset, float32x8 value, float32x8 mask)
    {
        return _mm256_mask_i32gather_ps(value, reinterpret_cast<const float*>(address), offset, mask, 4);
    }

    static inline float64x4 gather4(const double* address, int32x4 offset, float64x4 value, float64x4 mask)
    {
        return _mm256_mask_i32gather_pd(value, reinterpret_cast<const double*>(address), offset, mask, 8);
    }

    static inline uint32x8 gather8(const uint32* address, int32x8 offset, uint32x8 value, uint32x8 mask)
    {
        return _mm256_mask_i32gather_epi32(value, reinterpret_cast<const int*>(address), offset, mask, 4);
    }

    static inline int32x8 gather8(const int32* address, int32x8 offset, int32x8 value, int32x8 mask)
    {
        return _mm256_mask_i32gather_epi32(value, reinterpret_cast<const int*>(address), offset, mask, 4);
    }

    static inline uint64x4 gather4(const uint64* address, int32x4 offset, uint64x4 value, uint64x4 mask)
    {
        return _mm256_mask_i32gather_epi64(value, reinterpret_cast<const long long*>(address), offset, mask, 8);
    }

    static inline int64x4 gather4(const int64* address, int32x4 offset, int64x4 value, int64x4 mask)
    {
        return _mm256_mask_i32gather_epi64(value, reinterpret_cast<const long long*>(address), offset, mask, 8);
    }

#else

    // 128 bit gather

    static inline float32x4 gather4(const float* address, int32x4 offset)
    {
        auto s0 = address[get_component<0>(offset)];
        auto s1 = address[get_component<1>(offset)];
        auto s2 = address[get_component<2>(offset)];
        auto s3 = address[get_component<3>(offset)];
        return float32x4_set4(s0, s1, s2, s3);
    }

    static inline float64x2 gather2(const double* address, int32x4 offset)
    {
        auto s0 = address[get_component<0>(offset)];
        auto s1 = address[get_component<1>(offset)];
        return float64x2_set2(s0, s1);
    }

    static inline uint32x4 gather4(const uint32* address, int32x4 offset)
    {
        auto s0 = address[get_component<0>(offset)];
        auto s1 = address[get_component<1>(offset)];
        auto s2 = address[get_component<2>(offset)];
        auto s3 = address[get_component<3>(offset)];
        return uint32x4_set4(s0, s1, s2, s3);
    }

    static inline int32x4 gather4(const int32* address, int32x4 offset)
    {
        auto s0 = address[get_component<0>(offset)];
        auto s1 = address[get_component<1>(offset)];
        auto s2 = address[get_component<2>(offset)];
        auto s3 = address[get_component<3>(offset)];
        return int32x4_set4(s0, s1, s2, s3);
    }

    static inline uint64x2 gather2(const uint64* address, int32x4 offset)
    {
        auto s0 = address[get_component<0>(offset)];
        auto s1 = address[get_component<1>(offset)];
        return uint64x2_set2(s0, s1);
    }

    static inline int64x2 gather2(const int64* address, int32x4 offset)
    {
        auto s0 = address[get_component<0>(offset)];
        auto s1 = address[get_component<1>(offset)];
        return int64x2_set2(s0, s1);
    }

    // 256 bit gather

    static inline float32x8 gather8(const float* address, int32x8 offset)
    {
        float32x4 a = gather4(address, get_low(offset));
        float32x4 b = gather4(address, get_high(offset));
        return combine(a, b);
    }

    static inline float64x4 gather4(const double* address, int32x4 offset)
    {
        auto s0 = address[get_component<0>(offset)];
        auto s1 = address[get_component<1>(offset)];
        auto s2 = address[get_component<2>(offset)];
        auto s3 = address[get_component<3>(offset)];
        return float64x4_set4(s0, s1, s2, s3);
    }

    static inline uint32x8 gather8(const uint32* address, int32x8 offset)
    {
        uint32x4 a = gather4(address, get_low(offset));
        uint32x4 b = gather4(address, get_high(offset));
        return combine(a, b);
    }

    static inline int32x8 gather8(const int32* address, int32x8 offset)
    {
        int32x4 a = gather4(address, get_low(offset));
        int32x4 b = gather4(address, get_high(offset));
        return combine(a, b);
    }

    static inline uint64x4 gather4(const uint64* address, int32x4 offset)
    {
        auto s0 = address[get_component<0>(offset)];
        auto s1 = address[get_component<1>(offset)];
        auto s2 = address[get_component<2>(offset)];
        auto s3 = address[get_component<3>(offset)];
        return uint64x4_set4(s0, s1, s2, s3);
    }

    static inline int64x4 gather4(const int64* address, int32x4 offset)
    {
        auto s0 = address[get_component<0>(offset)];
        auto s1 = address[get_component<1>(offset)];
        auto s2 = address[get_component<2>(offset)];
        auto s3 = address[get_component<3>(offset)];
        return int64x4_set4(s0, s1, s2, s3);
    }

    // 128 bit masked gather

    static inline float32x4 gather4(const float* address, int32x4 offset, float32x4 value, float32x4 mask)
    {
        return select(value, mask, gather4(address, offset));
    }

    static inline float64x2 gather2(const double* address, int32x4 offset, float64x2 value, float64x2 mask)
    {
        return select(value, mask, gather2(address, offset));
    }

    static inline uint32x4 gather4(const uint32* address, int32x4 offset, uint32x4 value, uint32x4 mask)
    {
        return select(value, mask, gather4(address, offset));
    }

    static inline int32x4 gather4(const int32* address, int32x4 offset, int32x4 value, int32x4 mask)
    {
        return select(value, mask, gather4(address, offset));
    }

    static inline uint64x2 gather2(const uint64* address, int32x4 offset, uint64x2 value, uint64x2 mask)
    {
        return select(value, mask, gather2(address, offset));
    }

    static inline int64x2 gather2(const int64* address, int32x4 offset, int64x2 value, int64x2 mask)
    {
        return select(value, mask, gather2(address, offset));
    }

    // 256 bit masked gather

    static inline float32x8 gather8(const float* address, int32x8 offset, float32x8 value, float32x8 mask)
    {
        return select(value, mask, gather8(address, offset));
    }

    static inline float64x4 gather4(const double* address, int32x4 offset, float64x4 value, float64x4 mask)
    {
        return select(value, mask, gather4(address, offset));
    }

    static inline uint32x8 gather8(const uint32* address, int32x8 offset, uint32x8 value, uint32x8 mask)
    {
        return select(value, mask, gather8(address, offset));
    }

    static inline int32x8 gather8(const int32* address, int32x8 offset, int32x8 value, int32x8 mask)
    {
        return select(value, mask, gather8(address, offset));
    }

    static inline uint64x4 gather4(const uint64* address, int32x4 offset, uint64x4 value, uint64x4 mask)
    {
        return select(value, mask, gather4(address, offset));
    }

    static inline int64x4 gather4(const int64* address, int32x4 offset, int64x4 value, int64x4 mask)
    {
        return select(value, mask, gather4(address, offset));
    }

#endif // defined(MANGO_ENABLE_AVX2)

} // namespace simd
} // namespace mango
