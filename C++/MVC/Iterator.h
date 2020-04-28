#ifndef _QUEUEITERATOR_
#define _QUEUEITERATOR_

class StringList;

#include "Libs.h"
#include "StringList.h"

using namespace std;

	/// class QueueIterator ///

class StringListIterator {
protected:
	friend class StringList;

	StringList *_container;
	size_t _current;	

public:	

	StringListIterator(StringList* cont, int cur);

	StringListIterator(const StringListIterator& aIt);

	~StringListIterator() {}

	bool isDone() const;

	StringListIterator& first();

	StringListIterator& operator = (const StringListIterator& aIt);

	StringListIterator& next();

	Element& currentItem() const;

	bool operator == (const StringListIterator& aIt) const;

	bool operator != (const StringListIterator& aIt) const;
};

#endif