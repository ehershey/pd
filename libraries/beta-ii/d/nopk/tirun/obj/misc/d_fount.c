#include <std.h>
inherit OBJECT;
void create() {
    ::create();
    set_id(({ "fountain" }));
    set_name("fountain");
    set_long("The workmanship of the fountain is magnificent, in fact "
      "the finest you've seen in your life! Atop the fountain "
      "is a statue is of a mighty dragon, symbolizing Tirun's "
      "strength in battle. Water runs from the dragon's mouth "
      "into a pool at the dragons feet. A gold plaque has been "
      "mounted at the base of the fountain.");
    set_short("a fountain");
    set_weight(50);
    set("value", 0);
    set_prevent_get( "The fountain will not budge." );
}
int readPlaque(string what) {
    if (!what || what != "plaque") return 0;
    tell_room(environment(this_player()), this_player()->query_cap_name()+
      " reads over the plaque on the fountain.", ({ this_player()}));
    write("%^BOLD%^%^CYAN%^The gold plaque reads: %^RESET%^");
    write("%^YELLOW%^Reality has begun to wind itself and life has "
      "begun to spill forth upon this world. The gods "
      "whom sit on high would like to give thanks to thine, "
      "whom has helped in creating this, our world.");
    write("%^YELLOW%^Several names have been inscribed beneath the inscription:%^RESET%^");
    write("%^YELLOW%^Great thanks goes out to all whom hast helped, but especially to:\n");
    write(@ENDTEXT
Seeker                 Inferno             Stormbringer 
Detach                 Wiz                 Nightshade
Asmodeus               Slinker             Leviathas
Suluial                Daos                Wraith
ENDTEXT);
    return 1;
}
int goDrink(string str) {
    if (str != "fount" && str != "fountain" && str != "from fount" && str != "from fountain") {
	notify_fail("Drink from what?\n");
	return 0;
    }
    if (this_player()->query_disable())
    {
	write("You cannot drink that fast.");
	return 1;
    }
    if (!this_player()->add_quenched(15)) {
      write("You are too full to drink right now.\n");
      return 1;
    }
    this_player()->set_disable();
    this_player()->heal(10);
    write("%^BOLD%^%^BLUE%^The water refreshes you.%^RESET%^");
    return 1;
}
void init() {
    ::init();
    add_action("readPlaque", "read");
    add_action("goDrink", "drink");
}
string affect_environment() { return " A magnificent fountain of a dragon dominates the center of the park."; }
