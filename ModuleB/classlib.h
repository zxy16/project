#ifndef _CLASSLIB_H_
#define _CLASSLIB_H_
#define Length sizeof(struct student)
#define length sizeof(struct class1)
struct class1
{
	char classnum[20];	//课程编号
	char classname[20];	//课程名称
	char attribute[20];	//课程属性
	int hour;	//授课学时
	int score;	//学分
	int people;	//选课人数
	int limit;	//人数上限
	char namelist[200][20];
	struct class1 *next;
}*head1,*pp,*pp1,*pp2;
struct student
{
	char name[20];           //名字
	char num[20];            //学号
	char list[20][20];       //已选课列表
	int aaa;	//已选课程数
	int totalscore;               //总计学分
	struct student *next;
}*head,*p,*p1,*p2; //head表示开头  p表示不同位置的数据
void log11(char *c);
void classupdate();
void classadd();               
void classprint();
void classfind();
void classDelete();
void classamend();
void classsave();
void classread();
void read1();
void classfind1();
void classfind2();
#endif
