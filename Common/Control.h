#pragma once
#include "Graphics.h"
#include <vector>

using namespace std;

class Control
{
	static Control* focused;

protected:
	vector<Control*> controls;
	short left;
	short top;
	bool isFocus;
	bool isclick;

public:
	Control() : left(0), top(0), isFocus(true) {};
	static Control* getFocus() { return focused; };
	static void setFocus(Control& control) { focused = &control; };


	virtual void add(Control* newControl);
	virtual void draw(Graphics& g);
	virtual void draWrapper(Graphics& g) {};
	virtual void drawControls(Graphics& g);
	virtual void mousePressed(int x, int y, bool isLeft) {};
	virtual void keyDown(int keyCode, char charecter) {};
	virtual short getLeft() { return left; };
	virtual short getTop() { return top; };
	virtual void setTop(short top) { this->top = top; };
	virtual void setLeft(short left) { this->left = left; };
	virtual void getAllControls(vector<Control*>* controls) { controls = &(this->controls); };
	virtual bool canGetFocus() { return isFocus; };
	virtual bool myPureFunction() = 0;
	~Control();
};

