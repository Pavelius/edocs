#include "main.h"

xsfield properties_type[];
struct properties : xsobject
{
	xsobject*		object;
	xsobject*		requisit;
	int				value;
	
	const xsfield* getmeta() const
	{
		return properties_type;
	}

};
xsfield properties_type[] = {
	BSREQ(properties, object, reference_type),
	BSREQ(properties, requisit, reference_type),
	BSREQ(properties, value, number_type),
	{0}
};
static properties properties_data[4096];
BSMETA(properties)