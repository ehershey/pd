#include <std.h>

inherit OBJECT;

int slices = 0;

mapping slices;

void create() {
    ::create();
    slices = ([]);
    set_name("pumpkin");
    set("id", ({"pie", "pumpkin pie"}) );
    set_short("Luna's homemade pumpkin pie");
    set_long("Luna's delicious, homemade, mouthwatering pumpkin pie which is said to be imbued with magical restorative powers. Take a slice and enjoy!");
    set_prevent_get("Don't be greedy! Take a slice.");
}

void init() {
    ::init();
    add_action("cmd_take", "take");   
}

int cmd_take(string str) {
    object ob;   
    if (!str || str != "slice") 
        return notify_fail("That is not here.\n");

    if (slices[this_player()->query_name()] >= 2)
        return notify_fail("You have to wait for reboot to take another slice.\n");
    ob = new("/wizards/luna/pieslice.c");
    message("info", "You take a slice of the pie.", this_player());
    slices[this_player()->query_name()]++;
    ob->move(this_player());
    say(this_player()->query_cap_name()+" takes a slice of the pie.");
    return 1;
}

