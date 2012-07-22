// Sakura

#include <std.h>
inherit MONSTER;

string revealed = "no";

void create() {
    ::create();
    set_name("dragon");
    set_short("%^BOLD%^%^WHITE%^A mature red dragon");
    set_id(({"dragon", "red dragon", "mature red dragon"}));
    set_level(25);
    set_class("dragon");
    set_subclass("red");
    set_race("dragon");
    set_body_type("dragon");
    set_gender("male");
    set_long("This young dragon's elegence and perfection is clear to behold. His back, tail and flanks are covered in tiny interlocking scales the size of a human's fist and shining with the signiture deep crimson sheen which gives name to his race. His belly and underside bear much larger scales forming an armoured coalescence underneath him. A line of spines run from the back of his head down his neck, a thin flap of skin stretched between each forming a fin. His wings are thick leather between thin bone arcs, providing a medium for flight. His tail thins early, ending in a whiplike tip. His face is protected by large spikes, with two rearward facing horns growing out of the left and right of the back of his head, curling upwards slightly before ending in an infinately sharp point. Each of his legs is coated in more scales, larger then the ones on his back but smaller then the ones on his underside.");

}

int is_invincible() {

    if (revealed = "yes"){

	message("say", this_player()->query_cap_name()+" attempts to attack the dragon, but is stopped by a black light from Asmodeus.", environment(this_object()), this_player());
	message("say", "A black light shines out from Asmodeus, stopping you.", this_player());
	return 1; 
    }
    else {
	message("say", this_player()->query_cap_name()+" attempts to attack Venenum, but is stopped by a black light from Asmodeus.", environment(this_object()), this_player());
	message("say", "A black light shines out from Asmodeus, stopping you.", this_player());
	return 1; 
    }
}

int reveal() {
    revealed = "yes";
    set_name("venenum");
    set_short("%^BOLD%^%^CYAN%^Venenum The Red");
    set_id(({"venenum", "venenum the red"}));
    set_long("Venenum the Red, spawn of Quex'trilixil the Red, stands at almost thirty feet long and ten high, this young dragon's elegence and perfection is clear to behold. His back, tail and flanks are covered in tiny interlocking scales the size of a human's fist and shining with the signiture deep crimson sheen which gives name to his race. His belly and underside bear much larger scales forming an armoured coalescence underneath him. A line of spines run from the back of his head down his neck, a thin flap of skin stretched between each forming a fin. His wings are thick leather between thin bone arcs, providing a medium for flight. His tail thins early, ending in a whiplike tip. His face is protected by large spikes, with two rearward facing horns growing out of the left and right of the back of his head, curling upwards slightly before ending in an infinately sharp point. Each of his legs is coated in more scales, larger then the ones on his back but smaller then the ones on his underside.");
}

int kill(){
    new("/wizards/venenum/minievent/venenums_body.c")->move(environment(this_object()));
    this_object()->move("/d/nopk/standard/void.c");
    return 1;
}
