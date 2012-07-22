#include <terra.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
    set_short("Lair of the Vampires");
    set_long(
      "%^BOLD%^Beautiful dancing figures dance across "
      "the floor with an overwhelming collective "
      "charisma.  The patterns in the dance and the "
      "infinite beauty are almost hypnotic.  The "
      "organs music gets louder and louder and the "
      "vampires dance faster and faster.");
 
    set_items(([
        "vampires" : "Dancing figures. ",
        "figures" : "Vampires.",
        "floor" : "From here the full beauty of the "            "carpet and tiles cannot be seen.", 
        ]));
    
    set_exits( (["north" : ROOMS "vamplair2.c",
                 "stairs" : ROOMS "vampcav10.c", ]) );
    
}

void reset() {
 ::reset();
     if(!present("dancer1.c"))
       new(MOB"dancer1.c")->move(this_object());
}
