#include <std.h>
inherit OBJECT;

static int bp = 25;

void create() {
 ::create();
   set_name("mark");
   set_short("%^BOLD%^%^BLACK%^@%^WHITE%^)}-->---%^RESET%^%^RED%^ The mark of Cain %^BOLD%^%^WHITE%^---<--{(%^BLACK%^@%^RESET%^");
   set_long(@DARKONSETTE
%^BOLD%^%^BLACK%^           s,                                     .s
%^BOLD%^%^BLACK%^            ss,                                 .ss
%^BOLD%^%^BLACK%^            'SsSs,                           .sSsS'
%^BOLD%^%^BLACK%^             sSs'sSs,                     .sSs'sSs
%^BOLD%^%^BLACK%^              sSs  'sSs,               .sSs'  sSs
%^BOLD%^%^BLACK%^               sS,    'sSs,         .sSs'    .Ss
%^BOLD%^%^BLACK%^               'Ss       'sSs,   .sSs'       sS'
%^BOLD%^%^BLACK%^                sSs         ' .sSs'         sSs
%^BOLD%^%^BLACK%^                 sSs       .sSs' ..,       sSs
%^BOLD%^%^BLACK%^                  sS,   .sSs'%^RED%^  .  %^BOLD%^%^BLACK%^'sSs,   .Ss
%^BOLD%^%^BLACK%^                  'Ss .Ss'   %^RED%^  .    %^BOLD%^%^BLACK%^ 'sSs. ''
%^BOLD%^%^BLACK%^                   sSs '     %^RED%^  .    %^BOLD%^%^BLACK%^    'sSs,
%^BOLD%^%^BLACK%^               .sS.'sSs      %^RED%^  .    %^BOLD%^%^BLACK%^    .. 'sSs,
%^BOLD%^%^BLACK%^            .sSs'    sS,     %^RED%^.....  %^BOLD%^%^BLACK%^   .Ss    'sSs,
%^BOLD%^%^BLACK%^         .sSs'       'Ss     %^RED%^  .    %^BOLD%^%^BLACK%^   sS'       'sSs,
%^BOLD%^%^BLACK%^      .sSs'           sSs    %^RED%^  .    %^BOLD%^%^BLACK%^  sSs           'sSs,
%^BOLD%^%^BLACK%^   .sSs'____________________________ sSs ______________'sSs,
%^BOLD%^%^BLACK%^.sSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS'.Ss SSSSSSSSSSSSSSSSSSSSSs,
%^BOLD%^%^BLACK%^                        ...         sS'
%^BOLD%^%^BLACK%^                         sSs       sSs
%^BOLD%^%^BLACK%^                          sSs     sSs
%^BOLD%^%^BLACK%^                           sS,   .Ss
%^BOLD%^%^BLACK%^                           'Ss   sS'
%^BOLD%^%^BLACK%^                            sSs sSs
%^BOLD%^%^BLACK%^                             sSsSs
%^BOLD%^%^BLACK%^                              sSs
%^BOLD%^%^BLACK%^                               s
DARKONSETTE);
   set_id(({ "mark", "mark of cain", "v_mark_v" }));
   set_value(0);
   set_weight(0);
}
/*
void move() { if (!environment(this_object())->is_living()) ::move(); }

int query_bp() { return bp; }

void add_bp(int x) { bp += x; }

void set_bp(int x) { bp = x; }

int new_hp() {
   string tmp;
   tmp =  "%^BOLD%^%^RED%^hp%^RESET%^: "+this_player()->query_hp()+"/"
          +this_player()->query_max_hp()+"  ";
   tmp += "%^BOLD%^%^CYAN%^sp%^RESET%^: "+this_player()->query_sp()+"/"
          +this_player()->query_max_sp()+"  ";
   tmp += "%^BOLD%^%^MAGENTA%^mp%^RESET%^: "+this_player()->query_mp()+"/"
          +this_player()->query_max_mp()+"  ";
   tmp += "%^RED%^bp%^RESET%^: "+query_bp()+"/25";
   tmp += "%^BOLD%^%^BLUE%^level%^RESET%^: "+this_player()->query_level();
   write(tmp);
   return 1;
}

int my_bp() {
   write("%^RED%^bp%^RESET%^: "+query_bp()+"/25");
   return 1;
}

int vmp_help(string str) {
   if (!str) {
write(@ENDTEXT
%^BOLD%^%^WHITE%^Vampire Commands:%^BOLD%^%^BLACK%^
-----------------------------------------------------%^RESET%^
Gaze                 <gaze [living]>
Bloodrite            <bloodrite [player (sleeping)]>
Batform              <batform>
Blooddrink           <blooddrink [living]>
Bp                   <bp>
Hp                   <hp>
%^BOLD%^%^BLACK%^-----------------------------------------------------%^RESET%^
ENDTEXT);
   return 1;
   }
}

void init() {
 ::init();
   add_action("vmp_help", "vamplist");
   add_action("new_hp", "hp");
   add_action("my_bp", "bp");
}
*/
