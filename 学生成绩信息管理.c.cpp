#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define STU 3
#define VAL 4/*方便更改学生人数及统计科目数*/
struct person
{
	char name[20];
	float sc[VAL+2];
}stu[STU+2];/*定义结构体*/
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
		case '1':{statistics();printf("\n请按任意键返回菜单!");break;}
		case '2':{fag();printf("\n请按任意键返回菜单!");break;}
		case '0':{printf("\n\t您选择了退出平台，谢谢使用，再见!\n\n\t");dataSave();return(0);}
		default:{printf("\n\t您的输入有误!");printf("\n请按任意键返回菜单！");}
		}
		getch();
	}
}
void menu1()/*菜单1*/
{
	system("cls");
	printf("\n\n\t**************** 欢迎进入学生成绩信息管理平台！ ****************");
	printf("\n\n\n\t1->学生成绩统计系统");
	printf("\n\n\n\t2->学生成绩查找及修改系统");
	printf("\n\n\n\t0->退出平台");
	printf("\n\n\t******************************************************");
	printf("\n\n\t请选择选项：");
}
void menu2()/*菜单2*/
{
	system("cls");
	printf("\n\n\t**************** 欢迎进入学生成绩统计系统！ ****************");
	printf("\n\n\n\t1->统计单个学生平均成绩");
	printf("\n\n\n\t2->统计单个学生总成绩");
	printf("\n\n\n\t3->统计单科平均成绩");
	printf("\n\n\n\t4->统计单科总成绩");
	printf("\n\n\n\t0->返回上一级菜单");
	printf("\n\n\t******************************************************");
	printf("\n\n\t请选择选项：");
}
void menu3()/*菜单3*/
{
	system("cls");
	printf("\n\n\t**************** 欢迎进入学生成绩查找及修改系统！ ****************");
	printf("\n\n\n\t1->查找学生成绩");
	printf("\n\n\n\t2->重新输入已存入的学生成绩");
	printf("\n\n\n\t3->更改已存入的单个学生成绩");
	printf("\n\n\n\t0->返回上一级菜单");
	printf("\n\n\t******************************************************");
	printf("\n\n\t请选择选项：");
}
void dataLoad() /*读入文件*/
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
void dataSave() /*文件保存*/
{
	int i;
	FILE *fp;
	fp=fopen("stu.txt","w");
	for(i=0;i<STU;i++)
	fwrite(&stu[i],sizeof(person),1,fp);
	fclose(fp);	
}
void stuave(struct person *p)/*单个学生平均成绩统计函数*/
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
	printf("\t统计结果如下：\n");
	for(i=0;i<STU;i++)
		printf("\t\t%s平均成绩：%.2f\n",stu[i].name,stu[i].sc[VAL+1]);
}
void stuadd(struct person *p)/*单个学生总成绩统计函数*/
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
	printf("\t统计结果如下：\n");
	for(i=0;i<STU;i++)
		printf("\t\t%s总成绩：%.2f\n",stu[i].name,stu[i].sc[VAL]);
}
void valave(struct person *p)/*单科平均成绩统计函数*/
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
	printf("\t统计结果如下：\n");
	for(i=0;i<VAL;i++)
		printf("\t\t学科%d平均成绩：%.2f\n",i+1,stu[STU+1].sc[i]);
}
void valadd(struct person *p)/*单科总成绩统计函数*/
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
	printf("\t统计结果如下：\n");
	for(i=0;i<VAL;i++)
		printf("\t\t学科%d总成绩：%.2f\n",i+1,stu[STU].sc[i]);
}
void find(char *p)/*查找成绩函数*/
{
	int i,j;
	for(i=0;i<=STU;i++)
	{
		if(i==STU)
			printf("\n\t学生姓名输入有误,或不存在此学生!\n");
		if(strcmp(stu[i].name,p)==0)
		{
			for(j=0;j<VAL;j++)
				printf("\t学科%d:%.2f\n",(j+1),stu[i].sc[j]);
			break;
		}
	}
}
void again(struct person *p)/*重新输入成绩函数*/
{
	system("cls");
	int i,j;
	printf("请键入学生姓名及各科成绩：\n");
	for(i=0;i<STU;i++)
	{
		printf("第%d名学生姓名:",i+1);
		scanf("%s",stu[i].name);
		for(j=0;j<VAL;j++)
		{
			printf("第%d科成绩:",j+1);
			scanf("%f",&stu[i].sc[j]);
		}
	}
	dataSave();
}
void change(char *p)/*更改成绩函数*/
{
	system("cls");
	int i,j;
	for(i=0;i<=STU;i++)
	{
		if(i==STU)
				printf("\n\t学生姓名输入有误!\n");
		if(strcmp(stu[i].name,p)==0)
		{
			printf("\t修改信息:\n");
			printf("姓名:");scanf("%s",stu[i].name);
			for(j=0;j<VAL;j++)
			{
				printf("学科%d:",j+1);scanf("%f",&stu[i].sc[j]);
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
			case '1':{p=stu;stuave(p);printf("请按任意键返回菜单！");break;}
		    case '2':{p=stu;stuadd(p);printf("请按任意键返回菜单！");break;}
	      	case '3':{p=stu;valave(p);printf("请按任意键返回菜单！");break;}
	    	case '4':{p=stu;valadd(p);printf("请按任意键返回菜单！");break;}
			case '0':{printf("\n\t返回上一级菜单\n\n\t");return(0);}
		    default:{printf("\n\t您的输入有误!");printf("\n\t请按任意键返回菜单！");}
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
			        printf("\t请输入需要查找的学生姓名:");
			     	scanf("%s",s);
		    		find(s);
			   	    printf("请按任意键返回菜单！");
			    	break;
				 }
		case '2':{p=stu;again(p);printf("请按任意键返回菜单！");break;}
		case '3':
			{
				printf("\t请输入需要更改成绩的学生姓名:");
				scanf("%s",s);
				change(s);
				printf("\n请按任意键返回菜单！");
				break;
			}
		case '0':{printf("\n\t返回上一级菜单！\n\n\t");return(0);}
		default:{printf("\n\t您的输入有误!");printf("\n请按任意键返回菜单！");}
		}
		getch();
	}
}