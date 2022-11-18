nvcc -o main.o main.cu

CUDA_VISIBLE_DEVICES=1 ./main.o
