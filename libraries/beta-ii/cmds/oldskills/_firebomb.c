// seeker 06/02/2000
// Spell now hits all in room - does not require target.
// ::Inferno(Aug. - 09 2000);
// Help file changed due to player requests
#include <std.h>
#include <daemons.h>
inherit DAEMON;
int spell();
int cmd_firebomb(string str)
{
    int i, x;
    string what, party;
    object ob, *per=({});
    if (!spell())
    {
        write("What?\n");
        return 1;
    }
    if (!str || str=="")
    {
        notify_fail("Firebomb with what?\n");
        return 0;
    }
    if (!sscanf(str, "with %s", what))
    {
        write("Firebomb with what?");
        return 1;
    }
    if (this_player()->query_disable())
        return notify_fail("You are busy.\n");
    ob  = present(what, this_player());
    if (!ob)
    {
        write("You dont have that.");
        return 1;
    }
    if (ob->query_type()!="alcoholic")
    {
        write("You can only firebomb with alcoholic drinks.");
        return 1;
    }
    if (this_player()->query_mp() < 70)
        return notify_fail("Your spell fails, due to lack of magic.\n");
    if (environment(this_player())->query_property("no attack") ||
      environment(this_player())->query_property("no magic") )
    {
        write("Greater powers prevent your malice.");
        return 1;
    }
    i = ob->query_strength()*5;
    i += this_player()->query_skill("magic attack")/3; 
    i += this_player()->query_skill("pyromancy")/2;
    write("%^BOLD%^%^RED%^You light the "+ob->query_cap_name()+" on fire and quickly throw it at the ground!");
    say("%^BOLD%^%^RED%^"+this_player()->query_cap_name()+" lights "+ob->query_cap_name()+" on fire and quickly throws it at the ground!");
    this_player()->set_paralyzed(random(3), "The flames hold you back!");
    ob->remove();
    per = all_inventory(environment(this_player()));
    x = sizeof(per);
    if (this_player()->query_party())
        party = this_player()->query_party();
    else party = "AdkIl898-FL00Jn-neInfe_ron";
    while(x--) {
        if (!per[x]->is_living()) continue;
        if (this_player()->query_mp() < 70) {
            write ("%^BOLD%^%^RED%^The flames dissipate.%^RESET%^");
            say ("%^BOLD%^%^RED%^The flames dissipate.%^RESET%^");
            break;
        }
        if (per[x]->query_party() == party) continue;
        if (!per[x]->query_ghost() && per[x] != this_player() && per[x]->query_level() > 3 && !wizardp(per[x])) {
            if(per[x]->query_skill("magic defense")/2 > i) {
                write("%^BOLD%^%^RED%^Your flames engulf "+per[x]->query_cap_name()+" and dissapate doing no damage!%^RESET%^");
                say("%^BOLD%^%^RED%^The flames engulf "+per[x]->query_cap_name()+" and dissapate doing no damage!%^RESET%^");
                tell_object(per[x], "%^BOLD%^%^RED%^You are engulfed in flames, they dissipate at once, doing no damage!%^RESET%^");
                continue;
            }
            if(!this_player()->kill_ob(per[x])) continue;
            per[x]->damage(i + random(this_player()->query_level()/2) - per[x]->query_skill("magic defense"), "fire");
            tell_object(per[x], "%^BOLD%^%^RED%^You are engulfed in flames!");
            tell_room(environment(per[x]), "%^BOLD%^%^RED%^"+per[x]->query_cap_name()+" is engulfed in flames!", ({ per[x] }));
            this_player()->add_mp(-i/14)*x;
            this_player()->set_disable();
        }
    }
    return 1;
}
int spell()
{
    if (this_player()->query_subclass()!="pyromancer") return 0;
    if (this_player()->query_level() < 20) return 0;
    if (this_player()->query_skill("conjuring") < 70) return 0;
    return 1;
}
void help()
{
    write("Syntax: firebomb with (alcoholic beverage)\n"
      "This is a spell used by high level pyromancers. The caster "
      "ignites an alcoholic beverage in their inventory with "
      "their mind and throws it at the ground. The drink explodes "
      "and flames engulf everyone in the room, with the "
      "exception of the caster.");
}
