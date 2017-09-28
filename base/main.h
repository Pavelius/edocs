#include "aref.h"
#include "command.h"
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

extern xsfield						client_type[];
extern xsfield						char_type[];
extern xsfield						document_type[];
extern xsfield						offer_type[];
extern xsfield						profile_type[];
extern xsfield						properties_type[];
extern xsfield						reference_type[];
extern xsfield						requisit_type[];
extern xsfield						stock_type[];
extern xsfield						user_type[];

enum evrika_flag_s {EvrikaPredifined, EvrikaActualized, EvrikaDeleted,
};

namespace evrika
{
	struct folder;
	struct reference;
	struct user;
	namespace current
	{
		extern struct user*			user;
		extern struct user*			superuser;
		extern struct stock*		stock;
		namespace folders
		{
			extern folder*			administrators;
			extern folder*			users;
		}
	}
	struct rawobject
	{
		reference*					parent;
		unsigned					uid;
		unsigned					create, change;
		user*						creator;
		user*						changer;
		unsigned					flags;
		//
		bool						isactualized() const;
		bool						isdeleted() const;
		bool						ispredefined() const;
	};
	struct reference : rawobject
	{
		const char*					id;
		const char*					name;
		const char*					comment;
	};
	struct folder : reference
	{
		xsfield*					metadata;
	};
	struct profile_rights
	{
		unsigned					show;
		unsigned					change;
	};
	struct profile : reference
	{
		aref<profile_rights>		rights;
	};
	struct user : reference
	{
		struct profile*				profile;
	};
	struct requisit : rawobject
	{
	};
	struct properties
	{
		rawobject*					object; // Can be any raw object (document, reference e.t.c.)
		requisit*					requisit; // Specific requisit
		int							value;
	};
	struct stock : reference
	{
	};
	struct offer : reference
	{
	};
	struct client : reference
	{
		const char*					full_name;
		char						idcode[13];
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
	};
	folder*							create_folder(folder* parent, const char* name, xsfield* metadata = 0);
	reference*						create_predefined(folder* parent, const char* name);
}