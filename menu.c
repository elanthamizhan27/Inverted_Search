#include "main.h"

/*
Name	    : ELANTHAMIZHAN E
Date        :
Description :
Sample I/P  :
Sample O/P  :
*/

int db_flag=0;
int update=1;

Status menu(file** head, main_n* hash[])
{
	char ch='y';
	while(ch == 'y' || ch == 'Y')
	{
		printf("\n====DISPLAY MENU====\n");
		printf("1.Create database.\n2.Display database.\n3.Search database.\n4.Save database.\n5.Update database.\n\n");
		int op;
		printf("Enter the choise : ");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				if(db_flag == 0 && update == 1)
				{
					printf("\n====CREATE DATABASE====\n");
					if(create_database(head,hash) == SUCCESS)
						printf("\nINFO: Create database Success\n\n");
					else
						printf("\nERROR: Create database failed\n\n");
				}
				else
					printf("\nWARNING: Database already created\n\n");
				break;
			case 2:
				if(db_flag == 1)
				{
					printf("\n====DISPLAY DATABASE====\n");
					if(display_database(hash) == SUCCESS)
						printf("\nINFO: Display database Success\n\n");
					else
							printf("\nERROR: Display database failed\n\n");
				}
				else 
					printf("\nWARNING: Database is not created\n\n");
				break;
			case 3:
				if(db_flag == 1)
				{
					printf("\n====SEARCH DATABASE====\n");
					if(search_database(hash) == SUCCESS)
						printf("\nINFO: Search in database Success\n\n");
					else
						printf("\nERROR: Search in database failed\n\n");
				}
				else
					printf("\nWARNING: Database is not created\n\n");
				break;
			case 4:
				if(db_flag == 1 && update == 1)
				{
					printf("\n====SAVE DATABASE====\n");
					if(save_database(hash) == SUCCESS)
						printf("\nINFO: Save database Success\n\n");
					else
						printf("\nERROR: Save database failed\n\n");
				}
				else
				{
					if(update == 0)
						printf("\nWARNING: Database is updated from saved backup\n\n");
					else
						printf("\nWARNING: Data is not created\n\n");

				}
				break;
			case 5:
				if(db_flag == 0)
				{
					printf("\n====UPDATE DATABASE====\n");
					if( update_database(hash) == SUCCESS)
						printf("\nINFO: Update database is Successful\n\n");
					else
						printf("\nERROR: Update database is failed\n\n");
				}
				else
					printf("\nWARNING: Already database is created\n\n");
				break;
			default:
					printf("\nERROR: Invalid option\n\n");
			}
			printf("\nDo you want to continue(y/Y or n/N) : ");
			scanf(" %c",&ch);
		}





 return SUCCESS;
}

