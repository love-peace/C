#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h> 
#include<time.h>
#define MAXX 40//限制长
#define MAXY 40//限制宽


void ShowMenu();
void StartGame();
void Set();
void GameIntro();
void MaxScore();
void InitMap();
void PrintMap(); 
void Help();
void SetRandNum();
void SetSnakeNum();
void EatFood(); 
void gotoxy(int x, int y);

int mapArr[MAXX][MAXY];//  定义二维数组储存地图属性
int inputX=20;//默认地图长
int inputY=20;//默认地图宽
int MaxS=0;//最高分
int speed=5;//默认移动速度
int randX=0, randY =0;        //随机食物横纵坐标
int foodFlag=0;//判断食物是否存在的标志，为1时食物存在，为0时食物不存在
int BodyX= 1, BodyY= 1;	//头坐标
int Length=0;//蛇身长
char input = 'd';    //默认移动方向
int overFlag=1;   //判断游戏是否结束，为0时游戏结束
int *body[MAXX * MAXY];				//蛇身数组指针变量

main()
{
    int id;
	ShowMenu();
	scanf("%d",&id);
	while(1)
	{  
	   if(id==5)
	   	break;
	   switch(id)
	   {
	   case 1:StartGame();break;//游戏开始
	   case 2:Set();break;//设置
	   //case 3:MaxScore();break;//最高分   Max=Length+1    需要增加文件输入与输出： ①读取文件中的最高分   ②游戏结束后判断是否为最高分，并写入文件
	   case 4:GameIntro();break;//游戏介绍
	   default:printf("\n\t\t  输入错误");
	   }
	   getch();
	   ShowMenu();
	   scanf("%d",&id);
	}
	
}

void ShowMenu()
{
	system("cls");
	printf("\n\n\n\n\n");
    printf("\t\t|-----------------GAME-----------------|\n");
	printf("\t\t|\t\t\t\t       |\n");
    printf("\t\t|\t\t1.开始游戏\t       |\n");
    printf("\t\t|\t\t2.设置\t               |\n");
    printf("\t\t|\t\t3.最高分\t       |\n");
    printf("\t\t|\t\t4.游戏介绍\t       |\n");
    printf("\t\t|\t\t5.退出\t\t       |\n");
	printf("\t\t|\t\t\t\t       |\n");
    printf("\t\t|--------------------------------------|\n\n");
    printf("\t\t  请输入选项前的序号（1-5):");
  
}

void StartGame()
{   
   int reFlag=1;
   while(reFlag)
    { int j;
      overFlag=1;
      BodyX= 1;
	  BodyY= 1;
	  Length= 0;
	  input = 'd';
	  for (j = 0; j < Length; j++)             /* assign the snake body initial address value*/
	  {
		body[j] = &mapArr[BodyX - j][BodyY];
	  }

	  system("cls");
	  while(overFlag)
	  {
	 	InitMap();                   //创建地图属性
		SetSnakeNum();               //实现蛇的移动，修改游戏结束判定值overFlag
		SetRandNum();                //随机生成食物
		EatFood();                   //实现蛇吃食物，并增加蛇的长度
		PrintMap();                  //地图生成
		Help();                      //游戏提示 
		Sleep(1000/speed);                 
		gotoxy(0,0);
	  }
	  system("cls");
	  reFlag=0;
	  printf("得分：%d\n",Length);
	  printf("是否重新开始(y/n)？\n");
	  getchar();
	  if(getchar()=='y')
		  reFlag=1;
	}
}

void Set()
{
	int reSet=1;
	system("cls");
    printf("请输入地图的长度（5到40之间的整数）：\n");
    while(reSet)
	 {
	  scanf("%d", &inputX);
	  if((inputX<=MAXX)&&(inputX>4))
	   {
	      printf("\n");
          reSet=0;
	   }
	  else
	     printf("无效输入，请重新输入:\n");
	 }
	reSet=1;
	printf("请输入地图的宽度（5到40之间的整数）：\n");
	while(reSet)
	 {
	  scanf("%d", &inputY);
	  if((inputY<=MAXY)&&(inputY>4))
	   {
	      printf("\n");
          reSet=0;
	   }
	  else
	     printf("无效输入，请重新输入:\n");
	 }
	printf("\n");
	printf("请输入移动速度（1 到 n，1最慢）：\n");
	scanf("%d", &speed);
}

