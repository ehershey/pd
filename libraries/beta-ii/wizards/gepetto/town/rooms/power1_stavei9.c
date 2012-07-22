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

set_short("Power Lane/Stavei Ave.");
set_long("The sprawling city of Rawlthford begins at this point. Two streets intersect "
         "here and busy residents can be seen bustleing about their daily "
         "activities. Towards the north a large square is barely visible while "
         "while barely anything is visible to the east or west. Children play in "
         "the clean, well kept, streets.");
set_items(([ 
    "residents" : "Residents of every race and occupation mull about their daily buisness.",
    "square" : "A large square, presumably the center of town can be seen in the distance.",
    "children" : "Children run and play carelessly in the streets.",
    "streets" : "The streets are clean and well kept.",
         ]));
set_exits( ([
               "north" : ROOMS "power2.c",
             "west" : ROOMS "stavei8.c", 
             "east" : ROOMS "stavei10.c",
         ]) );
set_smell("default", "The city smells clean and the air is brisk.");
set_listen("default", "The sounds of a busy city are all about.");

}
