#include <std.h>
#include <lidelas.h>
#include <daemons.h>
#include <clock.h>

#define SEC_TO_EXP  3

inherit ROOM;


#define OLD_LANGUAGES ({ "elvish", "giantish", "orcish", "artrellian", "mischief", "sensuous", "hobbitish", "pseudo-speak", "gnomish", "demonish", "hawaiian" })


mapping queue;

void create()
{
    ::create();
        queue = ([]);
        set_name("rafore street");
        set_short("Rafore Street");
        set_long("This is the inside of a large building that appears to serve as a library. The walls are covered with books that reach to the ceiling, and down to the floor. Many large torches are scattered around the library, burning fiercely. The floor is made of square marble tiles, the entire floor is made of them. The tiles reflect all the light of the torches, making the room seem very bright.");  
        set_properties(([ 
        "light"         :1,
        "night light"   :1, 
        "no steal"      :1, 
        "no bump"       :1, 
        "no magic"      :1, 
        "no attack"     :1, 
        "town"          :1, 
        "indoor"        :1, 
        "no teleport"   :1
        ]));

        set_items(([
    	"books"    :  "An almost infinite number of books line the walls."
	    ]));
	    set_listen("default", "There is only silence.");
	    set_smell("default", "The air is musty and stale..");
	    set_exits(([
        "west"		: ROOMS "lidelas005.c",
        ]));
        add_pre_exit_function("west", "leave_the_room");
        set_no_clean(1);
        set_heart_beat(1);

}


void init() {
  ::init();
  add_action("ask_sage", "ask");
  add_action("study_lang", "study");
}


int remove_old_lang(object ob) {
  string *langs;
  int i, szl;

  if(!function_exists("query_all_languages", ob))
    return 0;
  langs = ob->query_all_languages();
  for(i = 0, szl = sizeof(langs); i < szl; i++)
    if(member_array(langs[i], OLD_LANGUAGES) != -1)
      ob->remove_language(langs[i]);
  return 1;
}


void reset()
{
 ::reset();
 if (!present("sage")) 
   new(MOB "sage")->move(this_object());
}


int fix_languages() {
  write("The sage peers and you intently.");
  if(!remove_old_lang(this_player()))
  {
    write("The sage says: You need new flesh before I can help your mind.");
    return 1;
  }
  LANG_D->init_languages(this_player());
  write("The sage says: You have been healed, my " + 
        (((string)this_player()->query_gender() == "male") ? "son" :
         "daughter") + ".");
  return 1;
}


int ask_sage(string str)
{
  string trash;

  notify_fail("Ask who, what?\n");
  if(!str)
    return 0;
  if(sscanf(str, "sage%s", trash, trash) == 1)
    notify_fail("What do you want to ask the sage?\n");
  if(sscanf(str, "sage%sfix%s", trash, trash) == 2)
  {
    return fix_languages();
  }
  return 0;
}

int study_lang(string str)
{
  string lang;

  if(!str)
  {
    write("Study which language for how long?");
    return 1;
  }

  if(queue[this_player()])
  {
    write("The sage says: I cannot teach you two languages at once, my " +
          (((string)this_player()->query_gender() == "male") ? "son." : 
           "daughter."));
    return 1;
  }

  if(!function_exists("learn_language", this_player()))
  {
    write("The sage says: I am sorry, my " + 
          (((string)this_player()->query_gender() == "male") ? "son" : 
           "daughter") + ", but I cannot teach you in your current body.");
    return 1;
  }
  if((sscanf(str, "%s", lang) != 1) || (lang == ""))
  {
    write("Study which language for how long?");
    return 1;
  }
  
  lang = lower_case(lang);

  if(member_array(lang, (string *)(LANG_D->all_languages())) == -1)
  {
    write("The sage says: " + capitalize(lang) + " is not a language.  "
          "If you did not want to study languages, then you should leave now, my " +
          (((string)this_player()->query_gender() == "male") ? "son." :
           "daughter."));
    return 1;
  }

  if(this_player()->query_exp() < SEC_TO_EXP)
  {
    write("The sage says: You should go out and learn more about the world before "
          "wasting time with me.  Go and explore while you're still young, my " +
          (((string)this_player()->query_gender() == "male") ? "son." :
           "daughter."));
    return 1;
  }

  write("You begin studying " + capitalize(lang) + ".  You must stay here and"
        " study, and you will learn more the longer you wait.");
  queue[this_player()] = lang;

  return 1;
}


int leave_the_room()
{
  if(queue[this_player()])
  {
    write("You decide to quit studying and go do other things.");
    map_delete(queue, this_player());
  }
  return 1;
}

void heart_beat()
{
  object *ob;
  string lang;
  int i;

  ob = keys(queue);
  i = sizeof(ob);
  while(i--) {
    if(!ob[i]) {
      map_delete(queue,ob[i]);
      continue;
      }
    if(environment(ob[i]) != this_object())
    {
      if(ob[i])
        if(queue[ob[i]])
          map_delete(queue,ob[i]);
      continue;
    }

    lang = (string)queue[ob[i]];

    ob[i]->add_exp(-SEC_TO_EXP);
    ob[i]->learn_language(lang, 1);

    if(ob[i]->query_lang_prof(lang) >= 10) {
      message("info", "You decide that you have learned as much of this language as possible.", ob[i]); map_delete(queue, ob[i]);
    }
    if(ob[i]->query_exp() < SEC_TO_EXP) {
      message("info", "You find that you have used up your experience studying and decide take a break.", ob[i]);
      map_delete(queue, ob[i]);
    }
  }
}



