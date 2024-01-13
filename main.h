#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct sub_node
{
	int wc;
	char* fname;
	struct sub_node* ss_link;

}sub_n;

typedef struct main_node
{
	char word[30];
	int fc;
	struct main_node* m_link;
	struct sub_node* ms_link;
}main_n;


typedef struct fname
{
	char* f_name;
	struct fname* f_link;
}file;

typedef enum
{
	SUCCESS,
	FAILURE
}Status;


Status read_validate(char* argv[],file** head);
Status menu(file** head,main_n* hash[]);
Status printlist(file* head);
Status create_database(file** head, main_n* hash[]);
Status display_database(main_n* hash[]);
Status search_database(main_n* hash[]);
Status save_database(main_n* hash[]);
Status update_database(main_n* hash[]);
#endif
