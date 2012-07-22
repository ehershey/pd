#include <std.h>
#include <aziraphale.h>
inherit MONSTER;

void create() {
   ::create();
        set_name("Kra'toan sentry");
        set_id( ({"monster", "sentry", "kra'toan"}) );
        set_heart_beat(1);

        set_short("a Sentry");
        set_long("This Kra'toan sentry guards the entrance to the village. The look in his eyes says he is here to keep those of any other race out of his home.");
        set_race("Kra'toan");
        set_gender("male");
        set_body_type("human");
        set_level(60);
        set_alignment(1000);
        set_swarm(1);
        set_class("fighter");
        set_subclass("warrior");
        set_skill("blunt", 220);
        set_skill("attack", 220);
        set_skill("melee", 220);
        new(KEEPWEAPON"zforest/kratoan/quarterstaff.c")->move(this_object());
        command("wield staff");
        set_spell_chance(30);
        set_spells(({"rush", "headbutt"}));
}

void die() {
   KEEPARMOUR"/zforest/kratoan/checkkill"->do_kill_check(this_object()->query_current_attacker());
   ::die(1);
}

void init() {
   ::init();
   if(this_player()->query_property("killersmark") == 1) {
     call_out("do_say", 1);
     this_object()->kill_ob(this_player());
   }
}

void do_say() {
     this_object()->force_me("say Murderer! Die for your sins!");
}
