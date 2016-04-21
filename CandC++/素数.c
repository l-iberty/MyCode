# include <stdio.h>
# include <math.h>
# define N 200

int main(void){
	int k;
	for(k = 2; k <= N ; k++)
		if(isPrime(k))
			printf("%d  ", k);
			
	return 0;
}

int isPrime(int number){
	int i;
	for(i = 2; i <= sqrt(number); i++)
		if(number % i == 0)
			return 0;
			
	return 1;
}
