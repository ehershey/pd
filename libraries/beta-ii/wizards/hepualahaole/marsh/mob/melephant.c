#include <std.h>
#include <marsh.h>
inherit MONSTER;

void create() {
   ::create();
   set_gender("male");
   set_name("elephant");
   set_id( ({ "elephant","sickly elephant"}) );
   set_short("A sickly elephant");
   set_long("The elephant is dying of a rare disease, Mad elephant's disease.");
   set_level(45);
   set_body_type("elephant");
   set_alignment(200);
   set_race("elephant");
   set_class("fighter");
   set_skill("attack",250);

    set_emotes(10,
        ({"The elephant looks around wildeyed.",
          "The elephant appears to be sick.",
          "The elephant charges at a tree and misses."}), 0);
   }