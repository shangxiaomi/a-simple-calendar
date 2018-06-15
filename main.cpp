/*
作业求过！！！！！满分啊！！！！满分啊！！！！
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
佛祖保佑             永无BUG
佛曰:
写字楼里写字间，写字间里程序员；
程序人员写程序，又拿程序换酒钱。
酒醒只在网上坐，酒醉还来网下眠；
酒醉酒醒日复日，网上网下年复年。
但愿老死电脑间，不愿鞠躬老板前；
奔驰宝马贵者趣，公交自行程序员。
别人笑我忒疯癫，我笑自己命太贱；
不见满街漂亮妹，哪个归得程序员？
##########################################################################################################*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<cstring>
#include <windows.h>
#pragma warning(disable:4996)//如果编译器不是VS把这行代码注释掉
int month_days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };//平年的每月的天数
int month_days_s[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };//闰年的每月的天数
char month_name[14][10] = { "","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Set","Oct","Nov","Dec" };
char week_name[8][10] = { "","Sum","Mon","Tue","Wed","Tur","Fri","Sat" };
bool judge_runnian(int year)//判断是否为闰年，是闰年返回1，不是返回0
{
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))return 1;
	else return 0;
}
int input()//选择功能时输入，有输入的判错
{
	char a[1000];
	scanf("%s", a);
	if (strlen(a) != 1)return -1;
	if (a[0] >= '0'&&a[0] <= '3')return a[0] - '0';
	return -1;
}
void getvalue_function1(int *year, int *month, int *day)//为功能1获取年月日的值
{
	time_t timep;
	struct tm *p;
	time(&timep);
	p = localtime(&timep);
	int year_system = 1900 + p->tm_year;//获取当年系统年份
	int month_system = 1 + p->tm_mon;//获取当前系统月份
	int day_system = p->tm_mday;//获取当前系统的天
	char yea[100], mon[100], da[100];
	int yeart = 0, montht = 0, dayt = 0;
	bool flag = 0;
	printf("请按顺序输入年月日，以空格或者回车为止\n");
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
		}//如果年月日的时间里有非数字字符，则输入一定为非法
		yeart = atoi(yea);//atoi()函数 将字符串转换为数字
		dayt = atoi(da);
		montht = atoi(mon);

		if (yeart < year_system) { flag = 1; goto end; }//输入年份早于系统年份
		if (montht>12 || montht <= 0 || dayt <= 0) { flag = 1; goto end; }//输入月份非法
		if ((judge_runnian(yeart) && dayt>month_days_s[montht]) || (!judge_runnian(yeart) && dayt>month_days[montht])) { flag = 1; goto end; }//此月中没有输入的天
		if ((yeart == year_system && montht == month_system && dayt<day_system) || (yeart == year_system && montht < month_system)) { flag = 1; goto end; }

	end:
		if (flag)
		{
			printf("输入的年月日有误，请重新输入：（注意输入日期的合法性，且日期不能早于今天哦）\n");
			continue;
		}
	} while (flag);//如果输入的数据有误（无此选项，或者有非数字字符，或者输入的日期早于系统时间，都会判错，重新输入时间）
	////测试点
	*year = yeart;
	*month = montht;
	*day = dayt;

}
void getvalue_function3(int *year, int *month)//为功能3获取年月的值
{
	char a[100], b[100];
	bool flag = 0;
	int yea, mon;
	printf("请按顺序输入年月，中间以回车或者空格分开\n");
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
			printf("输入的年月有误，请重新输入：\n");
			continue;
		}
	} while (flag);
	*year = atoi(a);
	*month = mon;
}
int getvalue_function2()//为功能2获取年的值
{
	char a[1000];
	bool flag;
	printf("请输入要打印日历的年份:\n");
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
			printf("您输入的日期有误，请重新输入:\n");
		}
	} while (flag);
	int year = atoi(a);
	printf("\t您选择的年份是%d\n\n", year);
	return year;
}
int ReturnWeekDay(int iYear, int iMonth)//蔡勒公式求星期几 
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

	iWeek = y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d - 1;    //蔡勒公式
	iWeek = iWeek >= 0 ? (iWeek % 7) : (iWeek % 7 + 7);    //iWeek为负时取模
	if (iWeek == 0)    //星期日不作为一周的第一天
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
	getvalue_function1(year, month, day);//获取数据
	//printf("%d %d %d\n", *year, *month, *day);
	int sum_day = 0;
	for (int i = year_system + 1; i < *year; i++)//将整年的天数加起来
	{
		if (judge_runnian(i))sum_day += 366;
		else sum_day += 365;
	}
	//printf("%d\n", sum_day);//
	if (year_system == *year)//输入年份等于系统时间的年份
	{
		if (month_system == *month)sum_day = sum_day + *day - day_system;//输入的月份等于系统的月份
		else
		{
			if (judge_runnian(*year)) {//判断是否为闰年
				for (int i = month_system + 1; i < *month; i++)
					sum_day += month_days_s[i];//把整月的天数加起来
				sum_day += month_days_s[*month] - day_system - 1;//把系统月份的时间剩下的天数加起来
			}
			else {
				for (int i = month_system + 1; i < *month; i++)
					sum_day += month_days[i];//把整月的天数加起来
				sum_day += month_days[*month] - day_system - 1;//把系统月份的时间剩下的天数加起来
			}
			sum_day += *day;//把输入的天数加起来
		}
	}
	else {//输入年份不等于系统年份
		if (judge_runnian(*year)) {//输入的年份是闰年
			for (int i = 1; i < *month; i++)sum_day += month_days_s[i];//把输入年份的天数加起来
			sum_day += *day;
		}
		else {
			for (int i = 1; i < *month; i++)sum_day += month_days[i];
			sum_day += *day;
		}
		if (judge_runnian(year_system)) {//系统的年份是闰年
			for (int i = month_system + 1; i <= 12; i++)sum_day += month_days_s[i];//把系统的年份剩下的天数加起来
			sum_day += month_days_s[month_system] - day_system;
		}
		else {
			for (int i = month_system + 1; i <= 12; i++)sum_day += month_days_s[i];
			sum_day += month_days[month_system] - day_system;
		}
	}
	printf("\n\n\t%d-%d-%d距离今天有%d天\n\n\n\n\n", *year, *month, *day, sum_day);//输出
	delete year;
	delete month;
	delete day;//释放
}
void function2()
{
	int year = getvalue_function2();//为功能2获取年份
	FILE*fp;
	fp = fopen("abc.txt", "wb");//打开文件
	if (NULL == fp)
	{
		printf("抱歉，文件打开有误，请联系软件开发者\n");
		return;//打开空文件指针要返回错误代码
	}
	fprintf(fp, "-----------------------------------------%d-------------------------------------------\r\n", year);
	int riqi[7][50];
	int t[4];
	for (int i = 0; i < 4; i++) {//每次并排输出一个季度的日历
		fprintf(fp, "%s", month_name[i * 3 + 1]);//打印月份的名称
		for (int j = 0; j < 27; j++)fprintf(fp, " ");
		fprintf(fp, "%s", month_name[i * 3 + 2]);
		for (int j = 0; j < 27; j++)fprintf(fp, " ");
		fprintf(fp, "%s", month_name[i * 3 + 3]);
		fprintf(fp, "\r\n");
		for (int j = 1; j <= 7; j++)fprintf(fp, " %s", week_name[j]);//打印周几的名称
		fprintf(fp, "  ");
		for (int j = 1; j <= 7; j++)fprintf(fp, " %s", week_name[j]);
		fprintf(fp, "  ");
		for (int j = 1; j <= 7; j++)fprintf(fp, " %s", week_name[j]);
		fprintf(fp, "\r\n");
		memset(riqi, 0, sizeof(riqi));//填充数组
		for (int j = 1; j <= 3; j++) {
			t[j] = ReturnWeekDay(year, i * 3 + j);//判断此年此月的第一天是周几
		}
		int l[3] = { 0 };//记录当前这个季度三个月的日历的行数
		for (int j = 0; j < 3; j++)
		{

			if (t[j + 1] != 7) {//如果第一天是不是周一，则把周几前的日期填充为0
				for (int m = 0; m < t[j + 1]; m++)
					riqi[0][m + j * 7] = 0;
				l[j] = 1;//此月的行加1
			}
			if (judge_runnian(year)) {//如果此年为闰年
				for (int m = 1; m <= month_days_s[3 * i + j + 1]; m++, t[j + 1]++) {//把此月相应的数组区域填充成第几号 ，下同
					if (t[j + 1] % 7 == 0)l[j]++;//逢七行数加1
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
		for (int h = 0; h <= 6; h++) {//将此季度日历同时打印拿出来
			for (int j = 0; j < 3; j++) {//每个月
				for (int l = 0; l < 7; l++) {//每周
					if (riqi[h][l + j * 7] != 0)fprintf(fp, "%4d", riqi[h][l + j * 7]);
					else fprintf(fp, "    ");
					if (l == 6 && j != 2)fprintf(fp, "  ");
				}
			}
			fprintf(fp, "\r\n");
		}
	}
	printf("%d年的日历已输入到“abc.txt”中，请查看\n\n\n", year);
	fclose(fp);
}
void function3()
{
	int *year = new int;
	int *month = new int;
	getvalue_function3(year, month);
	int t = ReturnWeekDay(*year, *month);
	printf("\n\t%d年%d月的日历为\n", *year, *month);
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
	time(&t);//获取系统时间
	printf("\t雨霖铃 \n\t柳永\n寒蝉凄切，对长亭晚，骤雨初歇。\n都门帐饮无绪，留恋处, 兰舟催发。\n执手相看泪眼，竟无语凝噎。\n念去去，千里烟波，暮霭沉沉楚天阔。\n多情自古伤离别，更那堪, 冷落清秋节, 今宵酒醒何处。\n杨柳岸, 晓风残月。\n此去经年，应是良辰好景虚设。\n便纵有千种风情，更与何人说。\n"); 
	printf("-------------------------------------\n\t系统时间为 %s  \n", ctime(&t));
	printf("\t作者:shangxiaomi\n\t啦啦啦，欢迎使用我写的日历程序哦\n\t好使的话给我点打赏吧\n\tQQ:724900708\n-------------------------------------\n");
	int choose;
	do
	{
		printf("---------------------------------------本程序有以下功能---------------------------------\n");
		printf("\t\t0:退出程序\n");
		printf("\t\t1:输入未来的一个日期，输出距离今天有多久\n");
		printf("\t\t2:输入一个年份，将该年日历输出到文件中\n");
		printf("\t\t3:输入年份月份,将此年此月的日历输出到屏幕中\n");
		printf("请输入你的选择:\n");
		do {
			choose = input();
			if (choose == -1)
			{
				printf("选择有错误，请按说明重新输入:\n");
			}
		} while (choose == -1);
		printf("------------------------------\n");
		printf("您的选择为功能%d\n\n", choose);

		switch (choose)
		{
		case 0: {
			printf("程序已经退出，欢迎下次使用！再见！\n");
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
