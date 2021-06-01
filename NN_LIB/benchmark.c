#include<stdio.h>
#include<sys/time.h>
#include <stdlib.h>

#include "test_temp_L1.h"


static double gtod_ref_time_sec = 0.0;

double dclock()
{
        double the_time, norm_sec;
        struct timeval tv;

        gettimeofday( &tv, NULL );

        if ( gtod_ref_time_sec == 0.0 )
                gtod_ref_time_sec = ( double ) tv.tv_sec;

        norm_sec = ( double ) tv.tv_sec - gtod_ref_time_sec;

        the_time = norm_sec + tv.tv_usec * 1.0e-6;

        return the_time;
}

void random_matrix( int m, int n, float *a)
{
  double drand48();
  int i,j;

  for ( i=0; i<m; i++ )
    for ( j=0; j<n; j++ )
		a[i*n+j]= 2.0 * (float)drand48( ) - 1.0 ;
}


void random_matrix1( int m, int n, float *a)
{
  double drand48();
  int i,j;

  for ( i=0; i<m; i++ )
    for ( j=0; j<n; j++ )
		a[i*n+j]= 1.0 ;
}

int main()
{

	int i,j,k;
	int loop=100;
	long M, N, K;
	float *C1;
	double start, cost;
	double gflops;
	int flag =0 ;
	long temp =-1;
	int pc;

	FILE *fp;


  	if( (fp=fopen("NSMM_small.txt","w")) == NULL )
  	{
    	puts("Fail to open file!");
    	exit(0);
  	}

    for( j =8; j < 129; j = j + 8)
    {


        M= N = K = j;
    	double ops = M *N *K * 1.0e-09 * 2;
    	fprintf(fp, "%d %d %d", M,N,K);

    	for(pc =0 ;pc < 5; pc++)
    	{
	    	float *A = ( float * ) malloc( K* M * sizeof( float ) );
	    	float *B = ( float * ) malloc( K* N * sizeof( float ) );
	    	float *C = ( float * ) malloc( M* N * sizeof( float ) );
	    	float *SB= ( float * ) malloc( K* N * sizeof( float ) );

	    	random_matrix(M,K,A);
	    	random_matrix(K,N,B);

		    for( i =0 ;i< 5; i++)
		    	NN_SMM(C, A, B, M, N, K);

			start = dclock();
			for( i= 0; i< loop ;i++)
				NN_SMM(C, A, B, M, N, K);
			cost =(dclock()-start)/loop; 

			ops = M * N  * K * 1.0e-09 * 2;
			printf("N_SMM:  M= %d N=%d K=%d flops = %lf effic= %.3lf %\n", M, N, K, ops/cost, ops/cost/17.6 * 100);
			fprintf(fp, " %.3f", ops/cost);

		    free(A);
		    free(B);
		    free(C);
		    free(SB);
		}

		fprintf(fp, "\n");
	}

	fclose(fp);
    return 0;
}