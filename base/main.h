#include "aref.h"
#include "xsbase.h"

#pragma once

#define BSRAW(c)\
BSREQ(c, parent, reference_type),\
BSREQ(c, flags, number_type),\
BSREQ(c, uid, number_type), \
BSREQ(c, create, number_type), \
BSREQ(c, change, number_type), \
BSREQ(c, creator, reference_type), \
BSREQ(c, changer, reference_type)

#define BSREF(c)\
BSRAW(c),\
BSREQ(c, name, text_type),\
BSREQ(c, comment, text_type)

extern xsfield						document_type[];
extern xsfield						properties_type[];
extern xsfield						reference_type[];
extern xsfield						stock_type[];
extern xsfield						client_type[];
extern xsfield						char_type[];

namespace evrika
{
	struct reference;
	namespace current
	{
		extern reference*			user;
	}
	struct rawobject
	{
		reference*					parent;
		unsigned					uid;
		unsigned					create, change;
		reference					*creator, *changer;
		unsigned					flags;
		//
		virtual bool				actualing() { return true; }
		virtual void				changing();
		virtual void				creating();
		bool						isactualized() const;
		bool						isdeleted() const;
		virtual int					get(const char* id) const;
		virtual const xsfield*		getmeta() const = 0;
	};
	struct reference : rawobject
	{
		const char*					name;
		const char*					comment;
	};
	struct requisit : rawobject
	{
		const char*					id;
	};
	struct properties
	{
		rawobject*					object; // Can be any raw object (document, reference e.t.c.)
		requisit*					requisit; // Specific requisit
		int							value;
	};
	struct stock : reference
	{
		const xsfield*				getmeta() const { return stock_type; }
	};
	struct offer : reference
	{
		const xsfield*				getmeta() const { return stock_type; }
	};
	struct client : reference
	{
		const char*					full_name;
		char						idcode[13];
		const xsfield*				getmeta() const { return client_type; }
	};
	struct document_offers
	{
		reference*					offer;
		int							value;
		int							price;
		long long					total;
	};
	struct document_price
	{
		reference*					offer;
		int							price;
	};
	struct document : rawobject
	{
		unsigned					data;
		stock*						stock_from;
		stock*						stock_to;
		client*						client_from;
		client*						client_to;
		const char*					comment;
		aref<document_offers>		offers;
		const xsfield*				getmeta() const { return document_type; }
	};
}