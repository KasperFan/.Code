#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum{false, true} bool;																					

struct Worker
{
	char num[20];
	char namepin[20];
	char name[20];
	char nation[20];
	char sex[20];
	char birth[20];
	char workday[20];
	char education[20];
	char position[20];
	char addr[20];
	char phone[20];
	char salary[20];
};

typedef struct node
{
	struct Worker worker;
	struct node *next;
	struct node *prior;
}Node;

int Meun     (Node *worker);
int addworker(Node *worker);
int delworker(Node *worker);
int serworker(Node *worker);
int risworker(Node *worker);
int sortworker(Node *worker);
int savefile (Node *worker);
int putNode  (Node *worker);
int readfile (Node *worker);
int next     (Node *worker);

int main()
{
	Node *worker;
	worker=(Node*)malloc(sizeof(Node));
	worker->next=worker->prior=NULL;
	system("color 3f");
	readfile(worker);
	Meun(worker);
	return 0;
}
int Meun(Node *worker)
{
	int choose=0;
	printf("****************************");
	printf("\t欢迎来到职工管理系统\n");
	printf("\t1.新增一名职工\n");
	printf("\t2.删除一名职工\n");
	printf("\t3.查找职工\n");
	printf("\t4.修改职工信息\n");
	printf("\t5.对职工进行排序\n");
	printf("\t0.退出系统\n");
	printf("\t请输入操作数字\n");
	printf("****************************");
	scanf("%d",&choose);
	switch(choose)
	{
	case 1:
		system("cls");
	    printf("****************************");
	    printf("欢迎进入新增员工界面\n");
	    printf("****************************");
	    addworker(worker);
	    savefile(worker);
	    next(worker);
	    break;
	case 2:
		system("cls");
		printf("****************************");
		printf("欢迎进入删除员工界面\n");
		printf("****************************");
		delworker(worker);
		savefile(worker);
		next(worker);
	    break;
	case 3:
		system("cls");
		printf("****************************");
		printf("欢迎进入查询员工界面\n");
		printf("****************************");
		serworker(worker);
		savefile(worker);
		next(worker);
	    break;	
	case 4:
		system("cls");
		printf("****************************");
		printf("欢迎进入修改员工界面\n");
		printf("****************************");
		risworker(worker);
		savefile(worker);
		next(worker);
	    break;
	case 5:
		system("cls");
		printf("****************************");
		printf("欢迎进入排序员工界面\n");
		printf("****************************");
		sortworker(worker);
		savefile(worker);
		next(worker);
		break;
	case 0:
		exit(0);
		default:
			system("cls");
			Meun(worker);
	}
}

int addworker (Node *worker)
{
	Node *p,*q,*pre,*k;
	q=pre=worker;
	k=worker->next;
	if(q->next!=NULL)
	{
		pre=q;
		q=q->next;
		q->prior=pre;
	}
	printf("请依次输入：\n");
	printf("编号\t姓名拼音\t姓名\t民族\t性别\t出生年月\t工作年月\t学历\t职位\t地址\t电话\t工资\n");
	p=(Node *)malloc(sizeof(Node));
	scanf("%s %s %s %s %s %s %s %s %s %s %s %s",p->worker.num,p->worker.namepin,p->worker.name,p->worker.nation,p->worker.sex,p->worker.birth,p->worker.workday,p->worker.education,p->worker.position,p->worker.addr,p->worker.phone,p->worker.salary);
	while(k!=NULL)
	{
		if(strcmp(p->worker.num,k->worker.num)==0)
		{
			printf("该编号已存在，请重新输入编号\n");
			scanf("%s",p->worker.num);
			k=worker;
		}
	        k=k->next;
	}
	printf("新增添职工信息如下：\n");
	printf("编号\t姓名拼音\t姓名\t民族\t性别\t出生年月\t工作年月\t学历\t职位\t地址\t电话\t工资\n");
	printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",p->worker.num,p->worker.namepin,p->worker.name,p->worker.nation,p->worker.sex,p->worker.birth,p->worker.workday,p->worker.education,p->worker.position,p->worker.addr,p->worker.phone,p->worker.salary);
	while(q!=NULL)
	{
		if((strcmp(p->worker.namepin,pre->worker.namepin)>0)&&(strcmp(p->worker.namepin,q->worker.namepin)<0))
		{
			p->next=q;
			p->prior=q->prior;
			q->prior=p;
			p->prior->next=p;
			break;
		}
		if((q->next==NULL)&&(strcmp(p->worker.namepin,pre->worker.namepin)>0))
		{
		    q->next=p;
			p->prior=q;
			p->next=NULL;
			break;	
		}
		pre=q;
		q=q->next;
		q->prior=pre;
	}

}

