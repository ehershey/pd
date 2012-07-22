#include <std.h>
#include <guild.h>
inherit ROOM;
void create()
{
::create();
set_properties((["light":3, "indoors":1]));
set_name("Illuminati Helgrath Subhall");
set_short("Illuminati Helgrath Subhall");
set_long("%^RESET%^%^ORANGE%^The inner sanctuary of the Helgrathian Subhall. Illuminati come here "
"to get away from the cold. A large fireplace keeps the room warm and there are "
"many comfy chairs around the room.");
set_exits(([
"up"    : ROOMS"illuminati/new/helentrance.c"
]));
set_items(([
"fireplace"     : "The flames in the fireplace never die out, keeping the room full of warmth at all times.",
"chairs"        : "The chairs are large and well padded, it would be very nice to sit in one."
]));
}
void reset()
{
::reset();
if(!present("portal2"))
        {
new(ROOMS"illuminati/new/portal2.c")->move(this_object());
}
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
