#include <std.h>
inherit ARMOUR;

string extralook =  "%^BOLD%^%^BLACK%^Small swarms of spiders crawl over "+this_player()->query_possessive()+" flesh.%^RESET%^";
string extra_look();

int do_wear()
{

    if (this_player()->query_race() == "drow" || this_player()->query_race() == "vampire")
    {
	write("You proudly don the dark armour of your people.");
	message("say", this_player()->query_cap_name()+" dons a suit of Dark Elvenchain.", environment(this_player()), this_player()); 
	return 1;
    }
    else
    {
	write("The chainmail disintergrates into thousands of tiny spiders which scurry away from your clutches.");
	message("say", this_player()->query_cap_name()+" attempts to wear a suit of dark elvenmail, but it simply disintergrates in "+this_player()->query_possessive()+" hands.", environment(this_player()), this_player());
	this_object()->move("/d/nopk/standard/void.c");
	return 0;
    }

}

void create() {
    ::create();
    set_name("elvenchain");
    set("id", ({"dark elvenchain", "elvenchain", "chainmail", "chain"}) );
    set_short("Dark Elvenchain");
    set_long("This work of art is an incredibly tiny weave of chain mesh, blackened with ashes to help camoflague it. The delicate, almost beautiful chain flows over his upper arms and thighs, providing incredible protection for armour of it's type. The considerable defense the armour provides has been strengthened by magical means.");
    set_type("chainmail");
    set_limbs( ({"right leg", "left leg", "right arm", "left arm", "torso"}) );
    set_mass(24);
    set_value(120);
    set_ac(14);
    set_wear((: do_wear :));
}

int query_auto_load() {
    if(this_player()->query_race() == "drow")
	return 1;
}

string extra_look() {return extralook+"\n";}
