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
    set_short("Zolenia supply Shop.");
    set_long("%^BOLD%^%^BLACK%^The supply shop of Zolenia is more detailed than the other shops.  There are displays with random items of all sorts, and random items cover the walls.  There is a sign posted on the front of the counter.  The floor is constructed of polished black onyx.");
    set_items(([
        "onyx" : "The floor is constructed of polished black onyx.",
        "floor" : "The floor is constructed of polished black onyx.",
        "walls" : "The walls are covered random items.",
        "displays" : "Displays full of random items are plentiful in this store.",
	"items" : "The items are really quite random, they're not too describable.",
        "sign" : "There is a sign in front of the counter, advising against attempted thievery.",
      ]));
    set_exits(([
        "out" : ROOMS "56"
      ]));
}

void reset() {
    ::reset();
    if(!present("riklin")) 
        new(MOB"riklin")->move(this_object());
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
    this_player()->move_player(ROOMS "supstore", "east");
    return 1;
}
