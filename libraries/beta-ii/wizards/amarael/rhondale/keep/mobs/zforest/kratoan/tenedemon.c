#include <std.h>
#include <aziraphale.h>
inherit MONSTER;

void create() {
   ::create();
        set_name("shadow");
        set_id( ({"monster", "demon"}) );
        set_heart_beat(1);

        set_short("%^BOLD%^BLACK%^Shadow Demon%^RESET%^");
        set_long("A demon of the shadow. It has been trapped within this room for decades and thirsts for blood.");
        set_race("demon");
        set_gender("male");
        set_body_type("demon");
        set_level(75);
        set_alignment(-1500);
        set_swarm(1);
        set_class("fighter");
        set_subclass("antipaladin");
        set_skill("melee", 375);
        set_skill("attack", 375);
        set_skill("faith", 300);
        set_spell_chance(100);
        set_spells(({"massacre"}));
}

void init() {
     object tp, ob;
   ::init();
     tp = this_player();
     ob = present("worthmark", tp);
     if(ob || member_array("kratoan", tp->query_quests()) != -1) { this_object()->move("/d/nopk/standard/void"); call_out("die", 1); }
     ob = present("sunstone", tp);
     if(ob) call_out("questit", 1, ob, tp);
     else
     command("stun "+tp->query_name());
}

void questit(object ob, object tp) {
     if(!present(tp)) return;
     ob->remove();
     message("info", "\nThe %^YELLOW%^sunstone%^RESET%^ flies out of your pocket and strikes the %^BOLD%^BLACK%^shadow demon %^RESET%^between the eyes, melting into the flesh!\n%^BOLD%^RED%^The demon screams in pain as a burning light envelops it.%^RESET%^", tp, );
     message("info", "A small stone flies from "+tp->query_cap_name()+"'s pocket striking the %^BOLD%^BLACK%^shadow demon %^RESET%^between the eyes, melting into the flesh!\n%^BOLD%^RED%^The demon screams in pain as a burning light envelops it.%^RESET%^", environment(this_object()), ({ this_object(), this_player() }) );
     message("info", "All that is left of the demon is a small ring, which "+tp->query_cap_name()+" quickly picks up.", environment(this_object()), tp );
     message("info", "All that is left of the demon is a small ring, which you quickly pick up.", tp, );
     new(KEEPARMOUR"zforest/kratoan/worthmark.c")->move(tp);
     this_object()->move("/d/nopk/standard/void");
     call_out("die", 1);
}

void die() {
   ::die(1);
}
