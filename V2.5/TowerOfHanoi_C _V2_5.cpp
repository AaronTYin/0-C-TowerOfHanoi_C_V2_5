/*
TowerOfHanoi_C V2.5
2020-02-28
*/

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <conio.h>


char StrI[8] = { ' ', ' ', ' ', '|', ' ', ' ', ' ' };	//8用（2*i）+1时显示“烫烫烫乱码”，此数组相当于空层
static char StrN[3][3][8] = { ' ' };					//柱
int i = 0, j = 1, k = 2;
char StrP3[8] = { ' ', ' ', '=', '=', '=', ' ', ' ' };	//小盘
char StrP5[8] = { ' ', '=', '=', '=', '=', '=', ' ' };	//中盘
char StrP7[8] = { '=', '=', '=', '=', '=', '=', '=' };	//大盘
char CH = '\0';

void Menu();		//主界面，包含输入判定
void Show();		//搭建游戏界面，只显示
void Help();		//帮助系统
void Play();		//初始化游戏，进入输入判断算法函数
void Getin();		//输入记录函数
void Judge();		//规则判断函数

int main()
{
	Menu();

	return 0;
}

void Menu()
{
	int M_CH = 0;
	printf("\n\n\n\n\t\t\t     Sakura 汉诺塔V2.5");
	printf("\n\n\n\n\n\t\t\t\t1. 开始游戏\n\n\n\t\t\t\t2. 帮助日志\n\n\n\t\t\t\t3. 退出游戏\n\n");
	M_CH = _getch();
	if (M_CH == '1')
	{
		system("cls");
		Play();
	}
	if (M_CH == '2')
	{
		system("cls");
		Help();
	}
	if (M_CH == '3')
	{
		exit(0);
	}
	else
	{
		printf("\n\n\t\t\t    输入错误，请重新输入!\n");
		int DELAY = 280000000;
		int i = 0;
		for (i = 0; i < DELAY; i++){}
		system("cls");
		Menu();
	}
}

void Show()
{
	printf("\n\tR:  重新开始\tB:  返回主菜单\tQ:  退出游戏\n");
	printf("\n-------------------------------------------------------------------\n");
	printf("\n| |                                                             | |");
	printf("\n| |                                                             | |");
	printf("\n| |                                                             | |");
	printf("\n| |\t\t%s\t\t%s\t\t%s\t\t| |", StrI, StrI, StrI);
	printf("\n| |\t\t%s\t\t%s\t\t%s\t\t| |", StrI, StrI, StrI);
	printf("\n| |\t\t%s\t\t%s\t\t%s\t\t| |", StrI, StrI, StrI);
	printf("\n| |\t\t%s\t\t%s\t\t%s\t\t| |", StrI, StrI, StrI);
	printf("\n| |\t\t%s\t\t%s\t\t%s\t\t| |", StrN[0][0], StrN[1][0], StrN[2][0]);
	printf("\n| |\t\t%s\t\t%s\t\t%s\t\t| |", StrN[0][1], StrN[1][1], StrN[2][1]);
	printf("\n| |\t\t%s\t\t%s\t\t%s\t\t| |", StrN[0][2], StrN[1][2], StrN[2][2]);
	printf("\n| |\t     ---------------------------------------------     \t| |");
	printf("\n| |                                                             | |");
	printf("\n| |                                                             | |");
	printf("\n| |                                                             | |");
	printf("\n-------------------------------------------------------------------\n\n");
}

void Help()
{
	printf("\n\n\n\n\t\t\t游戏帮助：");
	printf("\n\t\t\t\t使用1、2、3按键进行移动，大盘必须在小盘之上");
	printf("\n\n\n\t\t\t升级日志：");
	printf("\n\t\t\t\tV2.5：全面优化核心算法，分离输入捕获与判断系统");
	printf("\n\t\t\t\tV2.0：尝试遍历所有情况进行判断");
	printf("\n\t\t\t\tV1.0：初步判断并移动，大小叠加限制规则未实现，游戏胜利判定有延迟");
	printf("\n\n\n\t\t\t\t\t\t“按任意键返回...”");
	if (_getch())
	{
		system("cls");
		Menu();
	}
}

void Play()
{
	int n = 3;
	int i = 0;
	//printf("请输入层数:");
	//scanf_s("%d", &n);

	strcpy_s(StrN[0][0], StrP3);			//初始化
	strcpy_s(StrN[0][1], StrP5);
	strcpy_s(StrN[0][2], StrP7);
	strcpy_s(StrN[1][0], StrI);
	strcpy_s(StrN[1][1], StrI);
	strcpy_s(StrN[1][2], StrI);
	strcpy_s(StrN[2][0], StrI);
	strcpy_s(StrN[2][1], StrI);
	strcpy_s(StrN[2][2], StrI);
	Show();

	while (1)
	{
		Getin();
	}
}

