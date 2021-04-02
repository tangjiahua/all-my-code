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
/*������ѧ���йص����ݽṹ*/
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
/*����ÿ����¼��ڵ�����ݽṹ�����Ϊ��node*/
typedef struct node
{
	struct student date;     /*������*/
	struct node *next;       /*ָ����*/ 
}   Node,*Link;              /*Node Ϊnode���͵Ľṹ������*linkΪnode���͵�ָ�����*/ 

 void main()
{
	Link l;                 /*��������*/
	FILE *fp;               /*�ļ�ָ��*/ 
	int select;             /*����ѡ��������*/
	char ch;                /*���棨y,Y,n,N��*/
	int count=0;            /*�����ļ��еļ�¼����*/
	Node *p,*r;             /*�����¼ָ�����*/
	l=(Node*)malloc(sizeof(Node));
	if(!l)
	{
		printf("\n allocate memory failure");        /*��û�����뵽����ӡ��ʾ��Ϣ*/
		return ;                                     /*����������*/
	}
	 l->next=NULL;
	 r=1;
	 /*��׷�ӷ�ʽ��һ���������ļ����ɶ���д������t�ļ������ڣ��ᴴ�����ļ�*/
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
	 		printf(" memory malloc failure!\n");        /*û������ɹ�*/
	 		exit(0);                                    /*�˳�*/
	 		
	 	}
	 	if(fread (p,sizeof(Node),1,fp)==1)               /*һ�δ��ļ��ж�ȡһ��ѧ����¼*/
	 	{
		 p->next=NULL;
		 r->next=p;
		 r=p;                                            /*rָ������ƶ�һ��λ��*/
		 count++; 
		 } 
     }
     fclose(fp); /*�ر��ļ�*/
     printf("\n=============>open file sucess, the total records number is : %d.\n", count) ;
     menu();
     while(l)
     {
     	system("cls");
     	menu();
     	p=r;
     	printf("\n      Please Enter your choice(0~9):");/*��ʾ��ʾ��Ϣ*/
     	scanf("%d",&select) ;
     	if(select==0)
     	{
     		/*����������������޸���δ���д��̲�������˱�־Ϊ1*/
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
     		case 1:Add(l);break;           /*����ѧ����¼*/
     		case 2:Del(l);break;          /*ɾ��ѧ����¼*/ 
     		case 3:Qur(l);break;          /*��ѯѧ����¼*/
     		case 4:Modify(l);break;       /*�޸�ѧ����¼*/
     		case 5:Insert(l);break;      /*����ѧ����¼*/
     		case 6:Tongji(l);break;      /*ͳ��ѧ����¼*/
     		case 7:Sort(l);break;         /*����ѧ����¼*/
     		case 8:Save(l);break;          /*����ѧ����¼*/
     		case 9:system("cls");Disp (l);break;   /*��ʾѧ����¼*/
			default: Wrong();getchar();break;      /*�������󣬱���Ϊ0~9������*/
     	}
     }
     void menu()/*���˵�*/
     {
     	system("cls"); /*����DOSָ�����*/
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
     	/*���������*/
     	
     }
     /*�����ʾ��Ϣ*/
	 void printdata(Node *pp) /*��ʽ�����*/
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
     void Nofind()/*���δ���ҵ���ѧ������Ϣ*/
     {
     	printf("\n============>Can not find this student!\n"); 
     }
     /*��ʾ��Ϣ*/
     void Disp (Link l)
     {
     	Node *p;/*ͷ�ڵ� �������Ϣ*/
     	p=l->next;
		 if(!p)
		 {
		 	printf("\n=================>Not student record!\n");
		 	getchar();
		 	return;
		 } 
		 printf("\n\n");
		 printheader();/*������ͷ��*/
		 while(p);
		 {
		 	printdata(p);
		 	p=p->next;/*�ƶ��ڵ�*/
		 	printf(HEADER3);
		 }
		 getchar() ;
     }
     /*��Ϣ���Ҷ�λ*/
     /*��λ�����з���Ҫ��Ľڵ㣬������ָ��ýڵ��ָ��
	 findmass[]����Ҫ���ҵľ������ݣ�nameornum[]���水ʲô���ң��ڵ�����l�в���*/ 
	 Node* Locate(Link l,char findmass[],char nameornum[])
	 {
	 	Node *r;
	 	if(strcmp(nameornum,"num")==0) /*��ѧ�Ų�ѯ*/
	 	{
	 		r=l->next;
	 		while(r)
	 		{
	 			if(strcmp(r->data.num,findmass)==0)/*����ҵ�findmassֵ��ѧ��*/
	 			return r;
	 			r=r->next;
	 		}
	 	}
	 	else if(strcmp(nameornum,"name")==0) /*��������ѯ*/
	 	{
	 		r=l->next;
	 		while(r)
	 		{
	 			if(strcmp(r->data.num,findmass)==0)
	 			return r;
	 			r=r->next;
	 		}
	 	} 
	 	return 0;/*δ�ҵ������ؿ�ָ��*/
	 }
	 /*��ʽ����������*/
	 /*�����ַ��������г�����֤��С��lens��*/ 
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
	 /*�������������0С��100*/ 
	 int numberinput(char *notice) 
	 {
	 	int t=0;
	 	do{
	 		printf(notice);
			 scanf("%d",&t); 
	 	}
	 }
                                                                               //������ 

