#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("The chamber of Cain");
    set_day_long("This is an octagonal, wooden chamber.  Fine, red woods
decorate the whole room and give it an extremely beautiful twist.  A gigantic
fireplace rests within the wall, it's fire blazing.  A desk is build into the
northwest corner and proudly displays a brown, wooden covered book embossed
with runes.  A plush leather chair sits infront of the desk and is studded with
silver and gold.  An old clock is planted to the east with a tinted-red mirror
build into it.  ");
    
    set_night_long("This is an octagonal, wooden chamber.  Fine, red woods
decorate the whole room and give it an extremely beautiful twist.  A gigantic
fireplace rests within the wall, it's fire blazing.  A desk is build into the
northwest corner and proudly displays a brown, wooden covered book embossed
with runes.  A plush leather chair sits infront of the desk and is studded with
silver and gold.  An old clock is planted to the east with a tinted-red mirror
build into it.  ");


    set_items(([
          
         "wood" : "These woods are extremely rare and probably worth a
fortune.",
         "desk" : "The desk is built into one wall and holds some important look
ing
documents, expensive pens and a glass chalice of red wine",
         "fireplace" : "The fire flickers and warms up this room.  As their are
no windows, it is the only source of light.",
         "book" : "The wooden, rune embossed book is quite ugly.  It is
currently sealed.",             
                
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "out" : ROOMS "vtower4.c",
      ]));
    
}

void init() {
 ::init();
   add_action("fireplace", "enter");
}

int fireplace(string str) {
   if (!str || str != "fireplace") return notify_fail("Enter what?\n");
   write("You crawl into the fireplace and climb up the chimney.");
   this_player()->move_player( ROOMS "cainsecretpath1.c");
   return 1;
}

