#include "main.h"

/*
Name	    : ELANTHAMIZHAN E
Date        :
Description :
Sample I/P  :
Sample O/P  :
*/


Status save_database(main_n* hash[])
{
	char file_n[30];
	printf("Enter the file name you want to save : ");
	scanf(" %s",file_n);
	if(strstr(file_n,".txt"))
		printf("INFO: File extension validation Success\n");
	else
		printf("INFO: Invalid file extension.\nPlease Enter .txt file\n");
	FILE* sfptr=fopen(file_n,"w");
	if(sfptr == NULL)
		return FAILURE;

	for(int i=0; i<=26; i++)
	 {
		 if(hash[i] != NULL)
		 {
			 main_n* temp_m=hash[i];
			 while(temp_m != NULL)
			 {
			 	 fprintf(sfptr,"%c%d%c",'#',i,';');
				 fprintf(sfptr,"%s%c",temp_m->word,';');
				 fprintf(sfptr,"%d%c",temp_m->fc,';');
				 sub_n* temp_s=temp_m->ms_link;
				 while( temp_s != NULL)
				 {
					 fprintf(sfptr,"%s%c",temp_s->fname,';');
					 if(temp_s->ss_link != NULL)
					 	fprintf(sfptr,"%d%c",temp_s->wc,';');
					 else
						fprintf(sfptr,"%d",temp_s->wc);
					 temp_s=temp_s->ss_link;
				 }
				 fprintf(sfptr,"%c\n",'#');
				 temp_m=temp_m->m_link;
			 }		

		 }
	 }
	return SUCCESS;
}

