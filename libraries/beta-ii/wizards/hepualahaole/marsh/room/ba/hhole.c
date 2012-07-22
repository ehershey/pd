#include <std.h>
#include <marsh.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("inside",1);
    set_short("A country style house");
    set_long(
      "This is a country style house.  In the center of the room is an "
      "an oak table with six chairs around it.  There are many knick knacks."
      "scattered around the room making it have a more down to earth feeling for the "
      "guests.  There is a bookcase crammed with county style lizard dolls."
          );

    
    set_items(([
        "house" : "It is a very tidy little house.",
        "table" : "Made of oak, and has a vase of flowers on it.",
        "vase" : "Made of clay and painted a bright blue color.",
        "flowers" : "Lilacs",
        "chairs" : "Six oak made chairs set around the table.",
        "bookcase" : "It has five shelves full of dolls.",
        "dolls" : "Ugly, they have human faces on a lizard's body",
    ]));

    set_exits( ([
"out" : BA "ba33",
"down" : BA "hhole2",
    ]) );

}
