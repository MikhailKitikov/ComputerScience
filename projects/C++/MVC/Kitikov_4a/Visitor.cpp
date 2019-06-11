#include "Visitor.h"
#include "StringList.h"

	/// Element methods

void Element::Accept(Visitor& aVisitor) {
	aVisitor.visit(*this);
}

Element& Element::operator = (const Element& arg) {
	this->_val = arg._val;
	return *this;
}

Element::Element() : _val("") {}

Element::Element(const string& arg) : _val(arg) {}

	/// Visitor methods

Visitor::Visitor() : started(false), ind(-1) {}

MinVisitor::MinVisitor() : Visitor(), minVal(NULL), minPos(NULL) {}

MaxVisitor::MaxVisitor() : Visitor(), maxVal(NULL), maxPos(NULL) {}

void MinVisitor::visit(Element& element) {
	++ind;
	if (!this->started) {
		minVal = element._val.size();
		minPos = ind;
		minPos = ind;
		this->started = true;
		return;
	}
	if (element._val.size() < minVal) {
		minPos = ind;
		minVal = element._val.size();
	}
}

const size_t& MinVisitor::getMin() {
	this->started = false;
	return minPos;
}

void MaxVisitor::visit(Element& element) {
	++ind;
	if (!this->started) {
		maxVal = element._val.size();
		this->started = true;
		return;
	}
	if (element._val.size() >= maxVal) {
		maxPos = ind;
		maxVal = element._val.size();
	}
}

const size_t& MaxVisitor::getMax() {
	this->started = false;
	return maxPos;
}

