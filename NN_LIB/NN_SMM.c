#include <stdio.h>
#include "test_temp_L1.h"
#include <stdlib.h>

void NN_SMM(float *C, float *A, float *B, long M, long N, long K)
{

	if(N > 96)
	{
		float *SB= ( float * ) malloc( K* 16 * sizeof( float ) );
		SMM(C, A, B, M, N, K, SB);
		free(SB);
	}
	else
	{
		SMM_L1(C, A, B, M, N, K);
	}
}
