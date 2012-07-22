#include <std.h>
inherit ARMOUR;
void go_away(object ob) {
    tell_object(ob, "%^BOLD%^%^RED%^The halo dissolves into a searing mist, marking a burn on your head.%^RESET%^");
    ob->damage(random(25));
    if (!present("halo_burn_mark", ob))
	new("/wizards/inferno/angel/tatoo")->move(ob);
    this_object()->remove();
    return;
}
string check_wear() {
    if (this_player()->query_race() == "archangel") message("info", "%^BOLD%^%^YELLOW%^"
	  "The halo floats just above your head.", this_player());
    else {
	call_out("go_away", 2, this_player());
	message("info", "%^BOLD%^%^RED%^The halo rests atop your head, searing and "
	  "burning your forehead.", this_player());
    }
    return "";
}
int spin(string str) {
    if (str != "halo") return notify_fail("Spin what?\n");
    if (!present("halo", this_player())) return 0;
    if(environment(this_player())->query_property("no teleport"))
	return notify_fail("You may not spin your halo here!\n");
    if (!query_worn()) return 0;
    if (this_player()->query_alignment() < 750) {
	notify_fail("You have betrayed your alignment.");
	return 0;
    }
    if (this_player()->query_sp() < 0) {
	notify_fail("You are too tired.\n");
	return 0;
    }
    if(this_player()->query_current_attacker()) return notify_fail("You cannot do that in battle!\n");
    if(this_player()->query_disable()) return notify_fail("You are too busy to spin your halo.\n");
    this_player()->set_disable();
    if (this_player()->query_race()!=("archangel")){
	notify_fail("%^BOLD%^%^RED%^You are not an %^CYAN%^angel%^RED%^!%^RESET%^");
	return 0;
    }
    else 
	say(this_player()->query_cap_name()+" spins "
	  +this_player()->query_title_gender()+" halo and watches it whiz around "
	  +this_player()->query_title_gender()+" head.", this_player());
    write("%^BOLD%^%^WHITE%^You spin your halo and watch it whiz around your head.%^RESET%^");
    this_player()->move_player("/wizards/inferno/angel/main.c");
    this_player()->set_paralyzed(2, "You are busy.");
    return 1;
}
void init() {
    ::init();
    add_action("spin", "spin");
}
void create() {
    ::create();
    set_name("halo");
    set_short("%^RESET%^%^ORANGE%^a%^BOLD%^%^ORANGE%^ go%^WHITE%^ld%^RESET%^%^WHITE%^en%^BOLD%^%^WHITE%^ h%^YELLOW%^al%^RESET%^%^ORANGE%^o%^RESET%^");
    set_long("The golden halo of the angels is a holy relic symbolizing eternal "
      "peace and the power of good. Archangels, angels, and cherrubs all wear "
      "this symbol of their faith to the higher powers of good. The halo is a "
      "thin golden circlet that mystically floats above your head. A glowing aura "
      "of peace and protection radiates from the halo.");
    set_weight(0);
    set_value(0);
    set_property("no steal", 1);
    set_id(({ "halo", "golden halo", "circlet", "symbol" }));
    set_type("halo");
    set_ac(1);
    set_limbs(({ "head" }));
    set_wear( (: check_wear() :) );
}
int query_auto_load() {
    if (this_player()->query_race()!=("archangel")) return 0;
    return 1;
}
