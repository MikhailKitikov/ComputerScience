#define _CRT_SECURE_NO_WARNINGS
#undef UNICODE
#define TIMER_ID 100
#define CIRC_CNT 2
#define CIRC_RAD 40

#include <windows.h>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <Commctrl.h>
#include "KWnd.h"
#include "resource.h"

#pragma comment(lib, "comctl32.lib")
#include <commctrl.h>
#include <commdlg.h>

#define ESC_OF "Отказ от выбора или ошибка выполнения функции "

using namespace std;

HWND hStatus;

HINSTANCE hDlgInstance;
BOOL CALLBACK DlgProc(HWND hwnd, UINT Msg, WPARAM wParam, LPARAM lParam);
void SetIsotropic(HDC hdc, int cxClient, int cyClient);
HBRUSH hBrush;

OPENFILENAME ofn;
char szFile[MAX_PATH];
ifstream fin;

INT circlesCount;
INT circlesRadius;
vector<vector<POINT> > circles;
int currCircle[2];

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//==================================================================== 
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	KWnd mainWnd("Kitikov_Lab5", hInstance, nCmdShow, WndProc,
		MAKEINTRESOURCE(IDR_MENU1), 100, 100, 400, 300);

	hStatus = CreateStatusWindow(WS_CHILD | WS_VISIBLE,
		TEXT("Число строк: 2; Радиус окружностей: 40"), mainWnd.GetHWnd(), 10000);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

