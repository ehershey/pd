#include <std.h>
inherit MONSTER;

 static string owner;
 static object ob, pl;

void create() {
  ::create();
   ob = this_object();
   set_name("salamander");
   set_id( ({ "spirit","salamander","fire spirit","lizard","fire lizard" }) );
   set_gender("male");
   set_short("Salamander");
   set("aggressive", 0);
   set_property("no_corpse", 1);
   set_heart_beat(1);
   set_level(18);
   set_long(
     "A lizard-spirit from the plane of fire. Its body is "
     "mostly engulfed in flames and it jets around on "
     "eruptions of heat, preventing it from touching the ground. "
   );
   set_body_type("lizard");
   set_alignment(-700);
   set_race("Salamander");
   set_hp(query_max_hp());
   set_mp(query_max_mp());
   set_sp(query_max_sp());
   set_class("mage");
   set_subclass("pyromancer");
   set_exp(1);
   set_spell_chance(50);
   set_spells( ({ "fireball","burn" }) );
   set_die( "The %^BOLD%^%^RED%^salamander%^RESET%^ vanishes in a "
     "brilliant explosion of light and heat." );

}


void init() {
  ::init();
   add_action("command", "command");
}

int command(string str) {
   string order, tm;
   object oi;
   int x;
   if ((string)this_player() != owner) return 0;
   if (random(50) > (int)this_player()->query_stats("wisdom")) {
      x=random(20);
      switch (x) {
         case 1:
        write("The salamander ignores your orders.");
            return 1;
            break;
         case 4:
        write("The salamander ignores your orders.");
            return 1;
            break;
         case 10:
        write("The salamander breaks free from your will.");
            this_object()->kill_ob(pl, 0);
            owner = "blah";
            pl = (object)"";
            return 1;
            break;
         case 15:
        write("The salamander ignores your orders.");
            return 1;
            break;
         case 19:
        write("The salamander breaks free from your will.");
            this_object()->kill_ob(pl, 0);
            owner = "blah";
            pl = (object)"";
            return 1;
            break;
         default:
            break;
      }
   }
   if (!str || sscanf(str, "%s to %s", tm, order)!=2) {
      write("Syntax: <command [monster] to [command]>\n");
      return 0;
   }
   oi = present(tm, environment(this_player()));
   if (oi != this_object()) return 0;
   if (order == "reveal powers") {
      ob->force_me("say I know the following spells:");
      ob->force_me("say   burn and fireball");
      ob->force_me("say I have the following special abilities:");
      ob->force_me("say   <reveal powers> and <return>");
      ob->force_me("say I am level 18");
      return 1;
   }
   if (order == "die" || order == "suicide") {
   tell_room(environment(ob), "The %^BOLD%^%^RED%^salamander%^RESET%^ "
          "vanishes in a brilliant explosion of light and heat.\n", ({ ob }) );
      ob->remove();
      return 1;
   }
   if (order == "return") {
    tell_room(environment(ob), "%^BOLD%^%^RED%^The salamander disappears in a swirl of flames.%^RESET%^\n", ({ ob }));
      ob->remove();
      return 1;
   }
   ob->force_me(order);
   return 1;
}

void set_owner(string str) {
   owner = str;
   pl = present(str, environment(this_object()));
   set_exp_share(pl, to_float(1/2));
}

void heart_beat() {
 ::heart_beat();
  if (owner == "blah") return;
  if (environment(this_object()) != environment(pl)) {
      message("info", "A salamander leaves following its master.\n", environment(ob));
      this_object()->move(environment(pl));
      message("info", "A salamander enters following its master.\n",
environment((object)owner));
    }
}
