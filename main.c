#include "main.h"

/*
Name	    : ELANTHAMIZHAN E
Date        :
Description :
Sample I/P  :
Sample O/P  :
*/



int main(int argc, char* argv[])
{
	file* head=NULL;
	main_n* hash[27]={NULL}; 
 	if( argc == 1)
		menu(&head,hash);	
	else
	{
		printf("====READ AND VALIDATION STARTED====\n");
		if(read_validate(argv,&head) == SUCCESS)
		{
			printf("INFO: Read and Validation Success\n");
			printf("List of Valid Input files\n");
			printlist(head);
		}
		else
		{
			printf("ERROR: Read and validation Failure\n");	
		}
		menu(&head,hash);
		
	}

 return 0;
}

