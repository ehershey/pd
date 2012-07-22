#include <std.h>
#include "/domains/labyrinth/defs.h"
inherit BASE_OBJECT;

void create() {
    ::create();
    set_short("the Staff of Labrys");
    set_long(
      "It is a long staff of ebony, carved into strange and sinister
shapes."
    );
    set_name("staff");
    set_id(({ "staff", "staff of labrys", "ebony staff" }));
    set_weight(500);
    set_value(10000);
}

void init() {
    ::init();
    add_action("stabilize","stabilize");
    add_action("find","find");
    add_action("teleport","teleport");
}

int teleport(string str) {
    int x,y,z;

    if(sscanf(str,"%d %d %d",x,y,z)<3) {
        if(sscanf(str,"%d,%d,%d",x,y,z)<3) {
            if(sscanf(str,"%d;%d;%d",x,y,z)<3) {
                return notify_fail("Syntax: teleport <x> <y> <z>\n");
            }
        }
    }
    master()->send_player_to(this_player(),x,y,z);
    return 1;
}

int find(string str) {
    object who, env;
    if(str) { who = find_player(str); }
    else { who = this_player(); }
    if(!who) { return notify_fail("That person is not here.\n"); }
    if(!(env = environment(who))) { return notify_fail("That person has no environment!\n"); }
    if(!(env->query_labrys())) { return notify_fail("You cannot use that on one who is not in the Labyrinth!\n"); }
    if(who==this_player()) {
        write("Your coordinates are: "+env->query_x()+",
"+env->query_y()+",
"+env->query_z());
    } else {
        write(who->query_cap_name()+"'s coordinates are:
"+env->query_x()+",
"+env->query_y()+", "+env->query_z());
    }
    return 1;
}

int stabilize(string str) {
    string short, long, *items, *exits;
    int x, y, z, light;
    int i, j;
    object tp, env;
    string file, *lines, *newlines;
    env = environment(tp = this_player());
    file = read_file(ROOM_TEMPLATE);
    x = env->query_x();
    y = env->query_y();
    z = env->query_z();
    light = env->query_property("light");
    short = env->query_short();
    long = env->query_true_long();
    items = env->query_items();
    exits = env->query_exits();

    file = replace_string(file,"SHORT",short);
    file = replace_string(file,"XXX",x+"");
    file = replace_string(file,"YYY",y+"");
    file = replace_string(file,"ZZZ",z+"");
    file = replace_string(file,"LIGHT",light+"");

    lines = explode(file,"\n");
    newlines = ({ });
    for(i=0;i<8;i++) {
        newlines += ({ lines[i] });
    }
    for(i=0;i<strlen(long);i+=65) {
        j = i+65;
        if(j>strlen(long)) { j = strlen(long); }
        if(j<strlen(long)) {
            newlines += ({ "      \""+long[i..(j-1)]+"\"+" });
        } else {
            newlines += ({ "      \""+long[i..(j-1)]+"\"" });
        }
    }
    for(i=8;i<12;i++) {
        newlines += ({ lines[i] });
    }
    i = sizeof(exits);
    while(i--) {
        if(i) {
            newlines += ({ "      \""+exits[i]+"\" :
\""+env->query_exit(exits[i])+"\"," });
        } else {
            newlines += ({ "      \""+exits[i]+"\" :
\""+env->query_exit(exits[i])+"\"" });
        }
    }
    for(i=12;i<14;i++) {
        newlines += ({ lines[i] });
    }
    i = sizeof(items);
    while(i--) {
        if(env->query_long(items[i])=="You see nothing.") { items -= ({
items[i] }); }
    }
    i = sizeof(items);
    while(i--) {
        if(i) {
            newlines += ({ "      \""+items[i]+"\" :
\""+env->query_long(items[i])+"\"," });
        } else {
            newlines += ({ "      \""+items[i]+"\" :
\""+env->query_long(items[i])+"\"" });
        }
    }
    for(i=14;i<17;i++) {
        newlines += ({ lines[i] });
    }
    file = implode(newlines,"\n");
    file += "\n";
    if(!str) { str = x+"_"+y+"_"+z; }
    write_file(UNIQUES+str+".c",file,1);
    write("File created.");
    return 1;
}

mixed *query_auto_load() { return ({ LABYRINTH+"labrys_staff", ({ }) }); }

