#include <std.h>
#include <helgrath.h>

inherit ROOM;

void init() {
    ::init();
    add_action("break_ice", "break");
    add_action("search_ice", "search");
}
void create(){
    ::create();
    set_properties(([
	"light" : -1,
	"indoors" : 1
      ]));
    set_short("Ice Lair");
    set_long("Crushed skulls and frozen, mutilated body parts litter the cavern floor, sparkling "
      "with a frozen layer of icy gore. Smeared blood remains frozen where it "
      "splayed across the cold, rocky walls. Ominous shadows shift and loom on "
      "the corner of your vision. Leering red eyes stare from cracks and crevasses "
      "along one of the walls. "
    );

    set_exits(([
	"east": ROOMS "cave03.c" ]));
    set_smell("default", "The smell of rotting flesh wafts sickeningly about the room.");
    set_listen("default", "faint scratching noises can be heard.");
    set_items( ([
	"skulls" : "The skulls are partially frozen, some still have flesh on them.",
	"gore" : "Small bits of intestine, flash, and other parts of some past living body.",
	"blood" : "Frozen to the walls, the blood is smeared, spalltered, and splashed around the whole cave.",
	"eyes" : "Glowing faintly, the eyes follow your every move.",
	"walls" : "One of the walls has had marks chipped into it.",
	"marks" : "Something has been chipping at the ice.",
	"chips" : "The ice of one wall has funny chips taken out of it, perhaps you should search the ice...",
      ]));
}
void reset(){
    ::reset();
    if(present("cave lurker")) return;
    new(MOB"cave_lurker.c")->move(this_object());
    if(present("cave lurker 2")) return;
    new(MOB"cave_lurker.c")->move(this_object());
    if(present("cave lurker 3")) return;
    new(MOB"cave_lurker.c")->move(this_object());
    if(present("frozen corpse")) return;
    new("/d/helgrath/items/corpse.c")->move(this_object());

}
int break_ice(string str) {
    if(!str) {
	notify_fail("Break what?\n");
	return 0;
    }
    if(str != "ice" && str != "wall") {
	notify_fail("You can't break that!\n");
	return 0;
    }
    if(this_player()->query_stats("strength") < 30) {
	message("info", (string)this_player()->query_cap_name()+" chips at the northwest wall, doing little damage.", this_object(), ({ this_player() }));
	message("info", "You have not the strength to break the ice wall.", this_player());
	return 1;
    }
    message("info", (string)this_player()->query_cap_name()+" breaks the ice covering the northwest wall!", this_object(), ({ this_player() }));
    message("info", "You break the ice on the northwest wall uncovering an opening to another area!", this_player());
    add_exit(ROOMS"cave07.c", "northwest");
    return 1;
}
int search_ice(string str) {
    if(!str) {
	notify_fail("Search what?\n");
	return 0;
    }
    if(str != "ice" && str != "wall") {
	notify_fail("You don't find anything.\n");
	return 0;
    }     
    write("You notice the wall to the northwest is chipped and cracked like something was trying to break it.");
    say((string)this_player()->query_cap_name()+" studies the northwest wall.");
    return 1;
}
