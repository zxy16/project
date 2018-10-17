#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"classlib.h"
void main()                                  //主函数
{
	int a=1;
	printf("〓〓〓〓〓〓〓〓〓〓  ☆   可选课程管理系统     ☆  〓〓〓〓〓〓〓〓〓〓\n");
	printf("〓〓〓〓〓〓〓〓〓★  ☆          1.新增课程        ☆  ★〓〓〓〓〓〓〓〓〓\n");
	printf("〓〓〓〓〓〓〓〓〓★  ☆          2.显示全部信息        ☆  ★〓〓〓〓〓〓〓〓〓\n");
	printf("〓〓〓〓〓〓〓〓〓★  ☆          3.查看某课程详细信息        ☆  ★〓〓〓〓〓〓〓〓〓\n");
	printf("〓〓〓〓〓〓〓〓〓★  ☆          4.删除课程        ☆  ★〓〓〓〓〓〓〓〓〓\n");
	printf("〓〓〓〓〓〓〓〓〓★  ☆          5.修改某课程的信息或者更新数据        ☆  ★〓〓〓〓〓〓〓〓〓\n");
	printf("请选择：");
	scanf("%d",&a);
	if(a>=1&&a<=5)
	{
		switch(a)
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
			case 5:
			classamend();
			break;
		}
	}
	else
	{
		printf(" 您输入的不符合要求，将返回主菜单!\n");
	}
	printf("运行完，将自动退出系统\n");
}
