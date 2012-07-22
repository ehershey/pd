// a dungeonware.net production
// coded for Primal Darkness by Stormbringer
#include <std.h>
inherit DAEMON;
mapping waiting;
int spell();
void create()
{
    waiting = ([]);
}
int query_waiting(object ob) { return waiting[ob]; } 
int check_alignment(object tp);
int cmd_buffer(string str) {
    object ob;
    int defense, def;
    int cost, amount, time;
    if (!spell()) return notify_fail("What?\n");
    if(!str) {
        notify_fail("Cast buffer on whom?\n");
        return 0;
    }
    this_player()->set_magic_round(2);
    ob = present(str, environment(this_player()));
    if(!ob) {
        if(str == "me" || str == "myself") ob = this_player();
    }
    if(!ob) {
        notify_fail(capitalize(str)+" is not here.\n");
        return 0;
    }
    if(!living(ob)) {
        notify_fail(capitalize(str)+" is not alive!\n");
        return 0;
    }
    if(environment(this_player())->query_property("no magic")) {
        notify_fail("A holy force prevents this.\n");
        return 0;
    }
    cost = defense*2/3 + random(defense/3);
    if((int)this_player()->query_mp() < cost) {
        notify_fail("Too low on magic power.\n");
        return 0;
    }
    if (this_player()->query_disable())
        return notify_fail("You are busy.\n");
    if (this_player()->query_mp() < 100) 
        return notify_fail("Your spell fails, due to lack of magic.\n");
    defense = ((int)this_player()->query_skill("magic defense"));
    if(defense < 25) {
        write("You mutter words beyond your understanding.");
        say(this_player()->query_cap_name()+" mumbles words beyond "+
          this_player()->query_possessive()+" understanding.", this_player());
        return 1;
    }
    if(!alignment_ok(this_player())) {
        write("You have betrayed the source of your powers.");
        return 1;
    }
    if(ob==this_player()) {
        write("You look over yourself and call on your powers of protection.\n");
        say(this_player()->query_cap_name()+" looks at "+objective(this_player())+"self and calls on "+this_player()->query_possessive()+" powers of protection.", ob);
    } else {
        write("You look at "+ob->query_cap_name()+" and call on your powers of protection.");
        tell_object(ob, this_player()->query_cap_name()+" looks at you and calls on "+this_player()->query_possessive()+" powers of protection.");
        say(this_player()->query_cap_name()+" looks at "+ob->query_cap_name()+" and calls on "+this_player()->query_possessive()+" powers of protection.", ob);
    }
    if (defense < 50) def = 1; else
    if (defense < 100) def = 2; else
    if (defense < 200) def = 3; else
    if (defense < 325) def = 4; else
    if (defense < 500) def = 5; else
    if (defense > 500) def = 5;
    amount = (def*3/2)+(random(def))+1;
    time = (def*35)+random(def*3/2);
    waiting[ob] = time;
    ob->add_magic_protection( ({ 0, amount , time }));
    call_out("buffer_off", time, this_player());
    this_player()->set_disable();
    this_player()->add_skill_points("magic defense", random(defense/40));
    this_player()->add_alignment(random(defense/40));
    this_player()->add_mp(-cost);
    return 1;
}
void buffer_off(object ob) {
        write("%^YELLOW%^Your buffer wears off.%^RESET%^\n");
        map_delete(waiting, ob);
     return 1;
}
void help() {
    write("Syntax: <buffer [player]>\n\nCreates a powerful spell of "
      "protection. \n");
}
int spell() {
    object tp;
    tp = this_player();
    if (!tp) return 0;
    if (tp->query_skill("magic defense") < 25) return 0;
    if (tp->query_level() < 10) return 0;
    if (tp->query_class() != "mage" && tp->query_subclass() != "kataan")
        return 0;
    return 1;
}
