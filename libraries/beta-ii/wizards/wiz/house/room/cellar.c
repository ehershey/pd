#include <wiz.h>
inherit ROOM;

void create(){
::create();
   set_short("wiz's cellar");
   set_long("Evil creatures lurk here. "
            "wiz has not replaced the light bulb in ages, it is very dark. "
            "The evil h0h0tr0n is known to live here, along with other evil "
            "beasts.");
   set_items     (([ "stairs" : "They lead back upstairs." ]));
   set_properties(([ "dark":1, "night light":1, "indoors":1 ]));
   set_exits     (([ "up" : WIZHOUSE ]));
}
void reset(){
 ::reset();
  set_search("default", (: this_object(), "claws" :));
   if(!present("h0h0tr0n"))new(HOUSEMOB "h0h0tr0n.c")->move(this_object());
}
void claws(){
        write("You find a pair of golden wingclaws!");
        new(HOUSEARM "wingclaws.c")->move(this_player());
        remove_search("default");
}
