#include <std.h>
inherit ROOM;
void create() {
::create();
    set_short("a huge cave");
    set_long("This is the entrance of the cave of Carnage, many "
	        "adventurers have lost there lifes here.The walls seem "
	        "to be covered with cobwebs and dust, the floor is made "
	        "of rock hard granite.");
           set_items(([
	"walls" : "The walls are covered with cobwebs and dust.",
        "ground" : "The ground is a hard granite floor that "
	              "seems to be coverd with dust." ]));
 set_property("light", 1);

 set_exits(([
	"south" : "/wizards/detach/C_room2.c",
	"north" : "/wizards/detach/C_room3.c",    
        "west" : "/wizards/detach/C_room4.c",
        "up" : "/d/standard/pass13"]));
}

void reset() {
     if(!present("spider"))
 new("/wizards/detach/spider")->move(this_object());
}
