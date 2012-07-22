#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 1]) );
    set_property("indoors",1);
    set_short("Uwagi's Homes");
    set_long(
      "This hole is dark and gloomy.  Black candles everywhere, an altar "
      "placed in the exact center of the room.  On top of the altar, "
      "there is a goat skull placed inside a pool of %^RED%^blood%^RESET%^."
      "  The %^RED%^blood%^RESET%^ then drips off the table like a fountain."
    );
    set_items(([
        "room" : "It's very dark and gloomy.",
        "candles" : "It's the kind of candle that when lit, the flame is "
                    "black.",
        "altar" : "It's not very fancy, %^RED%^blood%^RESET%^ covers the whole altar.",
        "skull" : "It's the skull of a goat.",
        "blood" : "It's very strange, it stays only with the altar, yet it "
                  "flows.",
        "fountain" : "The %^RED%^blood%^RESET just drips off the altar, but not onto "
                     "the floor.",
        "floor" : "It is made of dirt",
    ]));
    set_exits( ([
"out" : BA "hhole16",
    ]) );
}
void init()
{
 ::init();
 add_action("drink", "drink");
}
int drink(string str)
{
 if (str!="blood") return notify_fail("You drink the %^RED%^blood%^RESET%^ of the dead!\n");
 if (this_player()->query_class()!="kataan")
   {
    write("You drink the %^RED%^blood%^RESET%^ of the dead!");
    return 1;
    }
 write("You hunger more for %^RED%^blood%^RESET%^ and dive in!");
 this_player()->move_player(GAR "kahall", "by diving into the %^RED%^blood%^RESET%^");
return 1;
}