int delworker(Node *worker)
{
	Node *p,*r;
	char delnum[20],delname[20];
	int delchoose,surechoose;
	p=worker->next;
	if(p==NULL)
	{
		printf("目前没有资料\n");
	}
	else 
	{
		printf("按职工编号删除：1\n");
		printf("按职工姓名删除：2\n");
		printf("****************************************************\n");
		scanf("%d",&delchoose);
		if(delchoose==1)
		{
			int num=0;
			printf("请输入要删除的编号\n");
			scanf("%s",delnum);
			while(p!=NULL)
			{
				if(strcmp(p->worker.num,delnum)==0)
				{	num++;
				printf("编号\t姓名拼音\t姓名\t民族\t性别\t出生年月\t工作年月\t学历\t职位\t地址\t电话\t工资\n");
				printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",p->worker.num,p->worker.namepin,p->worker.name,p->worker.nation,p->worker.sex,p->worker.birth,p->worker.workday,p->worker.education,p->worker.position,p->worker.addr,p->worker.phone,p->worker.salary);
				printf("确认删除：1，取消删除：2\n");
				scanf("%d",&surechoose);
				if(surechoose==1)
				{
					printf("%s删除成功\n",p->worker.name);
					if(p!=NULL)
					{
						r=worker;
						while(r->next!=p)
						{
							r=r->next;
						}
						r->next=r->next->next;
					}
					savefile(worker);
				}
				else if(surechoose==2)
				{
					printf("您已取消操作\n");
					break;
				}
				break;
			}
			else
			{
				if(p->next==NULL&&num==0)
				{
					printf("该职工不存在\n");
				}
			}
				p=p->next;
		}
		
	}
}	
};
int serworker(Node *worker)
{
	char serNum[20],sername[20],serjob[20],sereducation[20],sersalarysta[20],sersalaryend[20];
	int serchoose,numsta,numend,sersalarynum;
	Node* p=worker->next;
	if(p==NULL)
    {
		printf("目前没有资料\n");
	}
	else
	{
        printf("通过职工编号查询：  1\n");
		printf("通过职工姓名查询：  2\n");
		printf("通过职工工资范围查询： 3\n");
		printf("通过职工职位查询：   4\n");
		printf("通过职工学历查询：   5\n");
		printf("请输入对应数字\n");
		printf("*********************************************\n");
		scanf("%d",&serchoose);
		if(serchoose==1)
		{
			int num=0;
			printf("请输入要查询的职工编号：\n");
			scanf("%s",&serNum);
			while(p!=NULL);
			{
				if(strcmp(p->worker.name,sername)==0)
				{
					num++;
					if(num==1)
					{
						printf("*********************************************************************\n");
						printf("编号\t姓名拼音\t姓名\t民族\t性别\t出生年月\t工作年月\t学历\t职位\t地址\t电话\t工资\n");
					}
					printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",p->worker.num,p->worker.namepin,p->worker.name,p->worker.nation,p->worker.sex,p->worker.birth,p->worker.workday,p->worker.education,p->worker.position,p->worker.addr,p->worker.phone,p->worker.salary);
						
				}
				else
				{
					if(p->next==NULL&&num==0)
					{
						printf("未找到该职工\n");
					}
					
				}
				p=p->next;
			}
		}
		else if(serchoose==3)
		{
			int num=0;
			printf("请输入要查询的职工工资范围： \n");
			printf("起始工资：");
			scanf("%d",&sersalarysta);
			printf("工资上限：");
			scanf("%d",&sersalaryend);
			numsta=*(int  *)sersalarysta;
			numend=*(int *)sersalaryend;
			while(p!=NULL)
			{
				sersalarynum=atoi(p->worker.salary);
				if(sersalarynum>=numsta&&sersalarynum<=numend)
				{
				num++;
				if(num==1)
				{
					printf("****************************************************************************\n");
					printf("编号\t姓名拼音\t姓名\t民族\t性别\t出生年月\t工作年月\t学历\t职位\t地址\t电话\t工资\n");
				}
					printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",p->worker.num,p->worker.namepin,p->worker.name,p->worker.nation,p->worker.sex,p->worker.birth,p->worker.workday,p->worker.education,p->worker.position,p->worker.addr,p->worker.phone,p->worker.salary);
				}
				else
				{
					if(p->next==NULL&&num==0)
					{
						printf("该范围内没有职工\n");
					}
				}
				p=p->next;
			}
		}
		else if(serchoose==4)
		{
			int num=0;
			printf("请输入要查询的职工职务：\n");
			scanf("%s",&serjob);
			while(p!=NULL)
			{
				if(strcmp(p->worker.position,serjob)==0)
				{
					num++;
					if(num==1)
					{
						printf("****************************************************************\n");
						printf("编号\t姓名拼音\t姓名\t民族\t性别\t出生年月\t工作年月\t学历\t职位\t地址\t电话\t工资\n");
					}
						printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",p->worker.num,p->worker.namepin,p->worker.name,p->worker.nation,p->worker.sex,p->worker.birth,p->worker.workday,p->worker.education,p->worker.position,p->worker.addr,p->worker.phone,p->worker.salary);
				}
				else
				{
					if(p->next==NULL&&num==0)
					{
						printf("未找到该职工\n");
					}
				}
				p=p->next;
			}
		}
		else if(serchoose==5)
		{
			int num=0;
			printf("请输入要查询的职工学历：\n");
			scanf("%s",&sereducation);
			while(p!=NULL)
			{
				if(strcmp(p->worker.education,sereducation)==0)
				{
					num++;
					if(num==1)
					{
						printf("********************************************************************\n");
						printf("编号\t姓名拼音\t姓名\t民族\t性别\t出生年月\t工作年月\t学历\t职位\t地址\t电话\t工资\n");
					}
					printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",p->worker.num,p->worker.namepin,p->worker.name,p->worker.nation,p->worker.sex,p->worker.birth,p->worker.workday,p->worker.education,p->worker.position,p->worker.addr,p->worker.phone,p->worker.salary);
				}
				else
				{
					if(p->next==NULL&&num==0)
					{
						printf("未找到该职工\n");
					}
					
				}
				p=p->next;
			}
		}
		else
		{
			printf("输入出错，请重新选择\n");
			serworker(worker);
			
		}
	}
}
int risworker(Node *worker)
{
	char risnum[20],risname[20];
	int rischoose;
	Node *p=worker->next;
	if(p==NULL)
	{
		printf("目前没有资料\n");
	}
	else
	{
		printf("通过职工编号修改：   1\n");
		printf("通过职工姓名修改：   2\n");
		printf("请输入对应数字： \n");
		printf("********************************************************\n");
		scanf("%d",&rischoose);
		if(rischoose==1)
		{
			printf("请输入要修改的职工编号：\n");
			scanf("%s",&risnum);
			int num=0;
			while(p!=NULL)
			{
				if(strcmp(p->worker.num,risnum)==0)
				{
					num++;
					printf("找到该职工，其信息如下\n");
					printf("编号\t姓名拼音\t姓名\t民族\t性别\t出生年月\t工作年月\t学历\t职位\t地址\t电话\t工资\n");
					printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",p->worker.num,p->worker.namepin,p->worker.name,p->worker.nation,p->worker.sex,p->worker.birth,p->worker.workday,p->worker.education,p->worker.position,p->worker.addr,p->worker.phone,p->worker.salary);
					
					printf("\n请依次输入数据进行修改：\n");
					printf("编号\t姓名拼音\t姓名\t民族\t性别\t出生年月\t工作年月\t学历\t职位\t地址\t电话\t工资\n");
					printf("%s\t",p->worker.num);
					scanf("%s %s %s %s %s %s %s %s %s %s %s %s",p->worker.num,p->worker.namepin,p->worker.name,p->worker.nation,p->worker.sex,p->worker.birth,p->worker.workday,p->worker.education,p->worker.position,p->worker.addr,p->worker.phone,p->worker.salary);
					break;
				}
				else
				{
					if(p->next==NULL&&num==0)
					{
						printf("未找到该职工\n");
					}
				}
				p=p->next;
			}
		}
		else if(rischoose==2)
		{
			printf("请输入要修改的职工姓名：\n");
			scanf("%s",&risname);
			int num=0;
			while(p!=NULL)
			{
				if(strcmp(p->worker.name,risname)==0)
				{
					num++;
					printf("找到该职工，其信息如下\n");
					printf("编号\t姓名拼音\t姓名\t民族\t性别\t出生年月\t工作年月\t学历\t职位\t地址\t电话\t工资\n");
					printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",p->worker.num,p->worker.namepin,p->worker.name,p->worker.nation,p->worker.sex,p->worker.birth,p->worker.workday,p->worker.education,p->worker.position,p->worker.addr,p->worker.phone,p->worker.salary);
					
					printf("\n请依次输入数据进行修改：\n");
					printf("编号\t姓名拼音\t姓名\t民族\t性别\t出生年月\t工作年月\t学历\t职位\t地址\t电话\t工资\n");
					printf("%s\t",p->worker.name);
					scanf("%s %s %s %s %s %s %s %s %s %s %s %s",p->worker.num,p->worker.namepin,p->worker.name,p->worker.nation,p->worker.sex,p->worker.birth,p->worker.workday,p->worker.education,p->worker.position,p->worker.addr,p->worker.phone,p->worker.salary);
					break;
				}
				else
				{
					if(p->next==NULL&&num==0)
					{
						printf("未找到该职工\n");
					}
				}
				p=p->next;
			}
		}
	}
}

