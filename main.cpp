/*
��ҵ����������������ְ������������ְ���������
##########################################################################################################
				  _ooOoo_
				 o8888888o
				 88" . "88
				 (| -_- |)
				  O\ = /O
			  ____/`---'\____
			.   ' \\| |// `.
             / \\||| : |||// \
           / _||||| -:- |||||- \
             | | \\\ - /// | |
            | \_| ''\---/'' | |
             \ .-\__ `-` ___/-. /
          ___`. .' /--.--\ `. . __
       ."" '< `.___\_<|>_/___.' >'"".
      | | : `- \`.;`\ _ /`;.`/ - ` : | |
        \ \ `-. \_ __\ /__ _/ .-` / /
======`-.____`-.___\_____/___.-`____.-'======
`=---='
.............................................
���汣��             ����BUG
��Ի:
д��¥��д�ּ䣬д�ּ������Ա��
������Աд�������ó��򻻾�Ǯ��
����ֻ���������������������ߣ�
��������ո��գ����������긴�ꡣ
��Ը�������Լ䣬��Ը�Ϲ��ϰ�ǰ��
���۱������Ȥ���������г���Ա��
����Ц��߯��񲣬��Ц�Լ���̫����
��������Ư���ã��ĸ���ó���Ա��
##########################################################################################################*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<cstring>
#include <windows.h>
#pragma warning(disable:4996)//�������������VS�����д���ע�͵�
int month_days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };//ƽ���ÿ�µ�����
int month_days_s[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };//�����ÿ�µ�����
char month_name[14][10] = { "","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Set","Oct","Nov","Dec" };
char week_name[8][10] = { "","Sum","Mon","Tue","Wed","Tur","Fri","Sat" };
bool judge_runnian(int year)//�ж��Ƿ�Ϊ���꣬�����귵��1�����Ƿ���0
{
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))return 1;
	else return 0;
}
int input()//ѡ����ʱ���룬��������д�
{
	char a[1000];
	scanf("%s", a);
	if (strlen(a) != 1)return -1;
	if (a[0] >= '0'&&a[0] <= '3')return a[0] - '0';
	return -1;
}
void getvalue_function1(int *year, int *month, int *day)//Ϊ����1��ȡ�����յ�ֵ
{
	time_t timep;
	struct tm *p;
	time(&timep);
	p = localtime(&timep);
	int year_system = 1900 + p->tm_year;//��ȡ����ϵͳ���
	int month_system = 1 + p->tm_mon;//��ȡ��ǰϵͳ�·�
	int day_system = p->tm_mday;//��ȡ��ǰϵͳ����
	char yea[100], mon[100], da[100];
	int yeart = 0, montht = 0, dayt = 0;
	bool flag = 0;
	printf("�밴˳�����������գ��Կո���߻س�Ϊֹ\n");
	do {
		flag = 0;
		scanf("%s%s%s", yea, mon, da);
		for (int i = 0; i < strlen(yea); i++)
		{
			if (yea[i] < '0' || yea[i] > '9') {
				flag = 1;
				goto end;
			}
		}
		for (int i = 0; i < strlen(mon); i++)
		{
			if (mon[i] < '0' || mon[i] > '9') {
				flag = 1;
				goto end;
			}
		}
		for (int i = 0; i < strlen(da); i++)
		{
			if (da[i] < '0' || da[i] > '9') {
				flag = 1;
				goto end;
			}
		}//��������յ�ʱ�����з������ַ���������һ��Ϊ�Ƿ�
		yeart = atoi(yea);//atoi()���� ���ַ���ת��Ϊ����
		dayt = atoi(da);
		montht = atoi(mon);

		if (yeart < year_system) { flag = 1; goto end; }//�����������ϵͳ���
		if (montht>12 || montht <= 0 || dayt <= 0) { flag = 1; goto end; }//�����·ݷǷ�
		if ((judge_runnian(yeart) && dayt>month_days_s[montht]) || (!judge_runnian(yeart) && dayt>month_days[montht])) { flag = 1; goto end; }//������û���������
		if ((yeart == year_system && montht == month_system && dayt<day_system) || (yeart == year_system && montht < month_system)) { flag = 1; goto end; }

	end:
		if (flag)
		{
			printf("������������������������룺��ע���������ڵĺϷ��ԣ������ڲ������ڽ���Ŷ��\n");
			continue;
		}
	} while (flag);//�����������������޴�ѡ������з������ַ��������������������ϵͳʱ�䣬�����д���������ʱ�䣩
	////���Ե�
	*year = yeart;
	*month = montht;
	*day = dayt;

}
void getvalue_function3(int *year, int *month)//Ϊ����3��ȡ���µ�ֵ
{
	char a[100], b[100];
	bool flag = 0;
	int yea, mon;
	printf("�밴˳���������£��м��Իس����߿ո�ֿ�\n");
	do
	{
		scanf("%s%s", a, b);
		flag = 0;
		for (int i = 0; i<strlen(a); i++) {
			if (a[i]>'9' || a[i]<'0') { flag = 1; break; }
		}
		for (int i = 0; i<strlen(b) && flag == 0; i++) {
			if (b[i]>'9' || b[i]<'0') { flag = 1; break; }
		}
		if (flag == 0) {
			mon = atoi(b);
			if (mon>12 || mon<1) { flag = 1; }
		}
		if (flag)
		{
			printf("����������������������룺\n");
			continue;
		}
	} while (flag);
	*year = atoi(a);
	*month = mon;
}
int getvalue_function2()//Ϊ����2��ȡ���ֵ
{
	char a[1000];
	bool flag;
	printf("������Ҫ��ӡ���������:\n");
	do {
		flag = 0;
		scanf("%s", a);
		for (int i = 0; i<strlen(a); i++)
		{
			if (a[i] > '9' || a[i] < '0') {
				flag = 1; break;
			}
		}
		if (flag) {
			printf("�������������������������:\n");
		}
	} while (flag);
	int year = atoi(a);
	printf("\t��ѡ��������%d\n\n", year);
	return year;
}
int ReturnWeekDay(int iYear, int iMonth)//���չ�ʽ�����ڼ� 
{
	int iDay = 1;
	int iWeek = 0;
	int y = 0, c = 0, m = 0, d = 0;

	if (iMonth == 1 || iMonth == 2)
	{
		c = (iYear - 1) / 100;
		y = (iYear - 1) % 100;
		m = iMonth + 12;
		d = iDay;
	}
	else
	{
		c = iYear / 100;
		y = iYear % 100;
		m = iMonth;
		d = iDay;
	}

	iWeek = y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d - 1;    //���չ�ʽ
	iWeek = iWeek >= 0 ? (iWeek % 7) : (iWeek % 7 + 7);    //iWeekΪ��ʱȡģ
	if (iWeek == 0)    //�����ղ���Ϊһ�ܵĵ�һ��
	{
		iWeek = 7;
	}

	return iWeek;
}
void function1()
{
	int *year = new int;
	int *month = new int;
	int *day = new int;
	time_t timep;
	struct tm *p;
	time(&timep);
	p = localtime(&timep);
	int year_system = 1900 + p->tm_year;
	int month_system = 1 + p->tm_mon;
	int day_system = p->tm_mday;
	getvalue_function1(year, month, day);//��ȡ����
	//printf("%d %d %d\n", *year, *month, *day);
	int sum_day = 0;
	for (int i = year_system + 1; i < *year; i++)//�����������������
	{
		if (judge_runnian(i))sum_day += 366;
		else sum_day += 365;
	}
	//printf("%d\n", sum_day);//
	if (year_system == *year)//������ݵ���ϵͳʱ������
	{
		if (month_system == *month)sum_day = sum_day + *day - day_system;//������·ݵ���ϵͳ���·�
		else
		{
			if (judge_runnian(*year)) {//�ж��Ƿ�Ϊ����
				for (int i = month_system + 1; i < *month; i++)
					sum_day += month_days_s[i];//�����µ�����������
				sum_day += month_days_s[*month] - day_system - 1;//��ϵͳ�·ݵ�ʱ��ʣ�µ�����������
			}
			else {
				for (int i = month_system + 1; i < *month; i++)
					sum_day += month_days[i];//�����µ�����������
				sum_day += month_days[*month] - day_system - 1;//��ϵͳ�·ݵ�ʱ��ʣ�µ�����������
			}
			sum_day += *day;//�����������������
		}
	}
	else {//������ݲ�����ϵͳ���
		if (judge_runnian(*year)) {//��������������
			for (int i = 1; i < *month; i++)sum_day += month_days_s[i];//��������ݵ�����������
			sum_day += *day;
		}
		else {
			for (int i = 1; i < *month; i++)sum_day += month_days[i];
			sum_day += *day;
		}
		if (judge_runnian(year_system)) {//ϵͳ�����������
			for (int i = month_system + 1; i <= 12; i++)sum_day += month_days_s[i];//��ϵͳ�����ʣ�µ�����������
			sum_day += month_days_s[month_system] - day_system;
		}
		else {
			for (int i = month_system + 1; i <= 12; i++)sum_day += month_days_s[i];
			sum_day += month_days[month_system] - day_system;
		}
	}
	printf("\n\n\t%d-%d-%d���������%d��\n\n\n\n\n", *year, *month, *day, sum_day);//���
	delete year;
	delete month;
	delete day;//�ͷ�
}
void function2()
{
	int year = getvalue_function2();//Ϊ����2��ȡ���
	FILE*fp;
	fp = fopen("abc.txt", "wb");//���ļ�
	if (NULL == fp)
	{
		printf("��Ǹ���ļ�����������ϵ���������\n");
		return;//�򿪿��ļ�ָ��Ҫ���ش������
	}
	fprintf(fp, "-----------------------------------------%d-------------------------------------------\r\n", year);
	int riqi[7][50];
	int t[4];
	for (int i = 0; i < 4; i++) {//ÿ�β������һ�����ȵ�����
		fprintf(fp, "%s", month_name[i * 3 + 1]);//��ӡ�·ݵ�����
		for (int j = 0; j < 27; j++)fprintf(fp, " ");
		fprintf(fp, "%s", month_name[i * 3 + 2]);
		for (int j = 0; j < 27; j++)fprintf(fp, " ");
		fprintf(fp, "%s", month_name[i * 3 + 3]);
		fprintf(fp, "\r\n");
		for (int j = 1; j <= 7; j++)fprintf(fp, " %s", week_name[j]);//��ӡ�ܼ�������
		fprintf(fp, "  ");
		for (int j = 1; j <= 7; j++)fprintf(fp, " %s", week_name[j]);
		fprintf(fp, "  ");
		for (int j = 1; j <= 7; j++)fprintf(fp, " %s", week_name[j]);
		fprintf(fp, "\r\n");
		memset(riqi, 0, sizeof(riqi));//�������
		for (int j = 1; j <= 3; j++) {
			t[j] = ReturnWeekDay(year, i * 3 + j);//�жϴ�����µĵ�һ�����ܼ�
		}
		int l[3] = { 0 };//��¼��ǰ������������µ�����������
		for (int j = 0; j < 3; j++)
		{

			if (t[j + 1] != 7) {//�����һ���ǲ�����һ������ܼ�ǰ���������Ϊ0
				for (int m = 0; m < t[j + 1]; m++)
					riqi[0][m + j * 7] = 0;
				l[j] = 1;//���µ��м�1
			}
			if (judge_runnian(year)) {//�������Ϊ����
				for (int m = 1; m <= month_days_s[3 * i + j + 1]; m++, t[j + 1]++) {//�Ѵ�����Ӧ�������������ɵڼ��� ����ͬ
					if (t[j + 1] % 7 == 0)l[j]++;//����������1
					riqi[l[j]][t[j + 1] % 7 + 7 * j] = m;
				}
			}
			else {
				for (int m = 1; m <= month_days[3 * i + j + 1]; m++, t[j + 1]++) {
					if (t[j + 1] % 7 == 0)l[j]++;
					riqi[l[j]][t[j + 1] % 7 + 7 * j] = m;
				}
			}
		}
		for (int h = 0; h <= 6; h++) {//���˼�������ͬʱ��ӡ�ó���
			for (int j = 0; j < 3; j++) {//ÿ����
				for (int l = 0; l < 7; l++) {//ÿ��
					if (riqi[h][l + j * 7] != 0)fprintf(fp, "%4d", riqi[h][l + j * 7]);
					else fprintf(fp, "    ");
					if (l == 6 && j != 2)fprintf(fp, "  ");
				}
			}
			fprintf(fp, "\r\n");
		}
	}
	printf("%d������������뵽��abc.txt���У���鿴\n\n\n", year);
	fclose(fp);
}
void function3()
{
	int *year = new int;
	int *month = new int;
	getvalue_function3(year, month);
	int t = ReturnWeekDay(*year, *month);
	printf("\n\t%d��%d�µ�����Ϊ\n", *year, *month);
	for (int j = 1; j <= 7; j++)printf(" %s", week_name[j]);
	printf("\n");
	if (t != 7)
	{
		for (int i = 0; i<t; i++)printf("    ");
	}
	if (judge_runnian(*year)) {
		for (int m = 1; m <= month_days_s[*month]; m++, t++)
		{
			if (t % 7 == 0)printf("\n");
			printf("|%3d", m);
		}
	}
	else {
		for (int m = 1; m <= month_days[*month]; m++, t++)
		{
			if (t % 7 == 0)printf("\n");
			printf("|%3d", m);
		}
	}
	printf("\n\n");
}
int main()
{
	time_t t;
	time(&t);//��ȡϵͳʱ��
	printf("\t������ \n\t����\n�������У��Գ�ͤ�������Ъ��\n��������������������, ���۴߷���\nִ���࿴���ۣ���������ҭ��\n��ȥȥ��ǧ���̲���ĺ��������������\n�����Թ�����𣬸��ǿ�, ���������, �������Ѻδ���\n������, ������¡�\n��ȥ���꣬Ӧ�������þ����衣\n������ǧ�ַ��飬�������˵��\n"); 
	printf("-------------------------------------\n\tϵͳʱ��Ϊ %s  \n", ctime(&t));
	printf("\t����:shangxiaomi\n\t����������ӭʹ����д����������Ŷ\n\t��ʹ�Ļ����ҵ���Ͱ�\n\tQQ:724900708\n-------------------------------------\n");
	int choose;
	do
	{
		printf("---------------------------------------�����������¹���---------------------------------\n");
		printf("\t\t0:�˳�����\n");
		printf("\t\t1:����δ����һ�����ڣ������������ж��\n");
		printf("\t\t2:����һ����ݣ�����������������ļ���\n");
		printf("\t\t3:��������·�,��������µ������������Ļ��\n");
		printf("���������ѡ��:\n");
		do {
			choose = input();
			if (choose == -1)
			{
				printf("ѡ���д����밴˵����������:\n");
			}
		} while (choose == -1);
		printf("------------------------------\n");
		printf("����ѡ��Ϊ����%d\n\n", choose);

		switch (choose)
		{
		case 0: {
			printf("�����Ѿ��˳�����ӭ�´�ʹ�ã��ټ���\n");
			return 0;
		}
		case 1: {
			function1();
			break;
		}
		case 2: {
			function2();
			break;
		}
		case 3: {
			function3();
			break;
		}
		}
	} while (choose);
	system("pause");
	return 0;
}
