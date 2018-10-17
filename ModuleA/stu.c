#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stulib.h"
void main()                                  //主函数
{
	int a=1;
	printf("〓〓〓〓〓〓〓〓〓〓  ☆   学 生 信 息 管 理 系  统     ☆  〓〓〓〓〓〓〓〓〓〓\n");
	printf("〓〓〓〓〓〓〓〓〓★  ☆          1.增加学生信息        ☆  ★〓〓〓〓〓〓〓〓〓\n");
	printf("〓〓〓〓〓〓〓〓〓★  ☆          2.显示全部信息        ☆  ★〓〓〓〓〓〓〓〓〓\n");
	printf("〓〓〓〓〓〓〓〓〓★  ☆          3.查找学生信息        ☆  ★〓〓〓〓〓〓〓〓〓\n");
	printf("〓〓〓〓〓〓〓〓〓★  ☆          4.删除学生信息        ☆  ★〓〓〓〓〓〓〓〓〓\n");
	printf("〓〓〓〓〓〓〓〓〓★  ☆          5.修改学生信息        ☆  ★〓〓〓〓〓〓〓〓〓\n");
	printf("请选择：");
	scanf("%d",&a);
	if(a>=0&&a<=9)
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
		}
	}
	else
	{
		printf(" 您输入的不符合要求，将返回主菜单!\n");
	}
}
