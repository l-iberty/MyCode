#include <stdio.h>

int main (void)
{
	int n, m, s, r;
	int k;
	int count1, count2;
	
	while (1){
	
	while (1)
	{
		printf("\nEnter the number of the rows and the columns of the matrix(in order):\n"); 
	    puts("Matrix A:");
		scanf("%d%d", &n,&m);
	    puts("Matrix B:");
	    scanf("%d%d", &s, &r);
	    
	    if ( m != s)
	    {
	    	printf("Matrix A cannot time Matrix B£¡Please try again!");
			continue; 
		}
		else
		    break;
	}
	
	int A[n][m], B[s][r], AB[n][r];
	
	printf("\nEnter the element of Matrix A and B:\n");
	printf("Matrix A :\n");
	for ( count1 = 0; count1 < n; count1++ )
	{
		for ( count2 = 0; count2 < m; count2++ )
		{
			printf("A[%d][%d] = ", count1+1, count2+1);
			scanf("%d", &A[count1][count2]);
		}
	}
	
	printf("\nMatrix B :\n");
	for ( count1 = 0; count1 < s; count1++ )
	{
		for ( count2 = 0; count2 < r; count2++ )
		{
			printf("B[%d][%d] = ", count1+1, count2+1);
			scanf("%d", &B[count1][count2]);
		}
	} 
	
	printf("\nThe results:\nMatrix A:\n");
	for ( count1 = 0; count1 < n; count1++ )
	{
		for ( count2 = 0; count2 < m; count2++ )
		{
			printf("\t%d", A[count1][count2]);
			if ( count2 == m-1 )
			   printf("\n");
		}
	}
	
	printf("\nMatrix B:\n");
	for ( count1 = 0; count1 < s; count1++ )
	{
		for ( count2 = 0; count2 < r; count2++ )
		{
			printf("\t%d", B[count1][count2]);
			if ( count2 == r-1 )
			   printf("\n");
		}
	}
	
	for ( count1 = 0; count1 < n; count1++ )
	{
		for ( count2 = 0; count2 < r; count2++ )
		    AB[count1][count2] = 0;
	}
	for ( count1 = 0; count1 < n; count1++ )
	{
		for ( count2 = 0; count2 < r; count2++ )
		{
			for ( k = 0; k < m; k++ )
			    AB[count1][count2] += A[count1][k] * B[k][count2]; 
		}
	}
	
	printf("\nMatrix AB:\n");
	for ( count1 = 0; count1 < n; count1++ )
	{
		for ( count2 = 0; count2 < r; count2++ )
		{
			printf("\t%d", AB[count1][count2]);
			if ( count2 == r-1 )
			   printf("\n");
		}
	}
	
    }
	
	return 0;
}
