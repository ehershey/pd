#include <std.h>
#include <guild.h>
inherit ROOM;
void create() {
::create();
set_properties((["light":3, "indoors":1]));
set_name("Illuminati Tirun Subhall");
set_short("Illuminati Tirun Subhall");
set_long("%^RESET%^%^ORANGE%^This is the Illuminati subhall of Tirun, an outpost of the Tower of "
"Light. Members come here to get away from the crowds of city. Large chairs are "
"spread around the room."); 
set_exits(([
"down"    : ROOMS"illuminati/new/tirunenter.c"
]));
set_items(([
"chairs"     : "The chairs are placed in a circle facing inwards around the center of the room. It would be great to sit in one."
]));
}

void reset() {
::reset();
if(!present("portal2"))
new(ROOMS"illuminati/new/portal2.c")->move(this_object());
}

void init() {
   ::init();
     add_action("sit", "sit");
}

int sit(string str) {
     if (str == "in chair") {
        write("You sit down in the comfy chair and relax in the quiet.");
        this_player()->set_hp(this_player()->query_max_hp());
        this_player()->set_sp(this_player()->query_max_sp());
        this_player()->set_mp(this_player()->query_max_mp());
        this_player()->set_paralyzed(10);
        return 1;
        }
     write("The only thing to sit in would be the chair.");
     return 1;

}
