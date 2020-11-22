#include "GoBang.h"

class GoBang	//��������
{
	public:

		/*��ʼ����*/
		void Play()
		{
			Position Play1;   //���1�����
			Position Play2;   //���2
			while (1) 
			{
				int mode = ChooseMode();
				while (1) 
				{
					if (mode == 1)		//����VS���2
					{
						ComputerChess(Play1, flag1);	//������
						if (GetVictory(Play1, 0, flag1))	//Ϊ������Ի�ʤ��0ָ����
						{
							break;
						}
						PlayChess(Play2, 2, flag2);		//���2��
						//PrintChessBoard();
						if (GetVictory(Play2, 2, flag2))	//Ϊ�������2��ʤ��2ָ���2
						{
							break;
						}
					}
					else				//���1VS���2
					{
						PlayChess(Play1, 1, flag1);		//���1��
						//PrintChessBoard();
						if (GetVictory(Play1, 1, flag1))	//Ϊ�������1��ʤ��1ָ���1
						{
							break;
						}
						PlayChess(Play2, 2, flag2);		//���2��
						//PrintChessBoard();
						if (GetVictory(Play2, 2, flag2))	//Ϊ�������2��ʤ��2ָ���2
						{
							break;
						}
					}
				}

				/*��Ϸ������������Ϸ���˳�*/
				cout << "======����һ��=======" << endl;
				cout << "yes or no :";
				char s[] = "yes";
				cin >> s;	//����yes��no
				if (strcmp(s, "no") == 0)	//����no���˳�ѭ������������
				{
					break;
				}
			}
		}

	protected:

