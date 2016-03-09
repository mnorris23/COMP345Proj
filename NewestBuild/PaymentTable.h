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

	int data[7][6];  

	void DrawHeader(const char *s, int X, int Y, int W, int H);
	void DrawData(const char *s, int X, int Y, int W, int H);
	void draw_cell(TableContext context, int ROW = 0, int COL = 0, int X = 0, int Y = 0, int W = 0, int H = 0);
};