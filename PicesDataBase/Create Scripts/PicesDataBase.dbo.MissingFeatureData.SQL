drop table if exists MissingFeatureData;

Create Table MissingFeatureData
(
  ImageId             int unsigned     not null             comment 'ImageId ofg image that is missing a corresponding FeatureData entry',
  DateTimeAdded       datetime         not null             comment 'Date-Time that this entry was added to this table.',
  SipperFileId        int unsigned     not null             comment 'SipperFile that image was extracted from.',
  
  Primary key  (ImageId),
  Key           SipperFile    (SipperFileId  asc,  ImageId  asc),
  
  foreign key  (ImageId)      references Images      (ImageId),
  foreign key  (SipperFileId) references SipperFiles (SipperFileId)
  
)
  comment = 'This table lists the images that are missing corresponding FeatureData entries.'
;
