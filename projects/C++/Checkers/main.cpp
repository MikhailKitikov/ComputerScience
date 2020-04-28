//---------------------------------------------------------------------------
#include <fstream>
#include <vcl.h>
#pragma hdrstop
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <algorithm>
#include <windows.h>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
using namespace std;
class checker
{
 public:
	bool live;
	bool queen;
	int xpos;
	int ypos;
	bool move(int var);
	bool beat(int var);
};

Graphics::TBitmap* Back1 = new Graphics::TBitmap(), *Back2 = new Graphics::TBitmap(), *First = new Graphics::TBitmap(), *Second = new Graphics::TBitmap(), *Edge = new Graphics::TBitmap();
int play_field[10][10];
checker player[2][12];
int x_KD[2], y_KD[2], num_checkers[2], closed = 0, s, m, h, icon = 1, game_type = 1, Max_element, type_move, AI_element, AI_xposition, AI_yposition, whose_move = 1, moving = 0, taken_checker, difficulty = 0, comp_moves, player_moves, number;
bool must_beat = false;
int a, b;
vector <int> live_checkers;
vector <int> can_beat;
vector <int> can_move[2];
string texture[3][2];
int dir[2] = {-1, 1};
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

bool check_win(int var)
{
	if(num_checkers[var-1] == 0 || can_move[var-1].size() == 0)
		return true;
	else
		return false;
}

bool checker::beat(int var)
{
	int p = 0;
	int x, y;
	y = var;
	x = 3 - y;
	if(live == true)
		switch(queen)
		{
			case true:
			{
				int i, j, q;
				for(int I = 0; I < 2; I++)
					for(int J = 0; J < 2; J++)
					{   ShowMessage("dir");
						q = 0;
						i = ypos;
						j = xpos;
						while(q!=2 && i<9 && j<9 && i>0 && j>0)
						{
							i += dir[I];
							j += dir[J];
							if(play_field[i][j] == 0)
							{
								if(q == 1)
								{
									p++;
									break;
								}
							}
							else
								if(play_field[i][j] == y)
									q = 2;
								else
									q++;
						}
					}
				break;
			}
			case false:
			{
				if(play_field[ypos+1][xpos+1]==x && play_field[ypos+2][xpos+2]==0||
				   play_field[ypos-1][xpos-1]==x && play_field[ypos-2][xpos-2]==0||
				   play_field[ypos+1][xpos-1]==x && play_field[ypos+2][xpos-2]==0||
				   play_field[ypos-1][xpos+1]==x && play_field[ypos-2][xpos+2]==0)
					p++;
				break;
			}
		}
	if(p!=0)
		return true;
	else
		return false;
}

bool checker::move(int var)
{
	int p = 0;
	int y;
	y = var;
	if(live == true)
		switch(queen)
		{
			case false:
			{   //ShowMessage(IntToStr(xpos).c_str());
				if(play_field[ypos+dir[var-1]][xpos-1]==0||play_field[ypos+dir[var-1]][xpos+1]==0||play_field[ypos+dir[var-1]][xpos-1]==3||play_field[ypos+dir[var-1]][xpos+1]==3)
					p++;
				break;
			}
			case true:
			{
				int i, j, q;
				for(int I = 0; I < 2; I++)
					for(int J = 0; J < 2; J++)
					{
						q = 0;
						i = ypos;
						j = xpos;
						while(q==0 && i<9 && j<9 && i>0 && j>0)
						{
							i += dir[I];
							j += dir[J];
							if(play_field[i][j] == 0 || play_field[i][j] == 3)
								p++;
							else
								q++;
						}
					}
				break;
			}
		}
	if(p!=0)
		return true;
	else
		return false;
}

void structuring()
{
	live_checkers.clear();
	can_beat.clear();
	can_move[0].clear();
	can_move[1].clear();
	for(int i=0; i<12; i++)
	{
		if(player[1][i].live == true)
		{
			live_checkers.push_back(i);
			if(player[1][i].beat(2))
			   can_beat.push_back(i);
			if(player[1][i].move(2))
			   can_move[1].push_back(i);
		}
		if(player[0][i].live == true && player[0][i].move(1))
			can_move[0].push_back(i);
	}
}

int find_checker(int x_pos, int y_pos, int var)
{
	int p=0, find;
	for(int i=0; i<12; i++)
		if(player[var-1][i].live==true && player[var-1][i].xpos == x_pos && player[var-1][i].ypos == y_pos)
		{
			find = i;
			p = 1;
			break;
		}
	if(p==0)
		find = -1;
	return find;
}

