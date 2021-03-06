delimiter ;

drop procedure  if exists InstrumentDataInsert;

delimiter //

create procedure  InstrumentDataInsert 
      (in _SipperFileName       varChar(48), 
       in _ScanLine             int       unsigned, 
       in _ByteOffset           bigint    unsigned,
       in _CTDDateTime          datetime, 
       in _Latitude             double, 
       in _Longitude            double,
       in _CTDBattery           float,
       in _Conductivity         float,
       in _Density              float,
       in _Depth                float,
       in _FlowRate1            float,
       in _FlowRate2            float,
       in _Fluorescence         float,
       in _FluorescenceSensor   float,
       in _Oxygen               float,
       in _OxygenSensor         float,
       in _Pressure             float,
       in _RecordRate           float,
       in _Salinity             float,
       in _SoundVelocity        float,
       in _Temperature          float,
       in _Transmisivity        float,
       in _TransmisivitySensor  float,
       in _Turbidity            float,
       in _TurbiditySensor      float,
       in _Pitch                float,
       in _Roll                 float,
       in _CropLeft             int unsigned,
       in _CropRight            int unsigned,
       in _ActiveColumns        int unsigned
      )

begin
  declare  _sipperFileId  int  unsigned  default 0;
  
  set  _sipperFileId = (select  sf.SipperFileId  from SipperFiles sf  where  sf.SipperFileName = _sipperFileName);
  
  insert into  InstrumentData  
              (SipperFileId,     ScanLine,            ByteOffset, 
               CTDDateTime,      Latitude,            Longitude,
               CTDBattery,       Conductivity,        Density, 
               Depth,            FlowRate1,           FlowRate2,
               Fluorescence,     FluorescenceSensor,  Oxygen,         
               OxygenSensor,     Pressure,            RecordRate,       
               Salinity,         SoundVelocity,       Temperature,      
               Transmisivity,    TransmisivitySensor, Turbidity,        
               TurbiditySensor,  Pitch,               Roll,
               CropLeft,         CropRight,           ActiveColumns
              )
          values 
             (
               _sipperFileId, 
               _ScanLine,         
               _ByteOffset, 
               _CTDDateTime,
               _Latitude,
               _Longitude,
               _CTDBattery,
               _Conductivity,
               _Density, 
               _Depth,
               _FlowRate1,
               _FlowRate2,
               _Fluorescence,
               _FluorescenceSensor,
               _Oxygen,
               _OxygenSensor,
               _Pressure,
               _RecordRate,
               _Salinity,
               _SoundVelocity,
               _Temperature,
               _Transmisivity,
               _TransmisivitySensor,
               _Turbidity,
               _TurbiditySensor,
               _Pitch,
               _Roll,
               _CropLeft,
               _CropRight,
               _ActiveColumns
             );
end
//
delimiter ;


drop procedure  if exists InstrumentDataInsert2;

delimiter //

create procedure  InstrumentDataInsert2 
      (in _SipperFileName       varChar(48), 
       in _ScanLine             int       unsigned, 
       in _ByteOffset           bigint    unsigned,
       in _CTDDateTime          datetime, 
       in _Latitude             double, 
       in _Longitude            double,
       in _CTDBattery           float,
       in _Conductivity         float,
       in _Density              float,
       in _Depth                float,
       in _FlowRate1            float,
       in _FlowRate2            float,
       in _Fluorescence         float,
       in _FluorescenceSensor   float,
       in _CdomFluorescence       float,
       in _CdomFluorescenceSensor float,
       in _Oxygen               float,
       in _OxygenSensor         float,
       in _Pressure             float,
       in _RecordRate           float,
       in _Salinity             float,
       in _SoundVelocity        float,
       in _Temperature          float,
       in _Transmisivity        float,
       in _TransmisivitySensor  float,
       in _Turbidity            float,
       in _TurbiditySensor      float,
       in _Pitch                float,
       in _Roll                 float,
       in _CropLeft             int unsigned,
       in _CropRight            int unsigned,
       in _ActiveColumns        int unsigned
      )

begin
  declare  _sipperFileId  int  unsigned  default 0;
  
  set  _sipperFileId = (select  sf.SipperFileId  from SipperFiles sf  where  sf.SipperFileName = _sipperFileName);
  
  insert into  InstrumentData  
              (SipperFileId,     ScanLine,            ByteOffset, 
               CTDDateTime,      Latitude,            Longitude,
               CTDBattery,       Conductivity,        Density, 
               Depth,            FlowRate1,           FlowRate2,
               Fluorescence,     FluorescenceSensor,  
               CdomFluorescence, CdomFluorescenceSensor,  
               Oxygen,         
               OxygenSensor,     Pressure,            RecordRate,       
               Salinity,         SoundVelocity,       Temperature,      
               Transmisivity,    TransmisivitySensor, Turbidity,        
               TurbiditySensor,  Pitch,               Roll,
               CropLeft,         CropRight,           ActiveColumns               
              )
          values 
             (
               _sipperFileId, 
               _ScanLine,         
               _ByteOffset, 
               _CTDDateTime,
               _Latitude,
               _Longitude,
               _CTDBattery,
               _Conductivity,
               _Density, 
               _Depth,
               _FlowRate1,
               _FlowRate2,
               _Fluorescence,
               _FluorescenceSensor,
               _CdomFluorescence,
               _CdomFluorescenceSensor,
               _Oxygen,
               _OxygenSensor,
               _Pressure,
               _RecordRate,
               _Salinity,
               _SoundVelocity,
               _Temperature,
               _Transmisivity,
               _TransmisivitySensor,
               _Turbidity,
               _TurbiditySensor,
               _Pitch,
               _Roll,
               _CropLeft,
               _CropRight,
               _ActiveColumns
             );
end
//
delimiter ;







/**********************************************************************************************************************/
drop procedure  if exists InstrumentDataUpdateCropSettings;

delimiter //

create procedure  InstrumentDataUpdateCropSettings 
      (in _sipperFileName   varChar(48),
       in _scanLineStart    int unsigned,
       in _scanLineEnd      int unsigned,
       in _cropLeft         int unsigned,
       in _cropRight        int unsigned,
       in _activeColumns    int unsigned
      )

begin
  declare  _sipperFileId     int unsigned default 0;

  set _sipperFileId = (select  sf.SipperFileId  from  SipperFiles sf  where  sf.SipperFileName = _sipperFileName);

  

  update  InstrumentData id
    set  id.CropLeft      = _cropLeft,
         id.CropRight     = _cropRight,
         id.ActiveColumns = _activeColumns
    where  (id.SipperFileId = _sipperFileId)  and  (id.ScanLine >= _scanLineStart)  and  (id.ScanLine <= _scanLineEnd);
end
//
delimiter ;













/**********************************************************************************************************************/
drop procedure  if exists InstrumentDataGetByScanLine;

delimiter //
create procedure   InstrumentDataGetByScanLine (in _sipperFileName   varChar(48),
                                                in _scanLine         int unsigned
                                               )
begin
  declare  _sipperFileId    int unsigned default 0;
  declare  _startScanLine   int unsigned default 0;

  if  _scanLine > 8192  then
    set _startScanLine = _scanLine - 8192;
  else
    set _startScanLine = 0;
  end if;

  set _sipperFileId = (select  sf.SipperFileId  from  SipperFiles sf  where  sf.SipperFileName = _sipperFileName);

  select *  from  InstrumentData id
            where  (id.SipperFileId = _sipperFileId)  and  (id.ScanLine >= _startScanLine)  and  (id.ScanLine <= _scanLine)
            order by id.ScanLine  desc
            limit 1;  

end
//
delimiter ;






/**********************************************************************************************************************/
drop procedure  if exists InstrumentDataDeleteOneSipperFile;

delimiter //
create procedure   InstrumentDataDeleteOneSipperFile (in _sipperFileName   varChar(48))
begin
  declare  _sipperFileId   int unsigned default 0;
  set _sipperFileId = (select  sf.SipperFileId  from  SipperFiles sf  where  sf.SipperFileName = _sipperFileName);

  delete from  InstrumentData  where  SipperFileId = _sipperFileId;
end
//
delimiter ;








/**********************************************************************************************************************/
drop procedure  if exists InstrumentDataLoadOneSipperFile;

