#include "Iterator.h"
#include "StringList.h"

StringListIterator::StringListIterator(StringList* cont, int cur) {
	if (cont == nullptr || cur < 0) { throw exception("Error: creating invalid iterator!\n"); }
	_container = cont;
	_current = cur;
}

StringListIterator::StringListIterator(const StringListIterator& aIt) {
	_container = aIt._container;
	_current = aIt._current;
}

bool StringListIterator::isDone() const {
	if (this->_container == nullptr) { throw exception("Error: container should be specified!\n"); }
	return (_current >= _container->size());
}

StringListIterator& StringListIterator::operator = (const StringListIterator& aIt) {
	if (aIt._container == nullptr) { throw exception("Error: creating invalid iterator!\n"); }
	this->_container = aIt._container;
	this->_current = aIt._current;
	return *this;
}

StringListIterator& StringListIterator::next() {
	if (this->isDone()) { throw exception("Error: iterator out of bounds!\n"); }
	++_current;
	return *this;
}

StringListIterator& StringListIterator::first() {
	_current = 0;
	return *this;
}

Element& StringListIterator::currentItem() const {
	if (this->isDone()) { throw exception("Error: iterator out of bounds!\n"); }
	return this->_container->getAt(this->_current);
}

bool StringListIterator::operator == (const StringListIterator& aIt) const {
	return (this->_container == aIt._container && this->_current == aIt._current);
}

bool StringListIterator::operator != (const StringListIterator& aIt) const {
	return !(*this == aIt);
}