/*����ѧ����¼*/
void  Add (Link l)                //���嵥�������� 
{
Node *p,*r,*s;                           /*ʵ����Ӳ�������ʱ�Ľṹ��ָ�����*/
char  ch,flag=0,num[10];
r=l;
s=l->next;
system("cls");
Disp(l);                              /*�ȴ�ӡ�����е�ѧ����Ϣ*/
while(r->next!=NULL)
   r=r->next;                           /*��ָ������������ĩβ��׼����Ӽ�¼*/
/*һ�ο����������¼��ֱ������ѧ��Ϊ0�ļ�¼�����Ӳ���*/
while(1)
{
/*����ѧ�ţ���֤��ѧ��û�б�ʹ�ã�������ѧ��Ϊ0�����˳���Ӽ�¼����*/
while(1)
{
  stringinput(num,10,"input  number (press '0' return  menu):");    /*��ʽ������ѧ�ű��浽num��������������ѧ�Ű�0������һ���˵�*/
  flag=0;
  if(strcmp(num,"0")==0)              
     {return;}
  s=l->next;
/*��ѯ��ѧ���Ƿ��Ѿ����ڣ���������Ҫ����������һ��δ��ռ�õ�ѧ��*/
while(s)
   {
     if(strcmp(s->data.num,num)==0)
     {
      flag=1;
      break;
      }
   s=s->next;
   }
if (flag==1)                            /*��ʾ�û��Ƿ���������*/
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
p=(Node *)malloc(sizeof(Node));       /*�����ڴ�ռ�*/
if(!P)
{
  printf("\n allocate memory  failure ");/*��û�����뵽����ӡ��ʾ��Ϣ*/
  return ;                         /*����������*/
}
strcpy(p->data.num,num) ;       /*���ַ���num���Ƶ� p->data.num��*/
stringinput (p->data.name,15,"Name:");
p->data.cgrade=numberinput("C  language Score[0-100]:");   /*���벢�������������������0~100֮��*/
p->data.mgrade=numberinput("Math Score[0-100]:");       /*���벢�������������������0~100֮��*/
p->data.egrade=numberinput("English Score[0-100]:");       /*���벢�������������������0~100֮��*/
p->data.total=p->data.egrade+p->data.cgrade+p->data.mgrade;   /*�����ܷ�*/
p->data.ave=(float) (p->data.tota1/3);       /*����ƽ����*/
p->data.mingci=0;
p->next=NULL;                   /*�������������β�����*/
r->next=p;                       /*���½��Ľ���������β����*/
r=p;
saveflag=1;
}
  return ;
}
        //��ѯѧ����¼                                                                         //����� 
void Qur (link 1)//��ѧ�Ż�������ѯѧ����¼ 
{ int select;    //1:��ѧ�Ų飬2���������飬���������ز˵� 
  char searchinput[20];
  Node *p; 
 
  if(!l->next)  //������Ϊ��*
    { system("cls") ;
      print t ("\n=====>No student record! \n") ;
      getchar () ;
      return;}
  
  system("cls");
  printf("\n   ==> Search by number   ==>2 Search by name \n");
  printf (" please input choice[1,2]:  "); 
  scanf ("%d",&select) ;
  if(select==1)  /*��ѧ�Ų�ѯ*/
    {stringinput (searchinput,10,"Input the existing student number:") ;
     /*��1�в���ѧ��Ϊsearchinput ֵ�Ľڵ㣬�����ؽڵ��ָ��*/
     p=Locate (1,searchinput,"num") ;
     
	 if(p) /*��p!=NULL*/
       {printheader () ;
		printdata(p) ;
		printf(END) ;
		printf("press any key to return") ;
		getchar () ;} 
     else Nofind() ;
     getchar () ;
    } 
/*��������ѯ*/
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

 //ɾ��ѧ����¼                   //��˳�� 
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

r->next=p->next;            /*��p��ָ�ڵ��������ȥ��*/ 

free(p);                    /*�ͷ��ڴ�ռ�*/ 

printf("\n=====>delete success!\n");

getchar();

saveflag=1;

}

else

 Nofind();

getchar();

}

