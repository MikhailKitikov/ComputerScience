#ifndef _VISITOR_
#define _VISITOR_
#include "Libs.h"

using namespace std;

class Visitor;

	/// class Element ///

class Element {
public:
	string _val;

	Element();
	Element(const string& arg);

	Element& operator = (const Element& arg);

	void Accept(Visitor& aVisitor);
};

	/// abstract class Visitor ///

class Visitor {
protected:
	bool started;
	int ind;
public:
	Visitor();
	virtual void visit(Element& element) = 0;
	virtual ~Visitor() = default;
};

	/// class MinVisitor ///

class MinVisitor : public Visitor {
private:
	size_t minVal;
	int minPos;
public:
	MinVisitor();
	void visit(Element& element) override;
	const size_t& getMin();
};

	/// class MaxVisitor ///

class MaxVisitor : public Visitor {
private:
	size_t maxVal;
	int maxPos;
public:
	MaxVisitor();
	void visit(Element& element) override;
	const size_t& getMax();
};

#endif