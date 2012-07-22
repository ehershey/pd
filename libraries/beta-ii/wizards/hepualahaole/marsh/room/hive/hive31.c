#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Bridge");
    set_long(
      "The bridge crosses a deep ravine.  Looking down, makes one wonder "
      "exactly how deep this ravine is.  The north tunnel wall dissappeared "
      "to show a stunning view of a city floating in the middle of complete "
      "darkness.  There seems to be no bridges connecting this to this city.  "
      "The east opens into a well traveled tunnel."
     
    );
    set_items(([
        "tunnel" : "It seems to be welled used.",
        "bridge" : "It crosses over a deep ravine.",
        "ravine" : "If you listen carefully, you can hear trickling water.",
        "north" : "A large city sets the scene.",
        "wall" : " the only wall present is the one on the south side.",
        "city" : "It seems to taunt you, you can't see a way to get to it.",
  
    ]));
    set_listen("default", "Sounds of trickling water.");
    set_exits( ([
"east" : HIVE "hive32",
"west" : HIVE "hive30",
    ])  );
}
