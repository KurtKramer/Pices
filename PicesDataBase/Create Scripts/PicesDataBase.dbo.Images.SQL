drop table if exists Images;
Create Table Images
(
  ImageId               int unsigned     not null auto_increment,
  ImageFileName         varchar(64)      not null,
  SipperFileId          int unsigned     not null  references SipperFiles(SipperFileId),
  ByteOffset            bigint unsigned  not null  default 0  comment 'Byte offset of start of scanline "TopLeftRow"',
  TopLeftRow            int unsigned     not null  default 0  comment 'First scan line in "SipperFileName"  that contains the image.',
  TopLeftCol            int              not null,
  Height                int              not null,
  Width                 int              not null,
  PixelCount            int              not null,
  ConnectedPixelDist    tinyint unsigned not null  default 0  comment 'Size of structure used for Connected Component Analysis.',
  ExtractionLogEntryId  int unsigned     not null  default 0  comment 'Image Extraction LogEntryId that generated this image.',
  ClassLogEntryId       int unsigned     not null  default 0  comment 'Image Classification LogEntryId that updated class assignment.',
  CentroidRow           int              not null,
  CentroidCol           int              not null,
  Depth	                float            not null  default 0,
  Class1Id              int unsigned     null      references Classes(ClassId),
  Class1Prob            float            null,
  Class2id              int unsigned     null      references Classes(ClassId),
  Class2Prob            float            null,
  ClassValidatedId      int unsigned     null      references Classes(ClassId),
  ImageSize             float            not null  default 0.0,
  SizeCoordinates       varchar(32)      not null,  
  ThumbNail             blob(32768)      null,

  Primary key          (ImageId),
  unique ImageFileNameKey   (ImageFileName    asc),
  Key    SipperFileKey      (SipperFileId     asc,  TopLeftRow         asc),
  Key    ClassKey           (SipperFileId     asc,  Class1Id           asc,  ImageId asc),
  Key    DepthKey           (SipperFileId     asc,  Depth              asc,  ImageId asc),
  Key    ValidatedKey       (SipperFileId     asc,  ClassValidatedId   asc,  ImageId asc),
  Key    Class2Key          (SipperFileId     asc,  Class2Id           asc,  ImageId asc),
  Key    ImagesClass1Key    (Class1Id         asc),
  Key    ImagesClass2Key    (Class2Id         asc),
  Key    ImagesValidatedKey (ClassValidatedId asc)
);

