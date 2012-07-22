#include <std.h>
#include <marsh.h>
inherit MONSTER;
void create() {
   ::create();
   set_name("lizardman");
   set_id( ({ "lizardman","lizardmachete","hard-working lizardman","lizard"})
);
   set_short("A hard-working lizardman");
   set_long("A short stocky humanoid about five and a half feet tall. "
    "Powerfully muscled, it has dark green scaley skin and "
            "has a long tail.\n");
   set_level(40);
   set_gender("male");
   set_body_type("human");
   add_limb("tail","",600,0,9);
   set_alignment(-200);
   set_race("lizardman");
   set_class("fighter");
   set_skill("attack",200),
   set_money("gold", 500);
   new(WEP "machete")->move(this_object());
   force_me("wield sword");
   }
