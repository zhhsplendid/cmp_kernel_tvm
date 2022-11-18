A repo to compare CINN and TVM Matmul CUDA kernel speed.

Steps:

1. Run TVM or CINN auto schedule, get the CUDA kernel code from log
2. Copy the log into tvm_kernel.h or cinn_kernel.h
3. Change main.cu where call the kernel
4. Modify CUDA_VISIBLE_DEVICES in run.sh, then bash run.sh
