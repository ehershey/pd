#include <std.h>
#include <guild.h>
inherit OBJECT;
void create() {
    ::create();
    set_id(({ "enchanted pool", "pool" }));
    set_name("enchanted pool");
    set_long("A pool of enchanted water inhabited by a spirit. The spirit will help those in search of people locate them, for a price. To have the spirit find someone, use the syntax <locate [living]>.");
    set_short("%^WHITE%^An enchanted pool%^RESET%^");
    set_weight(1);
    set("value", 0);
    set_prevent_get( "The pool is far to large to move." );
}

int locPlayer(string str) 
{
    object ob;
    object *inv;
    string desc;
    
    if(GUILD_D->query_actual_position(this_player()->query_name()) == "squire") 
    { 
        write("The spirit laughs at you.\n"); 
        return 1; 
    }
    if(!str) 
    {
       notify_fail("Locate who?\n");
       return 0;
    }
    
    if(this_player()->query_money("platinum")<1)
    {
        notify_fail("The spirit screeches in anger, waiting for the platinum coin it wants.\n");
        return 0;
    }
    else
    {
        this_player()->add_money("platinum", -1);
        message("room", this_player()->query_cap_name()+" throws a coin into the pool, and it begins to glow."
            ,environment(this_player()),this_player());
        message("tp", "You throw a platinum coin into the pool.",this_player());
    }
 
    ob = find_living(str);
    if(!ob || !ob->is_player()) 
    {

        message("failed", "The spirit screeches in anger, unable to find the person.", this_player());
        return 0;
    }
    if(environment(ob)->query_property("no scry") || environment(ob)->query_property("no teleport"))
        return notify_fail("The spirit screeches in anger, unable to find the person.\n");
    if(wizardp(ob)) 
    {
        notify_fail("The spirit screeches in anger, unable to find the person.\n");
        return 0;
    }
    
    ob = environment(ob);
    if(!ob) write("The spirit screeches in anger, unable to find the person.\n");
    else {
        desc = (string)ob->query_long()+"\n";
        inv = all_inventory(ob);
        for(int i=0; i<sizeof(inv); i++) {
            if(inv[i]->query_invis()) continue;
            desc += (string)inv[i]->query_short()+"\n";
        }
        write("The spirit vanishes into the pool.\n"+desc);
    }

    return 1;
    
}
void init() {
    ::init();
        add_action("locPlayer", "locate");
}
