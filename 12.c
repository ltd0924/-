#include<string.h>
#include<stdio.h>
#include<malloc.h>

void finddata();
struct node
{
    char name[20];
    int num;
    char sex;
    int age;
    float score[10];
    struct node*next;
};
    struct node*head,*tail;
void initht()
{
    head=NULL;
    tail=NULL;
};
void put(struct node*p)
{
    p->next=NULL;
    if(head==NULL)
        {head=p;}
    else
        {tail->next=p;}
    tail=p;
}
void inputdata()
{
    int i;
    char ch;
	struct node*p;
	while(1)
    {
        printf("Input data(Y/N):\n");
        if(ch=='y'||ch=='Y')
        {
            p=(struct node*)malloc(sizeof(struct node));
            printf("Input name:");
            scanf("%s",p->name);
            printf("Input number:");
            scanf("%d",&p->num);
            printf("Input sex:");
            scanf("%c",&p->sex);
            printf("Input age:");
            scanf("%d",&p->age);
            printf("Input 10 scores:\n");
            for(i=0;i<10;i++)
            {
                scanf("%d",&p->score[i]);
            }
            put(p);
        }
        else break;

    }

}
void Fdname()
{
    int i;
    char name[20];
    struct node*p;
    printf("Input name:");
    scanf("%s",name);
    p=head;
    while(p!=NULL)
    {
        if(strcmp(name,p->name)==0)
        {
            printf("Name:%s",p->name);
            printf("Number:%d",p->num);
            printf("Sex:%c",p->sex);
            printf("Age:%d",p->age);
            for(i=0;i<10;i++)
            {
                printf("Score[%d]:%f\n",i+1,p->score[i]);
            }
        }
        p=p->next;
    }

}
void Fdnum()
{
    int i;
    int snum;
    struct node*p;
    printf("Input number:");
    scanf("%d",snum);
    p=head;
    while(p!=NULL)
    {
        if(snum==p->num)
        {
            printf("Name:%s",p->name);
            printf("Number:%d",p->num);
            printf("Sex:%c",p->sex);
            printf("Age:%d",p->age);
            for(i=0;i<10;i++)
            {
                printf("Score[%d]:%f\n",i+1,p->score[i]);
            }
        }
        p=p->next;
    }

}
void finddata()
{
    char ch;
    while(1)
    {
        printf("1:Find by name\n");
        printf("2:Find by number\n");
        printf("3:Exit\n");
        ch=getchar();
    switch(ch)
    {
    case'1':
        Fdname();
        break;
    case'2':
        Fdnum();
        break;
    case'3':
        return;

    }

}
}
void main()
{
    initht();
    inputdata();
    finddata();
}