		/*��ʼ������*/
		void InitChessBoard()
		{
			/*��һ��vector��ʼ��*/
			for (int i = 0; i < N; i++)
			{
				_iChessBoard.push_back(Array);	
				for (int j = 0; j < N; j++)
				{
					_iChessBoard[i].push_back(j);
				}
			}
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					_iChessBoard[i][j] = 0;
				}
			}
		}

        /*ѡ��ģʽ*/
		int ChooseMode() 
		{
			system("cls");	//ϵͳ���ã�����
			InitChessBoard();	//���³�ʼ������
			cout << "+-------------------------------------------------+" << endl;
			cout << "|-----------------[ 0���˳���Ϸ ]-----------------|" << endl;
			cout << "|-----------------[1������VS���]-----------------|" << endl;
			cout << "|-----------------[2�����VS���]-----------------|" << endl;
			cout << "+-------------------------------------------------+" << endl;
			while (1) 
			{
				int i = 0;
				cout << "��ѡ��ģʽ��";
				cin >> i;
				if (i == 0)		//�˳�
				{
					exit(1);
				}
				if (i == 1 || i == 2) 
				{
					return i;	//����ģʽ��Ӧֵ��void Play()
				}
				else	//����Ƿ�ֵ
				{
					cout << "�Ƿ����룬���������룡" << endl;
				}
			}
		}

		/*��ӡ����*/
		void PrintChessBoard()
		{
			//printf("   |---|---|---|---|---|---|---|---|---|---|---|---|---|---|---|\n");
			for (int i = 0; i < N; i++)
			{
				printf("%2d ", i + 1);//��ӡ������
				/*����ж�Ӧλ�÷���*/
				for (int j = 0; j < N; j++)
				{
					switch (_iChessBoard[i][j])
					{
						case 0:		//����
							cout << "  . ";
							break;
						case 1:		//���1����
							cout << " �� ";
							break;
						case 2:		//���2����
							cout << " �� ";
							break;
						case 3:		//���
							cout << " ��  ";
							break;
					}
				}
				cout << endl;
				cout << endl;
			}
			printf("     1   2   3   4   5   6   7   8   9  10  11  12  13  14  15\n");	//������
			cout << endl;
		}

		/*������*/
		void ComputerChess(Position& pos, char flag)
		{
		}

		/*�����*/
		void PlayChess(Position& pos, int player, char flag) 
		{
			/*��ʼ�����λ�ã���λ��8��8��*/
			int X = 8 - 1;
			int Y = 8 - 1;

			system("cls");		//����
			PrintChessBoard();	//��ӡ����

			/*��Ϸ��ʾ*/
			cout << "���" << player << "����";
			if (1 == player)
			{
				cout << "��" << "��ǰλ�ã�" << (Y + 1) << ", " << (X + 1) << endl;
			}
			else if (2 == player)
			{
				cout << "��" << "��ǰλ�ã�" << (Y + 1) << ", " << (X + 1) << endl;
			}

			/*���ݼ�ִֵ����Ӧ����*/
			while (1) 
			{
				char c = _getch();
				cout << c;
				//if ('w' == c) 
				if ('H' == c)	//����
				{
					if (Y != 0) 
					{
						Y--;
						if (_iChessBoard[Y][X] != 1 && _iChessBoard[Y][X] != 2)
						{
							_iChessBoard[Y][X] = 3;
						}
					}
				}
				//else if ('s' == c) 
				else if ('P' == c)	//����
				{
					if (Y != 14) 
					{
						Y++;
						if (_iChessBoard[Y][X] != 1 && _iChessBoard[Y][X] != 2)
						{
							_iChessBoard[Y][X] = 3;
						}
					}
				}
				//else if ('a' == c) 
				else if ('K' == c)	//����
				{
					if (X != 0) 
					{
						X--;
						if (_iChessBoard[Y][X] != 1 && _iChessBoard[Y][X] != 2)
						{
							_iChessBoard[Y][X] = 3;
						}
					}
				}
				//else if ('d' == c) 
				else if ('M' == c)	//����
				{
					if (X != 14) 
					{
						X++;
						if (_iChessBoard[Y][X] != 1 && _iChessBoard[Y][X] != 2)
						{
							_iChessBoard[Y][X] = 3;
						}
					}
				}
				else if (13 == c && 3 == _iChessBoard[Y][X])	//Enter���ҹ����ڣ���û�����ӵ�λ��
				{
					pos.row = Y;
					pos.col = X;
					_iChessBoard[Y][X] = player;
					break;
				}

				/*�������̣�����������*/
				for (int i = 0; i < N; i++)
				{
					for (int j = 0; j < N; j++)
					{
						if (i != Y || j != X)
						{
							if (_iChessBoard[i][j] != 1 && _iChessBoard[i][j] != 2)
							{
								//_ChessBoard[i][j] = ' ';
								_iChessBoard[i][j] = 0;
							}
						}
					}
				}
				system("cls");		//����
				PrintChessBoard();	//��ӡ����

				/*��Ϸ��ʾ*/
				cout << "���" << player << "����";
				if (1 == player)
				{
					cout << "��" << "��ǰλ�ã�" << (Y + 1) << ", " << (X + 1) << endl;
				}
				else if (2 == player)
				{
					cout << "��" << "��ǰλ�ã�" << (Y + 1) << ", " << (X + 1) << endl;
				}
			}
			PrintChessBoard();
		}

		/*�ж��Ƿ�����һ�ʤ���ײ��жϣ�*/
		int JudgeVictory(Position pos, int player)
		{
			int begin = 0;
			int end = 0;

			/*1.�ж����Ƿ���������*/
			(pos.col - 4) > 0 ? begin = (pos.col - 4) : begin = 1;
			(pos.col + 4) > N ? end = N : end = (pos.col + 4);
			for (int i = pos.row, j = begin; j + 4 <= end; ++j) 
			{
				if (_iChessBoard[i][j] == player && _iChessBoard[i][j + 1] == player &&
					_iChessBoard[i][j + 2] == player && _iChessBoard[i][j + 3] == player &&
					_iChessBoard[i][j + 4] == player)
					return 1;
			}
			/*2.�ж����Ƿ���������*/
			(pos.row - 4) > 0 ? begin = (pos.row - 4) : begin = 1;
			(pos.row + 4) > N ? end = N : end = (pos.row + 4);
			for (int j = pos.col, i = begin; i + 4 <= end; ++i) 
			{
				if (_iChessBoard[i][j] == player && _iChessBoard[i + 1][j] == player &&
					_iChessBoard[i + 2][j] == player && _iChessBoard[i + 3][j] == player &&
					_iChessBoard[i + 4][j] == player)
					return 1;
			}
			/*3.�ж����Խ����Ƿ���������*/
			int len = 0;    //��Գ���
			int start = 0;
			int finish = 0;
			pos.row > pos.col ? len = pos.col - 1 : len = pos.row - 1;
			if (len > 4) 
			{
				len = 4;
			}
			begin = pos.row - len;       //��������ʼλ��
			start = pos.col - len;       //��������ʼλ��

			pos.row > pos.col ? len = N - pos.row : len = N - pos.col;
			if (len > 4) 
			{
				len = 4;
			}
			end = pos.row + len;         //���������λ��
			finish = pos.col + len;      //���������λ��

			for (int i = begin, j = start; (i + 4 <= end) && (j + 4 <= finish); ++i, ++j) 
			{
				if (_iChessBoard[i][j] == player && _iChessBoard[i + 1][j + 1] == player &&
					_iChessBoard[i + 2][j + 2] == player && _iChessBoard[i + 3][j + 3] == player &&
					_iChessBoard[i + 4][j + 4] == player)
					return 1;
			}
			/*4.�жϸ��Խ����Ƿ���������*/
			(pos.row - 1) > (N - pos.col) ? len = N - pos.col : len = pos.row - 1;
			if (len > 4) 
			{
				len = 4;
			}
			begin = pos.row - len;       //��������ʼλ��
			start = pos.col + len;       //��������ʼλ��

			(N - pos.row) > (pos.col - 1) ? len = pos.col - 1 : len = N - pos.row;
			if (len > 4) 
			{
				len = 4;
			}
			end = pos.row + len;         //���������λ��
			finish = pos.col - len;      //���������λ�� 
			for (int i = begin, j = start; (i + 4 <= end) && (j - 4 >= finish); ++i, --j) 
			{
				if (_iChessBoard[i][j] == player && _iChessBoard[i + 1][j - 1] == player &&
					_iChessBoard[i + 2][j - 2] == player && _iChessBoard[i + 3][j - 3] == player &&
					_iChessBoard[i + 4][j - 4] == player)
					return 1;
			}
			//��λ�ò�δ����
			for (int x = 0; x < N; x++) 
			{
				for (int y = 0; y < N; y++) 
				{
					if (_iChessBoard[x][y] == 0) 
					{
						return 0;       //δ����
					}
				}
			}
			return -1;      //�;�
		}

		/*�жϾ����ʤ���*/
		bool GetVictory(Position& pos, int player, char flag) 
		{
			if (JudgeVictory(pos, player) != 0)	//�ж������˻�ʤ
			{
				if (JudgeVictory(pos, player) == 1)	//�ж��Ƿ����˻�ʤ,1��ʾ��ʤ
				{
					PrintChessBoard();		//��ӡ����
					if (player == 0) 
					{
						cout << "���Ի�ʤ��" << endl;
					}
					else 
					{
						printf("��ϲ���%d��ʤ��\n", player);
					}
				}
				else 
				{
					printf("�;֣�\n");
				}
				return true;	//���˻�ʤ
			}
			return false;		//û�˻�ʤ
		}

	private:
		vector< int > Array;
		vector< vector<int> > _iChessBoard;	//������̬��ά����

};

int main()
{
	GoBang g;
	g.Play();
	system("pause");
	return 0;
}