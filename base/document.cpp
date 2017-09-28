#include "crt.h"
#include "main.h"

using namespace evrika;

xsfield document_offers_type[] = {
	BSREQ(document_offers, offer, stock_type),
	BSREQ(document_offers, value, number_type),
	BSREQ(document_offers, price, number_type),
	BSREQ(document_offers, total, number_type),
	{0}
};
xsfield document_type[] = {
	BSRAW(document),
	BSREQ(document, data, number_type),
	BSREQ(document, flags, number_type),
	BSREQ(document, stock_from, stock_type),
	BSREQ(document, stock_to, stock_type),
	BSREQ(document, client_from, client_type),
	BSREQ(document, client_to, client_type),
	BSREQ(document, comment, text_type),
	BSREQ(document, offers, document_offers_type),
	{0}
};
static document document_data[128*128];
BSMETA(document)

COMMAND(app_initialize)
{
	auto root = create_folder(0, "���������", document_type);
	create_folder(root, "��������� ���������");
	create_folder(root, "��������� ���������");
	create_folder(root, "�������� �������");
	create_folder(root, "������������� �������");
	create_folder(root, "�������������� �������");
	create_folder(root, "��������� ���");
}