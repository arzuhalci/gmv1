
YCMD:birlikler(playerid, params[], help){
    printf("%s",Faction[strval(params[0])][name]);
    return 1;
}

YCMD:buekle(playerid, params[], help){
    new query[128];
    static p_id;
    p_id = Player[strval(params[3])][ID];
    mysql_format(g_SQL, query, sizeof(query),"UPDATE `players` SET `faction_id` = '%d' WHERE `player_id` = '%d'", strval(params[0]), p_id);
    mysql_tquery(g_SQL, query, "Callback_buekle");
    return 1;
}

YCMD:birlik(playerid, params[], help){
    if(!Faction_PlayerHasFaction(playerid)) return SendClientMessage(playerid, COLOR_BLUE, "Bir birliğe üye değilsiniz.");
    new query[128];
    mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM `players` WHERE `faction_id` = '%d'", Player[playerid][faction_id]);
    mysql_tquery(g_SQL, query, "Callback_birlik", "d", playerid);
    return 1;
}

YCMD:gmx(playerid, params[], help){
    SendRconCommand("gmx");
    return 1;
}

YCMD:test(playerid, params[], help){
    new tmp[128];
    new fid, targetid;
    if(sscanf(params, "du", fid, targetid)) return SendClientMessage(playerid, COLOR_BLUE, "Geçersiz parametre.");
    new db_id;
    db_id = Player[targetid][ID];
    mysql_format(g_SQL, tmp, sizeof tmp, "UPDATE players SET faction_id = '%d' WHERE player_id = '%d' SET", fid, db_id);
    mysql_tquery(g_SQL, tmp);
    
    return 1;
}

YCMD:birlikkur(playerid, params[], help){
    //iki eşittir yerine ünlem işareti koy işin bitince
    if(Player[playerid][faction_id] == 9999) return SendClientMessage(playerid, COLOR_BLUE, "Zaten bir birliğe üyesiniz.");
    new fname[24];
    if(sscanf(params, "s[24]", fname)) return SendClientMessage(playerid, COLOR_BLUE, "Geçersiz birlik ismi.");
    new query[128];
    mysql_format(g_SQL, query, sizeof query, "INSERT INTO `factions`(`faction_id`, `faction_name`) VALUES ('','%s')", fname);
    mysql_tquery(g_SQL, query, "Faction_OnFactionCreated", "d", playerid);
    //mysql_format(g_SQL, query, sizeof query, "UPDATE 'players' SET 'faction_id'")
    printf("%s", fname);
    return 1;
}