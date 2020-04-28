#define _CRT_SECURE_NO_WARNINGS
#undef UNICODE

#include "Libs.h"
#include "StringList.h"
#include "resource.h"
#include "View.h"
#include "Controller.h"

using namespace std;

BOOL CALLBACK DlgProc(HWND hWndDlg, UINT Msg, WPARAM wParam, LPARAM lParam);

//==================================================================== 
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_MAIN_DIALOG),
		NULL, (DLGPROC)DlgProc);
	return false;
}
//====================================================================
BOOL CALLBACK DlgProc(HWND hWndDlg, UINT Msg, WPARAM wParam, LPARAM lParam) {
	static HWND hInput;
	static HWND hState;
	static HWND hList;
	static HWND hFptr;
	static StringList MyStringList;
	static FrameView frameview(&MyStringList, &hList, &hInput, &hState, &hFptr);
	static Controller controller(&frameview, &MyStringList, &hInput, &hState);
	frameview._controller = &controller;
	static HINSTANCE hInstance = GetModuleHandle(NULL);	

	switch (Msg) {
		case WM_INITDIALOG: {
			hInput = GetDlgItem(hWndDlg, IDC_INPUT);
			hState = GetDlgItem(hWndDlg, IDC_STATE);
			hList = GetDlgItem(hWndDlg, IDC_ELEMENTS);
			hFptr = GetDlgItem(hWndDlg, IDC_FPTR);
			controller.Start();
			return true;
		}
		case WM_COMMAND: {
			if (LOWORD(wParam) == WM_DESTROY || LOWORD(wParam) == IDCLOSE) {
				EndDialog(hWndDlg, 0);
				return true;
			}
			else {
				return controller.InputProc(LOWORD(wParam), hInstance);
			}
				
		}
	}
	return false;
}