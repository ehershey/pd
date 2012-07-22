#include <std.h>
#include <aziraphale.h>
inherit MONSTER;

void create() {
   ::create();
        set_name("Dendrinar Guard");
        set_id( ({"monster", "guard", "dendrinar"}) );
        set_heart_beat(1);

        set_short("a Dendrinar Guard");
        set_long("The legendary Dendrinar, a race of trees made as though men. Instead of flesh they are made of wood with long hair of vines. They
were thought to have died out in the old wars where they fought the evil tides. Their presence in this world is a good omen for the followers of
light.");
        set_race("Dendrinar");
        set_gender("male");
        set_body_type("human");
        set_level(65);
        set_alignment(1500);
        set_swarm(1);
        set_class("fighter");
        set_subclass("paladin");
        set_skill("blade", 240);
        set_skill("attack", 220);
        set_skill("faith", 260);
        set_skill("healing", 215);
        new(KEEPWEAPON"zforest/kratoan/densword.c")->move(this_object());
        command("wield sword");
        new(KEEPWEAPON"zforest/kratoan/densword.c")->move(this_object());
        command("wield sword");
        set_spell_chance(70);
        set_spells(({"slash", "slash", "slash", "cure me"}));
}

void die() {
   KEEPARMOUR"/zforest/kratoan/checkkill"->do_kill_check(this_object()->query_current_attacker());
   ::die(1);
}

void init() {
   ::init();
   if(this_player()->query_property("killermark") == 1) {
     call_out("do_say", 1);
     this_object()->kill_ob(this_player());
   }
}

void do_say() {
     this_object()->force_me("say Betrayer! Die for your sins!");
}
