#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_LAST_NAME_SIZE 16
typedef struct __PHONE_BOOK_ENTRY{
    char LastName[MAX_LAST_NAME_SIZE];
    struct __PHONE_BOOK_ENTRY *pNext;
}PhoneBook;
static struct __PHONE_BOOK_ENTRY* phonebook =NULL;
static int maxIndex=0;
void deallocateData(void)
{
}
//we don't allocate in this case...
void allocateData(int size)
{
		maxIndex = size;
}
void insertData(char* Last)
{
		static int index = 0;
		struct __PHONE_BOOK_ENTRY* newNode;
		newNode = malloc(sizeof(struct __PHONE_BOOK_ENTRY));
		strcpy(newNode->LastName, Last);
		newNode->pNext = phonebook;
		phonebook = newNode;
		//if(index==(maxIndex-1) || index==0)printf("init str1: %s, str2: %s\n",Last, phonebook->LastName);
		index++;
}

int FindName(char* Last)
{
		//printf("search %s, start from: %s\n", Last, phonebook->LastName);
    while (phonebook->pNext!=NULL) {
        if (strcmp(Last, phonebook->LastName) == 0)
            return 1;
        phonebook = phonebook->pNext;
    }
    if (strcmp(Last, phonebook->LastName) == 0)
			return 1;
		
    return 0;
}


