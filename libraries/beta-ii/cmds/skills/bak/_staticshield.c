// based on _mudarmour.c
// a dungeonware.net production
#include <std.h>
mapping staticed, waiting; 
int spell();
void create()
{
 staticed = ([]);
 waiting = ([]);
}
int query_staticed(object ob) { return staticed[ob]; }
string type() { return "defense"; }
int cmd_staticshield( string str )
{
    int i;
    object ob;
    if (!spell()) return notify_fail("What?\n");
    if (this_player()->query_ghost()) {
        notify_fail("Your voice is hollow.\n");
        return 0;
    }
    if (this_player()->query_disable())
        return notify_fail("You are busy.\n");
    if (environment(this_player())->query_property("no magic")) {
        notify_fail("Something seems to be blocking your concentration.\n");
        return 0;
    }
    if (this_player()->query_mp() < 50) {
        notify_fail("Too low on magic power.\n");
        return 0;
    }
    if (!str || str == "" || !(ob = present(str, environment(this_player()))) || str == "me" || str == "myself")
        ob = this_player();
    if (!ob)
        return notify_fail("Staticshield whom?\n");
    if (waiting[ob] || staticed[ob]){
     write(ob->query_cap_name()+" already has a static shield.\n");
        return 1;
    }
    i = this_player()->query_skill("magic defense");
    waiting[ob] = i;
    call_out("form", 10, ob, i);
    this_player()->add_mp(-(i + random(40)) );
    if (this_player()!=ob) {
        write("%^ORANGE%^You charge the air around "+ob->query_cap_name()+" with energy.%^RESET%^");
        message("info", "%^ORANGE%^Your skin begins to tingle as "+this_player()->query_cap_name()+" makes hand gestures at "+ob->query_cap_name()+".%^RESET%^", environment(ob), ({ ob, this_player() }) );  
        message("info", "%^ORANGE%^"+this_player()->query_cap_name()+" makes hand gestures at you causing your skin to tingle.%^RESET%^", ob);
    } else {
        write("%^ORANGE%^You charge the air around you with energy.%^RESET%^");
        message("info", "%^ORANGE%^"+this_player()->query_cap_name()+" makes hand gestures at the air. Your skin begins to tingle.%^RESET%^", environment(this_player()), this_player());
    }
    return 1;
}
int form(object ob, int i, int def, int time)
{
  if (!ob) return 0;
    if (i < 60)  def = 1; else
    if (i < 80) def = 2; else
    if (i < 120) def = 3; else
    if (i < 160) def = 4; else
    if (i < 200) def = 5; else
    if (i >= 200) def = 6;
    time = (def*20)+random(def*5);
 staticed[ob] = waiting[ob];
 map_delete(waiting, ob);
 message("info", "\n%^ORANGE%^The air around you begins to shimmer.%^RESET%^", ob);
 message("info", "%^ORANGE%^The air around "+ob->query_cap_name()+" shimmers.%^RESET%^", environment(ob), ({ ob }) );
 ob->add_magic_protection( ({ 0, (def*3)+random(def), time}) );
 call_out("remove_prot", time, ob);
}
int remove_prot(object ob)
{
   if(!ob) return 0;
 message("info", "\nThe air around you returns to normal.", ob);
 message("info", "The air around "+ob->query_cap_name()+" returns to normal.", environment(ob), ob);
 map_delete(staticed, ob);
}
void help() {
write("
Syntax: <staticshield [living]>
The caster creats a shield of static that can absorb some damage in combat.
");
}
int spell() {
 if (this_player()->query_level() < 15) return 0;
 if (this_player()->query_subclass()=="sorceror") return 1; }
