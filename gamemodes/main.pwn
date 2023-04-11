#include <a_samp>

#define COLOR_BLUE 0xFFFFFF
#include <a_mysql>
#include <sscanf2>

#include	<YSI_Coding/y_inline>
#include	<YSI_Extra/y_inline_mysql>
#include	<YSI_Visual/y_dialog>
#include    <YSI_Visual/y_commands>


/*
server_main: öncelikle mysql bilgilerini server_data ile yaratır. ardından server_main içerisine server_hooks import edilir ve 
YSI_Hooks ile aslında oyun modunda sadece 1 kere 1 dosyada çağırılabilecek bir callback fonksiyonunu çağırırız. bunun içinde 
OnGameModeInit var. bu fonksiyon oyun modu ilk başladığında yapması gerekenleri sunucuya anlatır. burada sunucuya mysql bağlantısı
kurması gerektiği anlatılır. yani sunucuyla ilgili herşey server main içinde bulunur.
*/
#include <gamemodes\gameplay\server\server_main>
#include <gamemodes\gameplay\accounts\account_main>
#include <gamemodes\gameplay\factions\faction_main>



main(){
}
