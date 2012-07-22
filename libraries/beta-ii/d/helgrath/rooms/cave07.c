#include <std.h>
#include <helgrath.h>

inherit ROOM;

void create(){
    ::create();
    set_properties(([
	"light" : -1,
	"indoors" : 1
      ]));
    set_short("Icey Cavern");
    set_long("Crushed skulls and frozen, mutilated body parts litter the cavern floor, sparkling "
      "with a frozen layer of icy gore. Smeared blood remains frozen where it "
      "splayed across the cold, rocky walls. Ominous shadows shift and loom on "
      "the corner of your vision. ");
    set_exits(([ "southeast": ROOMS "cave05.c" ]));
    set_smell("default", "It reeks of rotting flesh in here.");
    set_listen("default", "Faint scratching noises can be heard.");
    set_items( ([
	"skulls" : "The skulls are partially frozen, some still have flesh on them.",
	"gore" : "Small bits of intestine, flash, and other parts of some past living body.",
	"blood" : "Frozen to the walls, the blood is smeared, spalltered, and splashed around the whole cave.",
      ]));
}
void reset(){
    ::reset();
    if(present("ice golem")) return;
    new(MOB"ice_golem.c")->move(this_object());
}
