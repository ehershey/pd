// A wine chest
#include <std.h>
inherit "/std/bag_logic";
static object var;
object query_location();
object set_location();

void create() {
    object ob;
    ::create();
    ob = this_object();
    set_id(({ "cabinet", "wine cabinet", "chest"}));
    set_name("winecab");
    set_short("a wine cabinet");
    set("long", "The wine cabinet is closed.");
    set_open_long("The wine cabinet is open.");
    set_closed_long("The wine cabinet is closed.");
    set_weight(50);
    set_value(10000);
    set_max_internal_encumbrance(20000);
    set_possible_to_close(1);
    set_lock("locked");
    set_property("magic hold", 100);
    set_key("limo_key");
    new("/wizards/inferno/beer")->move(ob);
    new("/wizards/inferno/beer")->move(ob);
    new("/wizards/inferno/beer")->move(ob);
    new("/wizards/inferno/beer")->move(ob);
    new("/wizards/inferno/beer")->move(ob);
    new("/wizards/inferno/beer")->move(ob);
    new("/wizards/inferno/beer")->move(ob);
    new("/wizards/inferno/beer")->move(ob);
    this_object()->toggle_closed();
}
int set_prevent_get() { return 1; }

object query_location() { return var; }

object set_location(object ob) { var = ob; }
