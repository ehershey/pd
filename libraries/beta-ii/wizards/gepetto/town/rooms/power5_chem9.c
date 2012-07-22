//Gepetto


#include <std.h>
#include <gepetto.h>

inherit ROOM;

void create() {
::create();
set_property ("plain", 1);
set_property ("outdoors" ,1);
set_property ("light", 2);
set_property ("night light", 1);

set_short("Power Lane/Chem Terrace");
set_long("This intersection lies about one third of the way between the "
         "city gates and the city square. Adults tend to their tasks as "
         "children play freely. Guards stand here to insure order and "
         "also keep guard over the city. The gates are finally beginning "
         "to fade from view south as the square begins to get noticably "
         "closer.");
set_items(([
       "gates" : "The city gates lie to the south." ,
       "adults" : "The adults tend to their daily routines." ,
       "children" : "Children frolic and play in the streets." ,
       "square" : "The square begins to grow noticeably closer." ,
         ]));
set_exits( ([ 
             "north" : ROOMS "power6.c",
             "south" : ROOMS "power4.c",
             "east" : ROOMS "chem10.c",
             "west" : ROOMS "chem8.c",
         ]) );
set_smell("default", "The city smells clean and the air is brisk.");
set_listen("default", "The sounds of a busy city are all about.");


}