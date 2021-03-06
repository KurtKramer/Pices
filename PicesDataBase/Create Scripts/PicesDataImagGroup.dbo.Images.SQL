drop table if exists ImageGroup;

Create Table ImageGroup
(
  ImageGroupId       int unsigned     not null auto_increment,
  ImageGroupName     varchar(64)      not null,
  Description        varchar(512)     null,

  Primary key              (ImageGroupId),
  unique ImageGroupNameKey (ImageGroupName  asc)
);
