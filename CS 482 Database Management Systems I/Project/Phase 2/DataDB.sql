INSERT INTO Players(PlayerID, TeamName, Position, TouchDowns, TotalYards, Salary) VALUES (1376, "Knights","QB", 1, 5, 563);
INSERT INTO Players(PlayerID, TeamName, Position, TouchDowns, TotalYards, Salary) VALUES (1859, "Knights","WR", 3, 10, 580);
INSERT INTO Players(PlayerID, TeamName, Position, TouchDowns, TotalYards, Salary) VALUES (1265, "Knights","PB", 1, 10, 639);
INSERT INTO Players(PlayerID, TeamName, Position, TouchDowns, TotalYards, Salary) VALUES (1607, "Spartans","QB", 5, 65, 540);
INSERT INTO Players(PlayerID, TeamName, Position, TouchDowns, TotalYards, Salary) VALUES (2275, "Spartans","RB", 8, 20, 819);
INSERT INTO Players(PlayerID, TeamName, Position, TouchDowns, TotalYards, Salary) VALUES (2478, "Spartans","WR", 10, 50, 942);

INSERT INTO Games(GameID, Date, Stadium, Result, Attendence, TicketRevenue) VALUES (110, '2019-1-01','Angel Stadium of Anaheim','L', 10638, 136861);
INSERT INTO Games(GameID, Date, Stadium, Result, Attendence, TicketRevenue) VALUES (114, '2019-2-15','Chase Field','L', 27652, 112640);
INSERT INTO Games(GameID, Date, Stadium, Result, Attendence, TicketRevenue) VALUES (138, '2019-5-30','Coors Field','T', 23736, 120244);
INSERT INTO Games(GameID, Date, Stadium, Result, Attendence, TicketRevenue) VALUES (159, '2019-9-17','Globe Life Park in Arlington','W', 31035, 151670);
INSERT INTO Games(GameID, Date, Stadium, Result, Attendence, TicketRevenue) VALUES (163, '2019-12-24','Marlins Park','W', 53519, 128145);
INSERT INTO Games(GameID, Date, Stadium, Result, Attendence, TicketRevenue) VALUES (183, '2019-10-30','PNC Park','W', 42895, 138434);

INSERT INTO Play(PlayerID, GameID) VALUES (1376, 110);
INSERT INTO Play(PlayerID, GameID) VALUES (1859, 114);
INSERT INTO Play(PlayerID, GameID) VALUES (1265, 138);
INSERT INTO Play(PlayerID, GameID) VALUES (1607, 159);
INSERT INTO Play(PlayerID, GameID) VALUES (2275, 163);
INSERT INTO Play(PlayerID, GameID) VALUES (2478, 183); 