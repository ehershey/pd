#include <std.h>
#include <marsh.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("inside",1);
    set_short("A wine cellar");
    set_long(
      "Wine aging from the wine racks.  Some of it aged for hundreds "
      "of years.  This wine cellar does not seem to be used often."

          );

    
    set_items(([
        "cellar" : "Very dusty.",
        "wine" : "All aging to perfection.",
        "racks" : "Designed to hold wine bottles upside-down.",
     
    ]));

    set_exits( ([
"up" : BA "hhole3",
    ]) );

}
