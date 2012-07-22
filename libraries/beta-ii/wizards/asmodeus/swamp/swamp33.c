#include <swamp.h>
#include <std.h>
inherit ROOM;
int ghast;

void init() {
::init();
add_action("licho", "crawl");

}

void create() {
::create();
set_short("A small clearing within the plants");
set_long("The clearing here is surrounded by trees and thorny vines.  It would serve well as a den for the creatures of the swamp.");
set_property("swamp",1);
set_items(([
"vines" : "The vines are quite strong and covered in nasty thorns.  The vines stand about a meter off of the ground.",
"trees" : "Big tall trees.",
]));
set_properties((["light" : 0, "night light" : 0,]));
set_exits(([

"southeast": SWAMP "swamp32.c",


])); 
}

int licho(string what) {
if (what != "under the vines") return 0;
if (what == "under the vines") {
this_player()->move_player(SWAMP "swamp34.c");
return 1;
}
}




void reset() {
::reset();

if (!present("snake")) {

new(MOB "vinesnake")->move(this_object());
new(MOB "vinesnake")->move(this_object());
new(MOB "vinesnake")->move(this_object());

}

ghast = random(100);


}
