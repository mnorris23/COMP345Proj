#pragma once

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Table.H>
#include <FL/fl_draw.H>

class PaymentTable : Fl_Table {
public:
	PaymentTable(int X, int Y, int W, int H, const char *L = 0);
	~PaymentTable();
private:
	static const int MAX_ROWS = 7;
	static const int MAX_COLS = 6;

	int data[7][6]{
		{ 0,10,7,82,14,129 },
		{ 1,22,8,90,15,134 },
		{ 2,33,9,98,16,138 },
		{ 3,44,10,105,17,142 },
		{ 4,54,11,112,18,145 },
		{ 5,64,12,118,19,148 },
		{ 6,73,13,124,20,150 }
	};

	void DrawHeader(const char *s, int X, int Y, int W, int H);
	void DrawData(const char *s, int X, int Y, int W, int H);
	void draw_cell(TableContext context, int ROW = 0, int COL = 0, int X = 0, int Y = 0, int W = 0, int H = 0);
};