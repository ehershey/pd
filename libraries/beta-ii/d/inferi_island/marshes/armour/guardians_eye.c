#include <std.h>
#include <amun.h>
inherit OBJECT;
void create() {
    ::create();
    set_name("Guardians Eye");
    set("id", ({"guardians eye", "eye"}) );
    set_short("%^BOLD%^%^YELLOW%^Guardians Eye%^RESET%^");
    set_long("%^BOLD%^%^YELLOW%^In a place of sight the eye is used.  Insert it correctly and let it fuse.%^RESET%^");
    set_weight(10);
}
