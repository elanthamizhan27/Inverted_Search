#include "main.h"

/*
Name	    : ELANTHAMIZHAN E
Date        :
Description :
Sample I/P  :
Sample O/P  :
*/


Status display_database(main_n* hash[])
{
	for(int i=0; i<100; i++)
		printf("=");
	printf("\n");
	printf("%-8s%-10s%-15s%s\n","Index","Word","Filecount","Filename [Word Count]");
	for(int i=0; i<100; i++)
		printf("=");
	printf("\n");

	 for(int i=0; i<=26; i++)
	 {
		 if(hash[i] != NULL)
		 {
			 printf("\n");
			 main_n* temp_m=hash[i];
			 while(temp_m != NULL)
			 {
			 	 printf("[%.2d]    ",i);
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
				 printf("\n");
				 temp_m=temp_m->m_link;
			 }
			for(int i=0;i<100; i++) 
				printf("_");
			printf("\n");		

		 }
	 }
	 printf("\n");
	 return SUCCESS;
}

