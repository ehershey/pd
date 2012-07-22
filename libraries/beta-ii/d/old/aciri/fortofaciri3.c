//Made using Room generator by Nightshade

#include <std.h>
#include <aciri.h>
inherit ROOM;

void create() {
    ::create();
    set_short("%^RED%^%^BOLD%^The Impregnable Fortress of Aciri%^RESET%^");
    set_properties( (["light" : 2, "night light" : 1]) );
    set_property("town", 1);
    set_listen("default", "A deep humming can be heard from far away.");
    set_smell("default", "The faint smell of insence is present.");
    set_long("Small guard towers are situated at the four corners of the fortress.  The stone tiled streets all seem rather clean, like someone has recently cleaned.  There are a few buildings within the fortress walls, most of which do not appear to have entrances of any kind.  The whole fortress looks rather spartan.  Far beyond it's walls, mountains can be seen, surrounding a shining blue and red pillar.  The pillar appears to be a leafless tree, shifting supernaturally.  Part of a valley can be seen behind the northern wall.  A massive set of stairs ascends into the mountains.");
    set_exits( (["west" : ROOMS+"fortofaciri4.c"
             ,"north" : ROOMS+"fortofaciri25.c"
             ,"east" : ROOMS+"fortofaciri37.c"
             ,"south" : ROOMS+"fortofaciri2.c"
              ]) );
    set_items( ([ "towers" : "The towers probably house guards who look out for intruders."
                 ,"walls" : "The tower walls are pretty high.  They are heavily fortified at the top also with an array of spikes."
                 ,"buildings" : "Many of the buildings don't seem to have any entrances."
                 ,"mountains" : "The mountains surround the pillar of blue and red light.  There seems to be a massive set of stairs leading up the first half."
                 ,"pillar" : "%^RED%^Blue %^RED%^and %^RED%^red %^BLUE%^shifting %^RED%^lights %^BLUE%^cover %^RED%^the %^BLUE%^pillar.%^RESET%^"
                 ,"stairs" : "A massive set of stairs appears to have been carved into the mountain."
                 ]) );
}

