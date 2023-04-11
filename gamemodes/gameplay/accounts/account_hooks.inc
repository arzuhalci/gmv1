#include <YSI_Coding\y_hooks>

hook OnPlayerConnect(playerid){
    g_MysqlRaceCheck[playerid]++;
    static const empty_player[E_PLAYERS];
	Player[playerid] = empty_player;
    GetPlayerName(playerid, Player[playerid][Name], MAX_PLAYER_NAME);
    new query[103];
    mysql_format(g_SQL, query, sizeof query, "SELECT * FROM `players` WHERE `username` = '%e' LIMIT 1", Player[playerid][Name]);
	mysql_tquery(g_SQL, query, "OnPlayerDataLoaded", "dd", playerid, g_MysqlRaceCheck[playerid]);	
}

hook OnPlayerDisconnect(playerid, reason){
	g_MysqlRaceCheck[playerid]++;

	UpdatePlayerData(playerid, reason);

	// if the player was kicked (either wrong password or taking too long) during the login part, remove the data from the memory
	if (cache_is_valid(Player[playerid][Cache_ID]))
	{
		cache_delete(Player[playerid][Cache_ID]);
		Player[playerid][Cache_ID] = MYSQL_INVALID_CACHE;
	}

}