void Getin()
{
	printf("\n\t\t\t\t输入");
	CH = _getch();													//_getch()实现键盘监测
	//-----------------------------------------------------------------------------------------------------------
	if (CH == '1')
	{
		printf("1");
		CH = _getch();
		if (CH == '2')
		{
			printf("2");
			i = 0; j = 1;
		}
		else if (CH == '3')
		{
			printf("3");
			i = 0; j = 2;
		}
		else
		{
			system("cls");
			Show();
			printf("\n\t\t\t   输入错误，请重新操作\n\n");
			Getin();
		}
	}
	else if (CH == '2')
	{
		printf("2");
		CH = _getch();
		if (CH == '1')
		{
			printf("1");
			i = 1; j = 0;
		}
		else if (CH == '3')
		{
			printf("3");
			i = 1; j = 2;
		}
		else
		{
			system("cls");
			Show();
			printf("\n\t\t\t   输入错误，请重新操作\n\n");
			Getin();
		}
	}
	else if (CH == '3')
	{
		printf("3");
		CH = _getch();
		if (CH == '1')
		{
			printf("1");
			i = 2; j = 0;
		}
		else if (CH == '2')
		{
			printf("2");
			i = 2; j = 1;
		}
		else
		{
			system("cls");
			Show();
			printf("\n\t\t\t   输入错误，请重新操作\n\n");
			Getin();
		}
	}
	//-----------------------------------------------------------------------------------------------------------
	else if (CH == 'q')
	{
		printf("\n\n\n\t\t\t   退出游戏....\n\n");
		exit(0);
	}
	else if (CH == 'r')
	{
		system("cls");
		Play();
	}
	else if (CH == 'b')
	{
		system("cls");
		Menu();
	}
	//-----------------------------------------------------------------------------------------------------------
	else
	{
		system("cls");
		Show();
		printf("\n\t\t\t   输入错误，请重新操作\n\n");
		Getin();
	}
	Judge();
}

void Judge()
{
	//-----------------------------------------------------------------------------------------------------------
	if (strcmp(StrN[i][0], StrI) != 0)						//i柱顶层不为空
	{
		strcpy_s(StrN[j][2], StrN[i][0]);					//i柱顶层移至j柱底层
		strcpy_s(StrN[i][0], StrI);							//i柱顶层制空
		system("cls");										//此处使用iostream
		Show();
		Getin();											//递归调用
	}
	//-----------------------------------------------------------------------------------------------------------
	else if (strcmp(StrN[i][0], StrI) == 0 && strcmp(StrN[i][1], StrI) != 0)	//i柱顶层为空中层不为空
	{
		if (strcmp(StrN[j][2], StrI) == 0)					//j柱底层为空
		{
			strcpy_s(StrN[j][2], StrN[i][1]);				//i柱中层移至j柱底层
			strcpy_s(StrN[i][1], StrI);
			system("cls");
			Show();
			Getin();
		}
		else if (strcmp(StrN[j][2], StrI) != 0)				//j柱底层不为空
		{
			if (strcmp(StrN[i][1], StrP3) == 0)				//i柱中层为小
			{
				strcpy_s(StrN[j][1], StrN[i][1]);			//i柱中层移至j柱中层
				strcpy_s(StrN[i][1], StrI);
				system("cls");
				Show();
				Getin();
			}
			else
			{
				system("cls");
				Show();
				Getin();
			}
		}
		else
		{
			system("cls");
			Show();
			Getin();
		}
	}
	//-----------------------------------------------------------------------------------------------------------
	else if (strcmp(StrN[i][1], StrI) == 0)					//i柱中层为空
	{
		if (strcmp(StrN[j][1], StrP5) == 0)					//j柱中层为中
		{
			strcpy_s(StrN[j][0], StrN[i][2]);				//i柱底层小移至j柱顶层
			strcpy_s(StrN[i][2], StrI);
			system("cls");
			Show();

			printf("\n\n\t\t\t游戏成功!\n\n");
			printf("\t1.  重新开始\tN.  返回主菜单\t0.  退出游戏\n\n");
			CH = _getch();
			if (CH == '1')
			{
				system("cls");
				Play();
			}
			else if (CH == '0')
			{
				exit(0);
			}
			else
			{
				system("cls");
				Menu();
			}
		}
		else if (strcmp(StrN[j][1], StrI) == 0)				//j柱中层为空
		{
			if (strcmp(StrN[j][2], StrI) == 0)				//j柱底层为空
			{
				strcpy_s(StrN[j][2], StrN[i][2]);			//i柱底层移至j柱底层
				strcpy_s(StrN[i][2], StrI);
				system("cls");
				Show();
				Getin();
			}
			else if (strcmp(StrN[j][2], StrI) != 0)			//j柱底层不为空
			{
				if (strcmp(StrN[j][2], StrP7) == 0 || (strcmp(StrN[j][2], StrP5) == 0 && strcmp(StrN[i][2], StrP3) == 0))	//j柱底层为大，或j柱底层为中且i柱底层为小
				{
				
					strcpy_s(StrN[j][1], StrN[i][2]);		//i柱底层移至j柱中层
					strcpy_s(StrN[i][2], StrI);
					system("cls");
					Show();
					Getin();
				}
				else
				{
					system("cls");
					Show();
					Getin();
				}
			}
			else
			{
				system("cls");
				Show();
				Getin();
			}
		}
		else
		{
			system("cls");
			Show();
			Getin();
		}
	}
	else
	{
		system("cls");
		Show();
		Getin();
	}
}
