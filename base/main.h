#include "aref.h"
#include "xsbase.h"

#pragma once

#define BSREF(c)\
BSREQ(c, uid, number_type),\
BSREQ(c, create, number_type),\
BSREQ(c, change, number_type),\
BSREQ(c, creator, reference_type),\
BSREQ(c, changer, reference_type)\

struct xsobject
{
	virtual int					get(const char* id) const;
	virtual const xsfield*		getmeta() const = 0;
	virtual void				read();
	virtual void				write() const;
};
struct reference : xsobject
{
	unsigned					uid;
	unsigned					create, change;
	xsobject					*creator, *changer;
};
extern xsfield					document_type[];
extern xsfield					stock_type[];
extern xsfield					client_type[];