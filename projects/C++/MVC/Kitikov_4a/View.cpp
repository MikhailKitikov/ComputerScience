#include "View.h"

FrameView::FrameView(StringList* aModel, HWND * aList, HWND * aInput, HWND * aState, HWND * aFptr)
	: _model(aModel), _controller(nullptr), hList(aList), hInput(aInput), hState(aState), hFptr(aFptr) {}

void FrameView::Update() {
	string res;
	SendMessage(*hList, LB_RESETCONTENT, 0, 0);
	if (!(_model->empty())) {
		SetWindowText(*hFptr, "<1st");
		char buf[21];
		for (auto it = _model->begin(); !it.isDone(); it.next()) {
			res = it.currentItem()._val;
			SendMessage(*hList, LB_ADDSTRING, 0, (LPARAM)res.c_str());
		}
		UpdateWindow(*hList);
	}
	else {
		SetWindowText(*hFptr, "");
	}		
}

void FrameView::ShowMinMax(const string& aMin, const string& aMax) {
	ostringstream os;
	os << "[" << aMin << ", " << aMax << "]";
	SetWindowText(*hState, os.str().c_str());
}

void FrameView::ShowToString() {
	string res = _model->toString();
	SetWindowText(*hState, res.c_str());
}

void FrameView::ShowSize() {
	ostringstream os;
	os << _model->size();
	SetWindowText(*hState, os.str().c_str());
}