#include <std.h>
#include <daemons.h>
inherit OBJECT;

void create() {
   ::create();
   set_name("pager");
   set_id( ({"pager"}) );
   set_short("A paging device");
   set_long("A device to beep at people with.");
   set_value(0);
   set_mass(0);
   set_prevent_get("This isnt yours.");
}

void init() {
   ::init();
   add_action("page","page");
}

int page(string str) {
   object who;
   if(!str){ notify_fail("Page whom?\n"); return 0; }
   if(!present(this_object(), this_player())) return 0;
   if(!(who = find_living(lower_case(str)))) {
        notify_fail("That person is notcurrently on primal darkness.\n");
        return 0;
   }
    message("page","%^BOLD%^%^BLUE%^"+this_player()->query_cap_name()+" pages you: %^WHITE%^MAY I HAVE YOUR ATTENTION PLEASE!? ^G ",who);
    message("page",capitalize(str)+" has been paged.",this_player());
   return 1;
}

int repage() {
}


