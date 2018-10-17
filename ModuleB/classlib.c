#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"classlib.h"
int nn=0;
int n=0;
void log11(char*c)
{
	FILE *fp;
	if((fp=fopen("/home/zxy16/review/MyProject/log.txt","a+"))==NULL)
	{printf("Can not open file!");exit(0);}
	fprintf(fp,"%s ",c);
	fclose(fp);
	system("date>>/home/zxy16/review/MyProject/log.txt");
}
void classupdate()
{
	classread();	
	pp=head1->next;
	while(pp!=NULL)
	{
	read1();
	int k=0,j=0;
	if(n!=0)
	{
	p=head->next;
	while(p!=NULL)
	{
	int i=0;
	for(;i<p->aaa;i++)
	if(!strcmp(p->list[i],pp->classname))
	{
	strcpy(pp->namelist[j],p->name);
	k++;
	j++;
	}
	p=p->next;
	}
	if(k==0)
	strcpy(pp->namelist[0],"暂时无学生选课");
	}
	else
	strcpy(pp->namelist[0],"暂时无学生选课");
	pp->people=k;
	pp=pp->next;
	}
	classsave();	
}
void read1()
{
	FILE *fp2;
	if((fp2=fopen("/home/zxy16/review/MyProject/ModuleA/student.txt","rb+"))==NULL)
	{printf("Can not open file!");exit(0);}
	do
	{
		p1=malloc(Length);
		if(n==0)                                     //判断链表开头
			head=p1;                                 //n=0代表输入的是第一个数据     //p2的结尾所指向的地址是p1
			else
				p2->next=p1;
				fread(p1,Length,1,fp2);
				p2=p1;
				n+=1;
	}while(p2->next!=NULL);
	fclose(fp2);
	printf("读取完成!\n");
}

void classadd()
{
	classread();	
	char bb[40]="add class ";
	pp1=(struct class1 *)malloc(length);
	if(nn==0)                                     //判断>    链表开头
		head1=pp1;   //n=0代表输入的是第一个数据     //p2的结尾所指向的地址是p1
		else pp2->next=pp1;//n!=0 就它们连接起来
		printf("请输入课程的基本信息：\n课程编号：");
		scanf("%s",pp1->classnum);
		printf("课程名称:\n");
		scanf("%s",pp1->classname);
		printf("课程属性:\n");
		scanf("%s",pp1->attribute);
		printf("授课学时:\n");
		scanf("%d",&pp1->hour);
		printf("学分:\n");
		scanf("%d",&pp1->score);
		printf("人数上限:\n");
		scanf("%d",&pp1->limit);
		pp2=pp1;                                           //p2指向p1所在的地址
		pp2->next=NULL; //链表结束标志
		nn+=1;                                           //n判断是不是第一个数据
		strcat(bb,pp1->classnum);
		log11(bb);
		classsave();
}

void classamend()
{
	classread();	
	char bb[40]="amend class ";
	if(nn!=0)
	{
		int c;
		char a[20];
		printf("请输入要修改的课程：");
		scanf("%s",a);
		pp=head1->next;
		while(pp!=NULL)
		{
			if(strcmp(a,pp->classname)==0)
			{
				strcat(bb,pp->classname);
				printf("\n被修改的课程信息如下：\n课程编号\t课程名称\t课程属性\t授课学时\n学分\t课程已选人数\t课程人数上限\n");
				printf("%-8s\t%-8s\t\t%8s\t%8d\n%d\t%8d\t%8d\n",pp->classnum,pp->classname,pp->attribute,pp->hour,pp->score,pp->people,pp->limit);
				printf("所选学生列表\n");
				int i;
				if(pp->people!=0)
				{
					for(i=0;i<pp->people;i++)
					{
						printf("%s\n",pp->namelist[i]);
					}
				}
				else printf("%s\n",pp->namelist[0]);
				break;
			}
			pp=pp->next;
		}
		printf("\n1.修改课程属性\n2.修改授课学时\n3.修改学分\n4.修改课程人数上限\n5.退出修改\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			printf("课程属性修改为：");
			scanf("%s",pp->attribute);break;
			case 2:
			printf("授课学时修改为：");
			scanf("%d",&pp->hour);break;
			case 3:
			printf("学分修改为:");
			scanf("%d",&pp->score);break;
			case 4:
			printf("课程人数上限修改为：");
			scanf("%d",&pp->limit);break;
			default:
				break;
		}
	}
	else
		printf("******您还没有添加数据哟!\n");
		log11(bb);
		classsave();
}

void classprint()
{
	classread();	
	if(nn!=0)
	{
		pp=head1->next;               //p先指向开头
		printf("课程编号\t课程名称\t课程属性\t授课学时\n学分\t课程已选人数\t课程人数上限\n");	
		while(pp!=NULL)
		{
			printf("%-8s\t%-8s\t\t%8s\t%8d\n%d\t%8d\t%8d\n",pp->classnum,pp->classname,pp->attribute,pp->hour,pp->score,pp->people,pp->limit);
			printf("所选学生列表\n");
			int i;
			if(pp->people!=0)
			{
			for(i=0;i<pp->people;i++)
			{
				printf("%s\n",pp->namelist[i]);
			}
				printf("\n");
			}
			else printf("%s\n",pp->namelist[0]);
			pp=pp->next;
		}//只要p指向的内存区域有数据 就打印内容
	}
	else
		printf("******您还没有添加数据哟!\n");
}

