// zombie for the raise spell
// a dungeonware.net production
#include <std.h>
#include <daemons.h>
inherit UNDEAD;
 static string owner;
 static object ob, pl;
void create() {
  ::create();
   ob = this_object();
   set_name("zombie");
   set_id( ({ "zombie undead", "zombie", "undead mob" }) );
   set_gender("male");
   set_short("a zombie");
   set_heart_beat(1);
   set("aggressive", 0);
   set_level(13);
   set_long("The half decayed remains of some creature, the flesh is rotting off the bone. "
            "The rotting creature stares vacantly. ");
   set_body_type("elf");
   set_alignment(-1500);
   set("race", "undead");
   set_exp(1);
   set_hp(query_max_hp());
   set_mp(query_max_mp());
   set_sp(query_max_sp());
   set_class("clergy");
   set_subclass("kataan");
   set_skill("faith",100);
   set_exp(1);
   set_spell_chance(25);
   set_spells( ({ "absorb", "fear" }) );
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
   if (random(50) > (int)this_player()->query_skill("necromancy")) {
      x=random(20);
      switch (x) {
         case 1:
            write("The zombie ignores your command!");
            return 1;
            break;
         case 4:
            write("The zombie ignores your command!");
            return 1;
            break;
         case 10:
            write("The zombie breaks out of your control!");
            this_object()->kill_ob(pl, 0);
            owner = "blah";
            pl = (object)"";
            return 1;
            break;
         case 15:
            write("The zombie ignores your command!");
            return 1;
            break;
         case 19:
            write("The zombie breaks out of your control!");
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
    if (present("gagger12345",this_player()) &&
        member_array(order[0..strsrch(order," ")-1],
        ({"say","yell","whisper","shout","tell","emote","emoteto","speak","reply"})) != -1 ||
        (int)sizeof(load_object(SOUL_D)->query_atmos(order[0..strsrch(order," ")-1])) >= 1) return 1;
   if (order == "reveal powers") {
      ob->force_me("say I know the following spells:");
      ob->force_me("say   absorb and fear");
      ob->force_me("say I have the following special abilities:");
      ob->force_me("say   <reveal powers> and <return>");
      ob->force_me("say I am level 13");
      return 1;
   }
   if (order == "die" || order == "suicide") {
   tell_room(environment(ob), "The zombie falls %^RED%^dead%^RESET%^ before you.\n"
                              "The corpse turn to dust and blows away.\n", ({ ob }));
      ob->remove();
      return 1;
   }
   if (order == "return") {
    tell_room(environment(ob), "%^BOLD%^The zombie digs it's way into the ground!%^RESET%^\n", ({ ob }));
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
  object *shade;
 ::heart_beat();
  if (owner == "blah") return;
  if (this_object() && pl)
  if (environment(this_object()) != environment(pl)) {
      message("info", "The zombie leaves following it's master.\n", environment(ob));
      this_object()->move(environment(pl));
      message("info", "A zombie enters following it's master.\n",environment((object)owner));
    }
  if(pl != (object)"")
    for(int i=0;i<sizeof(shade);i++)
      if((shade[i]->id("zombie undead")) && (shade[i] != this_object())) {
        message("info", "The zombie flails around and attacks it's
owner!",environment(ob));
        this_object()->kill_ob(pl, 0);
        pl = (object)"";
        owner = "blah";
      }
}