delimiter //
create procedure   InstrumentDataLoadOneSipperFile (in _sipperFileName   varChar(48))
begin
  declare  _sipperFileId   int unsigned default 0;
  set _sipperFileId = (select  sf.SipperFileId  from  SipperFiles sf  where  sf.SipperFileName = _sipperFileName);

  select * from InstrumentData id  where  id.SipperFileId = _sipperFileId;
end
//
delimiter ;








/**********************************************************************************************************************/
/**********************************************************************************************************************/
drop  function  if exists InstrumentDataGetMidPoint;

/**  "InstrumentDataGetMidPoint"  was replaced by "InstrumentDataGetMidPointOfDeployment"  */



/**********************************************************************************************************************/
drop procedure if exists  InstrumentDataGetMidPointOfDeployment;
drop function  if exists  InstrumentDataGetMidPointOfDeployment;

delimiter //
create function  InstrumentDataGetMidPointOfDeployment (_cruiseName      varChar(10),
                                                        _stationName     varChar(10),
                                                        _deploymentNum   varChar(4)
                                                       )
                                                       returns  DateTime
													   deterministic reads sql data
begin
  declare _maxDepth     float     default 0.0;
  declare _midPoint     datetime;

  set  _maxDepth = (select max(id.Depth)
                        from InstrumentData id
                        join (SipperFiles sf)  on(sf.SipperFileId = id.SipperFileId)
                        where  sf.CruiseName = _cruiseName  and  sf.StationName = _stationName  and  sf.DeploymentNum = _deploymentNum
                              and  id.CTDDateTime  > "2000-01-01 00:01:01"
                              and  id.CTDDateTime  < "2020-12-31 23:59:59"
                              and  id.CTDBattery   > 5.5   and  id.CTDBattery    < 14.0
                              and  id.Depth        < 1000
                              and  id.Temperature  > 0.0   and  id.Temperature   < 40.0
                                                           and  id.Salinity      < 40.0
                                                           and  id.Density       < 40.0
                              and  id.Fluorescence > -2    and  id.Fluorescence  < 80.0
                   );

  set _midPoint = (select max(id.CTDDateTime)
                        from InstrumentData id
                        join (SipperFiles sf)  on(sf.SipperFileId = id.SipperFileId)
                        where  sf.CruiseName = _cruiseName  and  sf.StationName = _stationName  and  sf.DeploymentNum = _deploymentNum
                              and  floor(id.Depth * 100) = floor(_maxDepth * 100)
                              and  id.CTDDateTime  > "2000-01-01 00:01:01"
                              and  id.CTDDateTime  < "2020-12-31 23:59:59"
                              and  id.CTDBattery   > 5.5   and  id.CTDBattery    < 14.0
                              and  id.Depth        < 1000
                              and  id.Temperature  > 0.0   and  id.Temperature   < 40.0
                                                           and  id.Salinity      < 40.0
                                                           and  id.Density       < 40.0
                              and  id.Fluorescence > -2    and  id.Fluorescence  < 80.0
                   );

  Return  _midPoint;
end;
//

delimiter ;




/**********************************************************************************************************************/
drop procedure if exists  InstrumentDataGetMidPointOfDeployment2;

delimiter //
create procedure  InstrumentDataGetMidPointOfDeployment2 (_cruiseName      varChar(10),
                                                          _stationName     varChar(10),
                                                          _deploymentNum   varChar(4)
                                                         )
begin
  select  InstrumentDataGetMidPointOfDeployment (_cruiseName, _stationName, _deploymentNum)  as  MidPoint;
end;
//

delimiter ;













/**********************************************************************************************************************/
drop procedure if exists  InstrumentDataByUpAndDownCast;

delimiter //
create procedure  InstrumentDataByUpAndDownCast (in  _cruiseName      varChar(10),
                                                 in  _stationName     varChar(10),
                                                 in  _deploymentNum   varChar(4),
                                                 in  _className       varChar(64),
                                                 in  _depthBinSize    int unsigned
                                                )
begin
  declare _classId      int       default 0;
  declare _midPoint     datetime;

  if  (!isnull(_className)  and  (_className != ""))  then
    set  _classId = (select ClassId  from  Classes  where  ClassName = _className);
  else
    set  _classId = -1;
  end if;

  set  _midPoint = InstrumentDataGetMidPointOfDeployment(_cruiseName, _stationName, _deploymentNum);

  drop  temporary table if exists  ImageCountStats;

  create TEMPORARY table ImageCountStats
   (
     UpCast           bool   not null,
     DepthIdx         int    not null,
     Depth            float  not null,
     ImageCount       int    not null,
     TotalPixelCount  int    not null,
     Less500          int    not null,
     Less1000         int    not null,
     Less5000         int    not null,
     Less10000        int    not null,
     More10000        int    not null
   );

  INSERT into ImageCountStats
      select (id.CTDDateTime >= _midPoint)                     as upCast,
              floor(i.depth / _depthBinSize)                   as bucketIdx,
             (floor(i.depth / _depthBinSize) * _depthBinSize)  as bucketDepth,
             Count(i.ImageId)                                  as ImageCount,
             sum(i.PixelCount)                                 as totalPixelCount,
             sum(i.PixelCount <=   500.0)                                   as  Less500,
             sum((i.PixelCount >   500.0)  and  (i.PixelCount <=  1000.0))  as  Less1000,
             sum((i.PixelCount >  1000.0)  and  (i.PixelCount <=  5000.0))  as  Less5000,
             sum((i.PixelCount >  5000.0)  and  (i.PixelCount <= 10000.0))  as  Less10000,
             sum((i.PixelCount >  10000.0))                                 as  More10000
             
          from Images i
          join (SipperFiles sf)     on  (sf.SipperFileId = i.SipperFileId)
          join (InstrumentData id)  on  (id.SipperFileId = i.SipperFileId  and  id.ScanLine = (floor(i.TopLeftRow / 4096) * 4096))
          where  sf.CruiseName = _cruiseName  and  sf.StationName = _stationName  and  sf.DeploymentNum = _deploymentNum
                 and  ((_classId < 0)  or  (i.Class1Id = _classId))
          group by (id.CTDDateTime >= _midPoint), floor(i.depth / _depthBinSize);



  select (id.CTDDateTime >= _midPoint)                       as upCast,
          floor(id.depth /  _depthBinSize)                   as bucketIdx,
         (floor(id.depth /  _depthBinSize) * _depthBinSize)  as bucketDepth,
         count(*) * 4096   as NumScanLines,
         max(id.CTDDateTime)          as  CTDDateTime,
         ics.ImageCount               as  ImageCont,
         ics.TotalPixelCount          as  TotalPixelCount,
         ics.Less500                  as  "<=500",
         ics.Less1000                 as  "<=1000",
         ics.less5000                 as  "<=5000",
         ics.less10000                as  "<=10000",
         ics.More10000                as  ">10000",
         avg(id.FlowRate1)            as  FlowRate1,           stddev(id.FlowRate1)            as  FlowRate1SD,
         avg(id.Density)              as  Density,             stddev(id.Density)              as  DensitySD,
         avg(id.Fluorescence)         as  Fluorescence,        stddev(id.Fluorescence)         as  FluorescenceSD,
         avg(id.FluorescenceSensor)   as  FluorescenceSensor,  stddev(id.FluorescenceSensor)   as  FluorescenceSensorSD,
         avg(id.Oxygen)               as  Oxygen,              stddev(id.Oxygen)               as  OxygenSD,
         avg(id.OxygenSensor)         as  OxygenSensor,        stddev(id.OxygenSensor)         as  OxygenSensorSD,
         avg(id.Pressure)             as  Pressure,            stddev(id.Pressure)             as  PressureSD,
         avg(id.RecordRate)           as  RecordRate,          stddev(id.RecordRate)           as  RecordRateSD,
         avg(id.Salinity)             as  Salinity,            stddev(id.Salinity)             as  SalinitySD,
         avg(id.SoundVelocity)        as  SoundVelocity,       stddev(id.SoundVelocity)        as  SoundVelocitySD,
         avg(id.Temperature)          as  Temperature,         stddev(id.Temperature)          as  TemperatureSD,
         avg(id.Transmisivity)        as  Transmisivity,       stddev(id.Transmisivity)        as  TransmisivitySD,
         avg(id.TransmisivitySensor)  as  TransmisivitySensor, stddev(id.TransmisivitySensor)  as  TransmisivitySensorSD,
         avg(id.Turbidity)            as  Turbidity,           stddev(id.Turbidity)            as  TurbiditySD,
         avg(id.TurbiditySensor)      as  TurbiditySensor,     stddev(id.TurbiditySensor)      as  TurbiditySensorSD

      from InstrumentData id
      join (SipperFiles sf)            on  (sf.SipperFileId = id.SipperFileId)
      left join (ImageCountStats ics)  on  (ics.UpCast = (id.CTDDateTime >= _midPoint)  and  ics.Depth = (floor(id.depth / _depthBinSize) * _depthBinSize))
      where  sf.CruiseName = _cruiseName  and  sf.StationName = _stationName  and  sf.DeploymentNum = _deploymentNum
        and  id.Depth  < 1000
        and  id.CTDDateTime  > "2000-01-01 00:01:01"
        and  id.CTDDateTime  < "2020-12-31 23:59:59"
        and  id.CTDBattery   > 5.5  and  id.CTDBattery    < 14.0
        and  id.Temperature  > 0.0  and  id.Temperature   < 40.0
                                    and  id.Salinity      < 40.0
                                    and  id.Density       < 40.0
        and  id.Fluorescence > -2   and  id.Fluorescence  < 80.0
      group by (id.CTDDateTime >= _midPoint), floor(id.depth / _depthBinSize);

