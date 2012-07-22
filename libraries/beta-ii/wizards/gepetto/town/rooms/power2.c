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

set_short("Power Lane");
set_long("Walking on Power Lane reveals how life truly should be. "
         "Residents of all races and classes mingle as they go about "
         "their buisness. Children play freely and without care in the "
         "streets. Looking north reveals two buildings on either side "
         "of the street. In the distance, the city square can be seen "
         "north. To the south, the gates of the city can be viewed "
         "towering over the guards.");
set_items(([
         "residents" : "Residents of all creeds and class mingle while going about their buisness." ,
         "children" : "Children laugh and play freely in the streets." ,
         "streets" : " The streets are clean and free of debris." ,
         "buildings" : "Two buildings can be seen just north of here." ,
         "square" : "The center of town can be seen north in the distance." ,
         "gates" : "The gates loom over you to the south, dwarfing the guards standing watch." ,
         ]));
set_exits( ([
             "north" : ROOMS "power3.c",
             "south" : ROOMS "power1_stavei9.c", 
         ]) );
set_smell("default", "The city smells clean and the air is brisk.");
set_listen("default", "The sounds of a busy city are all about.");

}
