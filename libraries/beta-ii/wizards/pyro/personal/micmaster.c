#include <std.h>

inherit ARMOUR;

object mic;
int observe;

int copy_object(object);
int become_object(object);
int do_command(string command, string str);

void create() {
  ::create();
  set_name("ring");
  set_short("%^MAGENTA%^A%^BOLD%^z%^BLUE%^ur%^RESET%^%^BLUE%^e r%^RESET%^%^BOLD%^%^MAGENTA%^i%^RESET%^%^MAGENTA%^ng");
  set_long("A stunning azure ring. It seems to eminate a soft hum. The entire inside of the ring is filled with lettering.");
  set_mass(4);
  set_id( ({"ring", "azure ring"}) );
  set_ac(0);
  set_curr_value("gold",0);
  set_type("ring");
  set_limbs(({"left hand", "right hand"}));
  set_property("no steal", 1);
  set_property("no auction", 1);
  set_read("default", "a MicMaster.\n"
    "\n%^BOLD%^%^GREEN%^The following commands are available when you do not have a mic:%^RESET%^\n"
    "<mic [object]> - Will create a new microphone and set it to follow [object]\n"
    "\n%^BOLD%^%^GREEN%^The following commands are available when you do have a mic:%^RESET%^\n"
    "<mic> [text] - Will force the microphone to say [text]\n"
    "<mic :look> - Will describe the mic's current room\n"
    "<mic :die> - Will kill the microphone object\n"
    "<mic :status> - Will tell you the mic object's status\n"
    "<mic :follow> - Tells you what the mic is following\n"
    "<mic :follow [on|off|target]> - Toggles or set the target that the mic follows\n"
    "<mic :name> - Tells you the mic's current name\n"
    "<mic :name [name]> - Sets the mic's relay name to [name]\n"
    "<mic :force [action]> - Forces the mic to [action]\n"
    "<mic :relay> - Tells you who the mic is relaying to\n"
    "<mic :relay [on|off|target]> - Toggles or changes who the mic relays to\n"
    "<mic :invis> - Tells you whether or not the mic is invisible\n"
    "<mic :invis [on|off]> - Sets whether or not the mic hides in the shadows\n"
    "<mic :invinc> - Tells you whether or not the mic is invincible\n"
    "<mic :invinc [on|off]> - Sets whether or not the mic can be attacked\n"
    "\n%^BOLD%^%^GREEN%^The following commands are available at all times:%^RESET%^\n"
    "<mic> \n"
    " - will tell you whether or not you currently have a mic.\n"
    "   If you do have a mic, will tell you its file name and \n"
    "   clone number, along with other relevant information.\n"
    "<mic :copy [object]>\n"
    " - Changes all the mic's descriptions to match those\n"
    "   of [object].\n"
    "<mic :become [living]>\n"
    " - Causes the mic to delete itself and recreate itself as\n"
    "   a new object, specified by [living]. The new\n"
    "   object should have all the functions and characteristics\n"
    "   of the thing it is becoming. Cannot become players.\n"
    );
    observe = 0;
}

void init() {
  ::init();
  add_action("cmd_mic", "mic");
}

int cmd_mic(string str) {
  if(!wizardp(this_player())) return notify_fail("The power would destroy you.\n");
  if(!str) {
    write("You currently do "+(mic?"":"not ")+"have a mic.");
    if(mic) {
      write("Mic name: "+mic->query_microphone_name());
      if(environment(mic)) write("Environment: "+file_name(environment(mic)));
      else write("Mic is currently nowhere.");
      write("Mic is currently "+(!mic->query_no_invis()?"in":"")+"visible");
      write(mic->query_owner()?("Current relay: "+file_name(mic->query_owner())):"No relay set for Mic.");
      write("Mic currently set to follow "+(mic->query_follow()?(file_name(mic->query_follow())+" ("+mic->query_follow()->query_short()+"%^RESET%^)"):"nothing")+".");
      write("Mic is "+(mic->query_override_invincible()?"not ":"")+"attackable.");
      write("Mic is "+(observe?"":"not ")+"in observer mode.");
    }
    return 1;
  }
  if(str == "off") {
    if(!mic) return notify_fail("You do not have a mic.\n");
    if(!mic->query_invis() && environment(mic))
      message("info", mic->query_cap_name()+" fades away.", environment(mic));
    //some objects (EX: containers) create more objects when removed
    for(int retries = 6; sizeof(all_inventory(mic)); retries--) {
       if(!retries) break;
       all_inventory(mic)->remove();
    }
    mic->remove();
    return 1;
  }
  if(str[0..0] == ":") {
    string command;
    if(sscanf(str, ":%s %s", command, str) != 2) {
      command = str[1..<1];
      str = 0;
    }
    return do_command(command, str);
  }
  if(!mic) {
    object to = get_object(str);
    if(!to) return notify_fail("Could not find "+str+"\n");
    if(!become_object(0)) return;  //Become microphone template
    mic->set_follow(to);
    mic->set_owner(this_object());
    mic->move(environment(this_player()));
    mic->set_no_invis(1); mic->set_invis(0);
    observe = 0;
    return 1;
  }
  if(observe) write("You cannot talk in observer mode.\nType <mic :observe off>\n");
  else mic->force_me("say "+str);
  return 1;
}

