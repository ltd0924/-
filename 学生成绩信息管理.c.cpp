#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define STU 3
#define VAL 4/*�������ѧ��������ͳ�ƿ�Ŀ��*/
struct person
{
	char name[20];
	float sc[VAL+2];
}stu[STU+2];/*����ṹ��*/
void stuave(struct person *p);
void stuadd(struct person *p);
void valave(struct person *p);
void valadd(struct person *p);
void menu1();
void menu2();
void menu3();
int statistics();
int fag();
void find(char *p);
void again(struct person *p);
void change(char *p);
void dataLoad();
void dataSave();
int main()
{
	char c;
	while(1)
	{
		menu1();
		c=getch();
		printf("%c\n",c);
		switch(c)
		{
		case '1':{statistics();printf("\n�밴��������ز˵�!");break;}
		case '2':{fag();printf("\n�밴��������ز˵�!");break;}
		case '0':{printf("\n\t��ѡ�����˳�ƽ̨��ллʹ�ã��ټ�!\n\n\t");dataSave();return(0);}
		default:{printf("\n\t������������!");printf("\n�밴��������ز˵���");}
		}
		getch();
	}
}
void menu1()/*�˵�1*/
{
	system("cls");
	printf("\n\n\t**************** ��ӭ����ѧ���ɼ���Ϣ����ƽ̨�� ****************");
	printf("\n\n\n\t1->ѧ���ɼ�ͳ��ϵͳ");
	printf("\n\n\n\t2->ѧ���ɼ����Ҽ��޸�ϵͳ");
	printf("\n\n\n\t0->�˳�ƽ̨");
	printf("\n\n\t******************************************************");
	printf("\n\n\t��ѡ��ѡ�");
}
void menu2()/*�˵�2*/
{
	system("cls");
	printf("\n\n\t**************** ��ӭ����ѧ���ɼ�ͳ��ϵͳ�� ****************");
	printf("\n\n\n\t1->ͳ�Ƶ���ѧ��ƽ���ɼ�");
	printf("\n\n\n\t2->ͳ�Ƶ���ѧ���ܳɼ�");
	printf("\n\n\n\t3->ͳ�Ƶ���ƽ���ɼ�");
	printf("\n\n\n\t4->ͳ�Ƶ����ܳɼ�");
	printf("\n\n\n\t0->������һ���˵�");
	printf("\n\n\t******************************************************");
	printf("\n\n\t��ѡ��ѡ�");
}
void menu3()/*�˵�3*/
{
	system("cls");
	printf("\n\n\t**************** ��ӭ����ѧ���ɼ����Ҽ��޸�ϵͳ�� ****************");
	printf("\n\n\n\t1->����ѧ���ɼ�");
	printf("\n\n\n\t2->���������Ѵ����ѧ���ɼ�");
	printf("\n\n\n\t3->�����Ѵ���ĵ���ѧ���ɼ�");
	printf("\n\n\n\t0->������һ���˵�");
	printf("\n\n\t******************************************************");
	printf("\n\n\t��ѡ��ѡ�");
}
void dataLoad() /*�����ļ�*/
{
	int i=0;
	FILE *fp;
	fp=fopen("stu.txt","r");
	if(fp!=NULL)
		for(i=0;i<STU;i++)
		fread(&stu[i],sizeof(person),1,fp);
	else fp=fopen("stu.txt","wt+");
	fclose(fp);
}
void dataSave() /*�ļ�����*/
{
	int i;
	FILE *fp;
	fp=fopen("stu.txt","w");
	for(i=0;i<STU;i++)
	fwrite(&stu[i],sizeof(person),1,fp);
	fclose(fp);	
}
void stuave(struct person *p)/*����ѧ��ƽ���ɼ�ͳ�ƺ���*/
{
	system("cls");
	int i,j;
	for(i=0;i<STU;i++)
	{	stu[i].sc[VAL]=0;
		for(j=0;j<VAL;j++)
		{
			stu[i].sc[VAL]+=stu[i].sc[j];
		}
		stu[i].sc[VAL+1]=stu[i].sc[VAL]/VAL;
	}
	printf("\tͳ�ƽ�����£�\n");
	for(i=0;i<STU;i++)
		printf("\t\t%sƽ���ɼ���%.2f\n",stu[i].name,stu[i].sc[VAL+1]);
}
void stuadd(struct person *p)/*����ѧ���ܳɼ�ͳ�ƺ���*/
{
	system("cls");
	int i,j;
	for(i=0;i<STU;i++)
	{
		stu[i].sc[VAL]=0;
		for(j=0;j<VAL;j++)
		{
			
			stu[i].sc[VAL]+=stu[i].sc[j];
		}
	}
	printf("\tͳ�ƽ�����£�\n");
	for(i=0;i<STU;i++)
		printf("\t\t%s�ܳɼ���%.2f\n",stu[i].name,stu[i].sc[VAL]);
}
void valave(struct person *p)/*����ƽ���ɼ�ͳ�ƺ���*/
{ 
	system("cls");
	int i,j;
	for(i=0;i<VAL;i++)
	{
		stu[STU].sc[i]=0;
		for(j=0;j<STU;j++)
		{
			stu[STU].sc[i]+=stu[j].sc[i];
		}
		stu[STU+1].sc[i]=stu[STU].sc[i]/STU;
	}
	printf("\tͳ�ƽ�����£�\n");
	for(i=0;i<VAL;i++)
		printf("\t\tѧ��%dƽ���ɼ���%.2f\n",i+1,stu[STU+1].sc[i]);
}
void valadd(struct person *p)/*�����ܳɼ�ͳ�ƺ���*/
{
	system("cls");
	int i,j;
	for(i=0;i<VAL;i++)
	{
		stu[STU].sc[i]=0;
		for(j=0;j<STU;j++)
		{
			stu[STU].sc[i]+=stu[j].sc[i];
		}
	}
	printf("\tͳ�ƽ�����£�\n");
	for(i=0;i<VAL;i++)
		printf("\t\tѧ��%d�ܳɼ���%.2f\n",i+1,stu[STU].sc[i]);
}
void find(char *p)/*���ҳɼ�����*/
{
	int i,j;
	for(i=0;i<=STU;i++)
	{
		if(i==STU)
			printf("\n\tѧ��������������,�򲻴��ڴ�ѧ��!\n");
		if(strcmp(stu[i].name,p)==0)
		{
			for(j=0;j<VAL;j++)
				printf("\tѧ��%d:%.2f\n",(j+1),stu[i].sc[j]);
			break;
		}
	}
}
void again(struct person *p)/*��������ɼ�����*/
{
	system("cls");
	int i,j;
	printf("�����ѧ�����������Ƴɼ���\n");
	for(i=0;i<STU;i++)
	{
		printf("��%d��ѧ������:",i+1);
		scanf("%s",stu[i].name);
		for(j=0;j<VAL;j++)
		{
			printf("��%d�Ƴɼ�:",j+1);
			scanf("%f",&stu[i].sc[j]);
		}
	}
	dataSave();
}
void change(char *p)/*���ĳɼ�����*/
{
	system("cls");
	int i,j;
	for(i=0;i<=STU;i++)
	{
		if(i==STU)
				printf("\n\tѧ��������������!\n");
		if(strcmp(stu[i].name,p)==0)
		{
			printf("\t�޸���Ϣ:\n");
			printf("����:");scanf("%s",stu[i].name);
			for(j=0;j<VAL;j++)
			{
				printf("ѧ��%d:",j+1);scanf("%f",&stu[i].sc[j]);
			}
		}
	}
}
int statistics()
{
	char c;
	struct person *p=stu;
	dataLoad();
	while(1)
	{
		menu2();
		c=getch();
		printf("%c\n",c);
		switch(c)
		{
			case '1':{p=stu;stuave(p);printf("�밴��������ز˵���");break;}
		    case '2':{p=stu;stuadd(p);printf("�밴��������ز˵���");break;}
	      	case '3':{p=stu;valave(p);printf("�밴��������ز˵���");break;}
	    	case '4':{p=stu;valadd(p);printf("�밴��������ز˵���");break;}
			case '0':{printf("\n\t������һ���˵�\n\n\t");return(0);}
		    default:{printf("\n\t������������!");printf("\n\t�밴��������ز˵���");}
		}
		getch();
	}
}
int fag()
{
	char c;
	char s[20];
	struct person *p=stu;
	dataLoad();
	while(1)
	{
		menu3();
		c=getch();
		printf("%c\n",c);
		switch(c)
		{
		case '1':{
			        printf("\t��������Ҫ���ҵ�ѧ������:");
			     	scanf("%s",s);
		    		find(s);
			   	    printf("�밴��������ز˵���");
			    	break;
				 }
		case '2':{p=stu;again(p);printf("�밴��������ز˵���");break;}
		case '3':
			{
				printf("\t��������Ҫ���ĳɼ���ѧ������:");
				scanf("%s",s);
				change(s);
				printf("\n�밴��������ز˵���");
				break;
			}
		case '0':{printf("\n\t������һ���˵���\n\n\t");return(0);}
		default:{printf("\n\t������������!");printf("\n�밴��������ز˵���");}
		}
		getch();
	}
}