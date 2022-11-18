// Copy cinn cuda code here

#pragma once

extern "C" {

#include "cinn_cuda_runtime_source.cuh"

#ifdef __CUDACC_RTC__
typedef int int32_t;
typedef char int8_t;
typedef long int int64_t;
#endif

// Calls with block = 1024, thread = 128
__global__
void __launch_bounds__(128) cinn_matmul_1024x1024(const float* __restrict__ X, const float* __restrict__ Y, float* __restrict__ temp_matmul_out)
{
  const float* X_reshape = X;
  const float* Y_reshape = Y;
  float* temp_matmul_out__reduce_init = temp_matmul_out;
  {
    if (((int)blockIdx.x < 1024)) {
      if (((int)threadIdx.x < 128)) {
        for (int32_t i_2 = 0; i_2 < 1; i_2 += 1) {
          for (int32_t j_2 = 0; j_2 < 1; j_2 += 1) {
            for (int32_t i_3 = 0; i_3 < 1; i_3 += 1) {
              for (int32_t j_3 = 0; j_3 < 1; j_3 += 1) {
                for (int32_t i_4 = 0; i_4 < 2; i_4 += 1) {
                  for (int32_t j_4 = 0; j_4 < 4; j_4 += 1) {
                    temp_matmul_out__reduce_init[((16384 * ((int)blockIdx.x / 16)) + ((2048 * ((int)threadIdx.x / 16)) + ((64 * ((int)blockIdx.x & 15)) + ((4 * ((int)threadIdx.x & 15)) + ((2048 * i_2) + ((2048 * i_3) + ((1024 * i_4) + ((4 * j_2) + ((4 * j_3) + j_4)))))))))] = 0;
                  };
                };
              };
            };
          };
        };
      };
    };
    if (((int)blockIdx.x < 1024)) {
      if (((int)threadIdx.x < 128)) {
        for (int32_t i_2 = 0; i_2 < 1; i_2 += 1) {
          for (int32_t j_2 = 0; j_2 < 1; j_2 += 1) {
            for (int32_t reduce_k_0 = 0; reduce_k_0 < 64; reduce_k_0 += 1) {
              for (int32_t reduce_k_1 = 0; reduce_k_1 < 4; reduce_k_1 += 1) {
                for (int32_t i_3 = 0; i_3 < 1; i_3 += 1) {
                  for (int32_t j_3 = 0; j_3 < 1; j_3 += 1) {
                    for (int32_t reduce_k_2 = 0; reduce_k_2 < 4; reduce_k_2 += 1) {
                      for (int32_t i_4 = 0; i_4 < 2; i_4 += 1) {
                        for (int32_t j_4 = 0; j_4 < 4; j_4 += 1) {
                          temp_matmul_out[((16384 * ((int)blockIdx.x / 16)) + ((2048 * ((int)threadIdx.x / 16)) + ((64 * ((int)blockIdx.x & 15)) + ((4 * ((int)threadIdx.x & 15)) + ((2048 * i_2) + ((2048 * i_3) + ((1024 * i_4) + ((4 * j_2) + ((4 * j_3) + j_4)))))))))] = (temp_matmul_out[((16384 * ((int)blockIdx.x / 16)) + ((2048 * ((int)threadIdx.x / 16)) + ((64 * ((int)blockIdx.x & 15)) + ((4 * ((int)threadIdx.x & 15)) + ((2048 * i_2) + ((2048 * i_3) + ((1024 * i_4) + ((4 * j_2) + ((4 * j_3) + j_4)))))))))] + (X_reshape[((16384 * ((int)blockIdx.x / 16)) + ((2048 * ((int)threadIdx.x / 16)) + ((2048 * i_2) + ((2048 * i_3) + ((1024 * i_4) + ((16 * reduce_k_0) + ((4 * reduce_k_1) + reduce_k_2)))))))] * Y_reshape[((64 * ((int)blockIdx.x & 15)) + ((4 * ((int)threadIdx.x & 15)) + ((4 * j_2) + ((4 * j_3) + ((16384 * reduce_k_0) + ((4096 * reduce_k_1) + ((1024 * reduce_k_2) + j_4)))))))]));
                        };
                      };
                    };
                  };
                };
              };
            };
          };
        };
      };
    };
  };
}

__global__
void __launch_bounds__(1) cinn_matmul_1024x1024_no_schedule(const float* __restrict__ X, const float* __restrict__ Y, float* __restrict__ temp_matmul_out)
{
  const float* X_reshape = X;
  const float* Y_reshape = Y;
  float* temp_matmul_out__reduce_init = temp_matmul_out;
  for (int32_t i = 0; i < 1024; i += 1) {
    for (int32_t j = 0; j < 1024; j += 1) {
      temp_matmul_out__reduce_init[((1024 * i) + j)] = 0;
      for (int32_t reduce_k = 0; reduce_k < 1024; reduce_k += 1) {
        temp_matmul_out[((1024 * i) + j)] = (temp_matmul_out[((1024 * i) + j)] + (X_reshape[((1024 * i) + reduce_k)] * Y_reshape[((1024 * reduce_k) + j)]));
      };
    };
  };
}

// Calls with block = 1024, thread = 1024
__global__
void __launch_bounds__(1024) cinn_matmul_1024x1024_bind_schedule(const float* __restrict__ X, const float* __restrict__ Y, float* __restrict__ temp_matmul_out)
{
  const float* X_reshape = X;
  const float* Y_reshape = Y;
  float* temp_matmul_out__reduce_init = temp_matmul_out;
  if (((int)blockIdx.x < 1024)) {
    if (((int)threadIdx.x < 1024)) {
      temp_matmul_out__reduce_init[(1024 * (int)blockIdx.x) + (int)threadIdx.x] = 0;
      for (int32_t reduce_k = 0; reduce_k < 1024; reduce_k += 1) {
        temp_matmul_out[((1024 * (int)blockIdx.x) + (int)threadIdx.x)] = (temp_matmul_out[((1024 * (int)blockIdx.x) + (int)threadIdx.x)] + (X_reshape[((1024 * (int)blockIdx.x) + reduce_k)] * Y_reshape[((1024 * reduce_k) + (int)threadIdx.x)]));
      };
    };
  };
}

}


