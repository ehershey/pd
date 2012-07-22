#include <std.h>
#include <zolenia.h>
inherit ROOM;
void init() {
    ::init();
    add_action("go_east", "east");
}

void create() {
    ::create();
    set_properties(([ "light" : 2, "indoors" : 1, "no bump" : 1, "no attack" : 1, "no magic" : 1 ]));
    set_short("Zolenia Food and Drink Shop.");
    set_long("%^BOLD%^%^BLACK%^The supply shop of Zolenia is the smallest of all of the shops.  There is a simple wooden counter, behind which there seems to be food.  The supply may be a little low at times.  The floor is constructed of polished black onyx.");
    set_items(([
        "onyx" : "The floor is constructed of polished black onyx.",
        "floor" : "The floor is constructed of polished black onyx.",
        "counter" : "There is a simple wooden counter, behind which there seems to be food.",
      ]));
    set_exits(([
        "out" : ROOMS "56"
      ]));
}

void reset() {
    ::reset();
    if(!present("vaslin")) 
        new(MOB"vaslin")->move(this_object());
}

int go_east() {
    if(!wizardp(this_player())) {
        message("my_action", "Trying to steal from the drows is NOT advisable.",
          this_player());
        message("other_action", (string)this_player()->query_cap_name()+
          " begins to leave east then thinks better of it.",
          this_object(), ({ this_player() }));
        return 1;
    }
    this_player()->move_player(ROOMS "foodstore", "east");
    return 1;
}
