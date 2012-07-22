#include <std.h>
inherit ROOM;
#include <zolenia.h>
void create() {
    ::create();
     set_no_clean(1);
	set_properties( ([ "light" : 1, "indoors" : 1]) );
    set_short("Zolenia Armour Supply");
    set_long("This is the storage room where armour is kept.");
    set_exits((["west" : ROOMS+"armour"]) );
    new(ARM"darkarmour")->move(this_object());
}
