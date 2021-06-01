#ifndef __TEST_H__ 
#define __TEST_H__ 

#include<stdio.h>
void NN_SMM(float *C, float *A, float *B, long M, long N, long K);
void SMM_L1(float *C, float *A, float *B, long M, long N, long K);
void SMM(float *C, float *A, float *B, long M, long N, long K, float *SB);

#endif