end;
//

delimiter ;







/**********************************************************************************************************************/
drop procedure if exists  InstrumentDataByUpAndDownCastUnfiltered;


delimiter //
create procedure InstrumentDataByUpAndDownCastUnfiltered (in  _cruiseName      varChar(10),
                                                          in  _stationName     varChar(10),
                                                          in  _deploymentNum   varChar(4),
                                                          in  _className       varChar(64),
                                                          in  _depthBinSize    int unsigned
                                                        )
begin
  declare _classId      int       default 0;
  declare _midPoint     datetime;

  if  (!isnull(_className)  and  (_className != ""))  then
    set  _classId = (select ClassId  from  Classes  where  ClassName = _className);
  else
    set  _classId = -1;
  end if;

  set  _midPoint = InstrumentDataGetMidPointOfDeployment(_cruiseName, _stationName, _deploymentNum);

  drop  temporary table if exists  ImageCountStats;


  create TEMPORARY table ImageCountStats
   (
     UpCast           bool   not null,
     DepthIdx         int    not null,
     Depth            float  not null,
     ImageCount       int    not null,
     TotalPixelCount  int    not null,
     Less500          int    not null,
     Less1000         int    not null,
     Less5000         int    not null,
     Less10000        int    not null,
     More10000        int    not null
   );

  INSERT into ImageCountStats
      select (id.CTDDateTime >= _midPoint)                     as upCast,
              floor(i.depth / _depthBinSize)                   as bucketIdx,
             (floor(i.depth / _depthBinSize) * _depthBinSize)  as bucketDepth,
             Count(i.ImageId)                                  as ImageCount,
             sum(i.PixelCount)                                 as totalPixelCount,
             sum(i.PixelCount <=   500.0)                                   as  Less500,
             sum((i.PixelCount >   500.0)  and  (i.PixelCount <=  1000.0))  as  Less1000,
             sum((i.PixelCount >  1000.0)  and  (i.PixelCount <=  5000.0))  as  Less5000,
             sum((i.PixelCount >  5000.0)  and  (i.PixelCount <= 10000.0))  as  Less10000,
             sum((i.PixelCount >  10000.0))                                 as  More10000
             
          from Images i
          join (SipperFiles sf)     on  (sf.SipperFileId = i.SipperFileId)
          join (InstrumentData id)  on  (id.SipperFileId = i.SipperFileId  and  id.ScanLine = (floor(i.TopLeftRow / 4096) * 4096))
          where  sf.CruiseName = _cruiseName  and  sf.StationName = _stationName  and  sf.DeploymentNum = _deploymentNum
                 and  ((_classId < 0)  or  (i.Class1Id = _classId))
          group by (id.CTDDateTime >= _midPoint), floor(i.depth / _depthBinSize);



  select (id.CTDDateTime >= _midPoint)                       as upCast,
          floor(id.depth /  _depthBinSize)                   as bucketIdx,
         (floor(id.depth /  _depthBinSize) * _depthBinSize)  as bucketDepth,
         count(*) * 4096   as NumScanLines,
         max(id.CTDDateTime)          as  CTDDateTime,
         ics.ImageCount               as  ImageCont,
         ics.TotalPixelCount          as  TotalPixelCount,
         ics.Less500                  as  '<=500',
         ics.Less1000                 as  '<=1000',
         ics.less5000                 as  '<=5000',
         ics.less10000                as  '<=10000',
         ics.More10000                as  '>10000',
         avg(id.FlowRate1)            as  FlowRate1,           stddev(id.FlowRate1)            as  FlowRate1SD,
         avg(id.Density)              as  Density,             stddev(id.Density)              as  DensitySD,
         avg(id.Fluorescence)         as  Fluorescence,        stddev(id.Fluorescence)         as  FluorescenceSD,
         avg(id.FluorescenceSensor)   as  FluorescenceSensor,  stddev(id.FluorescenceSensor)   as  FluorescenceSensorSD,
         avg(id.Oxygen)               as  Oxygen,              stddev(id.Oxygen)               as  OxygenSD,
         avg(id.OxygenSensor)         as  OxygenSensor,        stddev(id.OxygenSensor)         as  OxygenSensorSD,
         avg(id.Pressure)             as  Pressure,            stddev(id.Pressure)             as  PressureSD,
         avg(id.RecordRate)           as  RecordRate,          stddev(id.RecordRate)           as  RecordRateSD,
         avg(id.Salinity)             as  Salinity,            stddev(id.Salinity)             as  SalinitySD,
         avg(id.SoundVelocity)        as  SoundVelocity,       stddev(id.SoundVelocity)        as  SoundVelocitySD,
         avg(id.Temperature)          as  Temperature,         stddev(id.Temperature)          as  TemperatureSD,
         avg(id.Transmisivity)        as  Transmisivity,       stddev(id.Transmisivity)        as  TransmisivitySD,
         avg(id.TransmisivitySensor)  as  TransmisivitySensor, stddev(id.TransmisivitySensor)  as  TransmisivitySensorSD,
         avg(id.Turbidity)            as  Turbidity,           stddev(id.Turbidity)            as  TurbiditySD,
         avg(id.TurbiditySensor)      as  TurbiditySensor,     stddev(id.TurbiditySensor)      as  TurbiditySensorSD

      from InstrumentData id
      join (SipperFiles sf)            on  (sf.SipperFileId = id.SipperFileId)
      left join (ImageCountStats ics)  on  (ics.UpCast = (id.CTDDateTime >= _midPoint)  and  ics.Depth = (floor(id.depth / _depthBinSize) * _depthBinSize))
      where  sf.CruiseName = _cruiseName  and  sf.StationName = _stationName  and  sf.DeploymentNum = _deploymentNum
        and  id.CTDDateTime  > "2000-01-01 00:01:01"
        and  id.CTDDateTime  < "2020-12-31 23:59:59"
        and  id.CTDBattery   > 5.5  and  id.CTDBattery    < 14.0
        and  id.Depth        < 1000
        and  id.Temperature  > 0.0  and  id.Temperature   < 40.0
                                    and  id.Salinity      < 40.0
                                    and  id.Density       < 40.0
        and  id.Fluorescence > -2   and  id.Fluorescence  < 80.0
      group by (id.CTDDateTime >= _midPoint), floor(id.depth / _depthBinSize);

end;
//
delimiter ;





/**********************************************************************************************************************/
drop procedure if exists  InstrumentDataByUpAndDownCast2;

DELIMITER $$

CREATE procedure `InstrumentDataByUpAndDownCast2`(in  _cruiseName      varChar(10),
                                                  in  _stationName     varChar(10),
                                                  in  _deploymentNum   varChar(4)
                                                 )
