#include "crt.h"
#include "main.h"

using namespace evrika;

int rawobject::get(const char* id) const
{
	xsref r = {getmeta(), (void*)this};
	return r.get(id);
}

void rawobject::creating()
{
	creator = current::user;
	create = getdate();
}

void rawobject::changing()
{
	changer = current::user;
	change = getdate();
}