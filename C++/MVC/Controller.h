#ifndef _CONTROLLER_
#define _CONTROLLER_

class FrameView;
class StringList;

#include "Libs.h"
#include "View.h"
#include "StringList.h"
#include "Resource.h"
#include "Iterator.h"

using namespace std;

class Controller {
public:
	FrameView * _view;
	StringList *_model;
	HWND * hInput;
	HWND * hState;
	//////////////

	// c/tor
	Controller(FrameView * aView, StringList * aQueue, HWND* aInput, HWND* aState);

	// controller launch
	void Start();

	// reading data
	bool InputProc(WORD command, HINSTANCE hInstance);

	// clear model data
	void Clear();

	// minimum in the queue
	const string& Min();

	// maximum in the queue
	const string& Max();
};

#endif