#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("indoors",1);
    set_short("A tunnel");
    set_long(
      "A long narrow tunnel with whips along side the wall."
      
          );
    set_items(([
        "tunnel" : "Long dark and narrow",
        "whips" : "Some have nails on the end of them",
        "nails" : "Yuck, rotting flesh stuck between the nails",
        "flesh" : "It's greyish in color",
            ]));
    set_exits( ([
"southwest" : GAR "gar43",
"up" : UMI "umi21",
    ]) );
}
