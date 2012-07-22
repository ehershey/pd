#include <std.h>
#include <daemons.h>
inherit PIER;
static string letter;
int *query_coords() { return OCEAN_D->query_coord_from_letter(letter); }
void set_letter(string str) { letter = str; }
void init() {
    ::init();
    add_action("boat_recall", "recall");
    add_action("boat_board", "board");
    add_action("look", "look");
}
int boat_board(string str) {
    object ob;
    if (!str || str=="") {
	write("Board what?");
	return 1;
    }
    ob=OCEAN_D->find_player_ship(str);
    if(!ob) {
	write("You do not notice that boat in the harbor.");
	return 1;
    }
    if(ob->query_xy()[0] != query_coords()[0] && ob->query_xy()[1] != query_coords()[1]) {
	write("You do not notice that boat in the harbor.");
	return 1;
    }
    if(!ob->query_docked()) {
	write("That ship is not docked.\n");
	return 1;
    }
    write("You board "+capitalize(str)+"'s boat.");
    this_player()->move_player(ob, "on a boat");
    return 1;
}
int boat_recall(string str) {
    object ob;
    string st;
    int *i, x,y;
    mapping loc;
    st = DIR_BOATS+"/"+this_player()->query_name()+".o";
    if(!file_exists(st)) {
	write("You must own a ship first!\n");
	return 1;
    }
    i=query_coords();
    ob=OCEAN_D->find_player_ship(this_player()->query_name());
    if(!ob) ob=new("/std/obj/boat");
    if(!ob->query_owner()) ob->set_owner(this_player()->query_name());
    ob->load(this_player()->query_name());
    x=i[0];
    y=i[1];
    if(ob->query_sunk()) {
	write("Your boat is sitting at the bottom of the ocean.\n");
	return 1;
    }
    if(ob->query_xy()[0] == query_coords()[0] && ob->query_xy()[1] == query_coords()[1] && ob->query_docked()) {
	write("Your ship is already here.");
	return 1;
    }
    ob->set_docked(base_name(this_object()));
    ob->set_xy(i[0], i[1]);
    write("Your boat pulls into the docks.");
    return 1;
}
int look(string str) {
    object *o;
    int i;
    string out="";
    if(!str || (str != "ship" && str != "ships")) return "/cmds/mortal/_look"->cmd_look(str);
    i=sizeof(o=OCEAN_D->get_present_ships(query_coords()));
    if(!i) {
	write("You do not notice any ships near here.\n");
	return 1;
    }
    write("There are a total of "+i+" ships near here\n\n");
    while(i--) {
	if(o[i]->query_docked()) out += capitalize(o[i]->query_owner())+"'s boat is here. (Docked)\n";
	else if(o[i]->query_sunk()) out += "The wreckage of "+capitalize(o[i]->query_owner())+"'s boat is here.\n"; else
	    out += capitalize(o[i]->query_owner())+"'s boat is here.\n";
    }
    write(out);
    return 1;
}
