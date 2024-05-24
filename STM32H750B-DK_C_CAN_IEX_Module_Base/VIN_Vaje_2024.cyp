##PROJECT_GLOBAL_BEGIN
[Programs]
Count=1

[Misc Info]
Author=
Company=
Version=1.0
EditTime=7095
CyProVersion=2.8.0

[Protection]
Level=0
Password=
##PROJECT_GLOBAL_END

##PROGRAM_BEGIN_1
#PROJECT_OPTIONS_BEGIN
[Program]
Name=New Program

[VCP]
I2CPriority=5
SendSource=1
SendAlloc=1
ProtectWithPasswd=0
Password=
IORefresh=3
ScanOverrunStopsProgram=1
OutputRetentive=0
Com1Mode=1
Com1Baudrate=19200
Com1Data=0
Com2Mode=1
Com2Baudrate=19200
Com2Data=0
HSCMode=0
EthAbusEnable=1
EthModbusEnable=0
WANUrl=
PushEvent=0
PushUrl=
ModbusDelay=20
ModbusDeviceAddress=1
ModbusPLCDataModel=2
ModbusAddress=0
ModbusRegisterCount=1
ModbusCoilsArrayVar=
ModbusRegistersArrayVar=
PLCCoilVars=
PLCRegisterVars=
ModbusCoilAddresses=
ModbusRegisterAddresses=

[Misc Info]
MonitorHistorySpeed=10

[Hardware]
CPUUnit=4
Card1=11
Type1=0
NAD1=4468
VarPrefix1=bio00_
VarAreaTyp1.5.0=
VarAreaTyp1.5.1=
Card2=251
Type2=0
NAD2=750
VarPrefix2=stmh700_

[Net]
PrgDevice00=9322
CurrentNAD=9322

[Monitor01]
VarCount=13
VarName1=bio00_ix00
VarBase1=1
VarValue1=0
VarColor1=0
VarIndex1=0
VarName2=bio00_ix01
VarBase2=1
VarValue2=0
VarColor2=0
VarIndex2=1
VarName3=bio00_qx00
VarBase3=1
VarValue3=0
VarColor3=0
VarIndex3=2
VarName4=bio00_qx01
VarBase4=1
VarValue4=0
VarColor4=0
VarIndex4=3
VarName5=bio00_qx02
VarBase5=1
VarValue5=0
VarColor5=0
VarIndex5=4
VarName6=stm00_ix00
VarBase6=1
VarValue6=0
VarColor6=0
VarIndex6=5
VarName7=stm00_qx00
VarBase7=1
VarValue7=0
VarColor7=0
VarIndex7=6
VarName8=stm00_qx01
VarBase8=1
VarValue8=0
VarColor8=0
VarIndex8=7
VarName9=stm00_qx02
VarBase9=1
VarValue9=0
VarColor9=0
VarIndex9=8
VarName10=stm00_qx03
VarBase10=1
VarValue10=0
VarColor10=0
VarIndex10=9
VarName11=clock_10s
VarBase11=1
VarValue11=0
VarColor11=0
VarIndex11=10
VarName12=stm00_qx01
VarBase12=1
VarValue12=0
VarColor12=0
VarIndex12=11
VarName13=stm00_qx02
VarBase13=1
VarValue13=0
VarColor13=0
VarIndex13=12
#PROJECT_OPTIONS_END

#DMVARSLIST_BEGIN
#DMVARSLIST_END

#MASKS_BEGIN
#MASKS_END

#CODE_BEGIN
// AllocGroupList="User Variables", "I/O Variables", "Constants"
function main:void; language 'Structured Text';
begin
  
  // Periodic tasks
  
  if fp(clock_10s)  then
      bio00_qx00 := !bio00_qx00 ;   // Ventilator  every 10 secs
      bio00_qx01 := !bio00_qx01 ;   // Red LED   every 10 sec
  end_if ;
  
  
  if fp(clock_1s)  then
  //    bio00_qx00 := !bio00_qx00 ;   // Red LED  every 1 sec
  //    bio01_qx00 := !bio01_qx00 ;   // Red LED  every 1 sec
      stmh700_qx00 := !stmh700_qx00  ;
  end_if ;
  
  //if fp(clock_10ms)  then
  //
  //end_if ;
  
  if fp(stmh700_ix00)  then
      bio00_qx02 := !bio00_qx02 ;   // Red LED  on keypress
      stmh700_qx01 := !stmh700_qx01  ;
  end_if ;
  
  
  // SW Switch -> LED indicator & ventilator
  //sw00_qx03  := sw00_ix03;
  //bio00_qx00   := sw00_ix03;
  
  //sw00_qx01  := sw00_ix02;        // SW Key -> LED indicator
  //
  //if fp(sw00_ix01)  then
  //    bio00_qx01 := !bio00_qx01;   // SW Key -> change LED indicator
  //end_if ;
  
end;
#CODE_END

#DESCRIPTION_BEGIN
#DESCRIPTION_END

##PROGRAM_END_1

