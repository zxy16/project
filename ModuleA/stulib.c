#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stulib.h"
int n=0;
int nn=0;
void log1(char *c)
{
	FILE *fp;
	if((fp=fopen("/home/zxy16/review/MyProject/log.txt","a"))==NULL)
	{printf("Can not open file!");exit(0);}
	fprintf(fp,"%s ",c);
	fclose(fp);
	system("date>>/home/zxy16/review/MyProject/log.txt");
}

void update()
{
	read();
	int i;
	pa=heada->next;
	read2();
	if(nn!=0)
		ppa=head1a->next;
		else printf("课程还未上传\n");
		int a=0;
		while(pa!=NULL)
		{
			a=0;
			if(nn!=0)
				ppa=head1a;
				else printf("课程还未上传\n");
				int ccc=pa->aaa;
				for(i=0;i<pa->aaa;i++)
				{
					while(ppa!=NULL)
					{
						if(!strcmp(pa->list[i],ppa->classname))
						{
							a+=ppa->score;
							strcpy(pa->list[i],ppa->classname);
							break;
						}
						ppa=ppa->next;
						if(ppa==NULL)ccc--;
					}
				}
				pa->aaa=ccc;
				pa->totalscore=a;
				pa=pa->next;
		}
		save();
}

void read2()
{
	FILE *fp;
	if((fp=fopen("/home/zxy16/review/MyProject/ModuleB/class.txt","rb+"))==NULL)
	{printf("Can not open file!");exit(0);}
	do
	{
		pp1a=malloc(lengtha);
		if(nn==0)                                     //判断链表开头
			head1a=pp1a;                                 //n=0代表输入的是第一个数据     //p2的结尾所指向的地址是p1
			else
				pp2a->next=pp1a;
				fread(pp1a,lengtha,1,fp);
				pp2a=pp1a;
				nn+=1;
	}while(pp2a->next!=NULL);
	fclose(fp);
}

void add()                    //添加
{
	read();
	p1a=(struct studenta *)malloc(Lengtha);         //开辟存储空间
	if(n==0)                                     //判断链表开头
		heada=p1a;                                 //n=0代表输入的是第一个数据     //p2的结尾所指向的地址是p1
		else p2a->next=p1a;
		printf("请输入学生基本信息：\n姓名：");
		scanf("%s",p1a->name);
		printf("学号：");
		scanf("%s",p1a->num);
		read2();
		printf("已有课程：\n");
		if(nn!=0)
		{
			ppa=head1a->next;
		}
		else printf("课程还未上传\n");
		while(ppa!=NULL)
		{
			printf2("%s ",ppa->classname);
			ppa=ppa->next;
		}
		printf("\n");
		printf("选课数：");
		int i=0,k=0,h=0;
		scanf("%d",&p1a->aaa);
		printf("选课列表：");
		for(i=0;i<p1a->aaa;i++)
		{
			while(k!=1||h!=1)
			{
				ppa=head1a;
				char b[20];
				scanf("%s",b);
				while(ppa!=NULL)
				{
					if(!strcmp(b,ppa->classname))
					{
						k+=1;
						if(ppa->people<=ppa->limit)
						{
							h+=1;
							strcpy(p1a->list[i],b);
						}
					}
					ppa=ppa->next;
				}
				if(k!=1)
					printf("该课程没有开设，请重新选择一门课\n");
					if(k==1&&h!=1)
						printf("该课程人数已满，请重新选择一门课\n");
			}
			h=0;k=0;
		}
		char bb[40]="add student ";
		strcat(bb,p1a->num);
		log1(bb);
		p2a=p1a;                                       //p2指向p1所在的地址
		p2a->next=NULL; //链表结束标志
		n+=1;                                       //n判断是不是第一个数据
		save();
}

void print()
{
	read();
	if(n!=0)
	{
		pa=heada->next;                                   //p先指向开头
		while(pa!=NULL)
		{
			printf("姓名\t学号\t已选课程列表\n");
			printf("%-8s%-8s",pa->name,pa->num);
			int i;
			for(i=0;i<pa->aaa;i++)
				printf("%s ",pa->list[i]);
				printf("\n");
				printf("已选课总计学分\n");
				printf("%d\n",pa->totalscore);
				pa=pa->next;                            //p打印结束 把p指向next以判断下一个区域有没有内容
		}//只要p指向的内存区域有数据 就打印内容
	}
	else
		printf("******您还没有添加数据哟!\n");
}
void find()           //查找
{
	read();
	void find1();
	void find2();
	if(n!=0)
	{
		int a;
		printf("1.按姓名查找\n2.按学号查询\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1:
			find1();
			break;
			case 2:
			find2();
			break;
		}
	}
	else
	{printf("******您还没有添加数据哟!\n");system("pause");}
}

void Delete()
{
	read();
	if(n!=0)
	{
		struct studenta *f,*l;                              //定义新的指针 f使用来指向要删除的数据用来释放内存!
		char a[20];
		char bb[40]="delete student ";
		printf("删除完后，需更新选课管理系统\n请输入要删除的姓名：");
		scanf("%s",a);
		pa=heada;
		if(strcmp(heada->name,a)==0)
		{
			strcat(bb,heada->num);
			log1(bb);
			f=heada;heada=heada->next;free(f);
		}
		else
		{
			do
			{
				if(strcmp(pa->name,a)==0)
				{
					strcat(bb,pa->num);
					log1(bb);
					f=pa;
					l->next=pa->next;
					free(f);
					break;
				}
				l=pa;                                          //不满足if表示这不是要删除的那一个节点，l暂时指向p  之后p再指向下一个节点，如果这个是要删除的节点那么l指向这个节点的next的地址
				pa=pa->next;
			}while(pa!=NULL);
		}
	}
	else
		printf("******您还没有添加数据哟!\n");
		printf("数据已经被删除\n");
		save();
}

