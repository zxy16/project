#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"classlib.h"
#include"stulib.h"
void main()                                  //主函数
{
	int aa,dddd=1,a=1,b=1;	
	printf("1.学生信息管理系统\n2.可选课程管理系统\n");
	scanf("%d",&aa);
	switch(aa)
	{
		case 1:		
		printf("〓〓〓〓〓〓〓〓〓〓  ☆   学 生 信 息 管 理 系  统     ☆  〓〓〓〓〓〓〓〓〓〓\n");
		printf("〓〓〓〓〓〓〓〓〓★  ☆          1.增加学生信息        ☆  ★〓〓〓〓〓〓〓〓〓\n");
		printf("〓〓〓〓〓〓〓〓〓★  ☆          2.显示全部信息        ☆  ★〓〓〓〓〓〓〓〓〓\n");
		printf("〓〓〓〓〓〓〓〓〓★  ☆          3.查找学生信息        ☆  ★〓〓〓〓〓〓〓〓〓\n");
		printf("〓〓〓〓〓〓〓〓〓★  ☆          4.删除学生信息        ☆  ★〓〓〓〓〓〓〓〓〓\n");
		printf("〓〓〓〓〓〓〓〓〓★  ☆          5.修改学生信息        ☆  ★〓〓〓〓〓〓〓〓〓\n");
		printf("〓〓〓〓〓〓〓〓〓★  ☆          6.更新数据        ☆  ★〓〓〓〓〓〓〓〓〓\n");	
		printf("请选择：");
		scanf("%d",&a);
		if(a>=0&&a<=6)
		{
			switch(a)
			{
				case 1:
				add();
				break;
				case 2:
				print();
				break;
				case 3:
				find();
				break;
				case 4:
				Delete();
				break;
				case 5:
				amend();
				break;
				case 6:
				update();
				break;
				default :
				break;
			}
		}
		else
		{
			printf(" 您输入的不符合要求，将返回主菜单!\n");
		}
		printf("此次选择完成\n");
		break;
		case 2:
	printf("〓〓〓〓〓〓〓〓〓〓  ☆   可选课程管理系统     ☆  〓〓〓〓〓〓〓〓〓〓\n");
	printf("〓〓〓〓〓〓〓〓〓★  ☆          1.新增课程        ☆  ★〓〓〓〓〓〓〓〓〓\n");
	printf("〓〓〓〓〓〓〓〓〓★  ☆          2.显示全部信息        ☆  ★〓〓〓〓〓〓〓〓〓\n");
	printf("〓〓〓〓〓〓〓〓〓★  ☆          3.查看某课程详细信息        ☆  ★〓〓〓〓〓〓〓〓〓\n");
	printf("〓〓〓〓〓〓〓〓〓★  ☆          4.删除课程        ☆  ★〓〓〓〓〓〓〓〓〓\n");
	printf("〓〓〓〓〓〓〓〓〓★  ☆          5.修改某课程的信息        ☆  ★〓〓〓〓〓〓〓〓〓\n");

	printf("〓〓〓〓〓〓〓〓〓★  ☆          6.更新数据        ☆  ★〓〓〓〓〓〓〓〓〓\n");
	printf("请选择：");
	scanf("%d",&b);
	if(b>=1&&b<=6)
	{
		switch(b)
		{
			case 1:
			classadd();
			break;
			case 2:
			classprint();
			break;
			case 3:
			classfind();
			break;
			case 4:
			classDelete();
			break;
			case 5:
			classamend();
			break;
			case 6:
			classupdate();
			break;
		}
	}
	else
	{
		printf(" 您输入的不符合要求，将返回主菜单!\n");
	}
	printf("此次选择完成\n");
	break;
	default:
	printf("此次未选择\n");
	break;
	}
}
