inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
    ::create();
    set_property("indoors",0);
    set_property("light",0);
    set("short","Palace Wall");
    set("long","This is one of the turrets along the outer wall of the palace. "
      " The land surrounding the city can be seen from this height.  The wind"
      " whirls about up here.  The turret has exits to the east and north.");
    set_smell("default","The air here is clear and refreshing.");
    set_listen("default","The soft sound of people talking can be heard below.");
    set_items((["sky":"The sky is dark as ever.",
	"turret":"The turret is where the archers hang out and protect the citizens of Tenebrae."]));
    set_exits((["north":ROOMS "tower2.c","east":ROOMS "tower8.c"]));
}

void reset() {
    ::reset();
    if(!present("archer")) {
	new(MOB "archer")->move(this_object());
    }
}

void init() {
    ::init();
    add_action("jump_it","jump");
}

int jump_it(string str) {
    if(!str) {
	notify_fail("You jump around.\n");
	return 0;
    }
    if(str != "to roofs") {
	notify_fail("Jump to where?\n");
	return 0;
    }
    else {
	this_player()->move_player(ROOMS "roof17.c", "jumps to the roofs.");
	return 1;
    }

}
