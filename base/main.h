#include "xsbase.h"

#pragma once

struct xsobject
{
	int							get(const char* id) const;
	virtual const xsfield*		getmeta() const = 0;
};