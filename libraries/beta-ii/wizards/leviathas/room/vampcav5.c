#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
    set_short("The Vampires Cave");
    set_long(
      "%^RED%^T%^BOLD%^he red colour has almost completely filled "
      "this room and near the end of the cave there seems to be "
      "a dull light. There is a small hole in the wall.",);
 
    set_items(([
        "red" : "%^RED%^Blood is spilt all over the floor.",
        "light" : "The light is dull but it is definately there.",
        "hole" : "There is a small hole with a crack running down "
              "from it.  It is too small to enter. ",
        "crack" : "You look over the crack and break it opening up "
              "the hole.  It leads east. ", 
        ]));
    
    set_exits( (["north" : ROOMS "vampcav7.c",
                 "south" : ROOMS "vampcav4.c",
                 "east" : ROOMS "vampcav6.c", ]) );
    
    add_invis_exit("east");
}
