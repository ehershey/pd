#include <std.h>
#include <dirs.h>
#define OCEAN_D  "/wizards/whit/ocean/ocean"
inherit PIER;
static string letter;
int *query_coords() { return OCEAN_D->query_coord_from_letter(letter); }
void set_letter(string str) { letter = str; }
void init() {
    ::init();
    add_action("boat_recall", "recall");
    add_action("boat_board", "board");
    add_action("look_ships", "look");
}
int boat_board(string str) {
    string file;
    object ob;
    int *i, *z, x,x2,y,y2, *c;
    if (!str || str=="") {
	write("Board what?");
	return 1;
    }
    i=query_coords();
    c=OCEAN_D->get_ship_location(str);
    if(!c || c==({}) || !sizeof(c)) {
	write(identify(OCEAN_D->get_ship_location(str)) + " " + identify(i));
	write("You do not notice that boat in the harbor.");
	return 1;
    }
    write(identify(c));
    x=c[0]; y=c[1];
    x2=i[0]; y2=c[1];
    if(x != x2 || y != y2) {
	write(identify(OCEAN_D->get_ship_location(str)) + " " + identify(i));
	write("You do not notice that boat in the harbor.");
	return 1;
    }
    ob = OCEAN_D->get_boat(str);
    if (!ob) {
	write("You do not notice that boat in the harbor.");
	return 1;
    }
    write("You board "+capitalize(str)+"'s boat.");
    this_player()->move_player(ob, "on a boat");
    return 1;
}
int boat_recall(string str) {
    object ob;
    string st;
    int *i, x,y,x2,y2;
    mapping loc;
    st = DIR_BOATS+"/"+this_player()->query_name()+".o";
    if(!file_exists(st)) {
	write("You must own a ship first!\n");
	return 1;
    }
    i=query_coords();
    ob=OCEAN_D->get_boat(this_player()->query_name());
    if(!ob) ob=new("/std/obj/boat");
    if(!ob->query_owner()) ob->set_owner(this_player()->query_name());
    x=ob->query_xy()[0];
    y=ob->query_xy()[1];
    x2=i[0];
    y2=i[1];
    if(x == x2 || y == y2) {
	write("Your ship is already here.");
	return 1;
    }
    OCEAN_D->move_boat(this_player()->query_name(), i);
    OCEAN_D->set_boat(ob);
    ob->load(this_player()->query_name());
    OCEAN_D->ship_location(ob, i[0], i[1]);
    ob->set_docked(base_name(this_object()));
    ob->set_xy(i[0], i[1]);
    write("Your boat pulls into the docks.");
    return 1;
}
int look_ships(string str) {
    object *s;
    string tmp;
    int i, X, Y;
    X=query_coords()[0];
    Y=query_coords()[1];
    if(str != "ship" && str != "ships") return 0;
    s=OCEAN_D->get_room_ships(this_object(), X, Y);
    i=sizeof(s);
    if(!i) { 
	write("You do not see any ships near here.");
	return 1;
    }
    tmp="You can see: \n";
    while(i--) tmp += ""+capitalize(s[i]->query_owner())+"'s ship is here.\n";
    write(tmp);
    return 1;
}
