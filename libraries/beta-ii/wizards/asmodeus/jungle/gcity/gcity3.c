#include <gcity.h>
#include <mjungle.h>
#include <std.h>

inherit ROOM;

void init() {
    ::init();
    add_action("read", "read");
}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
set("short", "Silvermane Bar");
    set("long",
"%^YELLOW%^You have entered the Silvermane Bar although you find the name ironic as everything is still made of gold.  Weary travellers often come here to relax and share stories.  A sign lists availible drinks.%^RESET%^");
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
    if(!present("list")) 
      new("/std/obj/player_list")->move(this_object()); 
if(!present("bartender"))
new(GMOB"bartender")->move(this_object());
}

int read(string str) {
    object ob;
    int i;

    ob = present("bartender");
    if(!ob) {
        write("You cannot read the menu, as it is splattered with blood.");
     return 1;
    }
message("info", "The following classic drinks are served at the Silvermane Bar!",
this_player());
    message("info",
"-----------------------------------------------------------", this_player());
    message("info", "A firebreather\t\t\t"+
(int)ob->get_price("firebreather")+" gold", this_player());
    message("info", "A special of the
house\t\t"+(int)ob->get_price("special")+" gold", this_player());
    message("info", "A pale ale\t\t\t"+(int)ob->get_price("ale")+" gold",
this_player());
    message("info",
"-----------------------------------------------------------", this_player());
    message("info", "<buy drink_name> gets you a drink.", this_player());
    return 1;
}
