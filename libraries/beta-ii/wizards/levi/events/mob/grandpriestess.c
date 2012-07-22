#include <std.h>
#include <sp.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("priestess");
   set_id(({ "priestess", "grand priest" }));
   set_short("The Grand Priestess");
   set_level(50);
   set_long("The grand priestess is a simple woman, her hair "
        "woven in unique design down her back.  She is quite "
        "young an beautiful in a dull way.  Her eyes radiate "
        "with the light of the Avatar.");
   set_body_type("human");
   set_class("clergy");
   set_subclass("cleric");
   set_alignment(10000);
   set_skill("healing", 60000);
   set_skill("belief", 500);
   set_spells( ({"cure", "paralyze", "peace"}) );
   set("race", "human");
   set_gender("female");   
   set_hp(500000);
   set_mp(300000);
}
int query_mp() { return 300000; }
