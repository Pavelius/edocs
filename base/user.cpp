#include "main.h"

using namespace evrika;

user*			current::user;
user*			current::superuser;

xsfield user_type[] = {
	BSREF(stock),
	BSREQ(user, profile, profile_type),
	{0}
};