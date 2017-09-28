#include "main.h"

using namespace evrika;

folder* evrika::create_folder(folder* parent, const char* name, xsfield* metadata)
{
	if(!parent)
		return 0;
	auto md = parent->metadata;
	if(!md)
		md = metadata;
	if(!md)
		return 0;
	auto pb = xsbase::find(parent->metadata);
	if(!pb)
		return 0;
	auto p = (folder*)pb->add();
	p->name = name;
	p->parent = parent;
	p->metadata = md;
	return p;
}

reference* evrika::create_predefined(folder* parent, const char* name)
{
	if(!parent)
		return 0;
	auto pb = xsbase::find(parent->metadata);
	if(!pb)
		return 0;
	auto p = (reference*)pb->add();
	p->name = name;
	p->parent = parent;
	return p;
}

xsfield reference_type[] = {
	BSREF(reference),
	{0}
};