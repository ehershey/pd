#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("building",1);
    set_short("A Mental Insitution");
    set_long(
      "%^BOLD%^%^WHITE%^A sound proof, padded room, all white of course. "
           );
    set_items(([
        "walls" : "Padded so no one can hurt themselves",
        "room" : "It is for those who are mentally challenged.",
        "pad" : "They absorb hits so one dosn't hurt themselves.",
    ]));
    set_listen("default", "Complete silence fills the air");
    set_exits( ([
"north" : UMI "hosp6",
    ]) );
}
