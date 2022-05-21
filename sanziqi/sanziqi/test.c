#define _CRT_SECURE_NO_WARNINGS 1 
//������������Ϸ

//#include <stdio.h>ֱ�ӷ�game.h����
#include "game.h"

void menu()
{
	printf("========================================================\n");
	printf("=           <1>start            <0>exit                =\n");
	printf("========================================================\n");
}

//��Ϸ�������㷨ʵ��
void game()
{
	//����--����߳���������Ϣ
	char board[ROW][COL] = { 0 };//ϣ�����̿ո�
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	//����
	char ret = 0;
	while (1)
	{
		
		//�������
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//��������
		ComputerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//�жϵ����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("You Win!\n");
	}
	else if (ret == '#')
	{
		printf("You Lost!\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));//ʱ�����Ϊ������ĳ�ʼֵ��ͷ�ļ�<stdlib.h>��<time.h>
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				printf("��ʼ��Ϸ\n");
				game();
				break;
			case 0:
				printf("�˳���Ϸ\n");
				break;
			default:
				printf("ѡ�����������ѡ��\n");
				break;

		}
	} while (input);
}

int main()
{
	test();
	return 0;
}