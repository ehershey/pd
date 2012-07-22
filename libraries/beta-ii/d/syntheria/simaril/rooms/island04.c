#include <std.h>
#include <simaril.h>

inherit ROOM;
void create()
{
    ::create();
        set_name("small island");
        set_short("Small island");
        set_long("Lush green plants cover the entire island with the exception of a sandy shore that circles the island. "
                  "Stranded on the beach is a small dinghy. It looks lodged in the sands of the beach. "
                  "It is possible someone might be on this island. "
                  "Several large trees stand tall above the plants to the south, deeper into the island. "       
                );  
        set_properties( ([
        "light"       : 2,
        "night light" : 0,
        "forest"      : 1,
        ]) );
        set_items(([
        "sea"       :   "A vast sea which looks endless.",
        "island"    :   "A small island covered with lush greens.",
        "water"     :   "Small waves break on the sandy shore.",
        "plants"    :   "A wide variety of green plant life that grows wild.",
        "shore"     :   "A thin sandy beach that circles most of the island.",
        "trees"     :   "Large, thin, and tall. Maybe they have some fruit growing on them.",
        ]));
            set_listen("default", "The waves wash up on the shore creating a calming scene. Occasionally  a strange noise from the island breaks the peace.");
            set_smell("default", "Sea salt fills the air, masking out all other smells.");
                set_exits(([
                        "west"              : ROOMS"island10.c",
                        "east"              : ROOMS"island03.c",
                        "south"             : ROOMS"island05.c",                  
        ])); 
        new(OBJ"dinghy.c")->move(this_object());
}
 
void reset() {
   ::reset();

   
}
      






