#include "main.h"

struct client : reference
{
	const char*	comment;

	const xsfield* getmeta() const
	{
		return client_type;
	}

};
xsfield client_type[] = {
	BSREF(client),
	BSREQ(client, comment, text_type),
	{0}
};