else if(sel==2)            /*�Ȱ�������ѯ���ü�¼���ڵĽڵ�*/ 

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
 //�޸�ѧ����¼                //���� 
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
	p=Locate(l ,findness,"num");								// ��ѯ�ýڵ� 
 
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
 
  
 
//����ѧ����¼                    //������ 
/*�����¼����ѧ�Ų�ѯ��Ҫ����Ľ���λ�ã�Ȼ���ڸ�ѧ��֮�����һ���½��*/
void  Insert(Link l)
{
  Link p,v,newinfo;                /*pָ�����λ�ã�newinfoָ���²����¼*/
  char ch,num[10],s[10];           /*s[]��������λ��֮ǰ��ѧ�ţ�num[]����������¼�¼��ѧ��*/
  int  flag=0;
  v=l->next;
  system("cls");
  Disp  (l);
  while(1)
{  stringinput (s,10,"please input insert locatin after the Number:");
     flag=0;v=l->next;
     while(v)                         /*��ѯ��ѧ���Ƿ���ڣ�flah=1��ʾ��ѧ�Ŵ���*/
     {
      if(strcmp(v->data.num,s)==0)   {flag=1;break;}
        v=v->next;
}
 if ( flag==1)
   break;                       /*��ѧ�Ŵ��ڣ�����в���֮ǰ���¼�¼���������*/
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
/*�����¼�¼�����������Add()��ͬ*/
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
printf("\n  allocate  memory  failure ");  /*��û�����뵽����ӡ��ʾ��Ϣ*/
return ;                              /*����������*/   
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
saveflag=1;       /*��main()�жԸ�ȫ�ֱ������жϣ���Ϊ1������д��̲���*/
/*��ָ�븳ֵ��p,��Ϊ1�е�ͷ�ڵ����һ���ڵ��ʵ�ʱ�����ѧ���ļ�¼*/
  P=l->next;
  while (1)
    {
     if (strcmp(p->data.num,s)==0)    /*�����в���һ���ڵ�*/
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
//ͳ��ѧ����¼
//ͳ�Ƹð���ֵܷ�һ���͵��Ƶ�һ�����͸��Ʋ���������
void Tongji (Link 1)
  {
	Node *pm,*pe,*pc,*pt;/*����ָ�������ߵĽڵ�*/
	Node *r=1->next;
	int countc=O,countm=O,counte=0; /*����Ƴɼ��в����������*/
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
    	
	printf("\n-------------ͳ�ƽ��-------------\n");
	printt ("C language<60:%d��\n",countc);
	printf ("Math<60:%d��\n",countm);
	printf("Engliah<60:%d��\n",counte);
	printf("---------------------------");
	printf("The student with highest total score :%s total score:%d\n",      pt->data.name, pt->data,total);
	printf("The student with highest English score name:%s total score:%d\n",pe->data.name, pe->data.egrade);
	printf("The student with highest Math score name:%s total score:%d\n",   pm->data.name, pm->data,mgrade);
    printt("The student with highest C score name: %s total score:%d\n",     pc->data,name, pc->data.cgrade) ;
	printf("\n\npress any key to return\n") ;

	getchar();
  }
//������                                                                             //��˳�� 
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
//����ѧ����Ϣ                                                  ���� 
void Save(Link 1){
	FILE* fp;				
	Node *p;
	int count=0;
	fp=fopen("c:\\student","wb");					//��ֻд��ʽ�򿪶������ļ� 
	if(fp==NULL){									 
		printf("\n=====>open file error!\n");		//failed to open file	
		getchar();									//press "enter" Key to go on
		return ;
	}
	p=1->next;
	
	while(p) {
		if(fwrite(p,sizeof(Node),1,fp) == 1){ 		//ÿ��дһ����¼��һ���ڵ���Ϣ���ļ� 
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









