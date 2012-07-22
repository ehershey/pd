#include <std.h>
#include <marsh.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("cave",1);
    set_short("Bedroom");
    set_long(
      "This is a bedroom.  There is a four-post bed in a corner with a "
      "bedspread that has a five star pattern look.  The whole room is lit "
      "up with a cowboy boot lamp which stands in a corner opposite of the bed.
 "

      "There is a roll-top desk right next to the lamp.",
          );


    set_items(([
        "bedroom" : "It is deep within the banks, and very tidy.",
        "bed" : "It's been made already, it's a four-post all oak frame",
        "bedspread" : "A lot of work went into it, it is handmade.",
        "pattern" : "A very common pattern, a five star pattern.",
        "room" : "It is very tidy and cleaned up.",
        "lamp" : "Very ugly, it has a cowboy boot on the bottom.",
        "desk" : "An all oak desk that has a roll-top.",

    ]));

    set_exits( ([
"up" : BA "hhole",
    ]) );

}
