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
    char result_sting[20]; //������ � 20 ��������
	

	
	if (argc==1)
	{
		printf(" vu ne vveli parametru \n");
		printf("Usage foo param \n");
		printf("Where param mean \n");
		printf("-e - vvod structuru \n");
		printf("-h - vuvod structuru v file \n");
		printf("-x - poisk max o4enki \n");
		printf("-n - poisk min o4enki \n");
	}
	else
	{
		for(int i=0;i<argc;i++)
		{

	if(argv[i][0]=='-' && argv[i][1]=='e')
	{
		int kol;
	printf("informaciu ob skolbkix studentav gelaite vvesti ?");
	scanf_s("%d",&kol);
	ind2+=kol;
	
	for(int i=0;i<kol;i++)
	{
		printf("vvedite im9\n");
	    fflush(stdin);
		gets_s(cp_1[i+ind3].fio);
		printf("vvedite grupu");
		scanf_s("%d",& cp_1[i+ind3].gruop);
		cp_1[i+ind3].semestr[0]=1;
		printf("semestr 1 :angl = ");
		scanf_s("%d",& cp_2[i+ind3].angl);
		printf("semestr 1 :fiz = ");
		scanf_s("%d",& cp_2[i+ind3].fiz);
		printf("semestr 1 :mat = ");
		scanf_s("%d",& cp_2[i+ind3].mat);
		printf("semestr 1 :oaip = ");
		scanf_s("%d",& cp_2[i+ind3].oaip);
		cp_1[i+ind3].semestr[1]=2;
		printf("semestr 2 :chem = ");
		scanf_s("%d",& cp_3[i+ind3].chem);
		printf("semestr 2 :fiz2 = ");
		scanf_s("%d",& cp_3[i+ind3].fiz2);
		printf("semestr 2 :georgafi = ");
		scanf_s("%d",& cp_3[i+ind3].georgafi);
		printf("semestr 2 :mat2 = ");
		scanf_s("%d",& cp_3[i+ind3].mat2);
	}
	ind3+=kol;
	
		break;
	}
	if(argv[i][0]=='-' && argv[i][1]=='h' && zapret==0)
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
		//printf("Fio    grupa   Sem Angl fizika matim oaip sem chem fizika geografia matim \n");
		while (fscanf (file, "%s%d%d%d%d%d%d%d%d%d%d%d", cp_1[i].fio, &(cp_1[i].gruop), &(cp_1[i].semestr[0]), &(cp_2[i].angl), &(cp_2[i].fiz),&(cp_2[i].mat),&(cp_2[i].oaip),&(cp_1[i].semestr[1]),&(cp_3[i].chem),&(cp_3[i].fiz2),&(cp_3[i].georgafi),&(cp_3[i].mat2) ) != EOF)
		{
		//printf("%s %7d%5d%5d%5d%5d%5d%5d%5d%5d%5d%5d \n", cp_1[i].fio, (cp_1[i].gruop), (cp_1[i].semestr[0]), (cp_2[i].angl), (cp_2[i].fiz),(cp_2[i].mat),(cp_2[i].oaip),(cp_1[i].semestr[1]),(cp_3[i].chem),(cp_3[i].fiz2),(cp_3[i].georgafi),(cp_3[i].mat2) ); 
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
		printf("po itogom kakova semestra ? 1-pervogo, 2- vtoroga");
		scanf_s("%d",&sem);

		if(sem==1)
		{
			printf("Fio    grupa   Sem Angl fizika matim oaip sem chem fizika geografia matim \n");
		
			printf("%s %3d%3d%3d%3d%3d%3d%3d%3d%3d%3d%3d \n", cp_1[ind5[0]].fio, (cp_1[ind5[0]].gruop), (cp_1[ind5[0]].semestr[0]), (cp_2[ind5[0]].angl), (cp_2[ind5[0]].fiz),(cp_2[ind5[0]].mat),(cp_2[ind5[0]].oaip),(cp_1[ind5[0]].semestr[1]),(cp_3[ind5[0]].chem),(cp_3[ind5[0]].fiz2),(cp_3[ind5[0]].georgafi),(cp_3[ind5[0]].mat2) ); 
			printf("\n sredn99 ocenka = %f", max1);
		}
		else
		{
			printf("Fio    grupa   Sem Angl fizika matim oaip sem chem fizika geografia matim \n");
		
			printf("%s %3d%3d%3d%3d%3d%3d%3d%3d%3d%3d%3d \n", cp_1[ind5[1]].fio, (cp_1[ind5[1]].gruop), (cp_1[ind5[1]].semestr[0]), (cp_2[ind5[1]].angl), (cp_2[ind5[1]].fiz),(cp_2[ind5[1]].mat),(cp_2[ind5[1]].oaip),(cp_1[ind5[1]].semestr[1]),(cp_3[ind5[1]].chem),(cp_3[ind5[1]].fiz2),(cp_3[ind5[1]].georgafi),(cp_3[ind5[1]].mat2) ); 
			printf("\n sredn99 ocenka = %f", max2);
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
		printf("po itogom kakova semestra ? 1-pervogo, 2- vtoroga");
		scanf_s("%d",&sem);

		if(sem==1)
		{
			printf("Fio    grupa   Sem Angl fizika matim oaip sem chem fizika geografia matim \n");
		
			printf("%s %3d%3d%3d%3d%3d%3d%3d%3d%3d%3d%3d \n", cp_1[ind4[sem-1]].fio, (cp_1[ind4[sem-1]].gruop), (cp_1[ind4[sem-1]].semestr[0]), (cp_2[ind4[sem-1]].angl), (cp_2[ind4[sem-1]].fiz),(cp_2[ind4[sem-1]].mat),(cp_2[ind4[sem-1]].oaip),(cp_1[ind4[sem-1]].semestr[1]),(cp_3[ind4[sem-1]].chem),(cp_3[ind4[sem-1]].fiz2),(cp_3[ind4[sem-1]].georgafi),(cp_3[ind4[sem-1]].mat2) ); 
			printf("\n sredn99 ocenka = %f", min1);
		}
		else
		{
			printf("Fio    grupa   Sem Angl fizika matim oaip sem chem fizika geografia matim \n");
		
			printf("%s %3d%3d%3d%3d%3d%3d%3d%3d%3d%3d%3d \n", cp_1[ind4[sem-1]].fio, (cp_1[ind4[sem-1]].gruop), (cp_1[ind4[sem-1]].semestr[0]), (cp_2[ind4[sem-1]].angl), (cp_2[ind4[sem-1]].fiz),(cp_2[ind4[sem-1]].mat),(cp_2[ind4[sem-1]].oaip),(cp_1[ind4[sem-1]].semestr[1]),(cp_3[ind4[sem-1]].chem),(cp_3[ind4[sem-1]].fiz2),(cp_3[ind4[sem-1]].georgafi),(cp_3[ind4[sem-1]].mat2) ); 
			printf("\n sredn99 ocenka = %f", min2);
		}



		break;
	}
	else
	{
		printf("nevernui parametr");
	}
		}
	}
	
	getch();
	
	return 0;
}