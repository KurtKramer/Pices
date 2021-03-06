drop table if exists SipperFiles;
create table SipperFiles
(
   SipperFileID    int unsigned    not null auto_increment,
   SipperFileName  char(48)        not null,
   CruiseName      char(10)        not null,
   StationName     char(10)        not null,
   DeploymentNum   char(4)         not null,
   Description     varchar(255)    null,
   Latitude        double          null,
   Longitude       double          null,
   DateTimeStart   datetime        null,
   
   SP0Instrument   char(3)         null,
   SP1Instrument   char(3)         null,
   SP2Instrument   char(3)         null,
   SP3Instrument   char(3)         null,

   CtdExt0         char(3)         null,
   CtdExt1         char(3)         null,
   CtdExt2         char(3)         null,
   CtdExt3         char(3)         null,
   
   SizeInBytes     bigint unsigned null  default 0,
   NumScanLines    int unsigned    null  default 0,
   ScanRate        float                 default 24950.0,
   Depth           float           null  default 0.0        comment 'to be used if no Instrumentation Data',
   
   ExtractionStatus         char(1)      null default '0'   comment '0=Not Extracted, 1=Extract, 2=Extracting, 3=Extracted',
   ExtractionScanLineStart  int unsigned null default 0,
   ExtractionScanLineEnd    int unsigned null default 0,
 
   primary key                  (SipperFileID    asc),
   unique        SipperFileName (SipperFileName  asc),
   key           CruiseKey      (CruiseName asc,  StationName asc,  DeploymentNum asc),

   foreign key (CruiseName)                             references Cruises     (CruiseName),
   foreign key (CruiseName, StationName)                references Stations    (CruiseName, StationName),
   foreign key (CruiseName, StationName, DeploymentNum) references Deployments (CruiseName, StationName, DeploymentNum)
)
;


ALTER TABLE `pices_new`.`sipperfiles` 
      ADD COLUMN `ExtractionStatus` CHAR NULL DEFAULT '0' COMMENT '0=Not Extracted, 1=Extract, 2=Extracting, 3=Extracted'  AFTER `Depth` , 
      ADD COLUMN `ExtractionScanLineStart` INT UNSIGNED NULL DEFAULT '0'  AFTER `ExtractionStatus` , 
      ADD COLUMN `ExtractionScanLineEnd` INT UNSIGNED NULL DEFAULT '0'  AFTER `ExtractionScanLineStart`;
      