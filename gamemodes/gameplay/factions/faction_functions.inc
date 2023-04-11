forward GetFactionsQuery();
public GetFactionsQuery(){
    new query[128];

    mysql_format(g_SQL, query, sizeof(query), "SELECT * FROM `factions`");
    mysql_tquery(g_SQL, query, "OnFactionDataLoaded");
}   

forward OnFactionDataLoaded();
public OnFactionDataLoaded(){
    printf("%d", cache_num_rows());

    for(new i = 0, j = cache_num_rows(); i < j; i++){
        new fid;
        new fname[16];
        cache_get_value_index_int(i, 0, fid);
        cache_get_value_index(i, 1, fname);
        Faction[i][ID] = fid;
        Faction[i][name] = fname;

    }
}


forward Callback_birlik(playerid);
public Callback_birlik(playerid){
    new tmp_cache;
    tmp_cache = cache_save();
    inline Dialog_Birlik(playerid, dialogid, response, listitem, string:inputtext[]){
        cache_set_active(tmp_cache);
        switch(listitem){
            case 0:
            {
                for(new i = 0; i < cache_num_rows(); i++){
                    new tmp[128];
                    cache_get_value_index(i, 1, tmp);
                    SendClientMessage(playerid, 0xFFFFFFF, tmp);
                }
            }
            case 1:
            {
                inline Dialog_BirligeAl(playerid, dialogid, response, listitem, string:inputtext[]){
                    new targetid;
                    if(sscanf(inputtext, "u", targetid)) return SendClientMessage(playerid, 0xFFFFFFF, "Geçersiz parametre.");
                }
                Dialog_ShowCallback(playerid, using inline Dialog_BirligeAl, DIALOG_STYLE_INPUT, "Birliğe Davet Et", "Birliğe davet etmek istediğiniz oyuncunun ID'sini giriniz.", "Davet gönder", "Vazgeç");
            }
            case 2:
            {
                inline Dialog_BirliktenAt(playerid, dialogid, response, listitem, string:inputtext[]){
                    new targetid;
                    if(sscanf(inputtext, "u", targetid)) return SendClientMessage(playerid, 0xFFFFFFF, "Geçersiz parametre.");
                    if(!IsPlayerConnected(targetid)) return SendClientMessage(playerid, 0xFFFFFF, "Geçersiz oyuncu.");
                    new query[128];
                    mysql_format(g_SQL, query, sizeof(query), "UPDATE players SET faction_id = '-1' WHERE player_id = '%d'", Player[targetid][ID]);
                    mysql_tquery(g_SQL, query);
                    Player[targetid][faction_id] = -1;
                }
                Dialog_ShowCallback(playerid, using inline Dialog_BirliktenAt, DIALOG_STYLE_INPUT, "Birlikten At", "Birlikten atmak istediğiniz oyuncunun ID'sini giriniz.", "At", "Vazgeç");

            }
        }

    }
    Dialog_ShowCallback(playerid, using inline Dialog_Birlik, DIALOG_STYLE_LIST, "Birlik Menüsü", "Üyeler\nBirliğe davet et\nBirlikten at", "Seç", "Çık");
}

forward Callback_BirlikUyeler();
public Callback_BirlikUyeler(){
}

forward Faction_PlayerHasFaction(pid);
public Faction_PlayerHasFaction(pid){
    new tmp;
    tmp = Player[pid][faction_id];
    if(tmp == -1) return 0;
    else return 1;
}

forward Faction_KickFromFaction(pid, fid);
public Faction_KickFromFaction(pid, fid){
    new query[128];
    mysql_format(g_SQL, query, sizeof query, "UPDATE players SET faction_id = '%d' WHERE player_id = '%d'", fid, Player[pid][ID]);
    Player[pid][faction_id] = fid;
}

forward Faction_OnFactionCreated(pid);
public Faction_OnFactionCreated(pid){
    print("faction_onfactioncreated");
    new rcount;
    cache_get_field_count(rcount);
    printf("%d cache field count", rcount);
}

forward Faction_UpdatePlayerFaction(pid);
public Faction_UpdatePlayerFaction(pid){
    new query[128];
    mysql_format(g_SQL, query, sizeof query, "UPDATE players SET faction_id = '%d' WHERE player_id = '%d'");
}

forward Faction_GetPlayerFactionDBID(pid);
public Faction_GetPlayerFactionDBID(pid){

}