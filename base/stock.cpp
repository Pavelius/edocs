#include "main.h"

struct stock : reference
{
	const char*	comment;

	const xsfield* getmeta() const
	{
		return stock_type;
	}

};
xsfield stock_type[] = {
	BSREF(stock),
	BSREQ(stock, comment, text_type),
	{0}
};