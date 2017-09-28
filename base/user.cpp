#include "main.h"

using namespace evrika;

user*			current::user;
folder*			current::folders::administrators;
folder*			current::folders::users;

xsfield user_type[] = {
	BSREF(stock),
	BSREQ(user, profile, profile_type),
	{0}
};
static user user_data[32];
BSMETA(user);

COMMAND(app_initialize)
{
	auto root = create_folder(0, "Персоны", user_type);
	current::folders::administrators = create_folder(root, "Администраторы");
	current::folders::users = create_folder(root, "Пользователи");
}