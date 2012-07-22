#include <std.h>
#include <rain.h>
inherit MONSTER;

void create(){
   ::create();
   set_name("anaconda");
   set_id(({"anaconda", "snake", "large anaconda"}));
   set_short("A very large Anaconda");
   set("agressive", 0);
   set_level(20);
   set_long("This anaconda is %^BOLD%^%^RED%^HUGE%^RESET%^"
            " The Anaconda is green with many patterns on its scales");
   set_race("snake");
   set_body_type("artrell");
   new(OBJ"ana_fang.c")->move(this_object());
   this_object()->force_me("wield fangs");
}
