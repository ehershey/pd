#include <std.h>
#include <nemar.h>

inherit ROOM;

void create() {
::create();
set_name("faerie dock");

set_short("Faerie Dock");

set_day_long("The short stone dock seems to be constructed out of the same 
white marble as the walls.  You can see what appears to be reflected sunlight 
emitting off the bottom of the dock deep below the waters.  There are a few 
small boats moored on the dock that juts out from the wharf.");

set_night_long("The stone dock seems to be reflecting sunlight as though it 
were day.  The brightness of the dock is mirrored by the brightness of the 
walls of Naej.  It's a safe bet that from far off you can see the gleaming 
walls, a beacon to travelers.");

set_listen("default","The waves lightly lap against the dock rocking the 
boats lightly.  Something seems out of place...");

set_smell("default","The salty sea air smells as though it would sting the 
nose.");

set_items
  (([
    "stone" : "The stone is a beautiful white marble.",
    ({"walls","dock"}) : "Both the dock and the walls are made of white 
marble.  The beautiful carvings in the stone are inlaid with what looks to be 
gold.",
    "gold" : "Try as you might, the gold will not come out of the carvings, 
you cannot even scratch it.",
    "waves" : "The waves are eerily still, considering they are ocean waves.  
There is no harbor, just open ocean..."
  ]));

set_properties
  (([
    "light" : 3,
    "night light" : 2,
    "town" : 1
  ]));

set_exits
  (([
    "northeast" : NAEJ"north_wharf.c",
    "east" : NAEJ"wharf.c"
  ]));
}
