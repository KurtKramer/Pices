drop table if exists InstrumentAssignments;

create table  InstrumentAssignments
(
	SipperFileId     int      NOT NULL,
	InstrumentName   char(10) NOT NULL,
	SerialPortNum    int      NOT NULL,
 
    Primary Key (SipperFileId)
)  
;
