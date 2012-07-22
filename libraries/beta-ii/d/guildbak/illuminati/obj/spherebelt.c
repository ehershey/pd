#include <std.h>
#include <illuminati.h>

inherit PACK;

mapping spheres;

void create() {
   ::create();

     set_id( ({ "belt", "star belt" }) );
     set_name("star belt");
     set_short("%^RESET%^BLUE%^S%^BOLD%^ta%^YELLOW%^r B%^BLUE%^el%^RESET%^BLUE%^t%^RESET%^");
     set_long("The Star Belt is made from a soft, blue material that is strong, but somehow soft and flexible. There are many golden 'stars' which are used to magically hold Illuminati spheres.");
     set_curr_value("gold", 350+random(25));
     if(!spheres)
       spheres = ([ ]);
     else
       create_spheres();
}

void init() {
   ::init();
     add_action("put_in", "put");
     add_action("get_out", "get");
}

int put_in(string str) {
    string thing, bag;
    object ob;
    int ok;
    if(stringp(str) && sscanf(str,"%s in %s", thing, bag) != 2)
      return notify_fail("Put what where?");
    if(present(bag, this_player()) != this_object())
      return notify_fail("Put what where?");
    if(!ob = present(thing, this_player()))
      return notify_fail("Put what where?");
    if(!ob->is_sphere())
      return notify_fail("The belt can only be used to hold spheres.\n");
    if(ok = put_into(str))
      add_sphere(ob);
    return ok;
}

int get_out(string str) {
    object old_sphere;
    string thing, where;
    int ok;
    if(sscanf(str, "%s from %s", thing, where) != 2)
      return notify_fail("Get what from where?");
    if(present(where, this_player()) != this_object())
      return notify_fail("Get what from where?");
    if(!old_sphere = present(thing, this_object()))
      return notify_fail("There is no "+thing+" in your Star Belt.\n");
    if(ok = get_from(str))
      remove_sphere(old_sphere);
    return ok;
}

void add_sphere(object sphere) {
     spheres[file_name(sphere)] = sphere->query_props();
}

void remove_sphere(object sphere) {
     map_delete(spheres, file_name(sphere));
}

int create_spheres() {
    int i;
    object tmp;
    string *_keys, tmp2;
    _keys = keys(spheres);
    i = sizeof(_keys);

    while(i--) {
      tmp = new(ILOBJ"sphere.c");
      tmp2 = _keys[i];
      tmp->init_arg(spheres[tmp2]);
      tmp->move(this_object());
      map_delete(spheres, tmp2);
      }

    return 1;
}

string query_long() {
       if(this_player() && this_player()->query_guild() != "illuminati")
         return "A most fashionable blue belt with a star pattern.";
       else
         return ::query_long();
}

string query_type() {
       return "belt";
}

int query_ac() {
    return 2;
}

mixed *query_auto_load() {
    if(this_player()->query_level() >= 25 && this_player()->query_guild() == "illuminati")
      return ({ ILOBJ"spherebelt.c", spheres });
    else
      return 0;
}

void init_arg(mapping stuff) {
     spheres = stuff;
}
