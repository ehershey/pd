#include <std.h>

inherit ROOM;

int start_here(string);

void create()
{
    object board;
    
    ::create();
    
    set_properties(([
        "light"       : 2,
        "indoors"     : 1
        ]));
    set_short("Nesoo's Workroom");
    set_long("Nesoo's Workroom\n" +
        "Nesoo's workroom contains many benches covered " +
        "with piles of partially finished toys." );
    set_items(([
        ({ "toys", "toy" })        : "Toys are everywhere!",
        ({ "bench", "benches" }) : "A plain wooden " +
            "workbench with unidentifiable half finished " +
            "toys and tools scattered all over it."
        ]));
    set_exits(([
        "out" : "/d/nopk/tirun/square.c"
        ]));
    
    /* --- Board --- */
    board = new("std/bboard");
    board->set_name("board");
    board->set_id( ({ "board", "message board" }) );
    board->set_max_posts(50);
    board->set_edit_ok( ({ "nesoo", "stormbringer", "whit" }) );
    board->set_location("/wizards/nesoo/workroom.c");
    board->set_short("A message board");
    board->set_long("Leave a message or toy request " +
        "for Nesoo.  If you request a toy, come back " +
        "and check out the pile of toys to see if " +
        "he's made it yet.\n");
    board->set_board_id("nesoo_workroom");
}

void init()
{
    ::init();
    
    add_action("start_here", "start");
}

int start_here(string str)
{
    if( !wizardp(this_player()) )
        return 0;
    
    if( !str || str=="" )
         return notify_fail("Start where?\n");
    
    if( str != "here" )
         return notify_fail("You cannot start there.\n");
    
    this_player()->set_primary_start("/wizards/nesoo/workroom.c");
    write("You are now set to start here.");
    return 1;
}

