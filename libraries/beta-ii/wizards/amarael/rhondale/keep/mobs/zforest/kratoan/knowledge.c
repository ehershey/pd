#include <std.h>
#include <aziraphale.h>
inherit MONSTER;

void create() {
   ::create();
        set_name("Ancient Dendrinar");
        set_id( ({"monster", "dendrinar", "ancient dendrinar"}) );
        set_heart_beat(1);

        set_short("Ancient Dendrinar");
        set_long("This Dendrinar looks truly ancient as he stands atop the small stump of a tree remaining completely motionless.");
        set_race("Dendrinar");
        set_gender("male");
        set_body_type("human");
        set_level(75);
        set_alignment(1500);
        set_swarm(1);
        set_class("clergy");
        set_subclass("cleric");
        set_skill("belief", 450);
        set_skill("healing", 450);
        set_skill("magic attack", 300);
        set_spell_chance(100);
        set_spells(({"cure me", "lifetap", "lifetap", "lifetap"}));
        command("sit");
}

void die() {
   KEEPARMOUR"/zforest/kratoan/checkkill"->do_kill_check(this_object()->query_current_attacker());
   ::die(1);
}

void init() {
   ::init();
   if(this_player()->query_property("killermark") == 1) {
     command("stand");
     command("paralyze "+this_player()->query_name());
     command("shield me");
     this_object()->kill_ob(this_player());
   }
   else {
   add_action("sayin", "say");
   add_action("lookin", "look");
   }
}

int lookin(string str) {
    if(str == "dendrinar" || str == "monster" || str == "ancient dendrinar") {
      command("look "+this_player()->query_name());
      if(present("knowmark", this_player())) return 0;
      command("say I have a riddle for you. A man gives me to a woman: a bottomless hole to fill with flesh, blood and bone. What am I?");
      write("\n");
      return 0;
      }
    return 0;
}

int sayin(string str) {
    if(strsrch(str, "ring") == -1) return 0;
    if(present("knowmark", this_player()) || present("lyfralace", this_player())|| member_array("kratoan", this_player()->query_quests()) != -1 ) return 0;
    command("say Well done my friend. Here, a gift for you.");
    message("info", "\nYou feel blessed in some way.", this_player(), );
    message("info", this_player()->query_cap_name()+" puts on a smug look.", environment(this_player()), this_player());
    new(KEEPARMOUR"zforest/kratoan/knowmark.c")->move(this_player());
    return 1;
}
