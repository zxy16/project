#ifndef _STULIB_H_
#define _STULIB_H_
#define Lengtha sizeof(struct studenta)        //用来开辟空间
#define lengtha sizeof(struct class1a)
struct class1a
{
	char classnum[20];	//课程编号
	char classname[20];	//课程名称
	char attribute[20];	//课程属性
	int hour;	//授课学时
	int score;	//学分
	int people;	//选课人数
	int limit;	//人数上限
	char namelist[200][20];
	struct class1a *next;
}*head1a,*ppa,*pp1a,*pp2a;

struct studenta
{
	char name[20];           //名字
	char num[20];            //学号
	char list[20][20];       //已选课列表
	int aaa;	//已选课程数
	int totalscore;               //总计学分
	struct studenta *next;
}*heada,*pa,*p1a,*p2a;       //head表示开头  p表示不同位置的数据
void log1(char*c);
void update();
void read2();
void add();               
void print();
void find();
void Delete();
void amend();
void save();
void read();
void find1();
void find2();
#endif
