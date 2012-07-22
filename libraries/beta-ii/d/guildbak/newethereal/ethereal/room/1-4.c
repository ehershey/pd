#include <std.h>
#include <guild.h>
#include <ether.h>
inherit ETHERSTD;

void create() {
        ::create();
        set_short("%^RESET%^%^CYAN%^Ethereal Portal Room%^RESET%^");
        set_long(
                "%^RESET%^%^CYAN%^Ethereal Portal Room%^RESET%^\n"
                "%^BOLD%^%^WHITE%^A faint mist dances about the white marble floor. Luminous "
                "light floods into the room from an obscure source. There are a number of open "
		"portals here, they glow red, with mystic swirls of purple and blue.  The three "
		"portals which can be seen are marked %^RESET%^%^CYAN%^\<Helgrath\>%^BOLD%^%^WHITE%^,"
		" %^RESET%^%^CYAN%^\<Purgatory\> %^BOLD%^%^WHITE%^and%^RESET%^%^CYAN%^ \<Rhondale\>%^BOLD%^%^WHITE%^.%^RESET%^"
        );
        set_exits( ([
                "south" : ROOMS "1-1.c",
                "helgrath" : ROOMS "p-helg.c",
                "purgatory" : ROOMS "p-purg.c",
                "rhondale" : ROOMS "p-rhon.c",
        ]) );
        set_items( ([
                "mist" : "A faint mist.",
                "floor" : "%^BOLD%^%^WHITE%^A beautiful white marble floor.%^RESET%^",
                "light" : "%^BOLD%^%^WHITE%^Bright light that fills the room with a holy glow.%^RESET%^",
                "helgrath" : "%^BOLD%^%^WHITE%^This is a portal to Helgrath.%^RESET%^",
                "purgatory" : "%^BOLD%^%^WHITE%^This is a portal to Purgatory.%^RESET%^",
                "rhondale" : "%^BOLD%^%^WHITE%^This is a portal to Rhondale.%^RESET%^"
        ]) );
        set_smell("default", "The scent of aromatic blossoms intertwine with stench of blood.");
        set_listen("default", "Faint gaelic chanting drifts into the room from the marble halls.");
        set_pre_exit_functions( ({"helgrath"}), ({"lvl_check_helg"}) );
        set_pre_exit_functions( ({"purgatory"}), ({"lvl_check_purg"}) );
        set_pre_exit_functions( ({"rhondale"}), ({"lvl_check_rhon"}) );
}

int lvl_check_helg() {
        if (this_player()->query_level() < 25) {
                write("You are too weak to go to Helgrath!\n");
                return 0;
        }
	write("%^GREEN%^The vines pull back as the silver emblem begins to open. A large portal is revealed.%^RESET%^\n");
	write("You enter the portal.\n");
        return 1;
}
int lvl_check_purg() {
        if (this_player()->query_level() < 36) {
                write("You are too weak to go to to Purgatory!\n");
                return 0;
        }
	write(
		"%^RED%^The blood on the floor begins to boil and rushes away from the gold emblem, "
		"as it rises from the ground. A portal is revealed.%^RESET%^\n"
	);
	write("You enter the portal.\n");
        return 1;
}
int lvl_check_rhon() {
        if (this_player()->query_level() < 36) {
                write("You are too weak to go to to Rhondale!\n");
                return 0;
        }
	write("%^CYAN%^The flames rise around the emblem and pull back as it opens, to reveal a portal.%^RESET%^\n");
	write("You enter the portal.\n");
        return 1;
}
