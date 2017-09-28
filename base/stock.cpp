#include "main.h"

using namespace evrika;

xsfield stock_type[] = {
	BSREF(stock),
	{0}
};

COMMAND(app_initialize)
{
	auto root = create_folder(0, "Склады", stock_type);
	create_predefined(root, "Основной склад");
}