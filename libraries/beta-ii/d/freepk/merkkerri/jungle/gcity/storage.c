#include <std.h>
#include <gcity.h>
#include <mjungle.h>
inherit ROOM;
void create() {
  ::create();
set_short("%^YELLOW%^Dingo's supply room%^RESET%^");
set("long", "%^YELLOW%^Dingo stores weapons and such here.%^RESET%^");
    set_exits( 
(["south" : GCITY"gcity25.c"]) );
}

  void reset(){
   ::reset();
    if(random(100) > 74) {
    if (!present("belt of candles")) 
        new("/d/nopk/tirun/obj/misc/beltofcandles.c")->move(this_object()); }
   }
