//  Created by Whit

#include <std.h>
#include <citrin.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("walking dead");
    set_long("The corpse is rotting where is stands.");
    set_short("a walking dead");
    set_id( ({"corpse","walking dead", "dead"}) );
    set_race("walking dead");
    set_body_type("human");
    set_undead(1);
    if(random(2))
	set_level(60);
    else set_level(70);
    if(random(2))
	set_gender("male");
    else set_gender("female");
     if(random(100) > 97) {
       new("/wizards/daboura/ruby_red_belt.c")->move(this_object());
       command("wear belt");
     }
}