bool to_beat(int var)
{
	int kol = 0, x, y;
	x = var;
	y = 3 - x;
	for(int m=0; m<12; m++)
	{
		if(player[x-1][m].live == true)
			switch(player[x-1][m].queen)
			{
				case false:
				{
					if(player[x-1][m].beat(x))
						kol++;
					break;
				}
				case true:
				{
					int i, j, p = 0;
					for(int I = 0; I < 2; I++)
						for(int J = 0; J < 2; J++)
						{
							i = player[x-1][m].ypos;
							j = player[x-1][m].ypos;
							while(p!=2 && i<9 && j<9 && i>0 && j>0)
							{
								i += dir[I];
								j += dir[J];
								if(play_field[i][j] == 0 || play_field[i][j] == 3)
								{
									if(p == 1)
										kol++;
								}
								else
									if(play_field[i][j] == x)
										p = 2;
									else
										p++;
							}
						}
					break;
				}
			}
	}
	if(kol!=0)
		return true;
	else
		return false;
}

void win(int winner)
{
	if(game_type == 1)
	{
		if(winner == 1)
		{
			if (MessageDlg("Вы победили! Играть заново?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo,0) == mrYes)
			{
				 Form1->Button1->Click();
			}
			else
				 Form1->Close();
		}
		else
			if (MessageDlg("Вы проиграли( Играть заново?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo,0) == mrYes)
			{
				 Form1->Button1->Click();
			}
			else
				Form1->Close();
	}
	else
		if(winner == 1)
		{
			if (MessageDlg("Игрок 1 победил! Играть заново?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo,0) == mrYes)
			{
				 Form1->Button1->Click();
			}
			else
				 Form1->Close();
		}
		else
			if (MessageDlg("Игрок 2 победил! Играть заново?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo,0) == mrYes)
			{
				 Form1->Button1->Click();
			}
			else
				Form1->Close();

}

void knock_down(int var)
{
	Edge->LoadFromFile(texture[2][(icon + var)%2].c_str());
	if(var == 1)
		Form1->Image2->Canvas->CopyRect(Bounds(x_KD[var-1], y_KD[var-1], 30, 90), Edge->Canvas, Bounds(0,0,Edge->Width, Edge->Height));
	else
		Form1->Image1->Canvas->CopyRect(Bounds(x_KD[var-1], y_KD[var-1], 30, 90), Edge->Canvas, Bounds(0,0,Edge->Width, Edge->Height));
	x_KD[var-1]+=40;
	if(x_KD[var-1] == 250)
	{
		x_KD[var-1] = 10;
		y_KD[var-1] = 110;
	}
}

void check_queen()
{
	if(icon == 1)
	{
		First->LoadFromFile("White_Queen.bmp");
		Second->LoadFromFile("Black_Queen.bmp");
	}
	else
	{
		First->LoadFromFile("Black_Queen.bmp");
		Second->LoadFromFile("White_Queen.bmp");
	}
	for(int i=0; i<12; i++)
	{
		if(player[0][i].ypos==1 && player[0][i].queen==false)
		{
			player[0][i].queen=true;
			Form1->DrawGrid1->Canvas->CopyRect(Form1->DrawGrid1->CellRect(player[0][i].xpos-1,player[0][i].ypos-1),First->Canvas,Bounds(0, 0, First->Width, First->Height));
		}
		if(player[1][i].ypos==8 && player[1][i].queen==false)
		{
			player[1][i].queen=true;
			Form1->DrawGrid1->Canvas->CopyRect(Form1->DrawGrid1->CellRect(player[1][i].xpos-1,player[1][i].ypos-1),Second->Canvas,Bounds(0, 0, Second->Width, Second->Height));
		}
	}
}

int AI(int depth)
{
	structuring();
	if(depth <= difficulty) //если глубина не максимальна
	{
		if(!check_win(2))  //если никто не выиграл
		{
			 int dir_ypos, dir_xpos, maxi, step;
			 int i, j, p = 0, k = 0, max_k = 0;
			 if(to_beat(2)) //если надо бить
			 {
				srand(time(NULL));
				int X = can_beat[rand()%can_beat.size()];
				if(player[1][X].queen == false)
					Second->LoadFromFile("Black.bmp");
				else
					Second->LoadFromFile("Black_Queen.bmp");
				while(player[1][X].beat(2) == true)   //пока шашка может бить
				{
					maxi = 0; dir_ypos = 0; dir_xpos = 0;
					p = 0, k = 0, max_k = 0;
					for(int I = 0; I < 2; I++)
						for(int J = 0; J < 2; J++)
						{
							i = player[1][X].ypos;
							j = player[1][X].xpos;
							k = 0;
							p = 0;
							while(p!=2 && i<9 && j<9 && i>0 && j>0)
							{
								k++;
								if(player[1][X].queen == false && k > 2)
									break;
								i += dir[I];
								j += dir[J];
								if(play_field[i][j] == 0 || play_field[i][j] == 3)
								{
									if(p == 1)
									{
										step = AI(depth+1);
										if(step > maxi)
										{
											maxi = step;
											max_k = k;
											dir_ypos = dir[I];
											dir_xpos = dir[J];
											break;
										}
										else
											if(step == maxi)
												if(rand()%2 == 1)
													maxi = step;
									}
								}
								else
								{
									if(play_field[i][j] == 2)
										p = 2;
									else
										p++;
								}
							}
						}
						//прямые изменения
					Sleep(500);
					//ShowMessage(IntToStr(max_k).c_str());
					//ShowMessage(IntToStr(maxi).c_str());
					//ShowMessage(IntToStr(dir_ypos).c_str());
					//ShowMessage(IntToStr(dir_xpos).c_str());
					play_field[player[1][X].ypos][player[1][X].xpos] = 0;
					play_field[player[1][X].ypos+(max_k-1)*dir_ypos][player[1][X].xpos+(max_k-1)*dir_xpos] = 0;
					play_field[player[1][X].ypos+max_k*dir_ypos][player[1][X].xpos+max_k*dir_xpos] = 2;
					int found = find_checker(player[1][X].xpos+(max_k-1)*dir_xpos,player[1][X].ypos+(max_k-1)*dir_ypos,1);
					player[0][found].live = false;
					knock_down(1);
					num_checkers[0]--;
					Form1->DrawGrid1->Canvas->CopyRect(Form1->DrawGrid1->CellRect(player[1][X].xpos-1,player[1][X].ypos-1),Back2->Canvas,Rect(0,0,Back2->Width, Back2->Height));
					Form1->DrawGrid1->Canvas->CopyRect(Form1->DrawGrid1->CellRect(player[1][X].xpos+(max_k-1)*dir_xpos-1,player[1][X].ypos+(max_k-1)*dir_ypos-1),Back2->Canvas,Rect(0,0,Back2->Width, Back2->Height));
					Form1->DrawGrid1->Canvas->CopyRect(Form1->DrawGrid1->CellRect(player[1][X].xpos+max_k*dir_xpos-1,player[1][X].ypos+max_k*dir_ypos-1),Second->Canvas,Rect(0,0,Second->Width, Second->Height));
					player[1][X].xpos+=max_k*dir_xpos;
					player[1][X].ypos+=max_k*dir_ypos;
				}
					//ShowMessage(IntToStr(temp[temp.size()-1]).c_str());   ShowMessage("Hi!");
			 }
			 else
			 {
				srand(time(NULL));
				maxi = 0; dir_ypos = 0; dir_xpos = 0;
				p = 0, k = 0, max_k = 0;
				int X = can_move[1][rand()%can_move[1].size()];
				if(player[1][X].queen == false)
					Second->LoadFromFile("Black.bmp");
				else
					Second->LoadFromFile("Black_Queen.bmp");
				for(int I = 0; I < 2; I++)
					for(int J = 0; J < 2; J++)
					{
						i = player[1][X].ypos;
						j = player[1][X].xpos;
						k = 0;
						p = 0;
						if(!(player[1][X].queen == false && I == 0))
							while(p==0 && i<9 && j<9 && i>0 && j>0)
							{
								k++;
								if(player[1][X].queen == false && k > 1)
									break;
								i += dir[I];//ShowMessage("i"); ShowMessage(IntToStr(i).c_str());
								j += dir[J];//ShowMessage("j"); ShowMessage(IntToStr(j).c_str());
								if(play_field[i][j] == 0 || play_field[i][j] == 3)
								{
									step = AI(depth+1);
									if(step > maxi)
									{
										maxi = step;
										max_k = k;
										dir_ypos = dir[I];
										dir_xpos = dir[J];
										break;
									}
									else
										if(step == maxi)
											if(rand()%2 == 1)
												maxi = step;
								}
								else
									p++;
							}
					}
				// ShowMessage("Hi!");
				Sleep(500);
				//ShowMessage(IntToStr(dir_ypos).c_str());
				//ShowMessage(IntToStr(dir_xpos).c_str());
				play_field[player[1][X].ypos+max_k*dir_ypos][player[1][X].xpos+max_k*dir_xpos] = 2;
				play_field[player[1][X].ypos][player[1][X].xpos] = 0;     //ShowMessage(IntToStr(player[1][i].xpos).c_str());
				Form1->DrawGrid1->Canvas->CopyRect(Form1->DrawGrid1->CellRect(player[1][X].xpos+max_k*dir_xpos-1,player[1][X].ypos+max_k*dir_ypos-1),Second->Canvas,Rect(0,0,Second->Width, Second->Height));
				Form1->DrawGrid1->Canvas->CopyRect(Form1->DrawGrid1->CellRect(player[1][X].xpos-1,player[1][X].ypos-1),Back2->Canvas,Rect(0,0,Back2->Width ,Back2->Height));
				player[1][X].xpos+=max_k*dir_xpos;
				player[1][X].ypos+=max_k*dir_ypos;
				//ShowMessage(IntToStr(i).c_str());
				//ShowMessage(IntToStr(maxt).c_str());
			 }
			whose_move = 1;                // ShowMessage("Hi!");
		}
		else
			number = 1000;
	}
	else
	{
		number = num_checkers[1];
	}
	return number;
}

void play()
{
	//int i;
	//for(i=0; i<can_beat.size(); i++);
	//ShowMessage(IntToStr(i).c_str());
	//if(comp[8].live == true)
	   //	ShowMessage("live");
	int Intel = AI(0);   // ShowMessage("Hi!");
	if(!check_win(2))
	{
		whose_move = 1;
		//check_queen();
	}
	else
		win(1);
	//{
	//	Form1->BitBtn1->Visible = true;
	//	Form1->BitBtn1->Enabled = true;
	//}// ShowMessage(IntToStr(comp[11].xpos).c_str());
}

//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	First->LoadFromFile("White.bmp");
	First->Width = 88;
	First->Height = 88;
	Second->LoadFromFile("Black.bmp");
	Second->Width = 88;
	Second->Height = 88;
	Back1->LoadFromFile("Board1.bmp");
	Back2->LoadFromFile("Board2.bmp");
	Back1->Width = 88;
	Back1->Height = 88;
	Back2->Width = 88;
	Back2->Height = 88;
	texture[0][0] = "White.bmp"; texture[0][1] = "Black.bmp";
	texture[1][0] = "White_Queen.bmp"; texture[1][1] = "Black_Queen.bmp";
	texture[2][0] = "White_KD.bmp"; texture[2][1] = "Black_KD.bmp";
	fon->Picture->LoadFromFile("Background.bmp");
	board->Picture->LoadFromFile("Board.bmp");
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if (MessageDlg("Вы будете играть против компьютера?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo,0) == mrYes)
	{
		game_type = 1;
		//ShowMessage("Не советую (он еще не так хорош, что бы сразиться с Вами, Магнус Карлсен)");
	}
	else
		game_type = 2;
	closed = 0;
	if(game_type == 1)
	{
		if (MessageDlg("Хотите ли вы играть белыми?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo,0) == mrYes)
		{
			icon = 1;
			whose_move = 1;
		}
		else
		{
			icon = 2;
			whose_move = 2;
		}
	}
	else
	{
		srand(time(NULL));
		if(rand()%2+1 == 1)
		{
			if (MessageDlg("Жребий решил, что белыми играет Игрок 1", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo,0) == mrYes)
			{
				icon = 1;
				whose_move = 1;
			}
			else
			{
				icon = 2;
				whose_move = 2;
			}
		}
		else
			if (MessageDlg("Жребий решил, что белыми играет Игрок 2", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo,0) == mrYes)
			{
				icon = 2;
				whose_move = 2;
			}
			else
			{
				icon = 1;
				whose_move = 1;
			}
	}
	if(icon == 1)
	{
		First->LoadFromFile("White.bmp");
		Second->LoadFromFile("Black.bmp");
	}
	else
	{
		First->LoadFromFile("Black.bmp");
		Second->LoadFromFile("White.bmp");
	}
	Image1->Picture = NULL; Image1->Canvas->FloodFill(0,0,clWhite,fsSurface);
	Image2->Picture = NULL; Image2->Canvas->FloodFill(0,0,clWhite,fsSurface);
	num_checkers[0] = 12;
	num_checkers[1] = 12;
	x_KD[0] = 10; x_KD[1] = 10;
	y_KD[0] = 10; y_KD[1] = 10;
	moving = 0;
	must_beat = 0;
	for(int i=0; i<12; i++)
		live_checkers.push_back(i);
	for(int i=0; i<10; i++)
		for(int j=0; j<10; j++)
			play_field[i][j] = -1;
	for(int i=2; i<9; i+=2)
	{
		play_field[1][i] = 2;
		play_field[3][i] = 2;
		play_field[7][i] = 1;
		play_field[5][i] = 0;
	}
	for(int i=1; i<9; i+=2)
	{
		play_field[2][i] = 2;
		play_field[6][i] = 1;
		play_field[8][i] = 1;
		play_field[4][i] = 0;
	}
	player[1][0].xpos = 2; player[1][0].ypos = 1;
	player[1][1].xpos = 4; player[1][1].ypos = 1;
	player[1][2].xpos = 6; player[1][2].ypos = 1;
	player[1][3].xpos = 8; player[1][3].ypos = 1;
	player[1][4].xpos = 1; player[1][4].ypos = 2;
	player[1][5].xpos = 3; player[1][5].ypos = 2;
	player[1][6].xpos = 5; player[1][6].ypos = 2;
	player[1][7].xpos = 7; player[1][7].ypos = 2;
	player[1][8].xpos = 2; player[1][8].ypos = 3;
	player[1][9].xpos = 4; player[1][9].ypos = 3;
	player[1][10].xpos = 6; player[1][10].ypos = 3;
	player[1][11].xpos = 8; player[1][11].ypos = 3;
	player[0][0].xpos = 1; player[0][0].ypos = 8;
	player[0][1].xpos = 3; player[0][1].ypos = 8;
	player[0][2].xpos = 5; player[0][2].ypos = 8;
	player[0][3].xpos = 7; player[0][3].ypos = 8;
	player[0][4].xpos = 2; player[0][4].ypos = 7;
	player[0][5].xpos = 4; player[0][5].ypos = 7;
	player[0][6].xpos = 6; player[0][6].ypos = 7;
	player[0][7].xpos = 8; player[0][7].ypos = 7;
	player[0][8].xpos = 1; player[0][8].ypos = 6;
	player[0][9].xpos = 3; player[0][9].ypos = 6;
	player[0][10].xpos = 5; player[0][10].ypos = 6;
	player[0][11].xpos = 7; player[0][11].ypos = 6;
	for(int i=0; i<12; i++)
	{
		player[0][i].live = true;
		player[1][i].live = true;
		player[0][i].queen = false;
		player[1][i].queen = false;
	}
	for(int i=0; i<9; i+=2)
		for(int j=0; j<9; j+=2)
		{
			DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(j,i),Back1->Canvas,Rect(0,0,Back1->Width ,Back1->Height));
			DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(j+1,i),Back2->Canvas,Rect(0,0,Back2->Width ,Back2->Height));
		}
	 for(int i=1; i<9; i+=2)
		for(int j=0; j<9; j+=2)
		{
			DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(j, i), Back2->Canvas,Rect(0, 0, Back2->Width, Back2->Height));
			DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(j+1, i), Back1->Canvas,Rect(0, 0, Back1->Width, Back1->Height));
		}
	 for(int i=0; i<12; i++)
	 {
		DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(player[0][i].xpos-1,player[0][i].ypos-1),First->Canvas,Rect(0,0,First->Width ,First->Height));
		DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(player[1][i].xpos-1,player[1][i].ypos-1),Second->Canvas,Rect(0,0,Second->Width ,Second->Height));
	 }
	 Timer1->Enabled = true;
	 s=0; m=0; h=0;
	 structuring();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DrawGrid1SelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect)
{    // ShowMessage("Hello!"); ShowMessage("Habrahabr!");
	Label1->Caption = IntToStr(play_field[ARow+1][ACol+1]).c_str();
	if((game_type == 1 && whose_move == 1) || game_type == 2) //Если ход игрока
	{
		a = whose_move;
		b = 3 - a;
		if(moving == 1)  //если шашка уже выбрана
		{
			if(play_field[ARow+1][ACol+1] == 3)    //Если выбранная шашка может сюда ходить
			{
				First->LoadFromFile(texture[player[a-1][taken_checker].queen][(whose_move+icon)%2].c_str());    //Выбор текстуры фигуры
				for(int i=0; i<9; i++)
					for(int j=0; j<9; j++)
						if(play_field[i][j] == 3)
						{
							DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(j-1, i-1), Back2->Canvas,Rect(0, 0, Back2->Width, Back2->Height));
							play_field[i][j] = 0;
						}
				DrawGrid1->Canvas->Brush->Color = clGreen;
				if(to_beat(a)) //Надо ли бить? Да
				{    //ShowMessage("Player!");
						//Стираем сбитые шашки
					int i = player[a-1][taken_checker].ypos;
					int j = player[a-1][taken_checker].xpos;
					int dx = ACol+1 - player[a-1][taken_checker].xpos;
					int dy = ARow+1 - player[a-1][taken_checker].ypos;
					int k = abs(dx);
					dx /= abs(dx);
					dy /= abs(dy);
					while(k > 0)
					{
						i += dy;
						j += dx;
						k--;
						if(play_field[i][j] == b)
						{
							play_field[i][j] = 0;
							int found = find_checker(j,i,b);
							player[b-1][found].live = false;
							num_checkers[b-1]--;
							knock_down(b);
							DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(j-1,i-1), Back2->Canvas,Rect(0, 0, Back2->Width, Back2->Height));
						}
					}
						// делаем ход
					DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),First->Canvas,Bounds(0, 0, First->Width, First->Height));
					play_field[player[a-1][taken_checker].ypos][player[a-1][taken_checker].xpos] = 0;
					play_field[ARow+1][ACol+1] = a;
					DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(player[a-1][taken_checker].xpos-1, player[a-1][taken_checker].ypos-1), Back2->Canvas,Rect(0, 0, Back2->Width, Back2->Height));
					player[a-1][taken_checker].xpos = ACol+1;
					player[a-1][taken_checker].ypos = ARow+1;
						//Смотрим, надо ли ЕЩЁ бить
					check_queen(); //А вдруг она стала дамкой...
					int kol = 0;
					switch(player[a-1][taken_checker].queen)
					{
						case false:   //не дамка
						{
							DrawGrid1->Canvas->Brush->Color = clGreen;
							if(player[a-1][taken_checker].beat(a))
								kol++;
							for(int i = 0; i < 2; i++)
							   for(int j = 0; j < 2; j++)
									if(play_field[player[a-1][taken_checker].ypos+dir[i]][player[a-1][taken_checker].xpos+dir[j]] == b && play_field[player[a-1][taken_checker].ypos+2*dir[i]][player[a-1][taken_checker].xpos+2*dir[j]] == 0)
									{
										play_field[player[a-1][taken_checker].ypos+2*dir[i]][player[a-1][taken_checker].xpos+2*dir[j]] = 3;
										DrawGrid1->Canvas->FillRect(DrawGrid1->CellRect(ACol+2*dir[j],ARow+2*dir[i]));
									}
							break;
						}
						case true:  //дамка
						{
							ShowMessage("ok");
							DrawGrid1->Canvas->Brush->Color = clGreen;
							int p, i, j;
							for(int I = 0; I < 2; I++)
							   for(int J = 0; J < 2; J++)
							   {
									p = 0;
									i = player[a-1][taken_checker].ypos;
									j = player[a-1][taken_checker].xpos;
									while(p!=2 && i<9 && j<9 && i>0 && j>0)
									{
										i += dir[I];
										j += dir[J];
										if(play_field[i][j] == 0)
										{
											if(p == 1)
											{
												DrawGrid1->Canvas->Brush->Color = clGreen;
												play_field[i][j] = 3;
												DrawGrid1->Canvas->FillRect(DrawGrid1->CellRect(j-1,i-1));
												kol++;
											}
										}
										else
											if(play_field[i][j] == a)
												p = 2;
											else
												p++;
									}
							   }
						}
					}
					if(kol == 0)   //Если СНОВА бить не нужно
					{
							//Ставим шашку
						moving = 0;
						whose_move = 3 - whose_move;
						if(game_type == 1)
							play();
						must_beat = false;
					}
					else
						must_beat = true;
				}
				else   //Если бить не нужно
				{
					moving = 0;
					whose_move = 3 - whose_move;
					DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),First->Canvas,Bounds(0, 0, First->Width, First->Height));
					play_field[player[a-1][taken_checker].ypos][player[a-1][taken_checker].xpos] = 0;
					play_field[ARow+1][ACol+1] = a;
					DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(player[a-1][taken_checker].xpos-1, player[a-1][taken_checker].ypos-1), Back2->Canvas,Rect(0, 0, Back2->Width, Back2->Height));
					player[a-1][taken_checker].xpos = ACol+1;
					player[a-1][taken_checker].ypos = ARow+1;
					if(game_type == 1)
						play();
				}
				check_queen();
			}
			else  //Если фигура не может сюда ходить
			{
				if(must_beat)
					ShowMessage("Вы должны бить, товарищ гроссмейстер!");
				else
				{
					for(int i=0; i<9; i++)
						for(int j=0; j<9; j++)
							if(play_field[i][j] == 3)
							{
								DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(j-1, i-1), Back2->Canvas,Rect(0, 0, Back2->Width, Back2->Height));
								play_field[i][j] = 0;
							}
					moving = 0;
					ShowMessage("Увы, ход невозможен!");
				}
			}
		}
		else  //если шашка еще не выбрана
		{
			int found = find_checker(ACol+1,ARow+1,a);
			if(play_field[ARow+1][ACol+1]==a)  //Есть ли тут белая шашка?
			{
				if(to_beat(a)) //Нужно ли бить команде?  ДА
				{  //ShowMessage("ye");
					switch(player[a-1][found].queen)  //Дамка ли это?
					{
						case false: //не дамка
						{
							if(player[a-1][found].beat(a))   //если она может бить
							{      //ShowMessage("Hi!");
								taken_checker = found;
								moving = 1;
								DrawGrid1->Canvas->Brush->Color = clGreen;
								for(int i = 0; i < 2; i++)
								   for(int j = 0; j < 2; j++)
										if(play_field[player[a-1][found].ypos+dir[i]][player[a-1][found].xpos+dir[j]] == b && play_field[player[a-1][found].ypos+2*dir[i]][player[a-1][found].xpos+2*dir[j]] == 0)
										{
											play_field[player[a-1][found].ypos+2*dir[i]][player[a-1][found].xpos+2*dir[j]] = 3;
											DrawGrid1->Canvas->FillRect(DrawGrid1->CellRect(ACol+2*dir[j],ARow+2*dir[i]));
										}
							}
							else
								ShowMessage("Вы должны бить, товарищ гроссмейстер!");
							break;
						}
						case true:  //дамка
						{
							DrawGrid1->Canvas->Brush->Color = clGreen;
							int kol = 0;
							int p, i, j;
							for(int I = 0; I < 2; I++)
							   for(int J = 0; J < 2; J++)
							   {
									p = 0;
									i = player[a-1][found].ypos;
									j = player[a-1][found].xpos;
									while(p!=2 && i<9 && j<9 && i>0 && j>0)
									{
										i += dir[I];
										j += dir[J];
									   //	ShowMessage(IntToStr(p).c_str());
										if(play_field[i][j] == 0)
										{
											if(p == 1)
											{
												DrawGrid1->Canvas->Brush->Color = clGreen;
/**problem**/									play_field[i][j] = 3;
												DrawGrid1->Canvas->FillRect(DrawGrid1->CellRect(j-1,i-1));
												kol++;
											}
										}
										else
											if(play_field[i][j] == a)
												p = 2;
											else
											{
												p++;   // ShowMessage("Hi!");
											}
									}
							   }
							if(kol == 0)
								ShowMessage("Вы должны бить, товарищ гроссмейстер!");
							else
							{
								taken_checker = found;
								moving = 1;  //Поднимаем шашку
							}
							break;
						}
					}
				}
				else  //КОМАНДЕ НЕ НУЖНО БИТЬ
				{
					switch(player[a-1][found].queen)  //Дамка ли это?
					{
						case false: //не дамка
						{
							if(player[a-1][found].move(a))    //Есть ли у неё ходы?
							{
								taken_checker = found;
								moving = 1;
								DrawGrid1->Canvas->Brush->Color = clGreen;
								for(int J = 0; J < 2; J++)
									if(play_field[ARow+2-2*(whose_move%2)][ACol+1+dir[J]] == 0)
									{
										play_field[player[a-1][taken_checker].ypos+1-2*(whose_move%2)][player[a-1][taken_checker].xpos+dir[J]] = 3;
										if(Showpossiblemoves1->Checked == true)
											DrawGrid1->Canvas->FillRect(DrawGrid1->CellRect(ACol+dir[J],ARow+1-2*(whose_move%2)));
									}
							}
							else  //нет ходов
								ShowMessage("У шашки нет ходов!");
							break;
						}
						case true:  //дамка
						{
							DrawGrid1->Canvas->Brush->Color = clGreen;
							int kol = 0;
							int p, i, j;
							for(int I = 0; I < 2; I++)
							   for(int J = 0; J < 2; J++)
							   {
									p = 0;
									i = player[a-1][found].ypos;
									j = player[a-1][found].xpos;
									while(p==0 && i<9 && j<9 && i>0 && j>0)
									{
										i += dir[I];
										j += dir[J];
										if(play_field[i][j] == 0)
										{
											DrawGrid1->Canvas->Brush->Color = clGreen;
											play_field[i][j] = 3;
											if(Showpossiblemoves1->Checked == true)
												DrawGrid1->Canvas->FillRect(DrawGrid1->CellRect(j-1,i-1));
											kol++;
										}
										else
											p++;
									}
							   }
							if(kol == 0)   //нет ходов
								ShowMessage("У дамки нет ходов!");
							else
							{
								taken_checker = found;
								moving = 1;
                            }
							break;
						}
					}
				}
			}
			else
			{
				if(game_type == 1)
					ShowMessage("Здесь нет вашей шашки!");
				else
					if(play_field[ARow+1][ACol+1]==b)
						ShowMessage("Не ваш ход, господин.");
					else
						ShowMessage("По-моему, клетка пуста.");
			}
		}
	}
	if(whose_move == 1)
	{
		Label5->Top = 850;
		Timer1->Enabled = true;
		s=0; m=0; h=0;
	}
	else
	{
		Label5->Top = 10;
		Timer1->Enabled = true;
		s=0; m=0; h=0;
	}
	if(check_win(whose_move))
		win(3-whose_move);
	//check_queen();
	Label2->Caption = whose_move;          // ShowMessage("Hello!");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Quit1Click(TObject *Sender)
{
   if(closed == 0)
	if (MessageDlg("Сохранить игру?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo,0) == mrYes)
	{
		 Save1->Click();
	}
	closed = 1;
	Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Open2Click(TObject *Sender)
{
	if(OpenTextFileDialog1->Execute())
	{
		ifstream fin(OpenTextFileDialog1->FileName.c_str());
		char c;
		fin >> game_type >> whose_move >> num_checkers[0] >> num_checkers[1]  >> icon;
		for(int i=0; i<10; i++)
		{
			for(int j=0; j<10; j++)
				fin >> play_field[i][j];
		}
		for(int i=0; i<12; i++)
			fin >> player[0][i].live >> player[0][i].xpos >> player[0][i].ypos >> player[0][i].queen;;
		for(int i=0; i<12; i++)
			fin >> player[1][i].live >> player[1][i].xpos >> player[1][i].ypos >> player[1][i].queen;
		for(int i=0; i<9; i+=2)
			for(int j=0; j<9; j+=2)
			{
				DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(j,i),Back1->Canvas,Rect(0,0,Back1->Width ,Back1->Height));
				DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(j+1,i),Back2->Canvas,Rect(0,0,Back2->Width ,Back2->Height));
			}
		 for(int i=1; i<9; i+=2)
			for(int j=0; j<9; j+=2)
			{
				DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(j, i), Back2->Canvas,Rect(0, 0, Back2->Width, Back2->Height));
				DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(j+1, i), Back1->Canvas,Rect(0, 0, Back1->Width, Back1->Height));
			}
		 for(int j=0; j<2; j++)
			 for(int i=0; i<12; i++)
			 {
				if(player[j][i].live == true)
				{
					First->LoadFromFile(texture[player[j][i].queen][1-(icon+j)%2].c_str());
					DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(player[j][i].xpos-1,player[j][i].ypos-1),First->Canvas,Rect(0,0,First->Width ,First->Height));
				}
			 }
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
	Button1->Click();
	BitBtn1->Visible = false;
	BitBtn1->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	s++;
	Label5->Caption = "";
	if(s == 60)
	{
		s = 0;
		m++;
		if(m == 60)
		{
			m = 0;
			h++;
		}
	}
   if(h<10) Label5->Caption = Label5->Caption + '0'+ IntToStr(h).c_str(); else Label5->Caption = Label5->Caption + IntToStr(h).c_str();
   Label5->Caption = Label5->Caption + ':';
   if(m<10)	Label5->Caption = Label5->Caption + '0'+ IntToStr(m).c_str(); else Label5->Caption = Label5->Caption + IntToStr(m).c_str();
   Label5->Caption = Label5->Caption + ':';
   if(s<10)	Label5->Caption = Label5->Caption + '0'+ IntToStr(s).c_str(); else Label5->Caption = Label5->Caption + IntToStr(s).c_str();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::N1Click(TObject *Sender)
{
	if(whose_move == 1)
		whose_move = 2;
	else
		whose_move = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Save1Click(TObject *Sender)
{
	if(SaveTextFileDialog1->Execute())
	{
		ofstream fout(SaveTextFileDialog1->FileName.c_str());
		fout << game_type << ' ' << whose_move << ' ' << num_checkers[0] << ' ' << num_checkers[1] << ' ' << icon << '\n' ;
		for(int i=0; i<10; i++)
		{
			for(int j=0; j<10; j++)
				fout << play_field[i][j] << ' ';
			fout << '\n';
		}
		for(int i=0; i<12; i++)
			fout<< player[0][i].live<<' '<<player[0][i].xpos<<' '<<player[0][i].ypos<<' '<<player[0][i].queen<<' ';
		fout << '\n';
		for(int i=0; i<12; i++)
			fout << player[1][i].live<< ' '<<player[1][i].xpos<<' '<<player[1][i].ypos<<' '<<player[1][i].queen<<' ';
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
  	if(closed == 0)
		if (MessageDlg("Сохранить игру?", mtConfirmation, TMsgDlgButtons() << mbYes << mbNo,0) == mrYes)
		{
			 Save1->Click();
			 closed = 1;
		}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::k1Click(TObject *Sender)
{
	Button1->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Quit2Click(TObject *Sender)
{
	Quit1->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Save2Click(TObject *Sender)
{
	Save1->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Open3Click(TObject *Sender)
{
	Open2->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Missamove1Click(TObject *Sender)
{
	N1->Click();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Showpossiblemoves1Click(TObject *Sender)
{
	if(Showpossiblemoves1->Checked == true)
		Showpossiblemoves1->Checked = false;
	else
		Showpossiblemoves1->Checked = true;
}
//---------------------------------------------------------------------------

