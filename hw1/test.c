#include <time.h>
#include <stdio.h>
extern int findGCD(int, int);
int main(int argc, char* argv[])
{
		clock_t begin;
		int i,j,count;
		int upper = 9999;
		count=0;
		begin = clock();
		for(i=2;i<=upper;i++){
			for(j=i+1;j<=upper;j++){
				findGCD(i,j);
				count+=1;
			}
		}
		printf("%s finished %d cases(2~%d), time elapsed: %f\n",argv[0] , count, upper, (double) (clock()-begin)/CLOCKS_PER_SEC);

		return 0;
}

