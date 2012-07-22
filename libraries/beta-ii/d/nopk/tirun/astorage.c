#include <std.h>
inherit ROOM;
#include <tirun.h>
void create() {
    ::create();
    set_short("Tirun Armour Supply");
    set_long("This is the storage room where armour is kept.");
    set_exits((["west" : ROOMS+"armour"]) );
    set_no_clean(1);
    new(ARM"tarm")->move(this_object());
   new(ARM"tailties")->move(this_object());
   new(ARM"saddle")->move(this_object());
    if(random(100) > 74) {
    if (!present("belt of candles"))
        new(OBJ "beltofcandles.c")->move(this_object()); }
}
  void reset(){
   ::reset();

    if(random(100) > 49) {
    if (!present("belt of candles")) 
        new(OBJ "beltofcandles.c")->move(this_object()); }
}
