#include <petzoo.h>
#include <std.h>
inherit "std/room";

void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Slerne's House");
    set("long", "This looks to be a temporary abode of a dragon.  There's not much "+
      "furniture anywhere, although there is a big rock against the far wall that "+
      "that emanates heat and looks surprisingly comfortable.");
    set_exits( ([ "west" : ROOMS + "dragonhouse" ]) );
    set_items(
      (["rock" : "This is more of a rock shelf.  It covers most of the far wall and "+
	"even a little bit of the corner.  It is spacious and looks to be able to "+
	"function as either a place to lounge or even sleep on.",
	"corner" : "With some effort, you may even be able to grab the rock there and "+
	"pull it away from the wall.",
	"wall" : "It has a large rock shelf up against it, one piece extending around the corner.",
	"shelf" : "It's contoured in several places, and rather flat.",
	"piece" : "There is a little bit of space between there and the wall, maybe you can grab it?"
      ]) );

}
void init() {
    ::init();
    add_action("grab_rock", "grab");
}
int grab_rock(string str) {
    string pc = this_player()->query_cap_name();
    string pc_action = pc+" exposes a hole in the wall!";
    if(!str) return notify_fail("Grab what?");
    if ((str != "corner") && (str != "piece")) {
	return notify_fail("Grab what?\n");
    }
    write("You grab the rock near the corner and pull.  The whole thing is pretty heavy, but"+
      " you manage to slide it out a bit, exposing a hole in the wall!");
    add_exit(ROOMS"improom.c", "hole");
    tell_room(environment(this_object()),pc_action,this_object());
    return 1;
}
