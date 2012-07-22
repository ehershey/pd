#include <std.h>
#include <aziraphale.h>
inherit MONSTER;

void create() {
   ::create();
        set_name("Kra'toan villager");
        set_id( ({"monster", "villager", "kra'toan"}) );
        set_heart_beat(1);

        set_short("a Villager");
        set_long("The Kra'Toan people live in harmony with nature, and lead a peaceful life. Though they almost never will attack someone, they have great skills and will defend themselves if necessary. All Kra'thoans are trained for combat.");
        set_race("Kra'toan");
        if(random(2)==1)
          set_gender("male");
        else
          set_gender("female");
        set_body_type("human");
        set_level(55);
        set_alignment(1100);
        set_swarm(1);
        new(KEEPARMOUR"zforest/kratoan/tunic.c")->move(this_object());
        command("wear tunic");
}

void die() {
   KEEPARMOUR"/zforest/kratoan/checkkill"->do_kill_check(this_object()->query_current_attacker());
   ::die(1);
}

void init() {
   ::init();
   if(this_player()->query_property("killersmark") == 1)
     this_object()->kill_ob(this_player());
}

