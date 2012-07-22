#include <std.h>
#include <helgrath.h>

inherit ROOM;

void create(){
    ::create();
    set_properties(([
	"light" : 0, 
	"indoors" : 1
      ]));
    set_short("Ice Cave");
    set_long("Cold water drips slowly from the ceiling, collecting in small pools "
      "around the cave. The icey, reflective walls catch light from the distant "
      "exit, casting glimmering shadows across the floor. "
    );
    set_exits(([ "north": ROOMS "cave03.c",
	"south": ROOMS "cave01.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "Dripping water can be heard.");
    set_items( ([
	"walls" : "The walls are covered in ice",
	"pools" : "Pools of slushy water.",
      ]));
}
void reset(){
    ::reset();
    if(present("dark elf")) return;
    new(MOB"darkelf.c")->move(this_object());
}
