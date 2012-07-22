#include <gcity.h>
#include <mjungle.h>
#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
set("short", "Silvermane Bar");
    set("long",
"%^YELLOW%^You have entered the Silvermane Bar although you find the %^YELLOW%^name ironic as everything is still made of gold.  Weary %^YELLOW%^travellers often come here to relax and share stories.  A %^YELLOW%^sign lists availible drinks.%^RESET%^");
    set_items(
(["bar" : "The Silvermane Bar serves drinks to refresh the weary traveller.",
       "list" : "It looks like a list of drinks. Read it to see "
         "what's available."]));
    set_exits( 
(["south": GCITY "gcity2.c",
]));
    set_property("no castle", 1);
    set_property("no attack", 1);
}

void reset() {
  ::reset();
if(!present("bartender"))
new(GMOB"bartender")->move(this_object());
//set_read("list", present("bartender")->read_menu());
//set_read("sign", present("bartender")->read_menu());
}
