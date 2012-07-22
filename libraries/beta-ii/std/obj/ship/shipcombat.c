//  Ship Combat Simulator
//    Whit
#include <daemons.h>
#define FIRE_SYNTAX "Syntax: <fire cannons at [player]>\n"
#define BASE_DMG 5
static object *in_combat;
static object current;
void init() {
    add_action("fire_cannons", "fire");
    add_action("hail_ship", "hail");
    add_action("board_ship", "board");
}
int fire_cannons(string s) {
    string to;
    object o;
    if(!OCEAN_D->ship_combat_on()) return 0;
    if(!s) return notify_fail(FIRE_SYNTAX);
    if(this_player()->query_name() != this_object()->query_owner()) return
	notify_fail("You may not fire this ships cannons.\n");
    if(sscanf(s, "cannons at %s", to) != 1) return notify_fail(FIRE_SYNTAX);
    if(!in_combat) in_combat=({});
    if(!this_object()->query_cannons()) return notify_fail("You must "
	  "have cannons in order to fire upon someone.\n");
    if(current) return notify_fail("You have to wait for your cannons to hit.\n");
    if(!o=OCEAN_D->ship_present(this_object()->query_xy(), to)) 
	return notify_fail("You do not see that ship here.\n");
    if(!find_player(o->query_owner())) return 
	notify_fail("You may not fire apon an unmanned ship.\n");
    if(!present(find_player(to), o)) return 
	notify_fail("You may not fire apon an unmanned ship.\n");
    if(o->query_docked()) return 
	notify_fail("You may not fire upon a docked ship.\n");
    if(member_array(o, in_combat)==-1) {
	message("ship-combat", 
	  this_object()->query_owner()+"'s ship begins attacking your ship!\n", o);
	in_combat += ({o});
    }
    write("You point your cannons to "+capitalize(o->query_owner())+"'s ship.\n");
    say(this_player()->query_cap_name()+" points the ships cannons to "+
      capitalize(o->query_owner())+"'s ship.\n");
    current=o;
    call_out("hit", random(2)+1);
    return 1;   
}
void hit() {
    object o;
    int amt;
    o=copy(current);
    current=0;
    message("", o->query_owner()+" blah ", this_object());
    if(!OCEAN_D->ship_present(this_object()->query_xy(), o->query_owner())) return;
    amt=this_object()->query_cannons()*BASE_DMG;
    amt=(amt/o->query_armour())+random(3);
    if(!o->query_cannons()) amt=amt/2;
    if(amt<1) {
	message("ship-combat", "The cannons do no damage to "+o->query_owner()+
	  "'s ship.\n", this_object());
	message("ship-combat", capitalize(this_object()->query_owner())+
	  "'s ship misses it's attack on you.", o);
    } else {
	message("ship-combat", "Your cannons hit doing damage to "+
	  capitalize(o->query_owner())+"'s ship.\b", this_object());
	message("ship-combat", capitalize(this_object()->query_owner())+
	  " hits your ship causing damage.\n", o);
    }
    if(this_object()->query_owner() == "whit") message("ship-combat", 
	  "Damage Dealt: "+amt, this_object());
    if(amt >0)
	o->add_hp(amt);
    current=0;
    return;
}
void sink() {
    object *ships, *all;
    int i;
    message("ship-combat", "The ship begins to sink into the ocean.",
      this_object());
    ships=OCEAN_D->get_present_ships(this_object()->query_xy());
    ships -= ({this_object()});
    if(sizeof(ships))
	message("ship-combat", capitalize(this_object()->query_owner())+
	  "'s ship sinks into the sea.\n", ships);
    all=all_inventory(this_object());
    i=sizeof(all);
    while(i--) {
	if(all[i]->is_living()) { 
	    message("", "Whooosh!  You are thrown into the ocean.  "
	      "You find some of the debris from your ship and cling "
	      "on for dear life.", all[i]);
	    all[i]->move(new("/std/obj/shipdebris"));
	    all[i]->describe_current_room();
	}
    }
    all=all_inventory(this_object());
    i=sizeof(all);
    while(i--) all[i]->remove();
    this_object()->set_sunk(this_object()->query_xy());
}
int hail_ship(string s) {
    string to, msg;
    object o;
    if(!s || s=="") return notify_fail("Syntax: <hail [ship] [msg]>\n");
    if(sscanf(s, "%s %s", to, msg) != 2) return 
	notify_fail("Syntax: <hail [ship] [msg]>\n");
    if(!o=OCEAN_D->ship_present(this_object()->query_xy(), to)) 
	return notify_fail("You do not see that ship here.\n");
    if(o->query_sunk()) return notify_fail("You cannot hail a sunken ship.\n");
    message("ship-hail", "%^BOLD%^%^RED%^You hail "+
      capitalize(o->query_owner())+"'s ship: %^RESET%^"+msg, this_player());
    message("ship-hail", "%^BOLD%^%^RED%^"+this_player()->query_cap_name()+" hails "+
      capitalize(o->query_owner())+"'s ship: %^RESET%^"+msg, this_object(), ({this_player()}));
    message("ship-hail", "%^BOLD%^%^RED%^"+this_player()->query_cap_name()+" hails "+
      "your ship: %^RESET%^"+msg, o);
    return 1;
}
int board_ship(string s) {
    object o;
    if(!s || s=="") return notify_fail("Syntax: <board [ship]>\n");
    if(!o=OCEAN_D->ship_present(this_object()->query_xy(), s)) 
	return notify_fail("You do not see that ship here.\n");
    if(o->query_sunk()) return notify_fail("You may not board a sunken ship.\n");
    write("You attempt to board "+capitalize(o->query_owner())+"'s ship.\n");
    message("", "You are being boarded by "+this_player()->query_cap_name()+
      "!\n", o);
    if(o->is_static_ship()) 
      this_player()->move_player(o->query_start_room(), "off the ship"); else
    this_player()->move_player(o, "off the ship");
    return 1;
}
