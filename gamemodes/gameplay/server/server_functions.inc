SetupPlayerTable()
{
	mysql_tquery(g_SQL, "CREATE TABLE IF NOT EXISTS `players` (`player_id` int(11) NOT NULL AUTO_INCREMENT,`username` varchar(24) NOT NULL,`password` char(64) NOT NULL,`salt` char(16) NOT NULL, `faction_id` int(16) DEFAULT '-1',`kills` mediumint(8) NOT NULL DEFAULT '0',`deaths` mediumint(8) NOT NULL DEFAULT '0',`x` float NOT NULL DEFAULT '0',`y` float NOT NULL DEFAULT '0',`z` float NOT NULL DEFAULT '0',`angle` float NOT NULL DEFAULT '0',`interior` tinyint(3) NOT NULL DEFAULT '0', PRIMARY KEY (`player_id`), UNIQUE KEY `username` (`username`))");
    return 1;
}

SetupFactionTable(){
    mysql_tquery(g_SQL, "CREATE TABLE IF NOT EXISTS `factions` (`faction_id` int(11) NOT NULL AUTO_INCREMENT, `faction_name` varchar(24) NOT NULL, PRIMARY KEY (`faction_id`), UNIQUE KEY (`faction_name`))");
    return 1;
}