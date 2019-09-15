/*************************************************
** Դ�ļ�   : score.c
** ����˵�� : Function Definitions
** �����汾 : V1.0
/**************************************************/

/*----------------ͷ�ļ�--------------*/
#define  _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "score.h"

/*----------------��������-------------*/

//1.1�ֶ�����ѧ����������
void readData(SS stu[], int N)
{

	printf("�밴�����¸�ʽ����ѧ����Ϣ��ѧ��,����,ƽʱ�ɼ�,ʵ��ɼ�����ĩ�ɼ�\n");

	for (int i = 0; i < N; i++)
	{
		printf("��%d��ѧ��:", i + 1);
		scanf("%s %s %f %f %f", &stu[i].number, &stu[i].name,&stu[i].dailyScore, &stu[i].experimentalScore, &stu[i].finalScore);
		printf("\n");
	}

	printf("------�ɼ�¼�����!--------\n");

}

//1.2���ļ����ȡѧ����������
SS* readDataFromFile(int *N)
{

	printf("\n\n------��һ��: ���ļ���ȡѧ���ĳɼ���Ϣ--------\n\n");

	SS *stu;// �����¿ռ�,��ȡ�ļ��е�ÿ��ѧ����Ϣ

	FILE *fp = NULL;
	int count = 0;
	int index = 0;

	fp = fopen("data.txt", "r");

	//1.��ȡѧ����Ŀ
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

	printf("ѧ����ĿΪ:%d\n", count);


	//2.������ѧ������洢�ռ�
	stu = (SS*)malloc(count * sizeof(SS));


	//3.��ȡÿ��ѧ������Ϣ
	while ((!feof(fp)))
	{

		//�����ļ����ݵ��ڴ�	
		fscanf(fp, "%s%s%f%f\%f\n", (stu[index].number), (stu[index].name), &stu[index].dailyScore, &stu[index].experimentalScore, &stu[index].finalScore);

		//���������ѧ����Ϣ
		printf("* ѧ�ţ�%s	����:%s		ƽʱ�ɼ���%4.2f��		ʵ��ɼ�:%4.2f��	��ĩ�ɼ�:%4.2f��\n", (stu[index].number), (stu[index].name), stu[index].dailyScore, (stu[index].experimentalScore), stu[index].finalScore);

		index++;
	}

	getchar();

	fclose(fp);

	return stu;
}

//2.����N��ѧ�����Ե������ɼ�
void calcuScore(SS stu[], int N)
{


	printf("\n\n------�ڶ���: ����ÿ��ѧ���������ɼ�--------\n\n");

	for (int i = 0; i < N; i++)
	{

		stu[i].generalScore = 0.2*stu[i].dailyScore + 0.2*stu[i].experimentalScore + 0.6*stu[i].finalScore;
		printf("* ѧ�ţ�%s	����:%s		�ܳɼ�:%4.2f��\n", (stu[i].number), (stu[i].name), stu[i].generalScore);

	}

	getchar();
}


//3.���������ɼ�����
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

//4.����һ���ĸ�ʽ���N��ѧ������Ϣ
void printOut(SS stu[], int N)
{

	printf("\n------������: �����ܳɼ����ѧ��������Ϣ!------\n\n");

	for (int i = 0; i < N; i++)
	{

		printf("��%d����Ϣ ѧ�ţ�%s	����:%s		�ܳɼ�:%4.2f��\n", i + 1, &(stu[i].number[0]), &(stu[i].name[0]), stu[i].generalScore);
	}

	getchar();

}

//5.����ѧ�ſɲ�ѯĳ��ѧ���ĳɼ���Ϣ
void inquiry(SS stu[], int N)
{
	int i = 0;
	printf("\n------���Ĳ�: ����ѧ�Ų�ѯĳ��ѧ���ĳɼ���Ϣ!------\n\n");
	char studentnumber[20];
	scanf("%s",studentnumber);
	for ( i = 0; i < N ; i++)
	{
		
		if (strcmp(stu[i].number, studentnumber) == 0)
		{
			printf("��%d����Ϣ ѧ�ţ�%s	����:%s		�ܳɼ�:%4.2f��\n", i + 1, &(stu[i].number[0]), &(stu[i].name[0]), stu[i].generalScore);
			break;
		}
		

	}
	if (i == N) {
		printf("��ѧ�Ų�����");
	}
	getchar();

}

//6.ͳ��ȫ��ѧ���ɼ��ľ�ֵ�ͱ�׼������Գɼ��ֲ���Ҫ����
	void analyse(SS stu[], int N)
 {

	printf("\n------���岽: ͳ��ȫ��ѧ���ɼ��ľ�ֵ�ͱ�׼������Գɼ��ֲ���Ҫ����------\n\n");
	int total = 0;
	//����ȫ��ѧ���ɼ��ľ�ֵ
	for (int i = 0; i < N; i++)
	{
		total = total + stu[i].generalScore;
	}
	int average = total / N;
	printf("ȫ��ѧ���ɼ��ľ���Ϊ:%d\n", average);
	
	//����ȫ��ͬѧ�ı�׼����
	int f = 0;
	int i = 0;
	for (i = 0; i< N; i++)
	{
		i = i + pow(stu[i].generalScore - average, 2);
	}
	f = i / N;
	float variance = sqrt(f);
	printf("ȫ��ѧ���ɼ��ı�׼����Ϊ:%d\n", variance);
	
	//�Գɼ��ֲ���Ҫ����
	if (abs(variance) < 1)
	{
		printf("�ð�ѧ���ɼ���Ϊ����");
	}
	else {
		printf("�ð�ѧ���ɼ���ɢ");
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
		printf("�ð�ѧ���ɼ���90�ּ����ϵ������϶�");
	}
	else {
		printf("�ð�ѧ���ɼ���90�����µ������϶�");
	}

	getchar();
}