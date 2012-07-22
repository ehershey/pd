#include <std.h>
#include <aciri.h>
inherit ROOM;

void create() {
::create();
    set_short("An Archmage's home");
    
    set_listen("default", "%^BOLD%^%^RED%^The crackling of a fire can be heard.%^RESET%^");
    set_long("In this corner of the room lies a table.  It is made of wood "
        "with copper plating on the edges.  The wood of the table appears to "
        "be stained by many alchemistic liquids.  There are no windows in here, "
        "only a dim light from the fire, so it is rather difficult to read the "
        "labels on the many strangely shaped bottles.  Just beside the table sits "
        "a beautiful arm chair.");
    
    
    set_items(([
          "table" : "The wood of the table is stained by alchemistic liquids.",
          "bottles" : "The shops are both silver, glistening in the darkness as if out of a dream.  A weapon's sign decorates the northern shop, while an armour sign compliments the southern shop.",
          
        
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
        "indoors" : 1,
        "town" : 1,
    ]));
    set_exits(([
        "north" : ROOMS "fortofaciri67.c",
        "west" : ROOMS "fortofaciri68.c",
        "northwest" : ROOMS "fortofaciri66.c",
       ]));
       
}
void reset() {
  ::reset();
    if(!present("archmage")) 
      new(MOB "archmage.c")->move(this_object());
}
