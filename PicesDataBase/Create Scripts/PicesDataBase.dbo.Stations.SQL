

drop table if exists Stations;
create table Stations
(
   CruiseName    char(10)      not null,
   StationName   char(10)      not null,
   Description   varchar(255)  null,
   Latitude      double        null,
   Longitude     double        null,
   DateTimeStart datetime      null,
 
   primary key    (CruiseName  asc,  StationName asc),
   foreign key  (CruiseName)  references Cruises (CruiseName)
)
;


insert into Stations  (CruiseName, StationName, Description, Latitude, Longitude, DateTimeStart)
            values    ("ETP2007",    "1",         "",          0.0,      0.0,          "2007-10-28");

insert into Stations  (CruiseName, StationName, Description, Latitude, Longitude, DateTimeStart)
            values    ("ETP2007",    "2",         "",          0.0,      0.0,          "2007-10-28");

insert into Stations  (CruiseName, StationName, Description, Latitude, Longitude, DateTimeStart)
            values    ("ETP2007",    "8",         "",          0.0,      0.0,          "2007-10-28");

insert into Stations  (CruiseName, StationName, Description, Latitude, Longitude, DateTimeStart)
            values    ("ETP2008",    "4a",         "",          0.0,      0.0,          "2008-12-24");

insert into Stations  (CruiseName, StationName, Description, Latitude, Longitude, DateTimeStart)
            values    ("ETP2008",    "4b",         "",          0.0,      0.0,          "2008-12-24");


insert into Stations  (CruiseName, StationName, Description, Latitude, Longitude, DateTimeStart)
            values    ("ETP2008",    "A",         "",          0.0,      0.0,          "2008-12-28");
