// venenum

#include <std.h>
inherit MONSTER;

int killable=0;

void create() {
    ::create();
    set_name("sasayaki");
    set_short("Ronin Sasayaki walks a warrior's pilgrimage.");
    set_id(({"sasayaki"}));
    set_level(60);
    set_class("fighter");
    set_subclass("antipaladin");
    set_race("demon");
    set_body_type("demon");
    set_gender("male");
    set_long("Sasayaki The Slayer. %^BOLD%^%^RED%^Seth. Scoff. Scamp. Autema. Agent. Byblos.%^RESET%^");
    set_die( (: call_other, this_object(), "death_func":) );
    set_max_hp(this_object()->query_max_hp()*50);
    set_hp(this_object()->query_max_hp());

}

int is_invincible() {

    if(killable == 0){
	message("say", this_player()->query_cap_name()+" attempts to attack Sasayaki, but is stopped by a black light from the spirit of Asmodeus.", environment(this_object()), this_player());
	message("say", "A black light shines out from Asmodeus, stopping you.", this_player());
	return 1; 
    }
    else{return 0;}
}

int set_killable(){ 
    killable = 1;
    return 1;
}

int death_func() {

    message("say", "%^BOLD%^%^CYAN%^Sasayaki stumbles back, blood spraying out from numberous wounds, the nether-blessed ichor bursting into flame as it touches air. He slumps to one knee, gasping and panting. His concentration broken, Asmodeus looks up from his trance, glaring around.%^RESET%^", environment(this_object()), this_player());
    new("/wizards/venenum/minievent/sasadeath.c")->move(environment(this_object()));
    present("sasayakis body", environment(this_object()))->death_scene();
    this_object()->move("/d/nopk/standard/void.c");
    return 1;
}