void amend()
{
	read();
	if(n!=0)
	{
		int c;
		char a[20];
		char bb[40]="amend student ";
		printf("请输入要修改的姓名：");
		scanf("%s",a);
		pa=heada;
		do
		{
			if(strcmp(a,pa->name)==0)
			{
				printf("\n被修改人信息如下：\n姓名\t学号\t已选课程列表\t\t学分\n");
				printf("%-8s%-s",pa->name,pa->num);
				int i;
				for(i=0;i<pa->aaa;i++)
					printf("%s ",pa->list[i]);
					printf("\n");
					break;
			}
			pa=pa->next;                            ////指针指向下一个节点
		}while(pa!=NULL);
		printf("\n\n1.修改姓名\n2.修改学号\n3.修改选课列表(修改之后，需更新学生管理系统与选课管理系统)\n4.退出修改\n\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
			printf("姓名修改为：");
			scanf("%s",pa->name);break;
			case 2:
			printf("学号修改为：");
			scanf("%s",pa->num);break;
			case 3:
			read2();
			printf("已有课程：\n");
			if(nn!=0)
			{
				ppa=head1a;
			}
			else printf("课程还未上传\n");
			while(ppa!=NULL)
			{
				printf("%s ",ppa->classname);
				ppa=ppa->next;
			}
			printf("\n");
			printf("选课数：");
			int i=0,k=0,h=0;
			scanf("%d",&p1a->aaa);
			printf("选课列表：");
			for(i=0;i<p1a->aaa;i++)
			{
				while(k!=1||h!=1)
				{
					ppa=head1a;
					char b[20];
					scanf("%s",b);
					while(ppa!=NULL)
					{
						if(!strcmp(b,ppa->classname))
						{
							k+=1;
							if(ppa->people<=ppa->limit)
							{
								h+=1;
								strcpy(p1a->list[i],b);
							}
						}
						ppa=ppa->next;
					}
					if(k!=1)
						printf("该课程没有开设，请重新选择一门课\n");
						if(k==1&&h!=1)
							printf("该课程人数已满，请重新选择一门课\n");
				}
				h=0;k=0;
			}
			case 4:
			break;
		}
		strcat(bb,pa->num);
		log1(bb);
		printf("\n\n操作成功!\n\n");
	}
	else
		printf("******您还没有添加数据哟!\n");
		save();
}

void save()
{
	FILE *fp;
	struct studenta *pa;
	if((fp=fopen("/home/zxy16/review/MyProject/ModuleA/student.txt","wb"))==NULL)
		printf("Can not open the file!");
		pa=heada;
		while(pa!=NULL)
		{
			if(fwrite(pa,Lengtha,1,fp)!=1)
			{
				printf("写入数据出错\n");
				fclose(fp);
				break;
			}
			pa=pa->next;
		}
		fclose(fp);
		printf("存储完成\n");
}

void read()
{
	FILE *fp1;
	if((fp1=fopen("/home/zxy16/review/MyProject/ModuleA/student.txt","rb+"))==NULL)
	{printf("Can not open file!");exit(0);}
	do
	{
		p1a=malloc(Lengtha);
		if(n==0)                                     //判断链表开头
			heada=p1a;                                 //n=0代表输入的是第一个数据     //p2的结尾所指向的地址是p1
			else
				p2a->next=p1a;
				fread(p1a,Lengtha,1,fp1);
				p2a=p1a;
				n+=1;
	}while(p2a->next!=NULL);
	fclose(fp1);
	printf("读取完成!\n");
}

void find1()
{
	char a[20];
	printf("请输入要查找的姓名：");
	char bb[40]="find student ";
	scanf("%s",a);
	pa=heada;
	do
	{
		if(strcmp(a,pa->name)==0)
		{
			strcat(bb,pa->num);
			log1(bb);
			printf("\n信息已被找到：\n姓名\t学号\t已选课程列表\n");
			printf("%-8s%-8s",pa->name,pa->num);
			int i;
			for(i=0;i<pa->aaa;i++)
				printf("%s ",pa->list[i]);
				printf("\n");
				printf("学分\n");
				printf("%d\n",pa->totalscore);
		}
		pa=pa->next;                            ////指针指向下一个节点
	}while(pa!=NULL);
}

void find2()
{
	char a[20];
	printf("请输入要查找的学号：");
	char bb[40]="find student ";
	scanf("%s",a);
	pa=heada;
	do
	{
		//指针指向开头
		if(strcmp(a,pa->num)==0)
		{
			strcat(bb,pa->num);
			log1(bb);
			printf("\n信息已被找到：\n姓名\t学号\t已选课程列表\t学分\n");
			printf("%-8s%-8s",pa->name,pa->num);
			int i;
			for(i=0;i<pa->aaa;i++)
				printf("%s ",pa->list[i]);
				printf("\n");
		}
		pa=pa->next;                            //指针指向下一个节点
	}while(pa!=NULL);
}
