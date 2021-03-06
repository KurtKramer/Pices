
drop table if exists ImagesLogEntries;

Create Table ImagesLogEntries
(
  ImagesLogEntryId     int unsigned     not null auto_increment,
  ImageId              int unsigned     not null,
  ImageFileName        varchar(64)      not null,
  ValidatedClassName   varchar(64)                 comment 'Class Name validated to; will not reflect future changes to the class name.',
  DateTimeOccured      datetime         not null,
  Action               char(1)          not null   comment '"V"= Validation, "R"=Remove Validation, "D"=Image Deleted',
  DataBaseUserName     varchar(32)      not null,

  Primary key          (ImagesLogEntryId),
  Key    ImageIdKey    (ImageId  asc,  DateTimeOccured  asc)
);
