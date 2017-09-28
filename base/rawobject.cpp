#include "crt.h"
#include "main.h"

using namespace evrika;

bool rawobject::ispredefined() const
{
	return create == 0;
}