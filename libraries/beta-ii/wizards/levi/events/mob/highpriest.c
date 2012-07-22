#include <std.h>
#include <sp.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("high priest");
   set_id(({ "priest", "high priest" }));
   set_short("A High Priest");
   set_level(56);
   set_long("The high priest looks very old and experienced.  He is teaching the young priests and priestesses how to use the bells.");
   set_body_type("human");
   set("race", "human");
   set_gender("male");
   set_emotes(10,
      ({"%^CYAN%^The high priest says:%^RESET%^ When offering a sacrifice to the Avatar, it is important that you remember to ring the large bell ten times, the medium bell twice and the small bell once.  This is vitally important.",
        "%^CYAN%^The high priest says:%^RESET%^ Remember, our order's traditional bell song.  Ring the bells in the following order: Large, small, large, medium, large.",
        "%^CYAN%^The high priest says:%^RESET%^ Do not forget our thankful bell song at any time!  Ring the large bell twice and the small bell once." }), 0);
  new(ARM "priestrobe.c")->move(this_object());
    command("wear robe");
}
