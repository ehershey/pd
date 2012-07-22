// hellcat demon for the summon spell
// a dungeonware.net collaboration with
// -(Inferno)-
// Epiton Roston Verlin Drannor 
#include <std.h>
#include <sindarii.h>
inherit MONSTER;

 static string owner;
 static object ob, pl;
void create() {
  ::create();
   ob = this_object();
   set_name("hellcat");
   set_id( ({ "abyss demon", "hellcat", "demon", "cat" }) );
   set_gender("female");
   set_short("an fiendish hellcat");
   set("aggressive", 0);
   set_heart_beat(1);
   set_level(20);
    set_exp(0);
   set_long("A furless cat spawned from hell, the hellcat appears as a small black cat with glistening black fangs and glowing red eyes.");
   set_body_type("feline");
   set_alignment(-1000);
   set("race", "demon");
  set_hp(query_max_hp());
  set_mp(query_max_mp());
  set_sp(query_max_sp());
   set_class("rogue");
   set_spell_chance(40);
   set_spells( ({ "gore" }) );
   new(ROOMS"abyss/obj/ak")->move(ob);

}

void init() {
  ::init();
   add_action("command", "command");
}

int command(string str) {
   string order, tm,  victim, val;
   int x, penalty;
   object oi;
   if ((string)this_player() != owner) return 0;
   if (random(90) > (int)this_player()->query_skill("faith")) {
      x=random(20);
      switch (x) {
         case 1:
            write("The hellcat ignores your command!");
            return 1;
            break;
         case 4:
            write("The hellcat ignores your command!");
            return 1;
            break;
         case 10:
            write("The hellcat breaks out of your control!");
            this_object()->kill_ob(pl, 0);
            owner = "blah";
            pl = (object)"";
            return 1;
            break;
         case 15:
            write("The hellcat ignores your command!");
            return 1;
            break;
         case 19:
            write("The hellcat breaks out of your control!");
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
      ob->force_me("say   gore");
      ob->force_me("say I have the following special abilities:");
      ob->force_me("say   <reveal powers>, <curse>");
      ob->force_me("say  <curse [logged_on_player]>");
      ob->force_me("say I am level 20");
      return 1;
   }
   if (order == "die" || order == "suicide") {
    tell_room(environment(ob), "The hellcat turns a pale grey "+
              "and slumps down dead before you.\n", ({ ob }));
      ob->die();
      return 1;
   }
   if (sscanf(order, "curse %s", victim)==1) { 
       if (present(victim, environment(this_object()))) {
           penalty = -1
           victim->add_stat_bonus("strength", penalty, 100);
          
           return 1;
       } else {
           if (!(oi=find_living(victim = lower_case(victim)))) {
              write("<curse [logged_on_player]>");
              return 1;
           }
           owner = "blah";
           pl = (object)"";
           this_object()->move(environment(oi));
            if (oi->query_level() < 5) {
               destruct(ob);
             return 1;
           }
           val = sprintf("kill %s", victim);
           this_object()->force_me(val);
           return 1;
         }
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
      message("info", "A hellcat follows its master.\n", environment(ob));
      this_object()->move(environment(pl));
      message("info", "A hellcat enters, crossing your path.\n", environment((object)owner));
    }
}
