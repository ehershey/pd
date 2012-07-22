#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_short("an old mine shaft");
    set_long("You are inside an old mine shaft.  Security stands here "
      "to watch for criminals trying to steal precious "
      "diamonds and minerals.  After you pass security "
      "you are permitted to follow the tunnel north.");
    set_items(([
	"tunnel" : "The tunnel continues on north.",
      ]));
    set_properties(([
	"light" : 2,
	"night light" : 2,
      ]));
    set_exits(([
	"north" : "/wizards/marduk/mine_shaft/ms_room3.c",
"out" : "/d/nopk/standard/spass6",
      ]));
}

void reset() {
    ::reset();
    if(!present("goblin"))
	new("/wizards/marduk/mine_shaft/security.c")->move(this_object());
}