begin
  declare _midPoint     datetime;

  set  _midPoint = InstrumentDataGetMidPointOfDeployment(_cruiseName, _stationName, _deploymentNum);

  select sf.SipperFileName,
         id.ScanLine             as  ScanLine,
         (id.CTDDateTime >= _midPoint) as upCast,
         id.depth                as  Depth,
         id.CTDDateTime          as  CTDDateTime,
         id.FlowRate1            as  FlowRate1,           
         id.Density              as  Density,             
         id.Fluorescence         as  Fluorescence,        
         id.FluorescenceSensor   as  FluorescenceSensor,  
         id.Oxygen               as  Oxygen,              
         id.OxygenSensor         as  OxygenSensor,        
         id.Pressure             as  Pressure,            
         id.RecordRate           as  RecordRate,          
         id.Salinity             as  Salinity,            
         id.SoundVelocity        as  SoundVelocity,       
         id.Temperature          as  Temperature,         
         id.Transmisivity        as  Transmisivity,       
         id.TransmisivitySensor  as  TransmisivitySensor, 
         id.Turbidity            as  Turbidity,           
         id.TurbiditySensor      as  TurbiditySensor

      from InstrumentData id
      join (SipperFiles sf)            on  (sf.SipperFileId = id.SipperFileId)
      where  sf.CruiseName = _cruiseName  and  sf.StationName = _stationName  and  sf.DeploymentNum = _deploymentNum
        and  id.Depth  < 1000
        and  id.CTDDateTime  > "2000-01-01 00:01:01"
        and  id.CTDDateTime  < "2020-12-31 23:59:59"
        and  id.CTDBattery   > 5.5  and  id.CTDBattery    < 14.0
        and  id.Temperature  > 0.0  and  id.Temperature   < 40.0
                                    and  id.Salinity      < 40.0
                                    and  id.Density       < 40.0
        and  id.Fluorescence > -2   and  id.Fluorescence  < 80.0
      order by (id.CTDDateTime >= _midPoint), id.depth;
end
$$
delimiter ;






/**********************************************************************************************************************/
drop procedure  if exists InstrumentDataByDepth;

delimiter //
create procedure  InstrumentDataByDepth (in  _cruiseName      varChar(10),
                                         in  _stationName     varChar(10),
                                         in  _deploymentNum   varchar(4),
                                         in  _className       varChar(64),
                                         in  _depthBinSize    int unsigned
                                        )
begin
  declare _classId      int       default 0;
  declare _maxDepth     float     default 0.0;
  declare _midPoint     datetime;

  if  (!isnull(_className)  and  (_className != ""))  then
    set  _classId = (select ClassId  from  Classes  where  ClassName = _className);
  else
    set  _classId = -1;
  end if;

  drop  temporary table if exists  ImageCountStats;

  create TEMPORARY table ImageCountStats
   (
     CruiseName       varchar(10),
     StationName      varChar(10),
     deploymentNum    varChar(4),
     DepthIdx         int    not null,
     Depth            float  not null,
     ImageCount       int    not null,
     TotalPixelCount  int    not null,
     Less254          int    not null,
     Less1016         int    not null,
     Less2287         int    not null,
     Less4065         int    not null,
     More4065         int    not null,

     key TheKey (CruiseName asc, StationName asc, deploymentNum asc, DepthIdx asc)
   );


/* 254,572,1016,2287 and 4065 pixels */


  INSERT into ImageCountStats
      select sf.CruiseName,
             sf.StationName,
             sf.DeploymentNum,
             floor(i.depth / _depthBinSize)                    as bucketIdx,
             (floor(i.depth / _depthBinSize) * _depthBinSize)  as bucketDepth,
             Count(i.ImageId)                                  as ImageCount,
             sum(i.PixelCount)                                 as totalPixelCount,
             sum(i.PixelCount <=   254.0)                                  as  Less254,
             sum((i.PixelCount >   254.0)  and  (i.PixelCount <= 1016.0))  as  Less1016,
             sum((i.PixelCount >  1016.0)  and  (i.PixelCount <= 2287.0))  as  Less2287,
             sum((i.PixelCount >  2287.0)  and  (i.PixelCount <= 4065.0))  as  Less4065,
             sum((i.PixelCount >  4065))                                   as  More4065

          from Images i
          join (SipperFiles sf)     on  (sf.SipperFileId = i.SipperFileId)
          join (classes c)          on  (c.ClassId       = i.Class1Id)
          where  (sf.CruiseName = _cruiseName)  and  (sf.StationName = _stationName)  and  (sf.DeploymentNum = _deploymentNum)  and  (InStr (c.ClassName, _className) > 0)
          group by sf.CruiseName, sf.StationName, sf.DeploymentNum, floor(i.depth / _depthBinSize);



  select  sf.CruiseName,
          sf.StationName,
          sf.DeploymentNum,
          floor(id.depth /  _depthBinSize)                    as bucketIdx,
          (floor(id.depth /  _depthBinSize) * _depthBinSize)  as bucketDepth,
          count(*) * 4096   as NumScanLines,
          ics.ImageCount               as  ImageCont,
          ics.TotalPixelCount          as  TotalPixelCount,
          ics.Less254                  as  '<=254',
          ics.Less1016                 as  '<=1016',
          ics.Less2287                 as  '<=2287',
          ics.Less4065                 as  '<=4065',
          ics.More4065                 as  '>4065',
          avg(id.FlowRate1)            as  FlowRate1,           stddev(id.FlowRate1)            as  FlowRate1SD,
          avg(id.Density)              as  Density,             stddev(id.Density)              as  DensitySD,
          avg(id.Fluorescence)         as  Fluorescence,        stddev(id.Fluorescence)         as  FluorescenceSD,
          avg(id.FluorescenceSensor)   as  FluorescenceSensor,  stddev(id.FluorescenceSensor)   as  FluorescenceSensorSD,
          avg(id.Oxygen)               as  Oxygen,              stddev(id.Oxygen)               as  OxygenSD,
          avg(id.OxygenSensor)         as  OxygenSensor,        stddev(id.OxygenSensor)         as  OxygenSensorSD,
          avg(id.Pressure)             as  Pressure,            stddev(id.Pressure)             as  PressureSD,
          avg(id.RecordRate)           as  RecordRate,          stddev(id.RecordRate)           as  RecordRateSD,
          avg(id.Salinity)             as  Salinity,            stddev(id.Salinity)             as  SalinitySD,
          avg(id.SoundVelocity)        as  SoundVelocity,       stddev(id.SoundVelocity)        as  SoundVelocitySD,
          avg(id.Temperature)          as  Temperature,         stddev(id.Temperature)          as  TemperatureSD,
          avg(id.Transmisivity)        as  Transmisivity,       stddev(id.Transmisivity)        as  TransmisivitySD,
          avg(id.TransmisivitySensor)  as  TransmisivitySensor, stddev(id.TransmisivitySensor)  as  TransmisivitySensorSD,
          avg(id.Turbidity)            as  Turbidity,           stddev(id.Turbidity)            as  TurbiditySD,
          avg(id.TurbiditySensor)      as  TurbiditySensor,     stddev(id.TurbiditySensor)      as  TurbiditySensorSD

       from InstrumentData id
       join (SipperFiles sf)            on  (sf.SipperFileId = id.SipperFileId)
       left join (ImageCountStats ics)  on  ((ics.CruiseName = sf.CruiseName)  and  (ics.StationName = sf.StationName)  and  (ics.DeploymentNum = sf.DeploymentNum)  and  (ics.Depth = (floor(id.depth / _depthBinSize) * _depthBinSize)))
       where  (sf.CruiseName = _cruiseName)  and  (sf.StationName = _stationName)  and  (sf.DeploymentNum = _deploymentNum) 
         and  id.Depth  < 1000
         and  id.CTDDateTime  > "2000-01-01 00:01:01"
         and  id.CTDDateTime  < "2020-12-31 23:59:59"
         and  id.CTDBattery   > 5.5  and  id.CTDBattery    < 14.0
         and  id.Temperature  > 0.0  and  id.Temperature   < 40.0
                                     and  id.Salinity      < 40.0
                                     and  id.Density       < 40.0
         and  id.Fluorescence > -2   and  id.Fluorescence  < 80.0
       group by sf.CruiseName, sf.StationName, sf.DeploymentNum, floor(id.depth / _depthBinSize);

end;
//

delimiter ;
      
      
      
      
      
/**********************************************************************************************************************/


drop procedure  if exists InstrumentDataByDepth_ZED;

delimiter //
create procedure  InstrumentDataByDepth_ZED (in  _cruiseName       varChar(10),
                                             in  _stationName      varChar(10),
                                             in  _deploymentNum1   varchar(4),
                                             in  _deploymentNum2   varchar(4),
                                             in  _deploymentNum3   varchar(4),
                                             in  _deploymentNum4   varchar(4),
                                             in  _className        varChar(64),
                                             in  _depthBinSize     int unsigned
                                            )
