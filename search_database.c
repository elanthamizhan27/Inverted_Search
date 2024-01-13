#include "main.h"

/*
Name	    : ELANTHAMIZHAN E
Date        :
Description :
Sample I/P  :
Sample O/P  :
*/


Status search_database(main_n* hash[])
{

	char word[30];
	printf("Enter the word you want to search : ");
	scanf(" %s",word);
	char ch=word[0];
	ch=tolower(ch);
	int ind;
	if( ch >= 'a' && ch <= 'z')
		ind=ch % 97;
	else
		ind=26;
	for(int i=0; i<100; i++)
		printf("=");
	printf("\n");
	printf("%-8s%-10s%-15s%s\n","Index","Word","Filecount","Filename [Word Count]");
	for(int i=0; i<100; i++)
		printf("=");
	printf("\n");
	if(hash[ind] != NULL)
	{
		printf("\n");
		main_n* temp_m=hash[ind];
		while(temp_m != NULL)
		{
			if((!strcmp(temp_m->word,word)))
			{
				printf("[%.2d]    ",ind);
				printf("%-10s",temp_m->word);
				printf("%-15d",temp_m->fc);
				sub_n* temp_s=temp_m->ms_link;
				while( temp_s != NULL)
				{
					printf("%s ",temp_s->fname);
					printf("[%d]",temp_s->wc);
					printf("\t");
					temp_s=temp_s->ss_link;
				}
			}
			temp_m=temp_m->m_link;
		}
		printf("\n");
		for(int i=0;i<100; i++) 
			printf("_");
		printf("\n");
		return SUCCESS;
	}
	else
 		return FAILURE;
}

