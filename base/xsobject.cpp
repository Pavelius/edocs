#include "main.h"

int xsobject::get(const char* id) const
{
	xsref r = {getmeta(), (void*)this};
	return r.get(id);
}

void xsobject::read()
{
}

void xsobject::write() const
{
}