#include <std.h>
#include <soran.h>
inherit ROOM;

void create() {
    ::create(); 

    set_short("a stone bridge");
    set_long("Water flows under the bridge with an ominous hiss.  "
      "The bridge itself is made from a blue marble, its stones "
      "slick from the misty steam below.A temple that lays ahead "
      "appears to be ten stories high and resembles a pyramid. "
      "Though there are windows , no light shines from within. "
      "The town to the south is unsettlingly quiet.");
    set_listen( "default","The trickling of water is heard from under the bridge.");
    set_property("indoors",0);
    set_property("light",2);
    set_property("night light",3);
    set_exits(([
	"north": ROOMS "front1.c",
      ]));
}

