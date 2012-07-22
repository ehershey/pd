#include <std.h>
#include <guild.h>
#include "ether.h"
inherit ETHERSTD;
void create() {
        ::create();

        set_short("%^RESET%^%^CYAN%^Ethereal Scrying Room%^RESET%^");
        set_long(
                "%^RESET%^%^CYAN%^Ethereal Scrying Room%^RESET%^\n"
                "%^BOLD%^%^WHITE%^A faint mist dances about the white marble floor. Luminous light floods into "
                "the room from an obscure source. Tiny orbs of light playfully shroud a large stone altar. Upon "
                "the altar is a tattered map of the realm of PD, and a beautiful scrying crystal.%^RESET%^"
        );
        set_exits( ([
                "north" : ROOMS "1-1.c",
        ]) );


        set_items( ([
                "mist" : "A faint mist.",
                "floor" : "%^BOLD%^%^WHITE%^A beautiful white marble floor.%^RESET%^",
                "light" : "%^BOLD%^%^WHITE%^Bright light that fills the room with a holy glow.%^RESET%^",
                "orbs" : "%^RESET%^%^CYAN%^Tiny orbs of light which surround a large stone altar.%^RESET%^",
                "altar" : "%^BOLD%^%^WHITE%^A large altar made from white stone. It is used by the Ethereal as a scrying table.%^RESET%^",
                "map" : "%^RESET%^%^ORANGE%^A tattered map of the realm of PD.%^RESET%^",
                "crystal" : "%^RESET%^%^CYAN%^A beautiful crystal with a sharp point, and is held by a silver claw and chain. It is a scrying tool of the Ethereal.%^RESET%^"
        ]) );

        set_smell("default", "The scent of aromatic blossoms intertwine with stench of blood.");
        set_listen("default", "Faint gaelic chanting drifts into the room from the marble halls.");
}
void init() {
    ::init();
add_action("cmd_scry", "scry");
}
int cmd_scry(string str) {
    mixed strr;
    object env;
    if(!str) return notify_fail("Scry whom?\n");
    if(!find_player(str)) return notify_fail("No such person in this reality.\n");
    strr = find_player(str);
    env = environment(strr);
    write("%^BOLD%^You place your hands upon the crystal, and mutter the name: "+capitalize(str)+"\n");
    say("%^BOLD%^"+this_player()->query_cap_name()+
        " places his hands upon the crystal and mutters the name "+capitalize(str)+"\n");
    if(env->query_property("no scry")) {
        write("%^BOLD%^The image in the crystal is too faint to make out.\n");
        say("%^BOLD%^The image in the crystal is too faint to make out.\n");
        return 1;
    }

    if(wizardp(strr)) { 
        write("%^BOLD%^"+capitalize(str)+" is too powerful a being to be located in this way.\n");
        say("%^BOLD%^"+capitalize(str)+" is too powerful a being to be located in this way.\n");
        return 1;
    }
    write("The mist surrounding the crystal clears, revealing "+capitalize(str)+"'s  location.. \n\n"
        "%^BOLD%^%^BLUE%^\<crystal\:%^RESET%^"+capitalize(str)+"%^BOLD%^%^BLUE%^\>%^RESET%^\n"+env->query_short()+"\n");
    say("The mist surrounding the crystal clears, revealing "+capitalize(str)+"'s  location.. \n\n"
        "%^BOLD%^%^BLUE%^\<crystal\:%^RESET%^"+capitalize(str)+"%^BOLD%^%^BLUE%^\>%^RESET%^\n"+env->query_short()+"\n");
    write(""+env->query_long()+"\n%^BOLD%^%^BLUE%^\<\/crystal\:%^RESET%^"+capitalize(str)+"%^BOLD%^%^BLUE%^\>\n");
    say(""+env->query_long()+"\n%^BOLD%^%^BLUE%^\<\/crystal\:%^RESET%^"+capitalize(str)+"%^BOLD%^%^BLUE%^\>\n");
    return 1;
}
