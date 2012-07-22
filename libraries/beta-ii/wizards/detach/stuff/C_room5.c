#include <std.h>
inherit ROOM;
void create() {
::create();
    set_short("a huge cave");
    set_long("A slight 'path' continues to the north, and then back "
             "to the north. The cold granite surrounds you from every "
             "direction. You feel hopelessly lost.");
    set_items(([
        "walls" : "The walls are covered with cobwebs and dust.",
        "ground" : "The ground is a hard grante floor that "
	           "that seems to be covered with dust."]) );
   set_property("light", 1);
 set_exits(([
     "north" : "/wizards/detach/C_room2.c"
      ]));
}

void reset() {
 ::reset();
   if(!present("man"))
    new("/wizards/detach/man")->move(this_object());
}
