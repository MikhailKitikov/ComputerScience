#ifndef _VIEW_
#define _VIEW_

class Controller;

#include "Libs.h"
#include "Controller.h"
#include "Resource.h"
#include "StringList.h"
#include "Iterator.h"

using namespace std;

class FrameView {
public:
	Controller* _controller;
	StringList* _model;
	HWND * hInput;
	HWND * hState;
	HWND * hFptr;
	HWND * hList;
	//////////////////

	FrameView(StringList* aModel, HWND * aList, HWND * aInput, HWND * aState, HWND * aFptr);

	void Update();

	void ShowMinMax(const string& aMin, const string& aMax);

	void ShowToString();

	void ShowSize();

};

#endif