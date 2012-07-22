#include <std.h>
inherit WEAPON;

static int loaded, MAX_BULLET = 1;

void create() {
 ::create();
   set_name("elephant gun");
   set_short("an elephant gun");
   set_long("A high-powered elephant gun. The iron barrel comes to a fat "
	"mouth. The hadle of it is wooden. The gun somewhat resembles a "
	"rifle.");
   set_id(({ "elephant gun", "gun" }));
   set_type("blunt");
   set_wc(0);
}

int load(string str) {
   int i, mx;
   object bul;
   if (!str || str == "" || present(str, this_player()) != this_object())
	return notify_fail("Load what?\n");
   bul = present("bullets", this_player());
   if (!bul) return notify_fail("You have no bullets to load it with.");
   mx = bul->query_bullets();
   i = MAX_BULLET - loaded;
   if (i <= 0) return notify_fail("The elephant gun is already "
	"loaded!\n");
   if (mx <= 0) { bul->remove(); return 1; }
   if (i >= mx) i = mx;
   mx -= i;
   if (mx <= 0) bul->remove();
   bul->set_bullets(mx);
   if (i == 1) write("You load a single bullet into the elephant gun.");
   else write("You load "+(string)i+" bullets into the mk9.");
   loaded += i;
   if (loaded >= MAX_BULLET) loaded = MAX_BULLET;
   if (MAX_BULLET == loaded) write("The elephant gun is now full.");
   say(this_player()->query_cap_name()+" loads a bullet into "
	"an elephant gun.", this_player());
   return 1;
}

int fire(string str) {
   int i;
   string what, who, limb, *limbs = ({ });
   object ob;
   if (sscanf(str, "%s with %s", who, what) == 2) {
     if (present(what, this_player()) != this_object()) return 0;
   } else who = str;
   ob = present(who, environment(this_player()));
   if (!ob) return notify_fail("You do not see that here.\n");
   say(this_player()->query_cap_name()+" points an elephant gun at "+
	ob->query_cap_name()+" and fires!", this_player());
   if (!loaded) {
	tell_object(environment(this_player()), "%^BOLD%^> Click. <");
     return 1;
   }
     loaded = 0;
   write("You fire at "+ob->query_cap_name()+"!");
   tell_object(environment(this_player()), "%^RESET%^%^RED%^BANG!");
   ob->force_me("scream in pain");
   limbs = ob->query_limbs();
   i = random(sizeof(ob->query_limbs()));
   limb = limbs[i];
   ob->do_damage(limb, random(500) + 500);
   ob->check_on_limb(limb);
   if (ob->query_hp() <= 0) ob->die();
   return 1;
}

void init() {
 ::init();
   add_action("load",  "load");
   add_action("fire",  "shoot");
}