begin
  declare _classId      int       default 0;
  declare _maxDepth     float     default 0.0;
  declare _midPoint     datetime;

  declare _deploymentDesc  varchar(60);


  set  _deploymentDesc = concat(_deploymentNum1, "-", _deploymentNum2, "-", _deploymentNum3, "-", _deploymentNum4);

  if  (!isnull(_className)  and  (_className != ""))  then
    set  _classId = (select ClassId  from  Classes  where  ClassName = _className);
  else
    set  _classId = -1;
  end if;


  drop  temporary table if exists  ImageCountStats;


  create TEMPORARY table ImageCountStats
   (
     CruiseName       varchar(10),
     StationName      varChar(10),
     deploymentNum    varChar(4),
     DepthIdx         int    not null,
     Depth            float  not null,
     ImageCount       int    not null,
     TotalPixelCount  int    not null,
     Less254          int    not null,
     Less1016         int    not null,
     Less2287         int    not null,
     Less4065         int    not null,
     More4065         int    not null,

     key TheKey (CruiseName asc, StationName asc, deploymentNum asc, DepthIdx asc)
   );


/* 254,572,1016,2287 and 4065 pixels */


  INSERT into ImageCountStats
      select sf.CruiseName,
             sf.StationName,
             sf.DeploymentNum,
             floor(i.depth / _depthBinSize)                    as bucketIdx,
             (floor(i.depth / _depthBinSize) * _depthBinSize)  as bucketDepth,
             Count(i.ImageId)                                  as ImageCount,
             sum(i.PixelCount)                                 as totalPixelCount,
             sum(i.PixelCount <=   254.0)                                  as  Less254,
             sum((i.PixelCount >   254.0)  and  (i.PixelCount <= 1016.0))  as  Less1016,
             sum((i.PixelCount >  1016.0)  and  (i.PixelCount <= 2287.0))  as  Less2287,
             sum((i.PixelCount >  2287.0)  and  (i.PixelCount <= 4065.0))  as  Less4065,
             sum((i.PixelCount >  4065))                                   as  More4065

          from Images i
          join (SipperFiles sf)     on  (sf.SipperFileId = i.SipperFileId)
          join (classes c)          on  (c.ClassId       = i.Class1Id)
          where  (sf.CruiseName      = _cruiseName)    and  
                 (sf.StationName     = _stationName)  and  
                 ((sf.DeploymentNum   = _deploymentNum1) or (sf.DeploymentNum   = _deploymentNum2)  or  (sf.DeploymentNum   = _deploymentNum3) or  (sf.DeploymentNum   = _deploymentNum4))  and  
                 (InStr (c.ClassName, _className) > 0)
          group by sf.CruiseName, sf.StationName, floor(i.depth / _depthBinSize);



  select  sf.CruiseName,
          sf.StationName,
          _deploymentDesc,
          floor(id.depth /  _depthBinSize)                    as bucketIdx,
          (floor(id.depth /  _depthBinSize) * _depthBinSize)  as bucketDepth,
          count(*) * 4096   as NumScanLines,
          ics.ImageCount               as  ImageCont,
          ics.TotalPixelCount          as  TotalPixelCount,
          ics.Less254                  as  '<=254',
          ics.Less1016                 as  '<=1016',
          ics.Less2287                 as  '<=2287',
          ics.Less4065                 as  '<=4065',
          ics.More4065                 as  '>4065',
          avg(id.FlowRate1)            as  FlowRate1,           stddev(id.FlowRate1)            as  FlowRate1SD,
          avg(id.Density)              as  Density,             stddev(id.Density)              as  DensitySD,
          avg(id.Fluorescence)         as  Fluorescence,        stddev(id.Fluorescence)         as  FluorescenceSD,
          avg(id.FluorescenceSensor)   as  FluorescenceSensor,  stddev(id.FluorescenceSensor)   as  FluorescenceSensorSD,
          avg(id.Oxygen)               as  Oxygen,              stddev(id.Oxygen)               as  OxygenSD,
          avg(id.OxygenSensor)         as  OxygenSensor,        stddev(id.OxygenSensor)         as  OxygenSensorSD,
          avg(id.Pressure)             as  Pressure,            stddev(id.Pressure)             as  PressureSD,
          avg(id.RecordRate)           as  RecordRate,          stddev(id.RecordRate)           as  RecordRateSD,
          avg(id.Salinity)             as  Salinity,            stddev(id.Salinity)             as  SalinitySD,
          avg(id.SoundVelocity)        as  SoundVelocity,       stddev(id.SoundVelocity)        as  SoundVelocitySD,
          avg(id.Temperature)          as  Temperature,         stddev(id.Temperature)          as  TemperatureSD,
          avg(id.Transmisivity)        as  Transmisivity,       stddev(id.Transmisivity)        as  TransmisivitySD,
          avg(id.TransmisivitySensor)  as  TransmisivitySensor, stddev(id.TransmisivitySensor)  as  TransmisivitySensorSD,
          avg(id.Turbidity)            as  Turbidity,           stddev(id.Turbidity)            as  TurbiditySD,
          avg(id.TurbiditySensor)      as  TurbiditySensor,     stddev(id.TurbiditySensor)      as  TurbiditySensorSD

       from InstrumentData id
       join (SipperFiles sf)            on  (sf.SipperFileId = id.SipperFileId)
       left join (ImageCountStats ics)  on  ((ics.CruiseName = sf.CruiseName)  and  (ics.StationName = sf.StationName)  and  (ics.DeploymentNum = sf.DeploymentNum)  and  (ics.Depth = (floor(id.depth / _depthBinSize) * _depthBinSize)))
       where  (sf.CruiseName = _cruiseName)
         and  (sf.StationName = _stationName)  
         and  ((sf.DeploymentNum = _deploymentNum1)  or  (sf.DeploymentNum = _deploymentNum2)  or  (sf.DeploymentNum = _deploymentNum3)  or  (sf.DeploymentNum = _deploymentNum4))
         and  id.Depth  < 1000
         and  id.CTDDateTime  > "2000-01-01 00:01:01"
         and  id.CTDDateTime  < "2020-12-31 23:59:59"
         and  id.CTDBattery   > 5.5  and  id.CTDBattery    < 14.0
         and  id.Temperature  > 0.0  and  id.Temperature   < 40.0
                                     and  id.Salinity      < 40.0
                                     and  id.Density       < 40.0
         and  id.Fluorescence > -2   and  id.Fluorescence  < 80.0
       group by sf.CruiseName, sf.StationName, floor(id.depth / _depthBinSize);

end;
//

delimiter ;






/**********************************************************************************************************************/
drop procedure  if exists InstrumentDataUpdateLatitudeAndLongitude;

delimiter //

create procedure  InstrumentDataUpdateLatitudeAndLongitude 
      (
       in  _dateTimeStart          datetime, 
       in  _dateTimeEnd            datetime, 
       in  _latitude               double,
       in  _longitude              double
      )

begin
  update  InstrumentData id
    set  id.Latitude   = _latitude,
         id.Longitude = _longitude
         
    where  (CTDDateTime >= _dateTimeStart)  and  (CTDDateTime <= _dateTimeEnd);
end
//
delimiter ;




drop procedure  if exists InstrumentDataByTemporalOrder;
delimiter //


create procedure  InstrumentDataByTemporalOrder (in  _cruiseName      varChar(10),
                                                 in  _stationName     varChar(10),
                                                 in  _deploymentNum   varchar(4)
                                                 )
begin
  select id.* from InstrumentData id 
         join(SipperFiles sf) on(sf.SipperFileId = id.SipperFileId)
         where  ((sf.CruiseName    = _cruiseName)     or  (_cruiseName    = "")  or  (isnull(_cruiseName)))    and
                ((sf.StationName   = _stationName)    or  (_stationName   = "")  or  (isnull(_stationName)))   and
                ((sf.DeploymentNum = _deploymentNum)  or  (_deploymentNum = "")  or  (isnull(_deploymentNum))) and
                (id.ScanLine mod (32 * 1024) = 0)
         order by id.CTDDateTime, id.ScanLine;          
end
//
delimiter ;






drop procedure  if exists InstrumentDataGetVolumePerMeterDepth;
delimiter //


create procedure  InstrumentDataGetVolumePerMeterDepth (in  _sipperFileName   varChar(48),
                                                        in  _depthBinSize     float
                                                       )
