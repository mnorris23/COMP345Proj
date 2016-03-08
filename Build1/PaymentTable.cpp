#include "PaymentTable.h"


PaymentTable::PaymentTable(int X, int Y, int W, int H, const char *L) : Fl_Table(X, Y, W, H, L) {

	data[0][0] = 0;
	data[0][1] = 10;
	data[0][2] = 7;
	data[0][3] = 82;
	data[0][4] = 14;
	data[0][5] = 129; 
	data[1][0] = 1;
	data[1][1] = 22;
	data[1][2] = 8;
	data[1][3] = 90;
	data[1][4] = 15;
	data[1][5] = 134;
	data[2][0] = 2;
	data[2][0] = 33;
	data[2][0] = 9;
	data[2][0] = 98;
	data[2][0] = 16;
	data[2][0] = 138;
	data[3][0] = 3;
	data[3][1] = 44;
	data[3][2] = 10;
	data[3][3] = 105;
	data[3][4] = 17;
	data[3][5] = 142;
	data[4][0] = 4;
	data[4][1] = 54;
	data[4][2] = 11;
	data[4][3] = 112;
	data[4][4] = 18;
	data[4][5] = 145;
	data[5][0] = 5;
	data[5][1] = 64;
	data[5][2] = 12;
	data[5][3] = 118;
	data[5][4] = 19;
	data[5][5] = 148;
	data[5][0] = 5;
	data[6][0] = 6;
	data[6][1] = 73;
	data[6][2] = 13;
	data[6][3] = 124;
	data[6][4] = 20;
	data[6][5] = 150;

	/*
	{
		{ 0, 10, 7, 82, 14, 129 },
		{ 1,22,8,90,15,134 },
		{ 2,33,9,98,16,138 },
		{ 3,44,10,105,17,142 },
		{ 4,54,11,112,18,145 },
		{ 5,64,12,118,19,148 },
		{ 6,73,13,124,20,150 }
	};*/

	rows(MAX_ROWS);
	row_height_all(18);
	row_resize(0);

	cols(MAX_COLS);
	col_header(1);
	col_width_all(70);
	col_resize(1);
	end();
}
PaymentTable::~PaymentTable() {

}

						
void PaymentTable::DrawHeader(const char *s, int X, int Y, int W, int H) {
	fl_push_clip(X, Y, W, H);
	fl_draw_box(FL_THIN_UP_BOX, X, Y, W, H, row_header_color());
	fl_color(FL_BLACK);
	fl_draw(s, X, Y, W, H, FL_ALIGN_CENTER);
	fl_pop_clip();
}

void PaymentTable::DrawData(const char *s, int X, int Y, int W, int H) {
	fl_push_clip(X, Y, W, H);
	// Draw cell bg
	fl_color(FL_WHITE); fl_rectf(X, Y, W, H);
	// Draw cell data
	fl_color(FL_GRAY0); fl_draw(s, X, Y, W, H, FL_ALIGN_CENTER);
	// Draw box border
	fl_color(color()); fl_rect(X, Y, W, H);
	fl_pop_clip();
}
	
void PaymentTable::draw_cell(TableContext context, int ROW, int COL, int X, int Y, int W, int H) {
	static char s[40];
	switch (context) {
	case CONTEXT_STARTPAGE:
		fl_font(FL_HELVETICA, 15);
		return;
	case CONTEXT_COL_HEADER:
		if ((COL % 2) == 0)
			snprintf(s, 40, "%s", "# Cities");
		else
			snprintf(s, 40, "%s", "Electro");
		DrawHeader(s, X, Y, W, H);
		return;
	case CONTEXT_CELL:
		snprintf(s, 40, "%d", data[ROW][COL]);
		DrawData(s, X, Y, W, H);
		return;
	default:
		return;
	}
}
	
	

