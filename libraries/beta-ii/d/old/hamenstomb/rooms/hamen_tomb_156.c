#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long","%^BOLD%^%^YELLOW%^The light is staying unusually bright this far up in the pyramid, you notice there are many writings on the walls.  The breeze picks up and you are shivering like mad.  The torches shine brighter and brighter as they flicker with the wind.\n");
    set_items( ([ "writings": "%^BOLD%^%^BLACK%^In the darkness of the Pyramid, a mythical being can be found. If you find it, and respond to the unclear, you will find the '%^RED%^occulus inferi%^BLACK%^'.", "torch": "%^BOLD%^%^BLACK%^The torches are flickering as if shivering from the cold." ]) );
    set_exits( ([ "east": ROOMS+"hamen_tomb_158", "west": ROOMS+"hamen_tomb_154" ]) );
    new(MON+"great_red_scorpion")->move(this_object());
    new(MON+"rattlesnake")->move(this_object());
    new(MON+"baby_rattlesnake")->move(this_object());
    new(MON+"baby_red_scorpion")->move(this_object());
}
