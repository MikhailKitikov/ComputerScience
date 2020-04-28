#include "Controller.h"
#include "View.h"
#include "StringList.h"
#include "Resource.h"

Controller::Controller(FrameView * aView, StringList * aQueue, HWND* aInput, HWND* aState)
	: _model(aQueue), _view(aView), hInput(aInput), hState(aState) {
}

bool Controller::InputProc(WORD command, HINSTANCE hInstance) {
	switch (command) {
	case IDC_PUSH: {
		char buf[51];
		try {
			if (GetWindowText(*hInput, buf, 50) == 0) { throw exception("Некорректный ввод!"); }
			_model->push_back(buf);
			SetWindowText(*hState, "");
		}
		catch (exception& e) {
			MessageBox(NULL, e.what(), "Error!", MB_OK);
			return false;
		}
		SetWindowText(*hInput, "");
		_view->Update();
		break;
	}
	//////////////
	case IDC_POP: {
		SetWindowText(*hState, "");
		try {
			_model->pop_front();
		}
		catch (exception& e) {
			MessageBox(NULL, e.what(), "Error!", MB_OK);
			return false;
		}
		_view->Update();
		break;
	}
	//////////////
	case IDC_POPBACK: {
		SetWindowText(*hState, "");
		try {
			_model->pop_back();
		}
		catch (exception& e) {
			MessageBox(NULL, e.what(), "Error!", MB_OK);
			return false;
		}
		_view->Update();
		break;
	}
	//////////////
	case IDC_CLEAR2: {
		Clear();
		break;
	}
	case IDC_MINMAX: {
		try {
			string minRes = this->Min();
			string maxRes = this->Max();
			_view->ShowMinMax(minRes, maxRes);
		}
		catch (exception& e) {
			MessageBox(NULL, e.what(), "Warning!", MB_OK);
		}		
		break;
	}
	case IDC_TOSTRING: {
		_view->ShowToString();
		break;
	}
	case IDC_SIZE: {
		_view->ShowSize();
		break;
	}
	default: {
		break;
	}
	}
	_view->Update();
	return true;
}

void Controller::Start() {
	_view->Update();
}

const string& Controller::Min() {
	try {
		if (_model->empty()) { throw exception("list is empty"); }
		MinVisitor* _min = new MinVisitor();
		for (StringListIterator it = _model->begin(); !it.isDone(); it.next())
			it.currentItem().Accept(*_min);
		return _model->getAt(_min->getMin())._val;
	}
	catch (exception& e) {
		throw exception(e.what());
	}	
}

const string& Controller::Max() {
	try {
		if (_model->empty()) { throw exception("queue is empty"); }
		MaxVisitor* _max = new MaxVisitor();
		for (StringListIterator it = _model->begin(); !it.isDone(); it.next())
			it.currentItem().Accept(*_max);
		return _model->getAt(_max->getMax())._val;
	}
	catch (exception& e) {
		throw exception(e.what());
	}
}

void Controller::Clear() {
	SetWindowText(*hInput, "");
	SetWindowText(*hState, "");
	_model->Clear();
}