CREATE TABLE Players {
	Name VARCHAR(50),
	PlayerID INT not NULL, -- Make sure the player will always have an ID
	TeamName VARCHAR(50),
	Position CHAR(2),
	Touchdowns INT,
	TotalYards INT,
	Salary INT,
	CHECK (Position IN ('QB','RB','WR')),
	PRIMARY KEY (PlayerID) -- Make sure the ID will always be unique
};
	
CREATE TABLE Games {
	GameID INT not NULL, -- Make sure the game will always have an ID
	Date DATE,
	Stadium VARCHAR(75),
	Result CHAR(1),
    Attendence INT,
    TicketRevenue INT,
	PRIMARY KEY (GameID), -- Make sure the ID will always be unique
    CHECK (Result IN ('W','L','T'))
};

CREATE TABLE Play {
	PlayerID INT not NULL, -- Make sure the game will always have an ID
	GameID INT,
	Foreign key (PlayerID) references player (PlayerID) ON DELETE CASCADE, -- PlayerID connects to Players
	Foreign key (GameID) references games (GameID) ON DELETE CASCADE -- GameID connects to Games
};