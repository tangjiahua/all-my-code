typedef struct student
{
	char num[10];
	char name[15];
	int cgrade;
	int mgrade;
	int egrade;
	int total;
	float ave;
	int mingci;
};
typedef struct node
{ 
	struct student data;
	struct node *next;
	
}Node,*Link;


void printheader();
void printdata(Node *pp);
void stringinput(char *t,int lens,char *notice);
int numberinput(char *notice);
void Disp(Link l);
ode* Locate(Link l,char findmess[],char nameornum[]);
void Add(Link l);
void Qur(Link l);
void Del(Link l);
void Modify(Link l);
void Insert(link l);
void Tongji(Link l);
void Sort(Link l);
void Save(Link l) ;







#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"conio.h"
#define HEADER1 "    ------------------------------STUDENT------------------------------------   \n" 
#define HEADER2 "  |  number  |  name  |  Comp  |  Math  |  Eng  |  Sum  |  Ave  |  Mici  | \n"
#define HEADER3 "    |------------|---------|---|---|---|---|-------------|---------------|   "
#define FORMAT  "  |   %-10s  | %-15s  |   %4d  |   %4d  |  %4d  |   %4d |  %.2f |  %4d   | \n  "
#define DATA p->data.num,p->data.name,p->data.egrade,p->data.cgrade,p->data.mgrade,p->data.total,p->data.ava,p->data.mingci
#define END    "       ----------------------------------------------------------------------  \n "
int saveflag=0;
/*定义与学生有关的数据结构*/
typedef struct student
{
	char num[10];
	char name[15];
	int cgrade;
	int mgrade;
	int egrade;
	int total;
	float ave;
	int mingci;
	
	
} ;
/*定义每条记录或节点的数据结构，标记为：node*/
typedef struct node
{
	struct student date;     /*数据域*/
	struct node *next;       /*指针域*/ 
}   Node,*Link;              /*Node 为node类型的结构变量，*link为node类型的指针变量*/ 

 void main()
{
	Link l;                 /*定义链表*/
	FILE *fp;               /*文件指针*/ 
	int select;             /*保存选择结果变量*/
	char ch;                /*保存（y,Y,n,N）*/
	int count=0;            /*保存文件中的记录条数*/
	Node *p,*r;             /*定义记录指针变量*/
	l=(Node*)malloc(sizeof(Node));
	if(!l)
	{
		printf("\n allocate memory failure");        /*如没有申请到，打印提示信息*/
		return ;                                     /*返回主界面*/
	}
	 l->next=NULL;
	 r=1;
	 /*以追加方式打开一个二进制文件，可读可写，若此t文件不存在，会创建此文件*/
	 fp=fopen("C:\\student","ab+");
	 if(fp==NULL)
	 {
	 	printf("\n======>cannot open file!\n");
	 	exit(0);
	 }	 
	 while(!feof(fp))
	 {
	 	p=(Node*)malloc(sizeof(Node));
	 	if(!p)
	 	{
	 		printf(" memory malloc failure!\n");        /*没有申请成功*/
	 		exit(0);                                    /*退出*/
	 		
	 	}
	 	if(fread (p,sizeof(Node),1,fp)==1)               /*一次从文件中读取一条学生记录*/
	 	{
		 p->next=NULL;
		 r->next=p;
		 r=p;                                            /*r指针向后移动一个位置*/
		 count++; 
		 } 
     }
     fclose(fp); /*关闭文件*/
     printf("\n=============>open file sucess, the total records number is : %d.\n", count) ;
     menu();
     while(l)
     {
     	system("cls");
     	menu();
     	p=r;
     	printf("\n      Please Enter your choice(0~9):");/*显示提示信息*/
     	scanf("%d",&select) ;
     	if(select==0)
     	{
     		/*若对链表的数据有修改且未进行存盘操作，则此标志为1*/
     		if(saveflag==1) 
     		{getchar();
     		 printf("\n======>Whether save the modified record to file?(Y/N):");
     		 scanf("%c",&ch);
     		 if(ch=='y'||ch=='Y')
     		 save(l);
     		}
     		printf("===========>thank you for useness!");
     		getchar();
     		break;
     	}
     	switch(select)
     	{
     		case 1:Add(l);break;           /*增加学生记录*/
     		case 2:Del(l);break;          /*删除学生记录*/ 
     		case 3:Qur(l);break;          /*查询学生记录*/
     		case 4:Modify(l);break;       /*修改学生记录*/
     		case 5:Insert(l);break;      /*插入学生记录*/
     		case 6:Tongji(l);break;      /*统计学生记录*/
     		case 7:Sort(l);break;         /*排序学生记录*/
     		case 8:Save(l);break;          /*保存学生记录*/
     		case 9:system("cls");Disp (l);break;   /*显示学生记录*/
			default: Wrong();getchar();break;      /*按键有误，必须为0~9的数字*/
     	}
     }
     void menu()/*主菜单*/
     {
     	system("cls"); /*调用DOS指令，清屏*/
     	textcolor(10);
     	gotoxy(10,5);
     	cprintf("                            The Students' Grade Management System  \n");
     	gotoxy(10,8);
     	cprintf("***************************************Menu*************************************\n");
     	gotoxy(10,9);
     	cprintf("  *  1 input record      2 delete record         *\n");
     	gotoxy(10,10);
     	cprintf("  *  3 search record     4 modify record         *\n");
     	gotoxy(10,11);
     	cprintf("  *  5 insert record     6 count record          *\n");
     	gotoxy(10,12);
     	cprintf("  *  7 sort  record      8 save  record          *\n");
     	gotoxy(10,13);
     	cprintf("  *  9 display record    0 quit system           *\n");
     	gotoxy(10,14);
     	cprintf("**************************************************\n");
     	/*输出至窗口*/
     	
     }
     /*表格显示信息*/
	 void printdata(Node *pp) /*格式化输出*/
	 {
	 	Node* p;
	 	p=pp;
	 	printf(FORMAT,DATA);
	 }
     void Wrong()
     {
     	printf("\n\n\n\n\n***********Error:input has wrong!Press any key to continue***\n");
     	getchar();
     }
     void Nofind()/*输出未查找到此学生的信息*/
     {
     	printf("\n============>Can not find this student!\n"); 
     }
     /*显示信息*/
     void Disp (Link l)
     {
     	Node *p;/*头节点 后面的信息*/
     	p=l->next;
		 if(!p)
		 {
		 	printf("\n=================>Not student record!\n");
		 	getchar();
		 	return;
		 } 
		 printf("\n\n");
		 printheader();/*输出表格头部*/
		 while(p);
		 {
		 	printdata(p);
		 	p=p->next;/*移动节点*/
		 	printf(HEADER3);
		 }
		 getchar() ;
     }
     /*信息查找定位*/
     /*定位链表中符合要求的节点，并返回指向该节点的指针
	 findmass[]保存要查找的具体内容；nameornum[]保存按什么查找；在单链表l中查找*/ 
	 Node* Locate(Link l,char findmass[],char nameornum[])
	 {
	 	Node *r;
	 	if(strcmp(nameornum,"num")==0) /*按学号查询*/
	 	{
	 		r=l->next;
	 		while(r)
	 		{
	 			if(strcmp(r->data.num,findmass)==0)/*如果找到findmass值的学号*/
	 			return r;
	 			r=r->next;
	 		}
	 	}
	 	else if(strcmp(nameornum,"name")==0) /*按姓名查询*/
	 	{
	 		r=l->next;
	 		while(r)
	 		{
	 			if(strcmp(r->data.num,findmass)==0)
	 			return r;
	 			r=r->next;
	 		}
	 	} 
	 	return 0;/*未找到：返回空指针*/
	 }
	 /*格式化输入数据*/
	 /*输入字符串，进行长度验证（小于lens）*/ 
	 void stringinput(char *t,int lens,char *notice) 
	 {
	 	char n[222];
	 	do{
	 		printf(notice);
	 		scanf("%s",n);
	 		if(strlen(n)>lens)printf("\n exceed the required length!\n");
	 	}while(strlen(n)>lens);
	 	strcpy(t,n);
	 }
	 /*输入分数，大于0小于100*/ 
	 int numberinput(char *notice) 
	 {
	 	int t=0;
	 	do{
	 		printf(notice);
			 scanf("%d",&t); 
	 	}
	 }
                                                                               //李雨珂 

/*增加学生记录*/
void  Add (Link l)                //定义单链表类型 
{
Node *p,*r,*s;                           /*实现添加操作的临时的结构体指针变量*/
char  ch,flag=0,num[10];
r=l;
s=l->next;
system("cls");
Disp(l);                              /*先打印出已有的学生信息*/
while(r->next!=NULL)
   r=r->next;                           /*将指针移至链表最末尾，准备添加记录*/
/*一次可输入多条记录，直至输入学号为0的记录结点添加操作*/
while(1)
{
/*输入学号，保证该学号没有被使用，若输入学号为0，则退出添加记录操作*/
while(1)
{
  stringinput(num,10,"input  number (press '0' return  menu):");    /*格式化输入学号保存到num变量，不想输入学号按0返回上一级菜单*/
  flag=0;
  if(strcmp(num,"0")==0)              
     {return;}
  s=l->next;
/*查询该学号是否已经存在，若存在则要求重新输入一个未被占用的学号*/
while(s)
   {
     if(strcmp(s->data.num,num)==0)
     {
      flag=1;
      break;
      }
   s=s->next;
   }
if (flag==1)                            /*提示用户是否重新输入*/
  {  getchar();
    printf("=====>The  number  %s  is  not  existing,try again? (y/n):",num);
        scanf("%c",&ch);
        if(ch=='y'||ch=='Y')
         continue;
        else
          return;
      }
     else
      {break;}
}
p=(Node *)malloc(sizeof(Node));       /*申请内存空间*/
if(!P)
{
  printf("\n allocate memory  failure ");/*如没有申请到，打印提示信息*/
  return ;                         /*返回主界面*/
}
strcpy(p->data.num,num) ;       /*将字符串num复制到 p->data.num中*/
stringinput (p->data.name,15,"Name:");
p->data.cgrade=numberinput("C  language Score[0-100]:");   /*输入并检验分数，分数必须在0~100之间*/
p->data.mgrade=numberinput("Math Score[0-100]:");       /*输入并检验分数，分数必须在0~100之间*/
p->data.egrade=numberinput("English Score[0-100]:");       /*输入并检验分数，分数必须在0~100之间*/
p->data.total=p->data.egrade+p->data.cgrade+p->data.mgrade;   /*计算总分*/
p->data.ave=(float) (p->data.tota1/3);       /*计算平均分*/
p->data.mingci=0;
p->next=NULL;                   /*表明这是链表的尾部结点*/
r->next=p;                       /*将新建的结点加入链表尾部中*/
r=p;
saveflag=1;
}
  return ;
}
        //查询学生记录                                                                         //任羿飞 
void Qur (link 1)//按学号或姓名查询学生记录 
{ int select;    //1:按学号查，2：按姓名查，其他：返回菜单 
  char searchinput[20];
  Node *p; 
 
  if(!l->next)  //若链表为空*
    { system("cls") ;
      print t ("\n=====>No student record! \n") ;
      getchar () ;
      return;}
  
  system("cls");
  printf("\n   ==> Search by number   ==>2 Search by name \n");
  printf (" please input choice[1,2]:  "); 
  scanf ("%d",&select) ;
  if(select==1)  /*按学号查询*/
    {stringinput (searchinput,10,"Input the existing student number:") ;
     /*在1中查找学号为searchinput 值的节点，并返回节点的指针*/
     p=Locate (1,searchinput,"num") ;
     
	 if(p) /*若p!=NULL*/
       {printheader () ;
		printdata(p) ;
		printf(END) ;
		printf("press any key to return") ;
		getchar () ;} 
     else Nofind() ;
     getchar () ;
    } 
/*按姓名查询*/
else if (select==2)
   {
     stringinput (searchinput,15,"input the existing student name:") ;
     p=Locate(l,searchinput,"name") ;
  
     if (p)
      { printheader();
        printdata(p);
        printf(END);
        printf("press any key to return");
        getchar();} 

     else
      Nofind() ;
     
	 getchar () ;
   } 
else Wrong ();

getchar();
}

 //删除学生记录                   //杨顺岩 
 void Del(Link l)

{

int sel;

Node *p,*r;

char findmess[20];

if(!l->next)

{ system("cls");

printf("\n=====>No student record!\n");

getchar();

return;

}

system("cls");

Disp (1);

pintf("\n   =====>1 Delete by number   =====>2 Delete by name\n");

pintf("  please choice[1,2]:");

sanf("%d",&sel);

if(sel==1)

{

sringinput(findmess,10,"input the existing student number:");

p=Locate(1,findmess,"num");

if(p)

{

r=1;

while(r->next!=p)

r=r->next;

r->next=p->next;            /*将p所指节点从链表中去除*/ 

free(p);                    /*释放内存空间*/ 

printf("\n=====>delete success!\n");

getchar();

saveflag=1;

}

else

 Nofind();

getchar();

}

else if(sel==2)            /*先按姓名查询到该记录所在的节点*/ 

{

stringinput(findmess,15,"input the existing student name");

p=Locate(l,findmess,"name");

if(p)

{

r=1;

while(r->next!=p)

r=r->next;

r->next=p->next;

free(p);

printf("\n=====>delete success!\n");

getchar();

saveflag=1;

}

else

Nofind();

getchar();

}

else

Wrong();

getchar();

}
 //修改学生记录                //万轶 
 void Modify(Link l)
{
	Node *p;
	char findmess[20];
	if(!l->next)
	{
	system("cls");
	printf("\n=====>No student record!\n");
	getchar();
	return;	
	}
	system("cls");
	printf("modify student recorder");
	Disp (l);
	stringinput(findmess,10,"input the existing student:"); // input and check the ID.
	p=Locate(l ,findness,"num");								// 查询该节点 
 
 		if(p)
 		{
 			printf("Number:%s,\n",p->data,num);
			 printf("Name:%s",p->data,name);
			 stringinput(p->data,name,15,"input new name:"); 
			 printf("C language score:%d,",p->data.cgrade);
			 p->data.mgrade=numberinput("C language Score[0-100]:");
			 printf("Math score:%d,",p->data.mgrade);
			 p->data.mgrade=numberinput("Math Score[0-100]:");
			 printf("English score:%d",p->data.egrade);
			 p->data.egrade=numberinput("English Score[0-100];");
			 p->data.total=p->data.egrade+p->data.mgrade+p->data.cgrade;
			 p->data.ave={float}{p->data.total/3};
			 p->data.mingci=0;
			 printf("\n=====>odify success!\n");
			 Disp (l);
			 saveflag=1;
		 }
		 else
		 	Nofind();
		 	getchar();
	}
 
  
 
//插入学生记录                    //李雨珂 
/*插入记录：按学号查询到要插入的结点的位置，然后在该学号之后插入一个新结点*/
void  Insert(Link l)
{
  Link p,v,newinfo;                /*p指向插入位置，newinfo指向新插入记录*/
  char ch,num[10],s[10];           /*s[]保存插入点位置之前的学号，num[]保存输入的新记录的学号*/
  int  flag=0;
  v=l->next;
  system("cls");
  Disp  (l);
  while(1)
{  stringinput (s,10,"please input insert locatin after the Number:");
     flag=0;v=l->next;
     while(v)                         /*查询该学号是否存在，flah=1表示该学号存在*/
     {
      if(strcmp(v->data.num,s)==0)   {flag=1;break;}
        v=v->next;
}
 if ( flag==1)
   break;                       /*若学号存在，则进行插入之前的新纪录的输入操作*/
else
{  getchar();
printf("\n=====>The number %s is not existing,  try  again?(y/n): ",a);
   scanf("%c",&ch);
   if(ch=='y'||ch=='Y')
  {continue;}
   else
    {return;}
}
}
/*以下新记录的输入操作与Add()相同*/
stringinput(num,10, "input new  student  Number:");
v=l->next;
while(v)
{
  if (strcmp(v->data.num,num) ==0)
{
printf("=====>Sorry,the new number: '%s' is existing  !\n",num);
printheader();
printdata(v);
printf("\n");
getchar();
return;
}
v=v->next;
}
  newinfo=(Node *)malloc(sizeof(Node));
if(!newinfo)
 {
printf("\n  allocate  memory  failure ");  /*如没有申请到，打印提示信息*/
return ;                              /*返回主界面*/   
}
strcpy(newinfo->data.num,num); 
stringinput(newinfo->data.name,15,"Name:");
newinfo->data.cgrade=nemberinput("C language Score[0-100]:");
newinfo->data.mgrade=numberinput("Math Score[0-100]:");
newinfo->data.egrade=numberinput("English Score[0-100]:");
newinfo->data.total=newinfo->data.egrade+newinfo->data.cqrade+newinfo->data.mgrade;
newinfo->data.ave=(float) (newinfo->data.total/3);
newinfo->data.mingci=0;
newinfo->next=NULL;
saveflag=1;       /*在main()有对该全局变量的判断，若为1，则进行存盘操作*/
/*将指针赋值给p,因为1中的头节点的下一个节点才实际保存着学生的记录*/
  P=l->next;
  while (1)
    {
     if (strcmp(p->data.num,s)==0)    /*链表中插入一个节点*/
 {
    newinfo->next=p-->next;
    p->next-newinfo;
    break;
 }
    p=p->next;
    }
Disp  (l);
printf ("\n\n");
getchar();
}
//统计学生记录
//统计该班的总分第一名和单科第一名，和各科不及格人数
void Tongji (Link 1)
  {
	Node *pm,*pe,*pc,*pt;/*用于指向分数最高的节点*/
	Node *r=1->next;
	int countc=O,countm=O,counte=0; /*保存科成绩中不及格的人数*/
    if(!r)
	  { system("cls") ;
		printf("\nn==>No student record!\n") ;
		getchar();
		return;}

    system("cls");
    Disp (1);
    pm=pe=pc=pt=r;

    while(r)
	  { if(r->data.cgrade<60) countc++;
		if(r->data.mgrade<60) countm++;
		if(r->data.egrade<60) counte++;
	
		if(r->data.cgrade>=pc->data.cgrade) pc=r;
    	if(r->data.mgrade>=pm->data.mgrade) pm=r;
    	if(r->data.egrade>=pe->data.egrade) pe=r;
    	if(r->data.total>=pt->sdata.total)  pt=r;
    	r=r->next;}
    	
	printf("\n-------------统计结果-------------\n");
	printt ("C language<60:%d人\n",countc);
	printf ("Math<60:%d人\n",countm);
	printf("Engliah<60:%d人\n",counte);
	printf("---------------------------");
	printf("The student with highest total score :%s total score:%d\n",      pt->data.name, pt->data,total);
	printf("The student with highest English score name:%s total score:%d\n",pe->data.name, pe->data.egrade);
	printf("The student with highest Math score name:%s total score:%d\n",   pm->data.name, pm->data,mgrade);
    printt("The student with highest C score name: %s total score:%d\n",     pc->data,name, pc->data.cgrade) ;
	printf("\n\npress any key to return\n") ;

	getchar();
  }
//排序处理                                                                             //杨顺岩 
void Sort(Link l)

{

link ll;

Node *p,*rr,*s;

int i=0;

if(l->next==NULL)

{ system("cls");

  printf("\n=====>Not student record!\n");

getchar();

return;

}

ll =(Node*)malloc(sizeof(Node));

if(!ll)

{

printf("\n allocate memory failure");

return;

}

ll->next=NULL;

system("cls");

disp(l);

p=l->next;

while(p)

{

s=(Node*)malloc(sizeof(Node));

if(!s)

{

printf("\n allocate memory failure");

return;

}

s->date=p->data;

s->next=NULL;

rr=ll;

while(rr->next!=NULL && rr->next->data.total>=p->data.total)

{rr=rr->next;}

if(rr->next==NULL)

rr->next=s;

}

p=p->next;

}

l->next=ll->next;

p=l->next;

while(p!=NULL)

{

i++;

p->data.mingci=i:

p=p->next;

}
//存贮学生信息                                                  万轶 
void Save(Link 1){
	FILE* fp;				
	Node *p;
	int count=0;
	fp=fopen("c:\\student","wb");					//以只写方式打开二进制文件 
	if(fp==NULL){									 
		printf("\n=====>open file error!\n");		//failed to open file	
		getchar();									//press "enter" Key to go on
		return ;
	}
	p=1->next;
	
	while(p) {
		if(fwrite(p,sizeof(Node),1,fp) == 1){ 		//每次写一条记录或一个节点信息至文件 
			p=p->next;
			count++;
		}
		else{
			break;
		}
	}
	if(count>0){
		getchar();
		printf("\n\n\n\n\n=====>save file complete,total saved's record number is:%d\n",count);
		getchar();
		saveflag=0; 	
	}
	else{
		system("cls");
		printf("the current link is empty,no student record is saved!\n");
		getchar();
	}
	fclose(fp);
	
}









