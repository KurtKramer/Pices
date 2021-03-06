  drop table if exists Deployments;
  create table Deployments   
  (
    CruiseName           char(10)     not null,
    StationName          char(10)     not null,  
    DeploymentNum        char(4)      not null,
    Description          varchar(255) null,
    DateTimeStart        datetime     null,
    DateTimeEnd          datetime     null,
    Latitude             double       null,
    Longitude            double       null,
    SyncTimeStampActual  datetime     null,
    SyncTimeStampCTD     datetime     null,
    SyncTimeStampGPS     datetime     null,
    
    CropLeft             int unsigned not null default 0,
    CropRight            int unsigned not null default 4095,
    
    ChamberWidth         float        not null  default 0.098  comment 'Width of imaging chamber in Meters.',

    primary key (CruiseName asc,  StationName asc,  DeploymentNum asc),
    foreign key (CruiseName, StationName)  references Stations (CruiseName, StationName)
  );

insert into Deployments  (CruiseName, StationName, DeploymentNum, Description, DateTimeStart, DateTimeEnd,  Latitude, Longitude)
            values       ("ETP2007",    "1",         "A",           "",          "2007-10-28",  "2007-10-28", 0.0,      0.0);


insert into Deployments  (CruiseName, StationName, DeploymentNum, Description, DateTimeStart, DateTimeEnd,  Latitude, Longitude)
            values       ("ETP2007",    "1",         "B",           "",          "2007-10-28",  "2007-10-28", 0.0,      0.0);


insert into Deployments  (CruiseName, StationName, DeploymentNum, Description, DateTimeStart, DateTimeEnd,  Latitude, Longitude)
            values       ("ETP2007",    "1",         "C",           "",          "2007-10-28",  "2007-10-28", 0.0,      0.0);


insert into Deployments  (CruiseName, StationName, DeploymentNum, Description, DateTimeStart, DateTimeEnd,  Latitude, Longitude)
            values       ("ETP2007",    "1",         "D",           "",          "2007-10-28",  "2007-10-28", 0.0,      0.0);


insert into Deployments  (CruiseName, StationName, DeploymentNum, Description, DateTimeStart, DateTimeEnd,  Latitude, Longitude)
            values       ("ETP2007",    "1",         "E",           "",          "2007-10-28",  "2007-10-28", 0.0,      0.0);


insert into Deployments  (CruiseName, StationName, DeploymentNum, Description, DateTimeStart, DateTimeEnd,  Latitude, Longitude)
            values       ("ETP2007",    "1",         "F",           "",          "2007-10-28",  "2007-10-28", 0.0,      0.0);


insert into Deployments  (CruiseName, StationName, DeploymentNum, Description, DateTimeStart, DateTimeEnd,  Latitude, Longitude)
            values       ("ETP2007",    "1",         "G",           "",          "2007-10-28",  "2007-10-28", 0.0,      0.0);


insert into Deployments  (CruiseName, StationName, DeploymentNum, Description, DateTimeStart, DateTimeEnd,  Latitude, Longitude)
            values       ("ETP2007",    "2",         "",            "",          "2007-10-28",  "2007-10-28", 0.0,      0.0);


insert into Deployments  (CruiseName, StationName, DeploymentNum, Description, DateTimeStart, DateTimeEnd,  Latitude, Longitude)
            values       ("ETP2007",    "8",         "A",           "",          "2007-10-28",  "2007-10-28", 0.0,      0.0);


insert into Deployments  (CruiseName, StationName, DeploymentNum, Description, DateTimeStart, DateTimeEnd,  Latitude, Longitude)
            values       ("ETP2007",    "8",         "B",           "",          "2007-10-28",  "2007-10-28", 0.0,      0.0);


insert into Deployments  (CruiseName, StationName, DeploymentNum, Description, DateTimeStart, DateTimeEnd,  Latitude, Longitude)
            values       ("ETP2007",    "8",         "C",           "",          "2007-10-28",  "2007-10-28", 0.0,      0.0);


insert into Deployments  (CruiseName, StationName, DeploymentNum, Description, DateTimeStart, DateTimeEnd,  Latitude, Longitude)
            values       ("ETP2007",    "8",         "D",           "",          "2007-10-28",  "2007-10-28", 0.0,      0.0);


insert into Deployments  (CruiseName, StationName, DeploymentNum, Description, DateTimeStart, DateTimeEnd,  Latitude, Longitude)
            values       ("ETP2007",    "8",         "E",           "",          "2007-10-28",  "2007-10-28", 0.0,      0.0);


insert into Deployments  (CruiseName, StationName, DeploymentNum, Description, DateTimeStart, DateTimeEnd,  Latitude, Longitude)
            values       ("ETP2007",    "8",         "G",           "",          "2007-10-28",  "2007-10-28", 0.0,      0.0);


insert into Deployments  (CruiseName, StationName, DeploymentNum, Description, DateTimeStart, DateTimeEnd,  Latitude, Longitude)
            values       ("ETP2008",    "4b",         "A",           "",          "2008-12-24 19:27:00",  "2008-12-24", 0.0,      0.0);



insert into Deployments  (CruiseName, StationName, DeploymentNum, Description, DateTimeStart, DateTimeEnd,  Latitude, Longitude)
            values       ("ETP2008",    "8",         "A",           "",          "2008-12-28 17:42:00",  "2008-12-28", 0.0,      0.0);
