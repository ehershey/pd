#include <std.h>
inherit ROOM;
#include <zolenia.h>
void create() {
    ::create();
     set_no_clean(1);
    set_short("Zolenia Supply Supply");
    set_long("This is the storage room where supplies are kept.");
    set_exits((["west" : ROOMS+"supply"]) );
    new(OBJ"fangs")->move(this_object());
}
