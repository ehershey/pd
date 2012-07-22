#include <std.h>
#include <underpurgatory.h>

inherit ROOM;

void init() {
    ::init();
    add_action("move_tapestry", "grab");
    add_action("swing_table", "swing");
    add_action("climb_rack", "climb");
    add_action("shimmy_pole", "shimmy");
}
void create() {
    ::create();
     set_name("The Cooks Lair.");
     set_short("The Cooks Lair.");
     set_long("A rather huge kicthen, where even a giant would feel confortable "
"standing up, lies buried under the castle. Huge flames "
"bathe the kitchen in a flickering light from the fireplace, "
"licking higher up the chimney as a large bellows keep the "
"fire stoked. Tables as tall as a human stand before the "
"fireplace, topped with dressings and the like for the days "
"meals. The muffled screams of lunch emerge from different "
"pots as the cooks take a late nap. Racks full of plates, "
"pots, and pans line the south portion of this kitchen. To "
"the north are the shelves of different ingredients, "
"including live humans, elves and who knows what else...");
     set_night_long("Darkness swallows up all but the largest details of the cooks "
"lair. The sounds of the day have left behind a chilling "
"silence as the cooks have deserted their posts for the night. "
"The odd flapping of wings, and whimpering of the next days "
"dinner can be heard in the darkness. The great fireplace lies "
"dormant during the night as well as the bellows have been deflated. Without the "
"fire, it is very hard to see in here and the odd pot lying on the ground might "
"give an unwary traveler dents in his shins.");
     set_properties(([
        "light"       : 2,
        "night light" : 0,
        "no bump"     : 1,
        "indoors"     : 1,
        "castle"      : 1,
        "no steal"    : 1,
]));
 set_exits( (["east" : ROOMS"filename", 
              "west" : ROOMS"filename"]) );


    set_items( ([
        "fireplace"  : "A rather large fireplace, the %^BOLD%^%^RED%^f%^YELLOW%^l%^RESET%^%^RED%^a%^BOLD%^%^YELLOW%^m%^RED%^e%^YELLOW%^s%^RESET%^ flicker higher then a centaurs' head as they reach for the skies.",
        "table" : "This table looks HUGE! It towers above most normal peoples heads and it looks like thers some sort of substance stuck to the bottom...",
        "substance" : "It looks to be like chewed tree sap thats hanging down from the bottom of the table, it might be possible to grab ahold of it...",
        ({"shelf", "shelves"}) : "Theses shelves have all kinds of footprints all over them as their captives squiggle and squirm about them. They look to shimmy around their floors trying to get to the pole on the side of the shelves.",
        "pots" : "Quite large pots, these seem to be, almost large enough for you to climb into them.",
        "fire" : "The fire flickers in its place as its light flickers across the room.",
        "racks" : "These racks look pretty high up and filled with the od assortment of pots and pans. Maybe you found find out what else is up there...",
      ]) );
set_listen("default","The sound of bubbling water and the screams of lunch waft around the room.");
set_smell("default","Odd smells linger about the air from the different batches of food.");

}
int move_tapestry(string str) {
    if(!str) {
        notify_fail("grab what?\n");
        return 0;

    }
    if(str != "sap") {
        notify_fail("You can't grab that!\n");
        return 0;
    }
    
    message("info", (string)this_player()->query_cap_name()+" grabs ahold of some chewed tree sap. ", this_object(), ({ this_player() }));
    message("info", "You grab ahold of the tree sap and feel the urge to swing.....", this_player());
    return 1;
}

int swing_table(string str) {
    if(!str) {
        notify_fail("swing to where??\n");
        return 0;

    }
    if(str != "to table") {
        notify_fail("What are you, daft? You cant swing to there!\n");
        return 0;
    }
    

    message("info", "You swing yourself up onto the table", this_player());
    this_player()->move_player(ROOMS "table1.c", " swings up onto the table.");

    return 1;
}

int climb_rack(string str) {
    if(!str) {
        notify_fail("climb up where??\n");
        return 0;

    }
    if(str != "up the rack") {
        notify_fail("You must be stupid, you cant climb that.\n");
        return 0;
    }
    

    message("info", "You climb up the pots and pans rack.", this_player());
    this_player()->move_player(ROOMS "rack1.c", " climbs up the rack!");

    return 1;
}

int shimmy_pole(string str) {
    if(!str) {
        notify_fail("shimmy up what???\n");
        return 0;

    }
    if(str != "up pole") {
        notify_fail("Thats odd, you dont look like an entertainer.....\n");
        return 0;
    }
    

    message("info", "You shimmy your way up the pole.", this_player());
    this_player()->move_player(ROOMS "shelf1.c", " shimmies up a pole?!");

    return 1;
}
