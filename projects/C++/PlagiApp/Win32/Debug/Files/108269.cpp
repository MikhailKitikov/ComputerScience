//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <ctime>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int map1[11][11], map2[11][11];
int sh1[4],sh2[4];
int K=0,G=1,N=0,H=0;
Graphics::TBitmap  *c=new Graphics::TBitmap(), *w=new Graphics::TBitmap();
Graphics::TBitmap  *k1=new Graphics::TBitmap(), *k2=new Graphics::TBitmap(), *k2v=new Graphics::TBitmap(), *k3=new Graphics::TBitmap(), *k3v=new Graphics::TBitmap(), *k4=new Graphics::TBitmap(), *k4v=new Graphics::TBitmap();
Graphics::TBitmap  *mm=new Graphics::TBitmap(), *kr=new Graphics::TBitmap();
Graphics::TBitmap  *kb1=new Graphics::TBitmap(), *kb2=new Graphics::TBitmap(), *kb2v=new Graphics::TBitmap(), *kb3=new Graphics::TBitmap(), *kb3v=new Graphics::TBitmap(), *kb4=new Graphics::TBitmap(), *kb4v=new Graphics::TBitmap();
TRect rec;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
  w->LoadFromFile("w.bmp");
  c->LoadFromFile("c.bmp");
  k1->LoadFromFile("k1.bmp");
  k2->LoadFromFile("k2.bmp");
  k2v->LoadFromFile("k2v.bmp");
  k3->LoadFromFile("k3.bmp");
  k3v->LoadFromFile("k3v.bmp");
  k4->LoadFromFile("k4.bmp");
  k4v->LoadFromFile("k4v.bmp");
  mm->LoadFromFile("mm.bmp");
  kr->LoadFromFile("kr.bmp");
  kb1->LoadFromFile("k1.bmp");
  kb2->LoadFromFile("k2.bmp");
  kb2v->LoadFromFile("k2v.bmp");
  kb3->LoadFromFile("k3.bmp");
  kb3v->LoadFromFile("k3v.bmp");
  kb4->LoadFromFile("k4.bmp");
  kb4v->LoadFromFile("k4v.bmp");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DrawGrid1DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
		  TGridDrawState State)
{
	 switch (map1[ARow][ACol]%10)
	 {
		case 5:
		{
			rec=Bounds(72*(ACol-1),0,72,72);
			DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),w->Canvas,rec);
			break;
		}
		case 6:
		{
			rec=Bounds(0,72*(ARow-1),72,72);
			DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),c->Canvas,rec);
			break;
		}
		case 7:
		{
			rec=Bounds(0,0,72,72);
			DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),mm->Canvas,rec);
			break;
		}
	 }
   if (G==1)
   {
	 switch (map1[ARow][ACol]%10)
	 {
		case 1:
		{
			rec=Bounds(0,0,30,30);
			DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),k1->Canvas,rec);
			break;
		}
		case 2:
		{
			if (map1[ARow][ACol]%100/10==1)
			{
				rec=Bounds((map1[ARow][ACol]/100-1)*30,0,30,30);
				DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),k2->Canvas,rec);
			}
			if (map1[ARow][ACol]%100/10==2)
			{
				rec=Bounds(0,(map1[ARow][ACol]/100-1)*30,30,30);
				DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),k2v->Canvas,rec);
			}
			break;
		}
		case 3:
		{
			if (map1[ARow][ACol]%100/10==1)
			{
				rec=Bounds((map1[ARow][ACol]/100-1)*30,0,30,30);
				DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),k3->Canvas,rec);
			}
			if (map1[ARow][ACol]%100/10==2)
			{
				rec=Bounds(0,(map1[ARow][ACol]/100-1)*30,30,30);
				DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),k3v->Canvas,rec);
			}
			break;
		}
		case 4:
		{
			if (map1[ARow][ACol]%100/10==1)
			{
				rec=Bounds((map1[ARow][ACol]/100-1)*30,0,30,30);
				DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),k4->Canvas,rec);
			}
			if (map1[ARow][ACol]%100/10==2)
			{
				rec=Bounds(0,(map1[ARow][ACol]/100-1)*30,30,30);
				DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),k4v->Canvas,rec);
			}
			break;
		}
	 }
   }
	 switch (map1[ARow][ACol]/1000)
	 {
		case 1:
		{
			rec=Bounds(0,0,72,72);
			DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),kr->Canvas,rec);
			break;
		}
		case 2:
		{
            switch (map1[ARow][ACol]%10)
			{
				case 1:
				{
					rec=Bounds(0,0,30,30);
					DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),kb1->Canvas,rec);
					break;
				}
				case 2:
				{
					if (map1[ARow][ACol]%100/10==1)
					{
						rec=Bounds((map1[ARow][ACol]/100-1)*30,0,30,30);
						DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),kb2->Canvas,rec);
					}
					if (map1[ARow][ACol]%100/10==2)
					{
						rec=Bounds(0,(map1[ARow][ACol]/100-1)*30,30,30);
						DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),kb2v->Canvas,rec);
					}
					break;
				}
				case 3:
				{
					if (map1[ARow][ACol]%100/10==1)
					{
						rec=Bounds((map1[ARow][ACol]/100-1)*30,0,30,30);
						DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),kb3->Canvas,rec);
					}
					if (map1[ARow][ACol]%100/10==2)
					{
						rec=Bounds(0,(map1[ARow][ACol]/100-1)*30,30,30);
						DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),kb3v->Canvas,rec);
					}
					break;
				}
				case 4:
				{
					if (map1[ARow][ACol]%100/10==1)
					{
						rec=Bounds((map1[ARow][ACol]/100-1)*30,0,30,30);
						DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),kb4->Canvas,rec);
					}
					if (map1[ARow][ACol]%100/10==2)
					{
						rec=Bounds(0,(map1[ARow][ACol]/100-1)*30,30,30);
						DrawGrid1->Canvas->CopyRect(DrawGrid1->CellRect(ACol,ARow),kb4v->Canvas,rec);
					}
					break;
				}
	 		}
        }
	 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DrawGrid2DrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
		  TGridDrawState State)
{
	 switch (map2[ARow][ACol]%10)
	 {
		case 5:
		{
			rec=Bounds(72*(ACol-1),0,72,72);
			DrawGrid2->Canvas->CopyRect(DrawGrid2->CellRect(ACol,ARow),w->Canvas,rec);
			break;
		}
		case 6:
		{
			rec=Bounds(0,72*(ARow-1),72,72);
			DrawGrid2->Canvas->CopyRect(DrawGrid2->CellRect(ACol,ARow),c->Canvas,rec);
			break;
		}
		case 7:
		{
			rec=Bounds(0,0,72,72);
			DrawGrid2->Canvas->CopyRect(DrawGrid2->CellRect(ACol,ARow),mm->Canvas,rec);
			break;
		}
	 }
   if (G==1)
   {
	 switch (map2[ARow][ACol]%10)
	 {
		case 1:
		{
			rec=Bounds(0,0,30,30);
			DrawGrid2->Canvas->CopyRect(DrawGrid2->CellRect(ACol,ARow),k1->Canvas,rec);
			break;
		}
		case 2:
		{
			if (map2[ARow][ACol]%100/10==1)
			{
				rec=Bounds((map2[ARow][ACol]/100-1)*30,0,30,30);
				DrawGrid2->Canvas->CopyRect(DrawGrid2->CellRect(ACol,ARow),k2->Canvas,rec);
			}
			if (map2[ARow][ACol]%100/10==2)
			{
				rec=Bounds(0,(map2[ARow][ACol]/100-1)*30,30,30);
				DrawGrid2->Canvas->CopyRect(DrawGrid2->CellRect(ACol,ARow),k2v->Canvas,rec);
			}
			break;
		}
		case 3:
		{
			if (map2[ARow][ACol]%100/10==1)
			{
				rec=Bounds((map2[ARow][ACol]/100-1)*30,0,30,30);
				DrawGrid2->Canvas->CopyRect(DrawGrid2->CellRect(ACol,ARow),k3->Canvas,rec);
			}
			if (map2[ARow][ACol]%100/10==2)
			{
				rec=Bounds(0,(map2[ARow][ACol]/100-1)*30,30,30);
				DrawGrid2->Canvas->CopyRect(DrawGrid2->CellRect(ACol,ARow),k3v->Canvas,rec);
			}
			break;
		}
		case 4:
		{
			if (map2[ARow][ACol]%100/10==1)
			{
				rec=Bounds((map2[ARow][ACol]/100-1)*30,0,30,30);
				DrawGrid2->Canvas->CopyRect(DrawGrid2->CellRect(ACol,ARow),k4->Canvas,rec);
			}
			if (map2[ARow][ACol]%100/10==2)
			{
				rec=Bounds(0,(map2[ARow][ACol]/100-1)*30,30,30);
				DrawGrid2->Canvas->CopyRect(DrawGrid2->CellRect(ACol,ARow),k4v->Canvas,rec);
			}
			break;
		}
	 }
   }
	 switch (map2[ARow][ACol]/1000)
	 {
		case 1:
		{
			rec=Bounds(0,0,72,72);
			DrawGrid2->Canvas->CopyRect(DrawGrid2->CellRect(ACol,ARow),kr->Canvas,rec);
			break;
		}
		case 2:
		{
            switch (map2[ARow][ACol]%10)
			{
				case 1:
				{
					rec=Bounds(0,0,30,30);
					DrawGrid2->Canvas->CopyRect(DrawGrid2->CellRect(ACol,ARow),kb1->Canvas,rec);
					break;
				}
				case 2:
				{
					if (map2[ARow][ACol]%100/10==1)
					{
						rec=Bounds((map2[ARow][ACol]/100-1)*30,0,30,30);
						DrawGrid2->Canvas->CopyRect(DrawGrid2->CellRect(ACol,ARow),kb2->Canvas,rec);
					}
					if (map2[ARow][ACol]%100/10==2)
					{
						rec=Bounds(0,(map2[ARow][ACol]/100-1)*30,30,30);
						DrawGrid2->Canvas->CopyRect(DrawGrid2->CellRect(ACol,ARow),kb2v->Canvas,rec);
					}
					break;
				}
				case 3:
				{
					if (map2[ARow][ACol]%100/10==1)
					{
						rec=Bounds((map2[ARow][ACol]/100-1)*30,0,30,30);
						DrawGrid2->Canvas->CopyRect(DrawGrid2->CellRect(ACol,ARow),kb3->Canvas,rec);
					}
					if (map2[ARow][ACol]%100/10==2)
					{
						rec=Bounds(0,(map2[ARow][ACol]/100-1)*30,30,30);
						DrawGrid2->Canvas->CopyRect(DrawGrid2->CellRect(ACol,ARow),kb3v->Canvas,rec);
					}
					break;
				}
				case 4:
				{
					if (map2[ARow][ACol]%100/10==1)
					{
						rec=Bounds((map2[ARow][ACol]/100-1)*30,0,30,30);
						DrawGrid2->Canvas->CopyRect(DrawGrid2->CellRect(ACol,ARow),kb4->Canvas,rec);
					}
					if (map2[ARow][ACol]%100/10==2)
					{
						rec=Bounds(0,(map2[ARow][ACol]/100-1)*30,30,30);
						DrawGrid2->Canvas->CopyRect(DrawGrid2->CellRect(ACol,ARow),kb4v->Canvas,rec);
					}
					break;
				}
	 		}
		}
	 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
  if (MessageDlg("Сохранить игру?", mtWarning, TMsgDlgButtons() << mbYes << mbNo << mbCancel,0) == mrNo)
  {
		 Form1->Close();
  }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
  DrawGrid2->Left=8;
  DrawGrid2->Top=83;
  Label2->Left=88;
  Label2->Top=20;
  N=1;
  Image1->Visible=false;
  Image2->Visible=false;
  DrawGrid2->Enabled=false;
  DrawGrid2->Visible=false;
  Label2->Visible=false;
  G=1;
  for (int i=0; i < 11; i++)
  {
	   for (int j = 0; j < 11; j++)
	   {
			map1[i][j]=0;
			map2[i][j]=0;
	   }
  }
  for (int i=1; i < 11; i++)
  {
	  map1[0][i]=5;
	  map2[0][i]=5;
	  map1[i][0]=6;
	  map2[i][0]=6;
  }
  DrawGrid1->Enabled=true;
  DrawGrid1->Visible=true;
  Label1->Visible=true;
  BitBtn3->Visible=true;
  for (int i = 0; i < 4; i++)
  {
	   sh1[i]=0;
	   sh2[i]=0;
  }
  BitBtn5->Enabled=true;
  BitBtn5->Visible=true;
  BitBtn6->Enabled=true;
  BitBtn6->Visible=true;
  BitBtn7->Enabled=true;
  BitBtn7->Visible=true;
  BitBtn8->Enabled=true;
  BitBtn8->Visible=true;
  BitBtn9->Enabled=true;
  BitBtn9->Visible=true;
  BitBtn10->Enabled=true;
  BitBtn10->Visible=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DrawGrid1SelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect)

{
  int X1, Y1;
  X1=ACol;
  Y1=ARow;
  if (G==1)
  {
  		if ((K==0)&&(sh1[1]+sh1[2]+sh1[3]+sh1[0]!=10)&&(map1[Y1][X1]==0))
		{
				ShowMessage("Выберите корабль");
		}
		if ((map1[Y1][X1]/100>0)&&(map1[Y1][X1]%10>1)&&(K!=5))
		{
			if ((map1[Y1][X1]/10)%10==1)
			{
				int s=0;
				X1-=map1[Y1][X1]/100-1;
				for (int i=Y1+2; i < Y1+1+map1[Y1][X1]%10; i++)
				{
						for (int j = X1-1; j < X1+2; j++)
						{
							s+=map1[i][j];
						}
				}
				if ((s<100)&&(Y1<12-map1[Y1][X1]%10))
				{
					for (int i=1; i < map1[Y1][X1]%10; i++)
					{
							map1[Y1+i][X1]=map1[Y1][X1+i]+10;
							map1[Y1][X1+i]=0;
					}
					map1[Y1][X1]+=10;
				}
			}
			else
			{
				int s=0;
				Y1-=map1[Y1][X1]/100-1;
				for (int i=Y1-1; i < Y1+2; i++)
				{
						for (int j = X1+2; j < X1+1+map1[Y1][X1]%10; j++)
						{
							s+=map1[i][j];
						}
				}
				if ((s<100)&&(X1<12-map1[Y1][X1]%10))
				{
					for (int i=1; i < map1[Y1][X1]%10; i++)
					{
							map1[Y1][X1+i]=map1[Y1+i][X1]-10;
							map1[Y1+i][X1]=0;
					}
					map1[Y1][X1]-=10;
				}
			}
		}
		if ((map1[Y1][X1]==0)&&(K<=4)&&(K>0))
		{
			if ((X1>0)&&(Y1>0)&&(sh1[K-1]<5-K))
			{
					int s=0;
					for (int i=Y1-1; i < Y1+2; i++)
					{
						for (int j = X1-1; j < X1+K+1; j++)
						{
							s+=map1[i][j];
						}
					}
					if ((s<100)&&(X1<12-K))
					{
						for (int i = 1; i <=K; i++)
						{
							map1[Y1][X1+i-1]=100*i+10+K;
						}
						sh1[K-1]++;
						if (sh1[K-1]==5-K)
						{
							switch (K)
							{
							case 1:
								BitBtn5->Enabled=false; break;
							case 2:
								BitBtn6->Enabled=false; break;
							case 3:
								BitBtn7->Enabled=false; break;
							case 4:
								BitBtn8->Enabled=false; break;
							}
							K=0;
						}
					}
					else
					{
						if (Y1<12-K)
						{
							int s=0;
							for (int i=Y1-1; i < Y1+K+1; i++)
							{
								for (int j = X1-1; j < X1+2; j++)
								{
									s+=map1[i][j];
								}
							}
							if (s<100)
							{
								for (int i = 1; i <=K; i++)
								{
									map1[Y1+i-1][X1]=100*i+20+K;
								}
								sh1[K-1]++;
								if (sh1[K-1]==5-K)
								{
									switch (K)
									{
										case 1:
											BitBtn5->Enabled=false; break;
										case 2:
											BitBtn6->Enabled=false; break;
										case 3:
											BitBtn7->Enabled=false; break;
										case 4:
											BitBtn8->Enabled=false; break;
									}
									K=0;
								}
							}
						}
					}
			}
		}
		if ((K==5)&&(map1[Y1][X1]!=0))
		{
			int l=map1[Y1][X1]%10;
			if ((map1[Y1][X1]/10)%10==1)
			{
				X1-=map1[Y1][X1]/100-1;
				for (int i = 0; i < l; i++)
				{
					map1[Y1][X1+i]=0;
				}
			}
			else
			{
				Y1-=map1[Y1][X1]/100-1;
				for (int i = 0; i < l; i++)
				{
					map1[Y1+i][X1]=0;
				}
			}
			sh1[l-1]--;
			switch (l)
			{
				case 1:
				{
					BitBtn5->Enabled=true; break;
				}
				case 2:
				{
					BitBtn6->Enabled=true; break;
				}
				case 3:
				{
					BitBtn7->Enabled=true; break;
				}
				case 4:
				{
					BitBtn8->Enabled=true; break;
				}
			}
			BitBtn3->Enabled=false;
			K=0;
		}
		if (sh1[0]+sh1[1]+sh1[2]+sh1[3]==10)
		{
			BitBtn3->Enabled=true;
  		}
  }
  if (G==2)
  {
	  if (map1[Y1][X1]==0)
	  {
		  map1[Y1][X1]=7;
		  H=1;
		  DrawGrid1->Enabled=false;
		  DrawGrid2->Enabled=true;
		  Image2->Visible=false;
		  Image1->Visible=true;
	  }
	  if (map1[Y1][X1]/100!=0)
	  {
		  map1[Y1][X1]=map1[Y1][X1]%1000+1000;
		  int s=0;
		  int l=map1[Y1][X1]%10;
		  if ((map1[Y1][X1]/10)%10==1)
		  {
				X1-=map1[Y1][X1]/100-1;
				for (int i = 0; i < l; i++)
				{
					s+=map1[Y1][X1+i]/1000;
				}
		  }
		  else
		  {
				Y1-=map1[Y1][X1]/100-1;
				for (int i = 0; i < l; i++)
				{
					s+=map1[Y1+i][X1]/1000;
				}
		  }
		  if (s=l-1)
		  {
			  if ((map1[Y1][X1]/10)%10==1)
			  {
					for (int i = 0; i < l; i++)
					{
						map1[Y1][X1+i]+=1000;
					}
			  }
			  else
			  {
					for (int i = 0; i < l; i++)
					{
						map1[Y1+i][X1]+=1000;
					}
			  }
		  }
	  }
  }
  DrawGrid1->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DrawGrid2SelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect)

{
  int X2, Y2;
  X2=ACol;
  Y2=ARow;
  if (G==1)
  {
		if ((K==0)&&(sh2[1]+sh2[2]+sh2[3]+sh2[0]!=10)&&(map2[Y2][X2]==0))
		{
				ShowMessage("Выберите корабль");
		}
		if ((map2[Y2][X2]/100>0)&&(map2[Y2][X2]%10>1)&&(K!=5))
		{
			if ((map2[Y2][X2]/10)%10==1)
			{
				int s=0;
				X2-=map2[Y2][X2]/100-1;
				for (int i=Y2+2; i < Y2+1+map2[Y2][X2]%10; i++)
				{
						for (int j = X2-1; j < X2+2; j++)
						{
							s+=map2[i][j];
						}
				}
				if ((s<100)&&(Y2<12-map2[Y2][X2]%10))
				{
					for (int i=1; i < map2[Y2][X2]%10; i++)
					{
							map2[Y2+i][X2]=map2[Y2][X2+i]+10;
							map2[Y2][X2+i]=0;
					}
					map2[Y2][X2]+=10;
				}
			}
			else
			{
				int s=0;
				Y2-=map2[Y2][X2]/100-1;
				for (int i=Y2-1; i < Y2+2; i++)
				{
						for (int j = X2+2; j < X2+1+map2[Y2][X2]%10; j++)
						{
							s+=map2[i][j];
						}
				}
				if ((s<100)&&(X2<12-map2[Y2][X2]%10))
				{
					for (int i=1; i < map2[Y2][X2]%10; i++)
					{
							map2[Y2][X2+i]=map2[Y2+i][X2]-10;
							map2[Y2+i][X2]=0;
					}
					map2[Y2][X2]-=10;
				}
			}
		}
		if ((map2[Y2][X2]==0)&&(K<=4)&&(K>0))
		{
			if ((X2>0)&&(Y2>0)&&(sh2[K-1]<5-K))
			{
					int s=0;
					for (int i=Y2-1; i < Y2+2; i++)
					{
						for (int j = X2-1; j < X2+K+1; j++)
						{
								s+=map2[i][j];
						}
					}
					if ((s<100)&&(X2<12-K))
					{
						for (int i = 1; i <=K; i++)
						{
							map2[Y2][X2+i-1]=100*i+10+K;
						}
						sh2[K-1]++;
						if (sh2[K-1]==5-K)
						{
							switch (K)
							{
							case 1:
								BitBtn5->Enabled=false; break;
							case 2:
								BitBtn6->Enabled=false; break;
							case 3:
								BitBtn7->Enabled=false; break;
							case 4:
								BitBtn8->Enabled=false; break;
							}
							K=0;
						}
					}
					else
					{
						if (Y2<12-K)
						{
							int s=0;
							for (int i=Y2-1; i < Y2+K+1; i++)
							{
								for (int j = X2-1; j < X2+2; j++)
								{
									s+=map2[i][j];
								}
							}
							if (s<100)
							{
								for (int i = 1; i <=K; i++)
								{
									map2[Y2+i-1][X2]=100*i+20+K;
								}
								sh2[K-1]++;
								if (sh2[K-1]==5-K)
								{
									switch (K)
									{
										case 1:
											BitBtn5->Enabled=false; break;
										case 2:
											BitBtn6->Enabled=false; break;
										case 3:
											BitBtn7->Enabled=false; break;
										case 4:
											BitBtn8->Enabled=false; break;
									}
									K=0;
								}
							}
						}
					}
			}
		}
		if ((K==5)&&(map2[Y2][X2]!=0))
		{
			int l=map2[Y2][X2]%10;
			if ((map2[Y2][X2]/10)%10==1)
			{
				X2-=map2[Y2][X2]/100-1;
				for (int i = 0; i < l; i++)
				{
					map2[Y2][X2+i]=0;
				}
			}
			else
			{
				Y2-=map2[Y2][X2]/100-1;
				for (int i = 0; i < l; i++)
				{
					map2[Y2+i][X2]=0;
				}
			}
			sh2[l-1]--;
			switch (l)
			{
				case 1:
				{
					BitBtn5->Enabled=true; break;
				}
				case 2:
				{
					BitBtn6->Enabled=true; break;
				}
				case 3:
				{
					BitBtn7->Enabled=true; break;
				}
				case 4:
				{
					BitBtn8->Enabled=true; break;
				}
			}
			BitBtn4->Enabled=false;
			K=0;
		}
		if (sh2[0]+sh2[1]+sh2[2]+sh2[3]==10)
		{
			BitBtn4->Enabled=true;
  		}
  }
  if (G==2)
  {
	  if (map2[Y2][X2]==0)
	  {
		  map2[Y2][X2]=7;
		  H=0;
		  DrawGrid2->Enabled=false;
		  DrawGrid1->Enabled=true;
		  Image1->Visible=false;
		  Image2->Visible=true;
	  }
	  if (map2[Y2][X2]/100!=0)
	  {
		  map2[Y2][X2]=map2[Y2][X2]/1000+1000;
      }
  }
  DrawGrid2->Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn3Click(TObject *Sender)
{
  DrawGrid1->Enabled=false;
  DrawGrid1->Visible=false;
  Label1->Visible=false;
  DrawGrid2->Enabled=true;
  DrawGrid2->Visible=true;
  Label2->Visible=true;
  BitBtn5->Enabled=true;
  BitBtn6->Enabled=true;
  BitBtn7->Enabled=true;
  BitBtn8->Enabled=true;
  BitBtn3->Enabled=false;
  BitBtn3->Visible=False;
  BitBtn4->Visible=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn4Click(TObject *Sender)
{
  G=2;
  H=N%2;
  if (H==0)
  {
	  Image2->Visible=true;
	  DrawGrid1->Enabled=true;
  }
  else
  {
	  Image1->Visible=true;
  }
  DrawGrid2->Left=425;
  Label2->Left=536;
  DrawGrid1->Visible=true;
  Label1->Visible=true;
  BitBtn4->Visible=false;
  BitBtn4->Enabled=false;
  BitBtn5->Visible=false;
  BitBtn6->Visible=false;
  BitBtn7->Visible=false;
  BitBtn8->Visible=false;
  BitBtn9->Enabled=false;
  BitBtn9->Visible=false;
  BitBtn10->Enabled=false;
  BitBtn10->Visible=false;
  DrawGrid1->Refresh();
  DrawGrid2->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn5Click(TObject *Sender)
{
  K=1;	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn6Click(TObject *Sender)
{
  K=2;	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn7Click(TObject *Sender)
{
  K=3;	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn8Click(TObject *Sender)
{
  K=4;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn9Click(TObject *Sender)
{
   K=5;	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn10Click(TObject *Sender)
{
  int X1=0,Y1=0,X2=0,Y2=0,f=0,n=0;
  srand(time(NULL));
  if (DrawGrid1->Enabled)
  {
	  for (int i = 0; i < 4; i++)
	  {
		  sh1[i]=0;
	  }
	  for (int i=1; i < 11; i++)
	  {
			for (int j = 1; j < 11; j++)
			{
				map1[i][j]=0;
			}
	  }
	  while (sh1[0]+sh1[1]+sh1[2]+sh1[3]!=10)
	  {
		  X1=rand()%10+1;
		  Y1=rand()%10+1;
		  f=rand()%2+1;
		  n=rand()%4+1;
		  if ((sh1[n-1]<5-n)&&(f==1))
		  {
				int s=0;
				for (int i=Y1-1; i < Y1+2; i++)
				{
					for (int j = X1-1; j < X1+n+1; j++)
					{
						s+=map1[i][j];
					}
				}
				if ((s<100)&&(X1<12-n))
				{
					for (int i = 1; i <=n; i++)
					{
						map1[Y1][X1+i-1]=100*i+10+n;
					}
					sh1[n-1]++;
				}
		  }
		  if ((sh1[n-1]<5-n)&&(f==2))
		  {
				int s=0;
				for (int i=Y1-1; i < Y1+n+1; i++)
				{
					for (int j = X1-1; j < X1+2; j++)
					{
						s+=map1[i][j];
					}
				}
				if ((s<100)&&(Y1<12-n))
				{
					for (int i = 1; i <=n; i++)
					{
						map1[Y1+i-1][X1]=100*i+20+n;
					}
					sh1[n-1]++;
				}
		  }
	  }
	  DrawGrid1->Refresh();
	  BitBtn3->Enabled=true;
	  BitBtn5->Enabled=false;
	  BitBtn6->Enabled=false;
	  BitBtn7->Enabled=false;
	  BitBtn8->Enabled=false;
  }
  else
  {
	  for (int i = 0; i < 4; i++)
	  {
		  sh2[i]=0;
	  }
	  for (int i=1; i < 11; i++)
	  {
			for (int j = 1; j < 11; j++)
			{
				map2[i][j]=0;
			}
	  }
	  while (sh2[0]+sh2[1]+sh2[2]+sh2[3]!=10)
	  {
		  X2=rand()%10+1;
		  Y2=rand()%10+1;
		  f=rand()%2+1;
		  n=rand()%4+1;
		  if ((sh2[n-1]<5-n)&&(f==1))
		  {
				int s=0;
				for (int i=Y2-1; i < Y2+2; i++)
				{
					for (int j = X2-1; j < X2+n+1; j++)
					{
						s+=map2[i][j];
					}
				}
				if ((s<100)&&(X2<12-n))
				{
					for (int i = 1; i <=n; i++)
					{
						map2[Y2][X2+i-1]=100*i+10+n;
					}
					sh2[n-1]++;
				}
		  }
		  if ((sh2[n-1]<5-n)&&(f==2))
		  {
				int s=0;
				for (int i=Y2-1; i < Y2+n+1; i++)
				{
					for (int j = X2-1; j < X2+2; j++)
					{
						s+=map2[i][j];
					}
				}
				if ((s<100)&&(Y2<12-n))
				{
					for (int i = 1; i <=n; i++)
					{
						map2[Y2+i-1][X2]=100*i+20+n;
					}
					sh2[n-1]++;
				}
		  }
	  }
	  DrawGrid2->Refresh();
	  BitBtn4->Enabled=true;
	  BitBtn5->Enabled=false;
	  BitBtn6->Enabled=false;
	  BitBtn7->Enabled=false;
	  BitBtn8->Enabled=false;
  }
}
//---------------------------------------------------------------------------

