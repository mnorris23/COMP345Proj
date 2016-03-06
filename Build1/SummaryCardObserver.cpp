#include "SummaryCardObserver.h"

using namespace std;

SummaryCardObserver::SummaryCardObserver() {

	summary = new Fl_Group(885, 245, 460, 365, "Summary Card");
	
	summary->begin();
	summary->box(FL_ROUNDED_FRAME);
	summary->color(FL_BLACK);
	summary->align(Fl_Align(FL_ALIGN_TOP | FL_ALIGN_INSIDE));
	buff_summary = new Fl_Text_Buffer();
	info_summary = new Fl_Text_Display(900, 262, 430, 184);
	info_summary->buffer(buff_summary);
	info_summary->wrap_mode(3, 0);

	summaryCard = new SummaryCard();
	string sum = summaryCard->allPhases();
	const char * str = sum.data();
	buff_summary->text(str);
	info_summary->color(FL_DARK3);
	

	payment = new PaymentTable(890, 455, 455, 155);

	summary->end(); // Fl_Group* summary
}

SummaryCardObserver::~SummaryCardObserver() {

}

void SummaryCardObserver::hide() {
	summary->hide();
}

void SummaryCardObserver::show() {
	summary->show();
}