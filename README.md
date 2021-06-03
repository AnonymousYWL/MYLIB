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

These commands will copy BLASFEO library and headers in the installation path PREFIX.

