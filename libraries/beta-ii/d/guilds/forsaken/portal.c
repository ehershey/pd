#include <std.h>

inherit OBJECT;

void init()
{
    ::init();
    add_action("cmd_portal", "portal");
}

void create() {
    ::create();
    set_id(({"portal", "flaming portal"}));
    set_name("flaming portal");
    set_long("This is the transport portal of the %^BOLD%^%^BLUE%^For%^RESET%^%^WHITE%^sa%^BOLD%^%^BLUE%^ken%^RESET%^. It is used to travel great distances by means of incredible magics accesible by only that of the %^BOLD%^%^BLUE%^For%^RESET%^%^WHITE%^sa%^BOLD%^%^BLUE%^ken%^RESET%^. The portal's %^YELLOW%^fl%^RED%^am%^YELLOW%^es%^RESET%^ leap and dance inside the great circle, forming mysterious shapes and pictures of faraway lands..\n\nJust: portal to <tirun>\n                <helgrath>\n		<rhondale>\n                <purgatory>\n		");
    set_short("A %^BOLD%^%^RED%^Fl%^YELLOW%^ami%^RED%^ng%^RESET%^ portal");
    set_prevent_get("Don't be stupid n00b");
}

int cmd_portal(string str)
{
    if(str=="to tirun")
    {
	write("You enter the portal and appear in a new location.\n");
	say((string)this_player()->query_cap_name()+ 
	  " enters the portal and disappears.\n");
	this_player()->move_player("/d/guilds/forsaken/mainportal");
	return 1;
    }

    if(str=="to rhondale")
    {
	write("You enter the portal and appear in a new location.\n");
	say((string)this_player()->query_cap_name()+ 
	  " enters the portal and disappears.\n");
	this_player()->move_player("/d/guilds/forsaken/rhonportal");
	return 1;
    }

    if(str=="to purgatory")
    {
	write("You enter the portal and appear in a new location.\n");
	say((string)this_player()->query_cap_name()+ 
	  " enters the portal and disappears.\n");
	this_player()->move_player("/d/guilds/forsaken/purgportal.c");
	return 1;
    }
    if(str=="to helgrath")
    {
	write("You enter the portal and appear in a new location.\n");
	say((string)this_player()->query_cap_name()+
	  " enters the portal and disappears.\n");
	this_player()->move_player("/d/guilds/forsaken/helportal.c");
	return 1;
    }
}
