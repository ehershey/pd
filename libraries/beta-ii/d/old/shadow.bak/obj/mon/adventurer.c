#include <std.h>
#include <shadow.h>
inherit MONSTER;

create() {
  ::create();
  set_name("adventurer");
  set_id( ({"adventurer","monster","man","hermit"}) );
  set_short("An old adventurer");
  set_level(30);
  set_long("This old man must have been quite a treasure hunter back in the
day."
    "  Now he has grown old and has retired, looking for someone to succeed
him");
  set_gender("male");
  set("race", "elf");
  set_alignment(300);
  set_body_type("human");
}

void catch_tell(string str) {
    object ob;
    string a, b;

    if(this_player() == (ob = this_object())) return;
    if(sscanf(str, "%suest%s", a, b) == 2) {
        this_object()->force_me("say Long ago I heard about a scroll of ancient wisdom that was written by the mages of Tenebrae.  If you find it, you will learn of their ancient power.  Unfortunately, I found that it has been locked away in the palace, accessable only to the king.");
        return;
    }
    if(sscanf(str, "%sking%s", a, b) == 2) {
        this_object()->force_me("say Only the king has access to to the ancient scroll.  But even HE needs an object to open the seal.");
        return;
    }
    if(sscanf(str, "%sobject%s", a, b) == 2) {
        this_object()->force_me("say I have heard that someone found the object...  I do not know what it was, but he was thrown into prison and I was unable to talk to him.");
        return;
    }
}