begin
  declare  _sipperFileId   int unsigned default 0;
  declare  _scanRate       int unsigned default 0;
  declare  _secsPerRec     float default 0.0;
  declare  _chamberWidth   float default 0.0;
  
  select  sf.SipperFileId, sf.ScanRate, d.ChamberWidth  into  _sipperFileId, _scanRate, _chamberWidth
      from SipperFiles sf  
      join(Deployments d)  on(d.CruiseName = sf.CruiseName  and  d.StationName = sf.StationName  and  d.DeploymentNum = sf.DeploymentNum)
      where  sf.SipperFileName = _sipperFileName;

  /*
  set _sipperFileId = (select sf.SipperFileId  from  SipperFiles sf  where  sf.SipperFileName = _sipperFileName);
  set _scanRate     = (select sf.ScanRate      from  SipperFiles sf  where  sf.SipperFileName = _sipperFileName);
  set _chamberWidth = (select d.ChamberWidth)  from Deployments d  where d.CruiseName  
  */
    
  if  _scanRate < 1  then
    set _scanRate = 24950;
  end if;
  
  if  _chamberWidth < 0.01  then
    set  _chamberWidth = 0.096;
  end if;
  
  set _secsPerRec = 4096 / _scanRate;

  select   Floor(id.depth / _depthBinSize)                                     as BinId,
           Floor(id.depth / _depthBinSize) * _depthBinSize                     as BinDepth,
           sum(id.FlowRate1 * _secsPerRec * _chamberWidth * 0.096)  as VolumeSampled
         from  InstrumentData id
         where id.SipperFileId = _sipperFileId
         group by Floor(id.depth / _depthBinSize)
         order by Floor(id.depth / _depthBinSize); 
end
//
delimiter ;






drop procedure  if exists InstrumentDataDeploymentVolumeSampled;
delimiter //

create procedure  InstrumentDataDeploymentVolumeSampled (in  _cruiseName      varChar(10),
                                                         in  _stationName     varChar(10),
                                                         in  _deploymentNum   varchar(4),
                                                         in  _depthBinSize    float
                                                        )
begin
  declare  _scanRate       float unsigned default 24950;
  declare  _secsPerRec     float default 0.0;
  declare  _midPoint       DateTime default null;
  
  declare  _chamberWidth   float  default 0.096;
  declare  _cropLeft       int    default 0;
  declare  _cropRight      int    default 4095;


  set  @deploymentNum = _deploymentNum;
  if  (_deploymentNum is null)  or  (_deploymentNum = "")  or (_deploymentNum = " ")  then
     set @deploymentNum = (select d.DeploymentNum  from  Deployments d where d.CruiseName    = _cruiseName  and  d.StationName   = _stationName);
  end if;
  
  set _scanRate = (select max(sf.ScanRate)  from  SipperFiles sf  
					            where  (sf.CruiseName    = _cruiseName)  and
								             (sf.StationName   = _stationName) and 
                             (sf.DeploymentNum = @deploymentNum));
  if  _scanRate < 100  then
    set _scanRate = 24950.3;
  end if;
  
  select d.CropLeft, d.CropRight, d.ChamberWidth  into  _cropLeft, _cropRight, _chamberWidth
     from Deployments d
		 where  (d.CruiseName     = _cruiseName)  and
	          (d.StationName    = _stationName) and 
            ((d.DeploymentNum = @deploymentNum));

  if  (_chamberWidth < 0.001)  then
    set  _chamberWidth = 0.096;
  end if;
  
  
  set _secsPerRec = 4096.0 / _scanRate;
  set _midPoint = InstrumentDataGetMidPointOfDeployment(_cruiseName, _stationName, @deploymentNum);


  select   (id.CtdDateTime < _midPoint)                     as DownCast,
           Floor(id.depth / _depthBinSize)                  as BinId,
           Floor(id.depth / _depthBinSize) * _depthBinSize  as BinDepth,
           4096 * count(id.ScanLine)                        as ScanLines,
           sum(id.FlowRate1 * _secsPerRec * _chamberWidth * 0.096)  as VolumeSampled
           
         from  InstrumentData id
         join(SipperFiles sf)  on  (sf.SipperFileId = id.SipperFileId)
         where      (sf.CruiseName    = _cruiseName)  
               and  (sf.StationName   = _stationName) 
               and  ((sf.DeploymentNum = _deploymentNum)  or  (_deploymentNum = " "))
               and  id.CTDDateTime > "2000-01-01 00:01:01"
               and  id.CTDDateTime < "2020-01-01 00:01:01"
               and  id.CTDBattery   > 5.5   and  id.CTDBattery    < 14.0
               and  id.Depth        > 0.0   and  id.Depth         < 500
               and  id.Temperature  > 0.0   and  id.Temperature   < 40.0
                                            and  id.Salinity      < 40.0
                                            and  id.Density       < 40.0
               and  id.Fluorescence > -2    and  id.Fluorescence  < 80.0
               
         group by (id.CtdDateTime < _midPoint), Floor(id.depth / _depthBinSize)
         order by (id.CtdDateTime < _midPoint), Floor(id.depth / _depthBinSize); 
end
//
delimiter ;






drop procedure  if exists InstrumentDataRetrieveGpsInfo;
delimiter //

create procedure  InstrumentDataRetrieveGpsInfo (in  _cruiseName      varChar(10),
                                                 in  _stationName     varChar(10),
                                                 in  _deploymentNum   varChar(4),
                                                 in  _timeInterval    int
                                                )
begin
  declare  _ctdDateTime  DateTime;
  declare  _utcDateTime  DateTime;
  declare  _latitude     double;
  declare  _longitude    double;
  declare  _gpsAdjSecs   int   default null;
  declare  ExitLoop      bool  default  false;

  declare cur1 cursor for  select  id.CTDDateTime                                         as  CTDDateTime,
                                   date_add(id.CTDDateTime, INTERVAL _gpsAdjSecs SECOND)  as  UtcDateTime,
                                   avg(id.Latitude)                                       as  Latitude,
                                   avg(id.Longitude)                                      as  Longitude
                                 from InstrumentData id
                                 join (SipperFiles sf) on (sf.SipperFileId = id.SipperFileId)
                                 where sf.CruiseName    = _cruiseName     and 
                                       sf.StationName   = _stationName    and 
                                       sf.deploymentNum = _deploymentNum  and 
                                       id.FlowRate1 > 0
                                 group by sf.CruiseName, sf.StationName, sf.DeploymentNum,
                                       floor(UNIX_TIMESTAMP(date_add(id.CTDDateTime, INTERVAL _gpsAdjSecs SECOND)) / _timeInterval);

  declare continue HANDLER for not found set ExitLoop = true;

  select d.SyncTimeStampCTD, d.SyncTimeStampGPS  into  @syncCTD, @syncGPS
    from  Deployments d  where d.CruiseName = _cruiseName  and  d.StationName = _stationName  and  (d.DeploymentNum = _deploymentNum   or  _deploymentNum is null  or  _deploymentNum = "")  limit 1;

  set  _gpsAdjSecs = TO_SECONDS(@syncGPS) - TO_SECONDS(@syncCTD);
  
  drop  temporary table if exists  GpsTempData;

  create TEMPORARY table GpsTempData
   (
     CTDDateTime       DateTime,
     UtcDateTime       DateTime,
     Latitude          double  default 0.0,
     Longitude         double  default 0.0,
     courseOverGround  float   default 0.0,
     SpeedOverGround   float   default 0.0
   );

  open cur1;

  TheMainLoop:  loop

    fetch  cur1 into _ctdDateTime, _utcDateTime, _latitude, _longitude;
    if ExitLoop then
       close  cur1;
       leave  TheMainLoop;
    end if;
    
    call  GpsDataGetEstimate (_cruiseName, _utcDateTime, @longitude, @longitude, @cog, @sog);

    insert  into GpsTempData  values (_ctdDateTime, _utcDateTime, _latitude, _longitude, @cog, @sog);
  end loop  TheMainLoop;


  select  * from  GpsTempData  order by  UtcDateTime;

  /* drop  temporary table if exists  GpsTempData; */
end
//
delimiter ;



/******************************************************************************************************************/
/******************************************************************************************************************/
/******************************************************************************************************************/
drop procedure  if exists InstrumentDataBinByDepthIntoTempFile;
delimiter //

create procedure  InstrumentDataBinByDepthIntoTempFile (in  _cruiseName      varChar(10),
                                                        in  _stationName     varChar(10),
                                                        in  _deploymentNum   varchar(4),
                                                        in  _depthBinSize    float
                                                       )
