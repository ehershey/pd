#include <std.h>
inherit WEAPON;

static int loaded, MAX_BULLET = 6;

void create() {
 ::create();
   set_name("pistol");
   set_short("an mk9 stainless steel pistol");
   set_long("A 9mm pistol of stainless steel quality with easy-to-see "
	"sights, that are completely snag free. The grip is hard vinyl "
	"and gives a good hold. The undetachable magazine can hold up "
	"to six bullets at a time.");
   set_id(({ "mk9", "9mm", "pistol" }));
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
   if (i <= 0) return notify_fail("The magazine is already full!\n");
   if (mx <= 0) { bul->remove(); return 1; }
   if (i >= mx) i = mx;
   mx -= i;
   if (mx <= 0) bul->remove();
   bul->set_bullets(mx);
   if (i == 1) write("You load a single bullet into the mk9.");
   else write("You load "+(string)i+" bullets into the mk9.");
   loaded += i;
   if (loaded >= MAX_BULLET) loaded = MAX_BULLET;
   if (MAX_BULLET == loaded) write("The magazine is now full.");
   say(this_player()->query_cap_name()+" loads some bullets into "
	"an mk9.", this_player());
   return 1;
}

int fire(string str) {
   int i;
   string what, who, trig = 0;
   object ob, igor, env, *all = ({ }), *ppl = ({ });
   if (sscanf(str, "%s with %s", who, what) == 2) {
     if (present(what, this_player()) != this_object()) return 0;
   } else who = str;
   ob = present(who, environment(this_player()));
   if (ob) say(this_player()->query_cap_name()+" points an mk9 at "+
	ob->query_cap_name()+" and fires!", this_player());
   if (!loaded) {
     if (ob)
	tell_object(environment(this_player()), "%^BOLD%^> Click. <");
     else {
	say(
		this_player()->query_cap_name()+" points an mk9 "+who+
		" and fires!", this_player());
	write("You point an mk9 "+who+" and fire!");
	tell_object(environment(this_player()), "%^BOLD%^> Click. <");
     }
     return 1;
   }
     loaded -= 1;
     if (loaded <= 0) loaded = 0;
   if (!ob) {
     if (environment(this_player())->query_exit(who) == 
	"/d/standard/void") return notify_fail("You do not see that "
						"here.\n");
     igor = new("/wizards/inferno/igor");
     igor->move(environment(this_player())->query_exit(who));
     env = environment(igor);
     igor->remove();
     say(this_player()->query_cap_name()+" points an mk9 "+who+" and "
	 "fires!", this_player());
     all = all_inventory(env);
     i = sizeof(all);
     while (i--) {
	if (all[i]->is_living()) ppl += ({ all[i] });
     }
     if (!sizeof(ppl)) return notify_fail("A stray bullet flys "+who+
					  " and hits the ground!\n");
     if (random(4) <= 1) { tell_object(env, "A stray bullet flys into the "
					    "room and hits the ground!");
			   write("The stray bullet flys "+who+" and hits "
				 "the ground.");
			   return 1; }
     i = random(sizeof(ppl));
     ob = ppl[i];
     tell_object(ob, "A stray bullet flys into the room and clips you!");
     say("A stray bullet flys into the room and clips "+ob->query_cap_name()
	+"!", ob);
     ob->damage(random(100) + 25, "bullet");
     write("The stray bullet flys "+who+" and clips "
	+ob->query_cap_name()+"!");
     if (ob->query_hp() <= 0) ob->die();
     return 1;
   }
   write("You fire at "+ob->query_cap_name()+"!");
   tell_object(environment(this_player()), "%^BOLD%^%^RED%^Bang!");
   ob->force_me("scream in pain");
   ob->damage(random(100) + 100, "bullet");
   if (ob->query_hp() <= 0) ob->die();

   return 1;
}

void init() {
 ::init();
   add_action("load",  "load");
   add_action("fire",  "shoot");
}
