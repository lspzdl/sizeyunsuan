#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int Num[20], NumMax, OperatorLength, NumCount; //Num������������NumMaxΪ�������ֵ��OperatorLengthΪ��ʽ�ĳ���	
	int  n, z = 0;
	int OperatorNum;//���������
	int IntIndex1, IntIndex2;  //int��������λ��
	int  FloatIndex1, FloatIndex2; //Float��������λ��
	char Operator[6], OperatorTerm;//b[]Ϊ������洢����
	float FloatNum1, FloatNum2;
	int FileFlag = 2, FloatFlag;
	printf("��������Ҫ���Ƶ���Ŀ����:\n");
	scanf_s("%d", &NumCount);
	printf("�����������������㷶Χ:\n");
	scanf_s("%d", &NumMax);
	printf("������������Ҫ�����������:\n");
	scanf_s("%d", &OperatorNum);
	printf("��������Ҫ����������:\n");
	for (int OperatorI = 0; OperatorI < OperatorNum; OperatorI++) {
		cin >> Operator[OperatorI];
	}
	srand((unsigned)time(NULL));
	printf("���ʹ��С��������1����������2\n");
	scanf_s("%d", &FloatFlag);
	printf("��ѡ���Ƿ񽫽�����뵽�ĵ��У�1�����ǣ�2�����\n");
	scanf_s("%d", &FileFlag);
	if (FileFlag == 1) {
		printf("�����ĵ��ĵ�ַΪ: D:\\C.txt\n");
	}
	FILE *fp = fopen("D:\\C.txt", "a+");
	for (int t = 0; t < NumCount; t++)
	{
		char buffer[50];
		z = 0;
		OperatorLength = rand() % 7;//ÿ����ʽ�ĳ���
		if (OperatorLength <= 2)
			OperatorLength = 3;

		for (int i = 0; i <= OperatorLength; i++)
		{

			Num[i] = rand() % NumMax + 1;
		}
		int j = 0;
		IntIndex1 = rand() % OperatorLength; if (IntIndex1 >= OperatorLength - 2)IntIndex1 = IntIndex1 - 2; if (IntIndex1 < 0)IntIndex1 = 0;
		IntIndex2 = rand() % OperatorLength; if (IntIndex2 <= IntIndex1 + 2)IntIndex2 = IntIndex1 + 2;
		if (IntIndex1 == 0 && IntIndex2 >= OperatorLength - 1)
			IntIndex1 = IntIndex1 + 1;
		FloatNum1 = (float)rand() / RAND_MAX * NumMax;
		FloatNum2 = (float)rand() / RAND_MAX * NumMax;
		FloatIndex1 = rand() % OperatorLength - 1;
		FloatIndex2 = rand() % OperatorLength - 1;
		for (int i = 0; i < OperatorLength - 1; i++)
		{
			if (i == IntIndex1) {
				printf("(");
				fprintf(fp, "%c", '(');
			}
			if (i == IntIndex2)
			{
				printf("%d", Num[i]);
				fprintf(fp, "%d", Num[i]);
				printf(")");
				fprintf(fp, "%c", ')');
				printf("%c", Operator[j]);
				fprintf(fp, "%c", Operator[j]);
				z = 1;
				i++;
				j++;
				if (j == OperatorNum)j = 0;
			}
			if (FloatFlag == 1 && i == FloatIndex1)
			{
				printf("%.2f%c", FloatNum1, Operator[j]);
				fprintf(fp, "%.2f", FloatNum1);
				fprintf(fp, "%c", Operator[j]);
				j++;
				if (j == OperatorNum)j = 0;
				i++;
				if (i == IntIndex1) {
					printf("(");
					fprintf(fp, "%c", '(');
				}
				if (IntIndex2 == i)
				{
					printf("%d", Num[i]);
					fprintf(fp, "%d", Num[i]);
					printf(")");
					fprintf(fp, "%c", ')');
					printf("%c", Operator[j]);
					fprintf(fp, "%c", Operator[j]);
					z = 1;
					i++;
					j++;
					if (j == OperatorNum)j = 0;
				}
			}

			if (FloatFlag == 1 && i == FloatIndex2)
			{
				printf("%.2f%c", FloatNum2, Operator[j]);
				fprintf(fp, "%.2f", FloatNum2);
				fprintf(fp, "%c", Operator[j]);
				j++;
				if (j == OperatorNum)j = 0;
				i++;
				if (i == IntIndex1) {
					printf("(");
					fprintf(fp, "%c", '(');
				}
				if (IntIndex2 == i)
				{
					printf("%d", Num[i]);
					fprintf(fp, "%d", Num[i]);
					printf(")");
					fprintf(fp, "%c", ')');
					printf("%c", Operator[j]);
					fprintf(fp, "%c", Operator[j]);
					z = 1;
					i++;
					j++;
					if (j == OperatorNum)j = 1;
				}
			}
			printf("%d%c", Num[i], Operator[j]);
			fprintf(fp, "%d", Num[i]);
			fprintf(fp, "%c", Operator[j]);
			j++;
			if (j == OperatorNum)j = 0;
		}

		if (z == 0 && IntIndex2 >= OperatorLength - 1) {
			printf("%d)=\n", Num[OperatorLength]);
			fprintf(fp, "%d", Num[OperatorLength]);
			fprintf(fp, "%c", ')');
			fprintf(fp, "%c", '=');
		}
		else {
			printf("%d=\n", Num[OperatorLength]);
			fprintf(fp, "%d", Num[OperatorLength]);
			fprintf(fp, "%c", '=');
		}
		n = rand() % OperatorNum;
		OperatorTerm = Operator[n];
		Operator[n] = Operator[1];
		Operator[1] = OperatorTerm;

		fprintf(fp, "\n");
	}
	fclose(fp);

	return 0;
}