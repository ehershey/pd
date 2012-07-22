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
    set_short("Zolenia Armour Shop.");
    set_long("%^BOLD%^%^BLACK%^The armour shop of Zolenia is fairly plain.  There are not only sets of armour hung up on the wall, but also filling up shelves and a large wooden counter.  There is a sign posted on the front of the counter.  The floor is constructed of polished black onyx.");
    set_items(([
        "onyx" : "The floor is constructed of polished black onyx.",
        "floor" : "The floor is constructed of polished black onyx.",
        "shelves" : "Wooden shelves hold armour that doesn't fit on the walls and counter.",
        "walls" : "The walls are covered in armour that doesn't fit on the shelves or counter.",
        "counter" : "A counter made of black wood holds armour that doesn't fit on the walls and shelves.",
        "sign" : "There is a sign in front of the counter, advising against attempted thievery.",
      ]));
    set_exits(([
        "out" : ROOMS "56"
      ]));
}

void reset() {
    ::reset();
    if(!present("duaglin")) 
        new(MOB"duaglin")->move(this_object());
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
    this_player()->move_player(ROOMS "armstore", "east");
    return 1;
}
