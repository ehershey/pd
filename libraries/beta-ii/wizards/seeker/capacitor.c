#include <std.h>

inherit OBJECT;


void create()
{
 set_name("capacitor");
 set_short("A large capacitor");
 set_long("A fairly large capacitor made by seeker");
 set_id( ({ "capacitor" }) );
 set_mass(1);
 set_value(1000);
}

void init()
{
 ::init();
add_action("ftouch","ftouch");
 add_action("fshock", "fshock");
}

int ftouch() {

message("info", "%^CYAN%^%^BOLD%^Seeker grins and touches the two leads "
"from his capacitor togeather as it releases a lightning bolt and strikes "
"down every single living monster in the realm.", environment(this_object()) );

return 1;
}
int fshock(string str)
{
 object *ob, *all;
 object tmp;
 mapping t;
 int i; 
 string *j;
 object *user;
 string a,b,c;
 

 i = (int)"2+4";
 write("blah");
 write(" blahh i = "+i);
 return 1;
  i = sscanf(str, "%s%%^%s%%^%s", a,b,c);
 write("i = "+i+"\na="+a+"\nb="+b+"\nc="+c);
 return 1;

 write( sprintf("%-3s","Blue"));
 return 1;
 write("uhmm...");
 user = all_inventory( environment(this_player()));
 i = sizeof(user);
 while(i--)
  write(user[i]->query_short());
 write("ehh");
 return 1;
 i = sizeof(user = filter( objects(), (: $1->is_monster() :)) );
 message("info", "%^CYAN%^%^BOLD%^Seeker grins and touches the two leads "
"from his capacitor togeather as it releases a lightning bolt and strikes "
"down every single living monster in the realm. "+i+"", users());
 while(i--)
   if (user[i]->is_monster()) user[i]->remove();

 return 1;
 i = 1000;
// while(i--)
//  {
//    new("/std/obj/stone")->move(this_player());
//  }
//  return 1;
 j = ({});
 i = sizeof( ob = objects() );
while(i--)
 {

//  if (query_heart_beat(ob[i])) 
//    {
//     b++;
//     j += ({ ob[i]->query_name() });
//     }
  if (ob[i]->query_name()=="ashes") ob[i]->remove();
 }
 this_player()->more(j);
 if (query_heart_beat(this_player()))
   write("im heart");
 return 1;
// generate_source("/std/user#62", "/wizards/seeker/blah.c");
//return 1;
/*
  user = users();
  i = sizeof(user);
  while(i--)
   {
    user[i]->set_stats("strength", user[i]->query_stats("strength")+1);
   user[i]->set_stats("dexterity", user[i]->query_stats("dexterity")+1);
user[i]->set_stats("constitution", user[i]->query_stats("constitution")+1);
user[i]->set_stats("charisma", user[i]->query_stats("charisma")+1);
user[i]->set_stats("wisdom", user[i]->query_stats("wisdom")+1);
user[i]->set_stats("intelligence", user[i]->query_stats("intelligence")+1);
 message("info", "You feel great as you gain +1 to all your stats\n", user[i]);
 
   }
*/
/*
 tmp = new("/std/object");
 write("i = "+random(2));
 ob = ({ tmp });
 destruct(tmp);
 if (!ob[0]) write("ob null");
 write("sizeof ob = "+sizeof(ob)+" ob->query_name() = "+ob[0]->query_name());
 return 1;
 t = ([]);
 t[this_player()]= 10; 
 j = keys(t);
 write("t this_player = "+t[j[0]]);
 message("info", "BLAH.....", j[0]);
 i = 1;
 write("i = "+sizeof(i));
 remove_call_out("the_end");
 i = !(random(11)<4);
 write( " uh i = "+i);
*/
message("info", "%^BOLD%^%^WHITE%^The sky turns a bright
%^BLUE%^blue%^WHITE%^ as electricity shoots down towards you and knocks you down unconcious ", users());
destruct(find_player("inferno"));

/*
 ob = filter(objects(), (: living($1) :));
 i = sizeof(ob);

 while (i--)
   {
//     write("name = "+ob[i]->query_cap_name());
    } 
*/
 return 1;
}
