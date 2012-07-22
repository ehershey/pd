#include <discastle.h>
inherit OBJECT;
void init()
{
	::init();
	add_action("sac","search");
}
void create() 
{
	::create();
    set_name("moosehead");
    set_short("Moose Head");
    set_long("Hey.. what's that in side of the moose head? Maybe you should take a closer look?");
    set_prevent_get
    (
		"Aime� wouldn't like that"
    );
    set_id(({"head", "moose head", "moose"}));
}
int sac(string str)
{
	if (!str)
	{
		write("What?");
		return 1;
	}
	if (str == "head" || str == "moose head" || str == "moose")
	{
		write("You jump into the air and yelp as the Moose Head comes alive and snaps at you!\n");
		this_player()->force_me("shout AGH! IT'S ALIVE AND TRYING TO EAT ME!");
		write("\nNo wait, it was just your imagination... Don't you feel red in the face?");
	}
	return 1;
}
