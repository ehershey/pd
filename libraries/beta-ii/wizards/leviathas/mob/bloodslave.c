#include <std.h>
#include <terra.h>
inherit MONSTER;

void create() {
    ::create();
   set_name("bloodslave");
   set_id( ({ "bloodslave" }) );
   set_short("Bloodslave");
   set("aggressive", 1);
   set_level(20);
   set_long("A beautiful girl, stolen from her home.  The bloodslaves exist in this town for only one reason.  Food. "
        "She is completely naked if not for her collar and chains.");    
   set_body_type("human");
   set("race", "nymph");
   set_gender("female");
new(ARM "candc.c")->move(this_object());
    command("wear all");

}
