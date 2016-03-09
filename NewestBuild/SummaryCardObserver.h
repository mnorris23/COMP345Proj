#pragma once

#include "SummaryCard.h"
#include "PaymentTable.h"

#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <FL/FL_Text_Display.H>
#include <string>

class SummaryCardObserver {
public:
	SummaryCardObserver();
	~SummaryCardObserver();
	void hide();
	void show();
private:
	Fl_Group* summary;
	SummaryCard* summaryCard;
	PaymentTable* payment;

	Fl_Text_Buffer *buff_summary;
	Fl_Text_Display* info_summary;
};