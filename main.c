#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct fun_1
{
	char fio[20];
	int gruop;
	int semestr[2];

};

struct fun_2
{
	int fiz;
	int mat;
	int angl;
	int oaip;
};
struct fun_3
{
	int georgafi;
	int chem;
	int mat2;
	int fiz2;
};


int main (int argc, char *argv[2])
{
	int ind1=0,ind2=0,ind3=0,zapret=0;
	struct fun_1 cp_1[20];
	struct fun_2 cp_2[20];
	struct fun_3 cp_3[20];
	FILE *file,*file2; 
    char *fname = "d:/githubdir/index.txt";
	char *foutt ="d:/githubdir/out.txt";
    char result_sting[20]; 
	

	
	if (argc==1)
	{
		printf(" No param is find\n");
		printf("Usage foo param \n");
		printf("Where param mean \n");
		printf("-e - enter stucturs \n");
		printf("-p - print structurs in file \n");
		printf("-x - find max marke \n");
		printf("-n - find min marke \n");
		printf("-h - information \n");
	}
	else
	{
		for(int i=0;i<argc;i++)
		{
	if(argv[i][0]=='-' && argv[i][1]=='h')
	{
		printf("================================================================================\n"
               "                                    Help:\n\n"
               "Commands: \\e \\p \\x \\n \n\n"
               "\\e - Structure input\n"
               "    1) Enter the name of the student. \n"
			   "    1) Enter the group number. \n"
               "    3) Enter marks. Marks should be integers from 1 to 10. "
               "\\p - Print whole structure.\n"
               "    Print all entries in file.\n\n"
               "\\x - Searching for the maximum average of exam\n"
               "    Displays the maximum average of exams.\n\n"
               "\\n - Searching for the minimum average of exam\n"
               "    Displays the minimum average of exams.\n\n"
               "================================================================================\n");
        exit(0);
	}
	if(argv[i][0]=='-' && argv[i][1]=='e')
	{
		int kol;
	printf("information on how many students want to enter ?");
	scanf_s("%d",&kol);
	ind2+=kol;
	
	for(int i=0;i<kol;i++)
	{
		printf("enter Name\n");
	    fflush(stdin);
		gets_s(cp_1[i+ind3].fio);
		printf("enter nomber of group");
		scanf_s("%d",& cp_1[i+ind3].gruop);
		cp_1[i+ind3].semestr[0]=1;
		printf("term 1 :english = ");
		scanf_s("%d",& cp_2[i+ind3].angl);
		printf("term 1 :physics = ");
		scanf_s("%d",& cp_2[i+ind3].fiz);
		printf("term 1 :mathem = ");
		scanf_s("%d",& cp_2[i+ind3].mat);
		printf("term 1 :oaip = ");
		scanf_s("%d",& cp_2[i+ind3].oaip);
		cp_1[i+ind3].semestr[1]=2;
		printf("term 2 :chem = ");
		scanf_s("%d",& cp_3[i+ind3].chem);
		printf("term 2 :physics = ");
		scanf_s("%d",& cp_3[i+ind3].fiz2);
		printf("term 2 :geography = ");
		scanf_s("%d",& cp_3[i+ind3].georgafi);
		printf("term 2 :mathem = ");
		scanf_s("%d",& cp_3[i+ind3].mat2);
	}
	ind3+=kol;
	
		break;
	}
	if(argv[i][0]=='-' && argv[i][1]=='p' && zapret==0)
	{
		file = fopen(fname,"r");
		int i=0,x=1;
		
		while (fscanf (file, "%s%d%d%d%d%d%d%d%d%d%d%d", cp_1[i].fio, &(cp_1[i].gruop), &(cp_1[i].semestr[0]), &(cp_2[i].angl), &(cp_2[i].fiz),&(cp_2[i].mat),&(cp_2[i].oaip),&(cp_1[i].semestr[1]),&(cp_3[i].chem),&(cp_3[i].fiz2),&(cp_3[i].georgafi),&(cp_3[i].mat2) ) != EOF)
		{ 
		i++;
		ind2++;
		ind3++;
		}
        fclose(file);
		zapret=1;

		file2 = fopen(foutt,"w");
	for(i=0;i<ind2;i++)
    fprintf(file2,"%s %3d%3d%3d%3d%3d%3d%3d%3d%3d%3d%3d \n", cp_1[i].fio, (cp_1[i].gruop), (cp_1[i].semestr[0]), (cp_2[i].angl), (cp_2[i].fiz),(cp_2[i].mat),(cp_2[i].oaip),(cp_1[i].semestr[1]),(cp_3[i].chem),(cp_3[i].fiz2),(cp_3[i].georgafi),(cp_3[i].mat2) ); 

    fclose(file2);


		break;
	}
	if(argv[i][0]=='-' && argv[i][1]=='x')
	{

		file = fopen(fname,"r");
		int i=0,x=1;
		
		while (fscanf (file, "%s%d%d%d%d%d%d%d%d%d%d%d", cp_1[i].fio, &(cp_1[i].gruop), &(cp_1[i].semestr[0]), &(cp_2[i].angl), &(cp_2[i].fiz),&(cp_2[i].mat),&(cp_2[i].oaip),&(cp_1[i].semestr[1]),&(cp_3[i].chem),&(cp_3[i].fiz2),&(cp_3[i].georgafi),&(cp_3[i].mat2) ) != EOF)
		{
		 
		i++;
		ind2++;
		ind3++;
		}

        fclose(file);
		float max1,middle_markes2[2][20],max2;
		int sem,ind5[2]={0,0};
		for(int i=0;i<ind2;i++)
		{
			middle_markes2[0][i]=(cp_2[i].angl + cp_2[i].fiz + cp_2[i].mat + cp_2[i].oaip)/4.;
			middle_markes2[1][i]=(cp_3[i].chem + cp_3[i].fiz2 + cp_3[i].georgafi + cp_3[i].mat2)/4.;
		}
		max1=middle_markes2[0][0];
		max2=middle_markes2[1][0];
		for(int i=0;i<ind2;i++)
		{
			if(middle_markes2[0][i]>max1)
			{
				max1=middle_markes2[0][i];
				ind5[0]=i;
			}
			if(middle_markes2[1][i]>max2)
			{
				max2=middle_markes2[1][i];
				ind5[1]=i;
			}
		}
		printf("the results of what the term ? 1-first, 2- second");
		scanf_s("%d",&sem);

		if(sem==1)
		{
			printf("Fio    group   term english physics mathem oaip term chem physics geography mathem \n");
		
			printf("%s %3d%3d%3d%3d%3d%3d%3d%3d%3d%3d%3d \n", cp_1[ind5[0]].fio, (cp_1[ind5[0]].gruop), (cp_1[ind5[0]].semestr[0]), (cp_2[ind5[0]].angl), (cp_2[ind5[0]].fiz),(cp_2[ind5[0]].mat),(cp_2[ind5[0]].oaip),(cp_1[ind5[0]].semestr[1]),(cp_3[ind5[0]].chem),(cp_3[ind5[0]].fiz2),(cp_3[ind5[0]].georgafi),(cp_3[ind5[0]].mat2) ); 
			printf("\n averge = %f", max1);
		}
		else
		{
			printf("Fio    group   term english physics mathem oaip term chem physics geography mathem \n");
		
			printf("%s %3d%3d%3d%3d%3d%3d%3d%3d%3d%3d%3d \n", cp_1[ind5[1]].fio, (cp_1[ind5[1]].gruop), (cp_1[ind5[1]].semestr[0]), (cp_2[ind5[1]].angl), (cp_2[ind5[1]].fiz),(cp_2[ind5[1]].mat),(cp_2[ind5[1]].oaip),(cp_1[ind5[1]].semestr[1]),(cp_3[ind5[1]].chem),(cp_3[ind5[1]].fiz2),(cp_3[ind5[1]].georgafi),(cp_3[ind5[1]].mat2) ); 
			printf("\n averge  = %f", max2);
		}

		break;
	}
	if(argv[i][0]=='-' && argv[i][1]=='n')
	{
		file = fopen(fname,"r");
		int i=0,x=1;
		//printf("Fio    grupa   Sem Angl fizika matim oaip sem chem fizika geografia matim \n");
		while (fscanf (file, "%s%d%d%d%d%d%d%d%d%d%d%d", cp_1[i].fio, &(cp_1[i].gruop), &(cp_1[i].semestr[0]), &(cp_2[i].angl), &(cp_2[i].fiz),&(cp_2[i].mat),&(cp_2[i].oaip),&(cp_1[i].semestr[1]),&(cp_3[i].chem),&(cp_3[i].fiz2),&(cp_3[i].georgafi),&(cp_3[i].mat2) ) != EOF)
		{
		//printf("%s %7d%5d%5d%5d%5d%5d%5d%5d%5d%5d%5d \n", cp_1[i].fio, (cp_1[i].gruop), (cp_1[i].semestr[0]), (cp_2[i].angl), (cp_2[i].fiz),(cp_2[i].mat),(cp_2[i].oaip),(cp_1[i].semestr[1]),(cp_3[i].chem),(cp_3[i].fiz2),(cp_3[i].georgafi),(cp_3[i].mat2) ); 
		i++;
		ind2++;
		ind3++;
		}
        fclose(file);
		float min1,middle_markes[2][20],min2;
		int sem,ind4[2];
		for(int i=0;i<ind2;i++)
		{
			middle_markes[0][i]=(cp_2[i].angl + cp_2[i].fiz + cp_2[i].mat + cp_2[i].oaip)/4.;
			middle_markes[1][i]=(cp_3[i].chem + cp_3[i].fiz2 + cp_3[i].georgafi + cp_3[i].mat2)/4.;
		}
		min1=middle_markes[0][0];
		min2=middle_markes[1][0];
		for(int i=0;i<ind2;i++)
		{
			if(middle_markes[0][i]<min1)
			{
				min1=middle_markes[0][i];
				ind4[0]=i;
			}
			if(middle_markes[1][i]<min2)
			{
				min2=middle_markes[1][i];
				ind4[1]=i;
			}
		}
		printf("the results of what the term ? 1-first, 2- second");
		scanf_s("%d",&sem);

		if(sem==1)
		{
			printf("Fio    group   term english physics mathem oaip term chem physics geography mathem \n");
		
			printf("%s %3d%3d%3d%3d%3d%3d%3d%3d%3d%3d%3d \n", cp_1[ind4[sem-1]].fio, (cp_1[ind4[sem-1]].gruop), (cp_1[ind4[sem-1]].semestr[0]), (cp_2[ind4[sem-1]].angl), (cp_2[ind4[sem-1]].fiz),(cp_2[ind4[sem-1]].mat),(cp_2[ind4[sem-1]].oaip),(cp_1[ind4[sem-1]].semestr[1]),(cp_3[ind4[sem-1]].chem),(cp_3[ind4[sem-1]].fiz2),(cp_3[ind4[sem-1]].georgafi),(cp_3[ind4[sem-1]].mat2) ); 
			printf("\n averge = %f", min1);
		}
		else
		{
			printf("Fio    group   term english physics mathem oaip term chem physics geography mathem \n");
		
			printf("%s %3d%3d%3d%3d%3d%3d%3d%3d%3d%3d%3d \n", cp_1[ind4[sem-1]].fio, (cp_1[ind4[sem-1]].gruop), (cp_1[ind4[sem-1]].semestr[0]), (cp_2[ind4[sem-1]].angl), (cp_2[ind4[sem-1]].fiz),(cp_2[ind4[sem-1]].mat),(cp_2[ind4[sem-1]].oaip),(cp_1[ind4[sem-1]].semestr[1]),(cp_3[ind4[sem-1]].chem),(cp_3[ind4[sem-1]].fiz2),(cp_3[ind4[sem-1]].georgafi),(cp_3[ind4[sem-1]].mat2) ); 
			printf("\n averge  = %f", min2);
		}



		break;
	}
	
		}
	}
	
	getch();
	
	return 0;
}