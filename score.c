/*************************************************
** 源文件   : score.c
** 功能说明 : Function Definitions
** 创建版本 : V1.0
/**************************************************/

/*----------------头文件--------------*/
#define  _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "score.h"

/*----------------函数定义-------------*/

//1.1手动输入学生基本数据
void readData(SS stu[], int N)
{

	printf("请按照如下格式输入学生信息：学号,姓名,平时成绩,实验成绩，期末成绩\n");

	for (int i = 0; i < N; i++)
	{
		printf("第%d个学生:", i + 1);
		scanf("%s %s %f %f %f", &stu[i].number, &stu[i].name,&stu[i].dailyScore, &stu[i].experimentalScore, &stu[i].finalScore);
		printf("\n");
	}

	printf("------成绩录入完毕!--------\n");

}

//1.2从文件里读取学生基本数据
SS* readDataFromFile(int *N)
{

	printf("\n\n------第一步: 从文件读取学生的成绩信息--------\n\n");

	SS *stu;// 开辟新空间,存取文件中的每个学生信息

	FILE *fp = NULL;
	int count = 0;
	int index = 0;

	fp = fopen("data.txt", "r");

	//1.获取学生数目
	if (fp != NULL)
	{
		fscanf(fp, "%d", &count);
		*N = count;
	}
	else
	{
		printf("failed to open the info file\n");
		getchar();
	}

	printf("学生数目为:%d\n", count);


	//2.给所有学生分配存储空间
	stu = (SS*)malloc(count * sizeof(SS));


	//3.读取每条学生的信息
	while ((!feof(fp)))
	{

		//读入文件数据到内存	
		fscanf(fp, "%s%s%f%f\%f\n", (stu[index].number), (stu[index].name), &stu[index].dailyScore, &stu[index].experimentalScore, &stu[index].finalScore);

		//输出排序后的学生信息
		printf("* 学号：%s	姓名:%s		平时成绩：%4.2f分		实验成绩:%4.2f分	期末成绩:%4.2f分\n", (stu[index].number), (stu[index].name), stu[index].dailyScore, (stu[index].experimentalScore), stu[index].finalScore);

		index++;
	}

	getchar();

	fclose(fp);

	return stu;
}

//2.计算N个学生各自的总评成绩
void calcuScore(SS stu[], int N)
{


	printf("\n\n------第二步: 计算每个学生的总评成绩--------\n\n");

	for (int i = 0; i < N; i++)
	{

		stu[i].generalScore = 0.2*stu[i].dailyScore + 0.2*stu[i].experimentalScore + 0.6*stu[i].finalScore;
		printf("* 学号：%s	姓名:%s		总成绩:%4.2f分\n", (stu[i].number), (stu[i].name), stu[i].generalScore);

	}

	getchar();
}


//3.根据总评成绩排名
int cmpBigtoSmall(const void *a, const void *b)
{

	SS *aa = (SS *)(a);
	SS *bb = (SS *)(b);



	if ((*aa).generalScore < (*bb).generalScore)  return 1;

	else if ((*aa).generalScore > (*bb).generalScore)  return -1;

	else
		return 0;

}

void sortScore(SS stu[], int N)
{

	qsort(&(stu[0]), N, sizeof(stu[0]), cmpBigtoSmall);

}

//4.按照一定的格式输出N个学生的信息
void printOut(SS stu[], int N)
{

	printf("\n------第三步: 根据总成绩输出学生排名信息!------\n\n");

	for (int i = 0; i < N; i++)
	{

		printf("第%d名信息 学号：%s	姓名:%s		总成绩:%4.2f分\n", i + 1, &(stu[i].number[0]), &(stu[i].name[0]), stu[i].generalScore);
	}

	getchar();

}

//5.输入学号可查询某个学生的成绩信息
void inquiry(SS stu[], int N)
{
	int i = 0;
	printf("\n------第四步: 根据学号查询某个学生的成绩信息!------\n\n");
	char studentnumber[20];
	scanf("%s",studentnumber);
	for ( i = 0; i < N ; i++)
	{
		
		if (strcmp(stu[i].number, studentnumber) == 0)
		{
			printf("第%d名信息 学号：%s	姓名:%s		总成绩:%4.2f分\n", i + 1, &(stu[i].number[0]), &(stu[i].name[0]), stu[i].generalScore);
			break;
		}
		

	}
	if (i == N) {
		printf("该学号不存在");
	}
	getchar();

}

//6.统计全班学生成绩的均值和标准方差，并对成绩分布简要分析
	void analyse(SS stu[], int N)
 {

	printf("\n------第五步: 统计全班学生成绩的均值和标准方差，并对成绩分布简要分析------\n\n");
	int total = 0;
	//计算全班学生成绩的均值
	for (int i = 0; i < N; i++)
	{
		total = total + stu[i].generalScore;
	}
	int average = total / N;
	printf("全班学生成绩的均分为:%d\n", average);
	
	//计算全班同学的标准方差
	int f = 0;
	int i = 0;
	for (i = 0; i< N; i++)
	{
		i = i + pow(stu[i].generalScore - average, 2);
	}
	f = i / N;
	float variance = sqrt(f);
	printf("全班学生成绩的标准方差为:%d\n", variance);
	
	//对成绩分布简要分析
	if (abs(variance) < 1)
	{
		printf("该班学生成绩较为集中");
	}
	else {
		printf("该班学生成绩分散");
	}
	int j=0 ;
	int k=0 ;
	
	for (int i = 0; i < N; i++) 
	{
		if (stu[i].generalScore >= 90)
		{
			j++;
		}
		else{
			k++;
		}
	}
	if (j > k) {
		printf("该班学生成绩在90分及以上的人数较多");
	}
	else {
		printf("该班学生成绩在90分以下的人数较多");
	}

	getchar();
}