begin
  declare  _scanRate       float unsigned default 24950;
  declare  _secsPerRec     float default 0.0;
  declare  _midPoint       DateTime default null;
  
  declare  _chamberWidth   float  default 0.096;
  declare  _cropLeft       int    default 0;
  declare  _cropRight      int    default 4095;
  
  set _scanRate = (select max(sf.ScanRate)  from  SipperFiles sf  
					            where  (sf.CruiseName    = _cruiseName)  and
								             (sf.StationName   = _stationName) and 
                             ((sf.DeploymentNum = _deploymentNum)  or (_deploymentNum = "")));
  if  _scanRate < 100  then
    set _scanRate = 24950.3;
  end if;
  
  set  @deploymentNum = _deploymentNum;
  if  (_deploymentNum is null)  or  (_deploymentNum = "")  or (_deploymentNum = " ")  then
     set @deploymentNum = (select d.DeploymentNum  from  Deployments d where d.CruiseName    = _cruiseName  and  d.StationName   = _stationName);
  end if;

  select d.CropLeft, d.CropRight, d.ChamberWidth  into  _cropLeft, _cropRight, _chamberWidth
     from Deployments d
		 where  (d.CruiseName     = _cruiseName)  and
	          (d.StationName    = _stationName) and 
            ((d.DeploymentNum =  @deploymentNum) or (_deploymentNum = ""));

  if  (_chamberWidth < 0.001)  then
    set  _chamberWidth = 0.096;
  end if;
  
  set _secsPerRec = 4096.0 / _scanRate;
  set _midPoint = InstrumentDataGetMidPointOfDeployment(_cruiseName, _stationName, @deploymentNum);

  drop temporary table if exists InstrumentDataBinByDepthTempTable;

  create temporary table if not exists InstrumentDataBinByDepthTempTable  ENGINE=MyISAM as ( 
    select  (id.CtdDateTime < _midPoint)                     as DownCast,
             Floor(id.depth / _depthBinSize)                  as BinId,
             Floor(id.depth / _depthBinSize) * _depthBinSize  as BinDepth,
             4096 * count(id.ScanLine)                        as ScanLines,
             sum(id.FlowRate1 * _secsPerRec * _chamberWidth * 0.096)  as VolumeSampled,
             avg(id.Temperature)                              as TemperatureMean,
             avg(id.Salinity)                                 as SalinityMean,
             avg(id.Density)                                  as DenisityMean,
             avg(id.Fluorescence)                             as FluorescenceMean,
             avg(id.FluorescenceSensor)                       as FluorescenceSensorMean,
             avg(id.Oxygen)                                   as OxygenMean,
             avg(id.Depth)                                    as DepthMean,
             avg(id.Transmisivity)                            as TransmisivityMean,
             avg(id.Turbidity)                                as TurbidityMean,
             avg(id.CdomFluorescence)                         as CdomFluorescenceMean
           
           from  InstrumentData id
           join(SipperFiles sf)  on  (sf.SipperFileId = id.SipperFileId)
           where      (sf.CruiseName    = _cruiseName)  
                 and  (sf.StationName   = _stationName) 
                 and  ((sf.DeploymentNum = @deploymentNum)  or  (_deploymentNum = " "))
                 and  id.CTDDateTime > "2000-01-01 00:01:01"
                 and  id.CTDDateTime < "2020-01-01 00:01:01"
                 and  id.CTDBattery   > 5.5   and  id.CTDBattery    < 14.0
                 and  id.Depth        > 0.0   and  id.Depth         < 500
                 and  id.Temperature  > 0.0   and  id.Temperature   < 40.0
                                              and  id.Salinity      < 40.0
                                              and  id.Density       < 40.0
                 and  id.Fluorescence > -2    and  id.Fluorescence  < 80.0
               
           group by (id.CtdDateTime < _midPoint), Floor(id.depth / _depthBinSize)
           order by (id.CtdDateTime < _midPoint), Floor(id.depth / _depthBinSize)
  );
end
//
delimiter ;

/******************************************************************************************************************/
/******************************************************************************************************************/
/******************************************************************************************************************/
/******************************************************************************************************************/










drop procedure  if exists InstrumentDataBinByMeterDepth;
delimiter //

create procedure  InstrumentDataBinByMeterDepth (in  _cruiseName      varChar(10),
                                                 in  _stationName     varChar(10),
                                                 in  _deploymentNum   varchar(4),
                                                 in  _depthBinSize    float
                                                )
begin
  declare  _scanRate       float unsigned default 24950;
  declare  _secsPerRec     float default 0.0;
  declare  _midPoint       DateTime default null;
  
  declare  _chamberWidth   float  default 0.096;
  declare  _cropLeft       int    default 0;
  declare  _cropRight      int    default 4095;
  
  set _scanRate = (select max(sf.ScanRate)  from  SipperFiles sf  
					            where  (sf.CruiseName    = _cruiseName)  and
								             (sf.StationName   = _stationName) and 
                             ((sf.DeploymentNum = _deploymentNum)  or (_deploymentNum = "")));
  if  _scanRate < 100  then
    set _scanRate = 24950.3;
  end if;
  
  set  @deploymentNum = _deploymentNum;
  if  (_deploymentNum is null)  or  (_deploymentNum = "")  or (_deploymentNum = " ")  then
     set @deploymentNum = (select d.DeploymentNum  from  Deployments d where d.CruiseName    = _cruiseName  and  d.StationName   = _stationName);
  end if;

  

  select d.CropLeft, d.CropRight, d.ChamberWidth  into  _cropLeft, _cropRight, _chamberWidth
     from Deployments d
		 where  (d.CruiseName     = _cruiseName)  and
	          (d.StationName    = _stationName) and 
            ((d.DeploymentNum =  @deploymentNum) or (_deploymentNum = ""));

  if  (_chamberWidth < 0.001)  then
    set  _chamberWidth = 0.096;
  end if;
  
  set _secsPerRec = 4096.0 / _scanRate;
  set _midPoint = InstrumentDataGetMidPointOfDeployment(_cruiseName, _stationName, @deploymentNum);

  select   (id.CtdDateTime < _midPoint)                     as DownCast,
           Floor(id.depth / _depthBinSize)                  as BinId,
           Floor(id.depth / _depthBinSize) * _depthBinSize  as BinDepth,
           4096 * count(id.ScanLine)                        as ScanLines,
           sum(id.FlowRate1 * _secsPerRec * _chamberWidth * 0.096)  as VolumeSampled,
           avg(id.Temperature)                              as TemperatureMean,
           avg(id.Salinity)                                 as SalinityMean,
           avg(id.Density)                                  as DenisityMean,
           avg(id.Fluorescence)                             as FluorescenceMean,
           avg(id.FluorescenceSensor)                       as FluorescenceSensorMean,
           avg(id.Oxygen)                                   as OxygenMean,
           avg(id.Depth)                                    as DepthMean,
           avg(id.Transmisivity)                            as TransmisivityMean,
           avg(id.Turbidity)                                as TurbidityMean,
           avg(id.CdomFluorescence)                         as CdomFluorescenceMean
           
         from  InstrumentData id
         join(SipperFiles sf)  on  (sf.SipperFileId = id.SipperFileId)
         where      (sf.CruiseName    = _cruiseName)  
               and  (sf.StationName   = _stationName) 
               and  ((sf.DeploymentNum = @deploymentNum)  or  (_deploymentNum = " "))
               and  id.CTDDateTime > "2000-01-01 00:01:01"
               and  id.CTDDateTime < "2020-01-01 00:01:01"
               and  id.CTDBattery   > 5.5   and  id.CTDBattery    < 14.0
               and  id.Depth        > 0.0   and  id.Depth         < 500
               and  id.Temperature  > 0.0   and  id.Temperature   < 40.0
                                            and  id.Salinity      < 40.0
                                            and  id.Density       < 40.0
               and  id.Fluorescence > -2    and  id.Fluorescence  < 80.0
               
         group by (id.CtdDateTime < _midPoint), Floor(id.depth / _depthBinSize)
         order by (id.CtdDateTime < _midPoint), Floor(id.depth / _depthBinSize); 
end
//
delimiter ;






























/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/
/************************************************************************************************************************/
drop procedure  if   exists  InstrumentUpdateFromGpsData;

DELIMITER $$

