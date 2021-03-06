drop table if exists GpsData;
Create Table GpsData
(
  CruiseName            char(10)         not null,
  UtcDateTime           datetime         not null,
  latitude              double           default null,
  longitude             double           default null,
  courseOverGround      float            default null    comment  'True North',
  speedOverGround       float            default null    comment  'Speed in Knots',

  Primary key          (CruiseName, UtcDateTime)
);

