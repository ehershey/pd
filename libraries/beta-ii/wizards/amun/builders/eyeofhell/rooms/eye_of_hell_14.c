#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "EYE OF HELL");
    set("long","%^BOLD%^%^RED%^The path moving towards the middle of the eye' is bright with fire. The walls are glowing red from the hot flames scorching them. A high pitched howl is heard somewhere towards the middle of the eye. The stray faces behind the bars look beaten, demented and burnt. This is a place of torture.%^RESET%^");
    set_items( ([ "path": "%^RESET%^%^RED%^This path looks as if it is stained with years of blood.%^RESET%^", "blood": "%^RESET%^%^RED%^Some of it looks fresh.%^RESET%^", "cliff": "%^RESET%^%^ORANGE%^The cliff is full with rocks and shadows dancing off of them.%^RESET%^", "rocks": "%^RESET%^%^RED%^The rocks look as if they were used in battle.  There is some fresh flesh on a few of them.", "faces": "%^BOLD%^%^BLACK%^These are the faces of the beaten and torn. Their eyes call out to you for help." ]) );
    set_exits( ([ "west": HELLROOM+"eye_of_hell_13", "east": HELLROOM+"eye_of_hell_15", "northeast": HELLROOM+"middle_12" ]) );
}
void reset() {
    ::reset();
    if (!present("horseman", this_object()))
	new(HELLMON+"headless_horseman")->move(this_object());
    if (!present("centaur", this_object()))
	new(HELLMON+"black_centaur")->move(this_object());
}
