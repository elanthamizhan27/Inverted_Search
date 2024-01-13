#include "main.h"

/*
Name	    : ELANTHAMIZHAN E
Date        :
Description :
Sample I/P  :
Sample O/P  :
*/
extern int db_flag;

Status create_database(file** head, main_n* hash[])
{
	char word[30];
	file* temp=*head;
	FILE* fptr;
	int ind;
	while(temp != NULL)
	{
		if((fptr=fopen(temp->f_name,"r")) != NULL)
		{
			while((fscanf(fptr,"%s",word)) != EOF)
			{
				char ch=word[0];
				ch=tolower(ch);
				if(ch >= 'a' && ch <= 'z')
					ind=ch % 97;
				else
					ind=26;
				int cmp_f=0;
				int cmp_w=0;
					
				main_n* new_m=malloc(sizeof(main_n));
				if(new_m == NULL)
					return FAILURE;
				new_m->m_link=NULL;
			
				sub_n* new_s=malloc(sizeof(sub_n));
				if(new_s == NULL)
					return FAILURE;
				new_s->ss_link=NULL;
	
				if(hash[ind] == NULL)
				{
					(new_s->wc)++;
					new_s->fname=temp->f_name;
					strcpy(new_m->word,word);
					(new_m->fc)++;
					new_m->ms_link=new_s;
					hash[ind]=new_m;

				}
				else
				{
					main_n* temp_m=hash[ind];
					main_n* prev_m=NULL;
					while(temp_m != NULL)
					{
						if(!(strcmp(temp_m->word,word)))
						{
							sub_n* temp_s=temp_m->ms_link;
							sub_n* prev_s=NULL;
							cmp_w=1;
							while(temp_s != NULL)
							{
								if(!(strcmp(temp_s->fname,temp->f_name)))
								{
									(temp_s->wc)++;
									free(new_m);
									free(new_s);
									cmp_f=1;
									break;
								}
								prev_s=temp_s;
								temp_s=temp_s->ss_link;
							}
							if(cmp_f == 0)
							{
								(temp_m->fc)++;
								(new_s->wc)++;
								new_s->fname=temp->f_name;
								prev_s->ss_link=new_s;
								free(new_m);
							}

						}
						if(cmp_w == 1)
							break;
						prev_m=temp_m;
						temp_m=temp_m->m_link;
					}
					if(cmp_w == 0)
					{
						(new_s->wc)++;
						new_s->fname=temp->f_name;
						strcpy(new_m->word,word);
						(new_m->fc)++;
						new_m->ms_link=new_s;
						prev_m->m_link=new_m;

					}

				}



			}

		}
		else
		{
			perror("fopen");
			fprintf(stderr, "ERROR: Unable to open file %s\n",temp->f_name);
		}
		temp=temp->f_link;
	}



	db_flag=1;
 return SUCCESS;
}

