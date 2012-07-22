#include <std.h>
inherit MONSTER;
create(){
    ::create();
    set_name("Troll");
    set_short("Troll");
    set_id(({"monster","Troll"}));
    set_long("a giant troll");
    set_gender("neuter");
    set_race("troll");
    add_limb("head","FATAL",100,0,15);
    add_limb("torso","FATAL",150,0,15);
    add_limb("left arm","left claw",20,0,15);
    add_limb("right arm","right claw",20,0,15);
    add_limb("right claw","",20,0,15);
    add_limb("left claw","",20,0,15);
    add_limb("left foot","",20,0,15);
    add_limb("right foot","",20,0,15);
    add_limb("right leg","right foot",20,0,15);
    add_limb("left leg","left foot",20,0,15);
    set_level(9);
    set_skill("melee",80);
}
int remove_limb(string limb){
    if((limb!="torso")||(limb!="head")){
	say("A new Troll grows rapidly from the severed limb!\n");
	new("/d/helgrath/mobs/troll.c")->move(environment(this_object()));
	return ::remove_limb();
    }
    else {
	return ::remove_limb();
    }
}
