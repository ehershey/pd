
#include <std.h>

inherit WEAPON;
inherit CONTAINER;


int my_level;
string *my_rune_slots=({ "rune_1","rune_2","rune_3","rune_4" });
mapping my_runes;

create () {
    ::create();
    if(!my_runes) my_runes= ([ ]);
}

///////////////////////////////////////////////////////

string set_rune(string what_rune,object targ_rune) {
    string rune_file=base_name(targ_rune)+".c";
    string rune_name=targ_rune->query_name();

    if(!targ_rune->is_rune()) return "The object that you wish to combine with this weapon is not a rune. Nice Try.\n";
    if(!file_exists(rune_file)) error("invalid file to set_rune, file does not exist");

    if(!my_runes) my_runes= ([ ]);
    if(!member_array(what_rune, my_rune_slots)) return "This weapon does not have a rune placement called "+what_rune+" in it.";

    switch( what_rune ) {
    case "rune_1" :
	if(my_level < 10) return "You lack the experiance with the weapon to install the first rune.";
	my_runes["rune_1"]["filename"]=rune_file;
	my_runes["rune_1"]["rune"]=rune_name;
	break;
    case "rune_2" :
	if(my_level < 20) return "You lack the experiance with this weapon to install a rune in the second slot.";
	my_runes["rune_2"]["filename"]=rune_file;
	my_runes["rune_2"]["rune"]=rune_name;
	break;
    case "rune_3" :
	if(my_level < 30) return "You lack the experiance with this weapon to install a rune in the third slot.";
	my_runes["rune_3"]["filename"]=rune_file;
	my_runes["rune_3"]["rune"]=rune_name;
	break;
    case "rune_4" :
	if(my_level < 40) return "You lack the experiance with this weapon to install a rune in the fourth slot.";
	my_runes["rune_4"]["filename"]=rune_file;
	my_runes["rune_4"]["rune"]=rune_name;
	break;
    default:
	return "There are only four slots in this rune weapon."; }
    return "The rune has been sucessfully installed into the weapon.";}

///////////////////////////////////////////////////////////////////////////////

