#include "main.h"

using namespace evrika;

xsfield folder_type[] = {
	BSREF(offer),
	{0}
};

COMMAND(app_initialize)
{
	auto root = create_folder(0, "������������", offer_type);
	create_folder(root, "������");
	create_folder(root, "������");
}