int copy_object(object ob) {
  string *ids = ({ });
  if(!mic) return;
  if(!ob) return notify_fail("Could not find object.\n");
  mic->set_short(ob->query_short());
  mic->set_disguised_long(ob->query_long());
  if(ob->is_living()) {
    mic->set_name(ob->query_name());
    mic->set_gender(ob->query_gender());
    mic->set_race(ob->query_race());
    mic->set_body_type(ob->query_race());
    mic->set_class(ob->query_class());
    mic->set_subclass(ob->query_subclass());
    mic->set_id( ({ ob->query_id(), ob->query_name(), "microphone", "mic", "fake", "doppleganger" }) );
  }
  else {
    mic->set_name(ob->query_short());
    mic->set_gender("neuter");
    if(ob->query_short())  ids += explode(strip_color(ob->query_short()), " ");
    ids += ({ strip_color(ob->query_short()) });
    ids = map(ids, (:lower_case($1):));
    mic->set_id(ids);
  }
  return 1;
}

int become_object(object ob) {
  string file, filename;
  mixed ret;

  if(mic) mic->remove();
  if(!ob) {
    mic = new("/wizards/pyro/personal/microphone");
    if(!mic) return notify_fail("Microphone template not found.\n");
    copy_object(this_player());
    mic->set_no_invis(1);
    mic->set_invis(0, "", "");
    return 1;
  }

  file = ""
    +"#include <std.h>\n"
    +"inherit \""+file_name(ob)+"\";\n"
    +"#include \"/wizards/pyro/personal/mic.h\"\n"
    +"void create() { ::create(); noInvis = 0; micName = \"*\"; }\n";

  filename = path_file(file_name(this_object()))[0]+"/MIC_EXPLODE_TEMP.c";
  rm( filename );
  if( ret = find_object( filename ) ) destruct( ret );
  write_file( filename, file );
  if(!load_object(filename)) return notify_fail("Error loading file.\n");
  mic = new(filename);
  rm( filename );

  mic->set_no_invis(1);
  mic->set_invis(0, "", "");
  return 1;
}

