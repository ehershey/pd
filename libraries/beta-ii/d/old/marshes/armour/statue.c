#include <std.h> 
#include <amun.h>
inherit OBJECT;
void create() {
    ::create();
    set_name("Inferi Statue");
    set("id", ({"inferi", "statue", "inferi statue"}) );
    set_short("%^BOLD%^%^BLACK%^Inferi Statue");
    set_long("%^BOLD%^%^BLACK%^This statue was made by those who claimed this land. There is an Inferi Elf mounted upon an Inferi Centaur.  You notice that the marble statue is beginning to erode from time.");
    set_prevent_get("Your buffness is overcome by the might of gravity!");
}