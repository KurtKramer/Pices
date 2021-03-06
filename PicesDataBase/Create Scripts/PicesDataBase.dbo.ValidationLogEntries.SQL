drop table if exists ValidationLogEntries;

Create Table ValidationLogEntries
(
  ValidationLogEntryId          int unsigned     not null auto_increment,
  ImageId                       int unsigned     not null references Images(ImageId), 
  DateTimeOccured               datetime         not null,
  Action                        char(1)          not null         comment '"V"= Validation, "R"=Remove Validation, "D"=Image Deleted',
  
  ProgCode            char(4)          not null default "    "    comment '"IE"=Image Extraction, "CL"=Classification.',
  ProgName            varchar(64)      not null default ""        comment 'Name of applicationperforming process.',
  DateTimeCompiled    datetime                                    comment 'DateTime program was compiled.',
  CmdLine             varchar(512)     not null default ""        comment 'Command line used to run program.',
  CompName            varchar(32)      not null default ""        comment 'Name of computer that program ran on.',
  DataBaseUserName    varchar(32)      not null default ""        comment 'UserName used to connect to the database with.',
  CompUserName        varchar(32)      not null default ""        comment 'UserNane used to log into computer with.',
  DateTimeStart       datetime         not null                   comment 'DateTime process started.',
  DateTimeStartUtc    datetime         not null                   comment 'UTC DateTime process started.',
  DateTimeEnd         datetime         null,
  CpuTimeUsed         float            not null default 0         comment 'Number of CPU seconds used surimng process.',
  CompletionStatus    varchar(128)     not null default "Started" comment 'Indicates status of process when completed.',
  SipperFileId        int              not null default -1        comment 'Indicates the Sipper File if peocess like ImageExtraction.',

  Primary key          (ValidationLogEntryId),
  Key    ProgCode      (ProgCode       asc,  DateTimeStart      asc),
  Key    SipperFile    (SipperFileId   asc,  DateTimeStart      asc)
);
