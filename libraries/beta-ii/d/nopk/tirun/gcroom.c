#include <std.h>
#include <tirun.h>
#include <daemons.h>

inherit ROOM;
   object ob;
void create() {

   ::create();
   set_name("Portal Room west");
   set_short("Tirun Portal Room West");
   set_long("This small building houses only some tables with construction plans. A large board stands against one wall.");
    set_exits ( ([ "out" : ROOMS "nveros3" ]) );
   set_properties((["light":2, "night light":2, "indoors":1, "no attack":1, "no steal":1, "no magic":1]));
    ob = new(BBOARD);
    ob->set_name(" board");
    ob->set_location("/d/nopk/tirun/gcroom.c");
    ob->set_id( ({ "board", "construction board" }) );
    ob->set_board_id("area_builders_board");
    ob->set_max_posts(999);
    ob->set_short("Construction Board");
    ob->set_long("The Construction Board.");
    ob->set_edit_ok( ({ "whit", "stormbringer", "nulvect", "amun", "daos", "ironman" }) );
}
