#include "main.h"

using namespace evrika;

xsfield client_type[] = {
	BSREF(client),
	BSREQ(client, idcode, char_type),
	BSREQ(client, full_name, char_type),
	{0}
};