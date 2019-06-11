#ifndef _STRINGLIST_
#define _STRINGLIST_

#include "Libs.h"
#include "Visitor.h"
#include "Iterator.h"
#include "View.h"
#include "Controller.h"

using namespace std;

class StringList {
protected:
	// data
	Element* _data;
	size_t _capacity;
	size_t _size;
	size_t _first;
	const size_t MEMORY_BLOCK = 16;

	// random access for iterator
	Element& getAt(size_t ind);

	// extending data space
	void AllocateMemory(const size_t aSize = 1);

	void Erase();

	void Reset();

	void Copy(const StringList& aQueue);

public:
	friend class StringListIterator;
	friend class Controller;

	StringList();

	~StringList();

	// clear the queue
	void Clear();

	// copy c/tor
	explicit StringList(const StringList& aQueue);

	// move c/tor
	explicit StringList(StringList&& aQueue);

	// copy assignment operator
	StringList& operator = (const StringList& aQueue);

	// move-assign operator
	StringList& operator = (StringList&& aQueue);

	void push_back(const string& item);

	string pop_front();

	string pop_back();

	const size_t size() const;

	bool empty() const;

	string toString();

	// iterator methods

	StringListIterator CreateIterator();

	StringListIterator begin();

	StringListIterator end();
};

#endif