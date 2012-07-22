#include <std.h>
#include <aziraphale.h>
inherit MONSTER;

void create() {
   ::create();
        set_name("Lyfra");
        set_id( ({"monster", "guard", "dendrinar", "lyfra"}) );
        set_heart_beat(1);

        set_short("Ancient Winged Dendrinar");
        set_long("This ancient dendrinar doesn't look just merely human, but has giant leaf wings. Not another Dendrinar within the village, nor any in the legends, had ever been in this amazing form before you. What this means must remain a mystery for now, as there are more pressing matters at hand.");
        set_race("Dendrinar");
        set_gender("male");
        set_body_type("human");
        set_level(85);
        set_alignment(1500);
        set_swarm(1);
        set_class("fighter");
        set_subclass("paladin");
        set_skill("blade", 425);
        set_skill("attack", 425);
        set_skill("faith", 600);
        set_skill("healing", 800);
        set_skill("magic attack", 600);
        set_spell_chance(40);
        set_spells(({"dispell", "cripple", "cure me", "cure me"}));
        new(KEEPARMOUR"zforest/kratoan/lyfralace.c")->move(this_object());
        command("wear amulet");
}

void die() {
   KEEPARMOUR"/zforest/kratoan/checkkill"->do_kill_check(this_object()->query_current_attacker());
   ::die(1);
}

void init() {
     object tp;
   ::init();
   if(!this_player()->is_player())
   {
   return;
   }
   if(!this_player() || this_player() == this_object()) return;
   if(this_player()->query_property("killersmark") == 1) {
     call_out("do_say", 1);
     this_object()->kill_ob(this_player());
     }
   else {
     tp = this_player();
     if(!tp->is_player()) return;
     if(member_array("kratoan", tp->query_quests()) != -1 || present("lyfralace", tp))
       return;
     else {
       if((present("knowmark", this_player()) && !present("powermark", this_player()) || (present("powermark", this_player()) && !present("knowmark", this_player()))))
         call_out("do_say2", 1, tp);
       if(present("knowmark", this_player()) && present("powermark", this_player()) && !present("lyfralace", this_object()))
         call_out("do_say3", 1, tp);
       if(present("knowmark", this_player()) && present("powermark", this_player()) && present("lyfralace", this_object()))
         call_out("do_say4", 1, tp);
       }
     }
}

void do_say() {
     command("say I regret that it has come to this.");
}

void do_say2(object tp) {
     command("look "+tp->query_name());
     command("say Greetings, I must say you have done quite well to have proven your worth, let alone solve such a difficult riddle. Solve the other and I shall reward your efforts");
}

void do_say3(object tp) {
     command("look "+tp->query_name());
     command("say Ah, welcome. I must congratulate you on proving your worth and solving our riddles. Unfortuantely I have nothing to give you, another time perhaps.");
}

void do_say4(object tp) {
     command("look "+tp->query_name());
     command("say Welcome my friend, I must congratulate you on not only proving your worth but also solving our riddles. Here, let me present you with this gift.");
     present("lyfralace", this_object())->move(this_player());
     message("info", "Lyfra hands you his leaf amulet.", tp, );
     message("info", "Lyfra hands "+tp->query_cap_name()+" a leaf amulet.", environment(this_object()), tp);
     command("tell "+tp->query_name()+" Use it wisely.");
     present("knowmark", tp)->remove();
     present("powermark", tp)->remove();
}
