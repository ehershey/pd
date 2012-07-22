// by Halo for Illuminati
#include <std.h>
#include <guild.h>
inherit ROOM;

void create() {
::create();
    set_short("Main Chamber");
    set_long("You stand within the %^BOLD%^%^YELLOW%^H%^WHITE%^all of Trut%^YELLOW%^h%^RESET%^. Those seeking an audience "
"with the 'Solar' will find themselves waiting here to be "
"summoned.  The chamber spreads out from where you stand in a "
"spiral of columns, in the centre on which, a %^BOLD%^%^BLACK%^Throne%^RESET%^ is "
"situated. Light filters down seemingly from everywhere "
"creating a bizzare swirling effect that plays tricks on the eye, although " 
"leaving you slightly disorientated, the result is quite relaxing. To the east " 
"lies the Solar's study while his personal apartments are located to the west.");
    set_items(([
        "throne" : "Built from pure obsidian. In times past the Solar would give "
"decrees and pass judgement from here. However not in many years has there been "
"any need to use it.",
        "columns" : "They are magnificently crafted from an unknown stone. Each "
"column is covered in a different carving depicting one of the great victory's "
"of the light.",
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 3,
    ]));
    set_exits(([
        "north" : ROOMS"illuminati/new/floor6.c",
        "east" : ROOMS"illuminati/new/halo1.c",
        "west" : ROOMS"illuminati/new/halo2.c",
    ]));
}

void init() {
   ::init();
     add_action("west", "west");
}

int west() {
    if (this_player()->query_name() == "halo" || wizardp(this_player())){
       this_player()->move_player(ROOMS"illuminati/new/halo2.c");
       return 1;
       }
    write("You are not permitted into the Solar's Personal Chambers");
    return 1;
}

