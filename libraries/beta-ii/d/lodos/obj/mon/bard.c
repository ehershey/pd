#include <std.h>
inherit "/std/police";
static int singing=0;

void create() {
 ::create();
   set_short("Tryst, the wandering bard");
   set_id( ({ "tryst", "bard" }) );
   set_name("bard");
   set_level(21);
   set_long("Once a wandering bard, Tryst has settled in Lodos. "
            "You could probably ask him to sing.");
   set_body_type("human");
   set_race("elf");
   set_gender("male");
}

int sing(string str) {
   if (!str || str != "tryst to sing") return 0;
   if (!singing)
      singing = 1;
   return 1;
}

void init() {
 ::init();
   add_action("sing", "ask");
}

void heart_beat() {
   object ob, env;
 ::heart_beat();
   ob = this_object();
   env = environment(this_player());
   if (!singing) return;
   switch (singing) {
      case 1:
         tell_room(env, "%^CYAN%^Tryst sings:%^RESET%^ Welcome to "
         "the town of lore,", ({ }));
         break;
      case 2:
         tell_room(env, "%^CYAN%^Tryst sings:%^RESET%^ The place of "
         "life and peace,", ({ }));
         break;
      case 3:
         tell_room(env, "%^CYAN%^Tryst sings:%^RESET%^ Lodos, the village "
         "of health and love", ({ }));
         break;
      case 4:
         tell_room(env, "%^CYAN%^Tryst sings:%^RESET%^ Wander around, "
         "find your destiny, to heal and cure", ({ }));
         break;
      case 5:
         singing = 0;
         return;
      default:
         singing = 0;
         break;
   }
   if (singing > 4) singing = 0;
   if (singing <= 4) singing++;
}
