#include <std.h>
inherit ROOM;

void create() {
::create();
   set_short("lobby of a huge building");
   set_long("This is the lobby of a huge building. You look up and cant even "
	"see the top of the tower. The man that owns it must be very righ and "
	"powerful.  there are two security guards here to keep out all of the "
	"scum and beggars trying to sneak in.  Maybe you can slip "
	"through them unnoticed");
   set_items(([
	"tower" : "its big, supernaturally big.",
]));
   set_properties(([
	"light" : 3,
	"night light" : 2,
]));
   set_exits(([
	"tower" : "/wizards/manex/tower1.c",
	"south" : "/d/standard/square.c",
]));
}

void reset() {
if(!present("security guard"))
	new("/wizards/manex/security_guard.c")->move(this_object());
}
