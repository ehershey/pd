#include <std.h>
#include "/wizards/seeker/labyrinth/defs.h"
inherit DAEMON;
inherit LABRYS;

mapping loaded_rooms;

void create() {
    ::create();
    load_object(CLEANUP_DAEMON);
    loaded_rooms = ([ ]);
}

mixed *query_loaded_rooms() { return keys(loaded_rooms); }
mapping query_room_objects() { return loaded_rooms; }

string get_data(int x,int y,int z) {
    return read_bytes(DATA,(8 * (x + (DIMENSION * y) + (DIMENSION * DIMENSION * z))),8);
}
mapping get_specs(int x,int y,int z) {
    return storage()->decompress(read_bytes(DATA,(8 * (x + (DIMENSION * y)+(DIMENSION * DIMENSION * z))),8));
}

string *get_exit_specs(int x,int y,int z) {
    return storage()->decompress_exits(read_bytes(DATA,(8 * (x + (DIMENSION * y) + (DIMENSION * DIMENSION * z))),8));
}

mapping get_specs_manual(int start,int len) {
    return storage()->decompress(read_bytes(DATA,start,len));
}

int get_distance(int x,int y,int z) {
    float result, x_c, y_c, z_c;
    x_c = to_float(x) - ((to_float(DIMENSION)-1)/2);
    y_c = to_float(y) - ((to_float(DIMENSION)-1)/2);
    z_c = to_float(z) - ((to_float(DIMENSION)-1)/2);
    result = sqrt((x_c * x_c) + (y_c * y_c) + (z_c * z_c));
    return to_int(result);
}

