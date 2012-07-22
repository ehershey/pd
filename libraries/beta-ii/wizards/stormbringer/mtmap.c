#include <std.h>
inherit OBJECT;
void create() {
    :: create();
    set_name("old map");
    set_short("mountain map");
    set_long("A map of the mountains\n\n"
      "type 'view' to view it");
    set_id(({"map"}));
    set_mass(0);
    set_value(0);
}
void init()
{
    ::init();
    add_action("cmd_view", "view");
}
int cmd_view(string str)
{
    if (!str || str=="") return 0;
    if (str!="map") return 0;
    write( @EndText
                                                            
                                  ^                       ^  
                                  |                       |                 
                        OO        O-O               O-O   O               
                       /  \          \             /   \  |                   
                O-O-O-O    O          O     O-O-O-O     O O   OO          
To             /       \   |          |\   / /     \   /  |\ /  \       
Lodos     O-O-O         O  O   O-O-v  O O-O O       O-O-O O O    O       
|        /   /|         |   \ /        \    |      /  |   |  \    \          
O OO    O   O O         O    O     ^    O-O-O-O   O   O   O-O-O-O  OO     OO
|/  \  /   /   \       /     |     \   /       \ /     \        |\/  \   /  \ 
O    OO   O     O     O      O      O-O         v       v O-O   O O   OOO    OO 
 \     \  |     |     |       \     | |        /         /   \ /   \     \     \  
  O     O O     O     O        O    O O       O ^     v ^     O   OO      OO    O 
  |      \|     |      \       |     \ \     /   \   / / \    |  /  \    /  \   | 
  O       O     O       O-O-O-OO      O O-O O     O-O ^   O   O O    OOOO    O-OO-T
  |       /\    |              /\     |    �      |   |    \   \|    /   \    / |
  O      O  O-O-O     O-O     O  O    O   O O     O   v     O   O   OOO   OO-O  O 
 /      /  /    |\   /   \   /   |   /   /   \    |          \  |  /   \ /  /  /  
O      O  O     O O-O     O-O    v  O-O-O     O-O-O   ^       O-OOO     O  O-OO 
|      |  |      \       /              |      /      |            \    | /      
O      O-OO       O   O-O        ^      O-O-O-O       O             OOO-OO    
 \    /   |      / \ /           |     /              |                          
  O-OO    O     O   O O-O        O  O-O               O-O                       
  |      /      |   |/   \       | /                 /  |                     
O-O      O      O   O     O-O    OO                 O-O-O                        
|  \    /      /   /        |                        \ /                        
O   OO O    O-O   O         O                         v
|  /  \|   /     /         /                               
O O    OO-O-O-O-O     O-O-O  
|/               \   /    |   
O                 O-O     O 
|                        /  
To                      O   
Tenebrae                |   
                        v   
 
EndText );
    return 1;
}
int query_auto_load() { return 1; }
