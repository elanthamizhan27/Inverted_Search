#include "main.h"

/*
Name	    : ELANTHAMIZHAN E
Date        :
Description :
Sample I/P  :
Sample O/P  :
*/

extern int db_flag;
extern int update;


Status update_database(main_n* hash[])
{
	update =0;
	char backup[30];
	char str[100];
	printf("Enter the file you want to update : ");
	scanf(" %s",backup);
	FILE* fptr=fopen(backup,"r");
	if(fptr == NULL)
	{
		printf("ERROR: Invaild file name. Enter the correct file name which is used to backup database\n");
		return FAILURE;
	}
	char first=fgetc(fptr);
	fseek(fptr,-2,SEEK_END);
	char last=fgetc(fptr);
	rewind(fptr);
	if( first != last)
	{
		printf("ERROR: Invaild file name. Enter the correct file name which is used to backup database\n");
		return FAILURE;
	}

	while(fscanf(fptr,"%s",str) != EOF)
	{
		main_n* new_m=malloc(sizeof(main_n));
		if(new_m == NULL)
			return FAILURE;
		new_m->m_link=NULL;

		char* tok=strtok(str,"#;");
		int ind=atoi(tok);
		int fc;
		tok=strtok(NULL,"#;");
		strcpy(new_m->word,tok);
		tok=strtok(NULL,"#;");
		fc=atoi(tok);
		new_m->fc=fc;
		while(fc > 0)
		{
			int wc;
			sub_n* new_s=malloc(sizeof(sub_n));
			if(new_s == NULL)
				return FAILURE;
			new_s->ss_link=NULL;
			char* fname=malloc(sizeof(char)*30);
			if(fname == NULL)
				return FAILURE;
			tok=strtok(NULL,"#;");
			strcpy(fname,tok);
			new_s->fname=fname;	
			tok=strtok(NULL,"#;");
			wc=atoi(tok);
			new_s->wc=wc;
			if(new_m->ms_link == NULL)
				new_m->ms_link=new_s;
			else
			{
				sub_n* temp=new_m->ms_link;
				while( temp->ss_link != NULL)
					temp=temp->ss_link;
				temp->ss_link=new_s;
			}
			fc--;

		}
		if( hash[ind] == NULL)
			hash[ind]=new_m;
		else
		{
			main_n* temp=hash[ind];
			while( temp->m_link != NULL)
				temp=temp->m_link;
			temp->m_link=new_m;
		}
	}
	db_flag=1;

 return SUCCESS;
}

