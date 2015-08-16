#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_LAST_NAME_SIZE 16
#define BLOCKSIZE 90000
typedef struct __PHONE_BOOK_ENTRY{
				char LastName[MAX_LAST_NAME_SIZE];
				struct __PHONE_BOOK_ENTRY *pNext;
}PhoneBook;
static struct __PHONE_BOOK_ENTRY* phonebook =NULL;
static struct __PHONE_BOOK_ENTRY* free_phonebook =NULL;
void allocateData(void)
{
		int i;
		free_phonebook = malloc(BLOCKSIZE * sizeof(struct __PHONE_BOOK_ENTRY));
		for(i=0; i<BLOCKSIZE-1; i++)
				free_phonebook[i].pNext = &free_phonebook[i+1];
		free_phonebook[BLOCKSIZE-1].pNext = NULL;
}
void deallocateData()
{
		//todo
}
void insertData(char* Last)
{
		//static int index = 0;
		struct __PHONE_BOOK_ENTRY* newNode;
		//newNode = malloc(sizeof(struct __PHONE_BOOK_ENTRY));
		if(free_phonebook == NULL)
				return;
		newNode = free_phonebook;
		free_phonebook = free_phonebook->pNext;
		
		strcpy(newNode->LastName, Last);
		newNode->pNext = phonebook;
		phonebook = newNode;
		//if(index==(maxIndex-1) || index==0)printf("init str1: %s, str2: %s\n",Last, phonebook->LastName);
		//index++;
}

int FindName(char* Last)
{
		//printf("search %s, start from: %s\n", Last, phonebook->LastName);
    struct __PHONE_BOOK_ENTRY* searchNode = phonebook;
		while (searchNode!=NULL) {
        if (strcmp(Last, searchNode->LastName) == 0)
            return 1;
        searchNode = searchNode->pNext;
    }
    return 0;
}


