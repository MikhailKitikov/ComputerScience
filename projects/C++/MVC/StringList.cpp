#include "StringList.h"
#include "Visitor.h"
#include "Iterator.h"
#include "View.h"

Element& StringList::getAt(size_t ind) {
	if (ind < 0 || ind >= this->size()) { throw exception("Error: invalid index!\n"); }
	return _data[_first + ind];
}

void StringList::AllocateMemory(const size_t aSize) {
	size_t newSize = _size;
	size_t newCapacity = _size + max(MEMORY_BLOCK, aSize);
	Element* newArray = new Element[newCapacity];
	if (newArray == nullptr) { throw exception("Memory allocation error!\n"); }
	for (int i = 0; i < _size; ++i) {
		newArray[i] = this->getAt(i);
	}
	Erase();
	_data = newArray;
	_capacity = newCapacity;	
	_size = newSize;
	newArray = nullptr;
}

void StringList::Reset() {
	_size = 0;
	_first = 0;
	_capacity = MEMORY_BLOCK;
	_data = new Element[_capacity];
}

StringList::StringList() {
	Reset();
}

StringList::~StringList() {
	Erase();
}

void StringList::Erase() {
	if (_data != nullptr) {
		delete[] _data;
	}
	_data = nullptr;
	_size = _capacity = _first = 0;
}

void StringList::Clear() {
	Erase();
	Reset();
}

void StringList::Copy(const StringList& aQueue) {
	Erase();
	_capacity = _size = aQueue.size();
	_first = 0;
	_data = new Element[_capacity];
	for (int i = 0; i < aQueue.size(); ++i) {
		_data[i] = aQueue._data[aQueue._first + i];
	}
}

StringList::StringList(const StringList& aQueue) {
	Copy(aQueue);
}

StringList::StringList(StringList&& aQueue) {
	_data = aQueue._data;
	_size = aQueue.size();
	_capacity = aQueue._capacity;
	_first = aQueue._first;
	aQueue._data = nullptr;
	aQueue.Clear();
}

StringList& StringList::operator = (const StringList& aQueue) {
	if (this != &aQueue) {
		Copy(aQueue);
	}
	return *this;
}

StringList& StringList::operator = (StringList&& aQueue) {
	if (this != &aQueue) {
		Erase();
		_data = aQueue._data;
		_size = aQueue.size();
		_capacity = aQueue._capacity;
		_first = aQueue._first;
		aQueue._data = nullptr;
		aQueue.Reset();
	}
	return *this;
}

void StringList::push_back(const string& item) {
	if (_first + _size == _capacity) {
		this->AllocateMemory();
	}
	_data[_first + _size]._val = item;
	++_size;
}

string StringList::pop_front() {
	if (this->empty()) { throw exception("queue is empty"); }
	--_size;
	string temp = _data[_first]._val;
	if (_size == 0) { _first = 0; }
	else { ++_first; }
	return temp;
}

string StringList::pop_back() {
	if (this->empty()) { throw exception("list is empty"); }
	string temp = _data[_size - 1]._val;
	--_size;
	if (_size == 0) { _first = 0; }
	return temp;
}

const size_t StringList::size() const {
	return this->_size;
}

bool StringList::empty() const {
	return (_size == 0);
}

string StringList::toString() {
	ostringstream os;
	if (this->empty()) { os << "[list is empty]"; }
	else {
		StringListIterator it = this->CreateIterator();
		for (it.first(); !it.isDone(); it.next()) {
			os << it.currentItem()._val << "; ";
		}
	}
	return os.str();
}

StringListIterator StringList::CreateIterator() {
	return StringListIterator(static_cast<StringList*>(this), 0);
}

StringListIterator StringList::begin() {
	return StringListIterator(static_cast<StringList*>(this), 0);
}

StringListIterator StringList::end() {
	return StringListIterator(static_cast<StringList*>(this), this->size());
}