int sortworker(Node *worker)
{
	Node* p=worker->next;
	Node*sorsalary;
	sorsalary=(Node*)malloc(sizeof(Node));
	sorsalary->next=sorsalary->prior=NULL;
	Node*s=sorsalary->next;
	Node *q;
	int sersalarynum;
	int sorchoose;
	if(p==NULL)
	{
		printf("目前没有资料\n");
	}
	else
	{
		printf("按照姓名排序：1\n");
		printf("按照工资排序：2\n");
		printf("请输入对应数字：\n");
		printf("******************************************************************************\n");
		scanf("%d",&sorchoose);
		if(sorchoose==1)
		{
			printf("以下数据按照姓名进行字典排序\n\n");
			printf("编号\t姓名拼音\t姓名\t民族\t性别\t出生年月\t工作年月\t学历\t职位\t地址\t电话\t工资\n");
			while(p!=NULL)
			{
			printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",p->worker.num,p->worker.namepin,p->worker.name,p->worker.nation,p->worker.sex,p->worker.birth,p->worker.workday,p->worker.education,p->worker.position,p->worker.addr,p->worker.phone,p->worker.salary);	
			p=p->next;
			}
		}
		else if(sorchoose==2)
		{
			printf("以下数据按照工资进行排序\n\n");
			printf("编号\t姓名拼音\t姓名\t民族\t性别\t出生年月\t工作年月\t学历\t职位\t地址\t电话\t工资\n");
			s=(Node*)malloc(sizeof(Node));
			s->worker=p->worker;
			s->prior=sorsalary;
			s->next=NULL;
			p=p->next;
			while(p!=NULL)
			{
				sersalarynum=atoi(p->worker.salary);
				q=(Node*)malloc(sizeof(Node));
				q->worker=p->worker;
				do
				{
				//TODO
				if(sorsalary->next==NULL)
				{
					sorsalary->next=s;
				}
				if(sersalarynum>=atoi(s->worker.salary)&&s->next==NULL)
				{
					s->next=q;
					q->prior=s;
					q->next=NULL;
					break;
				}
				else if(sersalarynum>=atoi(s->prior->worker.salary)&&sersalarynum<atoi(s->worker.salary))
				{
					q->prior=s->prior;
					q->next=s;
					s->prior->next=q;
					s->prior=q;
					break;
					//TODO
				}
				s->prior=s;
				s=s->next;
				}while(s!=NULL);
					s=sorsalary->next;
				    s->prior=sorsalary;
					p=p->next;
			}
			savefile(sorsalary);
		}
		
	}
}
int savefile(Node* worker)
{
	Node *p=NULL;
    FILE *fp;
	int savechoose;
	if(worker->next==NULL)
	{
		printf("没有记录\n");
	}
	else
	{
		p=worker->next;
	}
	
	fp=fopen("职工资料.txt","w");
	if(fp==NULL)
	{
		printf("文件无法打开\n");
	}
	while(p!=NULL)
	{
		fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",p->worker.num,p->worker.namepin,p->worker.name,p->worker.nation,p->worker.sex,p->worker.birth,p->worker.workday,p->worker.education,p->worker.position,p->worker.addr,p->worker.phone,p->worker.salary);
		p=p->next;
		 
	}
	fclose(fp);
}
int savenode(Node* worker)
{
	Node*p=NULL;
	int savechoose;
	if(worker->next==NULL)
	{
		printf("没有记录\n");
	}
	else
	{
		p=worker->next;
	}
	while(p!=NULL)
	{
	printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",p->worker.num,p->worker.namepin,p->worker.name,p->worker.nation,p->worker.sex,p->worker.birth,p->worker.workday,p->worker.education,p->worker.position,p->worker.addr,p->worker.phone,p->worker.salary);	
	p=p->next;
	if(p==NULL)
	{
		printf("记录保存成功\n");
	}
	}
}
int readfile(Node *worker)
{
		Node *p,*r;
		FILE *fp;
		r=worker;
		fp=fopen("职工资料.txt","rt");
	    p=(Node *)malloc(sizeof(Node));
		fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",p->worker.num,p->worker.namepin,p->worker.name,p->worker.nation,p->worker.sex,p->worker.birth,p->worker.workday,p->worker.education,p->worker.position,p->worker.addr,p->worker.phone,p->worker.salary);
		if(fp==NULL)
		{
			printf("文件打开失败");
		}
		while(!feof(fp))
		{
			r->next=p;
			r=p;
			r->next=NULL;
			p=(Node *)malloc(sizeof(Node));
			fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",p->worker.num,p->worker.namepin,p->worker.name,p->worker.nation,p->worker.sex,p->worker.birth,p->worker.workday,p->worker.education,p->worker.position,p->worker.addr,p->worker.phone,p->worker.salary);
			
		}
		fclose(fp);
	
}
int next(Node*worker)
{
	printf("*******************************************************************************************\n");
	printf("返回主菜单：1；退出系统：0\n");
	int nextchoose;
	scanf("%d",&nextchoose);
	while(true)
	{
		if(nextchoose==1)
		{
			system("cls");
			Meun(worker);
		}
		else if(nextchoose==0)
		{
			exit(0);
		}
		else
		{
		printf("输入错误，请重新输入");
		scanf("%d",&nextchoose);
		continue;
		}
	}
}
