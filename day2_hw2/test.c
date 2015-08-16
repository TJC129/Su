#include <stdio.h>
#include <string.h>
#include <time.h>
#define DATA_ENTRIES 88799

extern void allocateData(int size);
extern void deallocateData(void);
extern void insertData(char* lastName);
extern int FindName(char* lastName);
int main(int argc, char* argv[])
{
		clock_t clock_begin;
		double time_result;
		FILE* fp = fopen("lastname.txt", "r");//entries:88799
		char tempName[16];
		//int count=0;
		if(fp==NULL)//open fail
		{
				printf("error opening file");
				return -1;
		}
		allocateData(DATA_ENTRIES);
		while (fscanf(fp, "%15s", tempName)==1)
		{
				//for measuring dataset size
				//count+=1;
				//if(strlen(tempName)>=13)
				//printf("%d: %s, length: %zd\n",count, tempName, strlen(tempName));

				if(feof(fp))//if the last line of data
				{
						fclose(fp);
						break;
				}
				else
				{
				//initialize the datastructure here
						insertData(tempName);
				}
		}
		//search the dataset here, and record the running time
		clock_begin = clock();
		FindName("Aaberg");//last case in DATA
		time_result = (double)(clock() - clock_begin) / CLOCKS_PER_SEC;
		printf("%s found the last case from %d cases, time elapsed:%f \n",\
				 argv[0], DATA_ENTRIES, time_result);
		deallocateData();
		return 0;
}
