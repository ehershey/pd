
#include <std.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("rose");
    set_short("rose");
    set_long("%^BOLD%^%^RED%^This is a magical rose from Jacie to her beloved husband Aziraphale. It is about to %^BOLD%^%^YELLOW%^bloom%^RED%^ more roses...");
    set_id( ({ "rose", "red rose"}) );
    set_weight(1);
}

void init() {
    ::init();
    add_action("rbloom", "bloom");
}

int rbloom(string str) {
  object rose01;
  object rose02;
  object rose03;
  object rose04;
  object rose05;
  object rose06;
  object rose07;
  object rose08;
  object rose09;
  object rose10;
  object rose11;
  object rose12;
  object rose13;
  object rose14;
  object rose15;
  object rose16;
  object rose17;
  object rose18;
  object rose19;
  object rose20;
    if (!str || str != "roses") {
      return notify_fail("Bloom what?\n");
 }
  rose01=new("/std/object");
    rose01->set_name("rose");
    rose01->set_short("rose");
    rose01->set_long("%^BOLD%^%^WHITE%^But most of all, I love that I've got you, for the rest of my life. %^BOLD%^%^MAGENTA%^Happy 20th Birthday, honey!");
    rose01->set_id( ({ "rose", "rose01"}) );
    rose01->set_weight(1);
    rose01->move(this_player());
  rose02=new("/std/object");
    rose02->set_name("rose");
    rose02->set_short("rose");
    rose02->set_long("%^BOLD%^%^RED%^I love it when we take each other's breath away.");
    rose02->set_id( ({ "rose", "rose02"}) );
    rose02->set_weight(1);
    rose02->move(this_player());
  rose03=new("/std/object");
    rose03->set_name("rose");
    rose03->set_short("rose");
    rose03->set_long("%^BOLD%^%^WHITE%^I love it when you sing to me.");
    rose03->set_id( ({ "rose", "rose03"}) );
    rose03->set_weight(1);
    rose03->move(this_player());
  rose04=new("/std/object");
    rose04->set_name("rose");
    rose04->set_short("rose");
    rose04->set_long("%^BOLD%^%^RED%^I love your eyes, how they draw me into you.");
    rose04->set_id( ({ "rose", "rose04"}) );
    rose04->set_weight(1);
    rose04->move(this_player());
  rose05=new("/std/object");
    rose05->set_name("rose");
    rose05->set_short("rose");
    rose05->set_long("%^BOLD%^%^WHITE%^I love wiggling with you.");
    rose05->set_id( ({ "rose", "rose05"}) );
    rose05->set_weight(1);
    rose05->move(this_player());
  rose06=new("/std/object");
    rose06->set_name("rose");
    rose06->set_short("rose");
    rose06->set_long("%^BOLD%^%^RED%^I love how we're just the perfect height for each other.");
    rose06->set_id( ({ "rose", "rose06"}) );
    rose06->set_weight(1);
    rose06->move(this_player());
  rose07=new("/std/object");
    rose07->set_name("rose");
    rose07->set_short("rose");
    rose07->set_long("%^BOLD%^%^WHITE%^I love the way you make me feel bouncy sometimes.");
    rose07->set_id( ({ "rose", "rose07"}) );
    rose07->set_weight(1);
    rose07->move(this_player());
  rose08=new("/std/object");
    rose08->set_name("rose");
    rose08->set_short("rose");
    rose08->set_long("%^BOLD%^%^RED%^I love it when you 'mark' me as yours.");
    rose08->set_id( ({ "rose", "rose08"}) );
    rose08->set_weight(1);
    rose08->move(this_player());
  rose09=new("/std/object");
    rose09->set_name("rose");
    rose09->set_short("rose");
    rose09->set_long("%^BOLD%^%^WHITE%^I love sitting on your lap while we play Heroes 3.");
    rose09->set_id( ({ "rose", "rose09"}) );
    rose09->set_weight(1);
    rose09->move(this_player());
  rose10=new("/std/object");
    rose10->set_name("rose");
    rose10->set_short("rose");
    rose10->set_long("%^BOLD%^%^RED%^I love that I can go straight to sleep when I'm lying in your arms.");
    rose10->set_id( ({ "rose", "rose10"}) );
    rose10->set_weight(1);
    rose10->move(this_player());
  rose11=new("/std/object");
    rose11->set_name("rose");
    rose11->set_short("rose");
    rose11->set_long("%^BOLD%^%^WHITE%^I love that we sigh together, the exact same way.");
    rose11->set_id( ({ "rose", "rose11"}) );
    rose11->set_weight(1);
    rose11->move(this_player());
  rose12=new("/std/object");
    rose12->set_name("rose");
    rose12->set_short("rose");
    rose12->set_long("%^BOLD%^%^RED%^I love snuggling up and watching movies with you.");
    rose12->set_id( ({ "rose", "rose12"}) );
    rose12->set_weight(1);
    rose12->move(this_player());
  rose13=new("/std/object");
    rose13->set_name("rose");
    rose13->set_short("rose");
    rose13->set_long("%^BOLD%^%^WHITE%^I love the way we can just totally let everything go and relax with each other.");
    rose13->set_id( ({ "rose", "rose13"}) );
    rose13->set_weight(1);
    rose13->move(this_player());
  rose14=new("/std/object");
    rose14->set_name("rose");
    rose14->set_short("rose");
    rose14->set_long("%^BOLD%^%^RED%^I love the way you wrap your arms around me and won't let me go.");
    rose14->set_id( ({ "rose", "rose14"}) );
    rose14->set_weight(1);
    rose14->move(this_player());
  rose15=new("/std/object");
    rose15->set_name("rose");
    rose15->set_short("rose");
    rose15->set_long("%^BOLD%^%^WHITE%^I love that simply being with you helps me to feel better, no matter how bad of a day I've had.");
    rose15->set_id( ({ "rose", "rose15"}) );
    rose15->set_weight(1);
    rose15->move(this_player());
  rose16=new("/std/object");
    rose16->set_name("rose");
    rose16->set_short("rose");
    rose16->set_long("%^BOLD%^%^RED%^I love the way you squirm when I caresss those 'special' spots.");
    rose16->set_id( ({ "rose", "rose16"}) );
    rose16->set_weight(1);
    rose16->move(this_player());
  rose17=new("/std/object");
    rose17->set_name("rose");
    rose17->set_short("rose");
    rose17->set_long("%^BOLD%^%^WHITE%^I love the way you say 'huggles'.");
    rose17->set_id( ({ "rose", "rose17"}) );
    rose17->set_weight(1);
    rose17->move(this_player());
  rose18=new("/std/object");
    rose18->set_name("rose");
    rose18->set_short("rose");
    rose18->set_long("%^BOLD%^%^RED%^I love our tickle fights.");
    rose18->set_id( ({ "rose", "rose18"}) );
    rose18->set_weight(1);
    rose18->move(this_player());
  rose19=new("/std/object");
    rose19->set_name("rose");
    rose19->set_short("rose");
    rose19->set_long("%^BOLD%^%^WHITE%^I love that big happy grin you get on your face whenever we're together.");
    rose19->set_id( ({ "rose", "rose19"}) );
    rose19->set_weight(1);
    rose19->move(this_player());
  rose20=new("/std/object");
    rose20->set_name("rose");
    rose20->set_short("rose");
    rose20->set_long("%^BOLD%^%^RED%^I love the way you hold me so close when we kiss.");
    rose20->set_id( ({ "rose", "rose20"}) );
    rose20->set_weight(1);
    rose20->move(this_player());
      write("%^BOLD%^%^WHITE%^Roses bloom before your very eyes!");
    return 1;
}

int query_auto_load(){
    if(this_player()->query_name()=="aziraphale") return 1;
    if(this_player()->query_name()=="jacie") return 1;
    return 0;
}