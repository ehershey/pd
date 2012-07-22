// Coded by Whit

#include <std.h>

#include <citrin.h>

inherit ROOM;


void init() {
::init();
add_action("east", "east");
}

int east() {
object tp;
tp = this_player();
write_file("/wizards/whit/areas/citrin", "Area Access: "+tp->query_cap_name()+
" of level "+tp->query_level()+"\n");

tp->move_player(ROOM2"2");
return 1;
}

void create() {
::create();
set_name("Citrin Forest");
set_day_long("This part of the path is very ruff.  Many "
"twigs from the overhead trees have fallen making it hard "
"to stay quiet from the animals of the forest.  Large trees "
"stand on both sides of the path making it hard to see all "
"but the path.  ");
set_night_long("This part of the forest is very ruff.  Many "
"twigs from the overhead trees have fallen making it hard "
"to stay quiet from the animals of the forest.  Large trees "
"stand on both sides of the path making it hard to see all "
"but the path.  ");
set_items(([

(({"path" , "twigs", "twig"})) : "The path is covered with twigs "
"from overhead.",
(({"tree", "trees"})) : "The giant trees dominate this forest." ]));
set_properties(([ "light" : 1, "night light" : 1, "forest" : 1 ]));
set_exits( ([ "east" : ROOM2"2.c",
            "west" : "/d/standard/outlands/cover3",
    ]) );

}
