#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h> 
#include<time.h>
#define MAXX 40//���Ƴ�
#define MAXY 40//���ƿ�


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

int mapArr[MAXX][MAXY];//  �����ά���鴢���ͼ����
int inputX=20;//Ĭ�ϵ�ͼ��
int inputY=20;//Ĭ�ϵ�ͼ��
int MaxS=0;//��߷�
int speed=5;//Ĭ���ƶ��ٶ�
int randX=0, randY =0;        //���ʳ���������
int foodFlag=0;//�ж�ʳ���Ƿ���ڵı�־��Ϊ1ʱʳ����ڣ�Ϊ0ʱʳ�ﲻ����
int BodyX= 1, BodyY= 1;	//ͷ����
int Length=0;//����
char input = 'd';    //Ĭ���ƶ�����
int overFlag=1;   //�ж���Ϸ�Ƿ������Ϊ0ʱ��Ϸ����
int *body[MAXX * MAXY];				//��������ָ�����

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
	   case 1:StartGame();break;//��Ϸ��ʼ
	   case 2:Set();break;//����
	   //case 3:MaxScore();break;//��߷�   Max=Length+1    ��Ҫ�����ļ������������ �ٶ�ȡ�ļ��е���߷�   ����Ϸ�������ж��Ƿ�Ϊ��߷֣���д���ļ�
	   case 4:GameIntro();break;//��Ϸ����
	   default:printf("\n\t\t  �������");
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
    printf("\t\t|\t\t1.��ʼ��Ϸ\t       |\n");
    printf("\t\t|\t\t2.����\t               |\n");
    printf("\t\t|\t\t3.��߷�\t       |\n");
    printf("\t\t|\t\t4.��Ϸ����\t       |\n");
    printf("\t\t|\t\t5.�˳�\t\t       |\n");
	printf("\t\t|\t\t\t\t       |\n");
    printf("\t\t|--------------------------------------|\n\n");
    printf("\t\t  ������ѡ��ǰ����ţ�1-5):");
  
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
	 	InitMap();                   //������ͼ����
		SetSnakeNum();               //ʵ���ߵ��ƶ����޸���Ϸ�����ж�ֵoverFlag
		SetRandNum();                //�������ʳ��
		EatFood();                   //ʵ���߳�ʳ��������ߵĳ���
		PrintMap();                  //��ͼ����
		Help();                      //��Ϸ��ʾ 
		Sleep(1000/speed);                 
		gotoxy(0,0);
	  }
	  system("cls");
	  reFlag=0;
	  printf("�÷֣�%d\n",Length);
	  printf("�Ƿ����¿�ʼ(y/n)��\n");
	  getchar();
	  if(getchar()=='y')
		  reFlag=1;
	}
}

void Set()
{
	int reSet=1;
	system("cls");
    printf("�������ͼ�ĳ��ȣ�5��40֮�����������\n");
    while(reSet)
	 {
	  scanf("%d", &inputX);
	  if((inputX<=MAXX)&&(inputX>4))
	   {
	      printf("\n");
          reSet=0;
	   }
	  else
	     printf("��Ч���룬����������:\n");
	 }
	reSet=1;
	printf("�������ͼ�Ŀ�ȣ�5��40֮�����������\n");
	while(reSet)
	 {
	  scanf("%d", &inputY);
	  if((inputY<=MAXY)&&(inputY>4))
	   {
	      printf("\n");
          reSet=0;
	   }
	  else
	     printf("��Ч���룬����������:\n");
	 }
	printf("\n");
	printf("�������ƶ��ٶȣ�1 �� n��1��������\n");
	scanf("%d", &speed);
}

void GameIntro()
{
   system("cls");
   printf("��Ϸ����:");
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
				printf("��");
				break;
			case 1:
				printf("��");
				break;
			case 2:
				printf("��");
				break;
			case 3:
				printf("��");
			}
		}
		printf("\n");
	}
}

void Help()
{
	printf("��ʾ�����ϡ���������w����8��\n");
	printf("      ���¡���������s����5��\n");
	printf("      ���󡪡�������a����4��\n");
	printf("      ���ҡ���������d����6��\n");
	printf("      ��ͣ��������������������Ļ�������������");
}

void SetRandNum()
{
	srand((unsigned)time(0));//ʱ������
	while ((mapArr[randX][randY] != 0) && (foodFlag == 0))
	{
		randX = rand() % (inputX - 1), randY = rand() % (inputY - 1);//����0����inputX - 2����inputY-2��֮��������
	}
	mapArr[randX][randY] = 3;	//����ͼ��ʳ������λ�õ�������Ϊ3
	foodFlag = 1;
}

void SetSnakeNum()
{
	int i;
	if (kbhit())         //kbhit()����������鵱ǰ�Ƿ��м������룬�����򷵻�һ����0ֵ�����򷵻�0
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
	switch (input)				//�ж��ƶ�����
	{
	case '8':					//����
	case 'w':BodyY--;break;
	case '5':					//����
	case 's':BodyY++;break;
	case '4':					//����
	case 'a':BodyX--;break;
	case '6':					//����
	case 'd':BodyX++;break;
	}
	for (i = Length; i != 0; i--)     //���괫��
	{
		body[i] = body[i - 1];
		*body[i] = 2;                 //���ĵ�ͼ�ϵ������
	}
	body[0] = &mapArr[BodyX][BodyY];//�ƶ������ͷ�����ַ
	if ((*body[0] == 1) || (*body[0] == 2))    //�ж�ͷ�Ƿ�ײ��ǽ������
	{
		overFlag = 0;
	}
	*body[0] = 2;              //�޸���ͷ���ڵ�ĵ�ͼ����
}

void EatFood()
{
	if (*body [0]== 3)
	{
		Length++;
		foodFlag = 0;
	}
}

void gotoxy(int x, int y) //������꣬�Ӹõ㿪ʼ�����ʵ�ָ��� 
{
	COORD pos;//COORD������ʾһ���ַ��ڿ���̨��Ļ�ϵ�����
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
