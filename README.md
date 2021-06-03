# LibShalom

LibShalom is a Library for Small Irregular-shaped Matrix Multiplications on ARMv8-based processors. It improves the performance of small and irregular-shaped GEMMs on ARMv8-based
processors by improving the shortcomings of existing BLAS libraries, such as packing accounts for a large portion of the runtime, inefficient edge case processing and unreasonable parallelization methods.

# Software dependences
- [GNU Compiler (GCC)](https://gcc.gnu.org/) (>=v8.2)
- [OpenMP](https://www.openmp.org/)

# hardware platform
Phytium 2000+, Kunpeng 920, ThunderX2 or otther ARMv8-based processors

# Compile and install
$ cd NN_LIB && make  
$ make install PREFIX= the installation path  
These commands will copy LibShalom library and headers in the installation path PREFIX.

# API
__LibShalom_sgemm(int transa, int transb, float *C, float *A, float *B, long M, long N, long K)__   // Interface of small GEMM  
__LibShalom_sgemm_mp(int transa, int transb, float *C, float *A, float *B, long M, long N, long K)__   // Interface of irregular-shaped GEMM  
**LibShalom_set_thread_nums(int num)**                  // Set the total number of threads

# Running Examples
The command  
$ cd SGEMM && make  
will compile the benchmark program of fp32 small GEMM to generate the executable file main. By executing main, the user can get the evaluation result of the matrices of sizes from 8x8x8 to 128x128x128.

# Note
The matrices are stored in the row-major format in this library.
We will keep this library updated and maintained.
