#ifndef __SKY__H__
#define __SKY__H__

string *ocean_map = ({
  "########################################################################################################################################################",
  "###############----------------###########---------------#################################################------########---------#######################",
  "---########-------##------------######----------##---------##############------------###################-----------##----------#----###############-----",
  "-------#####----------------------##-------------#------------########-----------------#############-----######----------------###------#######---------",
  "------------------------------------------------------------------#####-------------###########---------########-----------------#----------------------",
  "----------------------------------------------------------------------------------------------------++++++++++++++------------------------------+-------",
  "------------------------------------------------------------------------------------------------+++++++++++++++++++++-----------------------------+-----",
  "----------------------------------------------------------------------------------------------++++++++++++++++++++++++++--------------------------++----",
  "--------+++--++++--------------------+++-------------------------------------------------------++++++++++++++----++++++++--------------------------+----",
  "---------+++++++++++------------++++++++++-----+++----------------------------------------------++++++++++++------+++++++--------++----------------++---",
  "---------+++++++++++++++-----+++++++++++++++--+++------------------------------------------------++++++++++-------++++++--------+-------------------+---",
  "--------++++++++++++++++++--++++++++++++++++++++J+------------++------------------------------------++++++++------+++++-------------------------------+-",
  "--------++++++++++++++++++++++++++++++++++++++++++----------+++++---------------------------------------+++++----++++----------------------+++----------",
  "---------++++++++++++++++++++++++++++++++++++++++---------++++++++------------------------------+---------+++----------------------------++++++---------",
  "---------++++++Q+++++++++++++++++++++++++++++++----------++++++++--------------------------------++---------++--------------------------+++++++---------",
  "----------++++++++++++++++++++++++++++++++++++-----------+++++++---------------------------------+++---------++------------------------+++++++++--------",
  "-----------+++++++++++++++++++++++++++++++++++------------++++++++-------------------------------+------------+-----------------------++++++++----------",
  "------------++++++++L+E+++++++++++++++++++++++++-----------+++++++--------------------------------------------------------------------+++++++-----------",
  "------------++++++++++++++++++++O++++++++++++++++-----------+++++++----------------------------------------++--------------------------+++++++----------",
  "-----------+++++++++++++++++++++++++++++++++++++--------------++++---------------------------------------+++-----+-----------------------+++++----------",
  "-----------++++++++++++++++++++++++++++++++++++++--------------+H+-----------------------------------++++++++------+-----------------------++++---------",
  "---------+++++++++++F+++++++++++B+++D+++++++++++++-------------------------------------------------+++++++++++------++-----------------------+++--------",
  "--------++++++++++++++++++++++C+++++++++N++++++++++-----------------------------++-------------+++++++++++++++++-----+++----------------------+---------",
  "-------+R+++------++++++-----+++S+++--+------+++++++-------------------------+++--------------+++++++++++++++++++----++++++-----------------------------",
  "--------+++------------------------------------+++++-----------------------++++---------------+++++++++++++++++++++++++++++++----------------+----------",
  "------------------------------------------------+++-----------------------++-----------------+++++++++++++++++++++++++++++++++++------------------------",
  "-------------------------------------------------+-------------------------------------------+++++++++++++++++++++++++++++++++++++----------------------",
  "--------------------------------------------------------------------------------------------++++++++++++++++++++++++++++++++++++++----------------------",
  "-----++---T+++-------------------------------------------------------------------------------++++++++++++++++++++++++++++++++++++-----------------------",
  "----+++++++++++--------------------------------------------------------------------------------++++++++++++++++++++++++++++++++++-----------------------",
  "----+++++++++++----------------------------------++----------------------------------------------+++++++++++++++++++++++++++++++---------------+--------",
  "-------++++++++------------------------+---------+-----------------------------------------------+++++++++++++++++++++++++++++++--+------------++-------",
  "------------++-------------------------+-------------------------+------------------------++--+++++++++++++++++++++++++++++++++++++------------+++------",
  "---------------------------------------+-------------------------++------------------------+++++++++++++++++++++++++++++++++++++++----------------+-----",
  "---------------------------------------+--------------------------++------------------------+++++++++++++++++++++++++++++++++++++-----------------------",
  "----------+++--------------------------+---------------------------++--------------------------++++++++++++++++++++++++++++++++------------------+------",
  "-----+++++++++-------------------------------------------------+----I+---------------------------+++++++++++++++++++++++++++-----+--------------+--------",
  "----+++++++++++-----------------------------------------------+++---------------------------------+++++++++--------+++++++-----++++---------------------",
  "----+++++++++++---++-----++----------------------------------+++++----------------------------------+++++-------------++------++----------------+-------",
  "-----+++++++G+----+++-++--+----------------------------------++++-------------------------------------------+++-------------++++------------------------",
  "-----++++++++------------------------------+++------------++++++++-----------------------------------------++++-----------+++++++-----------------------",
  "--------++++-----++--++-----------------+++++++++-------+++++++++-----------------------+-----------------+++-------+----++++++++++---------------------",
  "-----------------+-----------++++----++++++++++++++---++++++++++++-----------------------+-----------------++-------+++--++++++++++++-------------------",
  "----------------------------+++++++++++++++++++++++++++++++++++++++-----------------------+----------------------+++++++++++++++++++++----------+-------",
  "---------------------------+++++++++++++++++++++++++++++++++++++++------------------------++----------------------++++++++++++++++++-----------++-------",
  "----------------------------++++++++++++++++++++++++++++++++++++++------------------------++--------------------++++++++++++++++++------------++++------",
  "----------------------------++++++++++++++++++++++++++++++++++++------------------------+++------------------+--++++++++++++++++++------------++++------",
  "---------------------------+++++++++++++++++++++++++++++++++++--------------------------++------------------+++++++++++++++++++++-------------+++++-----",
  "---------------------------++++++++++++++++++++++++++++++++++++------------------------+-------------------+++++++++++++++++++++---------------++++-----",
  "---------++M----------------++++++++++++++++++++++++++++++++++++-------------------------------------------+----++++++++++++-+--------+---------++++----",
  "--------++++----------------+++++++++++++++++++++++++++++++++++++-----------------------------------------------+++++++++++----------+++---------+++----",
  "-------++++------------------+++++++++++++++++++++++++++++++++++++----------------------------------------------++++++++++++--------+++-----------+++---",
  "-------+++-------------------++++++++++++++++++++++++++++++++++++----------------------------------------------++++++++++++-------------------------+---",
  "-------++++------------------++++++++++++++++++++++---------+++++++-------------------------------------------++++++++++++------------------------------",
  "--------++--------------------++++++++++++++++++++-------------++++------------------------------------------++++++++-++++------------------------------",
  "-------------------------------++++--+++++++++++-----+++--------++-----------------------------------------+++++++----++++------------------------------",
  "--------------------------------+++----++++++++-----+++--------+-----------------------------------------++++++---------++------------------++----------",
  "-----------------------------------------++++++------+++------------------------------------------------++++--------------------------------++-----------",
  "-------------------------------------------+++++------------------------------------------------------------------------------------------+-------------",
  "---------------------------------------------++++----------------------------------------------------------------------------------------+--------------",
  "--------------------------------------------------------------------------------------------------------------------------------------------------------",
  "--------------------------------------------------------------------------------------------------------------------------------------------------------",
  "-----------------------------------------------------------------------------------------------------------------------##------------#------------------",
  "-------------------#-----------------------------------------#-------------------#####--------###--------------------######--------##-------------------",
  "----##-------------##-----------#####------------------------##-----------###############------###--------------##############---------#########--------",
  "--#####------###-------------############----------######-------------######################-------------------#######################################--",
  "########################################################################################################################################################",
});
/*
   +-------------------+
   |        Key        |
   +-------------------+
   |                   |
   | land           +  |
   | water          -  |
   | Ice            #  |
   | Storm Clouds   %  |
   +-------------------+
*/
#define ROOMS ([ \
               "A":(["name":"Aekari", "room":""]), \
               "C":(["name":"outside Tirun", "room":""]), \
               "D":(["name":"Citrin Forest", "room":""]), \
               "E":(["name":"Distopia", "room":"", "airport":""]), \
               "F":(["name":"the desert", "room":""]), \
               "G":(["name":"Merkkirri", "room":"/d/freepk/merkkerri/jungle/merkkirri/mjungle1"]), \
               "H":(["name":"Purgatory", "room":"/d/freepk/purgatory/room/landing"]), \
               "I":(["name":"Rhondale", "room":"/d/freepk/rhondale/rooms/zvillage/[].c"]), \
               "J":(["name":"Helgrath", "room":"/d/helgrath/rooms/wilndursquare"]), \
               "K":(["name":"Helves", "room":""]), \
               "L":(["name":"Lodos", "room":"/d/lodos/square"]), \
               "M":(["name":"an island", "room":""]), \
               "N":(["name":"Arlon", "room":"/d/nopk/arlon/room/square"]), \
               "O":(["name":"Elven Village", "room":"/d/nopk/standard/rain_forest/corinthor/rooms/square"]), \
               "P":(["name":"near Tirun", "room":""]), \
               "Q":(["name":"Roston", "room":"/d/roston/rooms/roston"]), \
               "R":(["name":"Tenebrae", "room":"/d/shadow/rooms/tene10"]), \
               "S":(["name":"Tirun", "room":"/d/nopk/tirun/square", "airport":"/d/nopk/tirun/airdock"]), \
               "T":(["name":"Dunsinane", "room":"/wizards/powerman/room/patha"]), \
              ])

static int MAX_OCEAN_X = sizeof(ocean_map[0]);
static int MAX_OCEAN_Y = sizeof(ocean_map);
#define ZERO ({ 34, 31 })
#define SHIPS ([ "Shadow Cruiser":([ "airport":"/d/nopk/tirun/airdock", "letter":"S", ]), ])

#endif