create  procedure InstrumentUpdateFromGpsData(in  _cruiseName  char(10))
begin
  declare  _sipperFileId    int default 0;
  declare  _ctdDataTime     datetime;
  
  declare  _lastSipperFileId  int default 0;
  
  declare  _syncGpsDataTime   datetime;
  declare  _syncCtdDateTime   datetime;
  
  declare  _stationName       char(10); 
  declare  _deploymentNum     char(4);
  declare  _sipperFileName    char(48)  default null;
  
  declare  _deltaGpsCtdSecs   int  default 0;
  
  declare  _adjCtdDateTime    datetime;

  declare  _loopCount         int  default 0;

  declare  ExitLoop           boolean default FALSE;       

  declare cur1 cursor for  select distinct  id.SipperFileId, id.CTDDateTime from InstrumentData id
                                  join(SipperFiles sf)  on(sf.SipperFileId = id.SipperFileId)
                                  where sf.CruiseName=_cruiseName  and  id.CTDDateTime > "2002/01/01"
                                  order by sf.SipperFileName, id.CTDDateTime;

  declare continue HANDLER for not found set ExitLoop = true;


  open cur1;

  set  _deltaGpsCtdSecs = 0;

  TheMainLoop:  loop

    fetch  cur1 into _sipperFileId, _ctdDataTime;
    if ExitLoop then
       close  cur1;
       leave  TheMainLoop;
    end if;

    if  _sipperFileId <> _lastSipperFileId  then
      set  _lastSipperFileId = _sipperFileId;
        select sf.stationName, sf.deploymentNum, sf.SipperFileName  into  _stationName, _deploymentNum, _sipperFileName
               from  SipperFiles sf
               where  sf.SipperFileId = _sipperFileId;

        if  ExitLoop  then
         select "ExitLoop true afer selecting from SipperFiles";
        end if;

        select  d.SyncTimeStampCTD, d.SyncTimeStampGPS  into  _syncCtdDateTime, _syncGpsDataTime
               from Deployments d
               where (d.CruiseName = _cruiseName)  and  (d.StationName = _stationName)  and  (d.DeploymentNum = _deploymentNum);
         
        if  ExitLoop  then
         select "ExitLoop true afer selecting from Deployments";
        end if;
        
        
        /* select  _stationName, _deploymentNum, _sipperFileName, _syncCtdDateTime, _syncGpsDataTime; */
        

        set _deltaGpsCtdSecs = to_seconds(_syncGpsDataTime) - to_seconds(_syncCtdDateTime);

        if  (_deltaGpsCtdSecs = 0) then
            select "_deltaGpsCtdSecs = 0", _cruiseName, _stationName, _deploymentNum, _sipperFileId, _sipperFileName, _syncCtdDateTime, _syncGpsDataTime;
        end if;

        /* select   _sipperFileId, _stationName, _deploymentNum, _sipperFileName, _syncCtdDateTime, _syncGpsDataTime, _deltaGpsCtdSecs; */

    end if;
       
    set  _adjCtdDateTime = timestampadd(second, _deltaGpsCtdSecs, _ctdDataTime);
    
    call  GpsDataGetEstimate (_cruiseName, _adjCtdDateTime, @latitude, @longitude, @cog, @sog);

    if  ExitLoop  then
      select "ExitLoop true afer Calling    GpsDataGetEstimate", _cruiseName,  _stationName, _deploymentNum, _sipperFileName,  _syncCtdDateTime, _syncGpsDataTime, _adjCtdDateTime, @latitude, @longitude;
      set ExitLoop = False;
    end if;


    if  (@latitude is not null)  and  (@latitude <> 0.0)  then
       update  InstrumentData id
               set  id.Latitude   = @latitude,
                    id.Longitude = @longitude
       where  (id.SipperFileId = _sipperFileId)  and  (id.CTDDateTime = _ctdDataTime);
    end if;
                                                
    set  _loopCount = _loopCount + 1;
  end loop  TheMainLoop;
end
$$
delimiter ;




drop procedure  if   exists  InstrumentDataByTemporalSummary;

delimiter //

create procedure InstrumentDataByTemporalSummary(in  _cruiseName      varChar(10),
                                                 in  _stationName     varChar(10),
                                                 in  _deploymentNum   varchar(4),
                                                 in  _timeBucketSize  float,
                                                 in  _depthBucketSize float
												)
begin
  select  sf.CruiseName, sf.stationName, sf.DeploymentNum,
	      id.CtdDatetime,
          (_timeBucketSize * avg(id.FlowRate2) * d.chamberWidth * 0.096)  as  'VolumeSampled',
          avg(id.Depth),
          avg(id.Density),
          avg(id.Conductivity),
          avg(id.Fluorescence),
          avg(id.CdomFluorescence),
          avg(id.Oxygen),
          avg(id.Pressure),
          avg(id.Salinity),
          avg(id.Temperature),
          avg(id.Transmisivity),
          avg(id.Turbidity),
          avg(id.FlowRate2)
     from InstrumentData id 
         join(SipperFiles sf) on(sf.SipperFileId = id.SipperFileId)
         join(Deployments d)  on(d.CruiseName = sf.CruiseName  and  d.StationName = sf.StationName  and  d.deploymentNum = sf.deploymentNum)
     where  ((sf.CruiseName    = _cruiseName)     or  (_cruiseName    = "")  or  (isnull(_cruiseName)))    and
         ((sf.StationName   = _stationName)    or  (_stationName   = "")  or  (isnull(_stationName)))   and
         ((sf.DeploymentNum = _deploymentNum)  or  (_deploymentNum = "")  or  (isnull(_deploymentNum))) and
         (id.CTDDateTime  >  "2000-01-01 00:01:01")  and  (id.CTDDateTime  < "2020-12-31 23:59:59")     and
         (id.CTDBattery   > 5.5)   and  (id.CTDBattery    < 14.0)  and
         (id.Depth        < 1000)  and  (id.Temperature  > 0.0   and  id.Temperature   < 40.0)   and
         (id.Fluorescence > -2)    and  (id.Fluorescence  < 80.0)
     group by sf.CruiseName,
              sf.StationName,
              sf.DeploymentNum, 
			        truncate(TIME_TO_SEC(id.CtdDatetime) / _timeBucketSize, 0), 
              truncate(id.Depth / _depthBucketSize, 0)
     order by id.CTDDateTime;
end
//

delimiter ;





drop procedure  if   exists  InstrumentDataGetDeploymentTimes;

delimiter //

create procedure InstrumentDataGetDeploymentTimes(in  _cruiseName      varChar(10),
                                                  in  _stationName     varChar(10),
                                                  in  _deploymentNum   varchar(4)
                                                 )
begin
  set @utcDelta = (select  TIMESTAMPDIFF(Second, d.SyncTimeStampCTD , d.SyncTimeStampGPS)
                   from Deployments d
                   where d.CruiseName = _cruiseName  and  d.StationName=_stationName  and d.DeploymentNum = _deploymentNum);
                   
  set @clockDelta = (select  TIMESTAMPDIFF(Second, d.SyncTimeStampCTD , d.SyncTimeStampActual)
                     from Deployments d
                     where d.CruiseName = _cruiseName  and  d.StationName=_stationName  and d.DeploymentNum = _deploymentNum);
                   

  select   min(id.CTDDateTime) as 'ctdDateTimeStart', 
           max(id.CTDDateTime) as 'ctdDateTimeEnd',
           TIMESTAMPADD(Second, @utcDelta,   min(id.CTDDateTime))  as 'utcDateTimeStart',
           TIMESTAMPADD(Second, @utcDelta,   max(id.CTDDateTime))  as 'utcDateTimeEnd',
           TIMESTAMPADD(Second, @clockDelta, min(id.CTDDateTime))  as 'clockDateTimeStart',
           TIMESTAMPADD(Second, @clockDelta, max(id.CTDDateTime))  as 'clockDateTimeEnd'
           
    from InstrumentData id
    join (SipperFiles sf)  on(sf.SipperFileID = id.SipperFileId)
     where sf.CruiseName = _cruiseName  and  sf.StationName=_stationName  and  sf.DeploymentNum=_deploymentNum
      and  id.Depth >= 0.5  and  id.Depth < 500.0
      and  id.CTDDateTime  > "2000-01-01 00:01:01"
      and  id.CTDDateTime  < "2018-12-31 23:59:59"
      and  id.CTDBattery   > 5.5   and  id.CTDBattery    < 14.0
      and  id.Temperature  > 0.0   and  id.Temperature   < 40.0
                                   and  id.Salinity      < 40.0
                                   and  id.Density       < 40.0;
end
//

delimiter ;


