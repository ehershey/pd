#include <std.h>
inherit ROOM;
#include <zolenia.h>
void create() {
    ::create();
     set_no_clean(1);
    set_short("Zolenia Weapon Supply");
    set_long("This is the storage room where weapons are kept.");
    set_exits((["west" : ROOMS+"weapon"]) );
    new(WEP"darkblade")->move(this_object());
}
