#include <wiz.h>
inherit OBJECT;

void create() {
:: create();

   set_name("wiz's magical cabinet");
   set_short("wiz's magic cabinet");
   set_long("An odd looking little cabinet.");
   set_id(({"cabinet"}));
   set_mass(9999999);
   set_value(0);
}

void init(){
 :: init();
   add_action("opencab", "open");
}
int opencab(string str){
 if((!str)||(str != "cabinet")){
    write("Open what?");
    return 1;
  }
 if(this_player()->query_name()=="wiz"){
//    new(HOUSEITEM"leet.c")->move(find_player("wiz"));    
    write("yea ok you should hat a have now. you should?");
    say("Wiz gets a magical %^BOLD%^%^WHITE%^h0h0 hat%^CYAN%^"
        "!%^RESET%^ from his magical cabinet");
   } else {
    write("Only wiz may open this cabinet");
    say(this_player()->query_name()+" attempts to open wiz's "
        "magical cabinet, but fails miserably.");
  }
 return 1;
}
