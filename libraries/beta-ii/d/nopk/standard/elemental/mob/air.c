// air elemental for the conjure spell
// a dungeonware.net production

#include <std.h>
#include <elemental.h>
inherit MONSTER;

 static string owner;
 static object ob, pl;

void create() {
  ::create();
   ob = this_object();
   set_name("air elemental");
   set_id( ({ "elemental mob", "air", "elemental", "air elemental" }) );
   set_gender("female");
   set_short("air elemental");
   set("aggressive", 0);
   set_heart_beat(1);
   set_level(9);
   set_long("A cloudy haze that is roughly imp shaped. The elementals features "
            "appear to be blurry shadows. The being is almost invisible.");
   set_body_type("imp");
   set_alignment(0);
   set("race", "elemental");
   set_hp(query_max_hp());
   set_mp(query_max_mp());
   set_sp(query_max_sp());
   set_class("mage");
   set_spell_chance(20);
   set_spells( ({ "wind" }) );
   new(SPEC "wind")->move(this_object());
}

void die() {
   if (present("wind", this_object()))
     present("wind", this_object())->remove();
   ::die();
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
   if (random(50) > (int)this_player()->query_skill("faith")) {
      x=random(20);
      switch (x) {
         case 1:
            write("The elemental ignores your command!");
            return 1;
            break;
         case 4:
            write("The elemental ignores your command!");
            return 1;
            break;
         case 10:
            write("The elemental breaks out of your control!");
            this_object()->kill_ob(pl, 0);
            owner = "blah";
            pl = (object)"";
            return 1;
            break;
         case 15:
            write("The elemental ignores your command!");
            return 1;
            break;
         case 19:
            write("The elemental breaks out of your control!");
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
      ob->force_me("say   wind");
      ob->force_me("say I have the following special abilities:");
      ob->force_me("say   <reveal powers>");
      ob->force_me("say I am level 9");
      return 1;
   }
   if (order == "die" || order == "suicide" || order == "return") {
    tell_room(environment(ob), "The elemental returns to it's native plane.\n", ({ ob }));
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
      message("info", "The elemental flies after its master.\n", environment(ob));
      this_object()->move(environment(pl));
      message("info", "An air elemental floats in.\n",environment((object)owner));
    }
}