//==================================================================== 
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT ps;
	RECT rcClient;
	BOOL success;
	static COLORREF textColor;
	static HPEN hPen;
	static HBRUSH hInitBrush;

	int n, r, k, tRad;
	int X, Y;
	int w;

	switch (uMsg) {
	case WM_CREATE: {

		// Color struct
		ofn.lStructSize = sizeof(OPENFILENAME);
		ofn.hwndOwner = hWnd;
		ofn.lpstrFile = szFile;
		ofn.nMaxFile = sizeof(szFile);

		// Timer
		SetTimer(hWnd, TIMER_ID, 300, NULL);

		// Drawing
		circlesCount = CIRC_CNT;
		circlesRadius = CIRC_RAD;
		hInitBrush = CreateSolidBrush(RGB(255, 255, 255));
		hBrush = CreateSolidBrush(RGB(0, 0, 0));
		hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));		

		k = (circlesCount + 1) / 2;
		n = 2 * k + circlesCount;
		r = circlesRadius;
		w = (2 * n - 1) * 2 * r;
		k = n;

		circles.resize(n);

		X = -w / 2;

		if (circlesCount % 2 == 0) {
			Y = 2 * r;
			for (int i = 0; i < (n + 1) / 2; ++i) {
				circles[i].resize(k);
				circles[n - i - 1].resize(k);
				for (int j = 0; j < k; ++j) {
					circles[i][j].x = X;
					circles[i][j].y = Y;
					circles[n - i - 1][j].x = X;
					circles[n - i - 1][j].y = -Y;
					X += 4 * r;
				}

				k -= 2;
				w = (2 * k - 1) * 2 * r;
				X = -w / 2;
				Y += 4 * r;
			}
		}
		else {
			circles[0].resize(k);
			Y = 0;
			int i = 0;
			for (int j = 0; j < k; ++j) {
				circles[i][j].x = X;
				circles[i][j].y = Y;
				X += 4 * r;
			}
			k -= 2;
			w = (2 * k - 1) * 2 * r;
			X = -w / 2;
			Y += 4 * r;
			for (int i = 1; i < (n + 1) / 2; ++i) {
				circles[i].resize(k);
				circles[n - i].resize(k);
				for (int j = 0; j < k; ++j) {
					circles[i][j].x = X;
					circles[i][j].y = Y;
					circles[n - i][j].x = X;
					circles[n - i][j].y = -Y;
					X += 4 * r;
				}

				k -= 2;
				w = (2 * k - 1) * 2 * r;
				X = -w / 2;
				Y += 4 * r;
			}
		}

		currCircle[0] = 0;
		currCircle[1] = 0;

		hDC = GetDC(hWnd);
		break;
	}
	case WM_COMMAND: {
		switch (LOWORD(wParam)) {

		case IDM_OPEN:
			strcpy(szFile, "");
			success = GetOpenFileName(&ofn);
			if (success)
				MessageBox(hWnd, ofn.lpstrFile, "Открывается файл:", MB_OK);
			else
				MessageBox(hWnd, ESC_OF"GetOpenFileName",
					"Отказ от выбора или ошибка", MB_ICONWARNING);
			break;

		case IDM_SETTINGS:
			DialogBox(hDlgInstance, MAKEINTRESOURCE(IDD_SETTINGS),
				hWnd, (DLGPROC)DlgProc);
			break;

		case IDM_EXIT:
			SendMessage(hWnd, WM_DESTROY, 0, 0);
			break;

		default:
			break;
		}
		InvalidateRect(hWnd, NULL, TRUE);
		break;
	}
	case WM_PAINT: {
		hDC = BeginPaint(hWnd, &ps);
		GetClientRect(hWnd, &rcClient);
		SetIsotropic(hDC, rcClient.right, rcClient.bottom);

		SelectObject(hDC, (HBRUSH)hInitBrush);
		SelectObject(hDC, (HPEN)hPen);

		k = (circlesCount + 1) / 2;
		n = 2 * k + circlesCount;
		r = circlesRadius;
		w = (2 * n - 1) * 2 * r;
		k = n;

		for (int i = 0; i < (n + 1) / 2; ++i) {
			for (int j = 0; j < k; ++j) {
				X = circles[i][j].x;
				Y = circles[i][j].y;
				if (!(j == 0 || j == k - 1 || j == k - 2)) {
					Rectangle(hDC, X, Y, X + 4 * r, Y + 4 * r);
					Rectangle(hDC, X, -Y, X + 4 * r, -Y - 4 * r);
				}
				else {
					if (i == 0)
						if (i == 0 && (j == 0 || j == k - 2)) {
							MoveToEx(hDC, X, Y, NULL);
							LineTo(hDC, X + 4 * r, Y);
						}
					if (i == (n + 1) / 2 - 1) {
						MoveToEx(hDC, X, Y, NULL);
						LineTo(hDC, X, Y - 4 * r);
						MoveToEx(hDC, X, -Y, NULL);
						LineTo(hDC, X, -Y + 4 * r);
					}
				}
				if (i == 0 && j != k - 1 && circlesCount % 2 == 0) {
					Rectangle(hDC, X, Y, X + 4 * r, Y - 4 * r);
				}
			}

			k -= 2;
		}

		k = n;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < circles[i].size(); ++j) {	
				X = circles[i][j].x;
				Y = circles[i][j].y;
				Ellipse(hDC, X - r, Y - r,
					X + r, Y + r);
				SelectObject(hDC, (HBRUSH)hInitBrush);
			}
		}

		SelectObject(hDC, (HBRUSH)hBrush);
		tRad = 2 * r;

		for (int i = 0; i < n; ++i) {
			if (i == currCircle[0]) {
				int j = (currCircle[1]) ? circles[i].size() - 1 : 0;
				X = circles[i][j].x;
				Y = circles[i][j].y;
				Ellipse(hDC, X - tRad, Y - tRad,
					X + tRad, Y + tRad);
			}
		}

		SelectObject(hDC, (HBRUSH)hInitBrush);

		EndPaint(hWnd, &ps);
		break;
	}
	case WM_TIMER: {
		k = (circlesCount + 1) / 2;
		n = 2 * k + circlesCount;
		if (circlesCount == 1) {
			if (currCircle[0] == 0) {
				if (currCircle[1] == 0)
					++currCircle[0];
				else
					currCircle[0] = n - 1;
				InvalidateRect(hWnd, NULL, true);
				break;
			}
			if (currCircle[0] == 1) {
				--currCircle[0];
				currCircle[1] = 1;
				InvalidateRect(hWnd, NULL, true);
				break;
			}
			if (currCircle[0] == 2) {
				currCircle[0] = 0;
				currCircle[1] = 0;
				InvalidateRect(hWnd, NULL, true);
				break;
			}				
		}
		else {
			if (currCircle[0] < (n + 1) / 2 - 1 && currCircle[1] == 0) {
				++currCircle[0];
				InvalidateRect(hWnd, NULL, true);
				break;
			}
			if (currCircle[0] == (n + 1) / 2 - 1) {
				if (circlesCount % 2 != 0 || (circlesCount % 2 == 0 && currCircle[1] == 1)) {
					--currCircle[0];
				}
				currCircle[1] = 1;
				InvalidateRect(hWnd, NULL, true);
				break;
			}
			if (currCircle[0] == 0 && currCircle[1] == 1) {
				currCircle[0] = n - 1;
				InvalidateRect(hWnd, NULL, true);
				break;
			}
			if (currCircle[0] < (n + 1) / 2 - 1 && currCircle[1] == 1) {
				--currCircle[0];
				InvalidateRect(hWnd, NULL, true);
				break;
			}


			if (currCircle[0] > (n + 1) / 2 && currCircle[1] == 1) {
				--currCircle[0];
				InvalidateRect(hWnd, NULL, true);
				break;
			}
			if (currCircle[0] == (n + 1) / 2) {
				if (circlesCount % 2 != 0 || (circlesCount % 2 == 0 && currCircle[1] == 0)) {
					++currCircle[0];
				}
				currCircle[1] = 0;
				InvalidateRect(hWnd, NULL, true);
				break;
			}
			if (currCircle[0] == n - 1 && currCircle[1] == 0) {
				currCircle[0] = 0;
				InvalidateRect(hWnd, NULL, true);
				break;
			}
			if (currCircle[0] > (n + 1) / 2 && currCircle[1] == 0) {
				++currCircle[0];
				InvalidateRect(hWnd, NULL, true);
				break;
			}
		}
		
	}
	case WM_SIZE: {
		SendMessage(hStatus, WM_SIZE, wParam, lParam);
		break;
	}
	case WM_DESTROY: {
		DeleteObject((HBRUSH)hBrush);
		DeleteObject((HPEN)hPen);
		KillTimer(hWnd, TIMER_ID);
		PostQuitMessage(0);
		break;
	}
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;
}
//====================================================================
BOOL CALLBACK DlgProc(HWND hWndDlg, UINT Msg, WPARAM wParam, LPARAM lParam) {

	static HWND hstrspin, hradspin, hstrval, hradval,
				hchoosecolor, hmanualinput, hfileinput, hrgb, hred, hgreen, hblue;

	static CHOOSECOLOR cc;
	static COLORREF acrCustClr[16];

	static int currStr, currRad;
	int tempVal, n, r, k, w;
	char buf [21];
	string strstr;
	int X, Y;
	char* err;
	static bool input;
	static bool color;

	static bool col[3];

	switch (Msg) {
	case WM_INITDIALOG: {
		input = 0;
		color = 0;
		fin.open(ofn.lpstrFile);

		// Color struct
		cc.lStructSize = sizeof(CHOOSECOLOR);
		cc.hwndOwner = hWndDlg;
		cc.lpCustColors = (LPDWORD)acrCustClr;
		cc.Flags = CC_FULLOPEN | CC_RGBINIT;

		// Control elements
		hstrval = GetDlgItem(hWndDlg, IDC_STRVAL);
		SetWindowText(hstrval, "3");
		hradval = GetDlgItem(hWndDlg, IDC_RADVAL);
		SetWindowText(hradval, "40");
		hchoosecolor = GetDlgItem(hWndDlg, IDC_CHOOSE_COLOR);
		hmanualinput = GetDlgItem(hWndDlg, IDC_MANUAL_INPUT);
		SendMessage(hmanualinput, BM_SETCHECK, TRUE, 0L);
		hfileinput = GetDlgItem(hWndDlg, IDC_FILE_INPUT);
		hrgb = GetDlgItem(hWndDlg, IDC_RGB);
		hred = GetDlgItem(hWndDlg, IDC_RED);
		hgreen = GetDlgItem(hWndDlg, IDC_GREEN);
		hblue = GetDlgItem(hWndDlg, IDC_BLUE);

		// Figure
		currStr = circlesCount;
		currRad = circlesRadius;
		return true;
	}
	case WM_COMMAND: {
		switch (wParam) {
		case WM_DESTROY: {
			EndDialog(hWndDlg, 0);
			return true;
		}
		case IDOK: {
			if (input == 0) {
				GetWindowText(hstrval, buf, 20);
				currStr = strtol(buf, &err, 10);
				if (*err) {
					MessageBox(hWndDlg, "Некорректный ввод!", "Ошибка!", MB_OK);
					break;
				}
				GetWindowText(hradval, buf, 20);
				currRad = strtol(buf, &err, 10);
				if (*err) {
					MessageBox(hWndDlg, "Некорректный ввод!", "Ошибка!", MB_OK);
					break;
				}
			}
			else
			{
				fin >> currStr >> currRad;
			}
			circlesCount = currStr;
			circlesRadius = currRad;

			if (SendMessage(hrgb, BM_GETCHECK, 0, 0) == BST_CHECKED) {
				if (SendMessage(hred, BM_GETCHECK, 0, 0) == BST_CHECKED)
					col[0] = true;
				if (SendMessage(hgreen, BM_GETCHECK, 0, 0) == BST_CHECKED)
					col[1] = true;
				if (SendMessage(hblue, BM_GETCHECK, 0, 0) == BST_CHECKED)
					col[2] = true;
				hBrush = CreateSolidBrush(RGB(col[0] * 255, col[1] * 255, col[2] * 255));
			}
			else
			{
				hBrush = CreateSolidBrush(cc.rgbResult);
			}

			for (int i = 0; i < circles.size(); ++i)
				circles[i].clear();
			circles.clear();

			k = (circlesCount + 1) / 2;
			n = 2 * k + circlesCount;
			r = circlesRadius;
			w = (2 * n - 1) * 2 * r;
			k = n;

			circles.resize(n);

			X = -w / 2;

			if (circlesCount % 2 == 0) {
				Y = 2 * r;
				for (int i = 0; i < (n + 1) / 2; ++i) {
					circles[i].resize(k);
					circles[n - i - 1].resize(k);
					for (int j = 0; j < k; ++j) {
						circles[i][j].x = X;
						circles[i][j].y = Y;
						circles[n - i - 1][j].x = X;
						circles[n - i - 1][j].y = -Y;
						X += 4 * r;
					}

					k -= 2;
					w = (2 * k - 1) * 2 * r;
					X = -w / 2;
					Y += 4 * r;
				}
			}
			else {
				circles[0].resize(k);
				Y = 0;
				int i = 0;
				for (int j = 0; j < k; ++j) {
					circles[i][j].x = X;
					circles[i][j].y = Y;
					X += 4 * r;
				}
				k -= 2;
				w = (2 * k - 1) * 2 * r;
				X = -w / 2;
				Y += 4 * r;
				for (i = 1; i < (n + 1) / 2; ++i) {
					circles[i].resize(k);
					circles[n - i].resize(k);
					for (int j = 0; j < k; ++j) {
						circles[i][j].x = X;
						circles[i][j].y = Y;
						circles[n - i][j].x = X;
						circles[n - i][j].y = -Y;
						X += 4 * r;
					}

					k -= 2;
					w = (2 * k - 1) * 2 * r;
					X = -w / 2;
					Y += 4 * r;
				}
			}

			currCircle[0] = 0;
			currCircle[1] = 0; 

			strstr = "Число строк : ";
			strstr += _itoa(circlesCount, buf, 10);
			strstr += "; Радиус окружностей : ";
			strstr += _itoa(circlesRadius, buf, 10);
			SetWindowText(hStatus, (LPCSTR)strstr.c_str());
			UpdateWindow(hStatus);

			EndDialog(hWndDlg, 0);
			break;
		}
		case IDC_CHOOSE_COLOR: {
			ChooseColor(&cc);
			break;
		}
		case IDC_FILE_INPUT: {
			input = 1;
			break;
		}
		case IDC_MANUAL_INPUT: {
			input = 0;
			break;
		}
		}
		return true;
	}
	}
	return false;
}
//============================================================
void SetIsotropic(HDC hdc, int cxClient, int cyClient) {
	SetMapMode(hdc, MM_ISOTROPIC);
	SetWindowExtEx(hdc, cxClient, cyClient, NULL);
	SetViewportExtEx(hdc, cxClient / 2, -cyClient / 2, NULL);
	SetViewportOrgEx(hdc, cxClient / 2, cyClient / 2, NULL);
}

//////////////////////////////////////////////////////////////////////
