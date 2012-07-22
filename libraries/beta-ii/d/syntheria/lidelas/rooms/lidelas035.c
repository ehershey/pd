
#include <std.h>
#include <lidelas.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("rutyo street");
        set_short("Rutyo street");
        set_long("A short street in the town of lidelas, it serves to connect some of the residential districts to the main parts of town. A few old houses can be seen along the road, but most of them are hidden by the large buildings made from stone. The larger buildings have many sculptures on them, most of them would seem to be of gargoyles. The gargoyles look down to the street, watching over all the people who walk by. The streets are made of a fine cobble stone, and looks to be well maintained.");  
        set_properties( ([
        "light"       : 2,
        "night light" : 2,]) );
        set_items(([
        "houses"    :  "Houses built out of wood, nothing very special about them.",
        "gargoyles"    :  "They are not very large, and seem to be carved into the building."
            ]));
            set_listen("default", "It is rather quiet in this part of town.");
            set_smell("default", "Sea salt fills the air.");
            set_exits(([
                        "north"         : ROOMS "lidelas034.c",
                        "east"          : ROOMS "lidelas037.c",
        ]));

}

void reset() {
   object *childs;
   ::reset();
   childs = children(MOB"lidelas_patrol.c");
   if(find_object(MOB"lidelas_patrol.c")) childs -= ({find_object(MOB"lidelas_patrol.c") });
   if (childs==({}) || !sizeof(childs))
     new(MOB "lidelas_patrol.c")->move(this_object());
}
