#include "PaymentTable.h"


PaymentTable::PaymentTable(int X, int Y, int W, int H, const char *L) : Fl_Table(X, Y, W, H, L) {

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
	
	

