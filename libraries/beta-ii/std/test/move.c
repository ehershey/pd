//	/std/move.c
//	from the Nightmare mudlib
//	handles the moving and removing of objects
//	created by Descarte of Borg 18 february 1993

#include <move.h>

static private int encumbrance, no_clean;
static private object last_location;

void set_weight(int x);
void set_no_clean(int x);
int clean_up();
void set_last_location(object ob);
int query_weight();
int move(mixed dest);
int remove();

int move(mixed dest) {
    object ob;
    string str;

    if(!this_object()) return MOVE_DESTRUCTED;
    if(stringp(dest)) {
    	ob = load_object(dest);
	if(!ob) {
	    str = catch(call_other(dest, "???"));
	    if(str) {
	        write(str+"\n");
	        return MOVE_NO_DEST;
	    }
	    ob = load_object(dest);
        }
    }
    else ob = dest;
    if(!ob) return MOVE_NOT_ALLOWED;
    if(!ob->receive_objects(this_object())) return MOVE_NOT_ALLOWED;
    if(living(this_object()) && living(ob) && !( (int)ob->move_ok() ))
	return MOVE_NOT_ALLOWED;
    if(!ob->add_encumbrance(encumbrance)) return MOVE_NO_ROOM;
    if(environment(this_object()))
	environment(this_object())->add_encumbrance(-encumbrance);
    set_last_location(environment(this_object()));
    move_object(ob);
    // (seeker) - Has it setup so when you enter a room with a living
    // thing on your hunters it automatically puts it on your attackers
    // list so you do not have a chance to cast another non-attack spell
    // on it like charge/stun etc..
    if (this_object()->is_living()) this_object()->clean_up_attackers(); 
    return MOVE_OK;
}

int remove() {
    object env;
    object *inv;
    int i;

    env = environment(this_object());
    if(env) {
	env->add_encumbrance(-encumbrance);
	i= sizeof(inv = all_inventory(this_object()));
        while(i--) inv[i]->move(env);
    }
    this_object()->unequip();
    destruct(this_object());
    return 1;
}

int clean_up() {
    object ob, env;
    object *inv;
    int i;

    if(no_clean) return 0;

    if (!this_object()) return 0;
    if(!(ob = this_object())) return 0;

    env = environment(ob);
 if(ob->is_player()) return 0;
 if (env)
    if (env->is_player()) return 0;
/*
      if (ob->query_auto_load()) return 0;
*/
    if(env) if(env->is_bag()) return 1;
    if(env) if(env->query_property("storage room")) return 1;

    if(!objectp(ob)) return 0;
    i = sizeof(inv = deep_inventory(ob));

    while(i--)
      if(interactive(inv[i])) return 1;

    if(!env) {
        if(i = sizeof(inv)) 
          while(i--) {
           inv[i]->remove();
            if(inv[i]) destruct(inv[i]);
          }
        if(ob) ob->remove();
        if(ob) destruct(ob);
        return 0;
    
    }
    if(living(env) && userp(env)) return 1;
    if(userp(ob)) {
        if(!interactive(ob)) return 1;
        else if(query_idle(ob) < 1800) return 1;
    }

    env->clean_up();
    if(ob) return 1;
    return 0;
}

void set_last_location(object ob) { last_location = ob; }

object query_last_location() { return last_location; }

void set_weight(int x) { encumbrance = x; }

int query_weight() { return encumbrance; }

void set_no_clean(int x) { no_clean = x; }