void classsave()
{
	FILE *fp;
	struct class1*pp;
	if((fp=fopen("/home/zxy16/review/MyProject/ModuleB/class.txt","wb"))==NULL)
		printf("******您还没有添加数据哟!\n");
		pp=head1;
		while(pp!=NULL)
		{
			if(fwrite(pp,length,1,fp)!=1)
			{
				printf("写入数据出错\n");
				fclose(fp);
				break;
			}
			pp=pp->next;
		}
		fclose(fp);
		printf("存储完成\n");
}

void classread()
{
	FILE *fp3;
	if((fp3=fopen("/home/zxy16/review/MyProject/ModuleB/class.txt","rb+"))==NULL)
	{printf("Can not open file!");exit(0);}
	do
	{
		pp1=malloc(length);
		if(nn==0)                 //判断链表开头
			head1=pp1;           //n=0代表输入的是第一个数据     //p2的结尾所指向的地址是p1
			else
				pp2->next=pp1;
				fread(pp1,length,1,fp3);
				pp2=pp1;
				nn+=1;
	}while(pp2->next!=NULL);
	fclose(fp3);
	printf("读取完成!\n");
}

void classDelete()
{
	classread();	
	char bb[40]="delete class ";
	if(nn!=0)
	{
		struct class1 *f,*l;                              //定义新的指针 f使用来指向要删除的数据用来释放内存!
		char a[20];
		printf("删除完，需去学生管理系统更新数据\n请输入要删除的课程名：");
		scanf("%s",a);
		pp=head1;
		if(strcmp(head1->classname,a)==0)
		{
			strcat(bb,head1->classname);
			f=head1;head1=head1->next;free(f);
		}
		else
		{
			do
			{
				if(strcmp(pp->classname,a)==0)
				{
					strcat(bb,pp->classname);
					f=pp;l->next=pp->next;free(f);break;
				}
				l=pp;                                          //不满足if表示这不是要删除的那一个节点，l暂时指向p  之后p再指向下一个节点，如果这个是要删除的节点那么l指向这个节点的next的地址
				pp=pp->next;
			}while(pp!=NULL);
		}
	}
	else
		printf("******您还没有添加数据哟!\n");
		printf("数据已经被删除\n");
		log11(bb);
		classsave();
}

void classfind()           //查找
{
	classread();	
	if(nn!=0)
	{
		int a;
		printf("1.按课程名称查找\n2.按课程编号查询\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1:
			classfind1();
			break;
			case 2:
			classfind2();
			break;
		}
	}
	else
	{
		printf("******您还没有添加数据哟!\n");
		system("pause");
	}
}
void classfind1()
{
	char a[20];
	printf("请输入要查找的课程名称：");
	char bb[40]="find class ";
	scanf("%s",a);
	pp=head1;
	do
	{
		if(!strcmp(a,pp->classname))
		{
			strcat(bb,pp->classnum);
			printf("课程编号\t课程名称\t课程属性\t授课学时\n学分\t课程已选人数\t课程人数上限\n");
			printf("%-8s\t%-8s\t\t%8s\t%8d\n%d\t%8d\t%8d\n",pp->classnum,pp->classname,pp->attribute,pp->hour,pp->score,pp->people,pp->limit);
			printf("所选学生列表\n");
			int i;
			if(pp->people!=0)
			{
				for(i=0;i<pp->people;i++)
				{
					printf("%s\n",pp->namelist[i]);
				}
			}
			else printf("%s\n",pp->namelist[0]);
		}
		pp=pp->next;                            ////指针指向下一个节点
	}while(pp!=NULL);
	log11(bb);
}

void classfind2()
{
	char a[20];
	char bb[40]="find class ";
	printf("请输入要查找的学号：");
	scanf("%s",a);
	pp=head1;
	do
	{
		//指针指向开头
		if(!strcmp(a,pp->classnum))
		{
			strcat(bb,pp->classnum);
			printf("课程编号\t课程名称\t课程属性\t授课学时\n学分\t课程已选人数\t课程人数上限\n");
			printf("%-8s\t%-8s\t\t%8s\t%8d\n%d\t%8d\t%8d\n",pp->classnum,pp->classname,pp->attribute,pp->hour,pp->score,pp->people,pp->limit);
			printf("所选学生列表\n");
			int i;
			if(pp->people!=0)
			{
				for(i=0;i<pp->people;i++)
				{
					printf("%s\n",pp->namelist[i]);
				}
			}
			else printf("%s\n",pp->namelist[0]);
		}
		pp=pp->next;                            //指针指向下一个节点
	}while(pp!=NULL);
	log11(bb);
}
