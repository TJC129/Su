/*
	Runs the tests of findGCD, with input range [2, 9999]
*/
#include <time.h>
#include <stdio.h>
extern int findGCD(int, int);
int main(int argc, char* argv[])
{
		clock_t begin;
		int i,j;
		int upper = 9999;
		double totalTime;
		begin = clock();
		for(i=2;i<=upper;i++){
			for(j=i+1;j<=upper;j++){
				findGCD(i,j);
				
			}
		}
		totalTime = (double) (clock()-begin)/CLOCKS_PER_SEC;
		printf("%s finished cases(2~%d), time elapsed: %f\n",argv[0] , upper,totalTime); 

		return 0;
}