string find_entrance_room(int x,int y,int z,string dir) {
    string *possibilities;
    int i;
    object current;

    possibilities = get_dir(ENTRANCES);
    i = sizeof(possibilities);
    while(i--) {
        sscanf(possibilities[i],"%s.c",possibilities[i]);
        possibilities[i] = ENTRANCES+possibilities[i];
        load_object(possibilities[i]);
        current = find_object(possibilities[i]);

if((current->query_x()==x)&&(current->query_y()==y)&&(current->query_z()==z))
{
            if(current->query_exits(OPPOSITE_EXITS[dir])) {
                return possibilities[i];
            }
        }
    }
    return 0;

string find_unique_room(int x,int y,int z) {
    string *possibilities;
    int i;
    object current;

    possibilities = get_dir(UNIQUES);
    i = sizeof(possibilities);
    while(i--) {
        sscanf(possibilities[i],"%s.c",possibilities[i]);
        possibilities[i] = UNIQUES+possibilities[i];
        load_object(possibilities[i]);
        current = find_object(possibilities[i]);

if((current->query_x()==x)&&(current->query_y()==y)&&(current->query_z()==z))
{
            return possibilities[i];
        }
    }
    return 0;
}

object construct_room(int x,int y,int z,mapping specs) {
    object where;
    string desc, the_entrance, *exits, *stairs, *non_exits;
    int i, j, k, d, dd;

    d = get_distance(x,y,z);
    dd = get_distance(0,0,0) / 2;
    dd = ((7 * (d - dd)) / 4) + dd;
    if(dd<0) { dd = 0; }
    if(dd>get_distance(0,0,0)) { dd = get_distance(0,0,0); }
    where = new(ROOM_DIR+"room"+(specs["room"]+dd));
    where->set_xyz(x,y,z);
    i = sizeof(EXIT_ARR);
    while(i--) {
        if(the_entrance =
find_entrance_room(x+DMODS[EXIT_ARR[i]][0],y+DMODS[EXIT_ARR[i]][1],
            z+DMODS[EXIT_ARR[i]][2],EXIT_ARR[i])) {
            where->add_exit(EXIT_ARR[i],the_entrance);
            specs["exits"] += ({ EXIT_ARR[i] });
        }

    }
    i = sizeof(specs["exits"]);
    while(i--) {
        if(!(where->query_exit(specs["exits"][i]))) {
            if(the_entrance =
find_unique_room(x+DMODS[specs["exits"][i]][0],y+DMODS[specs["exits"][i]][1],
                z+DMODS[specs["exits"][i]][2])) {
                where->add_exit(specs["exits"][i],the_entrance);
            } else {
                where->add_exit(specs["exits"][i],"Labrys");
            }
        }
    }
    if(CONTENTS) {
        i = sizeof(specs["mons"]);
        while(i--) {
            j =
load_object(MONS_DIR+"mons"+(specs["mons"][i]+dd))->query_number();
            k = get_distance(0,0,0);
            if(k<=dd) { k = dd+1; }
            j = (j * (k - dd)) / k;
            if(j<1) { j = 1; }

            while(j--) {
                new(MONS_DIR+"mons"+(specs["mons"][i]+dd))->move(where);
            }
        }
        i = sizeof(specs["obj"]);
        while(i--) {
            new(OBJ_DIR+"obj"+(specs["obj"][i]+dd))->move(where);
        }
    }
    if(FULL_ITEMS) {
        j = 0;
        i = sizeof(specs["items"]);
        while(i--) {
            j += where->add_spec_item(specs["items"][i]);
        }
        if(j) {
            where->set_long(where->query_long()+".");
        }
    }
    if(where->query_stair_name()) {
        exits = specs["exits"] - ({ "up", "down" });
        stairs = specs["exits"] - exits;
        non_exits = EXIT_ARR - (exits + ({ "up", "down" }));
    } else {
        exits = specs["exits"];
        non_exits = EXIT_ARR - exits;
        stairs = ({ });
    }
    i = sizeof(exits);
    j = sizeof(stairs);
    desc = where->query_long();
    switch(i) {
    case 0: { break; }
    case 1: {
            desc += "  "+capitalize(where->query_exit_name())+" leads "+
            exits[0];
            break;
        }
    case 2: {
            desc += "  "+capitalize(where->query_exit_plural())+" lead "+

            exits[0]+" and "+exits[1];
            break;
        }
    default: {
            desc += "  "+capitalize(where->query_exit_plural())+" lead ";
            if(sizeof(non_exits)>2) {
                while(i--) {
                    if(i) {
                        desc += exits[i]+", ";
                    } else {
                        desc += "and "+exits[0];
                    }
                }
            } else {
                desc += "in all directions";
                switch(sizeof(non_exits)) {
                case 0: {
                        break;
                    }
                case 1: {
                        desc += " except "+non_exits[0];
                        break;
                    }
                case 2: {
                        desc += " except "+non_exits[0]+" and
"+non_exits[1];
                    }
                }

if((member_array("up",exits)+1)&&(member_array("down",exits)+1)) {
                    desc += ", including up and down";
                }
            }
            i = 1;
        }
    }
    switch(j) {
    case 0: {
            if(i) {
                desc += ".";
            }
            break;
        }
    case 1: {
            if(i) {
                desc += ", and "+where->query_stair_name()+" leads
"+stairs[0]+".";
            } else {
                desc += "  "+capitalize(where->query_stair_name())+" leads
"+stairs[0]+".";
            }
            break;
        }
    default: {
            if(i) {
                desc += ", and "+where->query_stair_plural()+" lead up and
down.";
            } else {
                desc += "  "+capitalize(where->query_stair_plural())+"
lead up and down.";
            }
        }
    }
    if(FULL_ITEMS) {
        switch(i) {
        case 0: { break; }
        case 2: { where->add_spec_item(16); }
        default: { where->add_spec_item(15); }
        }
        switch(j) {
        case 0: { break; }
        case 2: { where->add_spec_item(18); }
        default: { where->add_spec_item(17); }
        }
    }
    where->set_long(desc);
    where->get_occupants();
    return where;
}

object find_room(int x,int y,int z) {
    object where;
    int number;
    string name;

    number = x + (y * DIMENSION) + (z * DIMENSION * DIMENSION);
    if(!loaded_rooms) { loaded_rooms = ([ ]); }
    where = loaded_rooms[number];
    if(where) {
        return where;
    }
    if(name = find_unique_room(x,y,z)) {
        load_object(name);
        loaded_rooms += ([ number : (where = find_object(name)) ]);
    return where;
}
where = construct_room(x,y,z,get_specs(x,y,z));
loaded_rooms += ([ number : where ]);
return where;
}

object seek_room(int x,int y,int z) {
    object where;
    int number;
    number = x + (y * DIMENSION) + (z * DIMENSION * DIMENSION);
    if(!loaded_rooms) { return 0; }
    where = loaded_rooms[number];
    return where;
}

void send_player_to(object who,int x,int y,int z) {
    who->move_player(find_room(x,y,z));
}

