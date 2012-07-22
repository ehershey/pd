#include <std.h>
#include <roston.h>
inherit ROOM;

create() {
   ::create();
   set_short("%^BOLD%^%^BLACK%^D%^WHITE%^a%^BLACK%^r%^WHITE%^k "
             "%^BOLD%^%^BLACK%^S%^WHITE%^o%^BLACK%^u%^BLACK%^l%^WHITE%^s "
             "%^BOLD%^%^BLACK%^Dungeon%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^You are standing in the D%^WHITE%^a"
            "%^BLACK%^r%^WHITE%^k %^BLACK%^S%^WHITE%^o%^BLACK%^u"
            "%^WHITE%^l%^BLACK%^s dungeon. There is %^RESET%^%^RED%^blood"
            "%^BOLD%^%^BLACK%^ splattered all over the ground. There are "
            "some old rotting %^WHITE%^bones%^RESET%^%^BOLD%^%^BLACK%^ "
            "there are several cells along the walls. There are "
            "some shackles and chains also. There is a sign above "
            "the door.%^RESET%^");
   set_listen("default", "%^BOLD%^%^WHITE%^You hear screams echoing around the dungeon.");
   set_items((["blood" : "This is some old %^RED%^blood%^RESET%^ "
               "dried up on the floor.",
               "cells" : "The cells have strong metal bars guarding "
               "the entrance and some %^BOLD%^%^WHITE%^bones%^RESET%^ "
               "laying on the cot of one of the cells.",
               "bones" : "These are %^BOLD%^%^WHITE%^white%^RESET%^ "
               "bones just laying there.",
               "sign" : "%^BOLD%^%^WHITE%^It clearly reads even if you "
               "some how escape the guardian will destroy you."]));
   set_exits((["up" : DARKSOUL"room1"]));
}

void reset(){
   ::reset();
   if(!present("man"))
   new(DARKSOUL"screamer.c")->move(this_object());
}
