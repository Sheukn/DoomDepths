CREATE TABLE hero(
    level int(11) NOT NULL,
    max_health_points int(11) NOT NULL,
    health_points int(11) NOT NULL,
    max_mana_points int(11) NOT NULL,
    mana_points int(11) NOT NULL,
    attack int(11) NOT NULL,
    defense int(11) NOT NULL,
    alive int(11) NOT NULL,
    xp int(11) NOT NULL,
    xp_to_up int(11) NOT NULL
);

CREATE TABLE monster(
    health_points int(11) NOT NULL,
    min_atk_pow int(11) NOT NULL,
    max_atk_pow int(11) NOT NULL,
    defense int(11) NOT NULL,
    alive int(11) NOT NULL,
    xp int(11) NOT NULL,
    sprite_id int(11) NOT NULL
);

CREATE TABLE armor(
    name varchar(255) NOT NULL,
    defense int(11) NOT NULL
);

CREATE TABLE weapon(
    name varchar(255) NOT NULL,
    damage int(11) NOT NULL
);
