#include <std.h>
inherit WEAPON;

object atk;
object pyr;
object room;

void create() {
    ::create();
    set_id(({"sword", "drow sword", "dark elven sword", "blade", "dark elven blade", "drow blade"}));
    set_name("blade");
    set_short("Dark Elven Blade");
    set_long("This keenly edged blade represents the typical Drow fighting weapon. Long and thin, but slightly curved, it is an elegant but vicious weapon perfected after thousands of years of brutal use. The hilt of this weapon is shaped into the form of an elongated spider, it's eight legs tucked up against it's body, forming the guard. The blade is sharp on both sides, although only the leading edge of the blade is generally used for slicing, the blade's already considerable sharpness and strength are augmented by an array of magical aids placed upon the weapon to perfect it's killing power.");
    set_mass(9);
    set_value(240);
    set_wc(14);
    set_type("blade");
    set_hands(1);
    set_unwield((:this_object(),"unwield":));
    set_wield((:this_object(),"wield":));
    set_hit((:this_object(),"weapon_hit":));
    set_heart_beat(1);

}

int wield() {

    pyr = (object)this_player();
    atk = (object)this_player()->query_current_attacker();
    room = environment(environment(this_object()));

    if (this_player()->query_race() != "drow" && this_player()->query_race() != "vampire"){

	write("The sword crumbles to dust in your hands.");
	this_object()->move("/d/nopk/standard/void.c");
	message("say", this_player()->query_cap_name()+" attempts to wield a Dark Elven blade but it crumbles to dist in "+this_player()->query_possessive()+" hands.", room, this_player());
	return 1;
    }

    else {
	write("The spider hilt of the weapon comes to life, the eight legs kicking and squirming with glee as you grasp hold of the hilt.");
	message("say", this_player()->query_cap_name()+" draws a Dark Elven Blade.", room, this_player());

	return 1;
    }
}

int unwield() {

    pyr = (object)this_player();
    atk = (object)this_player()->query_current_attacker();
    room = environment(pyr);

    write("The spider on the hilt of the weapon seems to calm down finally as you release the weapon.");
    message("say", this_player()->query_cap_name()+" releases a Dark Elven Blade from "+this_player()->query_possessive()+" hand.", room, this_player());

    return 1;
}

int weapon_hit()
{

    int result;
    int parachance;
    int sm;

    pyr = this_player();
    atk = this_player()->query_current_attacker();
    room = environment(pyr);

    parachance = 15;
    sm = 1;

    if(random(100)+1 < 25) 
    {
	write("The blade gleams as it bites into living flesh.");
	message("say", this_player()->query_name()+"'s blade gleams as it bites into living flesh.", room, atk);
	message("say", this_player()->query_name()+"'s blade gleams as it bites into your flesh.", atk);

	if(atk->query_race() == "elf")
	{ 
	    write("%^BOLD%^%^YELLOW%^The spider on the hilt of your blade screams as it bites into the flesh of an elf.%^RESET%^");
	    message("say", "%^BOLD%^%^YELLOw%^An unearthly scream of rage echos from "+this_player()->query_cap_name()+"'s blade.", room);
	    sm = 4;
	}

	result=(pyr->query_skill("attack")+1)+pyr->query_stat("strength")+(pyr->query_stat("dexterity")+1)*sm;
	result=random(result)+random(result);
	return result;
    }
}


mixed query_auto_load() {
    if(this_player()->query_race() == "drow")
	return ({base_name(this_object()), ({})});
}