void GameIntro()
{
   system("cls");
   printf("游戏介绍:");
}

void InitMap()
{
	int X, Y;
	for (Y= 0;Y< inputY;Y++)
	{
		for (X= 0;X< inputX;X++)

		{
			if ((X== 0) || (X== inputX - 1) || (Y== 0) || (Y== inputY - 1))
			{
				mapArr[X][Y] = 1;
			}
			else
			{
				mapArr[X][Y] = 0;
			}
		}
	}
}

void PrintMap()
{
	int X, Y;
	for (Y= 0; Y < inputY; Y++)
	{
		for (X= 0;X< inputX;X++)
		{
			switch (mapArr[X][Y])
			{
			case 0:
				printf("□");
				break;
			case 1:
				printf("■");
				break;
			case 2:
				printf("●");
				break;
			case 3:
				printf("★");
			}
		}
		printf("\n");
	}
}

void Help()
{
	printf("提示：向上————“w”或“8”\n");
	printf("      向下————“s”或“5”\n");
	printf("      向左————“a”或“4”\n");
	printf("      向右————“d”或“6”\n");
	printf("      暂停————鼠标左键单击屏幕，按任意键继续");
}

void SetRandNum()
{
	srand((unsigned)time(0));//时间种子
	while ((mapArr[randX][randY] != 0) && (foodFlag == 0))
	{
		randX = rand() % (inputX - 1), randY = rand() % (inputY - 1);//产生0到（inputX - 2）或（inputY-2）之间的随机数
	}
	mapArr[randX][randY] = 3;	//将地图上食物所在位置的属性设为3
	foodFlag = 1;
}

void SetSnakeNum()
{
	int i;
	if (kbhit())         //kbhit()————检查当前是否有键盘输入，若有则返回一个非0值，否则返回0
	{
		int a = getch();
		switch (input)
		{
		case '8':
		case 'w':
			if (a == '4' || a == '6' || a == 'a' || a == 'd' || a == '8' || a == 'w')
				input = a;
			break;
		case '5':
		case 's':
			if (a == '4' || a == '6' || a == 'a' || a == 'd' || a == '5' || a == 's')
				input = a;
			break;
		case '4':
		case 'a':
			if (a == '8' || a == '5' || a == 'w' || a == 's' || a == '4' || a == 'a')
				input = a;
			break;
		case '6':
		case 'd':
			if (a == '8' || a == '5' || a == 'w' || a == 's' || a == '6' || a == 'd')
				input = a;
			break;
		}
	}
	switch (input)				//判断移动方向
	{
	case '8':					//向上
	case 'w':BodyY--;break;
	case '5':					//向下
	case 's':BodyY++;break;
	case '4':					//向左
	case 'a':BodyX--;break;
	case '6':					//向右
	case 'd':BodyX++;break;
	}
	for (i = Length; i != 0; i--)     //坐标传递
	{
		body[i] = body[i - 1];
		*body[i] = 2;                 //更改地图上点的属性
	}
	body[0] = &mapArr[BodyX][BodyY];//移动后的蛇头坐标地址
	if ((*body[0] == 1) || (*body[0] == 2))    //判断头是否撞到墙或身体
	{
		overFlag = 0;
	}
	*body[0] = 2;              //修改蛇头所在点的地图属性
}

void EatFood()
{
	if (*body [0]== 3)
	{
		Length++;
		foodFlag = 0;
	}
}

void gotoxy(int x, int y) //输出坐标，从该点开始输出，实现覆盖 
{
	COORD pos;//COORD——表示一个字符在控制台屏幕上的坐标
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
