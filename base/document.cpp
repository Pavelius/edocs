#include "main.h"

struct document_offers
{
	xsobject*				offer;
	int						value;
	int						price;
	int						total;
};
xsfield document_offers_type[] = {
	BSREQ(document_offers, offer, stock_type),
	BSREQ(document_offers, value, number_type),
	BSREQ(document_offers, price, number_type),
	BSREQ(document_offers, total, number_type),
	{0}
};
struct document : reference
{
	unsigned				actualize;
	unsigned				flags;
	xsobject*				stock_from;
	xsobject*				stock_to;
	xsobject*				client_from;
	xsobject*				client_to;
	const char*				comment;
	aref<document_offers>	offers;

	const xsfield* getmeta() const
	{
		return document_type;
	}

};
xsfield document_type[] = {
	BSREF(document),
	BSREQ(document, actualize, number_type),
	BSREQ(document, flags, number_type),
	BSREQ(document, stock_from, stock_type),
	BSREQ(document, stock_to, stock_type),
	BSREQ(document, client_from, client_type),
	BSREQ(document, client_to, client_type),
	BSREQ(document, comment, text_type),
	BSREQ(document, offers, document_offers_type),
	{0}
};
static document document_data[4096];
BSMETA(document)