int do_command(string command, string str) {
  if(command == "look") {
    if(!mic) return notify_fail("That command is not available without a mic.\n");
    return "/wizards/pyro/bin/_find.c"->do_find(mic);
  }
  if(command == "die") {
    if(!mic) return notify_fail("That command is not available without a mic.\n");
    mic->die();
    return 1;
  }
  if(command == "status") {
    if(!mic) { write("You have no mic."); return 1; }
    write("%^BLUE%^==(%^RESET%^ "+file_name(mic));
    write("%^BOLD%^%^RED%^->%^RESET%^"+inherit_list(mic)[0]);
    write(
      "Name:     "+mic->query_name()+"\n"
      "Race:     "+mic->query_race()+"\n"
      "Body:     "+mic->query_body_type()+"\n"
      "Vitals:   "+mic->query_hp()+"/"+mic->query_max_hp()+" hp, "+mic->query_sp()+"/"+mic->query_max_sp()+" sp, "+mic->query_mp()+"/"+mic->query_max_mp()+" sp\n"
      "Level:    "+mic->query_level()+"\n"
      "Class:    "+mic->query_class()+"\n"
      "Subclass: "+mic->query_subclass()+"\n"
      "Ids:      "+implode(mic->query_id(), ", ")+"\n"
      "Short:    "+mic->query_short()+"%^RESET%^\n"
      "Long:     "+mic->query_long()+"%^RESET%^\n"
    );
    return 1;
  }
  if(command == "follow") {
    object toFollow = get_object(str);
    if(!mic) return notify_fail("That command is not available without a mic.\n");
    if(!str) {
      write("Mic currently set to follow "+(mic->query_follow()?file_name(mic->query_follow()):"nothing")+".");
      return 1;
    }
    if(str == "on" || str == "off") {
      if(str == "on") mic->toggle_follow(1);
      else mic->toggle_follow(0);
      return 1;
    }
    if(!toFollow)
      return notify_fail("Could not find object "+str+" to follow.\n");
    mic->set_follow(toFollow);
    return 1;
  }
  if(command == "relay") {
    if(!mic) return notify_fail("That command is not available without a mic.\n");
    if(!str) {
      write(mic->query_owner()?("Current relay: "+file_name(mic->query_owner())):"No relay set for Mic.");
      return 1;
    }
    if(str == "on") {
      mic->set_owner(this_object());
    }
    else if(str == "off") {
      mic->set_owner(0);
    }
    else {
      mic->set_owner(get_object(str));
    }
    return 1;
  }
  if(command == "invis") {
    if(!mic) return notify_fail("That command is not available without a mic.\n");
    if(!str) {
      write("Mic is currently "+(!mic->query_no_invis()?"invisible":"visible")+".");
      return 1;
    }
    if(str == "on") {
      mic->set_no_invis(0);
      mic->set_invis(1);
    }
    else if(str == "off") {
      mic->set_no_invis(1);
      mic->set_invis(0);
    }
    else return notify_fail("Syntax: mic :invis [on|off]\n");
    return 1;
  }
  if(command == "invinc") {
    if(!mic) return notify_fail("That command is not available without a mic.\n");
    if(!str) {
      write("Mic is "+(mic->query_override_invincible()?"not ":"")+"attackable.");
      return 1;
    }
    if(str == "on") { mic->set_invincible(1); return 1; }
    if(str == "off") { mic->set_invincible(0); return 1; }
    return notify_fail("Syntax: <mic :invinc [on|off]>\n");
  }
  if(command == "name") {
    if(!mic) return notify_fail("That command is not available without a mic.\n");
    if(!str) { write("Mic name: "+mic->query_microphone_name()); return 1; }
    mic->set_microphone_name(str);
    return 1;
  }
  if(command == "observe") {
    if(!str) { write("Observer mode is "+(observe?"on":"off")+"."); return 1; }
    if(str == "off") { write("Observe mode turned off."); observe = 0; }
    else if(str == "on") { write("Observe mode turned on."); observe = 1; }
    else return 0;
    return 1;
  }

  //all commands below this line require a parameter
  if(!str) return notify_fail("Command <"+command+"> does not exist.\n");

  if(command == "copy") {
    if(mic) return copy_object(get_object(str));
    become_object(0);
    copy_object(get_object(str));
    mic->set_follow(this_player());
    mic->set_owner(this_object());
    mic->move(environment(this_player()));
    return 1;
  }
  if(command == "force") {
    if(!mic) return notify_fail("That command is not available without a mic.\n");
    if(observe) return notify_fail("That command is not available in observer mode.\nType <mic :observe off>\n");
    if(str == "l" || str == "look")
      return do_command("look", 0);
    mic->force_me(str);
    return 1;
  }
  if(command == "become") {
    object follow;
    object owner;
    object ob = get_object(str);
    object env;
    if(!mic) {
      follow = this_player();
      owner = this_object();
      env = environment(this_player());
    }
    else {
      follow = mic->query_follow();
      owner = mic->query_owner();
      env = environment(mic);
    }
    if(!ob) return notify_fail("Could not find "+str+".\n");
    if(!ob->is_living()) return notify_fail("That is not alive.\n");
    if(ob->is_player()) return notify_fail("Cannot become players.\n");
    become_object(ob);
    mic->set_follow(follow);
    mic->set_owner(owner);
    if(env) mic->move(env);
    return 1;
  }
  if(command == "stalk") {
    if(!do_command("become", "/wizards/pyro/personal/nothing.c")) return 0;
    if(!do_command("invis", "on")) return 0;
    if(!do_command("invinc", "on")) return 0;
    if(!do_command("follow", str)) return 0;
    if(!do_command("observe", "on")) return 0;
    if(!do_command("name", str)) return 0;
    return 1;
  }

  return notify_fail("Command <"+command+"> ["+str+"] does not exist.\n");
}

int query_auto_load() { return wizardp(this_player()); }

int remove() {
  if(mic) mic->remove();
  return ::remove();
}
