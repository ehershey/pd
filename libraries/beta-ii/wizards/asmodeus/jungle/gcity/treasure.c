#include <std.h>
#include <mjungle.h>
#include <gcity.h>
inherit BAG;

void create() {
    object money;

    ::create();
    set_id( ({"chest", "treasure chest"}) );
    set_name("chest");
set_short("a treasure chest");
    set("long", "A solid iron chest with a lock.\nIt is closed.");
    set_open_long("A solid iron chest with a lock.\nIt is open.");
    set_open_long("A solid iron chest with a lock.\nIt is closed.");
    set_no_clean(1);
    set_weight(2000000);
    set_value(100);
    set_max_internal_encumbrance(2000);
    set_possible_to_close(1);
    set_lock("locked");
    set_property("magic hold", 10);
set_key("ruby_key");
    money = new("std/obj/coins");
   money->set_money("platinum", random(150));
    money->set_money("gold", random(500));
    money->set_money("electrum", random(500));
    money->set_money("silver", random(1000));
    money->move(this_object());
}
