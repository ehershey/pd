#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 2, "indoors" : 0, "night light" : 2,
                "no teleport" : 1, "mountains" : 1, "town" : 1]) );
   set_short("Platinum Street - Steel Hammer Village");
   set_long(
            "This is the entrance to a village that lies ahead "
            "further to the east. The road leads into the village "
            "or transforms into a path beyond the gates. A large "
            "sign is hung on the side of a building. Small houses "
            "are ahead further east. Giant mountains surround "
	    "the village.");
   set_items(([
            "mountains" : "The mountains stretch in all directions. They "
                        "surround the small village. ",
            "gates" : "There are big, iron gates leading into the mountains.",
            "houses" : "Small stone buildings that have been carved from the "
                "mountains lie ahead to the east. They're all in different "
		"shapes and sizes, but they are all pretty small.",
            "road" : "A very interesting design. The road is stone, carved "
                "from the mountain, and into various designs. The designs "
		"are very artistic and beautiful.",
            "village" : "Steel Hammer village lies ahead to the east. "
                "around the village, taking part in their daily activities.",
            "path" : "The path leads west through the mountains. ",
            "sign" : "%^BOLD%^%^YELLOW%^          Welcome to Steel Hammer Village! "
		"\n \n %^RED%^1. No littering \n 2. No soliciting \n 3. No "
		"loitering \n 4. No mass slaughterings \n \n \n            "
		"               %^YELLOW%^-The Village Elders%^RESET%^"
   ]));
   set_smell("default", "The air is crisp and the air is humid.");
   set_listen("default", "The solf rumble of the village drones the air.");
   set_exits( ([ 
        "west" :  ROOMS "sh_1",
        "east" :  ROOMS "sh_3"]));
}
void reset() {
::reset();
    if(!present("villager")) new(MOB"villager2.c")->move(this_object());
}
