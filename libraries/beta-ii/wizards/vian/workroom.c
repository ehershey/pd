#include <std.h>

inherit ROOM;

object board;

void create() {
    ::create();
    set_properties( ([ "light" : 3, "night light" : 3]) );
    set_smell("default", "Many scents mix from the portals on the walls, from fresh air and dirty stone, to the brisk scent of ocean air.");
    set_listen("default", "The snoring of a baby dragon, escaped from a portal and sitting in the corner of the room, could keep a builder awake and coding all day and night.");
    set_short("The workroom of Vian.");
    set_long("%^BOLD%^This large stone room seems to have no doors, and no escape, save the portals on the walls.  Above a number of the portals, there are wooden signs with the destination carved deep.  In the center of the room, a bed, desk and rug are sprawled haphazardly, as if cleanliness and appearance is not what Vian was going for.  Upon the desk sits notebooks, maps, and random magical tools, only what is needed to create wondrous lands, and nothing more.  In the northern corner of the room, where no portals are present, rests a baby dragon, who seems to have escaped from the portal marked Zolenia.  You may wish to avoid her den, as the teeth she does have seem to be quite sharp.%^RESET%^");
    set_exits(([        "square" : "d/nopk/tirun/square",
"achronil" : "/wizards/vian/achronilsplash",
        "lounge" :  "/d/nopk/standard/adv_inner",
        "arlon" : "/d/nopk/newarlon/rooms/square",
        "pastarlon" : "/d/pastarlon/rooms/square.c",
        "zolenia" :  "/wizards/vian/zoleniasplash"]));
    ;
   set_items(([
         "bed" : "The large wooden bed is unmade and seems to be a place where very little sleep is had.",
         "desk" : "The desk contains all of the materials needed for creating wondrous worlds and fantastic creatures.",
         "notebooks" : "The notebooks contain notes on different areas, monsters, and sketches of monsters, armor, weapons and maps.",
         "maps" : "Maps of the lands of Primal Darkness are scattered throughout the desk, with circles around areas where creation may take place.",
         "tools" : "Random gadgets that the Wizards use to create rooms and creatures and items are scattered throughout the desk and floor around it.",
         "den" : "The baby dragon has created a small den for herself, made of hay and other such things found through the portals.",
         "signs" : "There are currently a mere 4 portals with signs marked: Lounge, Zolenia, Square and Ironman.",
         "portals" : "There are portals to take you to your heart's desire.  The currently named ones are Lounge, Zolenia, Square and Ironman.  It is highly advised that you do not "
    ]));
          board = new("std/bboard");
          board -> set_name("board");
          board -> set_id(({"board","Vian's workboard"}));
          board -> set_max_posts(1000);
          board -> set_edit_ok(({"vian"}));
          board -> set_location("/wizards/vian/workroom.c");
          board -> set_short("%^BOLD%^%^BLACK%^Vian's Workboard%^RESET%^");
          board -> set_long("This is Vian's workboard, where you may leave any sorts of notes or ideas or problems you may be having.  ");
           board->set_board_id("vian's workboard");
}
void reset() {
 ::reset(); 
    if(!present("dragon")) {
        new("/wizards/vian/dragon.c")->move(this_object());
}
    if (!present("box"))
        new("/wizards/seeker/box")->move(this_object());
}

